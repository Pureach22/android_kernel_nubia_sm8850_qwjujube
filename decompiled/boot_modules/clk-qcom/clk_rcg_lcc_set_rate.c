__int64 __fastcall clk_rcg_lcc_set_rate(__int64 a1)
{
  __int64 freq; // x0
  __int64 v3; // x20
  char is_enabled; // w8
  __int64 result; // x0

  freq = qcom_find_freq(*(_QWORD *)(a1 - 8));
  if ( !freq )
    return 4294967274LL;
  v3 = freq;
  regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 1024, 0, 0, 0, 0);
  _clk_rcg_set_rate(a1 - 48, v3);
  is_enabled = _clk_is_enabled(*(_QWORD *)(a1 + 8));
  result = 0;
  if ( (is_enabled & 1) != 0 )
  {
    regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 1024, 1024, 0, 0, 0);
    return 0;
  }
  return result;
}
