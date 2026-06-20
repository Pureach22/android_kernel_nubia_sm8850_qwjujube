void __fastcall ipareg_construct_cache_cfg_n(__int64 a1, unsigned __int8 *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8
  int v9; // w8

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
  *a3 = v9 | (*((_DWORD *)a2 + 2) << 7);
}
