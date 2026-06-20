void __fastcall ipareg_construct_hash_cfg_n(__int64 a1, unsigned __int8 *a2, int *a3)
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

  v3 = *a3 | *a2;
  *a3 = v3;
  v4 = v3 | (2 * a2[1]);
  *a3 = v4;
  v5 = v4 | (4 * a2[2]);
  *a3 = v5;
  v6 = v5 | (8 * a2[3]);
  *a3 = v6;
  v7 = v6 | (16 * a2[4]);
  *a3 = v7;
  v8 = v7 | (32 * a2[5]);
  *a3 = v8;
  v9 = v8 | (a2[6] << 6);
  *a3 = v9;
  v10 = ((*((_DWORD *)a2 + 4) & 0x1FF) << 7) | v9;
  *a3 = v10;
  v11 = v10 | (a2[7] << 16);
  *a3 = v11;
  v12 = v11 | (a2[8] << 17);
  *a3 = v12;
  v13 = v12 | (a2[9] << 18);
  *a3 = v13;
  v14 = v13 | (a2[10] << 19);
  *a3 = v14;
  v15 = v14 | (a2[11] << 20);
  *a3 = v15;
  v16 = v15 | (a2[12] << 21);
  *a3 = v16;
  v17 = v16 | (a2[13] << 22);
  *a3 = v17;
  *a3 = v17 | (*((_DWORD *)a2 + 5) << 23);
}
