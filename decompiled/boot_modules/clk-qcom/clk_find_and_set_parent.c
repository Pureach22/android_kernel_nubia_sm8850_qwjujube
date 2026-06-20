__int64 __fastcall clk_find_and_set_parent(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _UNKNOWN **v5; // x9
  unsigned int v6; // w21
  __int64 parent_by_index; // x22

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = &clk_hw_debug_mux_list;
    do
    {
      v5 = (_UNKNOWN **)*v5;
      if ( v5 == &clk_hw_debug_mux_list )
        return 4294967274LL;
    }
    while ( v5 - 3 != (_UNKNOWN **)a1 );
    if ( a1 == a2 )
    {
      return 0;
    }
    else
    {
      result = clk_set_parent(*(_QWORD *)(a1 + 8), *(_QWORD *)(a2 + 8));
      if ( !(_DWORD)result )
        return result;
      if ( !(unsigned int)clk_hw_get_num_parents(a1) )
        return 4294967274LL;
      v6 = 0;
      while ( 1 )
      {
        if ( (signed int)v6 >= *(_DWORD *)(a1 - 80) || *(_DWORD *)(*(_QWORD *)(a1 - 88) + 4LL * (int)v6) != -559038737 )
        {
          parent_by_index = clk_hw_get_parent_by_index(a1, v6);
          if ( !(unsigned int)clk_find_and_set_parent(parent_by_index, a2) )
            break;
        }
        if ( ++v6 >= (unsigned int)clk_hw_get_num_parents(a1) )
          return 4294967274LL;
      }
      return clk_set_parent(*(_QWORD *)(a1 + 8), *(_QWORD *)(parent_by_index + 8));
    }
  }
  return result;
}
