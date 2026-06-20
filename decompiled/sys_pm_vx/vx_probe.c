unsigned __int64 __fastcall vx_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned __int64 result; // x0
  __int64 matched; // x0
  __int64 v6; // x8
  int v7; // w10
  int v8; // w9
  int v10; // w9
  int v11; // w10
  __int64 dir; // x0
  __int64 v13; // x21
  __int64 file; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned __int64 v17; // x0
  unsigned __int64 v18; // x21

  v2 = devm_kmalloc(a1 + 16, 144, 3520);
  g_pd = v2;
  if ( !v2 )
    return 4294967284LL;
  v3 = v2;
  result = of_iomap(*(_QWORD *)(a1 + 760), 0);
  *(_QWORD *)v3 = result;
  if ( result && result < 0xFFFFFFFFFFFFF001LL )
  {
    matched = of_match_node(&drv_match_table, *(_QWORD *)(a1 + 760));
    if ( matched )
    {
      v6 = *(_QWORD *)(matched + 192);
      v7 = 0;
      do
        v8 = v7;
      while ( **(_BYTE **)(v6 + 8LL * v7++) );
      *(_QWORD *)(v3 + 32) = v6;
      *(_QWORD *)(v3 + 16) = v8;
      v10 = -1;
      do
      {
        v11 = v10 + 30;
        ++v10;
      }
      while ( **(_BYTE **)(v6 + 8LL * v11) );
      *(_QWORD *)(v3 + 40) = v6 + 232;
      *(_QWORD *)(v3 + 24) = v10;
      dir = debugfs_create_dir("sys_pm_vx", 0);
      *(_QWORD *)(v3 + 8) = dir;
      if ( dir )
      {
        v13 = dir;
        debugfs_create_file("sys_pm_violators", 256, dir, v3, &sys_pm_vx_fops);
        debugfs_create_file("trigger_dump", 384, v13, v3, &trigger_dump_enable_fops);
        file = device_create_file(a1 + 16, &dev_attr_debug_time_ms);
        if ( (_DWORD)file )
        {
          v18 = file;
          dev_err(a1 + 16, "failed: create sys pm vx sysfs debug time entry\n");
          goto LABEL_17;
        }
        v15 = device_create_file(a1 + 16, &dev_attr_debug_enable);
        if ( (_DWORD)v15 )
        {
          v18 = v15;
          dev_err(a1 + 16, "failed: create sys pm vx sysfs debug enable entry\n");
          goto LABEL_16;
        }
        v16 = device_create_file(a1 + 16, &dev_attr_set_timer_ms);
        if ( (_DWORD)v16 )
        {
          v18 = v16;
          dev_err(a1 + 16, "failed: create sys pm vx sysfs set timer_ms entry\n");
          goto LABEL_15;
        }
        v17 = qmp_get(a1 + 16);
        *(_QWORD *)(v3 + 96) = v17;
        if ( v17 >= 0xFFFFFFFFFFFFF001LL )
        {
          v18 = v17;
          device_remove_file(a1 + 16, &dev_attr_set_timer_ms);
LABEL_15:
          device_remove_file(a1 + 16, &dev_attr_debug_enable);
LABEL_16:
          device_remove_file(a1 + 16, &dev_attr_debug_time_ms);
LABEL_17:
          debugfs_remove(*(_QWORD *)(v3 + 8));
          return v18;
        }
        _mutex_init(v3 + 48, "&pd->lock", &vx_probe___key);
        result = 0;
        *(_BYTE *)(v3 + 120) = 0;
        *(_DWORD *)(v3 + 132) = 0;
        *(_QWORD *)(v3 + 124) = 21474836490000LL;
        *(_BYTE *)(v3 + 136) = 0;
        *(_QWORD *)(a1 + 168) = v3;
      }
      else
      {
        return 4294967274LL;
      }
    }
    else
    {
      return 4294967277LL;
    }
  }
  return result;
}
