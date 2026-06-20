unsigned __int64 __fastcall devm_clk_register_debug_mux(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // x0
  _UNKNOWN **v4; // x0
  void *v5; // x2

  if ( !a2 )
    return 4294967274LL;
  result = devm_clk_register(a1, a2 + 88);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    mutex_lock(&clk_debug_lock);
    v4 = (_UNKNOWN **)(a2 + 112);
    v5 = clk_hw_debug_mux_list;
    if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)clk_hw_debug_mux_list) != &clk_hw_debug_mux_list
      || v4 == &clk_hw_debug_mux_list
      || clk_hw_debug_mux_list == (_UNKNOWN *)v4 )
    {
      _list_add_valid_or_report(v4, &clk_hw_debug_mux_list);
    }
    else
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)clk_hw_debug_mux_list) = v4;
      *(_QWORD *)(a2 + 112) = v5;
      *(_QWORD *)(a2 + 120) = &clk_hw_debug_mux_list;
      clk_hw_debug_mux_list = (_UNKNOWN *)(a2 + 112);
    }
    mutex_unlock(&clk_debug_lock);
    return 0;
  }
  return result;
}
