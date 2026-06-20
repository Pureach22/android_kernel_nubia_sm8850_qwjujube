__int64 __fastcall sub_18AE9C(__int64 a1, __int64 _X1)
{
  __asm { STZ2G           X1, [X15,#-0x1E0]! }
  return scheduler_register_hdd_suspend_callback();
}
