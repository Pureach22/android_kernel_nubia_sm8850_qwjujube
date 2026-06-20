__int64 __fastcall clk_debug_measure_add(__int64 a1, __int64 a2)
{
  return debugfs_create_file("clk_measure", 292, a2, a1, &clk_measure_fops);
}
