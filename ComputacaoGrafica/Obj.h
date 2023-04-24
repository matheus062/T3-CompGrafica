#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <GL/freeglut.h>

using namespace std;

struct Face {
	vector<int> vi;
	vector<int> ti;
	vector<int> ni;

	Face(vector<int> vi, vector<int> ti, vector<int> ni) {
		this->vi = vi;
		this->ti = ti;
		this->ni = ni;
	}
};

class Obj
{
public:
	unsigned int idGlList;

	float speed;
	float scale;
	float pos[3];
	float rotation[3];

	vector<Face> faces;
	vector<vector<float>> vertexes;
	vector<vector<float>> normals;
	vector<vector<float>> textures;

	Obj();
	bool loadObjFile(string fileName);
	bool createGlList();
	void walkUp();
	void walkDown();
	void walkLeft();
	void walkRight();
	void walkFront();
	void walkBack();
	void scaleUp();
	void scaleDown();
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
};

