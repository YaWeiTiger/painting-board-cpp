#pragma once
#include"graphics.h"
#include"class.h"
#include "main.h"
#include<iostream>
#include<fstream>
using std::endl;
char str[1000];//inputbox_getline作为缓冲区使用
Shape shape[20];
void filesave();
void fileread();
void filepaint();
void initialboard()
{
	Controller c1{ 1280,640 };
	c1.open();
	inputbox_getline("画板参数输入", "请输入画板的宽度", str, sizeof(str) / sizeof(*str));
	c1.setWidth(atoi(str));
	inputbox_getline("画板参数输入", "请输入画板的高度", str, sizeof(str) / sizeof(*str));
	c1.setHeight(atoi(str));
	setfont(30, 0, "宋体");
	xyprintf(0, 0, "正在调整画板参数，请稍后");
	delay_ms(2000);
	c1.close();
	c1.open();
}
void wholemenu()
{
    setcolor(BLACK);
    setfillcolor(BLACK);
    bar(0, 0, 200, 200);
    setlinewidth(3);
    setcolor(WHITE);
    line(0, 170, 200, 170);
    line(200, 170, 200, 0);//这两条直线用于包围菜单
    setfont(18, 0, "宋体");
    char s2[] = "选择您想进行的操作：";
    xyprintf(10, 10, s2);
    xyprintf(10, 30, "1、清除屏幕");
    xyprintf(10, 50, "2、作画");
    xyprintf(10, 70, "3、关闭");
    xyprintf(10, 90, "4、返回上一步");
    xyprintf(10, 110, "5、撤销");
    xyprintf(10, 130, "6、制作人员");
    xyprintf(10, 150, "7、意见采纳");
}
void readmenu(void)
{
	char read;//read决定用户是否需要读取文件
	setfont(20, 0, "宋体");
	xyprintf(0, 0, "请使用英文输入法");
	delay_ms(2000);
	cleardevice();
	while (1)
	{
		xyprintf(10, 10, "欢迎您进入吖吖画板，请根据菜单做出选择，是否读取文件");
		xyprintf(10, 30, "1、读取");
		xyprintf(10, 50, "2、不读取");
		read = getch();
		if (read == '1')
		{
			cleardevice();
			xyprintf(10, 10, "已读取");
			getch();
			fileread();
			break;
		}
		else if (read == '2')
		{
			cleardevice();
			xyprintf(10, 10, "未读取");
			getch();
			break;
		}
		else
		{
			cleardevice();
			xyprintf(10, 10, "请您仔细阅读菜单后再做选择");
			getch();
			cleardevice();
		}
	}
}
void paintmenu(void)
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	bar(0, 0, 220, 200);
	setlinewidth(3);
	setcolor(WHITE);
	line(0, 150, 200, 150);
	line(200, 150, 200, 0);
	setfont(18, 0, "宋体");
	xyprintf(10, 10, "请选择具体作画方式:");
	xyprintf(10, 30, "1、弧");
	xyprintf(10, 50, "2、圆");
	xyprintf(10, 70, "3、三角形");
	xyprintf(10, 90, "4、矩形");
	xyprintf(10, 110, "5、返回上一步");
}
void flee(void)
{
	char flee;//用于判断用户是否退出
	char save;//用于判断用户是否保存文件
	cleardevice();
	setfont(50, 0, "宋体");
	xyprintf(20, 30, "是否返回菜单(返回请输1)");
	xyprintf(20, 100, "不返回将退出此程序");
	flee = getch();
	if (flee == '1')
	{
		cleardevice();
		xyprintf(20, 30, "按任意键继续");
		getch();
		cleardevice();
		setfont(20, 0, "宋体");

	}
	else
	{
		cleardevice();
		setfont(20, 0, "宋体");
		xyprintf(10, 20, "是否保存文件");
		xyprintf(10, 40, "保存请按1");
		xyprintf(10, 60, "不保存按任意键退出");
		save = getch();
		if (save == '1')
		{
			cleardevice();
			filesave();
			xyprintf(10, 20, "已保存至文件“shape.txt”");
			xyprintf(10, 40, "按任意键退出");
			getch();
			cleardevice();
			xyprintf(10, 30, "正在退出，请稍后");
			delay_ms(10);
			closegraph();
		}
		else
		{
			cleardevice();
			xyprintf(10, 30, "正在退出，请稍后");
			delay_ms(2000);
			closegraph();
		}
	}
}
void maker(void)
{
	xyprintf(220, 120, "学校：北京邮电大学");
	xyprintf(220, 140, "学院：计算机学院（国家示范性软件学院）");
	xyprintf(220, 160, "班级：2020211320班");
	xyprintf(220, 180, "姓名：胡家伟");
	setfont(30, 0, "宋体");
	xyprintf(220, 220, "侵权必究");
	setfont(18, 0, "宋体");
	getch();
}
void suggestions(void)
{
	char str[1000];
	inputbox_getline("意见箱", "请把您的意见填写在下面\n我们会认真对待", str, sizeof(str) / sizeof(*str));
}
void filesave()
{
	int num1, num2;
	std::ofstream ofs;
	ofs.open("C:\\Users\\胡家伟的windows\\Desktop\\paint boarding\\shape.txt", std::ios::out);
	ofs << Shape::cnt << endl;
	for (num1 = 0; num1 < Shape::cnt; num1++)
	{
		ofs << shape[num1].getCate() << endl;
		ofs << shape[num1].getRvalue() << " "<< shape[num1].getGvalue() << " " << shape[num1].getBvalue() << endl;
		ofs << shape[num1].getFilled() << endl;
		if (shape[num1].getFilled() == 1)
		{
			ofs << shape[num1].getR_value() << " " << shape[num1].getG_value() << " " << shape[num1].getB_value() << endl;
		}
		if (shape[num1].getCate() == 51 || shape[num1].getCate() == 52)
		{
			for (num2 = 0; num2 <= 20; num2++)
			{
				if (shape[num1].point[num2].getPtx() == 0)
				{
					break;
				}
				else
				{
					ofs << shape[num1].point[num2].getPtx();
				}
				if (shape[num1].point[num2].getPty() == 0)
				{
					break;
				}
				else
				{
					ofs << " " << shape[num1].point[num2].getPty()<<" ";
				}
			}
			ofs << endl;
		}
		else if (shape[num1].getCate() == 49)
		{
			ofs << shape[num1].point[0].getPtx() << " " << shape[num1].point[0].getPty() << " " << shape[num1].point[0].getStangle()
				<< " " << shape[num1].point[0].getEndangle() << " " << shape[num1].point[0].getRadius() << endl;
		}
		else if(shape[num1].getCate() == 50)
		{
			ofs << shape[num1].point[0].getPtx() << " " << shape[num1].point[0].getPty() << " " << shape[num1].point[0].getRadius() << endl;
		}
		ofs << endl;
	}
	ofs.close();
}
void fileread(void)
{
	int num1;
	int cate, R, G, B, R_, G_, B_, isfilled;
	int pt[10];
	std::ifstream ifs;
	ifs.open("C:\\Users\\胡家伟的windows\\Desktop\\paint boarding\\shape.txt", std::ios::in);
	ifs >> Shape::cnt;
	for (num1 = 0; num1 < Shape::cnt; num1++)
	{
		ifs >> cate;
		shape[num1].setCate(cate);
		ifs >> R >> G >> B;
		shape[num1].setRvalue(R);
		shape[num1].setGvalue(G);
		shape[num1].setBvalue(B);
		ifs >> isfilled;
		shape[num1].setFilled(isfilled);
		if (shape[num1].getFilled() == 1)
		{
			ifs >> R_ >> G_ >> B_;
			shape[num1].setR_value(R_);
			shape[num1].setG_value(G_);
			shape[num1].setB_value(B_);
		}
		if (shape[num1].getCate() == 49)
		{
			ifs >> pt[0] >> pt[1] >> pt[2] >> pt[3] >> pt[4];
			shape[num1].point[0].setPtx(pt[0]); 
			shape[num1].point[0].setPty(pt[1]);
			shape[num1].point[0].setStangle(pt[2]);
			shape[num1].point[0].setEndangle(pt[3]);
			shape[num1].point[0].setRadius(pt[4]);
		}
		else if (shape[num1].getCate() == 50)
		{
			ifs >> pt[0] >> pt[1] >> pt[2];
			shape[num1].point[0].setPtx(pt[0]);
			shape[num1].point[0].setPty(pt[1]);
			shape[num1].point[0].setRadius(pt[2]);
		}
		else if (shape[num1].getCate() == 51 )
		{
			ifs >> pt[0] >> pt[1] >> pt[2] >> pt[3] >> pt[4] >> pt[5] >> pt[6] >> pt[7];
			shape[num1].point[0].setPtx(pt[0]);
			shape[num1].point[0].setPty(pt[1]);
			shape[num1].point[1].setPtx(pt[2]);
			shape[num1].point[1].setPty(pt[3]);
			shape[num1].point[2].setPtx(pt[4]);
			shape[num1].point[2].setPty(pt[5]);
			shape[num1].point[3].setPtx(pt[6]);
			shape[num1].point[3].setPty(pt[7]);
		}
		else if (shape[num1].getCate() == 52)
		{
			ifs >> pt[0] >> pt[1] >> pt[2] >> pt[3];
			shape[num1].point[0].setPtx(pt[0]);
			shape[num1].point[0].setPty(pt[1]);
			shape[num1].point[1].setPtx(pt[2]);
			shape[num1].point[1].setPty(pt[3]);
		}
	}
	filepaint();
}
void filepaint()
{
	int i = 0;
	int i_ = 0;
	int point_ = 0;
	for (i = 0; i < Shape::cnt; i++)
	{
		switch (shape[i].getCate())
		{
		case 49:
			shape[i].linecolor();
			if (shape[i].getFilled() == true)
			{
				shape[i].fillcolor();
			}
			else
			{
				setfillcolor(EGERGB(0, 0, 0));
			}
			arc(shape[i].point[0].getPtx(), shape[i].point[0].getPty(), shape[i].point[0].getStangle(), shape[i].point[0].getEndangle(), shape[i].point[0].getRadius());
			break;
		case 50:
			shape[i].linecolor();
			if (shape[i].getFilled() == true)
			{
				setfillcolor(EGERGB(shape[i].getR_value(),shape[i].getG_value(),shape[i].getB_value()));
			}
			else
			{
				setfillcolor(EGERGB(0, 0, 0));
			}
			fillellipse(shape[i].point[0].getPtx(), shape[i].point[0].getPty(), shape[i].point[0].getRadius(),shape[i].point[0].getRadius());
			break;
		case 51:
			
			int data[50];
			shape[i].linecolor();
			if (shape[i].getFilled() == true)
			{
				shape[i].fillcolor();
			}
			else
			{
				setfillcolor(EGERGB(0, 0, 0));
			}
			while (i_ < 2 * shape[i_].point[point_].getNum())
			{
				data[i_] = shape[i].point[point_].getPtx();
				i_++;
				data[i] = shape[i].point[point_].getPty();
				i_++;
				point_++;
			}//以上while代码段实现了将结构体中的数据数组化
			fillpoly(shape[i].point[point_].getNum(), data);
			break;
		case 52:
			int left = shape[i].point[0].getPtx();
			int top = shape[i].point[0].getPty();
			int right = shape[i].point[1].getPtx();
			int bottom = shape[i].point[1].getPty();
			shape[i].linecolor();
			rectangle(left, top, right, bottom);
			if (shape[i].getFilled() == 1)
				floodfill((left + right) / 2, (top + bottom) / 2, EGERGB(shape[i].getRvalue(), shape[i].getGvalue(), shape[i].getBvalue()));
			break;
		}

	}
}