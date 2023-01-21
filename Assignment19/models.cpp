#define verticesEs1 8
#define indicesArrayLengthEs1 12 * 3
#define M_PI 3.14
struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
	glm::vec2 UV;
};

#define pi 3.14
#define pictureSize 1024
void cube();
void cylinder();


void setPoint(int pos, float x, float y, float z);

void print(int);


std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;


void makeModels() {

	cube();

	cylinder();
}

void cube() {

	bool swap = true;

	int numberOfPoints = 8;
	M1_vertices.resize(verticesEs1 * 3);
	M1_indices.resize(indicesArrayLengthEs1);

	float x, y, z;
	const float delta = 0.125;
	float y0 = 0;
	float x0 = 0.5f;

	float xT = 0;
	float yT = 0;

	// first vertex of M1
	int pos = 0;
	x = -1.0;
	y = -1.0;
	z = -1.0;

	xT = delta;
	yT = 3 * delta;

	M1_vertices[pos].UV = glm::vec2(xT, yT); // faccia 3
	M1_vertices[pos + 8].UV = glm::vec2(xT, yT); //faccia 5
	M1_vertices[pos + 16].UV = glm::vec2(xT, yT); //faccia 1
	setPoint(pos, x, y, z);
	
	pos = 1;
	x = 1.0;
	y = -1.0;
	z = -1.0;

	xT = 2 * delta;
	yT = 3 * delta;

	M1_vertices[pos].UV = glm::vec2(xT, yT); //faccia 4
	M1_vertices[pos + 8].UV = glm::vec2(xT, yT); //faccia 5
	M1_vertices[pos + 16].UV = glm::vec2(xT, yT); //faccia 1
	setPoint(pos, x, y, z);

	pos = 2;
	x = 1.0;
	y = -1.0;
	z = 1.0;

	M1_vertices[pos].UV = glm::vec2(3 * delta, 3 * delta); //faccia 4
	M1_vertices[pos + 8].UV = glm::vec2(2 * delta, 4 * delta); // faccia 5
	M1_vertices[pos + 16].UV = glm::vec2(2 * delta, 0.0f); //faccia 6
	setPoint(pos, x, y, z);

	pos = 3;
	x = -1.0;
	y = -1.0;
	z = 1.0;

	M1_vertices[pos].UV = glm::vec2(0.0f, 3 * delta); //faccia 3
	M1_vertices[pos + 8].UV = glm::vec2(delta, 4 * delta); //faccia 5
	M1_vertices[pos + 16].UV = glm::vec2(delta, 0.0f); //faccia 6
	setPoint(pos, x, y, z);

	pos = 4;
	x = -1.0;
	y = 1.0;
	z = -1.0;

	xT = delta;
	yT = 2 * delta;

	M1_vertices[pos].UV = glm::vec2(xT, yT); //faccia 3
	M1_vertices[pos + 8].UV = glm::vec2(xT, yT); //faccia 2
	M1_vertices[pos + 16].UV = glm::vec2(xT, yT); // faccia 1
	setPoint(pos, x, y, z);

	pos = 5;
	x = 1.0;
	y = 1.0;
	z = -1.0;

	xT = 2 * delta;
	yT = 2 * delta;

	M1_vertices[pos].UV = glm::vec2(xT, yT); //faccia 4
	M1_vertices[pos + 8].UV = glm::vec2(xT, yT); //faccia 2
	M1_vertices[pos + 16].UV = glm::vec2(xT, yT); //faccia 1
	setPoint(pos, x, y, z);

	pos = 6;
	x = 1.0;
	y = 1.0;
	z = 1.0;

	M1_vertices[pos].UV = glm::vec2(3 * delta, 2 * delta); // faccia 4
	M1_vertices[pos + 8].UV = glm::vec2(2 * delta, delta); //faccia 2
	M1_vertices[pos + 16].UV = glm::vec2(2 * delta, delta); //faccia 6
	setPoint(pos, x, y, z);

	pos = 7;
	x = -1.0;
	y = 1.0;
	z = 1.0;

	M1_vertices[pos].UV = glm::vec2(0.0f, 2 * delta); //faccia 3
	M1_vertices[pos + 8].UV = glm::vec2(delta, delta); //faccia 2
	M1_vertices[pos + 16].UV = glm::vec2(delta, delta); //faccia 6
	setPoint(pos, x, y, z);



	int indices[indicesArrayLengthEs1] = {
			
			
			//faccia 5 - y
			0,1,2, //fb
			3,2,0, //ft

			//faccia 3 - x
			4,7,0, //lt
			3,7,0, //lb

			//faccia 6 - z
			3,7,2, //tl
			7,2,6, //tr

			//faccia 4 - x
			6,2,1, //rt
			6,5,1, //lb

			//faccia 1 - z
			0,4,5, //bl
			0,1,5, //br

			//faccia 2 - y
			7,4,5, //bl
			5,7,6  //br
	};

	//add 8 to y direction faces
	pos = 0;
	for (int i = pos * 6; i < (pos + 1) * 6; i++)
		indices[i] += 8;

	pos = 5;
	for (int i = pos * 6; i < (pos + 1) * 6; i++)
		indices[i] += 8;

	//add 16 to y direction faces
	pos = 2;
	for (int i = pos * 6; i < (pos + 1) * 6; i++)
		indices[i] += 16;

	pos = 4;
	for (int i = pos * 6; i < (pos + 1) * 6; i++)
		indices[i] += 16;

	for (int i = 0; i < indicesArrayLengthEs1; i++) 
		M1_indices[i] = indices[i];
}

void cylinder() {

	double deltaPixel = 0.125;
	double x0 = 4*deltaPixel, y0 = 0;
	int nCircleVertices = 20;

	glm::vec2 centerTopCan = glm::vec2(x0 + deltaPixel, y0 + deltaPixel);
	glm::vec2 centerBottomCan = glm::vec2(x0 + 3 * deltaPixel, y0 + deltaPixel);

	glm::vec2 topLeftCan = glm::vec2(x0, y0 + 2 * deltaPixel);
	glm::vec2 topRightCan = glm::vec2(x0 + 4 * deltaPixel, y0 + 2 * deltaPixel);
	glm::vec2 bottomLeftCan = glm::vec2(x0, y0 + 4 * deltaPixel);
	glm::vec2 bottomRightCan = glm::vec2(x0 + 4 * deltaPixel, y0 + 4 * deltaPixel);

	int centerUpIndex = nCircleVertices * 4;
	int centerDownIndex = centerUpIndex + 1;
	int shiftForDuplicatePoint = 2 * nCircleVertices;

	float x, y, z;
	int pos;


	std::vector<float> circleVertices;
	std::vector<uint32_t> circleIndices;

	//(vertici * 2 (due UV) + 1 (centro top/bottom)) * 2 (sopra e sotto)
	M2_vertices.resize((nCircleVertices * 2 + 1) * 2);

	//numCircleVertices + center
	M2_indices.resize(nCircleVertices * 4 * 3);


	//center up and down
	x = 0;
	y = 1;
	z = 0;
	M2_vertices[centerUpIndex].pos = glm::vec3(x, y, z);
	M2_vertices[centerUpIndex].norm = glm::vec3(x, y, z);
	M2_vertices[centerUpIndex].UV = centerTopCan;
	
	y = -1;
	M2_vertices[centerDownIndex].pos = glm::vec3(x, y, z);
	M2_vertices[centerDownIndex].norm = glm::vec3(x, y, z);
	M2_vertices[centerDownIndex].UV = centerBottomCan;

	//1 first
	pos = 0;
	x = 0;
	y = 1;
	z = cos(0);
	M2_vertices[pos].pos = glm::vec3(x, y, z);
	M2_vertices[pos].norm = glm::vec3(0,y,0);
	M2_vertices[pos].UV = glm::vec2(centerTopCan.x + x * deltaPixel, centerTopCan.y + z * deltaPixel);

	M2_vertices[pos + shiftForDuplicatePoint].pos = glm::vec3(x, y, z);
	M2_vertices[pos + shiftForDuplicatePoint].norm = glm::vec3(x,0,z);
	M2_vertices[pos + shiftForDuplicatePoint].UV = topLeftCan;

	pos = 1;
	y = -1;
	M2_vertices[pos].pos = glm::vec3(x, y, z);
	M2_vertices[pos].norm = glm::vec3(0, y, 0);
	M2_vertices[pos].UV = glm::vec2(centerBottomCan.x + x * deltaPixel, centerBottomCan.y + z * deltaPixel);
	M2_vertices[pos + shiftForDuplicatePoint].pos = glm::vec3(x, y, z);
	M2_vertices[pos + shiftForDuplicatePoint].norm = glm::vec3(x, 0, z);
	M2_vertices[pos + shiftForDuplicatePoint].UV = bottomLeftCan;


	float currXOnPicture;
	for (int line = 1; line < nCircleVertices; line++) {

		//points of new line
		x = sin(2 * pi / nCircleVertices * line);
		y = 1;
		z = cos(2 * pi / nCircleVertices * line);

		pos = 2 * line;
		currXOnPicture = x0 + 4 * deltaPixel / nCircleVertices * line;
		M2_vertices[pos].pos = glm::vec3(x, y, z);
		M2_vertices[pos].norm = glm::vec3(0, y, 0);
		M2_vertices[pos].UV = glm::vec2(centerTopCan.x + x * deltaPixel, centerTopCan.y + z * deltaPixel);
		M2_vertices[pos + shiftForDuplicatePoint].pos = glm::vec3(x, y, z);
		M2_vertices[pos + shiftForDuplicatePoint].norm = glm::vec3(x, 0, z);
		M2_vertices[pos + shiftForDuplicatePoint].UV = glm::vec2(currXOnPicture, topLeftCan.y);


		pos = 2 * line + 1;
		y = -1;
		M2_vertices[pos].pos = glm::vec3(x, y, z);
		M2_vertices[pos].norm = glm::vec3(0, y, 0);
		M2_vertices[pos].UV = glm::vec2(centerBottomCan.x + x * deltaPixel, centerBottomCan.y + z * deltaPixel);
		M2_vertices[pos + shiftForDuplicatePoint].pos = glm::vec3(x, y, z);
		M2_vertices[pos + shiftForDuplicatePoint].norm = glm::vec3(x, 0, z);
		M2_vertices[pos + shiftForDuplicatePoint].UV = glm::vec2(currXOnPicture, bottomLeftCan.y);

		//connect currentLine with previous line
		M2_indices[(line - 1) * 12] = line * 2 - 2 + shiftForDuplicatePoint;
		M2_indices[(line - 1) * 12 + 1] = line * 2 - 1 + shiftForDuplicatePoint;
		M2_indices[(line - 1) * 12 + 2] = line * 2 + shiftForDuplicatePoint;
		M2_indices[(line - 1) * 12 + 3] = line * 2 + shiftForDuplicatePoint;
		M2_indices[(line - 1) * 12 + 4] = line * 2 - 1 + shiftForDuplicatePoint;
		M2_indices[(line - 1) * 12 + 5] = line * 2 + 1 + shiftForDuplicatePoint;

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
	M2_indices[(nCircleVertices - 1) * 12] = nCircleVertices * 2 - 2 + shiftForDuplicatePoint;
	M2_indices[(nCircleVertices - 1) * 12 + 1] = nCircleVertices * 2 - 1 + shiftForDuplicatePoint;
	M2_indices[(nCircleVertices - 1) * 12 + 2] = 0 + shiftForDuplicatePoint;
	M2_indices[(nCircleVertices - 1) * 12 + 3] = 0 + shiftForDuplicatePoint;
	M2_indices[(nCircleVertices - 1) * 12 + 4] = 1 + shiftForDuplicatePoint;
	M2_indices[(nCircleVertices - 1) * 12 + 5] = nCircleVertices * 2 - 1 + shiftForDuplicatePoint;


	//draw up triangle
	M2_indices[(nCircleVertices - 1) * 12 + 6] = nCircleVertices * 2 - 2;
	M2_indices[(nCircleVertices - 1) * 12 + 7] = 0;
	M2_indices[(nCircleVertices - 1) * 12 + 8] = centerUpIndex;

	//draw down triangle
	M2_indices[(nCircleVertices - 1) * 12 + 9] = nCircleVertices * 2 - 1;
	M2_indices[(nCircleVertices - 1) * 12 + 10] = 1;
	M2_indices[(nCircleVertices - 1) * 12 + 11] = centerDownIndex;

}


void setPoint(int pos, float x, float y, float z) {
	if (true) {
		M1_vertices[pos].pos = glm::vec3(x, y, z);
		M1_vertices[pos + 8].pos = M1_vertices[pos].pos;
		M1_vertices[pos + 16].pos = M1_vertices[pos].pos;
		M1_vertices[pos].norm = glm::vec3(x, 0.0f, 0.0f);
		M1_vertices[pos + 8].norm = glm::vec3(0.0f, y, 0.0f);
		M1_vertices[pos + 16].norm = glm::vec3(0.0f, 0.0f, z);
		//print(pos);
	}
}


void print(int pos) {
	int secondPos = pos + 8;
	int thirdPos = pos + 16;
	printf("\n\n//%d\nM1_vertices[%d].pos = glm::vec3(%f, %f, %f);\n", pos, pos, M1_vertices[pos].pos.x, M1_vertices[pos].pos.y, M1_vertices[pos].pos.z);
	printf("M1_vertices[%d].pos = glm::vec3(%f, %f, %f);\n", secondPos, M1_vertices[secondPos].pos.x, M1_vertices[secondPos].pos.y, M1_vertices[secondPos].pos.z);
	printf("M1_vertices[%d].pos = glm::vec3(%f, %f, %f);\n", thirdPos, M1_vertices[thirdPos].pos.x, M1_vertices[thirdPos].pos.y, M1_vertices[thirdPos].pos.z);

	printf("M1_vertices[%d].norm = glm::vec3(%f, %f, %f);\n", pos, M1_vertices[pos].norm.x, M1_vertices[pos].norm.y, M1_vertices[pos].norm.z);
	printf("M1_vertices[%d].norm = glm::vec3(%f, %f, %f);\n", secondPos, M1_vertices[secondPos].norm.x, M1_vertices[secondPos].norm.y, M1_vertices[secondPos].norm.z);
	printf("M1_vertices[%d].norm = glm::vec3(%f, %f, %f);\n", thirdPos, M1_vertices[thirdPos].norm.x, M1_vertices[thirdPos].norm.y, M1_vertices[thirdPos].norm.z);

	printf("M1_vertices[%d].UV = glm::vec2(%f, %f);\n", pos, M1_vertices[pos].UV.x, M1_vertices[pos].UV.y);
	printf("M1_vertices[%d].UV = glm::vec2(%f, %f);\n", secondPos, M1_vertices[secondPos].UV.x, M1_vertices[secondPos].UV.y);
	printf("M1_vertices[%d].UV = glm::vec2(%f, %f);\n", thirdPos, M1_vertices[thirdPos].UV.x, M1_vertices[thirdPos].UV.y);
}