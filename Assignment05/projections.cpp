
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
	glm::mat4 out = glm::mat4(1);
	/*
	glm::mat4 p = glm::mat4(2 * n / (r - l), 0, 0, 0,
		0, 2 * n / (b - t), 0, 0, 
		(r + l) / (r - l), (t + b) / (b - t), f / (n - f), -1, 
		0, 0, n * f / (n - f), 0);
		*/
	glm::mat4 u = glm::mat4(n, 0, 0, 0, 0, n, 0, 0, 0, 0, n, -1, 0, 0, 1, 0);
	glm::mat4 m = glm::mat4(1,0,0,0,0,-1,0,0,0,0,1,0,0,0,0,1); //adds background (?)
	glm::mat4 s = glm::mat4(2/(r-l),0,0,0,0,2/(t-b),0,0,0,0,n*f/(n-f),0,0,0,0,1);
	glm::mat4 tm= glm::mat4(1,0,0,0,0,1,0,0,0,0,1,0,-(r+l)/2,-(t+b)/2,-(n-1/n),1);
	//out = rot(-1.8f, 0, 1, 0);
	//out = glm::frustum(l, r, b, t, n, f);
	out = glm::perspective(0.78f, a, n, f); out[1][1] *= -1;
	//glm::mat4 out = sca(1, -1, 1) * glm::frustum(l, r, b, t, n, f) * glm::mat4(1.0);
	//out = tm*s*m*u * out;
	//out = sca(1, -1, 1) *  glm::frustum(l, r, b, t, n, f) * out;
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

	glm::mat4 p = glm::mat4(2 * n / (r - l), 0, 0, 0,
		0, 2 * n / (b - t), 0, 0,
		(r + l) / (r - l), (t + b) / (b - t), f / (n - f), -1,
		0, 0, n * f / (n - f), 0);
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

	glm::mat4 p = glm::mat4(2 * n / (r - l), 0, 0, 0,
		0, 2 * n / (b - t), 0, 0,
		(r + l) / (r - l), (t + b) / (b - t), f / (n - f), -1,
		0, 0, n * f / (n - f), 0);
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