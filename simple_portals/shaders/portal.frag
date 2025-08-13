
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

    FragColor = vec4(ambient, 1.);
} 