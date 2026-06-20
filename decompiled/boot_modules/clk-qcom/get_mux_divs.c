__int64 __fastcall get_mux_divs(__int64 a1)
{
  _UNKNOWN **v1; // x9
  int v2; // w20
  __int64 v3; // x19
  unsigned __int8 parent; // w8
  __int64 v5; // x0

  if ( !a1 )
    return 1;
  v1 = &clk_hw_debug_mux_list;
  while ( 1 )
  {
    v1 = (_UNKNOWN **)*v1;
    if ( v1 == &clk_hw_debug_mux_list )
      return 1;
    if ( v1 - 3 == (_UNKNOWN **)a1 )
    {
      v2 = *(_DWORD *)(a1 - 8);
      if ( v2 )
      {
        if ( *(_QWORD *)(a1 - 72) )
          goto LABEL_7;
      }
      else
      {
        __break(0x800u);
        v2 = *(_DWORD *)(a1 - 8);
        if ( *(_QWORD *)(a1 - 72) )
        {
LABEL_7:
          v3 = a1;
          parent = clk_debug_mux_get_parent(a1);
          a1 = v3;
          v2 *= *(_DWORD *)(*(_QWORD *)(v3 - 72) + 4LL * parent);
        }
      }
      v5 = clk_hw_get_parent(a1);
      return (unsigned int)get_mux_divs(v5) * v2;
    }
  }
}
