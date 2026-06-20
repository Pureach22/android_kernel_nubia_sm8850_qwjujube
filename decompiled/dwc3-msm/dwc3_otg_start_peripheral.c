__int64 __fastcall dwc3_otg_start_peripheral(_QWORD *a1, int a2)
{
  __int64 v4; // x22
  __int64 v5; // x21
  unsigned int v6; // w8
  unsigned int v13; // w10
  __int64 v14; // x0
  __int64 v15; // x22
  int v16; // w0
  __int64 v17; // x22
  int v18; // w0
  __int64 v19; // x22
  void (__fastcall *v20)(__int64, __int64); // x8
  _DWORD *v21; // x8
  __int64 v22; // x0
  void (*v23)(void); // x8
  __int64 v24; // x26
  unsigned __int64 v25; // x22
  int v26; // w27
  __int16 v27; // w25
  __int64 v28; // x22
  int v29; // w0
  __int64 v30; // x22
  int v31; // w0
  __int64 v32; // x22
  int v33; // w0
  __int64 v34; // x8
  int v35; // w22
  __int64 v36; // x8
  __int64 result; // x0
  __int64 v38; // x22
  int v39; // w0
  __int64 v40; // x8
  _DWORD *v41; // x8
  __int64 v42; // x22
  int v43; // w0
  __int64 v44; // x8
  _DWORD *v45; // x8
  __int64 v46; // x0
  void (*v47)(void); // x8
  __int64 v48; // x0
  void (*v49)(void); // x8
  __int64 v50; // x22
  __int64 v51; // x23
  int v52; // w0
  __int64 v53; // x22
  __int64 v54; // x23
  int v55; // w0
  __int64 v56; // x22
  int v57; // w0
  int v58; // w0
  int v59; // w0
  __int64 v60; // x21
  int v61; // w0
  __int64 v62; // x21
  int v63; // w0
  __int64 v64; // x9
  _QWORD *v65; // x20
  unsigned __int64 v68; // x9
  _QWORD v69[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v70[3]; // [xsp+18h] [xbp-18h] BYREF

  v70[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v5 = *(_QWORD *)(a1[5] + 168LL);
  if ( (_pm_runtime_resume(*a1, 4) & 0x80000000) != 0 )
  {
    v6 = *(_DWORD *)(v4 + 480);
    do
    {
      if ( !v6 )
        break;
      _X12 = (unsigned int *)(v4 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v13 = __ldxr(_X12);
        if ( v13 != v6 )
          break;
        if ( !__stlxr(v6 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v13 == v6;
      v6 = v13;
    }
    while ( !_ZF );
    dev_err(*a1, "%s: pm_runtime_resume_and_get failed\n", "dwc3_otg_start_peripheral");
    result = _pm_runtime_set_status(*a1, 2);
  }
  else
  {
    dwc3_dbg_print(a1[157], 0xFFu, "StrtGdgt gsync", *(_DWORD *)(*a1 + 480LL), (const char *)&unk_16A05);
    v14 = *a1;
    if ( a2 )
    {
      dev_info(v14, "%s: turn on gadget\n", "dwc3_otg_start_peripheral");
      if ( *((_BYTE *)a1 + 2581) == 1 )
        wcd_usbss_switch_update(0, 1);
      _pm_runtime_resume(a1[5] + 16LL, 4);
      if ( *(_DWORD *)(v5 + 1120) == 3 )
        flush_work(v5);
      dwc3_msm_notify_event((__int64 *)v5, 11, 0);
      v38 = a1[1];
      v39 = readl((unsigned int *)(v38 + 1017872));
      writel(v39 | 0x100000, (unsigned int *)(v38 + 1017872));
      readl((unsigned int *)(v38 + 1017872));
      v40 = a1[5];
      if ( v40 )
        v41 = (_DWORD *)(*(_QWORD *)(v40 + 168) + 1232LL);
      else
        v41 = a1 + 141;
      if ( *v41 >= 5u )
      {
        v42 = a1[1];
        v43 = readl((unsigned int *)(v42 + 1017904));
        writel(v43 | 0x1000000, (unsigned int *)(v42 + 1017904));
        readl((unsigned int *)(v42 + 1017904));
      }
      usb_redriver_notify_connect(a1[58], ((*((_DWORD *)a1 + 310) >> 2) & 1) == 0);
      v44 = a1[5];
      if ( v44 )
        v45 = (_DWORD *)(*(_QWORD *)(v44 + 168) + 1232LL);
      else
        v45 = a1 + 141;
      if ( *v45 >= 5u )
      {
        v46 = a1[57];
        if ( v46 )
        {
          v47 = *(void (**)(void))(v46 + 312);
          if ( v47 )
          {
            if ( *((_DWORD *)v47 - 1) != -1429527844 )
              __break(0x8228u);
            v47();
          }
        }
      }
      v48 = a1[56];
      if ( v48 )
      {
        v49 = *(void (**)(void))(v48 + 312);
        if ( v49 )
        {
          if ( *((_DWORD *)v49 - 1) != -1429527844 )
            __break(0x8228u);
          v49();
        }
      }
      v50 = a1[1];
      v51 = (unsigned int)(*(_DWORD *)(a1[62] + 104LL) + 1015808);
      v52 = readl((unsigned int *)(v50 + v51));
      writel(v52 | 0x80000000, (unsigned int *)(v50 + v51));
      readl((unsigned int *)(v50 + v51));
      usleep_range_state(1000, 1200, 2);
      v53 = a1[1];
      v54 = (unsigned int)(*(_DWORD *)(a1[62] + 104LL) + 1015808);
      v55 = readl((unsigned int *)(v53 + v54));
      writel(v55 & 0x7FFFFFFF, (unsigned int *)(v53 + v54));
      readl((unsigned int *)(v53 + v54));
      v56 = a1[1];
      v57 = readl((unsigned int *)(v56 + 1017864));
      writel(v57 | 2, (unsigned int *)(v56 + 1017864));
      readl((unsigned int *)(v56 + 1017864));
      if ( (*((_BYTE *)a1 + 508) & 1) == 0 )
      {
        writel(0xFFu, (unsigned int *)(a1[1] + (unsigned int)(*(_DWORD *)(a1[62] + 152LL) + 1015808)));
        writel(0xFFu, (unsigned int *)(a1[1] + (unsigned int)(*(_DWORD *)(a1[62] + 160LL) + 1015808)));
      }
      v58 = readl((unsigned int *)(a1[1] + 49664LL));
      writel(v58 & 0xFFFFFEFF, (unsigned int *)(a1[1] + 49664LL));
      v59 = readl((unsigned int *)(a1[1] + 49436LL));
      writel(v59 & 0xFFFFFEFF, (unsigned int *)(a1[1] + 49436LL));
      *((_BYTE *)a1 + 737) = 1;
      if ( *(_DWORD *)(v5 + 1248) == 13105 && *(_DWORD *)(v5 + 1252) == 825700394 )
      {
        v60 = a1[1];
        v61 = readl((unsigned int *)(v60 + 53264));
        writel(v61 & 0xFF00FFFF | 0x60000, (unsigned int *)(v60 + 53264));
        readl((unsigned int *)(v60 + 53264));
        v62 = a1[1];
        v63 = readl((unsigned int *)(v62 + 53264));
        writel(v63 & 0xFFFFFF00 | 5, (unsigned int *)(v62 + 53264));
        readl((unsigned int *)(v62 + 53264));
      }
      usb_role_switch_set_role(a1[153], 2);
      clk_set_rate(a1[42], a1[43]);
    }
    else
    {
      dev_info(v14, "%s: turn off gadget\n", "dwc3_otg_start_peripheral");
      v15 = a1[1];
      v16 = readl((unsigned int *)(v15 + 1017872));
      writel(v16 & 0xFFEFFFFF, (unsigned int *)(v15 + 1017872));
      readl((unsigned int *)(v15 + 1017872));
      v17 = a1[1];
      v18 = readl((unsigned int *)(v17 + 1017904));
      writel(v18 & 0xFEFFFFFF, (unsigned int *)(v17 + 1017904));
      readl((unsigned int *)(v17 + 1017904));
      v19 = a1[56];
      *((_BYTE *)a1 + 737) = 0;
      if ( v19 )
      {
        v20 = *(void (__fastcall **)(__int64, __int64))(v19 + 320);
        if ( !v20 )
          goto LABEL_17;
        if ( *((_DWORD *)v20 - 1) != -1429527844 )
          __break(0x8228u);
        v20(v19, 3);
        v19 = a1[56];
        if ( v19 )
        {
LABEL_17:
          usb_phy_set_charger_current(v19, 0);
          v21 = *(_DWORD **)(v19 + 288);
          if ( v21 )
          {
            if ( *(v21 - 1) != -935839885 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD))v21)(v19, 0);
          }
        }
      }
      v22 = a1[57];
      if ( v22 )
      {
        v23 = *(void (**)(void))(v22 + 320);
        if ( v23 )
        {
          if ( *((_DWORD *)v23 - 1) != -1429527844 )
            __break(0x8228u);
          v23();
        }
      }
      usb_redriver_notify_disconnect(a1[58]);
      v24 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 368) + 96LL) + 152LL);
      if ( *(_DWORD *)(v24 + 856) )
      {
        v25 = 0;
        v26 = 50204;
        do
        {
          ++v25;
          v27 = readl((unsigned int *)(*(_QWORD *)(v24 + 8) + (v26 & 0xFFFFFFFC)));
          writel(v27 & 0xFFFC, (unsigned int *)(*(_QWORD *)(v24 + 8) + (v26 & 0xFFFFFFFC)));
          ipc_log_string(
            *(_QWORD *)(v24 + 1256),
            "%s: remaining EVNTCOUNT(%d)=%d",
            "handle_gsi_buffer_clear_event",
            v25,
            v27 & 0xFFFC);
          v26 += 16;
        }
        while ( v25 < *(unsigned int *)(v24 + 856) );
      }
      v28 = a1[1];
      v29 = readl((unsigned int *)(v28 + 1017872));
      writel(v29 & 0xFFEFFFFF, (unsigned int *)(v28 + 1017872));
      readl((unsigned int *)(v28 + 1017872));
      v30 = a1[1];
      v31 = readl((unsigned int *)(v30 + 1017904));
      writel(v31 & 0xFEFFFFFF, (unsigned int *)(v30 + 1017904));
      readl((unsigned int *)(v30 + 1017904));
      v32 = a1[1];
      v33 = readl((unsigned int *)(v32 + 49856));
      writel(v33 & 0xFFFDFFFF, (unsigned int *)(v32 + 49856));
      readl((unsigned int *)(v32 + 49856));
      _pm_runtime_idle(a1[5] + 16LL, 4);
      v34 = a1[5];
      if ( *(_DWORD *)(v34 + 516) != 2 || (*(_WORD *)(v34 + 504) & 7) != 0 )
      {
        v35 = -999;
        while ( 1 )
        {
          v36 = *(_QWORD *)(v5 + 1376);
          if ( (v36 & 1) == 0 )
            break;
          msleep(20);
          if ( __CFADD__(v35++, 1) )
          {
            v36 = *(_QWORD *)(v5 + 1376);
            break;
          }
        }
        dwc3_dbg_print(a1[157], 0xFFu, "StopGdgt connected", v36 & 1, (const char *)&unk_16A05);
        _pm_runtime_suspend(a1[5] + 16LL, 0);
      }
      _X8 = a1 + 86;
      __asm { PRFM            #0x11, [X8] }
      do
        v68 = __ldxr(_X8);
      while ( __stxr(v68 | 8, _X8) );
      if ( *((_BYTE *)a1 + 2581) == 1 )
        wcd_usbss_switch_update(0, 0);
    }
    v70[0] = "USB_STATE=ONLINE";
    v70[1] = 0;
    v64 = a1[145];
    v69[0] = "USB_STATE=OFFLINE";
    v69[1] = 0;
    if ( v64 )
    {
      if ( a2 )
        v65 = v70;
      else
        v65 = v69;
      printk(&unk_173E2);
      kobject_uevent_env(a1[145], 2, v65);
    }
    _pm_runtime_idle(*a1, 4);
    result = dwc3_dbg_print(a1[157], 0xFFu, "StopGdgt psync", *(_DWORD *)(*a1 + 480LL), (const char *)&unk_16A05);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
