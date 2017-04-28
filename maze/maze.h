#ifndef MAZE_H
#define MAZE_H

#define ROW 16  //�Թ�����
#define COL 16  //�Թ�����

enum {
    MAZE_EMPTY, //ʲô��û��
    MAZE_ROAD,  //·
    MAZE_WALL,  //ǽ
    MAZE_BEGIN, //���
    MAZE_END,   //����
    GAME_HERO,  //��Ϸ��ɫ
    GAME_ATT,   //װ��-��
    GAME_DEF,   //װ��-��
    GAME_CREEP, //С��
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

int g_MazeMap[COL][ROW];    //�Թ���ͼ

int InitRoad(int, int, int);
int InitMaze();
int InitMonster(int);
int InitGame();
int ShowMaze();


#endif//end MAZE_H
