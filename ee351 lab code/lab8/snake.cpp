#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#define BLOCK_SIZE 20 // 每个小格子的长宽
#define HEIGHT 30     // 高度上一共30个小格子
#define WIDTH 40      // 宽度上一共40个小格子

// 全局变量定义
int Blocks[HEIGHT][WIDTH] = {0};
char moveDirection;
int isFailure = 0;
int food_i, food_j; // 食物的位置

void startup() // 初始化函数
{
    int i;
    Blocks[HEIGHT / 2][WIDTH / 2] = 1; // 画面中间画蛇头
    for (i = 1; i <= 4; i++)           // 向左依次4个蛇身
    {
        Blocks[HEIGHT / 2][WIDTH / 2 - i] = i + 1;
    }
    moveDirection = 'D';
    food_i = rand() % (HEIGHT - 5) + 2;
    food_j = rand() % (WIDTH - 5) + 2;
    initgraph(WIDTH * BLOCK_SIZE, HEIGHT * BLOCK_SIZE);
    setlinecolor(RGB(200, 200, 200));
    BeginBatchDraw(); // 开始批量绘制
}

void show() // 绘制函数
{
    cleardevice();
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (Blocks[i][j] > 0)
            {
                setfillcolor(HSVtoRGB(Blocks[i][j] * 10, 0.9, 1));
            }
            else
            {
                setfillcolor(RGB(150, 150, 150));
            }
            fillrectangle(j * BLOCK_SIZE, i * BLOCK_SIZE, (j + 1) * BLOCK_SIZE, (i + 1) * BLOCK_SIZE);
        }
    }
    setfillcolor(RGB(0, 255, 0)); // 食物颜色为绿色
    fillrectangle(food_j * BLOCK_SIZE, food_i * BLOCK_SIZE, (food_j + 1) * BLOCK_SIZE, (food_i + 1) * BLOCK_SIZE);

    if (isFailure) // 游戏失败
    {
        setbkmode(TRANSPARENT); // 文字字体透明
        settextcolor(RGB(255, 0, 0));
        settextstyle(80, 0, _T("宋体"));
        outtextxy(240, 220, _T("游戏失败"));
    }
    FlushBatchDraw(); // 批量绘制
}

void moveSnake()
{
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (Blocks[i][j] > 0) // 大于0的为小蛇元素
            {
                Blocks[i][j]++;
            }
        }
    }
    int oldTail_i, oldTail_j, oldHead_i, oldHead_j; // 存储旧蛇
    int max = 0;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (max < Blocks[i][j])
            {
                max = Blocks[i][j];
                oldTail_i = i;
                oldTail_j = j;
            }
            if (Blocks[i][j] == 2) // 旧蛇头
            {
                oldHead_i = i;
                oldHead_j = j;
            }
        }
    }
    int newHead_i = oldHead_i; // 设定变量存储新蛇头
    int newHead_j = oldHead_j;

    if (moveDirection == 'A') // 根据用户按键，设定新蛇头的位置
    {
        newHead_j = oldHead_j - 1;
    }
    else if (moveDirection == 'D')
    {
        newHead_j = oldHead_j + 1;
    }
    else if (moveDirection == 'W')
    {
        newHead_i = oldHead_i - 1;
    }
    else if (moveDirection == 'S')
    {
        newHead_i = oldHead_i + 1;
    }

    if (newHead_i >= HEIGHT || newHead_i < 0 || newHead_j >= WIDTH || newHead_j < 0 || Blocks[newHead_i][newHead_j] > 0) // 失败条件
    {
        isFailure = 1;
        return;
    }

    Blocks[newHead_i][newHead_j] = 1;               // 新蛇头位置数值为1
    if (newHead_i == food_i && newHead_j == food_j) // 如果新蛇头碰到食物
    {
        food_i = rand() % (HEIGHT - 5) + 2; // 食物重新随机位置
        food_j = rand() % (WIDTH - 5) + 2;
    }
    else
    {
        Blocks[oldTail_i][oldTail_j] = 0; // 旧蛇尾变成空白
    }
}
void updateWithoutInput() // 与输入无关的更新
{
    if (isFailure)
    {
        return;
    }
    static int waitIndex = 1;
    waitIndex++; // 每一帧加1
    if (waitIndex == 10)
    {
        moveSnake();
        waitIndex = 1;
    }
}

void updateWithInput() // 和输入有关的更新
{
    if (_kbhit() && isFailure == 0)
    {
        char input = _getch();
        if (input == 'A' || input == 'S' || input == 'D' || input == 'W')
        {
            moveDirection = input;
            moveSnake();
        }
    }
}

int main()
{
    startup(); // 初始化函数，仅执行一次
    while (1)
    {
        show();               // 进行绘制
        updateWithoutInput(); // 和输入无关的更新
        updateWithInput();    // 和输入有关的更新
    }
    return 0;
}