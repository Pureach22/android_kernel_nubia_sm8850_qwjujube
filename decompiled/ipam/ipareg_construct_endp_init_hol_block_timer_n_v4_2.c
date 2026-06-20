void __fastcall ipareg_construct_endp_init_hol_block_timer_n_v4_2(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8

  v3 = ((*(_DWORD *)(a2 + 8) & 0x1F) << 8) | *a3;
  *a3 = v3;
  *a3 = *(_DWORD *)(a2 + 4) & 0x1F | v3;
}
