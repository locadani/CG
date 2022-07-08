// Create the world matrix for the robot
glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {

	float scale = 0.1, radX = 0, radY =0;
	static glm::vec3 pos = glm::vec3(-3, 0, 2);	// variable to store robot position
	static glm::vec3 rot= glm::vec3(-3, 0, 2);	
	
	

	if (glfwGetKey(window, GLFW_KEY_W)) {
		pos.x += scale;
	}

	if (glfwGetKey(window, GLFW_KEY_A)) {
		pos.z -= scale;
	}

	if (glfwGetKey(window, GLFW_KEY_S)) {
		pos.x -= scale;
	}

	if (glfwGetKey(window, GLFW_KEY_D)) {
		pos.z += scale;
	}

	if (glfwGetKey(window, GLFW_KEY_Q)) {
		radX += scale;
	}

	if (glfwGetKey(window, GLFW_KEY_E)) {
		radY += scale;
	}


												// here glm::vec3(-3,0,2) represents a
												// meaningful initial position for the robot
												//
												// this variable is here just as an example!
												// it should replaced or combined with
												//  the ones you think necessary for the task
	glm::mat4 out;
	
	out = glm::translate(glm::mat4(1), pos) * glm::rotate(glm::mat4(1), radX, glm::vec3(1, 0, 0))
		* glm::rotate(glm::mat4(1), radY, glm::vec3(0, 1, 0));
												// this line has to be changed!
												// it is here just to allow the program to
												// be compiled and run
	return out;
}
/*
void test() {
	glm::mat4 WorldMatrix;
	glm::vec3 ux = glm::vec3(glm::rotate(glm::mat4(1),
		yaw, glm::vec3(0, 1, 0)) *
		glm::vec4(1, 0, 0, 1));
	glm::vec3 uy = glm::vec3(0, 1, 0);
	glm::vec3 uz = glm::vec3(glm::rotate(glm::mat4(1),
		yaw, glm::vec3(0, 1, 0)) *
		glm::vec4(0, 0, -1, 1));
	pitch += omega * rx * dt;
	yaw += omega * ry * dt;
	roll += omega * rz * dt;
	pos += ux * mu * mx * dt;
	pos += uy * mu * my * dt;
	pos += uz * mu * mz * dt;
	WorldMatrix = MakeWorldEuler(pos,
		alpha, beta, rho);
}

*/