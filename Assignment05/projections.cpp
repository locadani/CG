
float n = 0.1f;
float f = 9.9f;

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 90o
glm::mat4 PO1(float a) {
	float fov = 0.78f;
	//tan(45) = 1
	float r = a*n;
	float l = -a*n;
	float b = -n;
	float t = n;

	glm::mat4 out = glm::perspective(0.78f, a, n, f); out[1][1] *= -1;
	return out;
}

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 120o
glm::mat4 PO2(float a) {
	float fov = 1.0472f;
	float tan = 1.73f;
	float r = a * n * tan;
	float l = -a * n * tan;
	float b = -n * tan;
	float t = n * tan;

	glm::mat4 out = glm::perspective(1.0472f, a, n, f);
	out[1][1] *= -1;
	return out;
}

// Create a matrix for Perspecrtive projection with the given aspect ratio a,
// and a FovY = 30o
glm::mat4 PO3(float a) {
	float fov = 0.2618f;
	float tan = 0.2679f;
	float r = a * n * tan;
	float l = -a * n * tan;
	float b = -n * tan;
	float t = n * tan;

	glm::mat4 out = glm::perspective(fov , a, n, f);
	out[1][1] *= -1;
	return out;
}

// Create a matrix for Perspective projection, with the given aspect ratio a.
// Here the perspective should only show the left side of the view
// with a FovY = 90o. Here r=0, and l, t and b should be computed
// to match both the aspect ratio and the FovY
glm::mat4 PO4(float a) {
	float fov = 0.7854f;
	//float tan = 1;
	float r = 0;
	float l = -a * n;
	float b = -n;
	float t = n;


	glm::mat4 out = sca(1, -1, 1) * glm::frustum(l, r, b, t, n, f);

	return out;
}