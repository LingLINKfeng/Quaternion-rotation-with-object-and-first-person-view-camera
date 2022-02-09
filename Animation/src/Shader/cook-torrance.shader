#shader vertex
#version 330

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 Normal;
out vec3 FragPos;

void main()
{
	FragPos = vec3(model * vec4(aPos, 1.0));
	Normal = mat3(transpose(inverse(model))) * aNormal;
	gl_Position = projection * view * model * vec4(aPos, 1.0);

}

#shader fragment
#version 330
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform float roughness;
uniform bool blinn;

void main()
{
	float roughnessValue = roughness; // 0 : smooth, 1: rough
	float F0 = 0.8; // fresnel reflectance at normal incidence
	float k = 0.3; // fraction of diffuse reflection (specular reflection = 1 - k)

	// ambient
	float ambientStrength = 0.05;
	vec3 ambient = ambientStrength * lightColor;

	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float NL = max(dot(norm, lightDir), 0.0);

	float spec = 0;
	 {
		//spec=F*D*G/pi*dot(n,l)*dot(n,v)
		vec3 viewDir = normalize(viewPos - FragPos);
		vec3 halfwayDir = normalize(lightDir + viewDir);
		float NH = max(dot(norm, halfwayDir), 0.0);
		float NV = max(dot(norm, viewDir), 0.0);
		float VH = max(dot(viewDir, halfwayDir), 0.0);
		float mSquared = roughnessValue * roughnessValue;

		//G=MIN(1,2*dot(n,h)*dot(n,v)/dot(v,h),2*dot(n,h)*dot(n,l)/dot(v,h))
		float g1 = (NH*2.0*NV) / VH;
		float g2 = (NH*2.0*NL) / VH;
		float G = min(1.0,min(g1,g2));
		//D=exp(((NH*NH)-1)/m*m*dot(n,h)*dot(n,h))/pi*m*m*pow(dot(n,h),4)
		float D = exp((NH*NH-1.0)/(mSquared*NH*NH))/(3.14*mSquared*pow(NH,4.0));
		//F=F0+(1-F0)pow((1-dot(h,v)),5)
		float F = F0+ pow(1.0 - VH, 5.0)* (1.0 - F0);
		spec = (G * D * F) / (NV*NL*3.14);
	}
	vec3 specular = lightColor*NL * (k + spec * (1.0 - k));
	vec3 result = (ambient +  specular) * objectColor;
	FragColor = vec4(result, 1.0);
}

//reference£ºhttps://www.youtube.com/watch?v=Xi1FZZJ235I£¬https://zhuanlan.zhihu.com/p/152226698
