// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices

struct Vertex {
	glm::vec3 pos;
	glm::vec3 norm;
};

std::vector<Vertex> M1_vertices;
std::vector<Vertex> M2_vertices;
std::vector<Vertex> M3_vertices;
std::vector<Vertex> M4_vertices;

#define pi 3.14

void es1();
void es2();
void es3();
void es4();
void drawCircle(int nPoints, float z);
void drawRotatedCircle(int currentRotation, int currentCircle);
void setPoint(int pos, float x, float y, float z);
void printPoint(const std::string& input, std::vector<float> value, int pos);

// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
void makeModels() {

	es1();

	es2();

	es3();

	es4();
}



void es1() {

	float x, y, z;
	//// M1 : Cube
	// Replace the code below, that creates a simple square, with the one to create a cube.

	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices components (number of vertices * normalsPerVertex)
	M1_vertices.resize(8 * 3);



	// Resizes the indices array. Repalce the values with the correct number of
	// indices (number of triangles * 3)
	#define indicesArrayLengthEs1 12 * 3

	M1_indices.resize(indicesArrayLengthEs1);



	//REAR FACE

	// first vertex of M1
	int pos = 0;
	x = -1.0;
	y = -1.0;
	z = -1.0;
	setPoint(pos, x, y, z);

	pos = 1;
	x = 1.0;
	y = -1.0;
	z = -1.0;
	setPoint(pos, x, y, z);

	pos = 2;
	x = 1.0;
	y = -1.0;
	z = 1.0;
	setPoint(pos, x, y, z);

	pos = 3;
	x = -1.0;
	y = -1.0;
	z = 1.0;
	setPoint(pos, x, y, z);

	pos = 4;
	x = -1.0;
	y = 1.0;
	z = -1.0;
	setPoint(pos, x, y, z);

	pos = 5;
	x = 1.0;
	y = 1.0;
	z = -1.0;
	setPoint(pos, x, y, z);

	pos = 6;
	x = 1.0;
	y = 1.0;
	z = 1.0;
	setPoint(pos, x, y, z);

	pos = 7;
	x = -1.0;
	y = 1.0;
	z = 1.0;
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

void es2() {

	int nCircleVertices = 20;

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

	M2_vertices[centerDownIndex].pos = glm::vec3(0, -1, 0);
	M2_vertices[centerDownIndex].norm = glm::vec3(0, -1, 0);

	//1 first
	M2_vertices[0].pos = glm::vec3(cos(0), 1, sin(0));
	M2_vertices[0].norm = glm::vec3(cos(0), 1, sin(0));

	M2_vertices[1].pos = glm::vec3(cos(0), -1, sin(0));
	M2_vertices[1].norm = glm::vec3(cos(0), -1, sin(0));


	for (int line = 1; line < nCircleVertices; line++) {

		printf("Line: %d\n", line);


		//points of new line
		x = cos(2 * pi / nCircleVertices * line);
		y = 1;
		z = sin(2 * pi / nCircleVertices * line);

		M2_vertices[2 * line].pos = glm::vec3(x, y, z);
		M2_vertices[2 * line].norm = glm::vec3(x, y, z);


		y = -1;
		M2_vertices[2 * line + 1].pos = glm::vec3(x, y, z);
		M2_vertices[2 * line + 1].norm = glm::vec3(x, y, z);

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
	printf("begn index\n");
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
	printf("end index\n");

}

void es3() {

	int pointsPerCircle = 15;
	int radius = 15;
	int numPointsInMiddleOfHalfSphere = pointsPerCircle * (radius - 1);

	int firstUpperDiamPointIndex = pointsPerCircle;
	int firstLowerPointIndex = pointsPerCircle + numPointsInMiddleOfHalfSphere;
	int topPointIndex = firstLowerPointIndex + numPointsInMiddleOfHalfSphere;
	int bottomPointIndex = topPointIndex + 1;

	int trianglesPerMiddleLayer = pointsPerCircle * 2;
	int internalTriangles = trianglesPerMiddleLayer * (radius - 1);
	int firstInternalTriangleFromMiddleDownIndex = internalTriangles;
	int firstTopTriangleIndex = firstInternalTriangleFromMiddleDownIndex + internalTriangles;
	int firstBottomTriangleIndex = firstTopTriangleIndex + pointsPerCircle;

	int definedUpPoint, definedLowPoint;

	int writeOn;

	float x, y, z;

	//Mem organization

	//[longerDiamPoints|upper diam points|lower diam points|topPoint|bottomPoint] <- points
	//[internal Triangs from middle up| from middle down|uppest triangles|bottomest triangle] <- triangles

	//// M3 : Sphere
	// Replace the code below, that creates a simple triangle, with the one to create a sphere.

	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices components (3 * number of vertices)
	M3_vertices.resize(bottomPointIndex + 1);
	M3_indices.resize((firstBottomTriangleIndex + pointsPerCircle) * 3);

	//between circles in sphere + top/bottom


	//define biggest diameter
	for (int point = 0; point < pointsPerCircle; point++) {

		//printf("Writing on Points: %d\n", point);
		x = cos(2 * pi / pointsPerCircle * point);
		y = 0;
		z = sin(2 * pi / pointsPerCircle * point);
		M3_vertices[point].pos = glm::vec3(x, y, z);;
		M3_vertices[point].norm = glm::vec3(x, y, z);
	}

	//printf("Writing on Points: %d\n", topPointIndex);
	M3_vertices[topPointIndex].pos = glm::vec3(0, 1, 0);
	M3_vertices[topPointIndex].norm = glm::vec3(0, 1, 0);

	//printf("Writing on Points: %d\n", bottomPointIndex);
	M3_vertices[bottomPointIndex].pos = glm::vec3(0, -1, 0);
	M3_vertices[bottomPointIndex].norm = glm::vec3(0, -1, 0);


	for (int r = 1; r < radius; r++) {

		x = cos(2 * pi / pointsPerCircle * 0) * cos(pi / 2 / radius * r);
		y = sin(pi / 2 / radius * r);
		z = sin(2 * pi / pointsPerCircle * 0) * cos(pi / 2 / radius * r);

		M3_vertices[(firstUpperDiamPointIndex + (r - 1) * pointsPerCircle)].pos = glm::vec3(x, y, z);
		M3_vertices[(firstUpperDiamPointIndex + (r - 1) * pointsPerCircle)].norm = glm::vec3(x, y, z);

		M3_vertices[(firstLowerPointIndex + (r - 1) * pointsPerCircle)].pos = glm::vec3(x, -y, z);
		M3_vertices[(firstLowerPointIndex + (r - 1) * pointsPerCircle)].norm = glm::vec3(x, -y, z);

		for (int point = 1; point < pointsPerCircle; point++) {


			definedUpPoint = firstUpperDiamPointIndex + (r - 1) * pointsPerCircle + point;
			definedLowPoint = firstLowerPointIndex + (r - 1) * pointsPerCircle + point;

			//printf("Create point %d. DefinedLowPoint: %d\n", r, definedLowPoint);

			//printf("Writing on Points: %d\n", definedUpPoint);
			x = cos(2 * pi / pointsPerCircle * point) * cos(pi / 2 / radius * r);
			y = sin(pi / 2 / radius * r);
			z = sin(2 * pi / pointsPerCircle * point) * cos(pi / 2 / radius * r);
			M3_vertices[definedUpPoint].pos = glm::vec3(x, y, z);
			M3_vertices[definedUpPoint].norm = glm::vec3(x, y, z);

			//printf("Writing on Points: %d\n", definedLowPoint);
			M3_vertices[definedLowPoint].pos = glm::vec3(x, -y, z);
			M3_vertices[definedLowPoint].norm = glm::vec3(x, -y, z);

			//upSphere
			//printf("Writing on Indice: %d\n", (definedUpPoint - firstUpperDiamPointIndex - 1));
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1)] = definedUpPoint;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 1] = definedUpPoint - 1;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 2] = definedUpPoint - 1 - pointsPerCircle;


			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 3] = definedUpPoint;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 4] = definedUpPoint - pointsPerCircle;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 5] = definedUpPoint - 1 - pointsPerCircle;


			//downSphere
			writeOn = firstInternalTriangleFromMiddleDownIndex + (definedLowPoint - firstLowerPointIndex - 1) * 2;
			//printf("Writing on Indice: %d\n", writeOn);
			M3_indices[3 * writeOn] = definedLowPoint;
			M3_indices[3 * writeOn + 1] = definedLowPoint - 1;
			if (r == 1)
				M3_indices[3 * writeOn + 2] = point - 1;
			else
				M3_indices[3 * writeOn + 2] = definedLowPoint - 1 - pointsPerCircle;


			M3_indices[3 * writeOn + 3] = definedLowPoint;
			if (r == 1) {
				M3_indices[3 * writeOn + 4] = point;
				M3_indices[3 * writeOn + 5] = point - 1;
			}
			else {
				M3_indices[3 * writeOn + 4] = definedLowPoint - pointsPerCircle;
				M3_indices[3 * writeOn + 5] = definedLowPoint - 1 - pointsPerCircle;
			}


			//draw last layer of triangles (with top/bottom point as common element
			if (r == radius - 1) {

				//connecting first and last point of layer
				writeOn = firstTopTriangleIndex + point - 1;
				M3_indices[3 * writeOn] = definedUpPoint;
				M3_indices[3 * writeOn + 1] = definedUpPoint - 1;
				M3_indices[3 * writeOn + 2] = topPointIndex;

				writeOn = firstBottomTriangleIndex + point - 1;
				M3_indices[3 * writeOn] = definedLowPoint;
				M3_indices[3 * writeOn + 1] = definedLowPoint - 1;
				M3_indices[3 * writeOn + 2] = bottomPointIndex;

				if (point == pointsPerCircle - 1) {
					writeOn = firstTopTriangleIndex + point;
					M3_indices[3 * writeOn] = definedUpPoint;
					M3_indices[3 * writeOn + 1] = definedUpPoint - pointsPerCircle + 1;
					M3_indices[3 * writeOn + 2] = topPointIndex;

					writeOn = firstBottomTriangleIndex + point;
					M3_indices[3 * writeOn] = definedLowPoint;
					M3_indices[3 * writeOn + 1] = definedLowPoint - pointsPerCircle + 1;
					M3_indices[3 * writeOn + 2] = bottomPointIndex;
				}

			}
		}

		//draw closing "zip"
		writeOn = trianglesPerMiddleLayer * r - 2;
		M3_indices[3 * writeOn] = definedUpPoint;
		M3_indices[3 * writeOn + 1] = definedUpPoint - pointsPerCircle + 1;
		M3_indices[3 * writeOn + 2] = definedUpPoint - 2 * pointsPerCircle + 1;
		M3_indices[3 * writeOn + 3] = definedUpPoint;
		M3_indices[3 * writeOn + 4] = definedUpPoint - pointsPerCircle;
		M3_indices[3 * writeOn + 5] = definedUpPoint - 2 * pointsPerCircle + 1;

		writeOn = firstInternalTriangleFromMiddleDownIndex + trianglesPerMiddleLayer * r - 2;
		M3_indices[3 * writeOn] = definedLowPoint;
		M3_indices[3 * writeOn + 1] = definedLowPoint - pointsPerCircle + 1;
		if (r == 1) {
			M3_indices[3 * writeOn + 2] = 0;
		}
		else {
			M3_indices[3 * writeOn + 2] = definedLowPoint - 2 * pointsPerCircle + 1;
		}
		M3_indices[3 * writeOn + 3] = definedLowPoint;
		if (r == 1) {
			M3_indices[3 * writeOn + 4] = pointsPerCircle - 1;
			M3_indices[3 * writeOn + 5] = 0;
		}
		else {
			M3_indices[3 * writeOn + 4] = definedLowPoint - pointsPerCircle;
			M3_indices[3 * writeOn + 5] = definedLowPoint - 2 * pointsPerCircle + 1;
		}
	}
}

void es4() {
	int pointsPerCircle = 10;
	int circlesPerRotation = 10;
	int rotations = 5;
	float bigRadius = 3, smallRadius = 0.4f, height = 10;
	float x, y, z, smallTheta, bigTheta, distanceFromCenter, deltaY;
	deltaY = height / rotations / circlesPerRotation;

	int trianglesConnectingTwoCircles = 2 * pointsPerCircle, triangleIndex = 0;

	M4_vertices.resize(pointsPerCircle * circlesPerRotation * rotations);
	M4_indices.resize(3 * (trianglesConnectingTwoCircles * circlesPerRotation * rotations));

	smallTheta = pi / pointsPerCircle * 2;
	bigTheta = pi / circlesPerRotation * 2;

	glm::vec3 orientationVector;


	int writeOn, currentPoint;

	for (int currentRotation = 0; currentRotation < rotations; currentRotation++) {

		for (int currentCircleInRotation = 0; currentCircleInRotation < circlesPerRotation; currentCircleInRotation++) {
			orientationVector.y = sin(bigTheta * currentCircleInRotation + bigTheta / 2);

			for (int currentPointInCircle = 0; currentPointInCircle < pointsPerCircle; currentPointInCircle++) {


				currentPoint = currentRotation * circlesPerRotation * pointsPerCircle +
					currentCircleInRotation * pointsPerCircle +
					currentPointInCircle;
				writeOn = currentPoint;

				orientationVector.x = cos(smallTheta * currentPointInCircle + smallTheta / 2);
				orientationVector.z = sin(smallTheta * currentPointInCircle + smallTheta / 2);

				distanceFromCenter = (bigRadius + cos(smallTheta * currentPointInCircle) * smallRadius);
				x = (bigRadius + smallRadius * cos(smallTheta * currentPointInCircle)) * sin(bigTheta * currentCircleInRotation);
				y = (bigRadius + smallRadius * cos(smallTheta * currentPointInCircle)) * cos(bigTheta * currentCircleInRotation);
				z = smallRadius * sin(smallTheta * currentPointInCircle) + deltaY * (currentRotation * circlesPerRotation + currentCircleInRotation);

				M4_vertices[writeOn].pos = glm::vec3(x, y, z);
				M4_vertices[writeOn].norm = orientationVector;


				//connect to previous				
				if (!(currentCircleInRotation == 0 && currentRotation == 0)) {
					triangleIndex = currentRotation * circlesPerRotation * pointsPerCircle +
						currentCircleInRotation * pointsPerCircle +
						currentPointInCircle
						- pointsPerCircle; //first circle doest have connections to previous circle

					triangleIndex *= 2; //two each new point
					triangleIndex *= 3; //each triangle requires 3 array elements

					M4_indices[triangleIndex] = currentPoint; //this point
					M4_indices[triangleIndex + 1] = currentPoint - pointsPerCircle; //this point in circle before
					M4_indices[triangleIndex + 2] = currentPoint - pointsPerCircle - currentPointInCircle + (currentPointInCircle + 1) % pointsPerCircle; //this point in circle before + 1

					M4_indices[triangleIndex + 3] = currentPoint; //this point
					M4_indices[triangleIndex + 4] = currentPoint - currentPointInCircle + (currentPointInCircle + 1) % pointsPerCircle; //this point +1
					M4_indices[triangleIndex + 5] = currentPoint - pointsPerCircle - currentPointInCircle + (currentPointInCircle + 1) % pointsPerCircle; //this point in circle before + 1

				}
			}
		}
	}

}

void setPoint(int pos, float x, float y, float z) {

	M1_vertices[pos].pos = glm::vec3(x, y, z);
	M1_vertices[pos + 8].pos = glm::vec3(x, y, z);
	M1_vertices[pos + 16].pos = glm::vec3(x, y, z);
	M1_vertices[pos].norm = glm::vec3(x, 0.0f, 0.0f);
	M1_vertices[pos + 8].norm = glm::vec3(0.0f, y, 0.0f);
	M1_vertices[pos + 16].norm = glm::vec3(0.0f, 0.0f, z);
}

