__int64 __fastcall tpd_probe_work_deinit(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19

  v3 = tpd_cdev;
  printk(unk_322AA, "tpd_probe_work_deinit", a3);
  return cancel_delayed_work_sync(v3 + 2256);
}
