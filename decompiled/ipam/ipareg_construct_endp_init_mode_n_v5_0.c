void __fastcall ipareg_construct_endp_init_mode_n_v5_0(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8

  v3 = *a3 | a2[1] & 7;
  *a3 = v3;
  *a3 = (16 * (unsigned __int8)*a2) | v3;
}
