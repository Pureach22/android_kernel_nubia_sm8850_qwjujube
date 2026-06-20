__int64 __fastcall clk_debug_measure_set(__int64 result, int a2)
{
  __int64 v2; // x19
  _UNKNOWN **v3; // x9
  unsigned int v5; // w20
  __int64 parent_by_index; // x21
  unsigned int v7; // w23
  unsigned int v8; // w20
  __int64 v9; // x21

  if ( result )
  {
    v2 = result;
    v3 = &clk_hw_debug_mux_list;
    do
    {
      v3 = (_UNKNOWN **)*v3;
      if ( v3 == &clk_hw_debug_mux_list )
        return 0;
    }
    while ( v3 - 3 != (_UNKNOWN **)result );
    if ( !(unsigned int)clk_hw_get_num_parents(result) )
      goto LABEL_14;
    v5 = 0;
    while ( 1 )
    {
      if ( (signed int)v5 >= *(_DWORD *)(v2 - 80) || *(_DWORD *)(*(_QWORD *)(v2 - 88) + 4LL * (int)v5) != -559038737 )
      {
        parent_by_index = clk_hw_get_parent_by_index(v2, v5);
        if ( (clk_is_regmap_clk(parent_by_index) & 1) != 0 )
          break;
      }
      if ( ++v5 >= (unsigned int)clk_hw_get_num_parents(v2) )
        goto LABEL_14;
    }
    result = clk_runtime_get_regmap(parent_by_index);
    if ( !(_DWORD)result )
    {
LABEL_14:
      mutex_lock(&clk_debug_lock);
      regmap_update_bits_base(
        *(_QWORD *)(v2 - 56),
        *(unsigned int *)(v2 - 36),
        *(unsigned int *)(v2 - 28),
        (unsigned int)(a2 << *(_DWORD *)(v2 - 24)),
        0,
        0,
        0);
      v7 = clk_set_parent(*(_QWORD *)(v2 + 8), 0);
      if ( v7 )
        printk(&unk_2896D);
      mutex_unlock(&clk_debug_lock);
      if ( (unsigned int)clk_hw_get_num_parents(v2) )
      {
        v8 = 0;
        while ( 1 )
        {
          if ( (signed int)v8 >= *(_DWORD *)(v2 - 80) || *(_DWORD *)(*(_QWORD *)(v2 - 88) + 4LL * (int)v8) != -559038737 )
          {
            v9 = clk_hw_get_parent_by_index(v2, v8);
            if ( (clk_is_regmap_clk(v9) & 1) != 0 )
              break;
          }
          if ( ++v8 >= (unsigned int)clk_hw_get_num_parents(v2) )
            return v7;
        }
        clk_runtime_put_regmap(v9);
      }
      return v7;
    }
  }
  return result;
}
