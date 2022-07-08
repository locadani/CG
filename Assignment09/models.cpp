#define pi 3.14

void es1();
void es2();
void es3();
void drawCircle(int nPoints, float z);

void printPoint(const std::string& input, std::vector<float> value, int pos);

// this function creates the geometries to be shown, and output thems
// in global variables M1_vertices and M1_indices to M4_vertices and M4_indices
void makeModels() {


	es1();


	es2();


	es3();






	//// M4 : Spring
	// Replace the code below, that creates a simple octahedron, with the one to create a spring.
	M4_vertices.resize(3 * 6);

	// Vertices definitions
	M4_vertices[0] = 0.0;
	M4_vertices[1] = 1.414;
	M4_vertices[2] = -1.0;
	M4_vertices[3] = 0.0;
	M4_vertices[4] = -1.414;
	M4_vertices[5] = -1.0;
	M4_vertices[6] = -1.0;
	M4_vertices[7] = 0.0;
	M4_vertices[8] = -2.0;
	M4_vertices[9] = -1.0;
	M4_vertices[10] = 0.0;
	M4_vertices[11] = 0.0;
	M4_vertices[12] = 1.0;
	M4_vertices[13] = 0.0;
	M4_vertices[14] = 0.0;
	M4_vertices[15] = 1.0;
	M4_vertices[16] = 0.0;
	M4_vertices[17] = -2.0;


	// Resizes the indices array. Repalce the values with the correct number of
	// indices (3 * number of triangles)
	M4_indices.resize(3 * 8);

	// indices definitions
	M4_indices[0] = 0;
	M4_indices[1] = 2;
	M4_indices[2] = 3;
	M4_indices[3] = 1;
	M4_indices[4] = 3;
	M4_indices[5] = 2;
	M4_indices[6] = 0;
	M4_indices[7] = 3;
	M4_indices[8] = 4;
	M4_indices[9] = 1;
	M4_indices[10] = 4;
	M4_indices[11] = 3;
	M4_indices[12] = 0;
	M4_indices[13] = 4;
	M4_indices[14] = 5;
	M4_indices[15] = 1;
	M4_indices[16] = 5;
	M4_indices[17] = 4;
	M4_indices[18] = 0;
	M4_indices[19] = 5;
	M4_indices[20] = 2;
	M4_indices[21] = 1;
	M4_indices[22] = 2;
	M4_indices[23] = 5;
}



void es1() {

	//// M1 : Cube
	// Replace the code below, that creates a simple square, with the one to create a cube.

	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices components (3 * number of vertices)
	M1_vertices.resize(3 * 8);



	// Resizes the indices array. Repalce the values with the correct number of
	// indices (3 * number of triangles)
#define indicesArrayLengthEs1 3*12
	M1_indices.resize(indicesArrayLengthEs1);

	//FRONT FACE
		// first vertex of M1
	M1_vertices[0] = -1.0;
	M1_vertices[1] = -1.0;
	M1_vertices[2] = -1.0;

	// second vertex of M1
	M1_vertices[3] = 1.0;
	M1_vertices[4] = -1.0;
	M1_vertices[5] = -1.0;

	// third vertex of M1
	M1_vertices[6] = 1.0;
	M1_vertices[7] = 1.0;
	M1_vertices[8] = -1.0;

	// fourth vertex of M1
	M1_vertices[9] = -1.0;
	M1_vertices[10] = 1.0;
	M1_vertices[11] = -1.0;

	//FRONT FACE
	// 5 vertex of M1
	M1_vertices[12 + 0] = -1.0;
	M1_vertices[12 + 1] = -1.0;
	M1_vertices[12 + 2] = 1.0;

	// 6 vertex of M1
	M1_vertices[12 + 3] = 1.0;
	M1_vertices[12 + 4] = -1.0;
	M1_vertices[12 + 5] = 1.0;

	// 7 vertex of M1
	M1_vertices[12 + 6] = 1.0;
	M1_vertices[12 + 7] = 1.0;
	M1_vertices[12 + 8] = 1.0;

	// 8 vertex of M1
	M1_vertices[12 + 9] = -1.0;
	M1_vertices[12 + 10] = 1.0;
	M1_vertices[12 + 11] = 1.0;

	int indices[indicesArrayLengthEs1] = {
			0,1,2, //fb
			3,2,0, //ft
			4,7,0, //lt
			3,7,0, //lb
			3,7,2, //tl
			7,1,6, //tr
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





	/*
	M1_vertices.push_back(-1.0);
	M1_vertices.push_back(-1.0);
	M1_vertices.push_back(-1.0);
	for(int i =0;i<3;i++)
		printf("Value %d: %f\n", i, M1_vertices[i + 1]);

	// second vertex of M1
	M1_vertices.push_back(1.0);
	M1_vertices.push_back(-1.0);
	M1_vertices.push_back(-1.0);

	// third vertex of M1
	M1_vertices.push_back(1.0);
	M1_vertices.push_back(1.0);
	M1_vertices.push_back(-1.0);

	// fourth vertex of M1
	M1_vertices.push_back(-1.0);
	M1_vertices.push_back(1.0);
	M1_vertices.push_back(-1.0);

	//FRONT FACE
	// 5 vertex of M1
	M1_vertices.push_back(-1.0);
	M1_vertices.push_back(-1.0);
	M1_vertices.push_back(1.0);

	// 6 vertex of M1
	M1_vertices.push_back(1.0);
	M1_vertices.push_back(-1.0);
	M1_vertices.push_back(1.0);

	// 7 vertex of M1
	M1_vertices.push_back(1.0);
	M1_vertices.push_back(1.0);
	M1_vertices.push_back(1.0);

	// 8 vertex of M1
	M1_vertices.push_back(-1.0);
	M1_vertices.push_back(1.0);
	M1_vertices.push_back(1.0);*/
}

void es2() {

	int nCircleVertices = 20;

	int centerUpIndex = nCircleVertices * 2;
	int centerDownIndex = nCircleVertices * 2 + 1;


	std::vector<float> circleVertices;
	std::vector<uint32_t> circleIndices;

	M2_vertices.resize((nCircleVertices + 1) * 2 * 3);
	//numCircleVertices + center
	M2_indices.resize(nCircleVertices * 4 * 3);


	//center up and down
	M2_vertices[centerUpIndex * 3] = 0;
	M2_vertices[centerUpIndex * 3+2] = 0;
	M2_vertices[centerUpIndex * 3+1] = 1;
	M2_vertices[centerDownIndex * 3] = 0;
	M2_vertices[centerDownIndex * 3 + 2] = 0;
	M2_vertices[centerDownIndex * 3+ 1] = -1;


	//1 first
	M2_vertices[0] = cos(0);
	M2_vertices[2] = sin(0);
	M2_vertices[1] = 1;
	M2_vertices[3] = cos(0);
	M2_vertices[5] = sin(0);
	M2_vertices[4] = -1;




	for (int line = 1; line < nCircleVertices; line++) {


		//points of new line
		M2_vertices[6 * line] = cos(2 * pi / nCircleVertices * line);
		M2_vertices[6 * line + 2] = sin(2 * pi / nCircleVertices * line);
		M2_vertices[6 * line + 1] = 1;

		M2_vertices[6 * line + 3] = cos(2 * pi / nCircleVertices * line);
		M2_vertices[6 * line + 5] = sin(2 * pi / nCircleVertices * line);
		M2_vertices[6 * line + 4] = -1;


		//connect currentLine with previous line
		M2_indices[(line - 1) * 12] = line * 2 - 2;
		M2_indices[(line - 1) * 12 + 1] = line * 2 - 1;
		M2_indices[(line - 1) * 12 + 2] = line * 2;
		M2_indices[(line - 1) * 12 + 3] = line * 2;
		M2_indices[(line - 1) * 12 + 4] = line * 2 - 1;
		M2_indices[(line - 1) * 12 + 5] = line * 2 + 1;

		/*printf("Draw parete: \n");
		printf("Connecting %d, %d, %d\n", line * 2 - 2, line * 2 - 1, line * 2);
		printf("Connecting %d, %d, %d\n\n", line * 2, line * 2 - 1, line * 2+ 1);*/


		//draw up triangle
		M2_indices[(line - 1) * 12 + 6] = line * 2 - 2;
		M2_indices[(line - 1) * 12 + 7] = line * 2;
		M2_indices[(line - 1) * 12 + 8] = centerUpIndex;

		/*printf("Draw up triangle: \n");
		printf("Connecting %d, %d, %d\n", line * 2 - 2, line * 2, nCircleVertices * 2);*/

		//draw down triangle
		M2_indices[(line - 1) * 12 + 9] = line * 2 - 1;
		M2_indices[(line - 1) * 12 + 10] = line * 2 + 1;
		M2_indices[(line - 1) * 12 + 11] = centerDownIndex;


		/*printf("Draw down triangle: \n");
		printf("Connecting %d, %d, %d\n", line * 2 - 1, line * 2 +1, nCircleVertices * 2 +1);*/


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

	/*printf("Draw up triangle: \n");
	printf("Connecting %d, %d, %d\n", nCircleVertices * 2 - 2, nCircleVertices * 2, nCircleVertices * 6);
	*/

	//draw down triangle
	M2_indices[(nCircleVertices - 1) * 12 + 9] = nCircleVertices * 2 - 1;
	M2_indices[(nCircleVertices - 1) * 12 + 10] = 1;
	M2_indices[(nCircleVertices - 1) * 12 + 11] = nCircleVertices * 2 + 1;

	/*
	printf("Draw down triangle: \n");
	printf("Connecting %d, %d, %d\n", nCircleVertices * 2 - 1, 1, nCircleVertices * 2 + 1);
	*/
	/*
	for (int i = 0; i <= nCircleVertices * 6; i++) {
		if ((i) % 3 == 0)
			printf("\nPoint %d: ", i / 3);
		printf("%f, ", M2_vertices[i]);
	}

	for (int i = 0; i < nCircleVertices * 6; i++) {
		if ((i) % 3 == 0)
			printf("\nTriangle %d: ", i / 3);
		printf("%d, ", M2_indices[i]);
	}
	*/

}



void es3() {
	
	int pointsPerCircle = 6;
	int radius = 2;
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


	//// M3 : Sphere
	// Replace the code below, that creates a simple triangle, with the one to create a sphere.

	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices components (3 * number of vertices)
	M3_vertices.resize(((bottomPointIndex + 1) * 3));
	M3_indices.resize((firstBottomTriangleIndex + pointsPerCircle) * 3);
	//between circles in sphere + top/bottom


	//define biggest diameter
	for (int point = 0; point < pointsPerCircle; point++) {

		//printf("Writing on Points: %d\n", point);
		M3_vertices[3 * point] = cos(2 * pi / pointsPerCircle * point);
		M3_vertices[3 * point + 2] = sin(2 * pi / pointsPerCircle * point);
		M3_vertices[3 * point + 1] = 0;
	}

	//printf("Writing on Points: %d\n", topPointIndex);
	M3_vertices[3 * topPointIndex] = 0;
	M3_vertices[3 * topPointIndex + 2] = 0;
	M3_vertices[3 * topPointIndex + 1] = 1;


	//printf("Writing on Points: %d\n", bottomPointIndex);
	M3_vertices[3 * bottomPointIndex + 0] = 0;
	M3_vertices[3 * bottomPointIndex + 2] = 0;
	M3_vertices[3 * bottomPointIndex + 1] = -1;
	
	//Mem organization

	//[longerDiamPoints|upper diam points|lower diam points|topPoint|bottomPoint] <- points
	//[internal Triangs from middle up| from middle down|uppest triangles|bottomest triangle] <- triangles

	for (int r = 1; r < radius; r++) {

		printf("\n\nDefining layer %d\n", r);

		printf("Writing on Points: %d\n", (firstUpperDiamPointIndex + (r - 1) * pointsPerCircle));
		M3_vertices[3 * (firstUpperDiamPointIndex + (r - 1) * pointsPerCircle)] = cos(2 * pi / pointsPerCircle * 0) * cos(pi / 2 / radius * r);
		M3_vertices[3 * (firstUpperDiamPointIndex + (r - 1) * pointsPerCircle) + 2] = sin(2 * pi / pointsPerCircle * 0) * cos(pi / 2 / radius * r);
		M3_vertices[3 * (firstUpperDiamPointIndex + (r - 1) * pointsPerCircle) + 1] = sin(pi / 2 / radius * r);

		printf("Writing on Points: %d\n", firstLowerPointIndex + (r - 1) * pointsPerCircle);
		M3_vertices[3 * (firstLowerPointIndex + (r - 1) * pointsPerCircle)] = cos(2 * pi / pointsPerCircle * 0) * cos(pi / 2 / radius * r);
		M3_vertices[3 * (firstLowerPointIndex + (r - 1) * pointsPerCircle) + 2] = sin(2 * pi / pointsPerCircle * 0) * cos(pi / 2 / radius * r);
		M3_vertices[3 * (firstLowerPointIndex + (r - 1) * pointsPerCircle) + 1] = -sin(pi / 2 / radius * r);
		
		
		for (int point = 1; point < pointsPerCircle; point++) {


			definedUpPoint = firstUpperDiamPointIndex + (r - 1) * pointsPerCircle + point;
			definedLowPoint = firstLowerPointIndex + (r - 1) * pointsPerCircle + point;

			printf("Create point %d. DefinedLowPoint: %d\n", r, definedLowPoint);

			printf("Writing on Points: %d\n", definedUpPoint);

			M3_vertices[3 * definedUpPoint] = cos(2 * pi / pointsPerCircle * point) * cos(pi / 2 / radius * r);
			M3_vertices[3 * definedUpPoint + 2] = sin(2 * pi / pointsPerCircle * point) * cos(pi / 2 / radius * r);
			M3_vertices[3 * definedUpPoint + 1] = sin(pi / 2 / radius * r);

			printf("Writing on Points: %d\n", definedLowPoint);
			M3_vertices[3 * definedLowPoint] = cos(2 * pi / pointsPerCircle * point) * cos(pi / 2 / radius * r);
			M3_vertices[3 * definedLowPoint + 2] = sin(2 * pi / pointsPerCircle * point) * cos(pi / 2 / radius * r);
			M3_vertices[3 * definedLowPoint + 1] = -sin(pi / 2 / radius * r);
			
			//upSphere
			printf("Writing on Indice: %d\n", (definedUpPoint - firstUpperDiamPointIndex - 1));
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1)] = definedUpPoint;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex -1) + 1] = definedUpPoint - 1;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 2] = definedUpPoint - 1 - pointsPerCircle;


			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 3] = definedUpPoint;
			M3_indices[6 * (definedUpPoint - firstUpperDiamPointIndex - 1) + 4] = definedUpPoint - pointsPerCircle;
			M3_indices[6* (definedUpPoint - firstUpperDiamPointIndex - 1) + 5] = definedUpPoint - 1 - pointsPerCircle;


			//downSphere
			writeOn = firstInternalTriangleFromMiddleDownIndex + definedLowPoint - firstLowerPointIndex - 1;
			printf("Writing on Indice: %d\n", writeOn);
			M3_indices[6 * writeOn] = definedLowPoint;
			M3_indices[6 * writeOn + 1] = definedLowPoint - 1;
			if (r==1)
				M3_indices[6 * writeOn + 2] = point - 1;
			else
				M3_indices[6 * writeOn + 2] = definedLowPoint - 1 - pointsPerCircle;


			M3_indices[6 * writeOn + 3] = definedLowPoint;
			if (r == 1) {
				M3_indices[6 * writeOn + 4] = point;
				M3_indices[6 * writeOn + 5] = point - 1;
			}
			else {
				M3_indices[6 * writeOn + 4] = definedLowPoint - pointsPerCircle;
				M3_indices[6 * writeOn + 5] = definedLowPoint - 1 - pointsPerCircle;
			}
			

			printf("Draw: \n");
			printf("Connecting %d, %d, %d\n", M3_indices[6 * writeOn + 3], M3_indices[6 * writeOn + 4], M3_indices[6 * writeOn + 5]);
			//printf("Connecting %d, %d, %d\n\n", definedUpPoint, definedUpPoint - pointsPerCircle, definedUpPoint - 1 - pointsPerCircle);
			

			/*if (r == radius - 1) {
				writeOn = firstTopTriangleIndex + point - 1;
				M3_indices[3 * writeOn] = definedUpPoint;
				M3_indices[3 * writeOn + 1] = definedUpPoint - 1;
				M3_indices[3 * writeOn + 2] = topPointIndex;


				writeOn = firstBottomTriangleIndex + point - 1;
				M3_indices[3 * writeOn] = definedLowPoint;
				M3_indices[3 * writeOn + 1] = definedLowPoint - 1;
				M3_indices[3 * writeOn + 2] = bottomPointIndex;
			}*/


		}



		//connecting first and last point of layer

		writeOn = firstTopTriangleIndex + point - 1;
		M3_indices[3 * writeOn] = definedUpPoint;
		M3_indices[3 * writeOn + 1] = definedUpPoint - 1;
		M3_indices[3 * writeOn + 2] = topPointIndex;


		writeOn = firstBottomTriangleIndex + point - 1;
		M3_indices[3 * writeOn] = definedLowPoint;
		M3_indices[3 * writeOn + 1] = definedLowPoint - 1;
		M3_indices[3 * writeOn + 2] = bottomPointIndex;

	}


	

	
	/*

	for (int i = 0; i < M3_vertices.size(); i++) {
		if ((i) % 3 == 0)
			printf("\nPoint %d: ", i / 3);
		printf("%f, ", M3_vertices[i]);
	}
	*/
	for (int i = 0; i < M3_indices.size(); i++) {
		if ((i) % 3 == 0)
			printf("\nTriangle %d: ", i / 3);
		printf("%d, ", M3_indices[i]);
	}

}



void drawCircle(int nPoints, float z) {

	//// M2 : Cylinder
	// Replace the code below, that creates a simple rotated square, with the one to create a cylinder.

	// Resizes the vertices array. Repalce the values with the correct number of
	// vertices components (3 * number of vertices)


	M2_vertices.resize((nPoints + 1) * 3);
	//numCircleVertices + center
	M2_indices.resize((nPoints) * 3);




	//0 center
	M2_vertices[(nPoints - 1) * 3] = 0;
	M2_vertices[(nPoints - 1) * 3 + 1] = 0;
	M2_vertices[(nPoints - 1) * 3 + 2] = z;

	//1 first
	M2_vertices[0] = cos(0);
	M2_vertices[1] = sin(0);
	M2_vertices[2] = z;


	for (int point = 1; point < nPoints; point++) {

		M2_vertices[3 * point] = cos(2 * pi / nPoints * point);
		M2_vertices[3 * point + 1] = sin(2 * pi / nPoints * point);
		M2_vertices[3 * point + 2] = z;

		M2_indices[(point - 1) * 3] = 0;
		M2_indices[(point - 1) * 3 + 1] = point - 1;
		M2_indices[(point - 1) * 3 + 2] = point;

	}

	M2_indices[(nPoints - 1) * 3] = 0; //primo punto cerchio
	M2_indices[(nPoints - 1) * 3 + 1] = nPoints - 1; //centro
	M2_indices[(nPoints - 1) * 3 + 2] = nPoints - 2; // ultimo punto cerchio


}

void printPoint(const std::string& input, std::vector<float> value, int pos) {

	printf("%s -> x: %f, y: %f, z: %f\n", input.c_str(), value[pos], value[pos+2], value[pos+1]);
}