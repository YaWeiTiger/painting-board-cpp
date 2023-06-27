#pragma once
#include "menu.h"
#include "main.h"
#include "graphics.h"
class Controller//窗口类
{
private:
    int width{ 640 };
    int height{ 480 };
public:
    Controller() = default;
    Controller(int width_, int height_)
    {
        height = height_;
        width = width_;
    }
    void setHeight(int height)
    {
        this->height = height;
    }
    void setWidth(int width)
    {
        this->width = width;
    }
    int getHeight()
    {
        return height;
    }
    int getWidth()
    {
        return width;
    }
    void open()
    {
        initgraph(width, height);
    }
    void close()
    {
        closegraph();
    }
};
class Point//点类
{
private:
    int x{ 0 }, y{ 0 };
    int radius{ 0 };
    int stangle{ 0 };
    int endangle{ 0 };
    int num{ 3 };
public:
    Point()
    {
        int x = 0;
        int y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    ~Point() = default;
    void setPtx(int x)
    {
        this->x = x;
    }
    void setPty(int y)
    {
        this->y = y;
    }
    int getPtx()
    {
        return x;
    }
    int getPty()
    {
        return y;
    }
    void setRadius(int radius)
    {
        this->radius = radius;
    }
    int getRadius()
    {
        return radius;
    }
    void setStangle(int stangle)
    {
        this->stangle = stangle;
    }
    void setEndangle(int endangle)
    {
        this->endangle = endangle;
    }
    int getStangle()
    {
        return stangle;
    }
    int getEndangle()
    {
        return endangle;
    }
    void setNum(int num)
    {
        this->num = num;
    }
    int getNum()
    {
        return num;
    }
     Point operator+(Point &p)
    {
        Point point;
        point.setPtx((point.x + p.x) / 2);
        point.setPty((point.y + p.y) / 2);
        return point;
    }
     bool operator == (Point& p)
     {
         if ((this->x == p.x) && (this->y == p.y))
         {
             return true;
         }
         else 
         {
             return false;
         }
     }
     bool operator != (Point& p)
     {
         if ((this->x != p.x) || (this->y != p.y))
         {
             return true;
         }
         else
         {
             return false;
         }
     }
     int& operator[](const int& i)
     {
         if (i == 0)
         {
             return x;
         }
         if (i == 1)
         {
             return y;
         }
     }
};
class Shape
{
private:
    int R{ 0 }, G{ 0 }, B{ 0 };
    int R_{ 0 }, G_{ 0 }, B_{ 0 };
    int cate;
    bool filled{ 1 };
public:
    Point point[50];
    static int cnt;
    double getS();
    Shape() = default;
    Shape(const Shape& s)
    {
        R = s.R;
        R_ = s.R_;
        B = s.B;
        B_ = s.B_;
        G = s.G;
        G = s.G_;
        cate = s.cate;
        filled = s.filled;
    }
    void setCate(int cate)
    {
        this->cate = cate;
    }
    void setRvalue(int r)
    {
        R = r;
    }
    void setGvalue(int g)
    {
        G = g;
    }
    void setBvalue(int b)
    {
        B = b;
    }
    int getCate()
    {
        return cate;
    }
    int getRvalue()
    {
        return R;
    }
    int getGvalue()
    {
        return G;
    }
    int getBvalue()
    {
        return B;
    }
    void linecolor()
    {
        setcolor(EGERGB(R, G, B));
    }
    void fillcolor()
    {
        setfillcolor(EGERGB(R_, G_, B_));
    }
    void setFilled(bool filled)
    {
        this->filled = filled;
    }
    bool getFilled()
    {
        return filled;
    }
    void setR_value(int r)
    {
        R_ = r;
    }
    void setG_value(int g)
    {
        G_ = g;
    }
    void setB_value(int b)
    {
        B_ = b;
    }
    int getR_value()
    {
        return R_;
    }
    int getG_value()
    {
        return G_;
    }
    int getB_value()
    {
        return B_;
    }
    bool operator >(Shape &shape)
    {
        if (this->getS() > shape.getS())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator >=(Shape& shape)
    {
        if (this->getS() >= shape.getS())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator <(Shape& shape)
    {
        if (this->getS() < shape.getS())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator <=(Shape& shape)
    {
        if (this->getS() <= shape.getS())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator ==(Shape& shape)
    {
        if (this->getS() == shape.getS())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator !=(Shape& shape)
    {
        if (this->getS() != shape.getS())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Shape& operator = (const Shape& shape)
    {
        if (this != &shape)
        {
            this->cate = shape.cate;
            this->R = shape.R;
            this->R_ = shape.R_;
            this->G = shape.G;
            this->G_ = shape.G_;
            this->B = shape.B;
            this->B_ = shape.B_;
            this->filled = shape.filled;
        }
        return *this;
    }
    int operator [](const int& i)
    {
       if (i == 0)
       {
           return this->point[0].getPtx();
       }
       else if (i == 1)
       {
           return this->point[0].getPty();
       }
       else if (i == 2)
       {
           return this->point[1].getPtx();
       }
       else if (i == 3)
       {
           return this->point[1].getPty();
       }
       else if (i == 4)
       {
           return this->point[2].getPtx();
       }
       else if (i == 5)
       {
           return this->point[2].getPty();
       }
       else if (i == 6)
       {
           return this->point[3].getPtx();
       }
       else if (i == 7)
       {
           return this->point[3].getPty();
       }
    }
};
class Color:public Shape//颜色类
{
private:
    int R{ 0 }, G{ 0 }, B{ 0 };
    int* p;
public:
    Color()
    {
        p = new int(10);
    }
    Color(int R, int G, int B)
    {
        this->R = R;
        this->G = G;
        this->B = B;
        p = new int(10);
    }
    Color(const Color& c)
    {
        R = c.R;
        G = c.G;
        B = c.B;
        p = new int(10);
        *p = *(c.p);
    }
    ~Color() 
    {
        delete p;
    }
    bool operator==(Color& color)
    {
        if (this->R == color.R && this->G == color.G && this->B == color.B)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(Color& color)
    {
        if (this->R != color.R ||this->G != color.G || this->B != color.B)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int& operator[](const int& i)
    {
        if (i == 0)
        {
            return R;
        }
        else if (i == 1)
        {
            return G;
        }
        else if (i == 2)
        {
            return B;
        }
    }
    Color operator ++(int)
    {
        Color temp = *this;
        if(R < 255)
            this->R++; 
        if (G < 255)
            this->G++; 
        if (B < 255)
            this->B++;
        return temp;
    }
    Color operator --(int)
    {
        Color temp = *this;
        if (R > 0)
            this->R--;
        if (G > 0)
            this->G--;
        if (B > 0)
            this->B--;
        return temp;
    }
};
class Isfilled: public Shape//填充类
{
private:
    bool filled{ 1 };
   
public:
    Isfilled() = default;
    Isfilled( bool isfilled)
    {
        this->filled = filled;
    }
   
};
class Circle:public Shape,public Point //圆类
{
private:
    int radius{ 0 };
    int* p;
public:
    Circle()
    {
        p = new int(10);
    }
    Circle(int radius_)
    {
        radius = radius_;
        p = new int(10);
    }
    ~Circle()
    {
        delete p;
    }
    double getS()
    {
        return (3.14 * radius * radius);
    }
};
class Arcc :public Shape,public Point//圆弧类
{
private:
    int radius{ 0 };
    int stangle{ 0 };
    int endangle{ 0 };
    int* p;
public:
    Arcc()
    {
        p = new int(10);
    }
    Arcc(int radius_)
    {
        radius = radius_;
        p = new int(10);
    }
   
    ~Arcc()
    {
        delete p;
    }
   
};
class Triangle :public Shape ,public Point //三角形类
{
private:
    int num{ 3 };//用于表示三角形的边数
    int* p;
public:
    Point pt[10];//用于储存三角形各点坐标
    Triangle()
    {
        p = new int(10);
    }
    Triangle(int num)
    {
        this->num = num;
        p = new int(10);
    }
    ~Triangle()
    {
        delete p;
    }
    double getS()
    {
        return((1 / 2)*(pt[0].getPtx()*pt[1].getPty() + pt[0].getPty()*pt[2].getPtx() + pt[0].getPty() * pt[1].getPtx()* pt[2].getPty()
            - pt[2].getPtx()*pt[1].getPty() - pt[0].getPtx() * pt[2].getPty() - pt[1].getPtx()*pt[0].getPty()));
    }
    
};
class Rectanglee :public Shape,public Point//矩形类
{
private:
    int* p;
    
public:
    int left = 0;
    int top = 0;
    int right = 0;
    int bottom = 0;
    Rectanglee()
    {
        p = new int(10);
    }
    ~Rectanglee()
    {
        delete p;
    }
    /*void setLeft(int left)
    {
        this->left = left;
    }
    void setRight(int right)
    {
        this->right = right;
    }
    void setTop(int top)
    {
        this->top = top;
    }
    void setBottom(int bottom)
    {
        this->bottom = bottom;
    }
    int getLeft()
    {
        return left;
    }
    int getRight()
    {
        return right;
    }
    int getTop()
    {
        return top;
    }
    int getBottom()
    {
        return bottom;
    }*/
    double getS()
    {
        return((right-left)*(bottom - top));
    }
    
};