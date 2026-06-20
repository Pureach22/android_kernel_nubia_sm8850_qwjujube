__int64 __fastcall clk_common_debug_init(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 result; // x0

  if ( *(_QWORD *)(a1 + 64) )
    debugfs_create_file("clk_rate_max", 292, a2, a1, &rate_max_fops);
  v4 = *(_QWORD *)(a1 + 88);
  if ( v4 && *(_QWORD *)(v4 + 8) )
    debugfs_create_file("clk_list_rates", 292, a2, a1, &list_rates_fops);
  result = debugfs_create_file("clk_print_regs", 292, a2, a1, &clock_print_hw_fops);
  if ( (qcom_clk_debug_inited & 1) == 0 )
  {
    result = clk_debug_init(result);
    qcom_clk_debug_inited = 1;
  }
  return result;
}
