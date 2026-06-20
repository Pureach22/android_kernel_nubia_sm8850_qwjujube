__int64 __fastcall clk_debug_measure_register(__int64 a1)
{
  _UNKNOWN **v2; // x10

  if ( measure && (unsigned __int64)measure < 0xFFFFFFFFFFFFF001LL )
    return 0;
  if ( a1 )
  {
    v2 = &clk_hw_debug_mux_list;
    while ( 1 )
    {
      v2 = (_UNKNOWN **)*v2;
      if ( v2 == &clk_hw_debug_mux_list )
        break;
      if ( v2 - 3 == (_UNKNOWN **)a1 )
      {
        measure = a1;
        return 0;
      }
    }
  }
  return 4294967274LL;
}
