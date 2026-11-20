# include <stdio.h>

#define EMPTY 0

// White Pieces

#define W_PAWN 1
#define W_KNIGHT 2
#define W_BISHOP 3
#define W_ROOK 4
#define W_QUEEN 5
#define W_KING 6

// Black Pieces

#define B_PAWN 7
#define B_KNIGHT 8
#define B_BISHOP 9
#define B_ROOK 10
#define B_QUEEN 11
#define B_KING 12

// Board Structure

typedef struct {
    int squares[64];
    int side_to_move;
    int castling_rights;
    int en_passant;
    int halfmove_clock;
    int fullmove_clock;
} Board;

// Board Initialiation

void init_board(Board *board) {
    for (int i = 0; i < 64; i++) {
        board->squares[i] = EMPTY;
    }


// Step B: Define the starting position array
// Index 0 is top-left (a8), Index 63 is bottom-right (h1)

    int start_pos[64] = {
            B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK, // Rank 8 (0-7)
            B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN,         // Rank 7 (8-15)
            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,                 // Rank 6 (16-23)
            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,                 // Rank 5 (24-31)
            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,                 // Rank 4 (32-39)
            EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,                 // Rank 3 (40-47)
            W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN,         // Rank 2 (48-55)
            W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK  // Rank 1 (56-63)
        };

    for (int i = 0; i < 64; i++) {
        board->squares[i] = start_pos[i];
    }

    board->side_to_move = 1;
    board->castling_rights = 15;
    board->en_passant = -1;
    board->halfmove_clock = 0;
    board->fullmove_clock = 1;
}

// PRINTING BOARD

void print_board(const Board *board) {
    printf("\n  +---+---+---+---+---+---+---+---+\n");

    for (int rank = 0; rank < 8; rank++) {
        printf("%d |", 8 - rank);

        for (int file = 0; file < 8; file++)
        {
            int index = rank * 8 + file;
            int piece = board->squares[index];

            char symbol = ' ';

            switch (piece) {
                case W_PAWN:   symbol = 'P'; break;
                case W_KNIGHT: symbol = 'N'; break;
                case W_BISHOP: symbol = 'B'; break;
                case W_ROOK:   symbol = 'R'; break;
                case W_QUEEN:  symbol = 'Q'; break;
                case W_KING:   symbol = 'K'; break;
                case B_PAWN:   symbol = 'p'; break;
                case B_KNIGHT: symbol = 'n'; break;
                case B_BISHOP: symbol = 'b'; break;
                case B_ROOK:   symbol = 'r'; break;
                case B_QUEEN:  symbol = 'q'; break;
                case B_KING:   symbol = 'k'; break;
                default:       symbol = ' '; break; // EMPTY
            }
            printf("%c |", symbol);
        }
        printf("\n  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    a   b   c   d   e   f   g   h\n\n");
}

// MAIN Function

int main(void) {
    Board my_board;

    init_board(&my_board);

    printf("Chess Engine - Initial Position:\n");
    print_board(&my_board);

    return 0;
}