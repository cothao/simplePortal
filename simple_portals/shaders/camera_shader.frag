
#version 330 core
out vec4 FragColor;
  
in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D texture1;

vec3 lightPos = vec3(10., 10., 5.);

void main()
{

    vec3 ambient = vec3(texture(texture1, TexCoord));

    vec3 lightDir = normalize(FragPos - lightPos);

    float d = dot(Normal, lightDir);

    vec4 result = vec4(ambient + d + vec3(1., 0. ,0.), 1.);

    FragColor = result;
} 