__int64 __fastcall wcd939x_mbhc_init(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x8
  unsigned int v10; // w0
  __int64 v11; // x0
  _QWORD *v12; // x22
  __int64 v13; // x0
  __int64 v14; // x19
  __int64 i; // x23
  char *v16; // x21
  __int64 v17; // x0
  __int64 v18; // x20
  __int64 v19; // x0
  unsigned int v21; // w21

  if ( !a2 )
  {
    printk(&unk_19E1E, "wcd939x_mbhc_init");
    return 4294967274LL;
  }
  v6 = devm_kmalloc(*(_QWORD *)(a2 + 24), 1104, 3520);
  if ( !v6 )
    return 4294967284LL;
  v7 = v6;
  *(_QWORD *)(v6 + 1048) = a3;
  _init_rwsem(v6 + 976, "&(&wcd939x_mbhc->notifier)->rwsem", &wcd939x_mbhc_init___key);
  *(_QWORD *)(v7 + 1040) = 0;
  *(_DWORD *)(v7 + 900) = 1;
  init_timer_key(v7 + 1056, rdown_timer_callback, 0, 0, 0);
  v8 = *(_QWORD *)(a2 + 24);
  *(_DWORD *)(v7 + 1096) = 0;
  *(_BYTE *)(v7 + 1100) = 0;
  v9 = *(_QWORD *)(v8 + 144);
  if ( !v9 )
  {
    dev_err(v8, "%s: pdata pointer is NULL\n", "wcd939x_mbhc_init");
LABEL_18:
    v21 = -22;
    goto LABEL_19;
  }
  *(_DWORD *)(v7 + 176) = *(_DWORD *)(v9 + 36);
  v10 = wcd_mbhc_init(v7, a2, &mbhc_cb, &intr_ids, &wcd_mbhc_registers, 1);
  if ( v10 )
  {
    v21 = v10;
    dev_err(*(_QWORD *)(a2 + 24), "%s: mbhc initialization failed\n", "wcd939x_mbhc_init");
LABEL_19:
    timer_delete((timer_t)(v7 + 1056));
    devm_kfree(*(_QWORD *)(a2 + 24), v7);
    return v21;
  }
  *a1 = v7;
  snd_soc_add_component_controls(a2, &impedance_detect_controls, 2);
  snd_soc_add_component_controls(a2, &hph_type_detect_controls, 1);
  v11 = *(_QWORD *)(a2 + 24);
  v12 = *(_QWORD **)(v11 + 152);
  if ( !v12 )
  {
    dev_err(v11, "%s: wcd939x pointer is NULL\n", "wcd939x_mbhc_init");
    goto LABEL_18;
  }
  if ( *v12 )
  {
    v13 = kobject_create_and_add("usbcss_hs", kernel_kobj);
    if ( v13 )
    {
      v14 = v13;
      for ( i = 0; i != 20; ++i )
      {
        v16 = usbcss_sysfs_files[i];
        v17 = devm_kmalloc(*v12, 48, 3264);
        if ( v17 )
        {
          v18 = v17;
          v19 = devm_kstrdup(*v12, v16, 3264);
          if ( v19 )
          {
            *(_QWORD *)v18 = v12;
            *(_QWORD *)(v18 + 8) = v19;
            *(_DWORD *)(v18 + 40) = i;
            *(_WORD *)(v18 + 16) = 420;
            *(_QWORD *)(v18 + 24) = usbcss_sysfs_show;
            *(_QWORD *)(v18 + 32) = usbcss_sysfs_store;
            sysfs_create_file_ns(v14, v18 + 8, 0);
          }
        }
      }
    }
    else
    {
      dev_err(*v12, "%s: Could not create the USBC-SS HS kobj.\n", "usbcss_hs_sysfs_init");
    }
  }
  else
  {
    printk(&unk_19796, "usbcss_hs_sysfs_init");
  }
  return 0;
}
