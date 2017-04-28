#ifndef MAZE_H
#define MAZE_H

#define ROW 16  //迷宫行数
#define COL 16  //迷宫列数

enum {
    MAZE_EMPTY, //什么都没有
    MAZE_ROAD,  //路
    MAZE_WALL,  //墙
    MAZE_BEGIN, //入口
    MAZE_END,   //出口
    GAME_HERO,  //游戏角色
    GAME_ATT,   //装备-剑
    GAME_DEF,   //装备-盾
    GAME_CREEP, //小怪
    GAME_BOSS   //boss
};

// struct monster {
//     int maxHP;
//     int curHP;
//     int atk;
//     int def;
//     int exp;
// }g_Monster[] = {
//     {10, 10, 11, 1, 1},
//     {50, 50, 28, 20, 10}
// };
// 
// struct hero {
//     int maxHP;
//     int HPGrowth;
//     int curHP;
//     int atk;
//     int atkGrowth;
//     int def;
//     int defGrowth;
//     int level;
// }g_Hero = {100, 10, 100, 10, 5, 10, 5, 1};

int g_MazeMap[COL][ROW];    //迷宫地图

int InitRoad(int, int, int);
int InitMaze();
int InitMonster(int);
int InitGame();
int ShowMaze();


#endif//end MAZE_H
