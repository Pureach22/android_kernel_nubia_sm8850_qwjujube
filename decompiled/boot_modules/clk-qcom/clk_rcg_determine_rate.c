__int64 __fastcall clk_rcg_determine_rate(__int64 a1, __int64 a2)
{
  return freq_tbl_determine_rate(a1, *(_QWORD *)(a1 - 8), a2, *(_QWORD *)(a1 - 16));
}
