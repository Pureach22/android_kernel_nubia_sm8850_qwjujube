__int64 clock_debug_trace()
{
  _QWORD *v0; // x24
  unsigned int rate; // w0
  __int64 v2; // x22
  unsigned int v3; // w21
  __int64 v4; // x0

  mutex_lock(&clk_debug_lock);
  v0 = clk_hw_debug_list;
  if ( clk_hw_debug_list != (_UNKNOWN *)&clk_hw_debug_list )
  {
    _ReadStatusReg(SP_EL0);
    do
    {
      clk_hw_is_enabled(v0[2]);
      clk_hw_is_prepared(v0[2]);
      rate = clk_hw_get_rate(v0[2]);
      v2 = v0[2];
      v3 = rate;
      if ( (clk_is_regmap_clk(v2) & 1) != 0 && *(_QWORD *)(v2 + 48) )
        clk_find_vdd_level(v2, v2 + 48, v3);
      v4 = v0[2];
      if ( !*(_QWORD *)(v4 + 16) )
        clk_hw_get_name(v4);
      v0 = (_QWORD *)*v0;
    }
    while ( v0 != &clk_hw_debug_list );
  }
  mutex_unlock(&clk_debug_lock);
  return 0;
}
