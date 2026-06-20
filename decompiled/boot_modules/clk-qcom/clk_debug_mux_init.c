__int64 __fastcall clk_debug_mux_init(__int64 a1)
{
  unsigned __int64 v2; // x20

  if ( (unsigned int)clk_hw_get_num_parents(a1) )
  {
    v2 = 0;
    do
    {
      if ( !clk_hw_get_parent_by_index(a1, (unsigned int)v2) && v2 < *(unsigned int *)(a1 - 80) )
        *(_DWORD *)(*(_QWORD *)(a1 - 88) + 4 * v2) = -559038737;
      ++v2;
    }
    while ( v2 < (unsigned int)clk_hw_get_num_parents(a1) );
  }
  return 0;
}
