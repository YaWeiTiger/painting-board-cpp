#include"graphics.h"
#include"menu.h"
#include"class.h"
int Shape::cnt{ 0 };
int main()
{
    char operate;//���ھ����û��Ĳ���
    char str[1000];
    Point p[10];
    Rectanglee r;
    int left, top, right, bottom;
    int point_{ 0 };//���ƶ����ʱ�����������ε���ز���
    int i{ 0 };//�洢����ε�����ʱʹ�õı���
    int data[500];//�������г�ʼ�����ڶ���ε�����
    initialboard();
  read:
    readmenu();
    while (true)
    {
        wholemenu();
        operate = getch();
        if (operate != '1' && operate != '2' && operate != '3' && operate != '4' && operate != '5' && operate != '6' && operate != '7')
        {
            cleardevice();
            xyprintf(10, 10, "����ϸ�Ķ��˵�����������");
            getch();
            cleardevice();
        }
        else
        {
            switch (operate)
            {
            case '1':
                cleardevice();
                Shape::cnt = 0;
                break;
            case '2':
                paintmenu();
                shape[Shape::cnt].setCate(getch());
                switch (shape[Shape::cnt].getCate())
                {
                case'1':
                    inputbox_getline("Բ���Ĳ�������", "�Ƿ���Ҫ���", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setFilled(atoi(str));
                    if (shape[Shape::cnt].getFilled() == 1)
                    {
                        inputbox_getline("Բ���Ĳ�������", "������Բ���������ɫRֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setR_value(atoi(str));
                        inputbox_getline("Բ���Ĳ�������", "������Բ���������ɫGֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setG_value(atoi(str));
                        inputbox_getline("Բ���Ĳ�������", "������Բ���������ɫBֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setB_value(atoi(str));
                        shape[Shape::cnt].fillcolor();
                    }
                    inputbox_getline("Բ���Ĳ�������", "������Բ�ĵ�x������", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPtx(atoi(str));
                    inputbox_getline("Բ���Ĳ�������", "������Բ�ĵ�y������", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPty(atoi(str));
                    inputbox_getline("Բ���Ĳ�������", "��������ʼ�ǵĽǶ�", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setStangle(atoi(str));
                    inputbox_getline("Բ���Ĳ�������", "��������ֹ�ǵĽǶ�", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setEndangle(atoi(str));
                    inputbox_getline("Բ���Ĳ�������", "������Բ���İ뾶", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setRadius(atoi(str));
                    inputbox_getline("Բ���Ĳ�������", "������Բ������ɫRֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setRvalue(atoi(str));
                    inputbox_getline("Բ���Ĳ�������", "������Բ������ɫGֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setGvalue(atoi(str));
                    inputbox_getline("Բ���Ĳ�������", "������Բ������ɫBֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setBvalue(atoi(str));
                    shape[Shape::cnt].linecolor();
                    arc(shape[Shape::cnt].point[0].getPtx(), shape[Shape::cnt].point[0].getPty(), shape[Shape::cnt].point[0].getStangle(), shape[Shape::cnt].point[0].getEndangle(), shape[Shape::cnt].point[0].getRadius());
                    Shape::cnt++;
                    break;
                case'2':
                    inputbox_getline("Բ�Ĳ�������", "�Ƿ���Ҫ���", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setFilled(atoi(str));
                    if (shape[Shape::cnt].getFilled() == 1)
                    {
                        inputbox_getline("Բ�Ĳ�������", "������Բ�������ɫRֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setR_value(atoi(str));
                        inputbox_getline("Բ�Ĳ�������", "������Բ�������ɫGֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setG_value(atoi(str));
                        inputbox_getline("Բ�Ĳ�������", "������Բ�������ɫBֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setB_value(atoi(str));
                        shape[Shape::cnt].fillcolor();
                    }
                    inputbox_getline("Բ��Բ�Ĳ�������", "������Բ�ĵ�x������", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPtx(atoi(str));
                    inputbox_getline("Բ��Բ�Ĳ�������", "������Բ�ĵ�y������", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPty(atoi(str));
                    inputbox_getline("Բ�Ĳ�������", "������Բ�İ뾶", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setRadius(atoi(str));
                    inputbox_getline("Բ�Ĳ�������", "������Բ������ɫRֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setRvalue(atoi(str));
                    inputbox_getline("Բ�Ĳ�������", "������Բ������ɫGֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setGvalue(atoi(str));
                    inputbox_getline("Բ�Ĳ�������", "������Բ������ɫBֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setBvalue(atoi(str));
                    shape[Shape::cnt].linecolor();
                    fillellipse(shape[Shape::cnt].point[0].getPtx(), shape[Shape::cnt].point[0].getPty(), shape[Shape::cnt].point[0].getRadius(), shape[Shape::cnt].point[0].getRadius());
                    Shape::cnt++;
                    break;
                case'3':
                    inputbox_getline("�����εĲ�������", "�Ƿ���Ҫ���", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setFilled(atoi(str));
                    if (shape[Shape::cnt].getFilled() == 1)
                    {
                        inputbox_getline("�����εĲ�������", "�����������ε������ɫRֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setR_value(atoi(str));
                        inputbox_getline("�����εĲ�������", "�����������ε������ɫGֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setG_value(atoi(str));
                        inputbox_getline("�����εĲ�������", "�����������ε������ɫBֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setB_value(atoi(str));
                        shape[Shape::cnt].fillcolor();
                    }
                    shape[Shape::cnt].point[point_].setNum(3);
                    inputbox_getline("�����εĲ�������", "�����������ε���ɫRֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setRvalue(atoi(str));
                    inputbox_getline("�����εĲ�������", "�����������ε���ɫGֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setGvalue(atoi(str));
                    inputbox_getline("�����εĲ�������", "�����������ε���ɫBֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setBvalue(atoi(str));
                    shape[Shape::cnt].linecolor();
                    for (point_ = 0; point_ <= shape[Shape::cnt].point[point_].getNum(); point_++)
                    {
                        inputbox_getline("����������", "�����������ε��x����\n(��������һ����ÿ����ֱ��������)", str, (sizeof(str) / sizeof(*str)));
                        shape[Shape::cnt].point[point_].setPtx(atoi(str));
                        inputbox_getline("����������", "�����������ε��y����\n(��������һ����ÿ����ֱ��������)", str, (sizeof(str) / sizeof(*str)));
                        shape[Shape::cnt].point[point_].setPty(atoi(str));
                    }
                    point_ = 0;
                    while (i < 2 * shape[Shape::cnt].point[point_].getNum())
                    {
                        data[i] = shape[Shape::cnt].point[point_].getPtx();
                        i++;
                        data[i] = shape[Shape::cnt].point[point_].getPty();
                        i++;
                        point_++;
                    }//����while�����ʵ���˽��ṹ���е��������黯
                    fillpoly(shape[Shape::cnt].point[point_].getNum(), data);
                    Shape::cnt++;
                    break;
                case'4':
                    inputbox_getline("���εĲ�������", "�Ƿ���Ҫ���", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setFilled(atoi(str));
                    if (shape[Shape::cnt].getFilled() == 1)
                    {
                        inputbox_getline("���εĲ�������", "��������ε������ɫRֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setR_value(atoi(str));
                        inputbox_getline("���εĲ�������", "��������ε������ɫGֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setG_value(atoi(str));
                        inputbox_getline("���εĲ�������", "��������ε������ɫBֵ", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setB_value(atoi(str));
                        setfillcolor(EGERGB(shape[Shape::cnt].getR_value(), shape[Shape::cnt].getG_value(), shape[Shape::cnt].getB_value()));
                    }
                    inputbox_getline("���εĲ�������", "������x����", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPtx(atoi(str));
                    inputbox_getline("���εĲ�������", "�����ϲ�y����", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPty(atoi(str));
                    left = shape[Shape::cnt].point[0].getPtx();
                    top = shape[Shape::cnt].point[0].getPty();
                    inputbox_getline("���εĲ�������", "�����Ҳ�x����", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[1].setPtx(atoi(str));
                    inputbox_getline("���εĲ�������", "�����²�y����", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[1].setPty(atoi(str));
                    right = shape[Shape::cnt].point[1].getPtx();
                    bottom = shape[Shape::cnt].point[1].getPty();
                    inputbox_getline("���εĲ�������", "��������ε���ɫRֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setRvalue(atoi(str));
                    inputbox_getline("���εĲ�������", "��������ε���ɫGֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setGvalue(atoi(str));
                    inputbox_getline("���εĲ�������", "��������ε���ɫBֵ", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setBvalue(atoi(str));
                    shape[Shape::cnt].linecolor();
                    r.left = left;
                    r.right = right;
                    r.top = top;
                    r.bottom = bottom;
                    rectangle(left, top, right, bottom);
                    if (shape[Shape::cnt].getFilled() == 1)
                        floodfill((left + right) / 2, (top + bottom) / 2,EGERGB(shape[Shape::cnt].getRvalue(), shape[Shape::cnt].getGvalue(), shape[Shape::cnt].getBvalue()));
                    Shape::cnt++;
                    break;
                case'5':
                    break;
                }
                break;
            case '3':
                flee();
                break;
            case'4':
                cleardevice();
                Shape::cnt = 0;
                goto read;
                break;
           /* case '5':
                cleardevice();
                repeal();
                cnt--;//����֮��ͼ����Ŀ��1
                break;
                ������δ����
                */
            case '6':
                maker();
                cleardevice();
                break;
            case '7':
                suggestions();
                break;
            }
        }
    }
}