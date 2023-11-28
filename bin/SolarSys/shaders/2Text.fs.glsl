#version 330 core

uniform sampler2D uTexture;
uniform sampler2D uSecondTexture;

in vec4 vVertexPositionVC;
in vec4 vVertexNormalVC;

in vec2 vFragText;

out vec4 fFragColor;


void main() {
    // Own code
    vec4 text = texture(uTexture, vFragText);
    vec4 text2 = texture(uSecondTexture, vFragText);

    fFragColor =  text + text2;
}
