// This is my first project in C, and I started coding in it just yesterday (6/14/2024)
// I'll probably improve it in the future.

#include <stdio.h>

const int height = 10;
const int width = 7;

int grid[][7] = { // The grid.
   //0  1  2  3  4  5  6 Y
    {2, 2, 2, 2, 2, 2, 2}, // 0
    {2, 0, 0, 0, 0, 0, 2}, // 1
    {2, 0, 0, 0, 0, 0, 2}, // 2
    {2, 0, 0, 0, 0, 0, 2}, // 3
    {2, 0, 0, 0, 0, 0, 2}, // 4
    {2, 0, 0, 0, 0, 0, 2}, // 5
    {2, 0, 0, 0, 0, 0, 2}, // 6
    {2, 0, 0, 0, 0, 0, 2}, // 7
    {2, 0, 0, 0, 0, 0, 2}, // 8
    {2, 2, 2, 2, 2, 2, 2}  // 9 X

    // 0 represents empty spots.
    // 1 represents the sand blocks
    // 2 represents the walls, but you can change them to whatever number you want except 0
};

void init() { // This function just prints the grid.
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            printf("%2i", grid[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

typedef struct SandBlock { // This is to create a new SandBlock. You can set Y and X coordinates
    int xCords;
    int yCords;
} sandblock;

void CheckNeighbors(sandblock *block) { // This function checks the blocks neighboring spaces on the grid, and if it can move to that place
                                        // on the grid, it will.
    int xCords = block->xCords;
    int yCords = block->yCords;
    
    if (grid[xCords][yCords] == 0) { // Checks if the coordinates given can spawn in the sand block.
        grid[xCords][yCords] = 1; // If it can, it will spawn as '1'.
    }

    if (grid[xCords + 1][yCords] == 0) { // Checks if there is an empty space below the sand block and moves down it if there is.
        grid[xCords][yCords] = 0;
        grid[xCords + 1][yCords] = 1;
        block->xCords++;
    } else if (grid[xCords + 1][yCords + 1] == 0) { // Checks if there is an empty space diagonally down to the right, and if there is, it will move there.
        grid[xCords][yCords] = 0;
        grid[xCords + 1][yCords + 1] = 1;
        block->xCords++;
        block->yCords++;
    } else if (grid[xCords + 1][yCords - 1] == 0) { // Checks if there is an empty space diagonally down to the left, and if there is, it will move there.
        grid[xCords][yCords] = 0;
        grid[xCords + 1][yCords - 1] = 1;
        block->xCords--;
        block->yCords--;
    } else { // If there are no spaces to move the sand block, it will stop.
        return;
    }
}

int main() {
    sandblock *block; // Creates a sand block

    // Sets the X and Y coordinates. Make sure it is correct and can spawn on those coordinates.
    block->xCords = 1;
    block->yCords = 3;
    
    for (int i = 0; i < 7; i++) { // I don't know how to iterate each second so I just use a for loop.
        CheckNeighbors(block);
        init();
    }

    return 0;
}
