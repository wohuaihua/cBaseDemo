#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
 
typedef struct snake
{
    int x;
    int y;
    struct snake *next;
}Snake;
int X, Y;
enum STATUS{Up = 1, Down, Left, Right};
 
Snake *pHead, *pBody;//the head of the snake
 
enum STATUS Direction;
int score=0, scorePerFood=10;
int gameStatus = 0;
int timeInterval = 200;
void gameEnd(void);
void setPosition(int x, int y)
{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
}
void hideCursor()
{
	/**
	*	CONSOLE_CURSOR_INFO结构体，第一个参数是控制台光标高度，第二个参数为控制台光标是否显示
	*	非0为真 
	*/
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    /**
	*	设置控制台光标大小和是否显示 
	*/ 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void creatInterface(void)
{
    int i;
	//设置游戏墙的位置 
    for(i=0;i<58;i+=2)
    {
        setPosition(i,0);
        printf("■");//a ?? occupy two character space
        setPosition(i,26);
        printf("■");
    }
    for(i=1;i<26;i++)
    {
        setPosition(0,i);
        printf("■");
        setPosition(56,i);
        printf("■");
    }
    setPosition(65, 10);
    printf("Introduction");
    setPosition(63,12);
    printf("↑\tMove up.");
    setPosition(63,14);
    printf("↓\tMove Down.");
    setPosition(63,16);
    printf("←\tMove left.");
    setPosition(63,18);
    printf("→\tMove right.");
    setPosition(63,20);
    printf("F1\tSpeed up.");
    setPosition(63, 22);
    printf("F2\tSlow down.");
    setPosition(63, 24);
    printf("Space\tGame pause.");
    setPosition(63,26);
    printf("ESC\tQuit the game.");
    setPosition(63, 4);
    printf("Score:");
    setPosition(63, 6);
    printf("Score Per Food:");
}
void initializeSnake(void)
{
    Snake *pTail;
    int i;
    pTail = (Snake *)malloc(sizeof(Snake));
    pTail->x = 24;
    pTail->y = 5;
    pTail->next = NULL;
    for (i = 1; i < 4; i++)
    {
        pHead = (Snake *)malloc(sizeof(Snake));
        pHead->next = pTail;
        pHead->x = 24 + 2*i;
        pHead->y = 5;
        pTail = pHead;//Important
    }
    while (pTail != NULL)
    {
        setPosition(pTail->x, pTail->y);
        printf("■");
        pTail = pTail->next;
    }
}
int biteSelf(void)
{
    Snake *pSelf = pHead->next;
    while (pSelf != NULL)
    {
        if (pHead->x==pSelf->x && pHead->y==pSelf->y)
        {
            return 1;
        }
        pSelf = pSelf->next;
    }
    return 0;
}
void creatFood(void)
{
    int flag = 0;
    X = Y = 4;
    //设置rand()随机序列种子 
    srand((unsigned)time(NULL));
    do{
        X = rand()%52 + 2;
        Y = rand()%24 + 1;
 
        if (X%2 != 0)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }//Important
        pBody = pHead;
        while (pBody->next != NULL)
        {
            if(pBody->x==X && pBody->y==Y)
            {
                flag = 1;
            }
            pBody = pBody->next;
        }
    }while(flag==1);
    setPosition(X, Y);
    printf("■");
}
 
void hitWall(void)
{
    if (pHead->x==0 || pHead->x>=56 || pHead->y==0 || pHead->y>=26)
    {
        gameStatus = 1;
        gameEnd();
    }
}
void snakeMove(void)
{
    Snake *pNextHead;
    hitWall();
 
    pNextHead = (Snake *)malloc(sizeof(Snake));
    pNextHead->next = pHead;
    switch(Direction)
    {
    case Up:
        pNextHead->x = pHead->x;
        pNextHead->y = pHead->y - 1;
        break;
    case Down:
        pNextHead->x = pHead->x;
        pNextHead->y = pHead->y + 1;
        break;
    case Right:
        pNextHead->x = pHead->x + 2;
        pNextHead->y = pHead->y;
        break;
    case Left:
        pNextHead->x = pHead->x - 2;
        pNextHead->y = pHead->y;
        break;
    default:
        break;
    }
    pHead = pNextHead;
    pBody = pHead;
    if (pNextHead->x == X && pNextHead->y == Y)
    {
        while (pBody != NULL)
        {
            setPosition(pBody->x, pBody->y);
            printf("■");
            pBody = pBody->next;
        }
        score += scorePerFood;
        creatFood();
    }
    else
    {
        setPosition(pBody->x, pBody->y);
        printf("■");
        while (pBody->next->next != NULL)
        {
            pBody = pBody->next;
        }
        setPosition(pBody->next->x, pBody->next->y);
        printf("  ");
        free(pBody->next);
        pBody->next = NULL;
    }
    if (biteSelf() == 1)
    {
        gameStatus = 2;
        gameEnd();
    }
}
void pause(void)
{
    while(1)
    {
        Sleep(300);
        if(GetAsyncKeyState(VK_SPACE))
        {
            break;
        }
    }
}
void gameCircle(void)
{
    Direction = Right;
    while (1)
    {
        setPosition(72, 4);
        printf("%d", score);
        setPosition(80, 6);
        printf("%d ", scorePerFood);//Attention space is needed
        if (GetAsyncKeyState(VK_UP) && Direction!=Down)
        {
            Direction = Up;
        }
        else if (GetAsyncKeyState(VK_DOWN) && Direction!=Up)
        {
            Direction = Down;
        }
        else if (GetAsyncKeyState(VK_LEFT) && Direction!=Right)
        {
            Direction = Left;
        }
        else if (GetAsyncKeyState(VK_RIGHT) && Direction!=Left)
        {
            Direction = Right;
        }
        else if (GetAsyncKeyState(VK_SPACE))
        {
            pause();
        }
        else if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameStatus = 3;
            break;
        }
        else if (GetAsyncKeyState(VK_F1))
        {
            if(timeInterval >= 70)
            {
                timeInterval -= 60;
            }
        }
        else if (GetAsyncKeyState(VK_F2))
        {
            if (timeInterval <= 400)
            {
                timeInterval += 60;
            }
 
        }
        switch (timeInterval)
        {
            case 20: scorePerFood = 20;break;
            case 80: scorePerFood = 15;break;
            case 140: scorePerFood = 12;break;
            case 200: scorePerFood = 10;break;
            case 260: scorePerFood = 8;break;
            case 320: scorePerFood = 6;break;
            case 380: scorePerFood = 4;break;
            case 440: scorePerFood = 2;break;
            default: scorePerFood = 0;break;
        }
        Sleep(timeInterval);
        snakeMove();
    }
}
void welcomePage(void)
{
    setPosition(35,2);
    printf("Welcome to Snake");
    setPosition(15, 5);
    printf("Rules:");
    setPosition(15, 7);
    printf("1.  Use ↑↓←→ to control the movement of the Snake.");
    setPosition(15, 9);
    printf("2.  Biting the snake itself is forbidden.");
    setPosition(15, 11);
    printf("3.  Hit the wall is forbidden.");
    setPosition(15, 13);
    printf("Developeder:  zhaoyu.");
    setPosition(15, 15);
    printf("Blog:  http://blog.csdn.net/sinat_30046339");
    setPosition(28, 23);
    printf("Press any key to continue...");
    setPosition(0, 28);
    getchar();
    system("cls");
}
void gameEnd(void)
{
    system("cls");
    setPosition(32, 10);
    switch(gameStatus)
    {
    case 1:
        printf("You hit the wall!");
        break;
    case 2:
        printf("You bit yourself!");
        break;
    case 3:
        printf("You chose to end the game.");
        break;
    default:
        break;
    }
    setPosition(32, 14);
    printf("Your final score is   %d", score);
    getchar();
    setPosition(0, 25);
    exit(0);
}
void gameStart(void)
{
    system("mode con cols=100 lines=30");//no space around equal sign
    welcomePage();
    creatInterface();
    initializeSnake();
    creatFood();
}
 
 
 
//Main Function
int main(void)
{
	//设置控制台光标隐藏 
    hideCursor();
    gameStart();
    gameCircle();
    gameEnd();
    return 0;
}
