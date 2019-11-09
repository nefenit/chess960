#ifndef __CHESS960_H__
#define __CHESS960_H__

#define POSITION_SIZE 9 /* includes '\0' terminator */

typedef enum {
	PIECE_KING    = 'K',
	PIECE_QUEEN   = 'Q',
	PIECE_ROOK    = 'R',
	PIECE_BISHOP  = 'B',
	PIECE_KNIGHT  = 'N',
	PIECE_PAWN    = 'P',
	PIECE_UNKNOWN = '-'
} piece_t;

static const char position_unknown[] = {
	PIECE_UNKNOWN,
	PIECE_UNKNOWN,
	PIECE_UNKNOWN,
	PIECE_UNKNOWN,
	PIECE_UNKNOWN,
	PIECE_UNKNOWN,
	PIECE_UNKNOWN,
	PIECE_UNKNOWN,
	'\0'
};

static const piece_t kings_table[60][6] = {
	{
		PIECE_QUEEN,  
		PIECE_KNIGHT, 
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_QUEEN,  
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_KNIGHT, 
		PIECE_QUEEN,  
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_QUEEN,  
		PIECE_KING,   
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_QUEEN,  
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_ROOK,   
		PIECE_QUEEN
	}, {
		PIECE_QUEEN,  
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_KNIGHT, 
		PIECE_KING,   
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_QUEEN, 
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_KING,  
		PIECE_ROOK
	}, {
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_QUEEN,  
		PIECE_KNIGHT, 
		PIECE_KING,   
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_QUEEN, 
		PIECE_KING,  
		PIECE_ROOK
	}, {
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_KING,  
		PIECE_QUEEN, 
		PIECE_ROOK
	}, {
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_KNIGHT, 
		PIECE_KING,  
		PIECE_ROOK,  
		PIECE_QUEEN
	}, {
		PIECE_QUEEN, 
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_KNIGHT, 
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_QUEEN, 
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_KNIGHT,
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_QUEEN,  
		PIECE_KING,   
		PIECE_KNIGHT,
		PIECE_ROOK
	}, {
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_QUEEN,  
		PIECE_KNIGHT, 
		PIECE_ROOK
	}, {
		PIECE_KNIGHT,
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_KNIGHT,
		PIECE_QUEEN, 
		PIECE_ROOK
	}, {
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_QUEEN
	}, {
		PIECE_QUEEN, 
		PIECE_KNIGHT,
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_ROOK,   
		PIECE_KNIGHT
	}, {
		PIECE_KNIGHT,
		PIECE_QUEEN, 
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_ROOK,  
		PIECE_KNIGHT
	}, {
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_QUEEN, 
		PIECE_KING,  
		PIECE_ROOK,   
		PIECE_KNIGHT
	}, {
		PIECE_KNIGHT,
		PIECE_ROOK,   
		PIECE_KING,  
		PIECE_QUEEN, 
		PIECE_ROOK,  
		PIECE_KNIGHT
	}, {
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_ROOK,  
		PIECE_QUEEN,  
		PIECE_KNIGHT
	}, {
		PIECE_KNIGHT,
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_ROOK,   
		PIECE_KNIGHT, 
		PIECE_QUEEN
	}, {
		PIECE_QUEEN, 
		PIECE_ROOK,   
		PIECE_KNIGHT, 
		PIECE_KNIGHT, 
		PIECE_KING,   
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_QUEEN,  
		PIECE_KNIGHT,
		PIECE_KNIGHT,
		PIECE_KING,  
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_QUEEN, 
		PIECE_KNIGHT,
		PIECE_KING,   
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_KNIGHT, 
		PIECE_QUEEN,  
		PIECE_KING,   
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT, 
		PIECE_KNIGHT, 
		PIECE_KING,   
		PIECE_QUEEN,  
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT, 
		PIECE_KNIGHT, 
		PIECE_KING,   
		PIECE_ROOK,   
		PIECE_QUEEN
	}, {
		PIECE_QUEEN, 
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_KING,  
		PIECE_KNIGHT,
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_QUEEN,  
		PIECE_KNIGHT, 
		PIECE_KING,   
		PIECE_KNIGHT, 
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT, 
		PIECE_QUEEN, 
		PIECE_KING,   
		PIECE_KNIGHT, 
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_KING,  
		PIECE_QUEEN, 
		PIECE_KNIGHT,
		PIECE_ROOK
	}, {
		PIECE_ROOK,   
		PIECE_KNIGHT,
		PIECE_KING,  
		PIECE_KNIGHT,
		PIECE_QUEEN, 
		PIECE_ROOK
	}, {
		PIECE_ROOK,   
		PIECE_KNIGHT, 
		PIECE_KING,  
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_QUEEN
	}, {
		PIECE_QUEEN,
		PIECE_ROOK,   
		PIECE_KNIGHT, 
		PIECE_KING,   
		PIECE_ROOK,   
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_QUEEN, 
		PIECE_KNIGHT,
		PIECE_KING,  
		PIECE_ROOK, 
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_QUEEN, 
		PIECE_KING,  
		PIECE_ROOK, 
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_KING,  
		PIECE_QUEEN, 
		PIECE_ROOK, 
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT, 
		PIECE_KING, 
		PIECE_ROOK, 
		PIECE_QUEEN, 
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_KING, 
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_QUEEN
	}, {
		PIECE_QUEEN,
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_KNIGHT,
		PIECE_KNIGHT,
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_QUEEN, 
		PIECE_KING,  
		PIECE_KNIGHT,
		PIECE_KNIGHT,
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_QUEEN, 
		PIECE_KNIGHT,
		PIECE_KNIGHT,
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_KNIGHT,
		PIECE_QUEEN, 
		PIECE_KNIGHT, 
		PIECE_ROOK
	}, {
		PIECE_ROOK,  
		PIECE_KING, 
		PIECE_KNIGHT,
		PIECE_KNIGHT, 
		PIECE_QUEEN, 
		PIECE_ROOK
	}, {
		PIECE_ROOK, 
		PIECE_KING,  
		PIECE_KNIGHT,
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_QUEEN
	}, {
		PIECE_QUEEN, 
		PIECE_ROOK,  
		PIECE_KING, 
		PIECE_KNIGHT,
		PIECE_ROOK,  
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_QUEEN, 
		PIECE_KING,  
		PIECE_KNIGHT,
		PIECE_ROOK, 
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_QUEEN, 
		PIECE_KNIGHT,
		PIECE_ROOK,   
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_KNIGHT, 
		PIECE_QUEEN, 
		PIECE_ROOK,   
		PIECE_KNIGHT
	}, {
		PIECE_ROOK, 
		PIECE_KING, 
		PIECE_KNIGHT,
		PIECE_ROOK,   
		PIECE_QUEEN, 
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_KNIGHT, 
		PIECE_ROOK,   
		PIECE_KNIGHT, 
		PIECE_QUEEN
	}, {
		PIECE_QUEEN,  
		PIECE_ROOK,  
		PIECE_KING,  
		PIECE_ROOK,  
		PIECE_KNIGHT, 
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_QUEEN, 
		PIECE_KING,  
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,   
		PIECE_KING,  
		PIECE_QUEEN, 
		PIECE_ROOK,  
		PIECE_KNIGHT,
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,  
		PIECE_KING,   
		PIECE_ROOK,   
		PIECE_QUEEN, 
		PIECE_KNIGHT,
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_ROOK,  
		PIECE_KNIGHT, 
		PIECE_QUEEN, 
		PIECE_KNIGHT
	}, {
		PIECE_ROOK,   
		PIECE_KING,   
		PIECE_ROOK,   
		PIECE_KNIGHT, 
		PIECE_KNIGHT, 
		PIECE_QUEEN
	}
};

static const uint8_t bishops_table[0x10] = {
	0xC0, /*  0 BB-- ---- */
	0x90, /*  1 B--B ---- */
	0x84, /*  2 B--- -B-- */
	0x81, /*  3 B--- ---B */
	0x60, /*  4 -BB- ---- */
	0x30, /*  5 --BB ---- */
	0x24, /*  6 --B- -B-- */
	0x21, /*  7 --B- ---B */
	0x48, /*  8 -B-- B--- */
	0x18, /*  9 ---B B--- */
	0x0C, /* 10 ---- BB-- */
	0x09, /* 11 ---- B--B */
	0x42, /* 12 -B-- --B- */
	0x12, /* 13 ---B --B- */
	0x06, /* 14 ---- -BB- */
	0x03  /* 15 ---- --BB */
};

static const uint8_t n5n_table[10] = {
	0x18, /* 0 N N--- */
	0x14, /* 1 N -N-- */
	0x12, /* 2 N --N- */
	0x11, /* 3 N ---N */
	0x0C, /* 4 - NN-- */
	0x0A, /* 5 - N-N- */
	0x09, /* 6 - N--N */
	0x06, /* 7 - -NN- */
	0x05, /* 8 - -N-N */
	0x03, /* 9 - --NN */ 
};

#endif /* __CHESS960_H__ */
