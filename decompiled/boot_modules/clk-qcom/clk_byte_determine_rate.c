__int64 __fastcall clk_byte_determine_rate(__int64 a1, _QWORD *a2)
{
  unsigned int src_index; // w0
  char v5; // w21
  __int64 parent_by_index; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  int v10; // w8
  unsigned int v11; // w8

  src_index = qcom_find_src_index(a1, *(_QWORD *)(a1 - 40), *(unsigned __int8 *)(*(_QWORD *)(a1 - 8) + 8LL));
  if ( a2[1]
    && (v5 = *(_BYTE *)(a1 - 43),
        parent_by_index = clk_hw_get_parent_by_index(a1, src_index),
        (a2[5] = parent_by_index) != 0) )
  {
    v7 = clk_hw_round_rate(parent_by_index, a2[1]);
    v8 = a2[1];
    a2[4] = v7;
    v9 = (v8 + 2 * v7 - 1) / v8;
    if ( (unsigned int)(-1LL << v5) <= -(int)v9 )
      v10 = -(int)v9;
    else
      v10 = -1LL << v5;
    if ( v10 != -1 )
      v7 = 2 * (v7 % (unsigned int)-v10) / (unsigned int)-v10 + 2 * (v7 / (unsigned int)-v10);
    v11 = 0;
    a2[1] = v7;
  }
  else
  {
    return (unsigned int)-22;
  }
  return v11;
}
