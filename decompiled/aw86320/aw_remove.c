__int64 __fastcall aw_remove(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x19

  v7 = *(_QWORD *)(a1 + 184);
  printk(&unk_9B44, "aw86320", 1154, "aw_remove", a5, a6, a7);
  remove_proc_entry("enable", micro_pump_proc_entry);
  remove_proc_entry("speed", micro_pump_proc_entry);
  remove_proc_entry("freq", micro_pump_proc_entry);
  remove_proc_entry("reg", micro_pump_proc_entry);
  remove_proc_entry("update", micro_pump_proc_entry);
  remove_proc_entry("time", micro_pump_proc_entry);
  remove_proc_entry("driver/micropump", 0);
  cancel_delayed_work_sync(v7 + 608);
  return cancel_delayed_work_sync(v7 + 712);
}
