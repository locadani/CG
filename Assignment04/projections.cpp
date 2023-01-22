// Create a matrix for Isometric projection with the given aspect ration a
//120 deg between all axis
glm::mat4 PO1(float a) {
	//rotation of 35.26 of x axis * rotation of 45 of y axis
	glm::mat4 out = sca(1, -1, 1) * 
	glm::ortho(-2.0f, 2.0f, -2.0f / a, 2.0f / a, -4.0f, 12.0f) * rot(0.6154f, 1, 0, 0) * rot(0.785f, 0, 1, 0);
	return out;
}

// Create a matrix for Dimnetric projection (alpha = 45 degree)
// with the given aspect ration a
// x,z axis have same unit
glm::mat4 PO2(float a) {
	//rotation of 45 of x, y axis
	glm::mat4 out = sca(1,-1,1) * glm::ortho(-2.0f, 2.0f, -2.0f / a, 2.0f / a, -4.0f, 12.0f) * rot(0.785f, 1, 0, 0) * rot(0.785f, 0, 1, 0);
	return out;
}

// Create a matrix for Trimetric projection (alpha = 45 degree, beta = 60 degree)
// with the given aspect ration a
// different unit for each axis
glm::mat4 PO3(float a) {
	glm::mat4 out = sca(1, -1, 1) * glm::ortho(-2.0f, 2.0f, -2.0f / a, 2.0f / a, -4.0f, 12.0f) * rot(0.785f, 1, 0, 0) * rot(1.0472f, 0, 1, 0) * glm::mat4(1.0);
	return out;
}

// Create a matrix for Cabinet projection (alpha = 45)
// with the given aspect ration a
//x, y parallel to screen; x,y,z same unit
glm::mat4 PO4(float a) {
	glm::mat4 shear= glm::mat4(1, 0, 0, 0,
		0,1, 0, 0, 
		-0.5f * 0.7071, -0.5f * 0.7071,1, 0,
		0, 0, 0, 1);
	glm::mat4 out = sca(1, -1, 1) * glm::ortho(-2.0f, 2.0f, -2.0f / a, 2.0f / a, -4.0f, 12.0f) * shear * glm::mat4(1.0);
	return out;
}

