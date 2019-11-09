#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "chess960.h"

static char* scharnagls_direct_derivation(uint16_t n) {
	uint16_t    n2, b1, n3, b2, n4, q;
	static char sp[POSITION_SIZE];
	int         i, j;

	strncpy(sp, position_unknown, POSITION_SIZE);

	n2 = n / 4;
	b1 = n % 4;
	sp[2 * b1 + 1] = PIECE_BISHOP;
	
	n3 = n2 / 4;
	b2 = n2 % 4;
	sp[2 * b2] = PIECE_BISHOP;

	n4 = n3 / 6;
	q  = n3 % 6;

	for(i = j = 0; i < POSITION_SIZE; ++i) {
		if(sp[i] == PIECE_UNKNOWN) {
			if(q == j) {
				sp[i] = PIECE_QUEEN;
				break;
			}
			++j;
		}
	}

	for(i = 0, j = 4; i < POSITION_SIZE; ++i) {
		if(sp[i] == PIECE_UNKNOWN) {
			if(n5n_table[n4] & (1u << j))
				sp[i] = PIECE_KNIGHT;
			--j;
		}
	}
	
	for(i = j = 0; i < POSITION_SIZE; ++i)
		if(sp[i] == PIECE_UNKNOWN)
			switch(j++) {
				case 0:
				case 2:
					sp[i] = PIECE_ROOK;
					break;
				case 1:
					sp[i] = PIECE_KING;
					break;
			}

	return sp;
}

static char* scharnagls_two_table_representation(uint16_t n) {
	uint16_t    king_index   = n / 0x10;
	uint8_t     bishop_index = n % 0x10;
	static char sp[POSITION_SIZE];
	int         i, j;

	strncpy(sp, position_unknown, POSITION_SIZE);

	for(i = 0, j = 7; i < POSITION_SIZE; ++i) {
		if(sp[i] == PIECE_UNKNOWN) {
			if(bishops_table[bishop_index] & (1u << j))
				sp[i] = PIECE_BISHOP;
			--j;
		}
	}

	for(i = j = 0; i < POSITION_SIZE; ++i)
		if(sp[i] == PIECE_UNKNOWN)
			sp[i] = kings_table[king_index][j++];

	return sp;
}

static char* get_fen(uint16_t n) {
	static char fen[] = 
		"--------/--------/8/8/8/8/--------/-------- w KQkq - 0 1";
	piece_t pawn_lower = tolower(PIECE_PAWN);
	piece_t pawn_upper = toupper(PIECE_PAWN);
	int i;

	strncpy(fen,      scharnagls_two_table_representation(n), 8);
	strncpy(fen + 35, scharnagls_two_table_representation(n), 8);

	for(i = 0; i < 8; ++i) {
		 fen      [i] = tolower(fen[i]);
		(fen +  9)[i] = pawn_lower;	
		(fen + 26)[i] = pawn_upper;
		(fen + 35)[i] = toupper((fen+35)[i]);
	}

	return fen;
}

static void print_pgn(uint16_t n) {
	printf("[FEN \"%s\"]\n[Setup \"1\"]\n[Variant \"Chess960\"]\n", get_fen(n));
}

static void test(void) {
	int i;
	for(i = 0; i < 960; ++i) {
		printf("%d:\n%s\n%s\n%s\n", 
				i, 
				scharnagls_direct_derivation(i), 
				scharnagls_two_table_representation(i), 
				position_unknown
		);
		
		if(strcmp(scharnagls_direct_derivation(i), scharnagls_two_table_representation(i))) {
			fprintf(stderr, "ERROR: Differnet positions in #%d, aborting\n", i);
			exit(EXIT_FAILURE);
		}
	}
}

int main(int argc, char *argv[]) {
	puts(get_fen(518));
	/* test(); */
	/* puts(scharnagls_direct_derivation(518)); */ 
	/* print_fen(518); */
	return 0;
}
