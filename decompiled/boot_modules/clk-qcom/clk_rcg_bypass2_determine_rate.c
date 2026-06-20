__int64 __fastcall clk_rcg_bypass2_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x8

  v3 = clk_hw_round_rate(a2[5], a2[1]);
  a2[4] = v3;
  a2[1] = v3;
  return 0;
}
