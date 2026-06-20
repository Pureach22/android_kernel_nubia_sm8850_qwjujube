__int64 __fastcall tpd_resume_work_init(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x19

  v3 = (_QWORD *)tpd_cdev;
  printk(&unk_322AA, "tpd_resume_work_init", a3);
  v3[312] = 0xFFFFFFFE00000LL;
  v3[313] = v3 + 313;
  v3[314] = v3 + 313;
  v3[315] = tpd_resume_work;
  v3[308] = 0xFFFFFFFE00000LL;
  v3[309] = v3 + 309;
  v3[310] = v3 + 309;
  v3[316] = 0xFFFFFFFE00000LL;
  v3[311] = tpd_suspend_work;
  v3[317] = v3 + 317;
  v3[318] = v3 + 317;
  v3[319] = ufp_report_lcd_state_work;
  return init_timer_key(v3 + 320, &delayed_work_timer_fn, 0x200000, 0, 0);
}
