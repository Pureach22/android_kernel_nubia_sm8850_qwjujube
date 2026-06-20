char *__fastcall qdf_update_dbl(char *result)
{
  int v1; // w8
  int v2; // w15
  int v3; // w12
  char v4; // w8
  char v5; // w9
  unsigned __int64 v6; // t2
  char v7; // w10
  char v8; // w11
  int v9; // w13
  unsigned int v10; // w9
  int v11; // w14
  int v12; // w11
  char v13; // w10
  unsigned int v14; // w13
  int v15; // w10
  unsigned int v16; // w14
  int v17; // w12
  int v18; // w11
  int v19; // w10
  unsigned int v20; // w12

  v1 = (unsigned __int8)result[15];
  v2 = (unsigned __int8)result[11];
  v3 = v1 << 24;
  v4 = 2 * v1;
  HIDWORD(v6) = (unsigned __int8)result[14];
  LODWORD(v6) = v3;
  v5 = v6 >> 31;
  HIDWORD(v6) = (unsigned __int8)result[13];
  LODWORD(v6) = (unsigned __int8)result[14] << 24;
  v7 = v6 >> 31;
  HIDWORD(v6) = (unsigned __int8)result[12];
  LODWORD(v6) = (unsigned __int8)result[13] << 24;
  v8 = v6 >> 31;
  v9 = (unsigned __int8)result[10];
  HIDWORD(v6) = v2;
  LODWORD(v6) = (unsigned __int8)result[12] << 24;
  LOBYTE(v3) = v6 >> 31;
  result[14] = v5;
  v10 = (unsigned __int8)result[9];
  result[13] = v7;
  HIDWORD(v6) = v9;
  LODWORD(v6) = v2 << 24;
  v11 = (unsigned __int8)result[8];
  result[12] = v8;
  v12 = (unsigned __int8)result[7];
  result[11] = v3;
  v13 = __PAIR64__(v10, v9 << 24) >> 31;
  result[10] = v6 >> 31;
  v14 = (unsigned __int8)result[5];
  result[9] = v13;
  HIDWORD(v6) = v11;
  LODWORD(v6) = v10 << 24;
  LOBYTE(v10) = v6 >> 31;
  v15 = (unsigned __int8)result[6];
  HIDWORD(v6) = v12;
  LODWORD(v6) = v11 << 24;
  LOBYTE(v3) = v6 >> 31;
  v16 = (unsigned __int8)result[4];
  result[8] = v10;
  HIDWORD(v6) = v15;
  LODWORD(v6) = v12 << 24;
  result[7] = v3;
  v17 = (unsigned __int8)result[3];
  result[6] = v6 >> 31;
  v18 = (unsigned __int8)result[2];
  result[5] = __PAIR64__(v14, v15 << 24) >> 31;
  HIDWORD(v6) = v17;
  LODWORD(v6) = v16 << 24;
  result[4] = __PAIR64__(v16, v14 << 24) >> 31;
  v19 = (unsigned __int8)result[1];
  result[3] = v6 >> 31;
  HIDWORD(v6) = v18;
  LODWORD(v6) = v17 << 24;
  LOBYTE(v10) = v6 >> 31;
  v20 = *result;
  HIDWORD(v6) = v19;
  LODWORD(v6) = v18 << 24;
  result[15] = v4;
  result[2] = v10;
  result[1] = v6 >> 31;
  *result = __PAIR64__(v20, v19 << 24) >> 31;
  if ( (v20 & 0x80000000) != 0 )
    result[15] = v4 ^ 0x87;
  return result;
}
