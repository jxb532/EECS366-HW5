#pragma once

class Vertex
{
public:
	Vertex();
	void Normalize();
	Vertex operator*(float scalar);
	Vertex operator/(float scalar);
	Vertex operator+(const Vertex &vertex);
	Vertex operator-(const Vertex &vertex);
	float x, y, z, h;
};

class Vector
{
public:
	float i, j, k;
};

class Face
{
public:
	int v1, v2, v3;
};

class Object
{
public:
	Object();
	~Object();
	void Load(char* file, float s, float rx, float ry, float rz,
				  float tx, float ty, float tz);
	void WorldTranslate(float tx, float ty, float tz);
	void WorldRotate(float rx, float ry, float rz);
	void LocalRotate(float rx, float ry, float rz);
	void LocalScale(float s);
	Vertex* pBoundingBox;
	Vertex* pVertexList;
	int VertexCount;
	Face* pFaceList;
	int FaceCount;
	float ModelMatrix[16];
};

class Scene
{
public:
	void Load(char* file);
	Object* pObjectList;
	int ObjectCount;
};

class Camera
{
public:
	Camera();
	void Move(float tx, float ty, float tz);
	void Pan(float y, float p);
	void ScaleView(float s);
	void MoveView(float d);
	// ADD CODE HERE: functionality to move far/near planes is needed
	void EnforceVectors();
	void Perspective();
	void Orthographic();
	void LookAt();
	Vertex Position;
	float Pitch, Yaw;
	Vector n;
	Vector v;
	Vector u;
	float FarPlane, NearPlane, ViewPlane;
	float ViewWidth, ViewHeight;
	float ViewingMatrix[16];
	float ProjectionMatrix[16];
};

Vertex Transform(float* matrix, Vertex& point);
int Select(int previous, Scene* pScene, Camera* pCamera, float x, float y);
Vertex* ClipPolygon(int count, Vertex* input, int* out_count);
Vertex* ClipLeft(int count, Vertex* input, int* out_count);
Vertex* ClipRight(int count, Vertex* input, int* out_count);
Vertex* ClipBottom(int count, Vertex* input, int* out_count);
Vertex* ClipTop(int count, Vertex* input, int* out_count);
Vertex* ClipYon(int count, Vertex* input, int* out_count);
Vertex* ClipHither(int count, Vertex* input, int* out_count);
float getAlpha(float t1, float t2, float w1, float w2);
Vertex getIntersection(Vertex p1, Vertex p2, float alpha);