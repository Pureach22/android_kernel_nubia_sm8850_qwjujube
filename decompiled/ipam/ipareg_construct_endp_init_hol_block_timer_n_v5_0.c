void __fastcall ipareg_construct_endp_init_hol_block_timer_n_v5_0(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8

  v3 = *a3 | *(_BYTE *)(a2 + 15) & 0x1F;
  *a3 = v3;
  *a3 = ((*(_BYTE *)(a2 + 14) & 3) << 8) | v3;
}
