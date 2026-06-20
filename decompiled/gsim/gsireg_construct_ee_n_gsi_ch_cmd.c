void __fastcall gsireg_construct_ee_n_gsi_ch_cmd(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8

  v3 = *a3 | (*(_DWORD *)a2 << 24);
  *a3 = v3;
  *a3 = *(unsigned __int8 *)(a2 + 4) | v3;
}
