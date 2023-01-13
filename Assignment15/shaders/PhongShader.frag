#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
	vec3 lightPos;
	vec3 lightColor;
	vec3 eyePos;
	vec4 coneInOutDecayExp;
	vec4 selector;
} gubo;


/**** Modify from here *****/

vec3 direct_light_dir(vec3 pos) {
	// Directional light direction
	return vec3(gubo.lightDir.x, gubo.lightDir.y, gubo.lightDir.z);
}

vec3 direct_light_color(vec3 pos) {
	// Directional light color
	return vec3(gubo.lightColor.x, gubo.lightColor.y, gubo.lightColor.z);
}

vec3 point_light_dir(vec3 pos) {
	// Point light direction
	vec3 pointToLight = normalize(gubo.lightPos - pos);
	
	return pointToLight;
}

vec3 point_light_color(vec3 pos) {
	// Point light color	
	vec3 distanceVector = gubo.lightPos	 - pos;
	float distanceModulus = length(distanceVector);
	float g = gubo.coneInOutDecayExp.z;
	float beta = gubo.coneInOutDecayExp.w;
		
	return gubo.lightColor * pow(g/distanceModulus, beta);
}

vec3 spot_light_dir(vec3 pos) {
	// Spot light direction
	vec3 distanceVector = normalize(gubo.lightPos - pos);
	
	return distanceVector;
}

vec3 spot_light_color(vec3 pos) {
	// Spot light color
    vec3 distanceVector = gubo.lightPos - pos;
    float distanceModulus = length(distanceVector);
    vec3 lx = normalize(distanceVector);
    float g = gubo.coneInOutDecayExp.z; 
    float beta = gubo.coneInOutDecayExp.w; 
	float l = pow(g/distanceModulus, beta);
	float toClampValue = (dot(lx, gubo.lightDir) - gubo.coneInOutDecayExp.x) 
		/ 
	(gubo.coneInOutDecayExp.y - gubo.coneInOutDecayExp.x);
	float clampedFactor = clamp(toClampValue, 0, 1);
	
	
	return l * clampedFactor * gubo.lightColor;
}

/**** To from here *****/





void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
	
	vec3 lD;	// light direction from the light model
	vec3 lC;	// light color and intensity from the light model
	
	lD = direct_light_dir(fragPos) * gubo.selector.x +
	     point_light_dir(fragPos)  * gubo.selector.y +
	     spot_light_dir(fragPos)   * gubo.selector.z;
	lC = direct_light_color(fragPos) * gubo.selector.x +
	     point_light_color(fragPos)  * gubo.selector.y +
	     spot_light_color(fragPos)   * gubo.selector.z;

	vec3 Diffuse = (texture(texSampler, fragTexCoord).rgb * gubo.selector.w + vec3(1,1,1) * (1-gubo.selector.w)) * (max(dot(Norm, lD),0.0f) );
	vec3 Specular = vec3(pow(max(dot(EyeDir, -reflect(lD, Norm)),0.0f), 64.0f));
	
	outColor = vec4((Diffuse + Specular) * lC, 1.0f);	
}