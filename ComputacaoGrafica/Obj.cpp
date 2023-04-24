#include "Obj.h"

Obj::Obj() {
	this->pos[0] = 0;
	this->pos[1] = 0;
	this->pos[2] = -200;

	this->rotation[0] = 0;
	this->rotation[1] = 0;
	this->rotation[2] = 0;

	this->scale = 1.0;
	this->speed = 2.0;
	this->idGlList = -1;
}

bool Obj::loadObjFile(string fileName) {
	ifstream file(fileName);

	if (!file.is_open()) {
		throw runtime_error("Arquivo " + fileName + " não encontrado.");
	}

	string type;

	while (file >> type)
	{
		if (type == "f")
		{
			vector<int> vi;
			vector<int> ti;
			vector<int> ni;

			string a, b, c;
			file >> a >> b >> c;

			int v1, v2, v3;
			int t1, t2, t3;
			int n1, n2, n3;

			v1 = stoi(a.substr(0, a.find("/"))) - 1;
			v2 = stoi(b.substr(0, b.find("/"))) - 1;
			v3 = stoi(c.substr(0, c.find("/"))) - 1;

			a.erase(0, a.find("/") + 1);
			b.erase(0, b.find("/") + 1);
			c.erase(0, c.find("/") + 1);

			t1 = (a.find("/") != 0)
				? stoi(a.substr(0, a.find("/"))) - 1
				: -1;
			t2 = (b.find("/") != 0)
				? stoi(b.substr(0, b.find("/"))) - 1
				: -1;
			t3 = (c.find("/") != 0)
				? stoi(c.substr(0, c.find("/"))) - 1
				: -1;

			a.erase(0, a.find("/") + 1);
			b.erase(0, b.find("/") + 1);
			c.erase(0, c.find("/") + 1);

			n1 = stoi(a) - 1;
			n2 = stoi(b) - 1;
			n3 = stoi(c) - 1;

			vi.push_back(v1);
			vi.push_back(v2);
			vi.push_back(v3);

			ti.push_back(t1);
			ti.push_back(t2);
			ti.push_back(t3);

			ni.push_back(n1);
			ni.push_back(n2);
			ni.push_back(n3);

			faces.push_back(Face(vi, ti, ni));
		}
		else if (type == "v")
		{
			vector<float> vertex;
			float x, y, z;
			file >> x >> y >> z;
			vertex.push_back(x);
			vertex.push_back(y);
			vertex.push_back(z);
			vertexes.push_back(vertex);
		}
		else if (type == "vn")
		{
			vector<float> normal;
			float x, y, z;
			file >> x >> y >> z;
			normal.push_back(x);
			normal.push_back(y);
			normal.push_back(z);
			normals.push_back(normal);
		}
		else if (type == "vt") {
			vector<float> texture;
			float x, y;
			file >> x >> y;
			texture.push_back(x);
			texture.push_back(y);
			textures.push_back(texture);
		}
	}

	file.close();

	return this->createGlList();
}

bool Obj::createGlList() {
	this->idGlList = glGenLists(1);
	glPointSize(2.0);

	glNewList(this->idGlList, GL_COMPILE);

	glPushMatrix();

	for (int i = 0; i < faces.size(); i++)
	{
		glBegin(GL_TRIANGLES);

		Face face = this->faces[i];

		glNormal3f(this->normals[face.ni[0]][0], this->normals[face.ni[0]][1], this->normals[face.ni[0]][2]);
		glVertex3f(
			this->vertexes[face.vi[0]][0],
			this->vertexes[face.vi[0]][1],
			this->vertexes[face.vi[0]][2]
		);

		glNormal3f(this->normals[face.ni[1]][0], this->normals[face.ni[1]][1], this->normals[face.ni[1]][2]);
		glVertex3f(
			this->vertexes[face.vi[1]][0],
			this->vertexes[face.vi[1]][1],
			this->vertexes[face.vi[1]][2]
		);

		glNormal3f(this->normals[face.ni[2]][0], this->normals[face.ni[2]][1], this->normals[face.ni[2]][2]);
		glVertex3f(
			this->vertexes[face.vi[2]][0],
			this->vertexes[face.vi[2]][1],
			this->vertexes[face.vi[2]][2]
		);

		glEnd();
	}


	glPopMatrix();
	glEndList();

	return true;
}

void Obj::walkUp() {
	this->pos[1] += this->speed;
}

void Obj::walkDown() {
	this->pos[1] -= this->speed;
}

void Obj::walkLeft() {
	this->pos[0] -= this->speed;
}

void Obj::walkRight() {
	this->pos[0] += this->speed;
}

void Obj::walkFront() {
	this->pos[2] -= this->speed;
}

void Obj::walkBack() {
	this->pos[2] += this->speed;
}

void Obj::scaleUp() {
	this->scale *= 1.1f;
}

void Obj::scaleDown() {
	this->scale /= 1.1f;
}

void Obj::rotateX(float angle) {
	this->rotation[0] += angle;

	if (this->rotation[0] > 360) {
		this->rotation[0] -= 360;
	}
	else if (this->rotation[0] < 0) {
		this->rotation[0] += 360;
	}
}

void Obj::rotateY(float angle) {
	this->rotation[1] += angle;

	if (this->rotation[1] > 360) {
		this->rotation[1] -= 360;
	}
	else if (this->rotation[1] < 0) {
		this->rotation[1] += 360;
	}
}

void Obj::rotateZ(float angle) {
	this->rotation[2] += angle;

	if (this->rotation[2] > 360) {
		this->rotation[2] -= 360;
	}
	else if (this->rotation[2] < 0) {
		this->rotation[2] += 360;
	}
}