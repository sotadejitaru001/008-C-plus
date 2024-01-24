#include <iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<cmath>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid
{
public:
	virtual double GetSize() = 0;
	virtual string message() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :public Solid
{
private:
	double width;
	double height;
	double depth;

public:
	Box(double width, double height, double depth)
	{
		this->width = width;
		this->height = height;
		this->depth = depth;
	}
	double GetSize() override
	{
		return width + height + depth;
	}
	string message()
	{
		return "四角";
	}
};
class Cylinder :public Solid
{
private:
	double radius;
	double height;

public:
	Cylinder(double radius, double height)
	{
		this->radius = radius;
		this->height = height;
	}
	double GetSize()override
	{
		return radius * 4+ height;
	}
	string message()
	{
		return "円柱";
	}
};

class Cone :public Solid
{
private:
	double radius;
	double height;

public:
	Cone(double radius, double height)
	{
		this->radius = radius;
		this->height = height;
	}
	double GetSize()override
	{
		return radius * 4 + height;
	}
	string message()
	{
		return "円錐";
	}
};

class Sphere : public Solid
{
private:
	double radius;
public:
	Sphere(double radius)
	{
		this->radius = radius;
	}
	double GetSize()override
	{
		return radius * 6;
	}
	string message()
	{
		return "球";
	}
};


int main()
{
	Box box{ 20,50,110 };
	Cylinder cylinder{ 50,50 };
	Cone cone{ 30,30 };
	Sphere sphere{ 20 };
	int kuroneko[]={60,80,100,120,140,160,180,200};
	int yuupack[] = { 60,80,100,120,140,160,170};
	Solid* solids[] = { &box, &cylinder, &cone, &sphere };
	for (Solid* s : solids)
	{
		for (int i = 0; i < _countof(kuroneko); i++)
		{
			
			if (kuroneko[i] >= s->GetSize()) {
				if (i < _countof(kuroneko)) {
					cout << s->message() << ":体積=" << s->GetSize() << endl;
					cout << kuroneko[i] << "サイズ" << " " <<"黒猫" << endl;
				}
				break;
			}
		}
		if (s->GetSize() >kuroneko[7]) {
			cout << s->message() << ":体積=" << s->GetSize() << endl;
			cout << s->message() << "は送れません" << " " << "黒猫" << endl;
		}
		for (int i = 0; i < _countof(yuupack); i++)
		{
			if (yuupack[i] >= s->GetSize()) {
				if (i < _countof(yuupack)) {
					cout << yuupack[i] << "サイズ" << " " << "ゆうパック" << "\n" << endl;
				}
				break;
			}
		}
		if (s->GetSize()>yuupack[6]) {
			cout << s->message() << "は送れません" << " " << "ゆうパック" << "\n" << endl;
		}
	};
}