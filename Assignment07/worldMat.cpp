// Create a world matrix using position, Euler angles, and size
// Euler angles are passed in YPR parameter:
// YPR.x : Yaw
// YPR.y : Pitch
// YPR.z : Roll
glm::mat4 MakeWorldMatrixEuler(glm::vec3 pos, glm::vec3 YPR, glm::vec3 size) {
	glm::mat4 out = tra(pos.x, pos.y, pos.z)
		* rot(glm::radians(YPR.x), 0, 1, 0)
		* rot(glm::radians(YPR.y), 1, 0, 0)
		* rot(glm::radians(YPR.z), 0, 0, 1)
		* sca(size.x, size.y, size.z);
	return out;
}

// Create a world matrix using position, quaternion angles, and size
glm::mat4 MakeWorldMatrixQuat(glm::vec3 pos, glm::quat rQ, glm::vec3 size) {
	glm::mat4 quatRotation = glm::mat4(rQ);

	glm::mat4 out = tra(pos.x, pos.y, pos.z)
		* quatRotation
		* sca(size.x, size.y, size.z);
	return out;
}

