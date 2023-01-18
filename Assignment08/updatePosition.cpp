// Create the world matrix for the robot
glm::mat4 getRobotWorldMatrix(GLFWwindow* window) {
	
	static float scale = 0.05, roll = 0, yaw = 0;
	static glm::vec3 pos = glm::vec3(-3, 0, 2);	// variable to store robot position
	static glm::vec3 rot = glm::vec3(-3, 0, 2);



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