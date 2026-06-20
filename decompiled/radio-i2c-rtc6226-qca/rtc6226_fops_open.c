__int64 rtc6226_fops_open()
{
  __int64 v0; // x1
  __int64 v1; // x19
  int v2; // w0
  unsigned int v3; // w0
  unsigned int v4; // w20
  int v6; // w20
  unsigned int v13; // w8
  unsigned int v14; // w8
  unsigned int v17; // w10
  unsigned int v20; // w10

  v1 = *(_QWORD *)(video_devdata() + 336);
  _X9 = (unsigned int *)(v1 + 1752);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v13 = __ldxr(_X9);
    v14 = v13 + 1;
  }
  while ( __stlxr(v14, _X9) );
  __dmb(0xBu);
  if ( v14 != 1 )
  {
    printk(&unk_D357, v0);
    _X8 = (unsigned int *)(v1 + 1752);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 - 1, _X8) );
    return 4294967280LL;
  }
  *(_QWORD *)(v1 + 2312) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v1 + 2320) = v1 + 2320;
  *(_QWORD *)(v1 + 2328) = v1 + 2320;
  *(_QWORD *)(v1 + 2336) = rtc6226_handler;
  init_timer_key(v1 + 2344, &delayed_work_timer_fn, 0x200000, 0, 0);
  *(_QWORD *)(v1 + 2416) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v1 + 2424) = v1 + 2424;
  *(_QWORD *)(v1 + 2432) = v1 + 2424;
  *(_QWORD *)(v1 + 2440) = rtc6226_scan;
  init_timer_key(v1 + 2448, &delayed_work_timer_fn, 0x200000, 0, 0);
  *(_QWORD *)(v1 + 2056) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v1 + 2064) = v1 + 2064;
  *(_QWORD *)(v1 + 2072) = v1 + 2064;
  *(_QWORD *)(v1 + 2080) = rtc6226_rds_handler;
  v2 = rtc6226_fm_vdd_reg_cfg(v1, 1);
  if ( v2 < 0 )
  {
    v6 = v2;
    printk(&unk_D5E4, "rtc6226_fm_power_cfg");
LABEL_9:
    v3 = v6;
    goto LABEL_10;
  }
  v3 = rtc6226_fm_vio_reg_cfg(v1, 1);
  if ( (v3 & 0x80000000) != 0 )
  {
    v6 = v3;
    printk(&unk_CC71, "rtc6226_fm_power_cfg");
    rtc6226_fm_vdd_reg_cfg(v1, 0);
    goto LABEL_9;
  }
  if ( !v3 )
  {
    v4 = rtc6226_enable_irq((unsigned int *)v1);
    msleep(100);
    if ( !v4 )
      return 0;
    printk(&unk_CBDA, "rtc6226_fops_open");
    if ( (rtc6226_fm_vdd_reg_cfg(v1, 0) & 0x80000000) != 0 )
      printk(&unk_D5E4, "rtc6226_fm_power_cfg");
    if ( (rtc6226_fm_vio_reg_cfg(v1, 0) & 0x80000000) != 0 )
      printk(&unk_CC71, "rtc6226_fm_power_cfg");
    goto LABEL_18;
  }
LABEL_10:
  v4 = v3;
  printk(&unk_D6DC, "rtc6226_fops_open");
LABEL_18:
  _X8 = (unsigned int *)(v1 + 1752);
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stxr(v17 - 1, _X8) );
  return v4;
}
