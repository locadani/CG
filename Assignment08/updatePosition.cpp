// Create the world matrix for the robot
glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {

	//time
	/*
	static auto startTime = std::chrono::high_resolution_clock::now();
	static float lastTime = 0.0f;

	auto currentTime = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration<float, std::chrono::seconds::period>
		(currentTime - startTime).count();
	float deltaT = time - lastTime;
	lastTime = time;
	*/


	static float scale = 0.1, roll = 0, yaw =0;
	static glm::vec3 pos = glm::vec3(-3, 0, 2);	// variable to store robot position
	static glm::vec3 rot= glm::vec3(-3, 0, 2);	
	
	

	if (glfwGetKey(window, GLFW_KEY_W)) {
		pos += 
			glm::vec3(
				glm::rotate(glm::mat4(1.0f), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) *
				glm::vec4(1, 0, 0, 1)
			) * scale;
	}

	if (glfwGetKey(window, GLFW_KEY_S)) {
		pos -= glm::vec3(
			glm::rotate(glm::mat4(1.0f), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) *
			glm::vec4(1, 0, 0, 1)
		) * scale;
	}

	if (glfwGetKey(window, GLFW_KEY_A)) {
		pos -= glm::vec3(
			glm::rotate(glm::mat4(1.0f), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) *
			glm::vec4(0, 0, 1, 1)
		) * scale;
	}

	if (glfwGetKey(window, GLFW_KEY_D)) {
		pos += glm::vec3(
			glm::rotate(glm::mat4(1.0f), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) *
			glm::vec4(0, 0, 1, 1)
		) * scale;
	}

	if (glfwGetKey(window, GLFW_KEY_Q)) {
		yaw += scale;
	}

	if (glfwGetKey(window, GLFW_KEY_E)) {
		yaw -= scale;
	}


	glm::mat4 out;
	
	out = glm::translate(glm::mat4(1), pos) * glm::rotate(glm::mat4(1), yaw, glm::vec3(0, 1, 0));
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