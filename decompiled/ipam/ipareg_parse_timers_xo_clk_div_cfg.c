void __fastcall ipareg_parse_timers_xo_clk_div_cfg(__int64 a1, __int64 a2, int a3)
{
  *(_DWORD *)(a2 + 4) = a3 & 0x1FF;
  *(_BYTE *)a2 = a3 < 0;
}
