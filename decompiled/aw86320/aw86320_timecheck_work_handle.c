__int64 __fastcall aw86320_timecheck_work_handle(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x19

  v7 = g_aw86320;
  *(_DWORD *)(g_aw86320 + 16) = 0;
  printk(&unk_96DB, "aw86320", 514, "aw86320_timecheck_work_handle", a5, a6, a7);
  return haptic_i2c_write(v7, 37, 0);
}
