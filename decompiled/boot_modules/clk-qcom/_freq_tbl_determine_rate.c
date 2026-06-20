__int64 __fastcall freq_tbl_determine_rate(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4)
{
  __int64 v4; // x21
  __int64 freq; // x0
  __int64 v9; // x20
  unsigned int src_index; // w24
  char flags; // w23
  __int64 parent_by_index; // x0
  __int64 v13; // x21
  unsigned __int64 rate; // x9

  v4 = a3[1];
  freq = qcom_find_freq(a2);
  if ( !freq )
    return (unsigned int)-22;
  v9 = freq;
  src_index = qcom_find_src_index(a1, a4, *(unsigned __int8 *)(freq + 8));
  if ( (src_index & 0x80000000) != 0 )
    return src_index;
  flags = clk_hw_get_flags(a1);
  parent_by_index = clk_hw_get_parent_by_index(a1, src_index);
  if ( !parent_by_index )
    return (unsigned int)-22;
  if ( (flags & 4) != 0 )
  {
    rate = v4 * *(unsigned __int8 *)(v9 + 9);
    if ( *(_WORD *)(v9 + 12) )
      rate = rate * *(unsigned __int16 *)(v9 + 12) / *(unsigned __int16 *)(v9 + 10);
  }
  else
  {
    v13 = parent_by_index;
    rate = clk_hw_get_rate(parent_by_index);
    parent_by_index = v13;
  }
  a3[4] = rate;
  a3[5] = parent_by_index;
  src_index = 0;
  a3[1] = *(_QWORD *)v9;
  return src_index;
}
