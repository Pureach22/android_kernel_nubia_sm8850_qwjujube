__int64 __fastcall aw22xxx_fw_timer_func(__int64 a1)
{
  printk(&unk_130E1, "aw22xxx_fw_timer_func");
  queue_work_on(32, system_wq, a1 - 96);
  return 0;
}
