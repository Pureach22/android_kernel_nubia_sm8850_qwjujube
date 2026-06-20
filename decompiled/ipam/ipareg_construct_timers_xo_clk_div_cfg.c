void __fastcall ipareg_construct_timers_xo_clk_div_cfg(__int64 a1, unsigned __int8 *a2, int *a3)
{
  int v3; // w8

  v3 = *a3 | (*a2 << 31);
  *a3 = v3;
  *a3 = *((_DWORD *)a2 + 1) & 0x1FF | v3;
}
