xof 0303txt 0032
template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}


Mesh {
 148;
 -1.000000;-12.999999;0.000000;,
 -1.000000;-12.999999;0.000000;,
 -1.000000;-12.802500;-2.257427;,
 -1.000000;-12.802500;-2.257427;,
 -1.000000;-12.802493;2.257416;,
 -1.000000;-12.802493;2.257416;,
 -1.000000;-12.802493;2.257416;,
 -1.000000;-12.216002;-4.446262;,
 -1.000000;-12.216002;-4.446262;,
 -1.000000;-12.215998;4.446250;,
 -1.000000;-12.215998;4.446250;,
 -1.000000;-11.258329;-6.500000;,
 -1.000000;-11.258329;-6.500000;,
 -1.000000;-11.258326;6.499988;,
 -1.000000;-11.258326;6.499988;,
 -1.000000;-9.958576;8.356227;,
 -1.000000;-9.958576;8.356227;,
 -1.000000;-9.958575;-8.356238;,
 -1.000000;-9.958575;-8.356238;,
 -1.000000;-8.356239;9.958566;,
 -1.000000;-8.356239;9.958566;,
 -1.000000;-8.356237;-9.958576;,
 -1.000000;-8.356237;-9.958576;,
 -1.000000;-6.500002;11.258319;,
 -1.000000;-6.500002;11.258319;,
 -1.000000;-6.499998;-11.258329;,
 -1.000000;-6.499998;-11.258329;,
 -1.000000;-4.446266;12.215994;,
 -1.000000;-4.446266;12.215994;,
 -1.000000;-4.446258;-12.216002;,
 -1.000000;-4.446258;-12.216002;,
 -1.000000;-2.257432;12.802492;,
 -1.000000;-2.257432;12.802492;,
 -1.000000;-2.257424;-12.802497;,
 -1.000000;-2.257424;-12.802497;,
 -1.000000;-0.000007;12.999992;,
 -1.000000;-0.000007;12.999992;,
 -1.000000;0.000000;0.000000;,
 -1.000000;0.000002;-12.999996;,
 -1.000000;0.000002;-12.999996;,
 -1.000000;2.257419;12.802494;,
 -1.000000;2.257419;12.802494;,
 -1.000000;2.257428;-12.802497;,
 -1.000000;2.257428;-12.802497;,
 -1.000000;4.446253;12.216000;,
 -1.000000;4.446253;12.216000;,
 -1.000000;4.446262;-12.216000;,
 -1.000000;4.446262;-12.216000;,
 -1.000000;6.499992;11.258326;,
 -1.000000;6.499992;11.258326;,
 -1.000000;6.500000;-11.258326;,
 -1.000000;6.500000;-11.258326;,
 -1.000000;8.356230;9.958576;,
 -1.000000;8.356230;9.958576;,
 -1.000000;8.356238;-9.958572;,
 -1.000000;8.356238;-9.958572;,
 -1.000000;9.958569;8.356238;,
 -1.000000;9.958569;8.356238;,
 -1.000000;9.958576;-8.356233;,
 -1.000000;9.958576;-8.356233;,
 -1.000000;11.258322;6.500000;,
 -1.000000;11.258322;6.500000;,
 -1.000000;11.258327;-6.499995;,
 -1.000000;11.258327;-6.499995;,
 -1.000000;12.215997;4.446263;,
 -1.000000;12.215997;4.446263;,
 -1.000000;12.216002;-4.446257;,
 -1.000000;12.216002;-4.446257;,
 -1.000000;12.802494;2.257430;,
 -1.000000;12.802494;2.257430;,
 -1.000000;12.802497;-2.257422;,
 -1.000000;12.802497;-2.257422;,
 -1.000000;12.999994;0.000004;,
 -1.000000;12.999994;0.000004;,
 1.000000;-12.999999;0.000000;,
 1.000000;-12.999999;0.000000;,
 1.000000;-12.802500;-2.257427;,
 1.000000;-12.802500;-2.257427;,
 1.000000;-12.802493;2.257416;,
 1.000000;-12.802493;2.257416;,
 1.000000;-12.802493;2.257416;,
 1.000000;-12.216002;-4.446262;,
 1.000000;-12.216002;-4.446262;,
 1.000000;-12.215998;4.446250;,
 1.000000;-12.215998;4.446250;,
 1.000000;-11.258329;-6.500000;,
 1.000000;-11.258329;-6.500000;,
 1.000000;-11.258326;6.499988;,
 1.000000;-11.258326;6.499988;,
 1.000000;-9.958576;8.356227;,
 1.000000;-9.958576;8.356227;,
 1.000000;-9.958575;-8.356238;,
 1.000000;-9.958575;-8.356238;,
 1.000000;-8.356239;9.958566;,
 1.000000;-8.356239;9.958566;,
 1.000000;-8.356237;-9.958576;,
 1.000000;-8.356237;-9.958576;,
 1.000000;-6.500002;11.258319;,
 1.000000;-6.500002;11.258319;,
 1.000000;-6.499998;-11.258329;,
 1.000000;-6.499998;-11.258329;,
 1.000000;-4.446266;12.215994;,
 1.000000;-4.446266;12.215994;,
 1.000000;-4.446258;-12.216002;,
 1.000000;-4.446258;-12.216002;,
 1.000000;-2.257432;12.802492;,
 1.000000;-2.257432;12.802492;,
 1.000000;-2.257424;-12.802497;,
 1.000000;-2.257424;-12.802497;,
 1.000000;-0.000007;12.999992;,
 1.000000;-0.000007;12.999992;,
 1.000000;0.000000;0.000000;,
 1.000000;0.000002;-12.999996;,
 1.000000;0.000002;-12.999996;,
 1.000000;2.257419;12.802494;,
 1.000000;2.257419;12.802494;,
 1.000000;2.257428;-12.802497;,
 1.000000;2.257428;-12.802497;,
 1.000000;4.446253;12.216000;,
 1.000000;4.446253;12.216000;,
 1.000000;4.446262;-12.216000;,
 1.000000;4.446262;-12.216000;,
 1.000000;6.499992;11.258326;,
 1.000000;6.499992;11.258326;,
 1.000000;6.500000;-11.258326;,
 1.000000;6.500000;-11.258326;,
 1.000000;8.356230;9.958576;,
 1.000000;8.356230;9.958576;,
 1.000000;8.356238;-9.958572;,
 1.000000;8.356238;-9.958572;,
 1.000000;9.958569;8.356238;,
 1.000000;9.958569;8.356238;,
 1.000000;9.958576;-8.356233;,
 1.000000;9.958576;-8.356233;,
 1.000000;11.258322;6.500000;,
 1.000000;11.258322;6.500000;,
 1.000000;11.258327;-6.499995;,
 1.000000;11.258327;-6.499995;,
 1.000000;12.215997;4.446263;,
 1.000000;12.215997;4.446263;,
 1.000000;12.216002;-4.446257;,
 1.000000;12.216002;-4.446257;,
 1.000000;12.802494;2.257430;,
 1.000000;12.802494;2.257430;,
 1.000000;12.802497;-2.257422;,
 1.000000;12.802497;-2.257422;,
 1.000000;12.999994;0.000004;,
 1.000000;12.999994;0.000004;;
 144;
 3;37,6,10;,
 3;37,10,14;,
 3;37,14,16;,
 3;37,16,20;,
 3;37,20,24;,
 3;37,24,28;,
 3;37,28,32;,
 3;37,32,36;,
 3;37,36,41;,
 3;37,41,45;,
 3;37,45,49;,
 3;37,49,53;,
 3;37,53,57;,
 3;37,57,61;,
 3;37,61,65;,
 3;37,65,69;,
 3;37,69,73;,
 3;37,73,71;,
 3;37,71,67;,
 3;37,67,63;,
 3;37,63,59;,
 3;37,59,55;,
 3;37,55,51;,
 3;37,51,47;,
 3;37,47,43;,
 3;37,43,39;,
 3;37,39,34;,
 3;37,34,30;,
 3;37,30,26;,
 3;37,26,22;,
 3;37,22,18;,
 3;37,18,12;,
 3;37,12,8;,
 3;37,8,3;,
 3;37,3,1;,
 3;37,1,6;,
 3;111,84,80;,
 3;111,88,84;,
 3;111,90,88;,
 3;111,94,90;,
 3;111,98,94;,
 3;111,102,98;,
 3;111,106,102;,
 3;111,110,106;,
 3;111,115,110;,
 3;111,119,115;,
 3;111,123,119;,
 3;111,127,123;,
 3;111,131,127;,
 3;111,135,131;,
 3;111,139,135;,
 3;111,143,139;,
 3;111,147,143;,
 3;111,145,147;,
 3;111,141,145;,
 3;111,137,141;,
 3;111,133,137;,
 3;111,129,133;,
 3;111,125,129;,
 3;111,121,125;,
 3;111,117,121;,
 3;111,113,117;,
 3;111,108,113;,
 3;111,104,108;,
 3;111,100,104;,
 3;111,96,100;,
 3;111,92,96;,
 3;111,86,92;,
 3;111,82,86;,
 3;111,77,82;,
 3;111,75,77;,
 3;111,80,75;,
 3;83,9,5;,
 3;79,83,5;,
 3;87,13,9;,
 3;83,87,9;,
 3;89,15,13;,
 3;87,89,13;,
 3;93,19,15;,
 3;89,93,15;,
 3;97,23,19;,
 3;93,97,19;,
 3;101,27,23;,
 3;97,101,23;,
 3;105,31,27;,
 3;101,105,27;,
 3;109,35,31;,
 3;105,109,31;,
 3;114,40,35;,
 3;109,114,35;,
 3;118,44,40;,
 3;114,118,40;,
 3;122,48,44;,
 3;118,122,44;,
 3;126,52,48;,
 3;122,126,48;,
 3;130,56,52;,
 3;126,130,52;,
 3;134,60,56;,
 3;130,134,56;,
 3;138,64,60;,
 3;134,138,60;,
 3;142,68,64;,
 3;138,142,64;,
 3;146,72,68;,
 3;142,146,68;,
 3;144,70,72;,
 3;146,144,72;,
 3;140,66,70;,
 3;144,140,70;,
 3;136,62,66;,
 3;140,136,66;,
 3;132,58,62;,
 3;136,132,62;,
 3;128,54,58;,
 3;132,128,58;,
 3;124,50,54;,
 3;128,124,54;,
 3;120,46,50;,
 3;124,120,50;,
 3;116,42,46;,
 3;120,116,46;,
 3;112,38,42;,
 3;116,112,42;,
 3;107,33,38;,
 3;112,107,38;,
 3;103,29,33;,
 3;107,103,33;,
 3;99,25,29;,
 3;103,99,29;,
 3;95,21,25;,
 3;99,95,25;,
 3;91,17,21;,
 3;95,91,21;,
 3;85,11,17;,
 3;91,85,17;,
 3;81,7,11;,
 3;85,81,11;,
 3;76,2,7;,
 3;81,76,7;,
 3;74,0,2;,
 3;76,74,2;,
 3;78,4,0;,
 3;74,78,0;;

 MeshNormals {
  148;
  0.000000;-1.000000;0.000002;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.984808;-0.173648;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.984808;0.173649;,
  0.000000;-0.984808;0.173649;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.939693;-0.342020;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.939693;0.342019;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.866025;-0.500000;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.866026;0.499999;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.766045;0.642787;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.766044;-0.642788;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.642788;0.766044;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.642787;-0.766045;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.500001;0.866025;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.500000;-0.866026;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.342021;0.939692;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.342020;-0.939693;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.173649;0.984808;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.173648;-0.984808;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.173648;0.984808;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.173648;-0.984808;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.342020;0.939693;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.342020;-0.939693;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.500000;0.866026;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.500000;-0.866025;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.642787;0.766045;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.642788;-0.766044;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.766044;0.642788;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.766045;-0.642787;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.866025;0.500000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.866026;-0.500000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.939692;0.342021;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.939693;-0.342020;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.984808;0.173649;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.984808;-0.173648;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;-1.000000;0.000002;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.984808;-0.173648;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.984808;0.173649;,
  0.000000;-0.984808;0.173649;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.939693;-0.342020;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.939693;0.342019;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.866025;-0.500000;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.866026;0.499999;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.766045;0.642787;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.766044;-0.642788;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.642788;0.766044;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.642787;-0.766045;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.500001;0.866025;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.500000;-0.866026;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.342021;0.939692;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.342020;-0.939693;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.173649;0.984808;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.173648;-0.984808;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.173648;0.984808;,
  1.000000;0.000000;0.000000;,
  0.000000;0.173648;-0.984808;,
  1.000000;0.000000;0.000000;,
  0.000000;0.342020;0.939693;,
  1.000000;0.000000;0.000000;,
  0.000000;0.342020;-0.939693;,
  1.000000;0.000000;0.000000;,
  0.000000;0.500000;0.866026;,
  1.000000;0.000000;0.000000;,
  0.000000;0.500000;-0.866025;,
  1.000000;0.000000;0.000000;,
  0.000000;0.642787;0.766045;,
  1.000000;0.000000;0.000000;,
  0.000000;0.642788;-0.766044;,
  1.000000;0.000000;0.000000;,
  0.000000;0.766044;0.642788;,
  1.000000;0.000000;0.000000;,
  0.000000;0.766045;-0.642787;,
  1.000000;0.000000;0.000000;,
  0.000000;0.866025;0.500000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.866026;-0.500000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.939692;0.342021;,
  1.000000;0.000000;0.000000;,
  0.000000;0.939693;-0.342020;,
  1.000000;0.000000;0.000000;,
  0.000000;0.984808;0.173649;,
  1.000000;0.000000;0.000000;,
  0.000000;0.984808;-0.173648;,
  1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  1.000000;0.000000;0.000000;;
  144;
  3;37,6,10;,
  3;37,10,14;,
  3;37,14,16;,
  3;37,16,20;,
  3;37,20,24;,
  3;37,24,28;,
  3;37,28,32;,
  3;37,32,36;,
  3;37,36,41;,
  3;37,41,45;,
  3;37,45,49;,
  3;37,49,53;,
  3;37,53,57;,
  3;37,57,61;,
  3;37,61,65;,
  3;37,65,69;,
  3;37,69,73;,
  3;37,73,71;,
  3;37,71,67;,
  3;37,67,63;,
  3;37,63,59;,
  3;37,59,55;,
  3;37,55,51;,
  3;37,51,47;,
  3;37,47,43;,
  3;37,43,39;,
  3;37,39,34;,
  3;37,34,30;,
  3;37,30,26;,
  3;37,26,22;,
  3;37,22,18;,
  3;37,18,12;,
  3;37,12,8;,
  3;37,8,3;,
  3;37,3,1;,
  3;37,1,6;,
  3;111,84,80;,
  3;111,88,84;,
  3;111,90,88;,
  3;111,94,90;,
  3;111,98,94;,
  3;111,102,98;,
  3;111,106,102;,
  3;111,110,106;,
  3;111,115,110;,
  3;111,119,115;,
  3;111,123,119;,
  3;111,127,123;,
  3;111,131,127;,
  3;111,135,131;,
  3;111,139,135;,
  3;111,143,139;,
  3;111,147,143;,
  3;111,145,147;,
  3;111,141,145;,
  3;111,137,141;,
  3;111,133,137;,
  3;111,129,133;,
  3;111,125,129;,
  3;111,121,125;,
  3;111,117,121;,
  3;111,113,117;,
  3;111,108,113;,
  3;111,104,108;,
  3;111,100,104;,
  3;111,96,100;,
  3;111,92,96;,
  3;111,86,92;,
  3;111,82,86;,
  3;111,77,82;,
  3;111,75,77;,
  3;111,80,75;,
  3;83,9,5;,
  3;79,83,5;,
  3;87,13,9;,
  3;83,87,9;,
  3;89,15,13;,
  3;87,89,13;,
  3;93,19,15;,
  3;89,93,15;,
  3;97,23,19;,
  3;93,97,19;,
  3;101,27,23;,
  3;97,101,23;,
  3;105,31,27;,
  3;101,105,27;,
  3;109,35,31;,
  3;105,109,31;,
  3;114,40,35;,
  3;109,114,35;,
  3;118,44,40;,
  3;114,118,40;,
  3;122,48,44;,
  3;118,122,44;,
  3;126,52,48;,
  3;122,126,48;,
  3;130,56,52;,
  3;126,130,52;,
  3;134,60,56;,
  3;130,134,56;,
  3;138,64,60;,
  3;134,138,60;,
  3;142,68,64;,
  3;138,142,64;,
  3;146,72,68;,
  3;142,146,68;,
  3;144,70,72;,
  3;146,144,72;,
  3;140,66,70;,
  3;144,140,70;,
  3;136,62,66;,
  3;140,136,66;,
  3;132,58,62;,
  3;136,132,62;,
  3;128,54,58;,
  3;132,128,58;,
  3;124,50,54;,
  3;128,124,54;,
  3;120,46,50;,
  3;124,120,50;,
  3;116,42,46;,
  3;120,116,46;,
  3;112,38,42;,
  3;116,112,42;,
  3;107,33,38;,
  3;112,107,38;,
  3;103,29,33;,
  3;107,103,33;,
  3;99,25,29;,
  3;103,99,29;,
  3;95,21,25;,
  3;99,95,25;,
  3;91,17,21;,
  3;95,91,21;,
  3;85,11,17;,
  3;91,85,17;,
  3;81,7,11;,
  3;85,81,11;,
  3;76,2,7;,
  3;81,76,7;,
  3;74,0,2;,
  3;76,74,2;,
  3;78,4,0;,
  3;74,78,0;;
 }

 MeshTextureCoords {
  148;
  2.916668;1.000000;,
  0.500000;2.000000;,
  2.833334;1.000000;,
  0.586824;1.992404;,
  3.000001;1.000000;,
  0.000000;1.000000;,
  0.413176;1.992403;,
  2.750001;1.000000;,
  0.671010;1.969846;,
  0.083333;1.000000;,
  0.328990;1.969846;,
  2.666667;1.000000;,
  0.750000;1.933012;,
  0.166667;1.000000;,
  0.250000;1.933012;,
  0.250000;1.000000;,
  0.178606;1.883022;,
  2.583334;1.000000;,
  0.821394;1.883022;,
  0.333333;1.000000;,
  0.116978;1.821393;,
  2.500001;1.000000;,
  0.883022;1.821394;,
  0.416667;1.000000;,
  0.066988;1.750000;,
  2.416667;1.000000;,
  0.933012;1.750000;,
  0.500000;1.000000;,
  0.030154;1.671010;,
  2.333334;1.000000;,
  0.969846;1.671010;,
  0.583333;1.000000;,
  0.007596;1.586824;,
  2.250001;1.000000;,
  0.992404;1.586824;,
  0.666667;1.000000;,
  0.000000;1.500000;,
  0.500000;1.500000;,
  2.166667;1.000000;,
  1.000000;1.500000;,
  0.750000;1.000000;,
  0.007596;1.413176;,
  2.083334;1.000000;,
  0.992404;1.413176;,
  0.833333;1.000000;,
  0.030154;1.328990;,
  2.000000;1.000000;,
  0.969846;1.328990;,
  0.916667;1.000000;,
  0.066987;1.250000;,
  1.916667;1.000000;,
  0.933012;1.250000;,
  1.000000;1.000000;,
  0.116978;1.178606;,
  1.833334;1.000000;,
  0.883022;1.178606;,
  1.083333;1.000000;,
  0.178606;1.116978;,
  1.750000;1.000000;,
  0.821394;1.116978;,
  1.166667;1.000000;,
  0.250000;1.066987;,
  1.666667;1.000000;,
  0.750000;1.066987;,
  1.250000;1.000000;,
  0.328990;1.030154;,
  1.583334;1.000000;,
  0.671010;1.030154;,
  1.333334;1.000000;,
  0.413176;1.007596;,
  1.500000;1.000000;,
  0.586824;1.007596;,
  1.416667;1.000000;,
  0.500000;1.000000;,
  2.916668;0.000000;,
  0.500000;0.000000;,
  2.833334;0.000000;,
  0.413176;-0.007597;,
  3.000001;0.000000;,
  0.000000;0.000000;,
  0.586824;-0.007596;,
  2.750001;0.000000;,
  0.328990;-0.030154;,
  0.083333;0.000000;,
  0.671010;-0.030154;,
  2.666667;0.000000;,
  0.250000;-0.066988;,
  0.166667;0.000000;,
  0.750000;-0.066988;,
  0.250000;0.000000;,
  0.821394;-0.116978;,
  2.583334;0.000000;,
  0.178607;-0.116978;,
  0.333333;0.000000;,
  0.883022;-0.178607;,
  2.500001;0.000000;,
  0.116978;-0.178607;,
  0.416667;0.000000;,
  0.933013;-0.250000;,
  2.416667;0.000000;,
  0.066988;-0.250000;,
  0.500000;0.000000;,
  0.969846;-0.328990;,
  2.333334;0.000000;,
  0.030154;-0.328990;,
  0.583333;0.000000;,
  0.992404;-0.413176;,
  2.250001;0.000000;,
  0.007596;-0.413176;,
  0.666667;0.000000;,
  1.000000;-0.500000;,
  0.500000;-0.500000;,
  2.166667;0.000000;,
  0.000000;-0.500000;,
  0.750000;0.000000;,
  0.992404;-0.586824;,
  2.083334;0.000000;,
  0.007596;-0.586824;,
  0.833333;0.000000;,
  0.969846;-0.671010;,
  2.000000;0.000000;,
  0.030154;-0.671010;,
  0.916667;0.000000;,
  0.933013;-0.750000;,
  1.916667;0.000000;,
  0.066988;-0.750000;,
  1.000000;0.000000;,
  0.883022;-0.821394;,
  1.833334;0.000000;,
  0.116978;-0.821393;,
  1.083333;0.000000;,
  0.821394;-0.883022;,
  1.750000;0.000000;,
  0.178606;-0.883022;,
  1.166667;0.000000;,
  0.750000;-0.933013;,
  1.666667;0.000000;,
  0.250000;-0.933012;,
  1.250000;0.000000;,
  0.671010;-0.969846;,
  1.583334;0.000000;,
  0.328990;-0.969846;,
  1.333334;0.000000;,
  0.586824;-0.992404;,
  1.500000;0.000000;,
  0.413176;-0.992404;,
  1.416667;0.000000;,
  0.500000;-1.000000;;
 }

 MeshMaterialList {
  3;
  144;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;

  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;

   TextureFilename {
    "SawSide.jpg";
   }
  }

  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;

   TextureFilename {
    "SawSide.jpg";
   }
  }

  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;

   TextureFilename {
    "TwoPenceEdge.jpg";
   }
  }
 }

 VertexDuplicationIndices {
  148;
  74;
  1,
  1,
  3,
  3,
  6,
  6,
  6,
  8,
  8,
  10,
  10,
  12,
  12,
  14,
  14,
  16,
  16,
  18,
  18,
  20,
  20,
  22,
  22,
  24,
  24,
  26,
  26,
  28,
  28,
  30,
  30,
  32,
  32,
  34,
  34,
  36,
  36,
  37,
  39,
  39,
  41,
  41,
  43,
  43,
  45,
  45,
  47,
  47,
  49,
  49,
  51,
  51,
  53,
  53,
  55,
  55,
  57,
  57,
  59,
  59,
  61,
  61,
  63,
  63,
  65,
  65,
  67,
  67,
  69,
  69,
  71,
  71,
  73,
  73,
  75,
  75,
  77,
  77,
  80,
  80,
  80,
  82,
  82,
  84,
  84,
  86,
  86,
  88,
  88,
  90,
  90,
  92,
  92,
  94,
  94,
  96,
  96,
  98,
  98,
  100,
  100,
  102,
  102,
  104,
  104,
  106,
  106,
  108,
  108,
  110,
  110,
  111,
  113,
  113,
  115,
  115,
  117,
  117,
  119,
  119,
  121,
  121,
  123,
  123,
  125,
  125,
  127,
  127,
  129,
  129,
  131,
  131,
  133,
  133,
  135,
  135,
  137,
  137,
  139,
  139,
  141,
  141,
  143,
  143,
  145,
  145,
  147,
  147;
 }
}