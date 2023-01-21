#version 450

layout(set = 0, binding = 1) uniform sampler2D diffuseSampler;

layout(set = 0, binding = 2) uniform GlobalUniformBufferObject1 {
	vec3 lightDir;
	vec3 lightPos;
	vec3 lightColor;
	vec4 lightParams;
	vec3 eyePos;
} gubo1;

layout(set = 0, binding = 3) uniform sampler2D specularSampler;

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNormal;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

//Lambert diffuse and spec Phong lit by spot light
void main() {

    //compute spot light color
    vec3 distanceVector = gubo1.lightPos - fragPos;
    float distanceModulus = length(distanceVector);
    vec3 normalizedDir = distanceVector / distanceModulus;
    float cout = gubo1.lightParams.y;
    float cin = gubo1.lightParams.x;
    float toClampValue = (dot(normalizedDir, gubo1.lightDir) - cout) / (cin - cout);
    
    //to multiply by fr
    vec3 spotLight = gubo1.lightColor * clamp(toClampValue, 0 ,1);

    //compute Lambert diffuse
    vec3 lambert = texture(diffuseSampler, fragTexCoord).rgb * max(dot(normalizedDir, normalize(fragNormal)), 0);

    //compute Phong
    vec4 texel = texture(specularSampler, fragTexCoord);
    vec3 ms = texel.rgb;
    vec3 wr = normalize(gubo1.eyePos - fragPos);
    vec3 r = reflect(normalizedDir, fragNormal) * (-1);
    r = 2*dot(gubo1.lightDir, fragNormal) * fragNormal - gubo1.lightDir;
    vec3 phong = ms * pow(clamp(dot(wr, r), 0, 1), 200.0f * texel.a);
    outColor = vec4(spotLight * (lambert + phong), 1.0f);
}