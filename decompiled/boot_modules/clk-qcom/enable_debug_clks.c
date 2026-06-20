__int64 __fastcall enable_debug_clks(__int64 result)
{
  __int64 v1; // x19
  _UNKNOWN **v2; // x9
  unsigned int v3; // w20
  __int64 parent_by_index; // x21
  __int64 parent; // x0
  unsigned int v6; // w23
  unsigned int v7; // w8
  __int64 v8; // x1
  __int64 v9; // x2
  unsigned int v10; // w20
  __int64 v11; // x21

  if ( result )
  {
    v1 = result;
    v2 = &clk_hw_debug_mux_list;
    do
    {
      v2 = (_UNKNOWN **)*v2;
      if ( v2 == &clk_hw_debug_mux_list )
        return 0;
    }
    while ( v2 - 3 != (_UNKNOWN **)result );
    if ( !(unsigned int)clk_hw_get_num_parents(result) )
      goto LABEL_14;
    v3 = 0;
    while ( 1 )
    {
      if ( (signed int)v3 >= *(_DWORD *)(v1 - 80) || *(_DWORD *)(*(_QWORD *)(v1 - 88) + 4LL * (int)v3) != -559038737 )
      {
        parent_by_index = clk_hw_get_parent_by_index(v1, v3);
        if ( (clk_is_regmap_clk(parent_by_index) & 1) != 0 )
          break;
      }
      if ( ++v3 >= (unsigned int)clk_hw_get_num_parents(v1) )
        goto LABEL_14;
    }
    result = clk_runtime_get_regmap(parent_by_index);
    if ( !(_DWORD)result )
    {
LABEL_14:
      parent = clk_hw_get_parent(v1);
      v6 = enable_debug_clks(parent);
      if ( !v6 )
      {
        v7 = *(_DWORD *)(v1 - 40);
        v8 = *(unsigned int *)(v1 - 32);
        v9 = v7 <= 1 ? 1LL : v7;
        *(_DWORD *)(v1 - 40) = v9;
        if ( (_DWORD)v8 != -1 )
          regmap_update_bits_base(*(_QWORD *)(v1 - 56), v8, v9, (unsigned int)v9, 0, 0, 0);
      }
      if ( (unsigned int)clk_hw_get_num_parents(v1) )
      {
        v10 = 0;
        while ( 1 )
        {
          if ( (signed int)v10 >= *(_DWORD *)(v1 - 80)
            || *(_DWORD *)(*(_QWORD *)(v1 - 88) + 4LL * (int)v10) != -559038737 )
          {
            v11 = clk_hw_get_parent_by_index(v1, v10);
            if ( (clk_is_regmap_clk(v11) & 1) != 0 )
              break;
          }
          if ( ++v10 >= (unsigned int)clk_hw_get_num_parents(v1) )
            return v6;
        }
        clk_runtime_put_regmap(v11);
      }
      return v6;
    }
  }
  return result;
}
