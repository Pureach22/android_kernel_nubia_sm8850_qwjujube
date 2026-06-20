__int64 __fastcall clk_dyn_rcg_set_rate_and_parent(__int64 a1)
{
  __int64 freq; // x0

  freq = qcom_find_freq(*(_QWORD *)(a1 - 8));
  if ( freq )
    return configure_bank(a1 - 80, freq);
  else
    return 4294967274LL;
}
