void __fastcall ipareg_construct_endp_init_hdr_ext_n_v5_0(__int64 a1, __int64 a2, int *a3)
{
  int v5; // w8

  ipareg_construct_endp_init_hdr_ext_n_v4_5(a1, a2, a3);
  v5 = *a3 | (*(unsigned __int8 *)(a2 + 32) << 22);
  *a3 = v5;
  *a3 = v5 | (*(_DWORD *)(a2 + 36) << 24);
}
