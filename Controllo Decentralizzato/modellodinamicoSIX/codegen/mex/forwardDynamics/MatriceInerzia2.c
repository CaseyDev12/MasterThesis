/*
 * MatriceInerzia2.c
 *
 * Code generation for function 'MatriceInerzia2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forwardDynamics.h"
#include "MatriceInerzia2.h"
#include "mpower.h"

/* Function Definitions */
void MatriceInerzia2(const real_T qDH[8], real_T B1[64])
{
  real_T d0;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T d7;
  real_T d8;
  real_T d9;
  real_T d10;
  real_T d11;
  real_T d12;
  real_T d13;
  real_T d14;
  real_T d15;
  real_T d16;
  real_T d17;
  real_T d18;
  real_T d19;
  real_T d20;
  real_T d21;
  real_T d22;
  real_T d23;
  real_T d24;
  real_T d25;
  real_T d26;
  real_T d27;
  real_T d28;
  real_T d29;
  real_T d30;
  real_T d31;
  real_T d32;
  real_T d33;
  real_T d34;
  real_T d35;
  real_T d36;
  real_T d37;
  real_T d38;
  real_T d39;
  real_T d40;
  real_T d41;
  real_T d42;
  real_T d43;
  real_T d44;
  real_T d45;
  real_T d46;
  real_T d47;
  real_T d48;
  real_T d49;
  real_T d50;
  real_T d51;
  real_T d52;
  real_T d53;
  real_T d54;
  real_T d55;
  real_T d56;
  real_T d57;
  real_T d58;
  real_T d59;
  real_T d60;
  real_T d61;
  real_T d62;
  real_T d63;
  real_T d64;
  real_T d65;
  real_T d66;
  real_T d67;
  real_T d68;
  real_T d69;
  real_T d70;
  real_T d71;
  real_T d72;
  real_T d73;
  real_T d74;
  real_T d75;
  real_T d76;
  real_T d77;
  real_T d78;
  real_T d79;
  real_T d80;
  real_T d81;
  real_T d82;
  real_T d83;
  real_T d84;
  real_T d85;
  real_T d86;
  real_T d87;
  real_T d88;
  real_T d89;
  real_T d90;
  real_T d91;
  real_T d92;
  real_T d93;
  real_T d94;
  real_T d95;
  real_T d96;
  real_T d97;
  real_T d98;
  real_T d99;
  real_T d100;
  real_T d101;
  real_T d102;
  real_T d103;
  real_T d104;
  real_T d105;
  real_T d106;
  real_T d107;
  real_T d108;
  real_T d109;
  real_T d110;
  real_T d111;
  real_T d112;
  real_T d113;
  real_T d114;
  real_T d115;
  real_T d116;
  real_T d117;
  real_T d118;
  real_T d119;
  real_T d120;
  real_T d121;
  real_T d122;
  real_T d123;
  real_T d124;
  real_T d125;
  real_T d126;
  real_T d127;
  real_T d128;
  real_T d129;
  real_T d130;
  real_T d131;
  real_T d132;
  real_T d133;
  real_T d134;
  real_T d135;
  real_T d136;
  real_T d137;
  real_T d138;
  real_T d139;
  real_T d140;
  real_T d141;
  real_T d142;
  real_T d143;
  real_T d144;
  real_T d145;
  real_T d146;
  real_T d147;
  real_T d148;
  real_T d149;
  real_T d150;
  real_T d151;
  real_T d152;
  real_T d153;
  real_T d154;
  real_T d155;
  real_T d156;
  real_T d157;
  real_T d158;
  real_T d159;
  real_T d160;
  real_T d161;
  real_T d162;
  real_T d163;
  real_T d164;
  real_T d165;
  real_T d166;
  real_T d167;
  real_T d168;
  real_T d169;
  real_T d170;
  real_T d171;
  real_T d172;
  real_T d173;
  real_T d174;
  real_T d175;
  real_T d176;
  real_T d177;
  real_T d178;
  real_T d179;
  real_T d180;
  real_T d181;
  real_T d182;
  real_T d183;
  real_T d184;
  real_T d185;
  real_T d186;
  real_T d187;
  real_T d188;
  real_T d189;
  real_T d190;
  real_T d191;
  real_T d192;
  real_T d193;
  real_T d194;
  real_T d195;
  real_T d196;
  real_T d197;
  real_T d198;
  real_T d199;
  real_T d200;
  real_T d201;
  real_T d202;
  real_T d203;
  real_T d204;
  real_T d205;
  real_T d206;
  real_T d207;
  real_T d208;
  real_T d209;
  real_T d210;
  real_T d211;
  real_T d212;
  real_T d213;
  real_T d214;
  real_T d215;
  real_T d216;
  real_T d217;
  real_T d218;
  real_T d219;
  real_T d220;
  real_T d221;
  real_T d222;
  real_T d223;
  real_T d224;
  real_T d225;
  real_T d226;
  real_T d227;
  real_T d228;
  real_T d229;
  real_T b[36];
  real_T a[36];
  int32_T i2;
  int32_T i3;
  int32_T i4;
  static const int8_T b_a[36] = { -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, -1,
    0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, -1 };

  memset(&B1[0], 0, sizeof(real_T) << 6);

  /* costanti */
  mpower();
  d0 = b_mpower(muDoubleScalarSin(qDH[3]));
  d1 = b_mpower(muDoubleScalarSin(qDH[3]));
  d2 = b_mpower(muDoubleScalarSin(qDH[3]));
  d3 = b_mpower(muDoubleScalarSin(qDH[3]));
  d4 = b_mpower(muDoubleScalarSin(qDH[3]));
  d5 = b_mpower(muDoubleScalarCos(qDH[2] + qDH[1]));
  d6 = b_mpower(muDoubleScalarSin(qDH[1]));
  d7 = b_mpower(muDoubleScalarSin(qDH[2] + qDH[1]));
  d8 = b_mpower(muDoubleScalarSin(qDH[3]));
  d9 = b_mpower(muDoubleScalarSin(qDH[3]));
  d10 = b_mpower(muDoubleScalarSin(qDH[4]));
  d11 = b_mpower(muDoubleScalarSin(qDH[3]));
  d12 = b_mpower(muDoubleScalarSin(qDH[4]));
  d13 = b_mpower(muDoubleScalarSin(qDH[4]));
  d14 = b_mpower(muDoubleScalarSin(qDH[4]));
  d15 = b_mpower(muDoubleScalarSin(qDH[3]));
  d16 = b_mpower(muDoubleScalarSin(qDH[3]));
  d17 = b_mpower(muDoubleScalarSin(qDH[3]));
  d18 = b_mpower(muDoubleScalarSin(qDH[4]));
  d19 = b_mpower(muDoubleScalarSin(qDH[4]));
  d20 = b_mpower(muDoubleScalarCos(qDH[4]));
  d21 = b_mpower(muDoubleScalarCos(qDH[3]));
  d22 = b_mpower(muDoubleScalarSin(qDH[3]));
  d23 = b_mpower(muDoubleScalarCos(qDH[3]));
  d24 = b_mpower(muDoubleScalarSin(qDH[3]));
  d25 = b_mpower(muDoubleScalarSin(qDH[3]));
  d26 = b_mpower(muDoubleScalarSin(qDH[4]));
  d27 = b_mpower(muDoubleScalarCos(qDH[3]));
  d28 = b_mpower(muDoubleScalarSin(qDH[3]));
  d29 = b_mpower(muDoubleScalarCos(qDH[3]));
  d30 = b_mpower(muDoubleScalarSin(qDH[3]));
  d31 = b_mpower(muDoubleScalarSin(qDH[2]));
  d32 = b_mpower(muDoubleScalarSin(qDH[3]));
  d33 = b_mpower(muDoubleScalarSin(qDH[4]));
  d34 = b_mpower(muDoubleScalarSin(qDH[4]));
  d35 = b_mpower(muDoubleScalarSin(qDH[4]));
  d36 = b_mpower(muDoubleScalarSin(qDH[2]));
  d37 = b_mpower(muDoubleScalarCos(qDH[4]));
  d38 = b_mpower(muDoubleScalarCos(qDH[4]));
  d39 = b_mpower(muDoubleScalarCos(qDH[3]));
  d40 = b_mpower(muDoubleScalarSin(qDH[3]));
  d41 = b_mpower(muDoubleScalarSin(qDH[3]));
  d42 = b_mpower(muDoubleScalarSin(qDH[4]));
  d43 = b_mpower(muDoubleScalarCos(qDH[3]));
  d44 = b_mpower(muDoubleScalarSin(qDH[3]));
  d45 = b_mpower(muDoubleScalarSin(qDH[4]));
  d46 = b_mpower(muDoubleScalarCos(qDH[4]));
  d47 = b_mpower(muDoubleScalarSin(qDH[3]));
  d48 = b_mpower(muDoubleScalarSin(qDH[4]));
  d49 = b_mpower(muDoubleScalarSin(qDH[4]));
  d50 = b_mpower(muDoubleScalarCos(qDH[4]));
  d51 = b_mpower(muDoubleScalarCos(qDH[3]));
  d52 = b_mpower(muDoubleScalarSin(qDH[3]));
  d53 = b_mpower(muDoubleScalarCos(qDH[3]));
  d54 = b_mpower(muDoubleScalarSin(qDH[3]));
  d55 = b_mpower(muDoubleScalarSin(qDH[3]));
  d56 = b_mpower(muDoubleScalarSin(qDH[4]));
  d57 = b_mpower(muDoubleScalarCos(qDH[3]));
  d58 = b_mpower(muDoubleScalarSin(qDH[3]));
  d59 = b_mpower(muDoubleScalarCos(qDH[3]));
  d60 = b_mpower(muDoubleScalarSin(qDH[3]));
  d61 = b_mpower(muDoubleScalarSin(qDH[3]));
  d62 = b_mpower(muDoubleScalarSin(qDH[4]));
  d63 = b_mpower(muDoubleScalarSin(qDH[4]));
  d64 = b_mpower(muDoubleScalarSin(qDH[4]));
  d65 = b_mpower(muDoubleScalarCos(qDH[4]));
  d66 = b_mpower(muDoubleScalarCos(qDH[4]));
  d67 = b_mpower(muDoubleScalarCos(qDH[3]));
  d68 = b_mpower(muDoubleScalarSin(qDH[3]));
  d69 = b_mpower(muDoubleScalarSin(qDH[3]));
  d70 = b_mpower(muDoubleScalarSin(qDH[4]));
  d71 = b_mpower(muDoubleScalarCos(qDH[3]));
  d72 = b_mpower(muDoubleScalarSin(qDH[3]));
  d73 = b_mpower(muDoubleScalarSin(qDH[4]));
  d74 = b_mpower(muDoubleScalarCos(qDH[4]));
  d75 = b_mpower(muDoubleScalarCos(qDH[4]));
  d76 = b_mpower(muDoubleScalarSin(qDH[4]));
  d77 = b_mpower(muDoubleScalarCos(qDH[4]));
  d78 = b_mpower(muDoubleScalarSin(qDH[4]));
  d79 = b_mpower(muDoubleScalarCos(qDH[4]));
  d80 = b_mpower(muDoubleScalarSin(qDH[4]));
  d81 = b_mpower(muDoubleScalarCos(qDH[4]));
  d82 = b_mpower(muDoubleScalarSin(qDH[4]));
  d83 = b_mpower(muDoubleScalarCos(qDH[4]));
  d84 = b_mpower(muDoubleScalarSin(qDH[4]));
  d85 = b_mpower(muDoubleScalarCos(qDH[5]));
  d86 = b_mpower(muDoubleScalarCos(qDH[5]));
  d87 = b_mpower(muDoubleScalarSin(qDH[4]));
  d88 = b_mpower(muDoubleScalarCos(qDH[4]));
  d89 = b_mpower(muDoubleScalarSin(qDH[4]));
  d90 = b_mpower(muDoubleScalarCos(qDH[4]));
  d91 = b_mpower(muDoubleScalarSin(qDH[4]));
  d92 = b_mpower(muDoubleScalarCos(qDH[4]));
  d93 = b_mpower(muDoubleScalarSin(qDH[4]));
  d94 = b_mpower(muDoubleScalarCos(qDH[4]));
  d95 = b_mpower(muDoubleScalarSin(qDH[4]));
  d96 = b_mpower(muDoubleScalarCos(qDH[4]));
  d97 = b_mpower(muDoubleScalarSin(qDH[4]));
  d98 = b_mpower(muDoubleScalarCos(qDH[4]));
  d99 = b_mpower(muDoubleScalarSin(qDH[4]));
  d100 = b_mpower(muDoubleScalarCos(qDH[4]));
  d101 = b_mpower(muDoubleScalarSin(qDH[4]));
  d102 = b_mpower(muDoubleScalarCos(qDH[4]));
  d103 = b_mpower(muDoubleScalarSin(qDH[4]));
  d104 = b_mpower(muDoubleScalarCos(qDH[4]));
  d105 = b_mpower(muDoubleScalarCos(qDH[4]));
  d106 = b_mpower(muDoubleScalarSin(qDH[4]));
  d107 = b_mpower(muDoubleScalarCos(qDH[4]));
  d108 = b_mpower(muDoubleScalarSin(qDH[4]));
  d109 = b_mpower(muDoubleScalarCos(qDH[5]));
  d110 = b_mpower(muDoubleScalarCos(qDH[5]));
  d111 = b_mpower(muDoubleScalarSin(qDH[4]));
  d112 = b_mpower(muDoubleScalarSin(qDH[4]));
  d113 = b_mpower(muDoubleScalarCos(qDH[4]));
  d114 = b_mpower(muDoubleScalarSin(qDH[4]));
  d115 = b_mpower(muDoubleScalarCos(qDH[4]));
  d116 = b_mpower(muDoubleScalarSin(qDH[4]));
  d117 = b_mpower(muDoubleScalarCos(qDH[4]));
  d118 = b_mpower(muDoubleScalarSin(qDH[4]));
  d119 = b_mpower(muDoubleScalarCos(qDH[4]));
  d120 = b_mpower(muDoubleScalarSin(qDH[4]));
  d121 = b_mpower(muDoubleScalarSin(qDH[5]));
  d122 = b_mpower(muDoubleScalarSin(qDH[5]));
  d123 = b_mpower(muDoubleScalarSin(qDH[3]));
  d124 = b_mpower(muDoubleScalarCos(qDH[3]));
  d125 = b_mpower(muDoubleScalarSin(qDH[3]));
  d126 = b_mpower(muDoubleScalarSin(qDH[3]));
  d127 = b_mpower(muDoubleScalarSin(qDH[4]));
  d128 = b_mpower(muDoubleScalarSin(qDH[4]));
  d129 = b_mpower(muDoubleScalarSin(qDH[3]));
  d130 = b_mpower(muDoubleScalarCos(qDH[3]));
  d131 = b_mpower(muDoubleScalarCos(qDH[3]));
  d132 = b_mpower(muDoubleScalarSin(qDH[3]));
  d133 = b_mpower(muDoubleScalarCos(qDH[4]));
  d134 = b_mpower(muDoubleScalarSin(qDH[3]));
  d135 = b_mpower(muDoubleScalarSin(qDH[4]));
  d136 = b_mpower(muDoubleScalarSin(qDH[3]));
  d137 = b_mpower(muDoubleScalarCos(qDH[3]));
  d138 = b_mpower(muDoubleScalarSin(qDH[3]));
  d139 = b_mpower(muDoubleScalarSin(qDH[3]));
  d140 = b_mpower(muDoubleScalarSin(qDH[4]));
  d141 = b_mpower(muDoubleScalarSin(qDH[4]));
  d142 = b_mpower(muDoubleScalarSin(qDH[3]));
  d143 = b_mpower(muDoubleScalarSin(qDH[3]));
  d144 = b_mpower(muDoubleScalarSin(qDH[4]));
  d145 = b_mpower(muDoubleScalarSin(qDH[4]));
  d146 = b_mpower(muDoubleScalarSin(qDH[3]));
  d147 = b_mpower(muDoubleScalarCos(qDH[3]));
  d148 = b_mpower(muDoubleScalarSin(qDH[3]));
  d149 = b_mpower(muDoubleScalarSin(qDH[3]));
  d150 = b_mpower(muDoubleScalarCos(qDH[3]));
  d151 = b_mpower(muDoubleScalarSin(qDH[3]));
  d152 = b_mpower(muDoubleScalarCos(qDH[4]));
  d153 = b_mpower(muDoubleScalarSin(qDH[3]));
  d154 = b_mpower(muDoubleScalarSin(qDH[4]));
  d155 = b_mpower(muDoubleScalarSin(qDH[3]));
  d156 = b_mpower(muDoubleScalarCos(qDH[3]));
  d157 = b_mpower(muDoubleScalarSin(qDH[3]));
  d158 = b_mpower(muDoubleScalarSin(qDH[3]));
  d159 = b_mpower(muDoubleScalarSin(qDH[4]));
  d160 = b_mpower(muDoubleScalarSin(qDH[4]));
  d161 = b_mpower(muDoubleScalarSin(qDH[3]));
  d162 = b_mpower(muDoubleScalarSin(qDH[3]));
  d163 = b_mpower(muDoubleScalarCos(qDH[5]));
  d164 = b_mpower(muDoubleScalarCos(qDH[4]));
  d165 = b_mpower(muDoubleScalarSin(qDH[4]));
  d166 = b_mpower(muDoubleScalarCos(qDH[4]));
  d167 = b_mpower(muDoubleScalarSin(qDH[4]));
  d168 = b_mpower(muDoubleScalarCos(qDH[4]));
  d169 = b_mpower(muDoubleScalarSin(qDH[4]));
  d170 = b_mpower(muDoubleScalarCos(qDH[4]));
  d171 = b_mpower(muDoubleScalarSin(qDH[4]));
  d172 = b_mpower(muDoubleScalarCos(qDH[4]));
  d173 = b_mpower(muDoubleScalarSin(qDH[4]));
  d174 = b_mpower(muDoubleScalarCos(qDH[4]));
  d175 = b_mpower(muDoubleScalarSin(qDH[4]));
  d176 = b_mpower(muDoubleScalarCos(qDH[4]));
  d177 = b_mpower(muDoubleScalarSin(qDH[4]));
  d178 = b_mpower(muDoubleScalarSin(qDH[5]));
  d179 = b_mpower(muDoubleScalarSin(qDH[3]));
  d180 = b_mpower(muDoubleScalarCos(qDH[3]));
  d181 = b_mpower(muDoubleScalarSin(qDH[3]));
  d182 = b_mpower(muDoubleScalarSin(qDH[3]));
  d183 = b_mpower(muDoubleScalarSin(qDH[4]));
  d184 = b_mpower(muDoubleScalarSin(qDH[4]));
  d185 = b_mpower(muDoubleScalarSin(qDH[3]));
  d186 = b_mpower(muDoubleScalarCos(qDH[3]));
  d187 = b_mpower(muDoubleScalarCos(qDH[4]));
  d188 = b_mpower(muDoubleScalarSin(qDH[3]));
  d189 = b_mpower(muDoubleScalarSin(qDH[4]));
  d190 = b_mpower(muDoubleScalarSin(qDH[3]));
  d191 = b_mpower(muDoubleScalarSin(qDH[3]));
  d192 = b_mpower(muDoubleScalarSin(qDH[4]));
  d193 = b_mpower(muDoubleScalarSin(qDH[4]));
  d194 = b_mpower(muDoubleScalarSin(qDH[3]));
  d195 = b_mpower(muDoubleScalarCos(qDH[3]));
  d196 = b_mpower(muDoubleScalarSin(qDH[3]));
  d197 = b_mpower(muDoubleScalarSin(qDH[3]));
  d198 = b_mpower(muDoubleScalarCos(qDH[4]));
  d199 = b_mpower(muDoubleScalarSin(qDH[3]));
  d200 = b_mpower(muDoubleScalarSin(qDH[4]));
  d201 = b_mpower(muDoubleScalarSin(qDH[3]));
  d202 = b_mpower(muDoubleScalarSin(qDH[3]));
  d203 = b_mpower(muDoubleScalarCos(qDH[4]));
  d204 = b_mpower(muDoubleScalarSin(qDH[4]));
  d205 = b_mpower(muDoubleScalarCos(qDH[5]));
  d206 = b_mpower(muDoubleScalarCos(qDH[4]));
  d207 = b_mpower(muDoubleScalarSin(qDH[4]));
  d208 = b_mpower(muDoubleScalarCos(qDH[4]));
  d209 = b_mpower(muDoubleScalarSin(qDH[4]));
  d210 = b_mpower(muDoubleScalarCos(qDH[4]));
  d211 = b_mpower(muDoubleScalarSin(qDH[4]));
  d212 = b_mpower(muDoubleScalarCos(qDH[4]));
  d213 = b_mpower(muDoubleScalarSin(qDH[4]));
  d214 = b_mpower(muDoubleScalarSin(qDH[5]));
  d215 = b_mpower(muDoubleScalarSin(qDH[4]));
  d216 = b_mpower(muDoubleScalarSin(qDH[4]));
  d217 = b_mpower(muDoubleScalarSin(qDH[4]));
  d218 = b_mpower(muDoubleScalarSin(qDH[4]));
  d219 = b_mpower(muDoubleScalarSin(qDH[4]));
  d220 = b_mpower(muDoubleScalarCos(qDH[4]));
  d221 = b_mpower(muDoubleScalarSin(qDH[4]));
  d222 = b_mpower(muDoubleScalarSin(qDH[4]));
  d223 = b_mpower(muDoubleScalarSin(qDH[4]));
  d224 = b_mpower(muDoubleScalarCos(qDH[4]));
  d225 = b_mpower(muDoubleScalarSin(qDH[4]));
  d226 = b_mpower(muDoubleScalarCos(qDH[4]));
  d227 = b_mpower(muDoubleScalarCos(qDH[5]));
  d228 = b_mpower(muDoubleScalarSin(qDH[4]));
  d229 = b_mpower(muDoubleScalarSin(qDH[5]));
  b[0] =
    ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((0.62520097831335
    * muDoubleScalarCos(qDH[2] + qDH[1]) - 0.63963276511845 * muDoubleScalarSin
    (qDH[2] + qDH[1])) + 0.073290875804699993 * muDoubleScalarSin(qDH[1])) +
    9.0101748223806 * muDoubleScalarCos(qDH[1])) + 0.005561 * d0 *
    muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarCos(qDH[2]) *
    muDoubleScalarSin(qDH[1])) + 0.005561 * d1 * muDoubleScalarSin(qDH[2] + qDH
    [1]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) - 1.0E-6 * (((
    -muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) -
    (-muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4])) * muDoubleScalarCos(qDH[3])
    - muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarSin(qDH[2]) + (-(muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) + (-muDoubleScalarSin(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) + 2.45912384803251 *
    muDoubleScalarCos(qDH[1]) * muDoubleScalarCos(qDH[2] + qDH[1])) -
    2.51588887613257 * muDoubleScalarCos(qDH[1]) * muDoubleScalarSin(qDH[2] +
    qDH[1])) + 6.0E-6 * ((-muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) +
    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1]))
    + 0.145732 * muDoubleScalarCos(qDH[1]) * muDoubleScalarSin(qDH[1])) -
    0.000714 * (((muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) -
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarSin(qDH[4])) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[2]) - ((muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4]) +
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarCos(qDH[4])) * muDoubleScalarSin(qDH[2])) *
    muDoubleScalarSin(qDH[1])) - 0.01087191266925 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - 0.01473863665669068 *
    (-muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2] + qDH[1]) *
    muDoubleScalarCos(qDH[2]) + muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1]))
    + 0.072479417795 * ((muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) -
    0.13 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[2]) - 0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[1])) -
    0.01473863665669068 * (-muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]
    + qDH[1]) * muDoubleScalarSin(qDH[2]) - muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarCos(qDH[2])) *
    muDoubleScalarCos(qDH[1])) + 0.00792073504365 * muDoubleScalarCos(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) - 0.052804900291 * (((((-muDoubleScalarCos(qDH[3]) * ((-0.15 -
    0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1]))
    - 0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[4]) - 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) - 0.64707 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[3]) + (-muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) - 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) -
    (((-muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1]))
    - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) - 0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4]) +
    0.13 * d2 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2] + qDH[1]))
    - 0.13 * muDoubleScalarCos(qDH[3]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) -
    5.999999999999929E-6 * ((muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH
    [5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + (-muDoubleScalarCos
    (qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin
    (qDH[2]) + muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) - 0.052804900291 *
    (((((((-muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1]))
    - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) - 0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) -
    0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) - 0.64707 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[3]) +
    (-muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) -
    0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarSin(qDH[2]) + (((-muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) -
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[4]) + 0.13 * d3 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) - 0.13 * muDoubleScalarCos(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) * muDoubleScalarCos(qDH[2])) + 0.59 * d4 * muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[2] + qDH[1])) - 0.59 * muDoubleScalarCos(qDH[3]) * (
    -muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) * muDoubleScalarCos(qDH[1])) - 0.002706 * ((-muDoubleScalarCos
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2]) - (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.002706 *
    ((-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) + 31.29460847701786)
    + 0.090513 * d5) - 16.7938007456 * d6) + 2.002822066414367 * d7) - 0.011786 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin
    (qDH[1])) - 0.011786 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) *
    muDoubleScalarCos(qDH[1])) - 5.999999999999929E-6 * ((muDoubleScalarCos(qDH
    [5]) * (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) +
    (-muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) -
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[2]) - muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos
    (qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin
    (qDH[1])) - 0.0012902994670500002 * muDoubleScalarCos(qDH[3]) *
    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) + 0.0086019964470000019 * (((((((-muDoubleScalarCos(qDH[3]) *
    ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2]
    + qDH[1])) - 0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1])) * muDoubleScalarSin(qDH[4]) - 0.64707 * muDoubleScalarSin(qDH[4])
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[3]) + (-muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) - 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[4])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) +
    (((muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) +
    0.13 * d8 * muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[4]))
    - 0.13 * muDoubleScalarCos(qDH[3]) * (-muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) *
    muDoubleScalarCos(qDH[2])) + 0.59 * d9 * muDoubleScalarSin(qDH[2] + qDH[1]) *
    muDoubleScalarSin(qDH[4])) - 0.59 * muDoubleScalarCos(qDH[3]) *
    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) * muDoubleScalarCos(qDH[1])) + 1.2299108999999998E-6 *
    muDoubleScalarSin(qDH[3]) * (muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[5]) - muDoubleScalarSin(qDH[4]) * (muDoubleScalarCos
    (qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])))) +
    8.199406E-6 * ((((-muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin(qDH[3]) *
    ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2]
    + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1])) * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) -
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) - muDoubleScalarSin(qDH[5]) *
    (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) * muDoubleScalarSin(qDH[4]))
    - 0.64707 * muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) *
    muDoubleScalarCos(qDH[3]) + ((muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) - 0.64707 *
    muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5])) + 0.64707 *
    muDoubleScalarSin(qDH[4]) * (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]))) * muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2])
    - (((-d10 * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[5]) + (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) -
    muDoubleScalarSin(qDH[5]) * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarCos(qDH[4])) + 0.13 * muDoubleScalarSin(qDH[3]) *
    (muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5]) -
    muDoubleScalarSin(qDH[4]) * (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1])))) + 0.13 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[5]) * (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1]))) * muDoubleScalarSin(qDH[2])) *
    muDoubleScalarSin(qDH[1])) - 0.000118 * (-(muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2]) - (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.000118 *
    (-(muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) - 4.168006522089 * (
    -0.15 - 0.59 * muDoubleScalarCos(qDH[1])) * muDoubleScalarCos(qDH[2] + qDH[1]))
    - 4.264218434123 * (0.15 + 0.59 * muDoubleScalarCos(qDH[1])) *
    muDoubleScalarSin(qDH[2] + qDH[1])) - 1.10150196622066 * muDoubleScalarCos
    (qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[2] + qDH[1])) +
    0.0086019964470000019 * (((((-muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) -
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[4]) - 0.64707 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[3]) + (-muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) - 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[4])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) -
    (((muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) +
    0.13 * d11 * muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[4]))
    - 0.13 * muDoubleScalarCos(qDH[3]) * (-muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 4.0E-6 *
    ((muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) * muDoubleScalarCos(qDH[3]) + (muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) + muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) -
    0.037598417344349995 * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]
    + qDH[1])) + 0.250656115629 * ((muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[2]) - 0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[1])) - 0.000725 *
                       (-muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2] +
    qDH[1]) * muDoubleScalarCos(qDH[2]) + muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[2])) *
                       muDoubleScalarSin(qDH[1])) - 0.000725 *
                      (-muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2] +
    qDH[1]) * muDoubleScalarSin(qDH[2]) - muDoubleScalarCos(qDH[3]) *
                       muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarCos
                       (qDH[2])) * muDoubleScalarCos(qDH[1])) - 1.0E-6 *
                     (((-muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[5]) - (-muDoubleScalarSin(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4])) *
                       muDoubleScalarCos(qDH[3]) - muDoubleScalarCos(qDH[5]) *
                       (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[3])) *
                      muDoubleScalarCos(qDH[2]) - (-(muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) + (-muDoubleScalarSin
    (qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[4])) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin
                     (qDH[1])) - 1.2118239750000002E-5 * muDoubleScalarSin(qDH[3])
                    * (-muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                       muDoubleScalarSin(qDH[5]) - muDoubleScalarSin(qDH[4]) *
                       (muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) -
                        muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
                        muDoubleScalarSin(qDH[2] + qDH[1])))) -
                   8.0788265000000011E-5 * ((((((-muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) +
    muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarCos(qDH[5]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) * muDoubleScalarCos(qDH[3]) + ((-muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5]) +
    0.64707 * muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) + (((-d12 *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) +
    (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) + muDoubleScalarCos(qDH[5]) *
    (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) * muDoubleScalarCos(qDH[4]))
    + 0.13 * muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH[4]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarSin(qDH[5]) - muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])))) + 0.13 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) *
    muDoubleScalarCos(qDH[2])) + 0.59 * muDoubleScalarSin(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) -
     muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) - muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])))) + 0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1]))) * muDoubleScalarCos(qDH[1])) -
                  8.0788265000000011E-5 * ((((-muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) +
    muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarCos(qDH[5]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) * muDoubleScalarCos(qDH[3]) + ((-muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5])
    + 0.64707 * muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarCos(qDH[5]) *
     muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) - (((-d13 *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5])
    + (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
       (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1]))
    - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) + muDoubleScalarCos(qDH[5]) *
       (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1]))
    - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) * muDoubleScalarCos(qDH[4]))
    + 0.13 * muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH[4]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarSin(qDH[5]) - muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarCos(qDH[5]) *
     muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])))) + 0.13 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) + 7.0E-6 *
                 (((muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                    muDoubleScalarCos(qDH[4]) - muDoubleScalarSin(qDH[4]) *
                    (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
                     muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
                     muDoubleScalarSin(qDH[2] + qDH[1]))) * muDoubleScalarCos
                   (qDH[3]) + muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                   muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) -
                  (muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                   muDoubleScalarSin(qDH[4]) + (muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4])) *
                  muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) +
                8.199406E-6 * ((((((-muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) -
    muDoubleScalarSin(qDH[5]) * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[5]) *
    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) * muDoubleScalarCos(qDH[3]) + ((muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5])
    - 0.64707 * muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
     muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) + (((-d14 *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5])
    + (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
       (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1]))
    - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) - muDoubleScalarSin(qDH[5]) *
       (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1]))
    - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) * muDoubleScalarCos(qDH[4]))
    + 0.13 * muDoubleScalarSin(qDH[3]) * (muDoubleScalarCos(qDH[4]) *
    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarCos(qDH[5]) - muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
     muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])))) + 0.13 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) *
    muDoubleScalarCos(qDH[2])) + 0.59 * muDoubleScalarSin(qDH[3]) *
    (muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5]) -
     muDoubleScalarSin(qDH[4]) * (muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])))) + 0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1]))) * muDoubleScalarCos(qDH[1])) - 4.0E-6 *
               ((muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
                 muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarCos(qDH[3])
                 + (muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                    muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarSin(qDH[4])
                    * muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin
                 (qDH[3])) * muDoubleScalarCos(qDH[2]) - muDoubleScalarSin(qDH[3])
                * muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[4])
                * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) -
              0.01136949999999993 * muDoubleScalarCos(qDH[3]) *
              muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin((qDH[1] -
    qDH[3]) + qDH[2])) - 0.072479417795 * (muDoubleScalarSin(qDH[3]) * ((-0.15 -
    0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1]))
              - 0.13 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) -
            1.2118239750000002E-5 * muDoubleScalarCos(qDH[3]) *
            muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) *
             muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
             muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) -
           0.250656115629 * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
              muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] +
              qDH[1])) - 0.13 * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
            (qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin
           (qDH[1])) + 1.2299108999999998E-6 * muDoubleScalarCos(qDH[3]) *
          muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin(qDH[4]) *
           muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
           muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) +
         6.0E-6 * ((-muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH
            [1]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) +
                    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                     muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH
             [4]) * muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH
            [3])) * muDoubleScalarCos(qDH[2]) - muDoubleScalarCos(qDH[4]) *
                   muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])
                   * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) +
        0.0012902994670500002 * d15 * muDoubleScalarSin(qDH[2] + qDH[1]) *
        muDoubleScalarSin(qDH[4])) - 0.00792073504365 * d16 * muDoubleScalarCos
       (qDH[4]) * muDoubleScalarSin(qDH[2] + qDH[1])) - 0.01136949999999993 *
      muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) *
      muDoubleScalarSin((qDH[1] + qDH[3]) + qDH[2])) + 7.0E-6 *
     (((muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) *
         muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
         muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
        muDoubleScalarCos(qDH[4]) - muDoubleScalarSin(qDH[4]) *
        (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
          muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
          muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
         muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
         muDoubleScalarSin(qDH[2] + qDH[1]))) * muDoubleScalarCos(qDH[3]) +
       muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin(qDH[4]) *
        muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
        muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
       muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) +
      (muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) *
        muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
        muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
       muDoubleScalarSin(qDH[4]) + (muDoubleScalarCos(qDH[5]) *
        (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
         muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
         muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
        muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
       muDoubleScalarCos(qDH[4])) * muDoubleScalarCos(qDH[2])) *
     muDoubleScalarCos(qDH[1])) - 0.000714 * (((muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4])) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) + ((muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[4]) + (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1]);
  b[6] = ((((((((((((((((((((((((((((((((((((((((((((-0.002462 *
    muDoubleScalarCos(qDH[2] + qDH[1]) - 0.008851 * muDoubleScalarSin(qDH[2] +
    qDH[1])) - 0.75791928520612 * muDoubleScalarSin(qDH[1])) + 0.047671 *
    muDoubleScalarCos(qDH[1])) - 1.2299108999999998E-6 * muDoubleScalarCos(qDH[3])
    * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) - 1.2118239750000002E-5 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) - 0.005561 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[3])
    * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) - 0.005561 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarCos(qDH[1])) + 7.0E-6 * (((muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5]) - muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarCos(qDH[3]) -
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * d17) *
    muDoubleScalarCos(qDH[2]) - (d18 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[5]) + (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.000714 * (2.0 * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) + (d19 *
    muDoubleScalarSin(qDH[3]) - d20 * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) + 6.0E-6 * ((d21 *
    muDoubleScalarSin(qDH[4]) - muDoubleScalarSin(qDH[4]) * d22) *
    muDoubleScalarCos(qDH[2]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) + 6.0E-6 *
    ((d23 * muDoubleScalarSin(qDH[4]) - muDoubleScalarSin(qDH[4]) * d24) *
    muDoubleScalarSin(qDH[2]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) +
    0.0086019964470000019 * ((((0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarSin(qDH[4]) - 0.64707 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[3]) +
    ((-muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) + (-0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) + 1.2299108999999998E-6 *
    muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) -
    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])))) + 8.199406E-6 * (((((-muDoubleScalarSin(qDH[4])
    * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos
    (qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) -
    0.64707 * muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) - muDoubleScalarSin(qDH[5]) * (-0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3]))) * muDoubleScalarSin(qDH[4])) + 0.64707 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarCos(qDH[3]) + (((muDoubleScalarSin(qDH[4]) * (0.59
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) - muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarSin(qDH[5]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) -
    ((((-muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) + (-muDoubleScalarCos
    (qDH[5]) * (muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) -
    muDoubleScalarSin(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3]))) *
    muDoubleScalarCos(qDH[4])) + 0.13 * muDoubleScalarSin(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5]) - muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])))) - 0.13 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2])) *
    muDoubleScalarSin(qDH[1])) - 1.2118239750000002E-5 * muDoubleScalarSin(qDH[3])
    * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[4]) * (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[3])))) - 8.0788265000000011E-5 * (((((((-muDoubleScalarSin(qDH[4]) *
    (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarSin(qDH[5]) * (muDoubleScalarCos
    (qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) -
    0.64707 * muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) + muDoubleScalarCos(qDH[5]) * (-0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3]))) * muDoubleScalarSin(qDH[4])) - 0.64707 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) * muDoubleScalarCos(qDH[3]) + (((-muDoubleScalarSin(qDH[4]) *
    (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarCos(qDH[5]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) +
    ((((-muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) + (-muDoubleScalarSin
    (qDH[5]) * (muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) +
    muDoubleScalarCos(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3]))) *
    muDoubleScalarCos(qDH[4])) + 0.13 * muDoubleScalarSin(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])))) + 0.13 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5])) * muDoubleScalarCos(qDH[2])) + 0.59 *
    muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) -
    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[3])))) + 0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) * muDoubleScalarCos(qDH[1])) - 8.0788265000000011E-5 *
    (((((-muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) - (-muDoubleScalarSin
    (qDH[5]) * (muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) +
    muDoubleScalarCos(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3]))) *
    muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5])) * muDoubleScalarCos
    (qDH[3]) + (((-muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3])
    * muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) *
    muDoubleScalarCos(qDH[5]) + 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) + 0.64707 * muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[2]) - ((((-muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) + (-muDoubleScalarSin(qDH[5]) * (muDoubleScalarCos
    (qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) -
    0.64707 * muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) + muDoubleScalarCos(qDH[5]) * (-0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3]))) * muDoubleScalarCos(qDH[4])) + 0.13 *
    muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) -
    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[3])))) + 0.13 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) + 7.0E-6
    * (((muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) - muDoubleScalarSin
    (qDH[4]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[3]))) * muDoubleScalarCos(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) * d25) * muDoubleScalarSin(qDH[2]) + (d26 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) + (-muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) -
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos
    (qDH[4])) * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) +
    8.199406E-6 * (((((((-muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3]))
    + muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos
    (qDH[5]) * (muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) -
    muDoubleScalarSin(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3]))) *
    muDoubleScalarSin(qDH[4])) + 0.64707 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarCos
    (qDH[3]) + (((muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) -
    muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) *
    muDoubleScalarSin(qDH[5]) + 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarSin(qDH[2]) + ((((-muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[4]) + (-muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos
    (qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) -
    0.64707 * muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) - muDoubleScalarSin(qDH[5]) * (-0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3]))) * muDoubleScalarCos(qDH[4])) + 0.13 *
    muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) -
    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])))) - 0.13 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarCos(qDH[2])) + 0.59 * muDoubleScalarSin(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5]) - muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])))) - 0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[1])) - 4.0E-6 *
    ((-muDoubleScalarCos(qDH[4]) * d27 + muDoubleScalarCos(qDH[4]) * d28) *
    muDoubleScalarCos(qDH[2]) + muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 4.0E-6 *
    ((-muDoubleScalarCos(qDH[4]) * d29 + muDoubleScalarCos(qDH[4]) * d30) *
    muDoubleScalarSin(qDH[2]) - muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) +
    0.250656115629 * ((0.59 * muDoubleScalarCos(qDH[2]) + 0.13) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) + 0.59 *
    muDoubleScalarSin(qDH[3]) * d31) * muDoubleScalarSin(qDH[1])) +
    0.250656115629 * ((0.59 * muDoubleScalarCos(qDH[2]) + 0.13) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) - 1.0E-6 * (((-muDoubleScalarCos(qDH
    [4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) - (muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4])) * muDoubleScalarCos
    (qDH[3]) - muDoubleScalarSin(qDH[4]) * d32 * muDoubleScalarCos(qDH[5])) *
    muDoubleScalarCos(qDH[2]) - (-muDoubleScalarSin(qDH[5]) * d33 *
    muDoubleScalarSin(qDH[3]) + (muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.000118 * (-d34 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin
    (qDH[1])) - 0.000118 * (-d35 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2]) + muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) + 0.0086019964470000019 * ((((0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[4]) - 0.64707 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarCos
    (qDH[3]) + ((-muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) - (-0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.01136949999999993 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin((qDH[1] - qDH[3]) + qDH[2])) +
    0.072479417795 * ((-0.59 * muDoubleScalarCos(qDH[2]) - 0.13) *
                      muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) -
                      0.59 * muDoubleScalarCos(qDH[3]) * d36) *
    muDoubleScalarSin(qDH[1])) + 0.072479417795 * ((-0.59 * muDoubleScalarCos
    (qDH[2]) - 0.13) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) +
    0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) -
                       0.01136949999999993 * muDoubleScalarSin(qDH[3]) *
                       muDoubleScalarSin((qDH[1] + qDH[3]) + qDH[2])) -
                      0.052804900291 * ((((0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[4]) - 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[3]) +
    ((-muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) -
      muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) +
     0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) - (0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) - 5.999999999999929E-6 *
                     ((muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4]) *
                       muDoubleScalarCos(qDH[3]) + (muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[5]) *
                       muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) +
                      muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4]) *
                      muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) -
                    0.052804900291 * ((((0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[4]) - 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[3]) +
    ((-muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) -
      muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) +
     0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) + (0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) - 0.002706 * (-d37 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2]) + muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin
                   (qDH[1])) - 0.002706 * (-d38 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) -
                 5.999999999999929E-6 * ((muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
     (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + (muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) -
    muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.01473863665669068 *
                muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) *
                muDoubleScalarCos(qDH[1])) + 0.005893 * (d39 - d40) *
               muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) +
              0.01473863665669068 * muDoubleScalarCos(qDH[3]) *
              muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) - 1.0E-6 *
             (((-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
                muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) -
                (muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                 muDoubleScalarSin(qDH[3]) - muDoubleScalarCos(qDH[5]) *
                 muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4])) *
               muDoubleScalarCos(qDH[3]) - muDoubleScalarSin(qDH[4]) * d41 *
               muDoubleScalarCos(qDH[5])) * muDoubleScalarSin(qDH[2]) +
              (-muDoubleScalarSin(qDH[5]) * d42 * muDoubleScalarSin(qDH[3]) +
               (muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                muDoubleScalarSin(qDH[3]) - muDoubleScalarCos(qDH[5]) *
                muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) *
              muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) + 0.005893
            * (d43 - d44) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1]))
           - 0.000725 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) *
           muDoubleScalarSin(qDH[1])) - 0.000714 * (2.0 * muDoubleScalarSin(qDH
            [4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4]) *
           muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) - (d45 *
            muDoubleScalarSin(qDH[3]) - d46 * muDoubleScalarSin(qDH[3])) *
           muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) + 0.000725 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarCos
    (qDH[1]);
  b[12] = ((((((((((((((((((((((((((((((((((((((((((-0.002462 *
    muDoubleScalarCos(qDH[2] + qDH[1]) - 0.008851 * muDoubleScalarSin(qDH[2] +
    qDH[1])) - 1.2299108999999998E-6 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) - 1.2118239750000002E-5 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) - 0.005561 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[3])
    * muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) - 0.005561 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarCos(qDH[1])) + 7.0E-6 * (((muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5]) - muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarCos(qDH[3]) -
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * d47) *
    muDoubleScalarCos(qDH[2]) - (d48 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[5]) + (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.000714 * (2.0 * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) + (d49 *
    muDoubleScalarSin(qDH[3]) - d50 * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) + 6.0E-6 * ((d51 *
    muDoubleScalarSin(qDH[4]) - muDoubleScalarSin(qDH[4]) * d52) *
    muDoubleScalarCos(qDH[2]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) + 6.0E-6 *
    ((d53 * muDoubleScalarSin(qDH[4]) - muDoubleScalarSin(qDH[4]) * d54) *
    muDoubleScalarSin(qDH[2]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) +
    1.2299108999999998E-6 * muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH
    [4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[5]) - muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) -
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])))) -
    1.2118239750000002E-5 * muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH
    [4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) +
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])))) + 7.0E-6 *
    (((muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5]) - muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
    muDoubleScalarCos(qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * d55) * muDoubleScalarSin(qDH[2]) + (d56 * muDoubleScalarSin(qDH[3])
    * muDoubleScalarCos(qDH[5]) + (-muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) - 4.0E-6 *
    ((-muDoubleScalarCos(qDH[4]) * d57 + muDoubleScalarCos(qDH[4]) * d58) *
    muDoubleScalarCos(qDH[2]) + muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 4.0E-6 *
    ((-muDoubleScalarCos(qDH[4]) * d59 + muDoubleScalarCos(qDH[4]) * d60) *
    muDoubleScalarSin(qDH[2]) - muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) - 1.0E-6 *
    (((-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) - (muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) -
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin
    (qDH[4])) * muDoubleScalarCos(qDH[3]) - muDoubleScalarSin(qDH[4]) * d61 *
    muDoubleScalarCos(qDH[5])) * muDoubleScalarCos(qDH[2]) - (-muDoubleScalarSin
    (qDH[5]) * d62 * muDoubleScalarSin(qDH[3]) + (muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.000118 * (-d63 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin
    (qDH[1])) - 0.000118 * (-d64 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2]) + muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) - 0.01136949999999993 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin((qDH[1] - qDH[3]) + qDH[2])) -
    0.01136949999999993 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin((qDH[1]
    + qDH[3]) + qDH[2])) - 5.999999999999929E-6 * ((muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + (muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) +
    muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) - 0.002706 * (-d65 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2]) + muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin
    (qDH[1])) - 0.002706 * (-d66 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) - 5.999999999999929E-6 *
    ((muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) + (muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarCos(qDH[2]) - muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin
    (qDH[1])) + 8.199406E-6 * (((((0.64707 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos
    (qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
    + 0.13 * muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[4])) + 0.64707 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarCos(qDH[3]) + (((-0.64707 * muDoubleScalarCos(qDH
    [3]) * muDoubleScalarSin(qDH[4]) - 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarSin(qDH[5]) + 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[2]) - ((((0.64707 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) + (-muDoubleScalarCos
    (qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
    + 0.13 * muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[4])) + 0.13 *
    muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) -
    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])))) - 0.13 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) -
    8.0788265000000011E-5 * (((((((0.64707 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) - (-muDoubleScalarSin
    (qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
    + 0.13 * muDoubleScalarSin(qDH[4])) + 0.64707 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[4])) - 0.64707 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) * muDoubleScalarCos(qDH[3]) + (((0.64707 * muDoubleScalarCos(qDH[3])
    * muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[5]) + 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) + 0.64707 * muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarSin(qDH[2]) + ((((0.64707 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) + (-muDoubleScalarSin
    (qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
    + 0.13 * muDoubleScalarSin(qDH[4])) + 0.64707 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[4])) + 0.13 *
    muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) -
    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[3])))) + 0.13 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) * muDoubleScalarCos(qDH[2])) + 0.59 * muDoubleScalarSin(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])))) + 0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5])) * muDoubleScalarCos(qDH[1])) +
    0.0086019964470000019 * ((-1.29414 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) + (1.29414 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) + 0.13 *
    muDoubleScalarCos(qDH[4])) * muDoubleScalarSin(qDH[3])) * muDoubleScalarCos
    (qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.052804900291 *
    ((-1.29414 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
      muDoubleScalarCos(qDH[3]) + (1.29414 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) - 0.13 * muDoubleScalarSin(qDH[4])) *
      muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) - 0.64707 *
     muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
     (qDH[2])) * muDoubleScalarCos(qDH[1])) - 0.052804900291 * ((-1.29414 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[3]) + (1.29414 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
                - 0.13 * muDoubleScalarSin(qDH[4])) * muDoubleScalarSin(qDH[3]))
    * muDoubleScalarCos(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin
    (qDH[1])) + 8.199406E-6 * (((((((0.64707 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos
    (qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
    + 0.13 * muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[4])) + 0.64707 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarCos(qDH[3]) + (((-0.64707 * muDoubleScalarCos(qDH
    [3]) * muDoubleScalarSin(qDH[4]) - 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarSin(qDH[5]) + 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarSin(qDH[2]) + ((((0.64707 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) + (-muDoubleScalarCos
    (qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
    + 0.13 * muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[4])) + 0.13 *
    muDoubleScalarSin(qDH[3]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) -
    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])))) - 0.13 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarCos(qDH[2])) + 0.59 * muDoubleScalarSin(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarCos(qDH[5]) - muDoubleScalarSin(qDH[4]) *
     (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
      (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])))) - 0.59
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[1])) -
                       8.0788265000000011E-5 * (((((0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) - (-muDoubleScalarSin
    (qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
                + 0.13 * muDoubleScalarSin(qDH[4])) + 0.64707 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin
    (qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[5])) * muDoubleScalarCos(qDH[3]) + (((0.64707 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) + 0.13 *
    muDoubleScalarCos(qDH[4])) * muDoubleScalarCos(qDH[5]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
     (qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) - ((((0.64707 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) + 0.13 *
    muDoubleScalarCos(qDH[4])) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) + (-muDoubleScalarSin(qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4])
    * muDoubleScalarCos(qDH[3]) + 0.13 * muDoubleScalarSin(qDH[4])) + 0.64707 *
                muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[4])) + 0.13 * muDoubleScalarSin(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
     (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[4]) *
     (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
      (qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])))) + 0.13
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5])) * muDoubleScalarSin(qDH[2])) *
                       muDoubleScalarSin(qDH[1])) + 0.03258529503177 *
                      muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) *
                      muDoubleScalarCos(qDH[1])) - 0.00942232431335 *
                     muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) *
                     muDoubleScalarCos(qDH[1])) + 0.03258529503177 *
                    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) *
                    muDoubleScalarSin(qDH[1])) - 0.01473863665669068 *
                   muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) *
                   muDoubleScalarCos(qDH[1])) + 0.005893 * (d67 - d68) *
                  muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) +
                 0.01473863665669068 * muDoubleScalarCos(qDH[3]) *
                 muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) - 1.0E-6
                * (((-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
                     muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) -
                     (muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                      muDoubleScalarSin(qDH[3]) - muDoubleScalarCos(qDH[5]) *
                      muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4])) *
                    muDoubleScalarCos(qDH[3]) - muDoubleScalarSin(qDH[4]) * d69 *
                    muDoubleScalarCos(qDH[5])) * muDoubleScalarSin(qDH[2]) +
                   (-muDoubleScalarSin(qDH[5]) * d70 * muDoubleScalarSin(qDH[3])
                    + (muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                       muDoubleScalarSin(qDH[3]) - muDoubleScalarCos(qDH[5]) *
                       muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) *
                   muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) +
               0.005893 * (d71 - d72) * muDoubleScalarSin(qDH[2]) *
               muDoubleScalarCos(qDH[1])) - 0.000725 * muDoubleScalarSin(qDH[3])
              * muDoubleScalarSin(qDH[2]) * muDoubleScalarSin(qDH[1])) -
             0.00942232431335 * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
             (qDH[2]) * muDoubleScalarSin(qDH[1])) - 0.000714 * (2.0 *
             muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
             muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
             muDoubleScalarCos(qDH[2]) - (d73 * muDoubleScalarSin(qDH[3]) - d74 *
              muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2])) *
            muDoubleScalarSin(qDH[1])) + 0.0086019964470000019 * ((-1.29414 *
             muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[3]) *
             muDoubleScalarSin(qDH[4]) + (1.29414 * muDoubleScalarCos(qDH[3]) *
              muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
             muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) + 0.64707 *
            muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
            muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) + 0.000725 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) * muDoubleScalarCos
    (qDH[1]);
  b[18] = (((((((((((((((((((((((((((((((((((((((0.037598417344349995 *
    muDoubleScalarCos(qDH[3]) - 0.090513 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.01087191266925 * muDoubleScalarSin(qDH[3])) - 6.0E-6 * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) *
    muDoubleScalarSin(qDH[1])) + 4.0E-6 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos
    (qDH[1])) + 4.0E-6 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) - 6.0E-6 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2]) * muDoubleScalarCos(qDH[1])) + 0.00792073504365 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[4])) + 0.0012902994670500002 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) - 0.000714 * ((d75 -
    d76) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) + 2.0 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) + 1.2299108999999998E-6 *
    muDoubleScalarSin(qDH[3]) * (-d77 * muDoubleScalarCos(qDH[5]) - d78 *
    muDoubleScalarCos(qDH[5]))) + 8.199406E-6 * ((((0.64707 * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]) + (0.64707 *
    d79 * muDoubleScalarCos(qDH[5]) + 0.64707 * d80 * muDoubleScalarCos(qDH[5]))
    * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) + (0.13 *
    muDoubleScalarSin(qDH[3]) * (-d81 * muDoubleScalarCos(qDH[5]) - d82 *
    muDoubleScalarCos(qDH[5])) - 0.13 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos
    (qDH[2])) + 0.59 * muDoubleScalarSin(qDH[3]) * (-d83 * muDoubleScalarCos
    (qDH[5]) - d84 * muDoubleScalarCos(qDH[5]))) - 0.59 * muDoubleScalarCos(qDH
    [4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarCos(qDH[1])) - 5.999999999999929E-6 * ((d85 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) - muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin
    (qDH[2]) + d86 * d87 * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1]))
    - 0.000714 * ((d88 - d89) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2]) - 2.0 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) + 8.199406E-6 *
    ((0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3]) + (0.64707 * d90 * muDoubleScalarCos(qDH[5]) +
    0.64707 * d91 * muDoubleScalarCos(qDH[5])) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[2]) - (0.13 * muDoubleScalarSin(qDH[3]) * (-d92 *
    muDoubleScalarCos(qDH[5]) - d93 * muDoubleScalarCos(qDH[5])) - 0.13 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[3])) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) -
    0.000118 * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) - d94 *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.002706 *
    (muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2]) + d95 * muDoubleScalarCos(qDH[2])) *
    muDoubleScalarCos(qDH[1])) - 1.2118239750000002E-5 * muDoubleScalarSin(qDH[3])
    * (-d96 * muDoubleScalarSin(qDH[5]) - d97 * muDoubleScalarSin(qDH[5]))) -
    8.0788265000000011E-5 * ((((-0.64707 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + (0.64707 * d98 *
    muDoubleScalarSin(qDH[5]) + 0.64707 * d99 * muDoubleScalarSin(qDH[5])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) + (0.13 *
    muDoubleScalarSin(qDH[3]) * (-d100 * muDoubleScalarSin(qDH[5]) - d101 *
    muDoubleScalarSin(qDH[5])) + 0.13 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos
    (qDH[2])) + 0.59 * muDoubleScalarSin(qDH[3]) * (-d102 * muDoubleScalarSin
    (qDH[5]) - d103 * muDoubleScalarSin(qDH[5]))) + 0.59 * muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarCos(qDH[1])) - 0.000118 * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2]) + d104 * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) -
    1.0E-6 * (((-d105 * muDoubleScalarSin(qDH[5]) + d106 * muDoubleScalarSin
    (qDH[5])) * muDoubleScalarCos(qDH[3]) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin
    (qDH[2]) - 2.0 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos
    (qDH[1])) + 0.0086019964470000019 * (-0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]) - 0.13 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) + 7.0E-6 * (((d107 *
    muDoubleScalarCos(qDH[5]) - d108 * muDoubleScalarCos(qDH[5])) *
    muDoubleScalarCos(qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) + 2.0 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) -
    0.052804900291 * ((0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
                       (qDH[4]) * muDoubleScalarSin(qDH[2]) - 0.13 *
                       muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) *
                       muDoubleScalarCos(qDH[2])) - 0.59 * muDoubleScalarCos
                      (qDH[3]) * muDoubleScalarSin(qDH[4])) * muDoubleScalarCos
    (qDH[1])) - 5.999999999999929E-6 * ((d109 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) - muDoubleScalarCos
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) - d110 * d111 *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.002706 *
    (muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
     (qDH[3]) * muDoubleScalarCos(qDH[2]) - d112 * muDoubleScalarSin(qDH[2])) *
    muDoubleScalarSin(qDH[1])) - 1.0E-6 * (((-d113 * muDoubleScalarSin(qDH[5]) +
    d114 * muDoubleScalarSin(qDH[5])) * muDoubleScalarCos(qDH[3]) -
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarCos(qDH[2]) + 2.0 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) + 0.0086019964470000019 * ((-0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2]) + 0.13 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[2])) + 0.59 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[1])) + 0.250656115629 *
                      (0.13 * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH
    [2]) + 0.59 * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[1])) +
                     7.0E-6 * (((d115 * muDoubleScalarCos(qDH[5]) - d116 *
    muDoubleScalarCos(qDH[5])) * muDoubleScalarCos(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[2]) - 2.0 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.052804900291 * (0.64707 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[2]) + 0.13 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) -
                   8.0788265000000011E-5 * ((-0.64707 * muDoubleScalarCos(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + (0.64707 * d117 *
    muDoubleScalarSin(qDH[5]) + 0.64707 * d118 * muDoubleScalarSin(qDH[5])) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) - (0.13 *
    muDoubleScalarSin(qDH[3]) * (-d119 * muDoubleScalarSin(qDH[5]) - d120 *
    muDoubleScalarSin(qDH[5])) + 0.13 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) - 1.2299108999999998E-6 *
                  muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
                  muDoubleScalarCos(qDH[3])) - 0.01473863665669068 *
                 muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) *
                 muDoubleScalarCos(qDH[1])) - 0.000725 * muDoubleScalarCos(qDH[3])
                * muDoubleScalarSin(qDH[2]) * muDoubleScalarCos(qDH[1])) -
               0.01473863665669068 * muDoubleScalarSin(qDH[3]) *
               muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) -
              1.2118239750000002E-5 * muDoubleScalarCos(qDH[5]) *
              muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) -
             0.03258529503177 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
             (qDH[2]) * muDoubleScalarSin(qDH[1])) - 0.00942232431335 *
            muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) *
            muDoubleScalarSin(qDH[1])) - 0.000725 * muDoubleScalarCos(qDH[3]) *
           muDoubleScalarCos(qDH[2]) * muDoubleScalarSin(qDH[1])) +
    0.072479417795 * (0.13 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2])
                      + 0.59 * muDoubleScalarSin(qDH[3])) * muDoubleScalarCos
    (qDH[1]);
  b[24] = ((((((((((((((((((((((-0.052804900291 * (0.64707 * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) + 0.13 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1]) - 8.0788265000000011E-5 * (0.64707 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[2]) + 0.13 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) + 6.0E-6 * (muDoubleScalarCos(qDH[3])
    * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2]) + muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) -
    0.005561 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) *
    muDoubleScalarCos(qDH[1])) + 8.199406E-6 * ((-0.64707 * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + 0.13 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[2])) + 0.59 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[1])) +
    1.2118239750000002E-5 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])
    * muDoubleScalarCos(qDH[5])) + 1.2299108999999998E-6 * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) -
    5.999999999999929E-6 * ((-muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH
    [5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + d121 *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) - muDoubleScalarCos
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) + 8.199406E-6 *
    (-0.64707 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
     muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) - 0.13 *
     muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) - 4.0E-6
                        * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
    * muDoubleScalarSin(qDH[2]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) - 0.0012902994670500002 *
                       muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) -
                      4.0E-6 * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarCos(qDH[2]) + muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) -
                     8.0788265000000011E-5 * ((0.64707 * muDoubleScalarSin(qDH[4])
    * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin
    (qDH[2]) - 0.13 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[2])) - 0.59 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) * muDoubleScalarCos(qDH[1])) - 1.0E-6 * (muDoubleScalarCos(qDH[5])
    * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2]) - muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) +
                   0.0086019964470000019 * (0.64707 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) + 0.13 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) + 7.0E-6 * (muDoubleScalarSin(qDH[5])
    * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) + 0.00792073504365 *
                 muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) -
                0.052804900291 * ((0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.13 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[2])) - 0.59 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) *
                muDoubleScalarCos(qDH[1])) - 5.999999999999929E-6 *
               ((-muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[5]) *
                 muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + d122 *
                 muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) +
                muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) *
                muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[2])) *
               muDoubleScalarSin(qDH[1])) + 6.0E-6 * (muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[2]) - muDoubleScalarCos
    (qDH[4]) * muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) -
             0.005561 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]) *
             muDoubleScalarSin(qDH[1])) - 1.0E-6 * (muDoubleScalarCos(qDH[5]) *
             muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
             muDoubleScalarCos(qDH[2]) + muDoubleScalarCos(qDH[5]) *
             muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2])) *
            muDoubleScalarSin(qDH[1])) + 0.0086019964470000019 * ((0.64707 *
             muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
             muDoubleScalarSin(qDH[2]) - 0.13 * muDoubleScalarSin(qDH[4]) *
             muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2])) - 0.59 *
            muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) *
           muDoubleScalarCos(qDH[1])) + 7.0E-6 * (muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1]);
  b[30] = ((((((((((((-8.0788265000000011E-5 * ((-0.64707 * muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3]) + 0.64707 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarCos
    (qDH[2]) - (-0.13 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                muDoubleScalarSin(qDH[3]) + 0.13 * muDoubleScalarCos(qDH[5]) *
                muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[2])) *
                      muDoubleScalarSin(qDH[1]) + 8.199406E-6 * ((((0.64707 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]) + 0.64707 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarSin(qDH[2]) + (-0.13 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - 0.13 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos
    (qDH[2])) - 0.59 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3])) - 0.59 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[1])) -
                     1.2299108999999998E-6 * muDoubleScalarSin(qDH[5]) *
                     muDoubleScalarCos(qDH[3])) + 1.2118239750000002E-5 *
                    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                    muDoubleScalarSin(qDH[3])) - 1.2299108999999998E-6 *
                   muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                   muDoubleScalarSin(qDH[3])) + 8.199406E-6 * ((0.64707 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]) + 0.64707 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarCos(qDH[2]) - (-0.13 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - 0.13 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin
    (qDH[2])) * muDoubleScalarSin(qDH[1])) - 0.000118 * (-muDoubleScalarCos(qDH
    [3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin
                 (qDH[1])) - 1.2118239750000002E-5 * muDoubleScalarCos(qDH[5]) *
                muDoubleScalarCos(qDH[3])) - 8.0788265000000011E-5 *
               ((((-0.64707 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH
    [3]) + 0.64707 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                   muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) +
                  (-0.13 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4])
                   * muDoubleScalarSin(qDH[3]) + 0.13 * muDoubleScalarCos(qDH[5])
                   * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[2])) -
                 0.59 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                 muDoubleScalarSin(qDH[3])) + 0.59 * muDoubleScalarCos(qDH[5]) *
                muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[1])) -
              0.000118 * (-muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])
    * muDoubleScalarSin(qDH[2]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[2])) * muDoubleScalarCos(qDH[1])) - 1.0E-6 * ((-muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]) - muDoubleScalarCos
    (qDH[5]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) -
              muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
              muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) + 7.0E-6 *
            ((muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
              muDoubleScalarCos(qDH[3]) - muDoubleScalarSin(qDH[5]) *
              muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2]) +
             muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) *
             muDoubleScalarCos(qDH[2])) * muDoubleScalarCos(qDH[1])) - 1.0E-6 *
           ((-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
             muDoubleScalarCos(qDH[3]) - muDoubleScalarCos(qDH[5]) *
             muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[2]) +
            muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
            muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1])) + 7.0E-6 *
    ((muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
      (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3])) *
     muDoubleScalarCos(qDH[2]) - muDoubleScalarCos(qDH[5]) * muDoubleScalarSin
     (qDH[4]) * muDoubleScalarSin(qDH[2])) * muDoubleScalarSin(qDH[1]);
  b[1] = ((((((((((((((((((((((((((((((((((((((((((((((((-0.002462 *
    muDoubleScalarCos(qDH[2] + qDH[1]) - 0.008851 * muDoubleScalarSin(qDH[2] +
    qDH[1])) - 0.75791928520612 * muDoubleScalarSin(qDH[1])) + 0.047671 *
    muDoubleScalarCos(qDH[1])) + 0.0050751779037300016 * muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) *
    muDoubleScalarCos(qDH[2])) + 0.03115489117169 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2])) + 0.04276285649905 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[2])) -
    0.04276285649905 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] +
    qDH[1]) * muDoubleScalarCos(qDH[2])) - 1.06592278E-6 * (muDoubleScalarCos
    (qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[4])) - 5.999999999999929E-6 * muDoubleScalarCos(qDH[5])
    * (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]))
    + 0.000725 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2] + qDH[1]))
    - 0.00942232431335 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] +
    qDH[1])) + 0.03258529503177 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1])) - 6.0E-6 * muDoubleScalarCos(qDH[3]) *
    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) - 0.01473863665669068 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - 7.0E-6 * (-muDoubleScalarCos(qDH[5]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarCos(qDH[4]) + muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[3])) - 0.0050751779037300016 * muDoubleScalarSin(qDH[2])
    * (muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) + (-muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[3]))) + 4.0E-6 * (muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[3])) + 0.000714 * (-(muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[4]) + (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4])) *
    muDoubleScalarSin(qDH[3])) + 1.0E-6 * (muDoubleScalarCos(qDH[4]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarSin(qDH[5]) + (-muDoubleScalarSin(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4])) *
    muDoubleScalarSin(qDH[3])) - 0.005893 * d123 * muDoubleScalarSin(qDH[2] +
    qDH[1])) + 1.0502474450000003E-5 * muDoubleScalarCos(qDH[4]) *
    (muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) +
    8.0788265000000011E-5 * ((muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) + (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) +
    muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[4])) + 0.64707 * muDoubleScalarCos(qDH[5]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) * muDoubleScalarSin(qDH[3])) + 0.052804900291 *
    (-muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) -
    0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[3])) +
    4.7665076350000011E-5 * muDoubleScalarSin(qDH[2]) * (muDoubleScalarCos(qDH[3])
    * (-muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[5]) - muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin
    (qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) -
    muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[3]))) -
    8.199406E-6 * ((muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin(qDH[3]) *
    ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2]
    + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1])) * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) +
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) - muDoubleScalarSin(qDH[5]) *
    (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) * muDoubleScalarSin(qDH[4]))
    + 0.64707 * muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[3])) + 0.03115489117169 * muDoubleScalarSin(qDH[2]) *
    (muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) * muDoubleScalarCos(qDH[3]) + muDoubleScalarSin(qDH[3]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])))) - 0.0086019964470000019 * ((-(-muDoubleScalarCos(qDH[3]) *
    ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2]
    + qDH[1])) - 0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1])) * muDoubleScalarSin(qDH[4]) + 0.64707 * muDoubleScalarSin(qDH[4])
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) - 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[3])) + 8.0788265000000011E-5 * ((-muDoubleScalarSin
    (qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[5]) + 0.64707 * muDoubleScalarCos(qDH[4]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarSin(qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarCos(qDH[3])) + 4.7665076350000011E-5 * muDoubleScalarCos(qDH[2])
    * (-(muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) + muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin
    (qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])))) -
    4.83764954E-6 * muDoubleScalarSin(qDH[2]) * (muDoubleScalarCos(qDH[3]) *
    (muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5]) -
    muDoubleScalarSin(qDH[4]) * (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]))) - muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin(qDH[4])
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[3]))) - 4.83764954E-6 * muDoubleScalarCos(qDH[2]) *
    (muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5]) +
     (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]))) - 0.0086019964470000019 * (
    -muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) -
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) *
    muDoubleScalarSin(qDH[4])) * muDoubleScalarCos(qDH[3])) - 8.199406E-6 *
    ((muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
      muDoubleScalarSin(qDH[5]) - 0.64707 * muDoubleScalarCos(qDH[4]) *
      (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
       muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) *
       muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5])) +
     0.64707 * muDoubleScalarSin(qDH[4]) * (muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]))) * muDoubleScalarCos(qDH[3])) + 0.005893
                        * d124 * muDoubleScalarSin(qDH[2] + qDH[1])) +
                       0.14788710822110998 * muDoubleScalarSin(qDH[3]) *
                       muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarCos
                       (qDH[2])) + 0.000118 * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                      muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) +
                     0.0068646370378299994 * muDoubleScalarSin(qDH[3]) *
                     muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH
    [4])) - 1.06592278E-6 * muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH
    [4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                    muDoubleScalarCos(qDH[5])) - 0.14788710822110998 *
                   muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2] + qDH[1])
                   * muDoubleScalarSin(qDH[2])) - 1.0E-6 * muDoubleScalarCos
                  (qDH[3]) * muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH
    [4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) -
                 1.0502474450000003E-5 * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                 muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4])) +
                5.999999999999929E-6 * (-muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) - muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) *
                muDoubleScalarCos(qDH[3])) - 7.0E-6 * muDoubleScalarCos(qDH[3]) *
               muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) -
              0.02829999999999986 * muDoubleScalarSin(qDH[3]) *
              muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarCos(qDH[3])) -
             0.002706 * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
              muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
              muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) *
             muDoubleScalarSin(qDH[3])) - 6.0E-6 * d125 * muDoubleScalarSin(qDH
             [2] + qDH[1]) * muDoubleScalarSin(qDH[4])) + 0.0011182595381100003 *
           muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
           muDoubleScalarSin(qDH[2] + qDH[1])) - 4.0E-6 * d126 *
          muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2] + qDH[1])) +
    0.052804900291 * ((-(-muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) -
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
                       muDoubleScalarCos(qDH[4]) + 0.64707 * muDoubleScalarCos
                       (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
                       (qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
                      muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin
    (qDH[3]);
  b[7] = (((((((((((((((((((((((((((((((((((((((((((-0.03258529503177 *
    muDoubleScalarCos(qDH[3]) - 0.00942232431335 * muDoubleScalarSin(qDH[3])) +
    4.91824769606502 * muDoubleScalarCos(qDH[2])) - 5.03177775226514 *
    muDoubleScalarSin(qDH[2])) + 1.06592278E-6 * d127 * muDoubleScalarSin(qDH[3])
    * muDoubleScalarCos(qDH[5])) - 1.0502474450000003E-5 * muDoubleScalarSin
    (qDH[5]) * d128 * muDoubleScalarSin(qDH[3])) - 0.0050751779037300016 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2])) - 1.06592278E-6 * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) -
    0.02273899999999986 * d129) + 0.005561 * d130) - 0.03115489117169 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[2])) + 7.0E-6 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) - 1.0E-6 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5])) - 0.0068646370378299994 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) -
    0.0011182595381100003 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]))
    - 0.04276285649905 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2]))
    - 0.14788710822110998 * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos(qDH[2]))
    + 1.0502474450000003E-5 * muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) +
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3]))) + 0.052804900291 * (
    -(0.59 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[4]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin
    (qDH[3])) + 8.0788265000000011E-5 * ((-(-muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) + (-muDoubleScalarSin(qDH[5]) * (muDoubleScalarCos
    (qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) -
    0.64707 * muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) + muDoubleScalarCos(qDH[5]) * (-0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3]))) * muDoubleScalarSin(qDH[4])) + 0.64707 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) * muDoubleScalarSin(qDH[3])) + 0.052804900291 *
    ((-muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) -
    muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) +
    0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarCos(qDH[3])) + 0.03115489117169 * muDoubleScalarSin(qDH[2]) *
    (-muDoubleScalarCos(qDH[4]) * d131 - muDoubleScalarCos(qDH[4]) * d132)) -
    0.0086019964470000019 * (-(0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarSin(qDH[4]) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[3])) +
    8.0788265000000011E-5 * (((-muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarCos(qDH[5]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
    muDoubleScalarCos(qDH[3])) + 0.002706 * d133 * d134) + 4.7665076350000011E-5
    * muDoubleScalarCos(qDH[2]) * (-muDoubleScalarSin(qDH[5]) * d135 *
    muDoubleScalarSin(qDH[3]) + muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) +
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])))) - 4.83764954E-6 *
    muDoubleScalarSin(qDH[2]) * (muDoubleScalarCos(qDH[3]) * (-muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[5]) - muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) -
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]))) + muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * d136)) - 0.072479417795 * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13) * muDoubleScalarSin(qDH[3])) - 7.0E-6 *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarCos(qDH[5]) + muDoubleScalarSin(qDH[4]) *
     (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
      (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
    muDoubleScalarSin(qDH[3])) - 0.0050751779037300016 * muDoubleScalarSin(qDH[2])
                        * (-d137 * muDoubleScalarSin(qDH[4]) - muDoubleScalarSin
    (qDH[4]) * d138)) + 1.0E-6 * (muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) +
    (muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
     (qDH[3]) - muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarSin(qDH[4])) * muDoubleScalarSin(qDH[3])) +
                      4.7665076350000011E-5 * muDoubleScalarSin(qDH[2]) *
                      (muDoubleScalarCos(qDH[3]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) - muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) - muDoubleScalarSin(qDH[4]) * d139 *
                       muDoubleScalarCos(qDH[5]))) - 8.199406E-6 *
                     ((-(-muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3]))
    + muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) *
                       muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) + (
    -muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) - muDoubleScalarSin(qDH[5]) * (-0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3]))) * muDoubleScalarSin(qDH[4])) - 0.64707 *
                      muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
                      muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[3])) -
                    4.83764954E-6 * muDoubleScalarCos(qDH[2]) * (-d140 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) + (-muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) -
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos
    (qDH[4]))) - 0.0086019964470000019 * ((-muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) + 0.64707 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4])) * muDoubleScalarCos(qDH[3])) - 8.199406E-6 *
                  (((muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3])
    * muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) -
                     muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2])
    + 0.13)) * muDoubleScalarSin(qDH[5]) + 0.64707 * muDoubleScalarCos(qDH[4]) *
                    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
                    muDoubleScalarCos(qDH[5])) + 0.64707 * muDoubleScalarSin
                   (qDH[4]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3]))) * muDoubleScalarCos(qDH[3])) - 0.250656115629 *
                 (0.59 * muDoubleScalarCos(qDH[2]) + 0.13) * muDoubleScalarCos
                 (qDH[3])) + 0.011786 * muDoubleScalarCos(qDH[3]) *
                muDoubleScalarSin(qDH[3])) + 0.000118 * d141 * d142) -
              5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) *
              (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
               muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
               muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4]) *
              muDoubleScalarSin(qDH[3])) + 32.410934243414367) + 1.2E-5 *
            muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[3]) *
            muDoubleScalarSin(qDH[4])) + 8.0E-6 * muDoubleScalarCos(qDH[4]) *
           muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[3])) - 0.001428 *
          muDoubleScalarSin(qDH[4]) * d143 * muDoubleScalarCos(qDH[4])) +
    5.999999999999929E-6 * (muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[3]) + muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[3])) * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]);
  b[13] = (((((((((((((((((((((((((((((((((((((((((-0.06517059006354 *
    muDoubleScalarCos(qDH[3]) - 0.0188446486267 * muDoubleScalarSin(qDH[3])) +
    2.45912384803251 * muDoubleScalarCos(qDH[2])) - 2.51588887613257 *
    muDoubleScalarSin(qDH[2])) + 1.06592278E-6 * d144 * muDoubleScalarSin(qDH[3])
    * muDoubleScalarCos(qDH[5])) - 1.0502474450000003E-5 * muDoubleScalarSin
    (qDH[5]) * d145 * muDoubleScalarSin(qDH[3])) - 0.0050751779037300016 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarCos
    (qDH[2])) - 1.06592278E-6 * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) -
    0.02273899999999986 * d146) + 0.005561 * d147) - 0.011132187681920582 *
    muDoubleScalarSin(qDH[4]) * d148) - 0.03115489117169 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2])) +
    0.068336933662594732 * muDoubleScalarCos(qDH[4]) * d149) + 7.0E-6 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3])) - 1.0E-6 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) - 0.0068646370378299994 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4])) - 0.0011182595381100003 * muDoubleScalarCos(qDH[4])
    * muDoubleScalarCos(qDH[3])) - 0.04276285649905 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[2])) - 0.14788710822110998 * muDoubleScalarCos(qDH[3])
    * muDoubleScalarCos(qDH[2])) + 1.0502474450000003E-5 * muDoubleScalarCos
    (qDH[4]) * (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[3]))) + 0.03115489117169 * muDoubleScalarSin(qDH[2]) *
    (-muDoubleScalarCos(qDH[4]) * d150 - muDoubleScalarCos(qDH[4]) * d151)) +
    0.002706 * d152 * d153) + 4.7665076350000011E-5 * muDoubleScalarCos(qDH[2]) *
    (-muDoubleScalarSin(qDH[5]) * d154 * muDoubleScalarSin(qDH[3]) +
    muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[3])))) - 4.83764954E-6 * muDoubleScalarSin(qDH[2]) *
    (muDoubleScalarCos(qDH[3]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) -
    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3]))) + muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * d155)) - 7.0E-6 * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]) +
    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3]))) * muDoubleScalarSin(qDH[3])) -
    0.0050751779037300016 * muDoubleScalarSin(qDH[2]) * (-d156 *
    muDoubleScalarSin(qDH[4]) - muDoubleScalarSin(qDH[4]) * d157)) + 1.0E-6 *
    (muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
     (qDH[4]) * muDoubleScalarSin(qDH[3]) + (muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4])) *
    muDoubleScalarSin(qDH[3])) + 4.7665076350000011E-5 * muDoubleScalarSin(qDH[2])
    * (muDoubleScalarCos(qDH[3]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) - muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) - muDoubleScalarSin(qDH[4]) * d158 *
       muDoubleScalarCos(qDH[5]))) - 4.83764954E-6 * muDoubleScalarCos(qDH[2]) *
                        (-d159 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5]) + (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
                muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4]))) +
                       0.011786 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
                       (qDH[3])) + 0.000118 * d160 * d161) +
                     8.0788265000000011E-5 * ((-(0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) + (-muDoubleScalarSin
    (qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
                + 0.13 * muDoubleScalarSin(qDH[4])) + 0.64707 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin
    (qDH[4])) + 0.64707 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[5])) * muDoubleScalarSin(qDH[3])) + 0.052804900291 *
                    (1.29414 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
                     (qDH[3]) - 0.13 * muDoubleScalarSin(qDH[4])) *
                    muDoubleScalarCos(qDH[3])) + 8.0788265000000011E-5 *
                   (((0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
                      (qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
                     muDoubleScalarCos(qDH[5]) + 0.64707 * muDoubleScalarCos
                     (qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
                     (qDH[4]) * muDoubleScalarSin(qDH[3])) + 0.64707 *
                    muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarCos(qDH[3])) -
                  5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) *
                  (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                   muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
                   muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4]) *
                  muDoubleScalarSin(qDH[3])) + 3.1667594978143669) - 8.199406E-6
                * ((-(0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
                      (qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
                    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) +
                    (-muDoubleScalarCos(qDH[5]) * (-0.64707 * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarCos(qDH[3]) + 0.13 * muDoubleScalarSin(qDH[4])) -
                     0.64707 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
                     (qDH[3])) * muDoubleScalarSin(qDH[4])) - 0.64707 *
                   muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
                   muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[3])) -
               0.0086019964470000019 * (1.29414 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
               muDoubleScalarCos(qDH[3])) - 8.199406E-6 * (((-0.64707 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) - 0.13 *
    muDoubleScalarCos(qDH[4])) * muDoubleScalarSin(qDH[5]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
     (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
              muDoubleScalarCos(qDH[3])) + 1.2E-5 * muDoubleScalarSin(qDH[3]) *
             muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) + 8.0E-6 *
            muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
            muDoubleScalarCos(qDH[3])) - 0.001428 * muDoubleScalarSin(qDH[4]) *
           d162 * muDoubleScalarCos(qDH[4])) + 5.999999999999929E-6 *
    (muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
     (qDH[3]) + muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]);
  b[19] = ((((((((((((((((((((((0.01473863665669068 * muDoubleScalarCos(qDH[3])
    - 0.000725 * muDoubleScalarSin(qDH[3])) - 1.0E-6 * muDoubleScalarCos(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) + 7.0E-6 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[3])) + 0.0050751779037300016 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2])) - 0.04276285649905 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2])) + 0.03115489117169 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2])) - 5.999999999999929E-6 * d163 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) - 0.002588 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[4])) - 7.0E-6 * (-d164 * muDoubleScalarCos(qDH[5]) + d165 *
    muDoubleScalarCos(qDH[5])) * muDoubleScalarSin(qDH[3])) + 0.000714 * (-d166
    + d167) * muDoubleScalarSin(qDH[3])) + 1.0E-6 * (d168 * muDoubleScalarSin
    (qDH[5]) - d169 * muDoubleScalarSin(qDH[5])) * muDoubleScalarSin(qDH[3])) -
                     5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) *
                     muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[5]) *
                     muDoubleScalarCos(qDH[3])) + 8.0788265000000011E-5 *
                    (0.64707 * d170 * muDoubleScalarSin(qDH[5]) + 0.64707 * d171
                     * muDoubleScalarSin(qDH[5])) * muDoubleScalarCos(qDH[3])) -
                   4.83764954E-6 * muDoubleScalarSin(qDH[2]) *
                   (muDoubleScalarCos(qDH[3]) * (-d172 * muDoubleScalarCos(qDH[5])
    - d173 * muDoubleScalarCos(qDH[5])) + muDoubleScalarSin(qDH[5]) *
                    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]))) +
                  4.7665076350000011E-5 * muDoubleScalarSin(qDH[2]) *
                  (muDoubleScalarCos(qDH[3]) * (-d174 * muDoubleScalarSin(qDH[5])
    - d175 * muDoubleScalarSin(qDH[5])) - muDoubleScalarCos(qDH[5]) *
                   muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]))) -
                 8.199406E-6 * (0.64707 * d176 * muDoubleScalarCos(qDH[5]) +
    0.64707 * d177 * muDoubleScalarCos(qDH[5])) * muDoubleScalarCos(qDH[3])) +
                5.227566263355E-5 * muDoubleScalarCos(qDH[5]) *
                muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) -
               0.034168466831297366 * muDoubleScalarSin(qDH[4]) *
               muDoubleScalarSin(qDH[3])) - 0.0055660938409602912 *
              muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) - 4.0E-6 *
             muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) + 6.0E-6 *
            muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) +
           0.14788710822110998 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
           (qDH[2])) + 5.30558964042E-6 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]);
  b[25] = (((((((((((((((((((((-0.0068646370378299994 * muDoubleScalarSin(qDH[4])
    + 0.005561 * muDoubleScalarCos(qDH[3])) + 7.0E-6 * muDoubleScalarSin(qDH[5])
    * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) - 0.03115489117169 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2])) +
    0.0050751779037300016 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])
    * muDoubleScalarSin(qDH[2])) + 4.0E-6 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3])) - 0.0050751779037300016 * muDoubleScalarCos(qDH[4])
    * muDoubleScalarCos(qDH[2])) + 6.0E-6 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3])) - 1.0E-6 * muDoubleScalarSin(qDH[4]) *
                        muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5])) +
                       1.0502474450000003E-5 * muDoubleScalarCos(qDH[5]) *
                       muDoubleScalarCos(qDH[4])) + 0.034168466831297366 *
                      muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) -
                     0.03115489117169 * muDoubleScalarCos(qDH[4]) *
                     muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2])) +
                    5.227566263355E-5 * muDoubleScalarCos(qDH[5]) *
                    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3])) +
                   4.7665076350000011E-5 * muDoubleScalarCos(qDH[5]) *
                   muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2])) -
                  4.83764954E-6 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
                  (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]))
                 + 5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) *
                 muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                 muDoubleScalarSin(qDH[3])) - 4.7665076350000011E-5 *
                muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) *
                muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2])) +
               4.83764954E-6 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
               (qDH[5]) * muDoubleScalarCos(qDH[2])) - 0.0055660938409602912 *
              muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) -
             0.0011182595381100003 * muDoubleScalarCos(qDH[4])) +
            5.30558964042E-6 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
            (qDH[5]) * muDoubleScalarSin(qDH[4])) + 1.06592278E-6 *
           muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5])) +
    5.999999999999929E-6 * d178 * muDoubleScalarCos(qDH[3]);
  b[31] = (((((((((((((7.0E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
                       (qDH[4]) * muDoubleScalarSin(qDH[3]) - 1.0E-6 *
                       muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])) +
                      0.000118 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
                      (qDH[3])) + 1.0E-6 * muDoubleScalarSin(qDH[5]) *
                     muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) +
                    5.227566263355E-5 * muDoubleScalarCos(qDH[5]) *
                    muDoubleScalarSin(qDH[3])) + 5.227566263355E-5 *
                   muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
                   muDoubleScalarCos(qDH[3])) - 1.0502474450000003E-5 *
                  muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4])) -
                 4.7665076350000011E-5 * muDoubleScalarSin(qDH[5]) *
                 muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2])) + 7.0E-6
                * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) -
               4.83764954E-6 * muDoubleScalarSin(qDH[2]) * (-muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]))) +
              4.7665076350000011E-5 * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]) - muDoubleScalarCos
    (qDH[5]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[2])) +
             5.30558964042E-6 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
             (qDH[3])) + 4.83764954E-6 * muDoubleScalarCos(qDH[5]) *
            muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2])) -
           5.30558964042E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH
            [4]) * muDoubleScalarCos(qDH[3])) + 1.06592278E-6 *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]);
  b[2] = ((((((((((((((((((((((((((((((((((-0.002462 * muDoubleScalarCos(qDH[2]
    + qDH[1]) - 0.008851 * muDoubleScalarSin(qDH[2] + qDH[1])) - 1.06592278E-6 *
    (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[4])) - 5.999999999999929E-6 * muDoubleScalarCos(qDH[5])
    * (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]))
    + 0.000725 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[2] + qDH[1]))
    - 0.00942232431335 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] +
    qDH[1])) + 0.03258529503177 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1])) - 6.0E-6 * muDoubleScalarCos(qDH[3]) *
    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) - 0.01473863665669068 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 4.0E-6 * (muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[3])) - 0.005893 * d179 * muDoubleScalarSin(qDH[2] +
    qDH[1])) + 1.0502474450000003E-5 * muDoubleScalarCos(qDH[4]) *
    (muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) - muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) +
    0.052804900291 * (-muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[3]) *
    ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2]
    + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1])) - 0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])
    * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[3])) +
    8.0788265000000011E-5 * ((-muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
    muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5])) + 0.64707 *
    muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) -
    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]))) * muDoubleScalarCos(qDH[3])) - 0.0086019964470000019 * (
    -muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) -
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) *
    muDoubleScalarSin(qDH[4])) * muDoubleScalarCos(qDH[3])) - 8.199406E-6 *
    ((muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[5]) - 0.64707 * muDoubleScalarCos(qDH[4]) *
    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) * muDoubleScalarCos(qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarCos(qDH[3])) + 0.005893 * d180 * muDoubleScalarSin(qDH[2] +
    qDH[1])) + 7.0E-6 * (muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarCos(qDH[4]) - muDoubleScalarSin(qDH[4]) * (muDoubleScalarCos
    (qDH[5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[3])) + 8.199406E-6 * ((-muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) -
    muDoubleScalarSin(qDH[5]) * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[5]) *
    (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) * muDoubleScalarSin(qDH[3])) - 0.052804900291 *
    (((-muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1]))
    - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) - 0.64707 * muDoubleScalarCos
       (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4])
      - 0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
      muDoubleScalarSin(qDH[2] + qDH[1])) - 0.64707 * muDoubleScalarSin(qDH[4]) *
     muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[3])) +
                        0.0086019964470000019 * (((-muDoubleScalarCos(qDH[3]) *
    ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2]
    + qDH[1])) - 0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1])) * muDoubleScalarSin(qDH[4]) - 0.64707 * muDoubleScalarSin(qDH[4])
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                        muDoubleScalarSin(qDH[3])) - 1.0E-6 *
                       (-muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                        muDoubleScalarSin(qDH[5]) - (-muDoubleScalarSin(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4])) *
                       muDoubleScalarSin(qDH[3])) - 0.000714 *
                      ((muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                        muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos
                        (qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                       muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                       muDoubleScalarSin(qDH[4])) * muDoubleScalarSin(qDH[3])) -
                     8.0788265000000011E-5 * ((-muDoubleScalarSin(qDH[4]) *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
                muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))
    + muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarCos(qDH[5]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1]))) * muDoubleScalarSin(qDH[3])) + 0.000118 * (muDoubleScalarSin(qDH[4])
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) +
                   0.0068646370378299994 * muDoubleScalarSin(qDH[3]) *
                   muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[4]))
                  - 1.06592278E-6 * muDoubleScalarSin(qDH[4]) *
                  (-muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                   muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarCos(qDH[4])
                   * muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos
                  (qDH[5])) - 1.0E-6 * muDoubleScalarCos(qDH[3]) *
                 muDoubleScalarCos(qDH[5]) * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) -
                1.0502474450000003E-5 * (muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4])) +
               5.999999999999929E-6 * (-muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) - muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]) *
               muDoubleScalarCos(qDH[3])) - 7.0E-6 * muDoubleScalarCos(qDH[3]) *
              muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) -
             0.02829999999999986 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
             (qDH[2] + qDH[1]) * muDoubleScalarCos(qDH[3])) - 0.002706 *
            (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
             muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
             muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4]) *
            muDoubleScalarSin(qDH[3])) - 6.0E-6 * d181 * muDoubleScalarSin(qDH[2]
            + qDH[1]) * muDoubleScalarSin(qDH[4])) + 0.0011182595381100003 *
          muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
          muDoubleScalarSin(qDH[2] + qDH[1])) - 4.0E-6 * d182 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[2] + qDH[1]);
  b[8] = (((((((((((((((((((((((((((((((((-0.03258529503177 * muDoubleScalarCos
    (qDH[3]) - 0.00942232431335 * muDoubleScalarSin(qDH[3])) + 2.45912384803251 *
    muDoubleScalarCos(qDH[2])) - 2.51588887613257 * muDoubleScalarSin(qDH[2])) +
    1.06592278E-6 * d183 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5]))
    - 1.0502474450000003E-5 * muDoubleScalarSin(qDH[5]) * d184 *
    muDoubleScalarSin(qDH[3])) - 1.06592278E-6 * (-muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) -
    0.02273899999999986 * d185) + 0.005561 * d186) + 7.0E-6 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3])) - 1.0E-6 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) - 0.0068646370378299994 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4])) - 0.0011182595381100003 * muDoubleScalarCos(qDH[4])
    * muDoubleScalarCos(qDH[3])) + 1.0502474450000003E-5 * muDoubleScalarCos
    (qDH[4]) * (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[3]))) + 0.052804900291 * ((-muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) - muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) + 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[3])) +
    8.0788265000000011E-5 * (((-muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarCos(qDH[5]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin
    (qDH[4]) * muDoubleScalarSin(qDH[3])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
    (qDH[3]) + muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
    muDoubleScalarCos(qDH[3])) + 0.002706 * d187 * d188) - 0.0086019964470000019
    * ((-muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
        muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) +
       0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) *
    muDoubleScalarCos(qDH[3])) - 8.199406E-6 * (((muDoubleScalarSin(qDH[4]) *
    (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) - muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarSin(qDH[5]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
     (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
    muDoubleScalarCos(qDH[3])) + 0.011786 * muDoubleScalarCos(qDH[3]) *
                        muDoubleScalarSin(qDH[3])) + 0.000118 * d189 * d190) -
                      5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) *
                      (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                       muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
                       muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4]) *
                      muDoubleScalarSin(qDH[3])) + 3.1667594978143669) -
                    0.052804900291 * ((0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarCos(qDH[4]) - 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[3])) -
                   8.0788265000000011E-5 * (((-muDoubleScalarSin(qDH[4]) * (0.59
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarSin(qDH[5]) * (muDoubleScalarCos
    (qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) -
                0.64707 * muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4])
    * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) + muDoubleScalarCos(qDH[5]) * (
    -0.59 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3]))) * muDoubleScalarSin(qDH[4])) - 0.64707 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5])) * muDoubleScalarSin(qDH[3])) + 7.0E-6 * (muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
    (qDH[5]) - muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarSin(qDH[3])) +
                 8.199406E-6 * (((-muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos
    (qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) -
                0.64707 * muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4])
    * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) - muDoubleScalarSin(qDH[5]) * (
    -0.59 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) + 0.64707 *
    muDoubleScalarSin(qDH[3]))) * muDoubleScalarSin(qDH[4])) + 0.64707 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) * muDoubleScalarSin(qDH[3])) + 0.250656115629 * (-0.59 *
    muDoubleScalarCos(qDH[2]) - 0.13) * muDoubleScalarCos(qDH[3])) +
               0.072479417795 * (-0.59 * muDoubleScalarCos(qDH[2]) - 0.13) *
               muDoubleScalarSin(qDH[3])) + 0.0086019964470000019 * ((0.59 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[4]) - 0.64707 *
    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin
              (qDH[3])) - 1.0E-6 * (-muDoubleScalarCos(qDH[4]) *
              muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
              muDoubleScalarSin(qDH[3]) - (muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4])) *
             muDoubleScalarSin(qDH[3])) + 1.2E-5 * muDoubleScalarSin(qDH[3]) *
            muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) + 8.0E-6 *
           muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) *
           muDoubleScalarCos(qDH[3])) - 0.001428 * muDoubleScalarSin(qDH[4]) *
          d191 * muDoubleScalarCos(qDH[4])) + 5.999999999999929E-6 *
    (muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
     (qDH[3]) + muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]);
  b[14] = (((((((((((((((((((((((((((((-0.06517059006354 * muDoubleScalarCos
    (qDH[3]) - 0.0188446486267 * muDoubleScalarSin(qDH[3])) + 1.06592278E-6 *
    d192 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5])) -
    1.0502474450000003E-5 * muDoubleScalarSin(qDH[5]) * d193 * muDoubleScalarSin
    (qDH[3])) - 1.06592278E-6 * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) -
    0.02273899999999986 * d194) + 0.005561 * d195) - 0.011132187681920582 *
    muDoubleScalarSin(qDH[4]) * d196) + 0.068336933662594732 * muDoubleScalarCos
    (qDH[4]) * d197) + 7.0E-6 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
    (qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) - 1.0E-6 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5])) - 0.0068646370378299994 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) -
    0.0011182595381100003 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]))
    + 1.0502474450000003E-5 * muDoubleScalarCos(qDH[4]) * (-muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) +
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3]))) + 0.002706 * d198 *
    d199) + 0.011786 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[3])) +
                        0.000118 * d200 * d201) + 0.052804900291 * (1.29414 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) - 0.13 *
    muDoubleScalarSin(qDH[4])) * muDoubleScalarCos(qDH[3])) +
                      8.0788265000000011E-5 * (((0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[5]) + 0.64707 * muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3])) + 0.64707 * muDoubleScalarSin(qDH[4]) * (-muDoubleScalarSin(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarCos(qDH[3])) -
                     5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) *
                     (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                      muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
                      muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4]) *
                     muDoubleScalarSin(qDH[3])) - 0.0086019964470000019 *
                    (1.29414 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
                     (qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
                    muDoubleScalarCos(qDH[3])) - 8.199406E-6 * (((-0.64707 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) - 0.13 *
    muDoubleScalarCos(qDH[4])) * muDoubleScalarSin(qDH[5]) + 0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) * muDoubleScalarCos(qDH[5])) + 0.64707 * muDoubleScalarSin(qDH[4]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
     (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]))) *
                   muDoubleScalarCos(qDH[3])) + 7.0E-6 * (muDoubleScalarCos(qDH
    [4]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[5]) - muDoubleScalarSin(qDH[4]) * (-muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) -
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]))) * muDoubleScalarSin
                  (qDH[3])) - 1.0E-6 * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
    (qDH[3]) - (muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                muDoubleScalarSin(qDH[3]) - muDoubleScalarCos(qDH[5]) *
                muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4])) *
                 muDoubleScalarSin(qDH[3])) - 8.0788265000000011E-5 * (((0.64707
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) + 0.13 *
    muDoubleScalarCos(qDH[4])) * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[4]) - (-muDoubleScalarSin(qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4])
    * muDoubleScalarCos(qDH[3]) + 0.13 * muDoubleScalarSin(qDH[4])) + 0.64707 *
                muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3])) *
    muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5])) * muDoubleScalarSin
                (qDH[3])) + 8.199406E-6 * (((0.64707 * muDoubleScalarCos(qDH[3])
    * muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
    muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) - (-muDoubleScalarCos
    (qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])
                + 0.13 * muDoubleScalarSin(qDH[4])) - 0.64707 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3])) * muDoubleScalarSin
    (qDH[4])) + 0.64707 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarSin(qDH[3])) + 12.431305497814368)
             + 1.2E-5 * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[3]) *
             muDoubleScalarSin(qDH[4])) + 8.0E-6 * muDoubleScalarCos(qDH[4]) *
            muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[3])) - 0.001428 *
           muDoubleScalarSin(qDH[4]) * d202 * muDoubleScalarCos(qDH[4])) +
    5.999999999999929E-6 * (muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[3]) + muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[3])) * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3]);
  b[20] = ((((((((((((((((-0.034168466831297366 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) - 0.002588 * muDoubleScalarSin(qDH[4]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4])) - 4.0E-6 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) - 1.0E-6 *
                        muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                        muDoubleScalarCos(qDH[3])) - 0.0055660938409602912 *
                       muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) +
                      6.0E-6 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
                      (qDH[3])) - 1.0E-6 * (-d203 * muDoubleScalarSin(qDH[5]) +
    d204 * muDoubleScalarSin(qDH[5])) * muDoubleScalarSin(qDH[3])) -
                    5.999999999999929E-6 * d205 * muDoubleScalarSin(qDH[4]) *
                    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) +
                   8.0788265000000011E-5 * (0.64707 * d206 * muDoubleScalarSin
    (qDH[5]) + 0.64707 * d207 * muDoubleScalarSin(qDH[5])) * muDoubleScalarCos
                   (qDH[3])) + 7.0E-6 * muDoubleScalarCos(qDH[4]) *
                  muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) -
                 0.000714 * (d208 - d209) * muDoubleScalarSin(qDH[3])) +
                0.01473863665669068 * muDoubleScalarCos(qDH[3])) +
               5.227566263355E-5 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
               (qDH[4]) * muDoubleScalarSin(qDH[3])) + 7.0E-6 * (d210 *
    muDoubleScalarCos(qDH[5]) - d211 * muDoubleScalarCos(qDH[5])) *
              muDoubleScalarSin(qDH[3])) + 5.30558964042E-6 * muDoubleScalarSin
             (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) -
            8.199406E-6 * (0.64707 * d212 * muDoubleScalarCos(qDH[5]) + 0.64707 *
             d213 * muDoubleScalarCos(qDH[5])) * muDoubleScalarCos(qDH[3])) -
           5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin
           (qDH[4]) * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) -
    0.000725 * muDoubleScalarSin(qDH[3]);
  b[26] = (((((((((((((-0.0068646370378299994 * muDoubleScalarSin(qDH[4]) +
                       0.005561 * muDoubleScalarCos(qDH[3])) + 4.0E-6 *
                      muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) +
                     1.0502474450000003E-5 * muDoubleScalarCos(qDH[5]) *
                     muDoubleScalarCos(qDH[4])) - 1.0E-6 * muDoubleScalarSin
                    (qDH[4]) * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos
                    (qDH[5])) + 5.999999999999929E-6 * muDoubleScalarCos(qDH[5])
                   * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                   muDoubleScalarSin(qDH[3])) + 0.034168466831297366 *
                  muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) +
                 5.227566263355E-5 * muDoubleScalarCos(qDH[5]) *
                 muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3])) + 7.0E-6
                * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
                muDoubleScalarSin(qDH[3])) + 6.0E-6 * muDoubleScalarSin(qDH[4]) *
               muDoubleScalarSin(qDH[3])) - 0.0055660938409602912 *
              muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) -
             0.0011182595381100003 * muDoubleScalarCos(qDH[4])) +
            5.30558964042E-6 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
            (qDH[5]) * muDoubleScalarSin(qDH[4])) + 1.06592278E-6 *
           muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5])) +
    5.999999999999929E-6 * d214 * muDoubleScalarCos(qDH[3]);
  b[32] = (((((((((-1.0E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])
                   + 0.000118 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
                   (qDH[3])) + 1.0E-6 * muDoubleScalarSin(qDH[5]) *
                  muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) +
                 5.227566263355E-5 * muDoubleScalarCos(qDH[4]) *
                 muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) -
                1.0502474450000003E-5 * muDoubleScalarSin(qDH[5]) *
                muDoubleScalarSin(qDH[4])) + 7.0E-6 * muDoubleScalarSin(qDH[5]) *
               muDoubleScalarCos(qDH[3])) + 5.227566263355E-5 *
              muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3])) + 7.0E-6 *
             muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
             muDoubleScalarSin(qDH[3])) + 5.30558964042E-6 * muDoubleScalarSin
            (qDH[5]) * muDoubleScalarSin(qDH[3])) - 5.30558964042E-6 *
           muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
           muDoubleScalarCos(qDH[3])) + 1.06592278E-6 * muDoubleScalarCos(qDH[5])
    * muDoubleScalarSin(qDH[4]);
  b[3] = ((((((((((((((((((((8.0788265000000011E-5 * (-muDoubleScalarSin(qDH[5])
    * muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) +
    muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) *
    muDoubleScalarCos(qDH[4]) + 8.199406E-6 * d215 * (muDoubleScalarSin(qDH[3]) *
    ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2]
    + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1])) * muDoubleScalarCos(qDH[5])) - 0.000714 * (-muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[4])) - 8.0788265000000011E-5 * d216 *
    (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
     (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5]))
    - 0.002706 * (muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                  muDoubleScalarSin(qDH[2] + qDH[1]) + muDoubleScalarSin(qDH[4])
                  * muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH
    [4])) - 8.199406E-6 * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4])
    * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarSin
       (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) - muDoubleScalarSin(qDH[5])
    * (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) -
    0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 * muDoubleScalarCos
       (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) * muDoubleScalarCos(qDH[4]))
                        - 7.0E-6 * muDoubleScalarCos(qDH[5]) *
                        (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[4])) -
                       0.052804900291 * (muDoubleScalarCos(qDH[3]) * ((-0.15 -
    0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1]))
    + 0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
                       muDoubleScalarSin(qDH[4])) - 1.0E-6 * (muDoubleScalarSin
    (qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
                      muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4])) +
                     0.000714 * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
    muDoubleScalarCos(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4])) - 7.0E-6 *
                    (muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) +
                     muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
                     muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos
                    (qDH[4])) + 1.0E-6 * (-muDoubleScalarSin(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarCos(qDH[4])) -
                  0.01473863665669068 * muDoubleScalarSin(qDH[3]) *
                  muDoubleScalarSin(qDH[2] + qDH[1])) - 0.072479417795 *
                 muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1]))) - 0.000725 *
                muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))
               - 0.090513 * muDoubleScalarCos(qDH[2] + qDH[1])) +
              0.0086019964470000019 * (-muDoubleScalarCos(qDH[3]) * ((-0.15 -
    0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1]))
    - 0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
              muDoubleScalarCos(qDH[4])) + 4.0E-6 * muDoubleScalarSin(qDH[3]) *
             muDoubleScalarSin(qDH[2] + qDH[1]) * muDoubleScalarSin(qDH[4])) +
            0.000118 * (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                        muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarCos
                        (qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) *
            muDoubleScalarCos(qDH[4])) - 6.0E-6 * muDoubleScalarCos(qDH[4]) *
           muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) -
          0.250656115629 * muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 *
            muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])))
    + 5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH
    [5]) * (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
            muDoubleScalarSin(qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) *
            muDoubleScalarCos(qDH[2] + qDH[1])) + muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
    muDoubleScalarSin(qDH[4]);
  b[9] = ((((((((((((((((((8.0788265000000011E-5 * (-muDoubleScalarSin(qDH[5]) *
    (muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
    muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) +
    muDoubleScalarCos(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3]))) *
    muDoubleScalarCos(qDH[4]) + 8.199406E-6 * (muDoubleScalarSin(qDH[4]) * (0.59
    * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) - muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[4])) + 0.000714 * d217 * muDoubleScalarSin(qDH[3])) -
    8.0788265000000011E-5 * (muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) - muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarSin(qDH[4])) - 0.002588 * muDoubleScalarSin(qDH[4]) *
                        muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[4])) -
                       8.199406E-6 * (-muDoubleScalarCos(qDH[5]) *
    (muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
     muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) -
    muDoubleScalarSin(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3]))) *
                       muDoubleScalarCos(qDH[4])) - 7.0E-6 * d218 *
                      muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5])) -
                     0.052804900291 * (-0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3])) *
                     muDoubleScalarSin(qDH[4])) - 1.0E-6 * muDoubleScalarSin
                    (qDH[5]) * d219 * muDoubleScalarSin(qDH[3])) - 0.000714 *
                   d220 * muDoubleScalarSin(qDH[3])) - 7.0E-6 *
                  (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                   muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) *
                   muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) +
                 1.0E-6 * (muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[3]) - muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
    (qDH[3])) * muDoubleScalarCos(qDH[4])) + 0.01473863665669068 *
                muDoubleScalarCos(qDH[3])) - 0.04276285649905 *
               muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2])) - 0.000725
              * muDoubleScalarSin(qDH[3])) + 0.0086019964470000019 * (0.59 *
              muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
              muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[4])) - 4.0E-6 *
            muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) + 6.0E-6 *
           muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) +
          0.14788710822110998 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin
          (qDH[2])) + 5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
     (qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) *
    muDoubleScalarSin(qDH[4]);
  b[15] = ((((((((((((((((8.0788265000000011E-5 * (-muDoubleScalarSin(qDH[5]) *
    (-0.64707 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + 0.13 *
     muDoubleScalarSin(qDH[4])) + 0.64707 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[4]) + 8.199406E-6 *
    (-0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]) - 0.13 *
     muDoubleScalarCos(qDH[4])) * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin
    (qDH[4])) + 0.000714 * d221 * muDoubleScalarSin(qDH[3])) -
                        8.0788265000000011E-5 * (-0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[4]) - 0.13 * muDoubleScalarCos(qDH[4])) *
                        muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4])) -
                       0.002588 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin
                       (qDH[3]) * muDoubleScalarCos(qDH[4])) - 8.199406E-6 *
                      (-muDoubleScalarCos(qDH[5]) * (-0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + 0.13 *
    muDoubleScalarSin(qDH[4])) - 0.64707 * muDoubleScalarSin(qDH[5]) *
                       muDoubleScalarSin(qDH[3])) * muDoubleScalarCos(qDH[4])) -
                     7.0E-6 * d222 * muDoubleScalarSin(qDH[3]) *
                     muDoubleScalarCos(qDH[5])) - 0.034168466831297366 *
                    muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) -
                   1.0E-6 * muDoubleScalarSin(qDH[5]) * d223 * muDoubleScalarSin
                   (qDH[3])) - 0.000714 * d224 * muDoubleScalarSin(qDH[3])) -
                 7.0E-6 * (-muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4])
    * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
    (qDH[3])) * muDoubleScalarCos(qDH[4])) + 1.0E-6 * (muDoubleScalarSin(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarCos
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarCos(qDH[4])) +
               0.01473863665669068 * muDoubleScalarCos(qDH[3])) - 0.000725 *
              muDoubleScalarSin(qDH[3])) - 0.0055660938409602912 *
             muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) - 4.0E-6 *
            muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4])) + 6.0E-6 *
           muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3])) +
    5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[5])
    * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) - muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[4]);
  b[21] = (((((0.001428 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4])
               + 0.002706 * d225) - 1.4E-5 * muDoubleScalarCos(qDH[5]) *
              muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[4])) - 2.0E-6 *
             muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) *
             muDoubleScalarSin(qDH[4])) + 0.201548748823944) + 0.000118 * d226)
    + 5.999999999999929E-6 * d227 * d228;
  b[27] = (((7.0E-6 * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5]) -
             1.0E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4])) -
            4.0E-6 * muDoubleScalarSin(qDH[4])) + 6.0E-6 * muDoubleScalarCos
           (qDH[4])) - 5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]);
  b[33] = (-7.0E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) -
           1.0E-6 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4])) +
    0.000118 * muDoubleScalarCos(qDH[4]);
  b[4] = ((((((((((((((((((-1.0E-6 * muDoubleScalarCos(qDH[5]) *
    (muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) + 1.4E-7 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) - 0.005561 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) + 0.0086019964470000019 *
    muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) -
                        8.0788265000000011E-5 * muDoubleScalarSin(qDH[4]) *
                        (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
                        muDoubleScalarCos(qDH[5])) + 3.6400000000000003E-6 *
                       muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
                       muDoubleScalarSin(qDH[2] + qDH[1])) -
                      3.6400000000000003E-6 * muDoubleScalarCos(qDH[4]) *
                      muDoubleScalarCos(qDH[2] + qDH[1])) + 2.0E-8 *
                     muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) - 2.0E-8 *
                    muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
                    muDoubleScalarSin(qDH[2] + qDH[1])) - 1.6157653000000002E-6 *
                   muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos(qDH[3]) *
    ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2]
    + qDH[1])) + 0.64707 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1]))) + 1.6157653000000002E-6 * muDoubleScalarSin(qDH[5]) *
                  muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[3]) *
    ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2]
    + qDH[1])) + 0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2]
    + qDH[1]))) + 5.999999999999929E-6 * (-muDoubleScalarCos(qDH[5]) *
    (-muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin
     (qDH[2] + qDH[1]) - muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] +
    qDH[1])) - muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1])) * muDoubleScalarSin(qDH[5])) -
                8.199406E-6 * muDoubleScalarSin(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
                muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) *
                muDoubleScalarSin(qDH[5])) - 1.6398811999999998E-7 *
               muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
               (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
                muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])))
              - 0.052804900291 * muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
                muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) -
             1.6398811999999998E-7 * muDoubleScalarSin(qDH[5]) *
             (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos
    (qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
              muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) -
            7.0E-6 * muDoubleScalarSin(qDH[5]) * (-muDoubleScalarSin(qDH[4]) *
             muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) +
             muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) +
           1.4E-7 * muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
            muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
            muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) +
          4.0E-6 * muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) *
          muDoubleScalarSin(qDH[2] + qDH[1])) + 4.0E-6 * muDoubleScalarSin(qDH[4])
    * muDoubleScalarCos(qDH[2] + qDH[1]);
  b[10] = ((((((((((((((((((-0.0086019964470000019 * muDoubleScalarCos(qDH[4]) *
    (0.59 * muDoubleScalarCos(qDH[2]) + 0.13) - 1.0E-6 * muDoubleScalarSin(qDH[4])
    * muDoubleScalarSin(qDH[3]) * muDoubleScalarCos(qDH[5])) - 1.4E-7 *
    muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) + 0.005561 *
    muDoubleScalarCos(qDH[3])) + 0.0086019964470000019 * muDoubleScalarSin(qDH[4])
    * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
       muDoubleScalarCos(qDH[3]))) + 8.0788265000000011E-5 * (-muDoubleScalarSin
    (qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) -
                0.64707 * muDoubleScalarCos(qDH[3])) + muDoubleScalarCos(qDH[4])
    * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarCos(qDH[5])) +
                       3.6400000000000003E-6 * muDoubleScalarSin(qDH[4]) *
                       muDoubleScalarSin(qDH[3])) - 2.0E-8 * muDoubleScalarSin
                      (qDH[5]) * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin
                      (qDH[3])) + 2.0E-8 * muDoubleScalarCos(qDH[5]) *
                     muDoubleScalarCos(qDH[3])) - 1.6157653000000002E-6 *
                    muDoubleScalarCos(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3])
    * muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3]))) +
                   1.6157653000000002E-6 * muDoubleScalarSin(qDH[5]) *
                   (muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3])
    * muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
                    muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2])
    + 0.13))) + 5.999999999999929E-6 * (muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[5])) -
                 8.199406E-6 * (muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) - muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13)) * muDoubleScalarSin(qDH[5])) -
                1.6398811999999998E-7 * muDoubleScalarCos(qDH[5]) *
                (muDoubleScalarCos(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[2]) - 0.64707 * muDoubleScalarCos(qDH[3])) +
                 muDoubleScalarSin(qDH[4]) * (0.59 * muDoubleScalarCos(qDH[2]) +
    0.13))) - 0.052804900291 * muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3]))) - 0.052804900291 * muDoubleScalarSin(qDH[4]) *
              (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) - 1.6398811999999998E-7
             * muDoubleScalarSin(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3]) *
              muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3])))
            + 7.0E-6 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
            muDoubleScalarSin(qDH[3])) - 1.4E-7 * muDoubleScalarCos(qDH[5]) *
           muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) + 4.0E-6 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]);
  b[16] = ((((((((((((((((((-0.0011182595381100003 * muDoubleScalarCos(qDH[4]) -
    1.0E-6 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarCos(qDH[5])) - 1.4E-7 * muDoubleScalarSin(qDH[5]) *
    muDoubleScalarCos(qDH[3])) + 0.005561 * muDoubleScalarCos(qDH[3])) -
    0.0055660938409602912 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[4]))
                        + 8.0788265000000011E-5 * (0.64707 * muDoubleScalarCos
    (qDH[3]) * muDoubleScalarSin(qDH[4]) + 0.13 * muDoubleScalarCos(qDH[4])) *
                        muDoubleScalarCos(qDH[5])) + 3.6400000000000003E-6 *
                       muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3])) -
                      2.0E-8 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos
                      (qDH[4]) * muDoubleScalarSin(qDH[3])) + 2.0E-8 *
                     muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[3])) -
                    1.045513252671E-6 * muDoubleScalarCos(qDH[5]) *
                    muDoubleScalarSin(qDH[3])) + 1.6157653000000002E-6 *
                   muDoubleScalarSin(qDH[5]) * (-0.64707 * muDoubleScalarCos
    (qDH[4]) * muDoubleScalarCos(qDH[3]) + 0.13 * muDoubleScalarSin(qDH[4]))) +
                  5.999999999999929E-6 * (muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]) + muDoubleScalarSin
    (qDH[5]) * muDoubleScalarCos(qDH[3])) * muDoubleScalarSin(qDH[5])) -
                 8.199406E-6 * (-0.64707 * muDoubleScalarCos(qDH[3]) *
    muDoubleScalarSin(qDH[4]) - 0.13 * muDoubleScalarCos(qDH[4])) *
                 muDoubleScalarSin(qDH[5])) - 1.6398811999999998E-7 *
                muDoubleScalarCos(qDH[5]) * (-0.64707 * muDoubleScalarCos(qDH[4])
    * muDoubleScalarCos(qDH[3]) + 0.13 * muDoubleScalarSin(qDH[4]))) +
               0.034168466831297366 * muDoubleScalarCos(qDH[4]) *
               muDoubleScalarCos(qDH[3])) - 0.0068646370378299994 *
              muDoubleScalarSin(qDH[4])) - 1.0611179280839999E-7 *
             muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3])) + 7.0E-6 *
            muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4]) *
            muDoubleScalarSin(qDH[3])) - 1.4E-7 * muDoubleScalarCos(qDH[5]) *
           muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) + 4.0E-6 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3]);
  b[22] = (((((-1.0E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) +
               3.6400000000000003E-6 * muDoubleScalarCos(qDH[4])) + 2.0E-8 *
              muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4])) -
             5.999999999999929E-6 * muDoubleScalarCos(qDH[5]) *
             muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4])) + 7.0E-6 *
            muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[5])) + 1.4E-7 *
           muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4])) - 4.0E-6 *
    muDoubleScalarSin(qDH[4]);
  b[28] = ((0.274361 - 1.4E-7 * muDoubleScalarSin(qDH[5])) + 2.0E-8 *
           muDoubleScalarCos(qDH[5])) + 5.999999999999929E-6 * d229;
  b[34] = (-2.36E-6 - 1.0E-6 * muDoubleScalarCos(qDH[5])) + 7.0E-6 *
    muDoubleScalarSin(qDH[5]);
  b[5] = ((((((((8.199406E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarCos
                 (qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 - 0.59 *
    muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) +
    0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1])) +
                 8.199406E-6 * muDoubleScalarSin(qDH[5]) * (muDoubleScalarCos
    (qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1])) - 0.13 *
                muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) - 7.0E-6 *
                muDoubleScalarCos(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
    muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) - 7.0E-6 *
               muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[3]) *
               muDoubleScalarSin(qDH[2] + qDH[1])) + 0.000118 *
              muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[3]) *
              muDoubleScalarSin(qDH[2] + qDH[1])) - 0.000118 * muDoubleScalarCos
             (qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1])) -
            8.0788265000000011E-5 * muDoubleScalarSin(qDH[5]) *
            muDoubleScalarCos(qDH[4]) * (muDoubleScalarSin(qDH[3]) * ((-0.15 -
    0.59 * muDoubleScalarCos(qDH[1])) - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1]))
             + 0.64707 * muDoubleScalarSin(qDH[3]) * muDoubleScalarSin(qDH[2] +
              qDH[1]))) + 8.0788265000000011E-5 * muDoubleScalarCos(qDH[5]) *
           (muDoubleScalarCos(qDH[3]) * ((-0.15 - 0.59 * muDoubleScalarCos(qDH[1]))
             - 0.13 * muDoubleScalarCos(qDH[2] + qDH[1])) + 0.64707 *
            muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]))) -
          1.0E-6 * muDoubleScalarSin(qDH[5]) * (-muDoubleScalarCos(qDH[4]) *
           muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2] + qDH[1]) -
           muDoubleScalarSin(qDH[4]) * muDoubleScalarCos(qDH[2] + qDH[1]))) +
    1.0E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2] + qDH[1]);
  b[11] = (((((((8.199406E-6 * muDoubleScalarCos(qDH[5]) * (muDoubleScalarCos
    (qDH[4]) * (0.59 * muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) -
                0.64707 * muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4])
    * (0.59 * muDoubleScalarCos(qDH[2]) + 0.13)) + 8.199406E-6 *
                 muDoubleScalarSin(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3]) *
    muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3]))) + 7.0E-6 *
                muDoubleScalarCos(qDH[5]) * muDoubleScalarCos(qDH[4]) *
                muDoubleScalarSin(qDH[3])) + 7.0E-6 * muDoubleScalarSin(qDH[5]) *
               muDoubleScalarCos(qDH[3])) + 0.000118 * muDoubleScalarSin(qDH[4])
              * muDoubleScalarSin(qDH[3])) - 8.0788265000000011E-5 *
             muDoubleScalarSin(qDH[5]) * (muDoubleScalarCos(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[3]) * muDoubleScalarSin(qDH[2]) - 0.64707 *
    muDoubleScalarCos(qDH[3])) + muDoubleScalarSin(qDH[4]) * (0.59 *
    muDoubleScalarCos(qDH[2]) + 0.13))) + 8.0788265000000011E-5 *
            muDoubleScalarCos(qDH[5]) * (-0.59 * muDoubleScalarSin(qDH[3]) *
             muDoubleScalarSin(qDH[2]) + 0.64707 * muDoubleScalarSin(qDH[3]))) +
           1.0E-6 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
           muDoubleScalarSin(qDH[3])) - 1.0E-6 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[3]);
  b[17] = (((((((8.199406E-6 * muDoubleScalarCos(qDH[5]) * (-0.64707 *
    muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + 0.13 *
    muDoubleScalarSin(qDH[4])) + 5.30558964042E-6 * muDoubleScalarSin(qDH[5]) *
                 muDoubleScalarSin(qDH[3])) + 7.0E-6 * muDoubleScalarCos(qDH[5])
                * muDoubleScalarCos(qDH[4]) * muDoubleScalarSin(qDH[3])) +
               7.0E-6 * muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[3])) +
              0.000118 * muDoubleScalarSin(qDH[4]) * muDoubleScalarSin(qDH[3]))
             - 8.0788265000000011E-5 * muDoubleScalarSin(qDH[5]) * (-0.64707 *
              muDoubleScalarCos(qDH[4]) * muDoubleScalarCos(qDH[3]) + 0.13 *
              muDoubleScalarSin(qDH[4]))) + 5.227566263355E-5 *
            muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[3])) + 1.0E-6 *
           muDoubleScalarSin(qDH[5]) * muDoubleScalarCos(qDH[4]) *
           muDoubleScalarSin(qDH[3])) - 1.0E-6 * muDoubleScalarCos(qDH[5]) *
    muDoubleScalarCos(qDH[3]);
  b[23] = (-7.0E-6 * muDoubleScalarCos(qDH[5]) * muDoubleScalarSin(qDH[4]) -
           1.0E-6 * muDoubleScalarSin(qDH[5]) * muDoubleScalarSin(qDH[4])) +
    0.000118 * muDoubleScalarCos(qDH[4]);
  b[29] = (0.0021 + 7.0E-6 * muDoubleScalarSin(qDH[5])) - 1.0E-6 *
    muDoubleScalarCos(qDH[5]);
  b[35] = 0.10511799999999999;
  mpower();
  for (i2 = 0; i2 < 6; i2++) {
    for (i3 = 0; i3 < 6; i3++) {
      a[i2 + 6 * i3] = 0.0;
      for (i4 = 0; i4 < 6; i4++) {
        a[i2 + 6 * i3] += (real_T)b_a[i2 + 6 * i4] * b[i4 + 6 * i3];
      }
    }
  }

  for (i2 = 0; i2 < 6; i2++) {
    for (i3 = 0; i3 < 6; i3++) {
      B1[i2 + (i3 << 3)] = 0.0;
      for (i4 = 0; i4 < 6; i4++) {
        B1[i2 + (i3 << 3)] += (real_T)b_a[i2 + 6 * i4] * a[i4 + 6 * i3];
      }
    }
  }

  B1[54] = 150.0;
  B1[63] = 150.0;
}

/* End of code generation (MatriceInerzia2.c) */
