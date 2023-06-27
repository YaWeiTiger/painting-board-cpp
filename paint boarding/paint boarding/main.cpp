#include"graphics.h"
#include"menu.h"
#include"class.h"
int Shape::cnt{ 0 };
int main()
{
    char operate;//用于决定用户的操作
    char str[1000];
    Point p[10];
    Rectanglee r;
    int left, top, right, bottom;
    int point_{ 0 };//绘制多边形时用来储存多边形的相关参数
    int i{ 0 };//存储多边形点坐标时使用的变量
    int data[500];//以上三行初始化用于多边形的描述
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
            xyprintf(10, 10, "请仔细阅读菜单后重新输入");
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
                    inputbox_getline("圆弧的参数输入", "是否需要填充", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setFilled(atoi(str));
                    if (shape[Shape::cnt].getFilled() == 1)
                    {
                        inputbox_getline("圆弧的参数输入", "请输入圆弧的填充颜色R值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setR_value(atoi(str));
                        inputbox_getline("圆弧的参数输入", "请输入圆弧的填充颜色G值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setG_value(atoi(str));
                        inputbox_getline("圆弧的参数输入", "请输入圆弧的填充颜色B值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setB_value(atoi(str));
                        shape[Shape::cnt].fillcolor();
                    }
                    inputbox_getline("圆弧的参数输入", "请输入圆心的x轴坐标", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPtx(atoi(str));
                    inputbox_getline("圆弧的参数输入", "请输入圆心的y轴坐标", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPty(atoi(str));
                    inputbox_getline("圆弧的参数输入", "请输入起始角的角度", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setStangle(atoi(str));
                    inputbox_getline("圆弧的参数输入", "请输入终止角的角度", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setEndangle(atoi(str));
                    inputbox_getline("圆弧的参数输入", "请输入圆弧的半径", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setRadius(atoi(str));
                    inputbox_getline("圆弧的参数输入", "请输入圆弧的颜色R值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setRvalue(atoi(str));
                    inputbox_getline("圆弧的参数输入", "请输入圆弧的颜色G值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setGvalue(atoi(str));
                    inputbox_getline("圆弧的参数输入", "请输入圆弧的颜色B值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setBvalue(atoi(str));
                    shape[Shape::cnt].linecolor();
                    arc(shape[Shape::cnt].point[0].getPtx(), shape[Shape::cnt].point[0].getPty(), shape[Shape::cnt].point[0].getStangle(), shape[Shape::cnt].point[0].getEndangle(), shape[Shape::cnt].point[0].getRadius());
                    Shape::cnt++;
                    break;
                case'2':
                    inputbox_getline("圆的参数输入", "是否需要填充", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setFilled(atoi(str));
                    if (shape[Shape::cnt].getFilled() == 1)
                    {
                        inputbox_getline("圆的参数输入", "请输入圆的填充颜色R值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setR_value(atoi(str));
                        inputbox_getline("圆的参数输入", "请输入圆的填充颜色G值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setG_value(atoi(str));
                        inputbox_getline("圆的参数输入", "请输入圆的填充颜色B值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setB_value(atoi(str));
                        shape[Shape::cnt].fillcolor();
                    }
                    inputbox_getline("圆的圆心参数输入", "请输入圆心的x轴坐标", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPtx(atoi(str));
                    inputbox_getline("圆的圆心参数输入", "请输入圆心的y轴坐标", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPty(atoi(str));
                    inputbox_getline("圆的参数输入", "请输入圆的半径", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setRadius(atoi(str));
                    inputbox_getline("圆的参数输入", "请输入圆的线颜色R值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setRvalue(atoi(str));
                    inputbox_getline("圆的参数输入", "请输入圆的线颜色G值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setGvalue(atoi(str));
                    inputbox_getline("圆的参数输入", "请输入圆的线颜色B值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setBvalue(atoi(str));
                    shape[Shape::cnt].linecolor();
                    fillellipse(shape[Shape::cnt].point[0].getPtx(), shape[Shape::cnt].point[0].getPty(), shape[Shape::cnt].point[0].getRadius(), shape[Shape::cnt].point[0].getRadius());
                    Shape::cnt++;
                    break;
                case'3':
                    inputbox_getline("三角形的参数输入", "是否需要填充", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setFilled(atoi(str));
                    if (shape[Shape::cnt].getFilled() == 1)
                    {
                        inputbox_getline("三角形的参数输入", "请输入三角形的填充颜色R值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setR_value(atoi(str));
                        inputbox_getline("三角形的参数输入", "请输入三角形的填充颜色G值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setG_value(atoi(str));
                        inputbox_getline("三角形的参数输入", "请输入三角形的填充颜色B值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setB_value(atoi(str));
                        shape[Shape::cnt].fillcolor();
                    }
                    shape[Shape::cnt].point[point_].setNum(3);
                    inputbox_getline("三角形的参数输入", "请输入三角形的颜色R值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setRvalue(atoi(str));
                    inputbox_getline("三角形的参数输入", "请输入三角形的颜色G值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setGvalue(atoi(str));
                    inputbox_getline("三角形的参数输入", "请输入三角形的颜色B值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setBvalue(atoi(str));
                    shape[Shape::cnt].linecolor();
                    for (point_ = 0; point_ <= shape[Shape::cnt].point[point_].getNum(); point_++)
                    {
                        inputbox_getline("三角形坐标", "请输入三角形点的x坐标\n(依次输入一个，每个点分别进行输入)", str, (sizeof(str) / sizeof(*str)));
                        shape[Shape::cnt].point[point_].setPtx(atoi(str));
                        inputbox_getline("三角形坐标", "请输入三角形点的y坐标\n(依次输入一个，每个点分别进行输入)", str, (sizeof(str) / sizeof(*str)));
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
                    }//以上while代码段实现了将结构体中的数据数组化
                    fillpoly(shape[Shape::cnt].point[point_].getNum(), data);
                    Shape::cnt++;
                    break;
                case'4':
                    inputbox_getline("矩形的参数输入", "是否需要填充", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setFilled(atoi(str));
                    if (shape[Shape::cnt].getFilled() == 1)
                    {
                        inputbox_getline("矩形的参数输入", "请输入矩形的填充颜色R值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setR_value(atoi(str));
                        inputbox_getline("矩形的参数输入", "请输入矩形的填充颜色G值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setG_value(atoi(str));
                        inputbox_getline("矩形的参数输入", "请输入矩形的填充颜色B值", str, sizeof(str) / sizeof(*str));
                        shape[Shape::cnt].setB_value(atoi(str));
                        setfillcolor(EGERGB(shape[Shape::cnt].getR_value(), shape[Shape::cnt].getG_value(), shape[Shape::cnt].getB_value()));
                    }
                    inputbox_getline("矩形的参数输入", "矩形左部x坐标", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPtx(atoi(str));
                    inputbox_getline("矩形的参数输入", "矩形上部y坐标", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[0].setPty(atoi(str));
                    left = shape[Shape::cnt].point[0].getPtx();
                    top = shape[Shape::cnt].point[0].getPty();
                    inputbox_getline("矩形的参数输入", "矩形右部x坐标", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[1].setPtx(atoi(str));
                    inputbox_getline("矩形的参数输入", "矩形下部y坐标", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].point[1].setPty(atoi(str));
                    right = shape[Shape::cnt].point[1].getPtx();
                    bottom = shape[Shape::cnt].point[1].getPty();
                    inputbox_getline("矩形的参数输入", "请输入矩形的颜色R值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setRvalue(atoi(str));
                    inputbox_getline("矩形的参数输入", "请输入矩形的颜色G值", str, sizeof(str) / sizeof(*str));
                    shape[Shape::cnt].setGvalue(atoi(str));
                    inputbox_getline("矩形的参数输入", "请输入矩形的颜色B值", str, sizeof(str) / sizeof(*str));
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
                cnt--;//撤销之后，图形数目减1
                break;
                功能尚未完善
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