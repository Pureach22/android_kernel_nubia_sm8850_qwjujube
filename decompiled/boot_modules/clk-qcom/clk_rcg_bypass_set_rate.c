__int64 __fastcall clk_rcg_bypass_set_rate(__int64 a1)
{
  _clk_rcg_set_rate(a1 - 48, *(_QWORD *)(a1 - 8));
  return 0;
}
