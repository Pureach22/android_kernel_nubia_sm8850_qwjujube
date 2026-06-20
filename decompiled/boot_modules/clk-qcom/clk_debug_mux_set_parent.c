__int64 __fastcall clk_debug_mux_set_parent(__int64 a1, unsigned __int8 a2)
{
  unsigned int v4; // w21
  __int64 parent_by_index; // x22
  __int64 result; // x0
  unsigned int updated; // w0
  __int64 v8; // x1
  unsigned int v9; // w22
  unsigned int v10; // w20
  __int64 v11; // x21

  if ( !*(_QWORD *)(a1 - 88) )
    return 0;
  if ( !(unsigned int)((__int64 (*)(void))clk_hw_get_num_parents)() )
    goto LABEL_11;
  v4 = 0;
  while ( 1 )
  {
    if ( (signed int)v4 >= *(_DWORD *)(a1 - 80) || *(_DWORD *)(*(_QWORD *)(a1 - 88) + 4LL * (int)v4) != -559038737 )
    {
      parent_by_index = clk_hw_get_parent_by_index(a1, v4);
      if ( (clk_is_regmap_clk() & 1) != 0 )
        break;
    }
    if ( ++v4 >= (unsigned int)clk_hw_get_num_parents(a1) )
      goto LABEL_11;
  }
  result = clk_runtime_get_regmap(parent_by_index);
  if ( !(_DWORD)result )
  {
LABEL_11:
    updated = regmap_update_bits_base(
                *(_QWORD *)(a1 - 56),
                *(unsigned int *)(a1 - 36),
                *(unsigned int *)(a1 - 28),
                (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 - 88) + 4LL * a2) << *(_DWORD *)(a1 - 24)),
                0,
                0,
                0);
    if ( !updated )
    {
      v8 = *(unsigned int *)(a1 - 20);
      if ( (_DWORD)v8 == -1 )
        updated = 0;
      else
        updated = regmap_update_bits_base(
                    *(_QWORD *)(a1 - 56),
                    v8,
                    *(unsigned int *)(a1 - 16),
                    (unsigned int)((*(_DWORD *)(a1 - 8) - 1) << *(_DWORD *)(a1 - 12)),
                    0,
                    0,
                    0);
    }
    v9 = updated;
    if ( (unsigned int)clk_hw_get_num_parents(a1) )
    {
      v10 = 0;
      while ( 1 )
      {
        if ( (signed int)v10 >= *(_DWORD *)(a1 - 80) || *(_DWORD *)(*(_QWORD *)(a1 - 88) + 4LL * (int)v10) != -559038737 )
        {
          v11 = clk_hw_get_parent_by_index(a1, v10);
          if ( (clk_is_regmap_clk() & 1) != 0 )
            break;
        }
        if ( ++v10 >= (unsigned int)clk_hw_get_num_parents(a1) )
          return v9;
      }
      clk_runtime_put_regmap(v11);
    }
    return v9;
  }
  return result;
}
