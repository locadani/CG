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

void cube_1();
void cylinder_2();
void sphere_3();
void spring_4();

void setPoint(int pos, float x, float y, float z);

// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
void makeModels() {

	cube_1();

	cylinder_2();

	sphere_3();

	spring_4();
}



void cube_1() {
	//// M1 : Cube

	float x, y, z;
	int shift = 8;

	#define indicesArrayLengthEs1 12 * 3
	
	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices components (number of vertices * normalsPerVertex)
	M1_vertices.resize(8 * 3);
	M1_indices.resize(indicesArrayLengthEs1);


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

void cylinder_2() {

	int nCircleVertices = 4;

	int centerUpIndex = nCircleVertices * 4;
	int centerDownIndex = centerUpIndex + 1;
	int shift = 2 * nCircleVertices;


	float x, y, z;
	int pos;


	std::vector<float> circleVertices;
	std::vector<uint32_t> circleIndices;

	//(vertici * 2 (due normali) + 1 (centro top/bottom)) * 2 (sopra e sotto)
	/*
		points associated to vertical norms are stored in the first part of the array [vertex0, vertex0_below, vertex1, vertex1_below]
		then the horizontal ones [same as before]
		eventually the two centers of the top and bottom faces
	*/
	M2_vertices.resize((nCircleVertices * 2 + 1) * 2);

	//numCircleVertices + center
	M2_indices.resize(nCircleVertices * 4 * 3);


	//center up and down
	x = 0;
	y = 1;
	z = 0;
	M2_vertices[centerUpIndex].pos = glm::vec3(x, y, z);
	M2_vertices[centerUpIndex].norm = glm::vec3(x, y, z);

	y = -1;
	M2_vertices[centerDownIndex].pos = glm::vec3(x, y, z);
	M2_vertices[centerDownIndex].norm = glm::vec3(x, y, z);

	//1 first
	pos = 0;
	x = 0;
	y = 1;
	z = cos(0);
	M2_vertices[pos].pos = glm::vec3(x, y, z);
	M2_vertices[pos + shift].pos = glm::vec3(x, y, z);
	M2_vertices[pos].norm = glm::vec3(0, y, 0); 
	M2_vertices[pos + shift].norm = glm::vec3(x, 0, z);

	pos = 1;
	y = -1;
	M2_vertices[pos].pos = glm::vec3(x, y, z);
	M2_vertices[pos + shift].pos = glm::vec3(x, y, z);
	M2_vertices[pos].norm = glm::vec3(0, y, 0);
	M2_vertices[pos + shift].norm = glm::vec3(x, 0, z);


	for (int line = 1; line < nCircleVertices; line++) {
		pos = 2 * line;


		//points of new line
		x = sin(2 * pi / nCircleVertices * line);
		y = 1;
		z = cos(2 * pi / nCircleVertices * line);


		M2_vertices[pos].pos = glm::vec3(x, y, z);
		M2_vertices[pos + shift].pos = glm::vec3(x, y, z);
		M2_vertices[pos].norm = glm::vec3(0, y, 0);
		M2_vertices[pos + shift].norm = glm::vec3(x, 0, z);


		pos = 2 * line + 1;
		y = -1;
		M2_vertices[pos].pos = glm::vec3(x, y, z);
		M2_vertices[pos + shift].pos = glm::vec3(x, y, z);
		M2_vertices[pos].norm = glm::vec3(0, y, 0);
		M2_vertices[pos + shift].norm = glm::vec3(x, 0, z);


		//connect currentLine with previous line
		M2_indices[(line - 1) * 12] = line * 2 - 2 + shift;
		M2_indices[(line - 1) * 12 + 1] = line * 2 - 1 + shift;
		M2_indices[(line - 1) * 12 + 2] = line * 2 + shift;
		M2_indices[(line - 1) * 12 + 3] = line * 2 + shift;
		M2_indices[(line - 1) * 12 + 4] = line * 2 - 1 + shift;
		M2_indices[(line - 1) * 12 + 5] = line * 2 + 1 + shift;

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
	M2_indices[(nCircleVertices - 1) * 12] = nCircleVertices * 2 - 2 + shift;
	M2_indices[(nCircleVertices - 1) * 12 + 1] = nCircleVertices * 2 - 1 + shift;
	M2_indices[(nCircleVertices - 1) * 12 + 2] = 0 + shift;
	M2_indices[(nCircleVertices - 1) * 12 + 3] = 0 + shift;
	M2_indices[(nCircleVertices - 1) * 12 + 4] = 1 + shift;
	M2_indices[(nCircleVertices - 1) * 12 + 5] = nCircleVertices * 2 - 1 + shift;


	//draw up triangle
	M2_indices[(nCircleVertices - 1) * 12 + 6] = nCircleVertices * 2 - 2;
	M2_indices[(nCircleVertices - 1) * 12 + 7] = 0;
	M2_indices[(nCircleVertices - 1) * 12 + 8] = centerUpIndex;

	//draw down triangle
	M2_indices[(nCircleVertices - 1) * 12 + 9] = nCircleVertices * 2 - 1;
	M2_indices[(nCircleVertices - 1) * 12 + 10] = 1;
	M2_indices[(nCircleVertices - 1) * 12 + 11] = centerDownIndex;
	
}

void sphere_3() {
	//// M3 : Sphere

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


	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices components (3 * number of vertices)
	M3_vertices.resize(bottomPointIndex + 1);
	M3_indices.resize((firstBottomTriangleIndex + pointsPerCircle) * 3);


	//define biggest diameter
	for (int point = 0; point < pointsPerCircle; point++) {

		x = cos(2 * pi / pointsPerCircle * point);
		y = 0;
		z = sin(2 * pi / pointsPerCircle * point);
		M3_vertices[point].pos = glm::vec3(x, y, z);;
		M3_vertices[point].norm = glm::vec3(x, y, z);
	}

	M3_vertices[topPointIndex].pos = glm::vec3(0, 1, 0);
	M3_vertices[topPointIndex].norm = glm::vec3(0, 1, 0);

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

			x = cos(2 * pi / pointsPerCircle * point) * cos(pi / 2 / radius * r);
			y = sin(pi / 2 / radius * r);
			z = sin(2 * pi / pointsPerCircle * point) * cos(pi / 2 / radius * r);
			M3_vertices[definedUpPoint].pos = glm::vec3(x, y, z);
			M3_vertices[definedUpPoint].norm = glm::vec3(x, y, z);

			M3_vertices[definedLowPoint].pos = glm::vec3(x, -y, z);
			M3_vertices[definedLowPoint].norm = glm::vec3(x, -y, z);

			//upSphere
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1)] = definedUpPoint;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 1] = definedUpPoint - 1;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 2] = definedUpPoint - 1 - pointsPerCircle;


			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 3] = definedUpPoint;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 4] = definedUpPoint - pointsPerCircle;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 5] = definedUpPoint - 1 - pointsPerCircle;


			//downSphere
			writeOn = firstInternalTriangleFromMiddleDownIndex + (definedLowPoint - firstLowerPointIndex - 1) * 2;
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

void spring_4() {
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

	glm::vec3 orientationVector, center;


	int writeOn, currentPoint;

	for (int currentRotation = 0; currentRotation < rotations; currentRotation++) {

		for (int currentCircleInRotation = 0; currentCircleInRotation < circlesPerRotation; currentCircleInRotation++) {
			
			//center of current circle to draw
			center.x = bigRadius * sin(bigTheta * currentCircleInRotation);
			center.y = bigRadius * cos(bigTheta * currentCircleInRotation);
			center.z = deltaY * (currentRotation * circlesPerRotation + currentCircleInRotation);

			for (int currentPointInCircle = 0; currentPointInCircle < pointsPerCircle; currentPointInCircle++) {


				currentPoint = currentRotation * circlesPerRotation * pointsPerCircle +
					currentCircleInRotation * pointsPerCircle +
					currentPointInCircle;
				writeOn = currentPoint;

				distanceFromCenter = (bigRadius + cos(smallTheta * currentPointInCircle) * smallRadius);
				x = (bigRadius + smallRadius * cos(smallTheta * currentPointInCircle)) * sin(bigTheta * currentCircleInRotation);
				y = (bigRadius + smallRadius * cos(smallTheta * currentPointInCircle)) * cos(bigTheta * currentCircleInRotation);
				z = smallRadius * sin(smallTheta * currentPointInCircle) + deltaY * (currentRotation * circlesPerRotation + currentCircleInRotation);

				M4_vertices[writeOn].pos = glm::vec3(x, y, z);
				orientationVector = glm::normalize(M4_vertices[writeOn].pos - center);

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
	int shift = 8;
	M1_vertices[pos].pos = glm::vec3(x, y, z);
	M1_vertices[pos + shift].pos = glm::vec3(x, y, z);
	M1_vertices[pos + 2 * shift].pos = glm::vec3(x, y, z);
	M1_vertices[pos].norm = glm::vec3(x, 0.0f, 0.0f);
	M1_vertices[pos + shift].norm = glm::vec3(0.0f, y, 0.0f);
	M1_vertices[pos + 2 * shift].norm = glm::vec3(0.0f, 0.0f, z);
}

