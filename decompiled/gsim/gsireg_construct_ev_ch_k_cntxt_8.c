void __fastcall gsireg_construct_ev_ch_k_cntxt_8(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w8

  v3 = *a3 | (*(_DWORD *)a2 << 24);
  *a3 = v3;
  v4 = ((unsigned __int8)*(_DWORD *)(a2 + 4) << 16) | v3;
  *a3 = v4;
  *a3 = v4 | *(unsigned __int16 *)(a2 + 8);
}
