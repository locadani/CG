 // Create a look in direction matrix
 // Pos    -> Position of the camera
 // Angs.x -> direction (alpha)
 // Angs.y -> elevation (beta)
 // Angs.z -> roll (rho)
glm::mat4 LookInDirMat(glm::vec3 Pos, glm::vec3 Angs) {

	glm::mat4 out = rot(-Angs.z, 0, 0, 1) * rot(-Angs.y, 1, 0, 0) * rot( - Angs.x, 0, 1, 0) * glm::translate(glm::mat4(1), -Pos);
	return out;
}

 // Create a look at matrix
 // Pos    -> Position of the camera (c)
 // aim    -> Posizion of the target (a)
 // Roll   -> roll (rho)
glm::mat4 LookAtMat(glm::vec3 Pos, glm::vec3 aim, float Roll) {
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 out = glm::rotate(glm::lookAt(Pos, aim, up), Roll, glm::vec3(0, 0, 1));
	return out;
}



