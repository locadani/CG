#version 450
layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 1) uniform GlobalUniformBufferObject {
	float time;
} gubo;

void main() {
	outColor = vec4(abs(cos(gubo.time/2)), abs(sin(gubo.time/2)), abs(sin(gubo.time*4)), 1.0f);
}