__int64 __fastcall enabled_clocks_show(__int64 a1)
{
  mutex_lock(&clk_debug_lock);
  clock_debug_print_enabled_clocks(a1);
  mutex_unlock(&clk_debug_lock);
  return 0;
}
