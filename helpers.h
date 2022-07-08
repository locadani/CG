glm::mat4 tra(int x, int y, int z) {
	return glm::translate(glm::mat4(1), glm::vec3(x, y, z));
}

glm::mat4 rot(float rad, int x, int y, int z) {
	return glm::rotate(glm::mat4(1), rad, glm::vec3(x, y, z));
}

glm::mat4 sca(float x, float y, float z) {
	return glm::scale(glm::mat4(1), glm::vec3(x, y, z));
}

glm::mat4 sca(float val) {
	return glm::scale(glm::mat4(1), glm::vec3(val));
}
