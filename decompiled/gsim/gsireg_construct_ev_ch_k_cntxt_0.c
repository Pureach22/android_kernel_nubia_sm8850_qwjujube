void __fastcall gsireg_construct_ev_ch_k_cntxt_0(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8

  v3 = *a3 | (*a2 << 24);
  *a3 = v3;
  v4 = ((a2[1] & 0xF) << 20) | v3;
  *a3 = v4;
  v5 = ((unsigned __int8)a2[3] << 8) | v4;
  *a3 = v5;
  v6 = ((a2[2] & 1) << 16) | v5;
  *a3 = v6;
  v7 = (16 * (a2[4] & 0xF)) | v6;
  *a3 = v7;
  *a3 = v7 | a2[5] & 0xF;
}
