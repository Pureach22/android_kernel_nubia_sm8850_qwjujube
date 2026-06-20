__int64 __fastcall clk_rcg_set_rate(__int64 a1)
{
  __int64 freq; // x0

  freq = qcom_find_freq(*(_QWORD *)(a1 - 8));
  if ( !freq )
    return 4294967274LL;
  _clk_rcg_set_rate(a1 - 48, freq);
  return 0;
}
