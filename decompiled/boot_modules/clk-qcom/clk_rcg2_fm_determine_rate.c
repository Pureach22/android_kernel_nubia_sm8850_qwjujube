unsigned __int64 __fastcall clk_rcg2_fm_determine_rate(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x22
  __int64 freq_multi; // x0
  unsigned __int64 *v6; // x20
  unsigned __int64 result; // x0
  unsigned __int64 v8; // x24
  unsigned int v9; // w23
  char flags; // w22
  __int64 parent_by_index; // x0
  __int64 v12; // x21
  unsigned __int64 rate; // x8

  v2 = a2[1];
  freq_multi = qcom_find_freq_multi(*(_QWORD *)(a1 - 8), v2);
  if ( !freq_multi )
    return 4294967274LL;
  v6 = (unsigned __int64 *)freq_multi;
  if ( !*(_QWORD *)(freq_multi + 16) )
    return 4294967274LL;
  result = _clk_rcg2_select_conf(a1, freq_multi, v2);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
  v8 = result;
  result = qcom_find_src_index(a1, *(_QWORD *)(a1 - 40), *(unsigned __int8 *)result);
  if ( (result & 0x80000000) != 0 )
    return result;
  v9 = result;
  flags = clk_hw_get_flags(a1);
  parent_by_index = clk_hw_get_parent_by_index(a1, v9);
  if ( !parent_by_index )
    return 4294967274LL;
  if ( (flags & 4) != 0 )
  {
    rate = *v6;
    if ( *(_BYTE *)(v8 + 1) )
    {
      if ( !rate )
        rate = a2[1];
      rate = (rate >> 1) + (rate >> 1) * *(unsigned __int8 *)(v8 + 1);
    }
    if ( *(_WORD *)(v8 + 4) )
      rate = rate * *(unsigned __int16 *)(v8 + 4) / *(unsigned __int16 *)(v8 + 2);
  }
  else
  {
    v12 = parent_by_index;
    rate = clk_hw_get_rate(parent_by_index);
    parent_by_index = v12;
  }
  a2[4] = rate;
  a2[5] = parent_by_index;
  a2[1] = *v6;
  return 0;
}
