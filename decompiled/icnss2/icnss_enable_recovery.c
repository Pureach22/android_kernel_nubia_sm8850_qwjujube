unsigned __int64 __fastcall icnss_enable_recovery(__int64 a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 ramdump_device; // x0
  __int64 v4; // x8
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x0
  unsigned __int64 result; // x0
  unsigned __int64 v12; // x0
  const char *v13; // x19
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x20
  unsigned __int64 v16; // x0
  int v17; // w21
  int v18; // w22
  int v19; // w21
  int v20; // w21
  int v21; // w21
  unsigned __int64 v24; // x9
  unsigned __int64 v27; // x9
  unsigned __int64 v34; // x9

  if ( (*(_QWORD *)(a1 + 328) & 8) != 0 )
    return ipc_log_string(icnss_ipc_log_context, "icnss2: Recovery disabled through module parameter\n");
  if ( (*(_QWORD *)(a1 + 328) & 0x20) != 0 )
  {
    ipc_log_string(icnss_ipc_log_context, "icnss2: SSR disabled through module parameter\n");
    goto LABEL_44;
  }
  if ( !*(_QWORD *)(a1 + 8) )
  {
    v13 = "%sicnss2: Platform priv or pdev is NULL\n";
    printk("%sicnss2: Platform priv or pdev is NULL\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, v13, &unk_12DBF3);
  }
  v2 = class_create("icnss_ramdump");
  *(_QWORD *)(a1 + 5792) = v2;
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (alloc_chrdev_region(a1 + 5800, 0, 256, "icnss_ramdump") & 0x80000000) != 0 )
    {
      printk("%sicnss2: %s: Unable to allocate major\n", byte_130B32, "icnss_ramdump_devnode_init");
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: %s: Unable to allocate major\n",
        (const char *)&unk_12DBF3,
        "icnss_ramdump_devnode_init");
      return class_destroy(*(_QWORD *)(a1 + 5792));
    }
  }
  else
  {
    v18 = v2;
    printk("%sicnss2: %s:Class create failed for ramdump devices (%d)\n", byte_130B32, "icnss_ramdump_devnode_init", v2);
    result = ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2: %s:Class create failed for ramdump devices (%d)\n",
               (const char *)&unk_12DBF3,
               "icnss_ramdump_devnode_init",
               v18);
    if ( v18 )
      return result;
  }
  ramdump_device = icnss_create_ramdump_device(a1, "wcss_msa0");
  *(_QWORD *)(a1 + 2928) = ramdump_device;
  if ( !ramdump_device || ramdump_device > 0xFFFFFFFFFFFFF000LL || !*(_QWORD *)(ramdump_device + 40) )
  {
    v13 = "%sicnss2: Failed to create msa0 dump device!";
    printk("%sicnss2: Failed to create msa0 dump device!", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, v13, &unk_12DBF3);
  }
  v4 = *(_QWORD *)(a1 + 304);
  if ( v4 == 25680 || v4 == 30544 || v4 == 26448 )
  {
    v5 = icnss_create_ramdump_device(a1, "wcnss_phyareg");
    *(_QWORD *)(a1 + 2936) = v5;
    if ( v5 && v5 <= 0xFFFFFFFFFFFFF000LL && *(_QWORD *)(v5 + 40) )
    {
      v6 = icnss_create_ramdump_device(a1, "wcnss_phydbg");
      *(_QWORD *)(a1 + 2944) = v6;
      if ( v6 && v6 <= 0xFFFFFFFFFFFFF000LL && *(_QWORD *)(v6 + 40) )
      {
        v7 = icnss_create_ramdump_device(a1, "wcnss_wmac0reg");
        *(_QWORD *)(a1 + 2952) = v7;
        if ( v7 && v7 <= 0xFFFFFFFFFFFFF000LL && *(_QWORD *)(v7 + 40) )
        {
          v8 = icnss_create_ramdump_device(a1, "wcnss_WCSSDBG");
          *(_QWORD *)(a1 + 2960) = v8;
          if ( v8 && v8 <= 0xFFFFFFFFFFFFF000LL && *(_QWORD *)(v8 + 40) )
          {
            v9 = icnss_create_ramdump_device(a1, "wcnss_PHYAPDMEM");
            *(_QWORD *)(a1 + 2968) = v9;
            if ( v9 && v9 <= 0xFFFFFFFFFFFFF000LL && *(_QWORD *)(v9 + 40) )
              goto LABEL_28;
            v13 = "%sicnss2: Failed to create m3 dump for Phyapdmem segment device!";
            printk("%sicnss2: Failed to create m3 dump for Phyapdmem segment device!", byte_130B32);
          }
          else
          {
            v13 = "%sicnss2: Failed to create m3 dump for Wcssdbg segment device!";
            printk("%sicnss2: Failed to create m3 dump for Wcssdbg segment device!", byte_130B32);
          }
        }
        else
        {
          v13 = "%sicnss2: Failed to create m3 dump for Wmac0reg segment device!";
          printk("%sicnss2: Failed to create m3 dump for Wmac0reg segment device!", byte_130B32);
        }
      }
      else
      {
        v13 = "%sicnss2: Failed to create m3 dump for Phydbg segment device!";
        printk("%sicnss2: Failed to create m3 dump for Phydbg segment device!", byte_130B32);
      }
    }
    else
    {
      v13 = "%sicnss2: Failed to create m3 dump for Phyareg segment device!";
      printk("%sicnss2: Failed to create m3 dump for Phyareg segment device!", byte_130B32);
    }
    return ipc_log_string(icnss_ipc_log_context, v13, &unk_12DBF3);
  }
LABEL_28:
  if ( *(_BYTE *)(a1 + 5968) != 1 )
  {
    if ( (*(_BYTE *)(a1 + 6112) & 1) == 0 )
    {
      *(_QWORD *)(a1 + 2768) = icnss_modem_notifier_nb;
      *(_DWORD *)(a1 + 2784) = 1;
      v12 = qcom_register_ssr_notifier("mpss", a1 + 2768);
      *(_QWORD *)(a1 + 2736) = v12;
      if ( !v12 || v12 >= 0xFFFFFFFFFFFFF001LL )
      {
        v21 = v12;
        printk("%sicnss2: Modem register notifier failed: %d\n", byte_130B32, v12);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: Modem register notifier failed: %d\n",
          (const char *)&unk_12DBF3,
          v21);
      }
      _X8 = (unsigned __int64 *)(a1 + 1832);
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr(_X8);
      while ( __stxr(v27 | 0x80, _X8) );
      if ( (*(_QWORD *)(a1 + 328) & 0x10) == 0 )
        goto LABEL_44;
      return ipc_log_string(icnss_ipc_log_context, "icnss2: PDR disabled through module parameter\n");
    }
    if ( (*(_QWORD *)(a1 + 328) & 0x10) != 0 )
      return ipc_log_string(icnss_ipc_log_context, "icnss2: PDR disabled through module parameter\n");
LABEL_44:
    v14 = pdr_handle_alloc(icnss_pdr_notifier_cb, a1);
    v15 = v14;
    if ( !v14 || v14 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk("%sicnss2: Failed to alloc pdr handle, err %d", byte_130B32, v14);
      return ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2: Failed to alloc pdr handle, err %d",
               (const char *)&unk_12DBF3,
               v15);
    }
    v16 = pdr_add_lookup(v14, "wlan/fw", "msm/modem/wlan_pd");
    v17 = v16;
    if ( !v16 || v16 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk("%sicnss2: Failed to add lookup, err %d", byte_130B32, v16);
      return ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2: Failed to add lookup, err %d",
               (const char *)&unk_12DBF3,
               v17);
    }
    *(_QWORD *)(a1 + 5664) = v15;
    *(_QWORD *)(a1 + 5672) = v16;
    _X8 = (unsigned __int64 *)(a1 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v34 = __ldxr(_X8);
    while ( __stxr(v34 | 0x100, _X8) );
    v13 = "%sicnss2: PDR registration happened";
    printk("%sicnss2: PDR registration happened", byte_13289B);
    return ipc_log_string(icnss_ipc_log_context, v13, &unk_12DBF3);
  }
  *(_QWORD *)(a1 + 2816) = icnss_wpss_early_notifier_nb;
  v10 = qcom_register_early_ssr_notifier("wpss", a1 + 2816);
  *(_QWORD *)(a1 + 2752) = v10;
  if ( !v10 || v10 >= 0xFFFFFFFFFFFFF001LL )
  {
    v19 = v10;
    printk("%sicnss2: WPSS register early notifier failed: %d\n", byte_130B32, v10);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: WPSS register early notifier failed: %d\n",
      (const char *)&unk_12DBF3,
      v19);
  }
  *(_QWORD *)(a1 + 2792) = icnss_wpss_notifier_nb;
  *(_DWORD *)(a1 + 2808) = 1;
  result = qcom_register_ssr_notifier("wpss", a1 + 2792);
  *(_QWORD *)(a1 + 2744) = result;
  if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
  {
    v20 = result;
    printk("%sicnss2: WPSS register notifier failed: %d\n", byte_130B32, result);
    result = ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2: WPSS register notifier failed: %d\n",
               (const char *)&unk_12DBF3,
               v20);
  }
  _X8 = (unsigned __int64 *)(a1 + 1832);
  __asm { PRFM            #0x11, [X8] }
  do
    v24 = __ldxr(_X8);
  while ( __stxr(v24 | 0x80, _X8) );
  *(_DWORD *)(a1 + 3276) = 0;
  return result;
}
