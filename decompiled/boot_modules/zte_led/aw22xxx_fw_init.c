__int64 __fastcall aw22xxx_fw_init(_QWORD *a1)
{
  bool v2; // zf

  hrtimer_init(a1 + 78, 1, 1);
  a1[83] = aw22xxx_fw_timer_func;
  a1[66] = 0xFFFFFFFE00000LL;
  a1[67] = a1 + 67;
  a1[68] = a1 + 67;
  a1[69] = aw22xxx_fw_work_routine;
  a1[70] = 0xFFFFFFFE00000LL;
  a1[71] = a1 + 71;
  a1[72] = a1 + 71;
  v2 = g_ver_var == 11;
  a1[73] = aw22xxx_cfg_work_routine;
  if ( v2 )
  {
    a1[74] = 0xFFFFFFFE00000LL;
    a1[75] = a1 + 75;
    a1[76] = a1 + 75;
    a1[77] = aw22xxx_recover_work_routine;
  }
  printk(&unk_12C70, "aw22xxx_fw_init");
  return hrtimer_start_range_ns(a1 + 78, 1000000000, 0, 1);
}
