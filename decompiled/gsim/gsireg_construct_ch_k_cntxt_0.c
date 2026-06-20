void __fastcall gsireg_construct_ch_k_cntxt_0(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8

  v3 = *a3 | (*a2 << 24);
  *a3 = v3;
  v4 = ((a2[1] & 0xF) << 20) | v3;
  *a3 = v4;
  v5 = ((a2[2] & 0x1F) << 14) | v4;
  *a3 = v5;
  v6 = ((a2[4] & 0x1F) << 8) | v5;
  *a3 = v6;
  v7 = (16 * (a2[5] & 0xF)) | v6;
  *a3 = v7;
  v8 = v7 | (8 * (a2[6] != 0));
  *a3 = v8;
  *a3 = v8 | a2[7] & 7;
}
