#pragma once
#include"graphics.h"
#include"class.h"
#include "main.h"
#include<iostream>
#include<fstream>
using std::endl;
char str[1000];//inputbox_getline��Ϊ������ʹ��
Shape shape[20];
void filesave();
void fileread();
void filepaint();
void initialboard()
{
	Controller c1{ 1280,640 };
	c1.open();
	inputbox_getline("�����������", "�����뻭��Ŀ��", str, sizeof(str) / sizeof(*str));
	c1.setWidth(atoi(str));
	inputbox_getline("�����������", "�����뻭��ĸ߶�", str, sizeof(str) / sizeof(*str));
	c1.setHeight(atoi(str));
	setfont(30, 0, "����");
	xyprintf(0, 0, "���ڵ���������������Ժ�");
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
    line(200, 170, 200, 0);//������ֱ�����ڰ�Χ�˵�
    setfont(18, 0, "����");
    char s2[] = "ѡ��������еĲ�����";
    xyprintf(10, 10, s2);
    xyprintf(10, 30, "1�������Ļ");
    xyprintf(10, 50, "2������");
    xyprintf(10, 70, "3���ر�");
    xyprintf(10, 90, "4��������һ��");
    xyprintf(10, 110, "5������");
    xyprintf(10, 130, "6��������Ա");
    xyprintf(10, 150, "7���������");
}
void readmenu(void)
{
	char read;//read�����û��Ƿ���Ҫ��ȡ�ļ�
	setfont(20, 0, "����");
	xyprintf(0, 0, "��ʹ��Ӣ�����뷨");
	delay_ms(2000);
	cleardevice();
	while (1)
	{
		xyprintf(10, 10, "��ӭ������߹߹���壬����ݲ˵�����ѡ���Ƿ��ȡ�ļ�");
		xyprintf(10, 30, "1����ȡ");
		xyprintf(10, 50, "2������ȡ");
		read = getch();
		if (read == '1')
		{
			cleardevice();
			xyprintf(10, 10, "�Ѷ�ȡ");
			getch();
			fileread();
			break;
		}
		else if (read == '2')
		{
			cleardevice();
			xyprintf(10, 10, "δ��ȡ");
			getch();
			break;
		}
		else
		{
			cleardevice();
			xyprintf(10, 10, "������ϸ�Ķ��˵�������ѡ��");
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
	setfont(18, 0, "����");
	xyprintf(10, 10, "��ѡ�����������ʽ:");
	xyprintf(10, 30, "1����");
	xyprintf(10, 50, "2��Բ");
	xyprintf(10, 70, "3��������");
	xyprintf(10, 90, "4������");
	xyprintf(10, 110, "5��������һ��");
}
void flee(void)
{
	char flee;//�����ж��û��Ƿ��˳�
	char save;//�����ж��û��Ƿ񱣴��ļ�
	cleardevice();
	setfont(50, 0, "����");
	xyprintf(20, 30, "�Ƿ񷵻ز˵�(��������1)");
	xyprintf(20, 100, "�����ؽ��˳��˳���");
	flee = getch();
	if (flee == '1')
	{
		cleardevice();
		xyprintf(20, 30, "�����������");
		getch();
		cleardevice();
		setfont(20, 0, "����");

	}
	else
	{
		cleardevice();
		setfont(20, 0, "����");
		xyprintf(10, 20, "�Ƿ񱣴��ļ�");
		xyprintf(10, 40, "�����밴1");
		xyprintf(10, 60, "�����水������˳�");
		save = getch();
		if (save == '1')
		{
			cleardevice();
			filesave();
			xyprintf(10, 20, "�ѱ������ļ���shape.txt��");
			xyprintf(10, 40, "��������˳�");
			getch();
			cleardevice();
			xyprintf(10, 30, "�����˳������Ժ�");
			delay_ms(10);
			closegraph();
		}
		else
		{
			cleardevice();
			xyprintf(10, 30, "�����˳������Ժ�");
			delay_ms(2000);
			closegraph();
		}
	}
}
void maker(void)
{
	xyprintf(220, 120, "ѧУ�������ʵ��ѧ");
	xyprintf(220, 140, "ѧԺ�������ѧԺ������ʾ�������ѧԺ��");
	xyprintf(220, 160, "�༶��2020211320��");
	xyprintf(220, 180, "����������ΰ");
	setfont(30, 0, "����");
	xyprintf(220, 220, "��Ȩ�ؾ�");
	setfont(18, 0, "����");
	getch();
}
void suggestions(void)
{
	char str[1000];
	inputbox_getline("�����", "������������д������\n���ǻ�����Դ�", str, sizeof(str) / sizeof(*str));
}
void filesave()
{
	int num1, num2;
	std::ofstream ofs;
	ofs.open("C:\\Users\\����ΰ��windows\\Desktop\\paint boarding\\shape.txt", std::ios::out);
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
	ifs.open("C:\\Users\\����ΰ��windows\\Desktop\\paint boarding\\shape.txt", std::ios::in);
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
			}//����while�����ʵ���˽��ṹ���е��������黯
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