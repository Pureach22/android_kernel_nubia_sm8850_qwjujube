void __fastcall gsireg_construct_gsi_cfg_v2_5(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8

  v3 = *a3 | (32 * (a2[1] != 0));
  *a3 = v3;
  v4 = v3 | (16 * (a2[2] != 0));
  *a3 = v4;
  v5 = v4 | (8 * (a2[3] != 0));
  *a3 = v5;
  v6 = v5 | (4 * (a2[4] != 0));
  *a3 = v6;
  v7 = v6 | (2 * (a2[5] != 0));
  *a3 = v7;
  v8 = v7 | (a2[6] != 0);
  *a3 = v8;
  *a3 = ((*a2 & 0xF) << 8) | v8;
}
