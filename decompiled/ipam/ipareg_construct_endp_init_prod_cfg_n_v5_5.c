void __fastcall ipareg_construct_endp_init_prod_cfg_n_v5_5(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8

  v3 = *a3 | (*a2 != 0);
  *a3 = v3;
  v4 = v3 | (2 * (unsigned __int8)a2[1]);
  *a3 = v4;
  v5 = v4 | (4 * (unsigned __int8)a2[2]);
  *a3 = v5;
  v6 = (8 * (unsigned __int8)a2[3]) & 0xF0 | v5;
  *a3 = v6;
  v7 = v6 | ((unsigned __int8)a2[4] << 8);
  *a3 = v7;
  v8 = v7 | ((unsigned __int8)a2[5] << 16);
  *a3 = v8;
  *a3 = v8 | ((unsigned __int8)a2[6] << 24);
}
