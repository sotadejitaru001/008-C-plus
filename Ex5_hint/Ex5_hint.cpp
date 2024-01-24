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
	virtual double GetVolume() = 0;
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
	double GetVolume() override
	{
		return width * height * depth;
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
	double GetVolume()override
	{
		return radius * radius * M_PI * height;
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
	double GetVolume()override
	{
		return radius * radius * M_PI * height * 1 / 3;
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
	double GetVolume()override
	{
		return 4.0 / 3 * radius * radius * radius * M_PI;
	}
	string message()
	{
		return "球";
	}
};


int main()
{
	Box box{ 9,2,10 };
	Cylinder cylinder{ 2,5 };
	Cone cone{ 3,3 };
	Sphere sphere{ 3 };
	int kuroneko[]={60,80,100,120,140,160,180,200};
	int yuupack[] = { 60,80,100,120,140,160,170};
	Solid* solids[] = { &box, &cylinder, &cone, &sphere };
	for (Solid* s : solids)
	{
		for (int i = 0; i < _countof(kuroneko); i++)
		{
			
			if (kuroneko[i] >= s->GetVolume()) {
				if (i < _countof(kuroneko)) {
					cout << s->message() << ":体積=" << s->GetVolume() << endl;
					cout << kuroneko[i] << "サイズ" << " " <<"黒猫" << endl;
				}
				break;
			}
		}
		if (s->GetVolume() >kuroneko[7]) {
			cout << s->message() << "は送れません" << " " << "黒猫" << endl;
		}
		for (int i = 0; i < _countof(yuupack); i++)
		{
			if (yuupack[i] >= s->GetVolume()) {
				if (i < _countof(yuupack)) {
					cout << yuupack[i] << "サイズ" << " " << "ゆうパック" << "\n" << endl;
				}
				break;
			}
		}
		if (s->GetVolume()>yuupack[6]) {
			cout << s->message() << "は送れません" << " " << "ゆうパック" << "\n" << endl;
		}
	};
}