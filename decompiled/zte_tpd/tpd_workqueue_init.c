__int64 __fastcall tpd_workqueue_init(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x20
  __int64 v4; // x0
  __int64 v5; // x2
  _QWORD *v7; // x21
  __int64 inited; // x0

  v3 = (_QWORD *)tpd_cdev;
  printk(&unk_3649F, a2, a3);
  v4 = alloc_workqueue(&unk_364AC, 393226, 1, "tpd_wq");
  v3[150] = v4;
  if ( !v4 )
    goto LABEL_2;
  if ( (unsigned int)tpd_report_work_init() )
  {
    if ( !v3[150] )
      destroy_workqueue(0);
LABEL_2:
    printk(&unk_38BD5, "tpd_workqueue_init", v5);
    return 4294967284LL;
  }
  v7 = (_QWORD *)tpd_cdev;
  printk(&unk_322AA, "tpd_probe_work_init", v5);
  v7[282] = 0xFFFFFFFE00000LL;
  v7[283] = v7 + 283;
  v7[284] = v7 + 283;
  v7[285] = ztp_probe_work;
  inited = init_timer_key(v7 + 286, &delayed_work_timer_fn, 0x200000, 0, 0);
  tpd_resume_work_init(inited);
  v3[295] = 0xFFFFFFFE00000LL;
  v3[296] = v3 + 296;
  v3[297] = v3 + 296;
  v3[298] = tp_ghost_check_work;
  init_timer_key(v3 + 299, &delayed_work_timer_fn, 0x200000, 0, 0);
  return 0;
}
