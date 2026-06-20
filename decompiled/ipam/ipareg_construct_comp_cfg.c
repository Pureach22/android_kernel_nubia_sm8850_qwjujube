void __fastcall ipareg_construct_comp_cfg(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8
  int v9; // w8
  int v10; // w8
  int v11; // w8
  int v12; // w8
  int v13; // w8
  int v14; // w8
  int v15; // w8
  int v16; // w8
  int v17; // w8
  int v18; // w8
  int v19; // w8

  v3 = *a3 | ((unsigned __int8)a2[7] << 16);
  *a3 = v3;
  v4 = v3 | ((unsigned __int8)a2[8] << 15);
  *a3 = v4;
  v5 = v4 | ((unsigned __int8)a2[9] << 14);
  *a3 = v5;
  v6 = v5 | ((unsigned __int8)a2[10] << 13);
  *a3 = v6;
  v7 = v6 | ((unsigned __int8)a2[11] << 12);
  *a3 = v7;
  v8 = v7 | ((unsigned __int8)a2[12] << 11);
  *a3 = v8;
  v9 = v8 | ((unsigned __int8)a2[13] << 10);
  *a3 = v9;
  v10 = v9 | ((unsigned __int8)a2[14] << 9);
  *a3 = v10;
  v11 = v10 | ((unsigned __int8)a2[15] << 8);
  *a3 = v11;
  v12 = v11 | ((unsigned __int8)a2[16] << 7);
  *a3 = v12;
  v13 = v12 | ((unsigned __int8)a2[17] << 6);
  *a3 = v13;
  v14 = v13 | (32 * (unsigned __int8)a2[18]);
  *a3 = v14;
  v15 = v14 | (8 * (unsigned __int8)a2[20]);
  *a3 = v15;
  v16 = v15 | (4 * (unsigned __int8)a2[21]);
  *a3 = v16;
  v17 = v16 | (2 * (unsigned __int8)a2[22]);
  *a3 = v17;
  v18 = ((a2[3] & 0xF) << 17) | v17;
  *a3 = v18;
  v19 = v18 | (unsigned __int8)a2[24];
  *a3 = v19;
  *a3 = v19 | (16 * (unsigned __int8)a2[19]);
}
