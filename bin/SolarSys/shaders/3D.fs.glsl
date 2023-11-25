#version 330 core

uniform sampler2D uTexture;

in vec4 vVertexPositionVC;
in vec4 vVertexNormalVC;

in vec2 vFragText;

out vec4 fFragColor;

void main() {
  vec4 text = texture(uTexture, vFragText);
  vec4 color_norm = normalize(vVertexNormalVC);
  fFragColor = text;
  //fFragColor = vec4(1.f, 0.f, 0.f, 0.f);
}