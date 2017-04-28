#include "maze.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int InitRoad(int x, int y, int in) {
    int r;
    int sign = 0;
     srand(time(NULL));
     ShowMaze();
     //入口
     if (x == -1 && y == -1) {
         r = rand();
         if (r % 4  == 0) { //上边
             x = rand() % (COL-2) + 1;
             y = 0;
             g_MazeMap[x][y] = MAZE_BEGIN;
             InitRoad(x, y+1, r%4);
         } else if (r % 4 == 1) { //右边
             x = COL - 1;
             y = rand() % (ROW - 2) + 1;
             g_MazeMap[x][y] = MAZE_BEGIN;
             InitRoad(x-1, y, r%4);
         } else if (r % 4 == 2) { //下边
             x = rand() % (COL-2) + 1;
             y = ROW - 1;
             g_MazeMap[x][y] = MAZE_BEGIN;
             InitRoad(x, y-1, r%4);
         } else { //左边
             x = 0;
             y = rand() % (ROW - 2) + 1;
             g_MazeMap[x][y] = MAZE_BEGIN;
             InitRoad(x+1, y, r%4);
         }
     }
     //出口
     if (x == 0 || x == COL-1 || y == 0 || y == ROW-1) {
         if ((y == 0 && in == 2) || (x == COL-1 && in == 3) ||
             (y == ROW-1 && in == 0) || (x == 0 && in == 1)) {
             g_MazeMap[x][y] = MAZE_END;
             return 1;
         } else {
             return 0;
         }
     }
     g_MazeMap[x][y] = MAZE_ROAD;
     r = rand();
     if (r % 4 == 0) {
         if (g_MazeMap[x][y-1] != MAZE_ROAD) {
             sign = InitRoad(x, y - 1, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x+1][y] != MAZE_ROAD) {
             sign = InitRoad(x + 1, y, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x][y+1] != MAZE_ROAD) {
             sign = InitRoad(x, y + 1, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x-1][y] != MAZE_ROAD) {
             sign = InitRoad(x - 1, y, in);
             if (sign == 1) {
                 return 1;
             }
         }
     } else if (r % 4 == 1) {
         if (g_MazeMap[x+1][y] != MAZE_ROAD) {
             sign = sign = InitRoad(x + 1, y, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x][y+1] != MAZE_ROAD) {
             sign = InitRoad(x, y + 1, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x-1][y] != MAZE_ROAD) {
             sign = InitRoad(x - 1, y, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x][y-1] != MAZE_ROAD) {
             sign = InitRoad(x, y - 1, in);
             if (sign == 1) {
                 return 1;
             }
         }
     } else if (r % 4 == 2) {
         if (g_MazeMap[x][y+1] != MAZE_ROAD) {
             sign = InitRoad(x, y + 1, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x-1][y] != MAZE_ROAD) {
             sign = InitRoad(x - 1, y, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x][y-1] != MAZE_ROAD) {
             sign = InitRoad(x, y - 1, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x+1][y] != MAZE_ROAD) {
             sign = InitRoad(x + 1, y, in);
             if (sign == 1) {
                 return 1;
             }
         }
     } else if (r % 4 == 3) {
         if (g_MazeMap[x-1][y] != MAZE_ROAD) {
             sign = InitRoad(x - 1, y, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x][y-1] != MAZE_ROAD) {
             sign = InitRoad(x, y - 1, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x+1][y] != MAZE_ROAD) {
             sign = InitRoad(x + 1, y, in);
             if (sign == 1) {
                 return 1;
             }
         }
         if (g_MazeMap[x][y+1] != MAZE_ROAD) {
             sign = InitRoad(x, y + 1, in);
             if (sign == 1) {
                 return 1;
             }
         }
     }
     return 0;
}

int InitMaze() {
    int i, j;

    //生成起点到终点的通路
    InitRoad(-1, -1, 0);

    //生成边界
    for (i = 0; i < COL; i++) {
        if (g_MazeMap[i][0] == MAZE_EMPTY) {
            g_MazeMap[i][0] = MAZE_WALL;
        }
        if (g_MazeMap[i][ROW-1] == MAZE_EMPTY) {
            g_MazeMap[i][ROW-1] = MAZE_WALL;
        }
    }
    for (i = 0; i < ROW; i++) {
        if (g_MazeMap[0][i] == MAZE_EMPTY) {
                g_MazeMap[0][i] = MAZE_WALL;
        }
        if (g_MazeMap[COL-1][i] == MAZE_EMPTY) {
                g_MazeMap[COL-1][i] = MAZE_WALL;
        }
    }

    //其他地方随机生成路0.1或墙0.9
    srand(time(NULL));
    for (i = 0; i < COL; i++) {
        for (j = 0; j < ROW; j++) {
            if (g_MazeMap[i][j] == MAZE_EMPTY) {
                if (rand() % 10 == 9) {
                    g_MazeMap[i][j] = MAZE_ROAD;
                } else {
                    g_MazeMap[i][j] = MAZE_WALL;
                }
            }
        }
    }

    return 1;
}

int InitMonster(int numMon) {
    int i, j, k;
    int numRoad = 0;
    int index = 0;
    int *creep = (int*)malloc(numMon*sizeof(int));
    srand(time(NULL));
    for (i = 0; i < COL; i++) {
        for (j = 0; j < ROW; j++) {
            if (g_MazeMap[i][j] == MAZE_END) {
                if (i == 0) {
                    g_MazeMap[i+1][j] = GAME_BOSS;
                } else if (i == COL -1) {
                    g_MazeMap[i-1][j] = GAME_BOSS;
                } else if (j == 0) {
                    g_MazeMap[i][j+1] = GAME_BOSS;
                } else {
                    g_MazeMap[i][j-1] = GAME_BOSS;
                }
            }
            if (g_MazeMap[i][j] == MAZE_ROAD) {
                numRoad++;
            }
        }
    }
    for (i = 0; i < numMon; i++) {
        creep[i] = rand() % numRoad;
    }
    for (i = 0; i < COL; i++) {
        for (j = 0; j < ROW; j++) {
            for (k = 0; k < numMon; k++) {
                if (index == creep[k]) {
                    g_MazeMap[i][j] == GAME_CREEP;
                }
            }
        }
    }
    return 1;
}

int ShowMaze() {
    int i, j;
    system("cls");
    for (i = 0; i < COL; i++) {
        for (j = 0; j < ROW; j++) {
            switch (g_MazeMap[i][j]) {
                case MAZE_BEGIN :
                    printf("☆");
                    break;
                case MAZE_END :
                    printf("◎");
                    break;
                case MAZE_ROAD :
                    printf("□");
                    break;
                case MAZE_WALL :
                    printf("▓");
                    break;
                case GAME_HERO :
                    printf("☺");
                    break;
                case GAME_CREEP :
                    printf("♤");
                    break;
                case GAME_BOSS :
                    printf("卍");
                    break;
                case GAME_ATT :
                    printf("➴");
                    break;
                case GAME_DEF :
                    printf("☯");
                    break;
                default:
                    printf("○");
                    break;
            }
        }
        printf("\n");
    }
    system("pause");
    return 1;
}

int InitGame() {
    InitMaze();
    InitMonster(3);
    ShowMaze();
    return 1;
}