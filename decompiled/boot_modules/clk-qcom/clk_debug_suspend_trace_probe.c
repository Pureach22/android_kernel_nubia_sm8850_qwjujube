void __fastcall clk_debug_suspend_trace_probe(__int64 a1, const char *a2, int a3, char a4)
{
  if ( a3 >= 1 && (a4 & 1) != 0 && (debug_suspend & 1) != 0 && !strcmp("machine_suspend", a2) )
  {
    printk(&unk_2898C);
    clock_debug_print_enabled_clocks(0);
  }
}
