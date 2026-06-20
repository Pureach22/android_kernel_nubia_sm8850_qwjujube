__int64 __fastcall clk_rcg_set_floor_rate(__int64 a1)
{
  __int64 freq_floor; // x0

  freq_floor = qcom_find_freq_floor(*(_QWORD *)(a1 - 8));
  if ( !freq_floor )
    return 4294967274LL;
  _clk_rcg_set_rate(a1 - 48, freq_floor);
  return 0;
}
