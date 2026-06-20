__int64 __fastcall clk_debug_suspend_enable_set(__int64 a1, __int64 a2)
{
  if ( debug_suspend != (a2 != 0) )
    debug_suspend = a2 != 0;
  return 0;
}
