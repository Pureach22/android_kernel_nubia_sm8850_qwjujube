__int64 __fastcall mux_div_determine_rate(__int64 a1, _QWORD *a2)
{
  unsigned __int64 v2; // x23
  unsigned int v5; // w21
  unsigned __int64 v6; // x25
  __int64 parent_by_index; // x22
  __int64 v8; // x8
  unsigned int v9; // w27
  unsigned __int64 v10; // x28
  unsigned __int64 v11; // x26
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x8
  bool v18; // cf

  v2 = a2[1];
  if ( !(unsigned int)clk_hw_get_num_parents(a1) )
    return 4294967274LL;
  v5 = 0;
  v6 = 0;
  do
  {
    parent_by_index = clk_hw_get_parent_by_index(a1, v5);
    clk_hw_get_rate(parent_by_index);
    v8 = -1LL << *(_DWORD *)(a1 - 36);
    if ( (unsigned int)v8 <= 0xFFFFFFFD )
    {
      v9 = ~(_DWORD)v8;
      v10 = v2 >> 1;
      v11 = 1;
      do
      {
        v14 = v11 >> 1;
        if ( (v2 & 1) == 0 )
          v14 = 0;
        v15 = clk_hw_round_rate(parent_by_index, v14 + v10);
        v16 = 2 * (v15 % v11) / v11;
        v17 = v16 + 2 * (v15 / v11);
        v18 = v2 > v17 || v17 >= v6;
        if ( !v18 || v6 < v2 && v6 < v17 )
        {
          v6 = v16 + 2 * (v15 / v11);
          a2[1] = v17;
          a2[4] = v15;
          a2[5] = parent_by_index;
        }
        ++v11;
        v10 += v2 >> 1;
      }
      while ( v2 <= v17 && v6 > v2 && (unsigned int)v11 < v9 );
    }
    ++v5;
  }
  while ( v5 < (unsigned int)clk_hw_get_num_parents(a1) );
  if ( v6 )
    return 0;
  else
    return 4294967274LL;
}
