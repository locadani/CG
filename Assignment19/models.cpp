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

void normalize();

void setPoint(int pos, float x, float y, float z);

void print(int);


std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;


void makeModels() {

	cube();

	cylinder();/*
	int i = 0;

	int NSlices = 20;
	float radius = 1;
	float height = 1;
	float cx = 0, cy = 0, cz = -3; // Center of the model, not of the face!

	// Vertices definitions
	// For NSlices, considering only the top surface, we need NSlices + 1 vertexes (considering also the center)
	M2_vertices.resize(((NSlices + 1) * 3) * 2 * 2 + 2); // final + 2 to replicate last vertices to wrap the texture
	int middle_index = ((NSlices + 1) * 3) * 2;

	i = 0;

	// Top face
	M2_vertices[i].pos = glm::vec3(cx, cy + height, cz);
	M2_vertices[i].norm = glm::vec3(0, 1, 0);
	M2_vertices[i].UV = glm::vec2(0.625, 0.125);

	M2_vertices[middle_index + i].pos = glm::vec3(cx, cy + height, cz);
	M2_vertices[middle_index + i].norm = glm::vec3(0, 1, 0);
	M2_vertices[middle_index + i].UV = glm::vec2(0.625, 0.125);
	i = i + 1;

	float x, y, z, u, v;
	float center_u = 0.625, shift_u = 0.25;
	float center_v = 0.125;
	float uv_radius = 0.125;
	int initial_i = i;

	for (i; i <= NSlices; i++) {
		// Top
		x = cx + radius * cos((float)(i - 1) / NSlices * 2.0 * M_PI); // x of the vertex
		y = cy + height;                                        // y of the vertex
		z = cz + radius * sin((float)(i - 1) / NSlices * 2.0 * M_PI); // z of the vertex

		u = center_u + uv_radius * cos((float)(i - 1) / NSlices * 2.0 * M_PI);
		v = center_v + uv_radius * sin((float)(i - 1) / NSlices * 2.0 * M_PI);

		M2_vertices[i].pos = glm::vec3(x, y, z);
		M2_vertices[i].norm = glm::vec3(cos((float)(i - 1) / NSlices * 2.0 * M_PI), 0, sin((float)i / NSlices * 2.0 * M_PI));
		M2_vertices[i].UV = glm::vec2(0.5 + 0.5 * (i - 1) / NSlices, 0.25);

		M2_vertices[middle_index + i].pos = glm::vec3(x, y, z);
		M2_vertices[middle_index + i].norm = glm::vec3(0, 1, 0);
		M2_vertices[middle_index + i].UV = glm::vec2(u, v);

		// Bottom
		x = cx + radius * cos((float)(i - 1) / NSlices * 2.0 * M_PI); // x of the vertex
		y = cy - height;                                        // y of the vertex
		z = cz + radius * sin((float)(i - 1) / NSlices * 2.0 * M_PI); // z of the vertex

		u = center_u + shift_u + uv_radius * cos((float)(i - 1) / NSlices * 2.0 * M_PI);
		v = center_v + uv_radius * sin((float)(i - 1) / NSlices * 2.0 * M_PI);

		M2_vertices[NSlices + 1 + i].pos = glm::vec3(x, y, z);
		M2_vertices[NSlices + 1 + i].norm = glm::vec3(cos((float)(i - 1) / NSlices * 2.0 * M_PI), 0, sin((float)i / NSlices * 2.0 * M_PI));
		M2_vertices[NSlices + 1 + i].UV = glm::vec2(0.5 + 0.5 * (i - 1) / NSlices, 0.5);

		M2_vertices[middle_index + NSlices + 1 + i].pos = glm::vec3(x, y, z);
		M2_vertices[middle_index + NSlices + 1 + i].norm = glm::vec3(0, -1, 0);
		M2_vertices[middle_index + NSlices + 1 + i].UV = glm::vec2(u, v);
	}
	// First vertexes replica to wrap the texture around
	int lastIndex = ((NSlices + 1) * 3) * 2 * 2;
	M2_vertices[lastIndex].pos = M2_vertices[initial_i].pos;
	M2_vertices[lastIndex].norm = glm::vec3(0, 1, 0);
	M2_vertices[lastIndex].UV = glm::vec2(1.0, 0.25);

	M2_vertices[lastIndex + 1].pos = M2_vertices[initial_i + NSlices + 1].pos;
	M2_vertices[lastIndex + 1].norm = glm::vec3(0, 1, 0);
	M2_vertices[lastIndex + 1].UV = glm::vec2(1.0, 0.25);

	printf("Top face: %d\n", i);

	// Bottom face
	M2_vertices[i].pos = glm::vec3(cx, cy - height, cz);
	M2_vertices[i].norm = glm::vec3(0, -1, 0);
	M2_vertices[i].UV = glm::vec2(0.875, 0.125);

	M2_vertices[middle_index + i].pos = glm::vec3(cx, cy - height, cz);
	M2_vertices[middle_index + i].norm = glm::vec3(0, -1, 0);
	M2_vertices[middle_index + i].UV = glm::vec2(0.875, 0.125);

	// Indexes definitions
	int totalIndicesCount = 3 * 4 * NSlices;
	M2_indices.resize(totalIndicesCount);

	// Top and bottom faces
	i = 0;
	for (; i < NSlices; i++) {
		M2_indices[i * 3 + 0] = 0 + middle_index;
		M2_indices[i * 3 + 1] = i + 1 + middle_index;
		M2_indices[i * 3 + 2] = (i + 1) % NSlices + 1 + middle_index;

		int base = NSlices + 1;
		M2_indices[(NSlices + i) * 3 + 0] = base + middle_index;
		M2_indices[(NSlices + i) * 3 + 1] = base + i + 1 + middle_index;
		M2_indices[(NSlices + i) * 3 + 2] = base + (i + 1) % NSlices + 1 + middle_index;
	}
	printf("First face indices: %d\n", i);
	printf("Second face indices: %d\n", i + NSlices);

	// Sides
	int starting_index = 2 * NSlices * 3;
	for (int j = 0; j < NSlices; j++) {
		M2_indices[starting_index + j * 3 + 0] = j + 1;
		M2_indices[starting_index + j * 3 + 1] = (j + 1) % NSlices + 1;
		M2_indices[starting_index + j * 3 + 2] = NSlices + j + 2;

		M2_indices[starting_index + (NSlices + j) * 3 + 0] = NSlices + j + 2;
		M2_indices[starting_index + (NSlices + j) * 3 + 1] = NSlices + (j + 1) % NSlices + 2;
		M2_indices[starting_index + (NSlices + j) * 3 + 2] = (j + 1) % NSlices + 1;

		// Texture wrapping
		if (j == NSlices - 1) {
			M2_indices[starting_index + j * 3 + 1] = lastIndex;
			M2_indices[starting_index + (NSlices + j) * 3 + 1] = lastIndex + 1;
			M2_indices[starting_index + (NSlices + j) * 3 + 2] = lastIndex;
		}
	}
	*/

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
	M1_vertices[pos + 16].UV = glm::vec2(xT + x0, yT); //faccia 1
	setPoint(pos, x, y, z);
	
	pos = 1;
	x = 1.0;
	y = -1.0;
	z = -1.0;

	xT = 2 * delta;
	yT = 3 * delta;

	M1_vertices[pos].UV = glm::vec2(xT, yT); //faccia 4
	M1_vertices[pos + 8].UV = glm::vec2(xT, yT); //faccia 5
	M1_vertices[pos + 16].UV = glm::vec2(xT + x0, yT); //faccia 1
	setPoint(pos, x, y, z);

	pos = 2;
	x = 1.0;
	y = -1.0;
	z = 1.0;

	xT = 2 * delta;
	yT = 2 * delta;

	M1_vertices[pos].UV = glm::vec2(3 * delta, 3 * delta); //faccia 4
	M1_vertices[pos + 8].UV = glm::vec2(2 * delta, 4 * delta); // faccia 5
	M1_vertices[pos + 16].UV = glm::vec2(2 * delta, 0.0f); //faccia 6
	setPoint(pos, x, y, z);

	pos = 3;
	x = -1.0;
	y = -1.0;
	z = 1.0;

	xT = delta;
	yT = 2 * delta;

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
	M1_vertices[pos + 16].UV = glm::vec2(xT + x0, yT); // faccia 1
	setPoint(pos, x, y, z);

	pos = 5;
	x = 1.0;
	y = 1.0;
	z = -1.0;

	xT = 2 * delta;
	yT = 2 * delta;

	M1_vertices[pos].UV = glm::vec2(xT, yT); //faccia 4
	M1_vertices[pos + 8].UV = glm::vec2(xT, yT); //faccia 2
	M1_vertices[pos + 16].UV = glm::vec2(xT + x0, yT); //faccia 1
	setPoint(pos, x, y, z);

	pos = 6;
	x = 1.0;
	y = 1.0;
	z = 1.0;

	xT = 2 * delta;
	yT = 3 * delta;

	M1_vertices[pos].UV = glm::vec2(3 * delta, 2 * delta); // faccia 4
	M1_vertices[pos + 8].UV = glm::vec2(2 * delta, delta); //faccia 2
	M1_vertices[pos + 16].UV = glm::vec2(2 * delta, delta); //faccia 6
	setPoint(pos, x, y, z);

	pos = 7;
	x = -1.0;
	y = 1.0;
	z = 1.0;

	xT = 2 * delta;
	yT = 3 * delta;

	M1_vertices[pos].UV = glm::vec2(0.0f, 2 * delta); //faccia 3
	M1_vertices[pos + 8].UV = glm::vec2(delta, delta); //faccia 2
	M1_vertices[pos + 16].UV = glm::vec2(delta, 3 * delta); //faccia 6
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

	if (false) {

		for (int i = 0; i < numberOfPoints; i++)
			print(i);

		printf("\n\nPrinting indices: \n");
		for (int i = 0; i < indicesArrayLengthEs1; i++) {
			printf("%d", M1_indices[i]);

			if ((i + 1) % 6 == 0)
				printf("\n\n");
			else if ((i + 1) % 3 == 0)
				printf("\n");
			else
				printf(",");
		}
	}

}

void cylinder() {

	double deltaPixel = 0.128;
	double x0 = 4*deltaPixel, y0 = 0;// deltaPixel * 4;
	int nCircleVertices = 4;

	glm::vec2 centerTopCan = glm::vec2(x0 + deltaPixel, y0 + deltaPixel);
	glm::vec2 centerBottomCan = glm::vec2(x0 + 3 * deltaPixel, y0 + deltaPixel);

	glm::vec2 topLeftCan = glm::vec2(x0, y0 + 2 * deltaPixel);
	glm::vec2 topRightCan = glm::vec2(x0 + 4 * deltaPixel, y0 + 2 * deltaPixel);
	glm::vec2 bottomLeftCan = glm::vec2(x0, y0 + 4 * deltaPixel);
	glm::vec2 bottomRightCan = glm::vec2(x0 + 4 * deltaPixel, y0 + 4 * deltaPixel);

	int centerUpIndex = nCircleVertices * 2;
	int centerDownIndex = nCircleVertices * 2 + 1;
	int shiftForDuplicatePoint = centerDownIndex + 1;


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
	M2_vertices[pos].norm = glm::vec3(x, 0, z);
	M2_vertices[pos].UV = topLeftCan;

	M2_vertices[pos + shiftForDuplicatePoint].pos = glm::vec3(x, y, z);
	M2_vertices[pos + shiftForDuplicatePoint].norm = glm::vec3(0, y, 0);
	M2_vertices[pos + shiftForDuplicatePoint].UV = glm::vec2(centerTopCan.x + x, centerTopCan.y + z);

	pos = 1;
	y = -1;
	M2_vertices[pos].pos = glm::vec3(x, y, z);
	M2_vertices[pos].norm = glm::vec3(x, 0, z);
	M2_vertices[pos].UV = bottomLeftCan;
	M2_vertices[pos + shiftForDuplicatePoint].pos = glm::vec3(x, y, z);
	M2_vertices[pos + shiftForDuplicatePoint].norm = glm::vec3(0, y, 0);
	M2_vertices[pos + shiftForDuplicatePoint].UV = glm::vec2(centerBottomCan.x + x, centerBottomCan.y + z);


	float currXOnPicture;
	for (int line = 1; line < nCircleVertices; line++) {

		//points of new line
		x = sin(2 * pi / nCircleVertices * line);
		y = 1;
		z = cos(2 * pi / nCircleVertices * line);

		pos = 2 * line;
		currXOnPicture = x0 + 4 * deltaPixel / nCircleVertices * line;
		M2_vertices[pos].pos = glm::vec3(x, y, z);
		M2_vertices[pos].norm = glm::vec3(x, 0, z);
		M2_vertices[pos].UV = glm::vec2(currXOnPicture, topLeftCan.y);
		M2_vertices[pos + shiftForDuplicatePoint].pos = glm::vec3(x, y, z);
		M2_vertices[pos + shiftForDuplicatePoint].norm = glm::vec3(0, y, 0);
		M2_vertices[pos + shiftForDuplicatePoint].UV = glm::vec2(centerTopCan.x + x, centerTopCan.y + z);


		pos = 2 * line + 1;
		y = -1;
		M2_vertices[pos].pos = glm::vec3(x, y, z);
		M2_vertices[pos].norm = glm::vec3(x, 0, z);
		M2_vertices[pos].UV = glm::vec2(currXOnPicture, bottomLeftCan.y);
		M2_vertices[pos + shiftForDuplicatePoint].pos = glm::vec3(x, y, z);
		M2_vertices[pos + shiftForDuplicatePoint].norm = glm::vec3(0, y, 0);
		M2_vertices[pos + shiftForDuplicatePoint].UV = glm::vec2(centerBottomCan.x + x, centerBottomCan.y + z);

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

void normalize() {
	for (int i = 0; i < M2_vertices.size(); i++) {
		M2_vertices[i].UV.x = M2_vertices[i].UV.x / (pictureSize / 1000.0);
		M2_vertices[i].UV.y = M2_vertices[i].UV.y / (pictureSize / 1000.0);
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