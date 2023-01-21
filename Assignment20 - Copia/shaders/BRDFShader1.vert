#version 450

layout(set = 0, binding = 0) uniform UniformBufferObject {
    mat4 mvpMat;
    mat4 mMat;
    mat4 nMat;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexCoord;

layout(location = 0) out vec3 fragPos;
layout(location = 1) out vec3 fragNormal;
layout(location = 2) out vec2 fragTexCoord;

void main() {
    gl_Position = ubo.mvpMat * vec4(inPosition, 1.0);
    fragPos = vec3(ubo.mMat * vec4(inPosition, 1.0));
    fragNormal = vec3(ubo.nMat * vec4(inNormal, 0.0));
    fragTexCoord = inTexCoord;
}