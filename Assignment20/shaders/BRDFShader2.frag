#version 450

layout(set = 0, binding = 1) uniform sampler2D ambientSampler;

layout(set = 0, binding = 2) uniform GlobalUniformBufferObject2 {
	vec3 lightDir;
	vec3 lightColor;
	vec3 eyePos;
} gubo2;

layout(set = 0, binding = 3) uniform sampler2D specularSampler;

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNormal;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

//ambient plus spec Blinn lit by directional light
void main() {
	
	vec3 dirColor = gubo2.lightColor;

    vec3 ambient = texture(ambientSampler, fragTexCoord).rgb;

    //compute Blinn
    vec4 texel = texture(specularSampler, fragTexCoord);
    vec3 blinnColor = texel.rgb;
    vec3 h = normalize(gubo2.lightDir + normalize(fragNormal));
    vec3 blinn = blinnColor * pow(
            clamp(dot(fragNormal, h), 0, 1), 
        200.0f * texel.a);
    outColor = vec4(dirColor * blinn + ambient, 1.0f);
}