__int64 __fastcall msm_mmrm_probe(__int64 a1)
{
  int v2; // w0
  int v3; // w9
  unsigned __int64 v4; // x0
  __int64 v5; // x1
  unsigned int v6; // w0
  unsigned int v7; // w19
  __int64 result; // x0
  unsigned int v9; // w0
  unsigned int v10; // w19

  if ( (~msm_mmrm_debug & 0x10002) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_24:
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      printk(&unk_C50C, "err ", "msm_mmrm_probe");
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_DA62, "err ", "msm_mmrm_probe");
    }
    return 4294967274LL;
  }
  printk(&unk_DA4D, "high", "msm_mmrm_probe");
  if ( !a1 )
    goto LABEL_24;
LABEL_3:
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,msm-mmrm") )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_D4BC, "err ", "msm_mmrm_probe");
    return 4294967274LL;
  }
  drv_data = _kmalloc_cache_noprof(mutex_unlock, 3520, 120);
  if ( !drv_data )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_D4EC, "err ", "msm_mmrm_probe_init");
    result = 4294967284LL;
    goto LABEL_35;
  }
  v2 = mmrm_count_clk_clients_frm_dt(a1);
  v3 = msm_mmrm_debug & 0x10002;
  if ( v2 )
  {
    if ( v3 == 65538 )
      printk(&unk_CB98, "high", "msm_mmrm_probe_init");
    *(_BYTE *)(drv_data + 8) = 1;
    *(_QWORD *)drv_data = mmrm_get_platform_data(a1 + 16);
    if ( !*(_QWORD *)drv_data )
    {
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_CD60, "err ", "msm_mmrm_probe_init");
      v7 = -22;
      goto LABEL_34;
    }
    v4 = msm_mmrm_debugfs_init();
    v5 = drv_data;
    *(_QWORD *)(drv_data + 112) = v4;
    if ( !v4 && (~msm_mmrm_debug & 0x10001) == 0 )
    {
      printk(&unk_CBDB, "err ", "msm_mmrm_probe_init");
      v5 = drv_data;
    }
    *(_QWORD *)(a1 + 168) = v5;
    v6 = ((__int64 (__fastcall *)(__int64))mmrm_read_platform_resources)(a1);
    if ( v6 )
    {
      v7 = v6;
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_D0C0, "err ", "msm_mmrm_probe_init");
LABEL_33:
      mmrm_free_platform_resources(drv_data);
LABEL_34:
      kfree(drv_data);
      result = v7;
      drv_data = -517;
LABEL_35:
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
      {
        v10 = result;
        printk(&unk_DA62, "err ", "msm_mmrm_probe_init");
        return v10;
      }
      return result;
    }
    v9 = mmrm_init(drv_data);
    if ( v9 )
    {
      v7 = v9;
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_D43D, "err ", "msm_mmrm_probe_init");
      msm_mmrm_debugfs_deinit();
      goto LABEL_33;
    }
    result = sysfs_create_group(a1 + 16, &mmrm_fs_attrs_group);
    if ( (_DWORD)result )
    {
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_E36D, "err ", "msm_mmrm_probe_init");
      return 0;
    }
  }
  else
  {
    if ( v3 == 65538 )
      printk(&unk_E296, "high", "msm_mmrm_probe_init");
    *(_BYTE *)(drv_data + 8) = 0;
    return 0;
  }
  return result;
}
