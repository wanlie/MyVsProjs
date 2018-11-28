#include "stdafx.h"
#include "Sense.h"
#include <stdlib.h>


CSense::CSense(int xSize, int ySize)
{
    m_nMapWidth = xSize;
    m_nMapHeight = ySize;

    m_pMap = shared_ptr<char>(new char[m_nMapWidth * m_nMapHeight], \
                              std::default_delete<char[]>());

    m_nCurX = 0;
    m_nCurY = 10;

    //背景墙需要初始化

    for (int i = 0; i < m_nMapHeight; i++)
    {

        for (int j = 0; j < m_nMapWidth; j++)
        {

            if (j == 0 || j == m_nMapWidth - 1 || i == m_nMapHeight - 1)
            {
                //设置边界
                (&*m_pMap)[i*m_nMapWidth + j] = 1;
            }
            else
            {
                (&*m_pMap)[i*m_nMapWidth + j] = 0;
            }

        }
    }

    //初始化方块
    m_Block = CBlock();
    DrawBg();
}


void CSense::DrawBg()
{

    for (int i = 0; i < m_nMapHeight; i++)
    {
        for (int j = 0; j < m_nMapWidth; j++)
        {
            //表示该块为空
            if ((&*m_pMap)[i*m_nMapWidth + j] == 0)
            {
                ShowBg(i, j);
            }
            else if ((&*m_pMap)[i*m_nMapWidth + j] == 1)
            {
                ShowBlock(i, j);
            }

        }
    }
}

//绘制方块
void CSense::ShowBlock(int x, int y)
{
    WriteChar(x,  // 第 1 行
              y,  // 第 1 列
              "  ",
              SetConsoleColor(COLOR_BLACK, // 
                              COLOR_WHITE)  // 白色背景
    );
}

//绘制背景
void CSense::ShowBg(int x, int y)
{
    WriteChar(x,  // 第 1 行
              y,  // 第 1 列
              "  ",
              SetConsoleColor(COLOR_WHITE, // 黑色前景
                              COLOR_BLACK)  // 白色背景
    );
}

bool CSense::BlockMoveable(int nDiret)
{
    return false;
}

bool CSense::BlockRotateable()
{
    return false;
}
