void __fastcall gsireg_construct_ch_k_cntxt_1_v3_0(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8

  v3 = *a3 | *a2 & 0xFFFFFF;
  *a3 = v3;
  *a3 = v3 | (a2[1] << 24);
}
