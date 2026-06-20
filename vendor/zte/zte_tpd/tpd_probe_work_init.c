__int64 __fastcall tpd_probe_work_init(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x19

  v3 = (_QWORD *)tpd_cdev;
  printk(unk_322AA, "tpd_probe_work_init", a3);
  v3[282] = 0xFFFFFFFE00000LL;
  v3[283] = v3 + 283;
  v3[284] = v3 + 283;
  v3[285] = ztp_probe_work;
  init_timer_key(v3 + 286, &delayed_work_timer_fn, 0x200000, 0, 0);
  return 0;
}
