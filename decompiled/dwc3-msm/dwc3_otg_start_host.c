__int64 __fastcall dwc3_otg_start_host(_QWORD *a1, int a2)
{
  __int64 v2; // x8
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x21
  unsigned int v7; // w0
  char v8; // w8
  __int64 v9; // x8
  __int64 v10; // x9
  _DWORD *v11; // x9
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x0
  int v15; // w3
  __int64 v16; // x21
  unsigned int v17; // w0
  __int64 v18; // x8
  _DWORD *v19; // x8
  __int64 v20; // x8
  __int64 v21; // x0
  void (*v22)(void); // x8
  __int64 v23; // x0
  void (*v24)(void); // x8
  int v25; // w0
  int v26; // w0
  int v27; // w0
  __int64 v28; // x21
  int v29; // w0
  __int64 v30; // x21
  int v31; // w0
  __int64 v32; // x8
  const char *v33; // x0
  __int64 v34; // x21
  int v35; // w0
  __int64 v36; // x23
  __int64 v37; // x8
  const void *v38; // x1
  _QWORD *v39; // x21
  __int64 v40; // x0
  __int64 v41; // x21
  __int64 v42; // x21
  int v43; // w0
  __int64 v44; // x20
  int v45; // w0
  __int64 v46; // x20
  int v47; // w0
  __int64 v48; // x0
  __int64 v49; // x20
  __int64 v50; // x21
  int v51; // w0
  int v52; // w0
  __int64 v53; // x21
  int v54; // w0
  __int64 v55; // x0
  void (*v56)(void); // x8
  __int64 v57; // x0
  void (*v58)(void); // x8
  __int64 v59; // x20
  int v60; // w0
  int v61; // w0
  __int64 v62; // x20
  int v63; // w0
  __int64 v64; // x8
  __int64 v65; // x20
  int v66; // w0
  unsigned int v68; // w8
  unsigned int v69; // w20
  unsigned int v72; // w10
  unsigned int v73; // w8
  unsigned int v76; // w10
  __int64 v77; // x8
  unsigned __int64 v84; // x9

  v2 = a1[5];
  v4 = *a1;
  v5 = *(_QWORD *)(v2 + 168);
  if ( a2 )
  {
    dev_info(v4, "%s: turn on host\n", "dwc3_otg_start_host");
    v12 = a1[56];
    if ( v12 )
    {
      *(_DWORD *)(v12 + 16) |= 1u;
      v13 = a1[56];
      v14 = a1[157];
      if ( v13 )
      {
        v15 = *(_DWORD *)(v13 + 16);
        goto LABEL_13;
      }
    }
    else
    {
      v14 = a1[157];
    }
    v15 = 0;
LABEL_13:
    dwc3_dbg_print(v14, 0xFFu, "hs_phy_flag:", v15, (const char *)&unk_16A05);
    if ( *((_BYTE *)a1 + 2581) == 1 )
      wcd_usbss_switch_update(0, 1);
    v16 = *a1;
    v17 = _pm_runtime_resume(*a1, 4);
    if ( (v17 & 0x80000000) != 0 )
    {
      v73 = *(_DWORD *)(v16 + 480);
      do
      {
        if ( !v73 )
          break;
        _X12 = (unsigned int *)(v16 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v76 = __ldxr(_X12);
          if ( v76 != v73 )
            break;
          if ( !__stlxr(v73 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v76 == v73;
        v73 = v76;
      }
      while ( !_ZF );
      v69 = v17;
      dev_err(*a1, "%s: pm_runtime_resume_and_get failed\n", "dwc3_otg_start_host");
      v77 = a1[56];
      if ( v77 )
        *(_DWORD *)(v77 + 16) &= ~1u;
      goto LABEL_97;
    }
    dwc3_dbg_print(a1[157], 0xFFu, "StrtHost gync", *(_DWORD *)(*a1 + 480LL), (const char *)&unk_16A05);
    clk_set_rate(a1[42], a1[43]);
    usb_redriver_notify_connect(a1[58], ((*((_DWORD *)a1 + 310) >> 2) & 1) == 0);
    v18 = a1[5];
    if ( v18 )
      v19 = (_DWORD *)(*(_QWORD *)(v18 + 168) + 1232LL);
    else
      v19 = a1 + 141;
    if ( *v19 >= 5u )
    {
      v20 = a1[57];
      if ( v20 )
      {
        *(_DWORD *)(v20 + 16) |= 1u;
        v21 = a1[57];
        if ( v21 )
        {
          v22 = *(void (**)(void))(v21 + 312);
          if ( v22 )
          {
            if ( *((_DWORD *)v22 - 1) != -1429527844 )
              __break(0x8228u);
            v22();
          }
        }
      }
    }
    v23 = a1[56];
    if ( v23 )
    {
      v24 = *(void (**)(void))(v23 + 312);
      if ( v24 )
      {
        if ( *((_DWORD *)v24 - 1) != -1429527844 )
          __break(0x8228u);
        v24();
      }
    }
    a1[100] = dwc3_msm_host_notifier;
    usb_register_notify(a1 + 100);
    if ( (*(_BYTE *)(v5 + 1379) & 0x10) == 0 )
    {
      v25 = readl((unsigned int *)(a1[1] + 49664LL));
      writel(v25 | 0x100, (unsigned int *)(a1[1] + 49664LL));
      v26 = readl((unsigned int *)(a1[1] + 49436LL));
      writel(v26 | 0x100, (unsigned int *)(a1[1] + 49436LL));
    }
    if ( *((_BYTE *)a1 + 2560) == 1 )
    {
      v27 = readl((unsigned int *)(a1[1] + 49664LL));
      writel(v27 | 0x40, (unsigned int *)(a1[1] + 49664LL));
    }
    if ( *(_DWORD *)(v5 + 1248) == 13105 && *(_DWORD *)(v5 + 1252) > 0x31373029u )
    {
      v28 = a1[1];
      v29 = readl((unsigned int *)(v28 + 49436));
      writel(v29 & 0xFF1FFFFF | 0x200000, (unsigned int *)(v28 + 49436));
      readl((unsigned int *)(v28 + 49436));
      v30 = a1[1];
      v31 = readl((unsigned int *)(v30 + 50700));
      writel(v31 | 0x10000, (unsigned int *)(v30 + 50700));
      readl((unsigned int *)(v30 + 50700));
    }
    v32 = a1[56];
    if ( v32 )
    {
      v33 = *(const char **)(v32 + 8);
      if ( !v33 || strcmp(v33, "M31 eUSB2") )
        goto LABEL_44;
    }
    else if ( !(unsigned int)of_device_is_compatible(
                               *(_QWORD *)(*(_QWORD *)(a1[59] + 96LL) + 744LL),
                               "qcom,m31-eUSB2-phy") )
    {
LABEL_44:
      usb_role_switch_set_role(a1[153], 1);
      if ( *(_DWORD *)(v5 + 1120) == 3 )
        flush_work(v5);
      v36 = *(_QWORD *)(v5 + 384);
      v37 = *(_QWORD *)(v36 + 152);
      if ( v37 && (v38 = *(const void **)(v37 + 120)) != nullptr )
      {
        v39 = (_QWORD *)a1[106];
        memcpy(v39, v38, 0xC0u);
        *v39 = dwc3_host_prepare;
        v39[1] = dwc3_host_complete;
        *(_QWORD *)(*(_QWORD *)(v36 + 152) + 120LL) = v39;
      }
      else
      {
        dev_err(v36 + 16, "can't override PM OPs\n");
      }
      *((_BYTE *)a1 + 736) = 1;
      _pm_runtime_use_autosuspend(*(_QWORD *)(v5 + 384) + 16LL, 1);
      pm_runtime_set_autosuspend_delay(*(_QWORD *)(v5 + 384) + 16LL, 0);
      v40 = pm_runtime_allow(*(_QWORD *)(v5 + 384) + 16LL);
      v41 = *(_QWORD *)(v5 + 384);
      *(_QWORD *)(v41 + 536) = ktime_get_mono_fast_ns(v40);
      v42 = a1[1];
      v43 = readl((unsigned int *)(v42 + 49856));
      writel(v43 | 0x20000, (unsigned int *)(v42 + 49856));
      readl((unsigned int *)(v42 + 49856));
      if ( *(_DWORD *)(v5 + 1248) == 13105 && *(_DWORD *)(v5 + 1252) == 825700394 )
      {
        v44 = a1[1];
        v45 = readl((unsigned int *)(v44 + 53264));
        writel(v45 & 0xFF00FFFF | 0x60000, (unsigned int *)(v44 + 53264));
        readl((unsigned int *)(v44 + 53264));
        v46 = a1[1];
        v47 = readl((unsigned int *)(v46 + 53264));
        writel(v47 & 0xFFFFFF00 | 5, (unsigned int *)(v46 + 53264));
        readl((unsigned int *)(v46 + 53264));
      }
      v48 = dwc3_dbg_print(a1[157], 0xFFu, "StrtHost psync", *(_DWORD *)(*a1 + 480LL), (const char *)&unk_16A05);
      v49 = *a1;
      *(_QWORD *)(v49 + 520) = ktime_get_mono_fast_ns(v48);
      _pm_runtime_suspend(*a1, 12);
      return 0;
    }
    v34 = a1[1];
    v35 = readl((unsigned int *)(v34 + 49436));
    writel(v35 | 0x400, (unsigned int *)(v34 + 49436));
    readl((unsigned int *)(v34 + 49436));
    goto LABEL_44;
  }
  dev_info(v4, "%s: turn off host\n", "dwc3_otg_start_host");
  v6 = a1[5];
  v7 = _pm_runtime_resume(v6 + 16, 4);
  if ( (v7 & 0x80000000) == 0 )
  {
    dwc3_dbg_print(a1[157], 0xFFu, "StopHost gsync", *(_DWORD *)(*a1 + 480LL), (const char *)&unk_16A05);
    v8 = *((_BYTE *)a1 + 1232);
    *((_BYTE *)a1 + 736) = 0;
    if ( (v8 & 1) == 0 )
    {
      dwc3_msm_host_ss_powerup(a1);
      ipc_log_string(a1[157], "%s: resetting params for USB ss\n", "dwc3_msm_clear_dp_only_params");
      v9 = a1[57];
      *((_BYTE *)a1 + 1232) = 0;
      if ( v9 )
        *(_DWORD *)(v9 + 16) &= ~0x200u;
      phy_set_mode_ext(a1[60], 0, 1);
      v10 = a1[5];
      if ( v10 )
        v11 = (_DWORD *)(*(_QWORD *)(v10 + 168) + 1232LL);
      else
        v11 = a1 + 141;
      *v11 = *((_DWORD *)a1 + 283);
      usb_redriver_notify_disconnect(a1[58]);
    }
    v50 = a1[1];
    v51 = readl((unsigned int *)(v50 + 1017864));
    writel(v51 | 0x100, (unsigned int *)(v50 + 1017864));
    _const_udelay(21475);
    v52 = readl((unsigned int *)(a1[1] + 1017864LL));
    writel(v52 | 9, (unsigned int *)(a1[1] + 1017864LL));
    _const_udelay(21475);
    v53 = a1[1];
    v54 = readl((unsigned int *)(v53 + 1017864));
    writel(v54 & 0xFFFFFEFF, (unsigned int *)(v53 + 1017864));
    v55 = a1[57];
    if ( v55 && (*(_BYTE *)(v55 + 16) & 1) != 0 )
    {
      v56 = *(void (**)(void))(v55 + 320);
      if ( !v56 )
        goto LABEL_61;
      if ( *((_DWORD *)v56 - 1) != -1429527844 )
        __break(0x8228u);
      v56();
      v55 = a1[57];
      if ( v55 )
LABEL_61:
        *(_DWORD *)(v55 + 16) &= ~1u;
    }
    usb_redriver_notify_disconnect(a1[58]);
    v57 = a1[56];
    if ( v57 )
    {
      v58 = *(void (**)(void))(v57 + 320);
      if ( v58 )
      {
        if ( *((_DWORD *)v58 - 1) != -1429527844 )
          __break(0x8228u);
        v58();
      }
    }
    usb_role_switch_set_role(a1[153], 2);
    if ( *(_DWORD *)(v5 + 1120) == 3 )
      flush_work(v5);
    v59 = a1[1];
    v60 = readl((unsigned int *)(v59 + 1017864));
    writel(v60 | 0x100, (unsigned int *)(v59 + 1017864));
    _const_udelay(21475);
    v61 = readl((unsigned int *)(a1[1] + 1017864LL));
    writel(v61 & 0xFFFFFFF6, (unsigned int *)(a1[1] + 1017864LL));
    _const_udelay(21475);
    v62 = a1[1];
    v63 = readl((unsigned int *)(v62 + 1017864));
    writel(v63 & 0xFFFFFEFF, (unsigned int *)(v62 + 1017864));
    v64 = a1[56];
    if ( v64 )
      *(_DWORD *)(v64 + 16) &= ~1u;
    usb_unregister_notify(a1 + 100);
    v65 = a1[1];
    v66 = readl((unsigned int *)(v65 + 49856));
    writel(v66 & 0xFFFDFFFF, (unsigned int *)(v65 + 49856));
    readl((unsigned int *)(v65 + 49856));
    _X8 = a1 + 86;
    __asm { PRFM            #0x11, [X8] }
    do
      v84 = __ldxr(_X8);
    while ( __stxr(v84 | 8, _X8) );
    _pm_runtime_suspend(a1[5] + 16LL, 4);
    dwc3_dbg_print(a1[157], 0xFFu, "StopHost psync", *(_DWORD *)(*a1 + 480LL), (const char *)&unk_16A05);
    if ( *((_BYTE *)a1 + 2581) == 1 )
      wcd_usbss_switch_update(0, 0);
    return 0;
  }
  v68 = *(_DWORD *)(v6 + 496);
  v69 = v7;
  do
  {
    if ( !v68 )
      break;
    _X12 = (unsigned int *)(v6 + 496);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v72 = __ldxr(_X12);
      if ( v72 != v68 )
        break;
      if ( !__stlxr(v68 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v72 == v68;
    v68 = v72;
  }
  while ( !_ZF );
  dev_err(*a1, "%s: pm_runtime_resume_and_get failed\n", "dwc3_otg_start_host");
  _pm_runtime_set_status(a1[5] + 16LL, 2);
LABEL_97:
  _pm_runtime_set_status(*a1, 2);
  return v69;
}
