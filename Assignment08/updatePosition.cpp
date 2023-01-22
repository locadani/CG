// Create the world matrix for the robot
glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {
	
	static float scale = 0.05, roll = 0, yaw = 0;
	static glm::vec3 pos = glm::vec3(-3, 0, 2);	// variable to store robot position
	static glm::vec3 rot = glm::vec3(-3, 0, 2);
	
	static auto startTime = std::chrono::high_resolution_clock::now();
	static float lastTime = 0.0f;
	
	auto currentTime = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration<float, std::chrono::seconds::period>
				(currentTime - startTime).count();
	float deltaT = time - lastTime;
	lastTime = time;
	



	if (glfwGetKey(window, GLFW_KEY_W)) {
		pos +=
			glm::vec3(
				glm::rotate(glm::mat4(1.0f), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) *
				glm::vec4(1, 0, 0, 1)
			) * deltaT;
	}

	if (glfwGetKey(window, GLFW_KEY_S)) {
		pos -= glm::vec3(
			glm::rotate(glm::mat4(1.0f), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) *
			glm::vec4(1, 0, 0, 1)
		) * deltaT;
	}

	if (glfwGetKey(window, GLFW_KEY_A)) {
		pos -= glm::vec3(
			glm::rotate(glm::mat4(1.0f), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) *
			glm::vec4(0, 0, 1, 1)
		) * deltaT;
	}

	if (glfwGetKey(window, GLFW_KEY_D)) {
		pos += glm::vec3(
			glm::rotate(glm::mat4(1.0f), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) *
			glm::vec4(0, 0, 1, 1)
		) * deltaT;
	}

	if (glfwGetKey(window, GLFW_KEY_Q)) {
		yaw += deltaT;
	}

	if (glfwGetKey(window, GLFW_KEY_E)) {
		yaw -= deltaT;
	}


	glm::mat4 out;

	out = glm::translate(glm::mat4(1), pos) * glm::rotate(glm::mat4(1), yaw, glm::vec3(0, 1, 0));
	return out;
}