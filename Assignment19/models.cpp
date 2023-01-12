// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
	glm::vec2 UV;
};

#define pi 3.14
#define pictureSize 1024
void cube();
void cylinder();

void normalize();

void setPoint(int pos, float x, float y, float z, float xT, float yT);



std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;


void makeModels() {

	cube();

	cylinder();

}

void cube() {

	int numberOfFaces = 8;
	M1_vertices.resize(numberOfFaces  * 3);


	// Resizes the indices array. Repalce the values with the correct number of
	// indices (number of triangles * 3)
	#define indicesArrayLengthEs1 12 * 3

	M1_indices.resize(indicesArrayLengthEs1);
	float x, y, z;
	float deltaX = 0.128;
	float deltaY = 0.128;
	float y0 = 0;
	float x0 = 0;

	float xT = 0;
	float yT = y0 + 0;

	// first vertex of M1
	int pos = 0;
	x = -1.0;
	y = -1.0;
	z = -1.0;
	//A
	xT = deltaX;
	yT = y0;
	setPoint(pos, x, y, z, xT, yT);
	//I
	pos += numberOfFaces;
	xT = deltaX;
	yT = y0 + 4 * deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//O
	pos += numberOfFaces;
	xT = 0;
	yT = y0 + deltaY;
	setPoint(pos, x, y, z, xT, yT);

	pos = 1;
	// second vertex of M1
	x = 1.0;
	y = -1.0;
	z = -1.0;
	//B
	xT = 0;
	yT = y0 + 2 * deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//D
	pos += numberOfFaces;
	xT = 3 * deltaX;
	yT = y0 + deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//H
	pos += numberOfFaces;
	xT = 2 * deltaX;
	yT = y0 + 4 * deltaY;
	setPoint(pos, x, y, z, xT, yT);

	pos = 2;
	// third vertex of M1
	x = 1.0;
	y = 1.0;
	z = -1.0;
	//E
	xT = 3 * deltaX;
	yT = y0 + 2 * deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//G
	pos += numberOfFaces;
	xT = 2 * deltaX;
	yT = y0 + 3 * deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);

	pos = 3;
	// fourth vertex of M1
	x = -1.0;
	y = 1.0;
	z = -1.0;
	//L
	xT = deltaX;
	yT = y0 + 3 * deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//N
	pos += numberOfFaces;
	xT = 0;
	yT = y0 + 2 * deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);


	//FRONT FACE
	pos = 4;
	// 5 vertex of M1
	x = -1.0;
	y = -1.0;
	z = 1.0;
	//P
	xT = deltaX;
	yT = y0 + deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);

	pos = 5;
	// 6 vertex of M1
	x = 1.0;
	y = -1.0;
	z = 1.0;
	//C
	xT = 2 * deltaX;
	yT = y0 + deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);

	pos = 6;
	// 7 vertex of M1
	x = 1.0;
	y = 1.0;
	z = 1.0;
	//F
	xT = 2 * deltaX;
	yT = y0 + 2 * deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);

	pos = 7;
	// 8 vertex of M1
	x = -1.0;
	y = 1.0;
	z = 1.0;
	//M
	xT = deltaX;
	yT = y0 + 2 * deltaY;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);
	//null
	pos += numberOfFaces;
	setPoint(pos, x, y, z, xT, yT);

	int indices[indicesArrayLengthEs1] = {
			0,1,2, //fb
			3,2,0, //ft
			4,7,0, //lt
			3,7,0, //lb
			3,7,2, //tl
			7,2,6, //tr
			6,2,1, //rt
			6,5,1, //lb
			0,4,5, //bl
			5,0,1, //br
			7,4,5, //fl
			5,7,6
	};


	for (int i = 0; i < indicesArrayLengthEs1; i++) {
		M1_indices.push_back(indices[i]);
	}

}

void cylinder() {

	double deltaPixel = 0.128;
	double x0 = 4*deltaPixel, y0 = 0;// deltaPixel * 4;
	int nCircleVertices = 20;

	glm::vec2 centerTopCan = glm::vec2(x0 + deltaPixel, y0 + deltaPixel);
	glm::vec2 centerBottomCan = glm::vec2(x0 + 3 * deltaPixel, y0 + deltaPixel);

	glm::vec2 topLeftCan = glm::vec2(x0, y0 + 2 * deltaPixel);
	glm::vec2 topRightCan = glm::vec2(x0 + 4 * deltaPixel, y0 + 2 * deltaPixel);
	glm::vec2 bottomLeftCan = glm::vec2(x0, y0 + 4 * deltaPixel);
	glm::vec2 bottomRightCan = glm::vec2(x0 + 4 * deltaPixel, y0 + 4 * deltaPixel);

	int centerUpIndex = nCircleVertices * 2;
	int centerDownIndex = nCircleVertices * 2 + 1;

	float x, y, z;


	std::vector<float> circleVertices;
	std::vector<uint32_t> circleIndices;

	M2_vertices.resize((nCircleVertices + 1) * 2);

	//numCircleVertices + center
	M2_indices.resize(nCircleVertices * 4 * 3);


	//center up and down
	M2_vertices[centerUpIndex].pos = glm::vec3(0, 1, 0);
	M2_vertices[centerUpIndex].norm = glm::vec3(0, 1, 0);
	M2_vertices[centerUpIndex].UV = centerTopCan;
	

	M2_vertices[centerDownIndex].pos = glm::vec3(0, -1, 0);
	M2_vertices[centerDownIndex].norm = glm::vec3(0, -1, 0);
	M2_vertices[centerDownIndex].UV = centerBottomCan;

	//1 first
	M2_vertices[0].pos = glm::vec3(cos(0), 1, sin(0));
	M2_vertices[0].norm = glm::vec3(cos(0), 1, sin(0));
	M2_vertices[0].UV = topLeftCan;

	M2_vertices[1].pos = glm::vec3(cos(0), -1, sin(0));
	M2_vertices[1].norm = glm::vec3(cos(0), -1, sin(0));
	M2_vertices[1].UV = bottomLeftCan;


	float currXOnPicture;
	for (int line = 1; line < nCircleVertices; line++) {

		//points of new line
		x = cos(2 * pi / nCircleVertices * line);
		y = 1;
		z = sin(2 * pi / nCircleVertices * line);


		currXOnPicture = x0 + 4 * deltaPixel * (nCircleVertices - line) / nCircleVertices;
		M2_vertices[2 * line].pos = glm::vec3(x, y, z);
		M2_vertices[2 * line].norm = glm::vec3(x, y, z);
		M2_vertices[2 * line].UV = glm::vec2(currXOnPicture, topLeftCan.y);


		y = -1;
		M2_vertices[2 * line + 1].pos = glm::vec3(x, y, z);
		M2_vertices[2 * line + 1].norm = glm::vec3(x, y, z);
		M2_vertices[2 * line + 1].UV = glm::vec2(currXOnPicture, bottomLeftCan.y);

		//connect currentLine with previous line
		M2_indices[(line - 1) * 12] = line * 2 - 2;
		M2_indices[(line - 1) * 12 + 1] = line * 2 - 1;
		M2_indices[(line - 1) * 12 + 2] = line * 2;
		M2_indices[(line - 1) * 12 + 3] = line * 2;
		M2_indices[(line - 1) * 12 + 4] = line * 2 - 1;
		M2_indices[(line - 1) * 12 + 5] = line * 2 + 1;

		//draw up triangle
		M2_indices[(line - 1) * 12 + 6] = line * 2 - 2;
		M2_indices[(line - 1) * 12 + 7] = line * 2;
		M2_indices[(line - 1) * 12 + 8] = centerUpIndex;

		//draw down triangle
		M2_indices[(line - 1) * 12 + 9] = line * 2 - 1;
		M2_indices[(line - 1) * 12 + 10] = line * 2 + 1;
		M2_indices[(line - 1) * 12 + 11] = centerDownIndex;


	}

	//last face of cylinder
	M2_indices[(nCircleVertices - 1) * 12] = nCircleVertices * 2 - 2;
	M2_indices[(nCircleVertices - 1) * 12 + 1] = nCircleVertices * 2 - 1;
	M2_indices[(nCircleVertices - 1) * 12 + 2] = 0;
	M2_indices[(nCircleVertices - 1) * 12 + 3] = 0;
	M2_indices[(nCircleVertices - 1) * 12 + 4] = 1;
	M2_indices[(nCircleVertices - 1) * 12 + 5] = nCircleVertices * 2 - 1;


	//draw up triangle
	M2_indices[(nCircleVertices - 1) * 12 + 6] = nCircleVertices * 2 - 2;
	M2_indices[(nCircleVertices - 1) * 12 + 7] = 0;
	M2_indices[(nCircleVertices - 1) * 12 + 8] = nCircleVertices * 2;

	//draw down triangle
	M2_indices[(nCircleVertices - 1) * 12 + 9] = nCircleVertices * 2 - 1;
	M2_indices[(nCircleVertices - 1) * 12 + 10] = 1;
	M2_indices[(nCircleVertices - 1) * 12 + 11] = nCircleVertices * 2 + 1;

	normalize();
}


void setPoint(int pos, float x, float y, float z, float xT, float yT) {
	if (xT > 1)
		xT = 1;

	if (yT > 1)
		yT = 1;

	//printf("Pos: %d, xT: %f, yT: %f\n", pos % 8, xT, yT);
	M1_vertices[pos].pos = glm::vec3(x, y, z);
	M1_vertices[pos].norm = glm::vec3(
		x * cos(pi / 4),
		y * cos(pi / 4),
		z * cos(pi / 4));
	M1_vertices[pos].UV = glm::vec2(xT, yT);
}

void normalize() {
	for (int i = 0; i < M2_vertices.size(); i++) {
		M2_vertices[i].UV.x = M2_vertices[i].UV.x / (pictureSize / 1000.0);
		M2_vertices[i].UV.y = M2_vertices[i].UV.y / (pictureSize / 1000.0);
	}
}