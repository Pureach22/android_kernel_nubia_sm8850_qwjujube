__int64 __fastcall aw882xx_monitor_init(__int64 a1)
{
  __int64 **v1; // x21
  __int64 *v3; // x8
  __int64 v4; // x1
  __int64 *v5; // x8
  __int64 v6; // x1
  const char *v7; // x20
  __int64 v8; // x1
  __int64 result; // x0
  __int64 v10; // x1
  char *s1[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = (__int64 **)(a1 - 560);
  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(__int64 **)(a1 - 560);
  v4 = v3[14];
  if ( !v4 )
    v4 = *v3;
  printk(&unk_26EB3, v4, "aw882xx_monitor_init");
  v5 = *v1;
  s1[0] = nullptr;
  if ( (of_property_read_string(v5[93], "monitor-mode", s1) & 0x80000000) != 0 )
  {
    v6 = (*v1)[14];
    if ( !v6 )
      v6 = **v1;
    printk(&unk_28695, v6, "aw_monitor_parse_mode");
  }
  else
  {
    v7 = s1[0];
    *(_BYTE *)(a1 + 204) = strcmp(s1[0], "kernel_monitor") && !strcmp(v7, "hal_monitor");
    v8 = (*v1)[14];
    if ( !v8 )
      v8 = **v1;
    printk(&unk_25F99, v8, "aw_monitor_parse_mode");
  }
  *(_QWORD *)a1 = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 8) = a1 + 8;
  *(_QWORD *)(a1 + 16) = a1 + 8;
  *(_QWORD *)(a1 + 24) = aw_monitor_work_func;
  init_timer_key(a1 + 32, &delayed_work_timer_fn, 0x200000, 0, 0);
  result = sysfs_create_group(*v1, &aw_monitor_attr_group);
  if ( (result & 0x80000000) != 0 )
  {
    v10 = (*v1)[14];
    if ( !v10 )
      v10 = **v1;
    result = printk(&unk_230C2, v10, "aw882xx_monitor_init");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
