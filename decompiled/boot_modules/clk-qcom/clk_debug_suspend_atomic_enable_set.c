__int64 __fastcall clk_debug_suspend_atomic_enable_set(__int64 a1, __int64 a2)
{
  debug_suspend_atomic = a2 != 0;
  return 0;
}
