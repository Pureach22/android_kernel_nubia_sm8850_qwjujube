__int64 __fastcall _mux_div_set_rate_and_parent(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v4; // x24
  unsigned __int64 v5; // x27
  __int64 parent_by_index; // x25
  __int64 v7; // x8
  __int64 v8; // x20
  unsigned int v9; // w28
  unsigned __int64 v10; // x26
  unsigned int v11; // w8
  bool v12; // cc
  bool v13; // cf
  unsigned __int64 v14; // x23
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x8
  bool v18; // cf
  __int64 result; // x0
  unsigned int *v20; // [xsp+0h] [xbp-10h]
  int v21; // [xsp+8h] [xbp-8h]
  int v22; // [xsp+Ch] [xbp-4h]

  v20 = (unsigned int *)(a1 - 40);
  if ( (unsigned int)clk_hw_get_num_parents(a1) )
  {
    v4 = 0;
    v5 = 0;
    v22 = 0;
    v21 = 0;
    do
    {
      parent_by_index = clk_hw_get_parent_by_index(a1, (unsigned int)v4);
      clk_hw_get_rate(parent_by_index);
      v7 = -1LL << *(_DWORD *)(a1 - 36);
      if ( (unsigned int)v7 <= 0xFFFFFFFD )
      {
        v8 = 0;
        v9 = ~(_DWORD)v7;
        v10 = a2 >> 1;
        do
        {
          v15 = (unsigned __int64)(v8 + 1) >> 1;
          if ( (a2 & 1) == 0 )
            v15 = 0;
          v16 = clk_hw_round_rate(parent_by_index, v15 + v10);
          v14 = v8 + 1;
          v17 = 2 * (v16 % v14) / v14 + 2 * (v16 / v14);
          v18 = v17 < a2 || v17 >= v5;
          if ( !v18 || v5 < a2 && v5 < v17 )
          {
            v5 = 2 * (v16 % v14) / v14 + 2 * (v16 / v14);
            v21 = v8;
            v22 = *(_DWORD *)(*(_QWORD *)(a1 - 8) + 4 * v4);
          }
          v13 = v17 >= a2;
          v11 = v8++ + 2;
          v12 = v13 && v5 > a2;
          v10 += a2 >> 1;
          v13 = !v12 || v11 >= v9;
        }
        while ( !v13 );
      }
      ++v4;
    }
    while ( v4 < (unsigned int)clk_hw_get_num_parents(a1) );
  }
  else
  {
    v21 = 0;
    v22 = 0;
  }
  result = mux_div_set_src_div(v20, v22, v21);
  if ( !(_DWORD)result )
  {
    *(_DWORD *)(a1 - 20) = v21;
    *(_DWORD *)(a1 - 16) = v22;
  }
  return result;
}
