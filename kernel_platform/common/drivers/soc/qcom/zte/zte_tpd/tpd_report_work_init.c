__int64 __fastcall tpd_report_work_init(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x20
  __int64 v4; // x0
  __int64 v5; // x2

  v3 = (_QWORD *)tpd_cdev;
  printk(unk_322AA, "tpd_report_work_init", a3);
  v4 = alloc_workqueue(unk_364AC, 393226, 1, "tpd_report_wq");
  v3[151] = v4;
  if ( v4 )
  {
    v3[152] = 0xFFFFFFFE00000LL;
    v3[153] = v3 + 153;
    v3[154] = v3 + 153;
    v3[155] = tpd_id0_report_work;
    init_timer_key(v3 + 156, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3[165] = 0xFFFFFFFE00000LL;
    v3[166] = v3 + 166;
    v3[167] = v3 + 166;
    v3[168] = tpd_id1_report_work;
    init_timer_key(v3 + 169, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3[178] = 0xFFFFFFFE00000LL;
    v3[179] = v3 + 179;
    v3[180] = v3 + 179;
    v3[181] = tpd_id2_report_work;
    init_timer_key(v3 + 182, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3[191] = 0xFFFFFFFE00000LL;
    v3[192] = v3 + 192;
    v3[193] = v3 + 192;
    v3[194] = tpd_id3_report_work;
    init_timer_key(v3 + 195, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3[204] = 0xFFFFFFFE00000LL;
    v3[205] = v3 + 205;
    v3[206] = v3 + 205;
    v3[207] = tpd_id4_report_work;
    init_timer_key(v3 + 208, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3[217] = 0xFFFFFFFE00000LL;
    v3[218] = v3 + 218;
    v3[219] = v3 + 218;
    v3[220] = tpd_id5_report_work;
    init_timer_key(v3 + 221, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3[230] = 0xFFFFFFFE00000LL;
    v3[231] = v3 + 231;
    v3[232] = v3 + 231;
    v3[233] = tpd_id6_report_work;
    init_timer_key(v3 + 234, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3[243] = 0xFFFFFFFE00000LL;
    v3[244] = v3 + 244;
    v3[245] = v3 + 244;
    v3[246] = tpd_id7_report_work;
    init_timer_key(v3 + 247, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3[256] = 0xFFFFFFFE00000LL;
    v3[257] = v3 + 257;
    v3[258] = v3 + 257;
    v3[259] = tpd_id8_report_work;
    init_timer_key(v3 + 260, &delayed_work_timer_fn, 0x200000, 0, 0);
    v3[269] = 0xFFFFFFFE00000LL;
    v3[270] = v3 + 270;
    v3[271] = v3 + 270;
    v3[272] = tpd_id9_report_work;
    init_timer_key(v3 + 273, &delayed_work_timer_fn, 0x200000, 0, 0);
    return 0;
  }
  else
  {
    printk(unk_334E1, "tpd_report_work_init", v5);
    return 4294967284LL;
  }
}
