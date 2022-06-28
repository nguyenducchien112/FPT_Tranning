#pragma once
#include<Windows.h>

class CShape {
public:
	int color;
	virtual	void draw(int , int , HDC ) = 0;
};

class CCircle : public CShape {
private:
	int radium;
public:
	CCircle(int, int);
	void draw(int, int, HDC);
};

class CLine : public CShape {
private:
	int length;
public:
	CLine(int , int );
	void draw(int , int , HDC );
};


class CRectangle : public CShape {
protected:
	int width;
	int heigh;
public:
	CRectangle();
	CRectangle(int , int , int );
	void draw(int , int , HDC );
};

class CSquare : public CRectangle {
public:
	CSquare(int , int );
	void draw(int , int , HDC );
};

class CPicture {
public:
	CShape* picture[4];
};