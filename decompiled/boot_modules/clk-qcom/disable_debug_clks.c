__int64 __fastcall disable_debug_clks(__int64 result)
{
  __int64 v1; // x19
  _UNKNOWN **v2; // x9
  unsigned int v3; // w20
  __int64 parent_by_index; // x21
  unsigned int v5; // w8
  __int64 v6; // x1
  __int64 v7; // x2
  unsigned int v8; // w20
  __int64 v9; // x21
  __int64 parent; // x0

  if ( result )
  {
    v1 = result;
    v2 = &clk_hw_debug_mux_list;
    while ( 1 )
    {
      v2 = (_UNKNOWN **)*v2;
      if ( v2 == &clk_hw_debug_mux_list )
        break;
      if ( v2 - 3 == (_UNKNOWN **)result )
      {
        if ( !(unsigned int)clk_hw_get_num_parents(result) )
          goto LABEL_13;
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
            goto LABEL_13;
        }
        result = clk_runtime_get_regmap(parent_by_index);
        if ( !(_DWORD)result )
        {
LABEL_13:
          v5 = *(_DWORD *)(v1 - 40);
          v6 = *(unsigned int *)(v1 - 32);
          if ( v5 <= 1 )
            v7 = 1;
          else
            v7 = v5;
          *(_DWORD *)(v1 - 40) = v7;
          if ( (_DWORD)v6 != -1 )
            regmap_update_bits_base(*(_QWORD *)(v1 - 56), v6, v7, 0, 0, 0, 0);
          if ( (unsigned int)clk_hw_get_num_parents(v1) )
          {
            v8 = 0;
            while ( 1 )
            {
              if ( (signed int)v8 >= *(_DWORD *)(v1 - 80)
                || *(_DWORD *)(*(_QWORD *)(v1 - 88) + 4LL * (int)v8) != -559038737 )
              {
                v9 = clk_hw_get_parent_by_index(v1, v8);
                if ( (clk_is_regmap_clk(v9) & 1) != 0 )
                  break;
              }
              if ( ++v8 >= (unsigned int)clk_hw_get_num_parents(v1) )
                goto LABEL_26;
            }
            clk_runtime_put_regmap(v9);
          }
LABEL_26:
          parent = clk_hw_get_parent(v1);
          return disable_debug_clks(parent);
        }
        return result;
      }
    }
  }
  return result;
}
