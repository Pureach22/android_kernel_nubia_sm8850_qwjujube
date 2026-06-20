__int64 __fastcall clk_rcg2_shared_set_rate(__int64 a1)
{
  __int64 freq; // x0
  __int64 v3; // x20
  __int64 result; // x0

  freq = qcom_find_freq(*(_QWORD *)(a1 - 8));
  if ( !freq )
    return 4294967274LL;
  v3 = freq;
  if ( (clk_hw_is_enabled(a1) & 1) == 0 )
    return _clk_rcg2_configure(a1 - 48, v3, a1 + 148);
  result = clk_rcg2_set_force_enable(a1);
  if ( !(_DWORD)result )
  {
    result = clk_rcg2_configure(a1 - 48, v3);
    if ( !(_DWORD)result )
      return regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 2, 0, 0, 0, 0);
  }
  return result;
}
