__int64 __fastcall dwc3_msm_vbus_notifier(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x22
  __int64 v7; // x8
  __int64 v8; // x23
  const char *edev_name; // x0
  int state; // w0
  int v11; // w21
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x19
  int v15; // w0
  __int64 v16; // x8
  _DWORD *v17; // x8
  int v18; // w8
  int v19; // w3

  if ( forge_usb_offline == 1 )
    forge_usb_offline = 0;
  if ( a3 )
  {
    v6 = *(_QWORD *)(a1 - 16);
    if ( v6 )
    {
      v7 = *(_QWORD *)(v6 + 40);
      if ( v7 )
        v8 = *(_QWORD *)(v7 + 168);
      else
        v8 = 0;
      dwc3_dbg_print(*(_QWORD *)(v6 + 1256), 0xFFu, "extcon idx", *(_DWORD *)(a1 - 8), (const char *)&unk_16A05);
      edev_name = (const char *)extcon_get_edev_name(a3);
      ipc_log_string(*(_QWORD *)(v6 + 1256), "%s: edev:%s\n", "dwc3_msm_vbus_notifier", edev_name);
      if ( *(_BYTE *)(*(_QWORD *)(v6 + 784) + 80LL * *(int *)(a1 - 8) + 72) != 1 )
      {
        if ( *(unsigned __int8 *)(v6 + 746) == a2 )
          return 0;
        *(_BYTE *)(v6 + 746) = a2 != 0;
        goto LABEL_24;
      }
      state = extcon_get_state(a3, 61);
      if ( *(unsigned __int8 *)(v6 + 747) == a2 )
        return 0;
      *(_BYTE *)(v6 + 747) = a2 != 0;
      if ( !v8 || *(_DWORD *)(*(_QWORD *)(v8 + 848) + 72LL) < 5u )
      {
        if ( state || !*(_DWORD *)(v6 + 696) )
        {
LABEL_23:
          *(_BYTE *)(v6 + 745) = 1;
LABEL_24:
          v18 = *(_DWORD *)(v6 + 700);
          *(_DWORD *)(v6 + 792) = *(_DWORD *)(a1 - 8);
          if ( v18 == 3 && (*(_BYTE *)(v6 + 632) & 1) == 0 )
            queue_work_on(32, *(_QWORD *)(v6 + 640), v6 + 568);
          return 0;
        }
        v14 = *(_QWORD *)(v6 + 8);
        v15 = readl((unsigned int *)(v14 + 1017872));
        writel(v15 & 0xFFEFFFFF | ((a2 != 0) << 20), (unsigned int *)(v14 + 1017872));
        readl((unsigned int *)(v14 + 1017872));
        if ( a2 )
        {
          v16 = *(_QWORD *)(v6 + 40);
          if ( v16 )
            v17 = (_DWORD *)(*(_QWORD *)(v16 + 168) + 1232LL);
          else
            v17 = (_DWORD *)(v6 + 1128);
          if ( *v17 < 5u )
            return 0;
          v19 = 1;
        }
        else
        {
          v19 = 0;
        }
        dwc3_msm_write_reg_field(*(_QWORD *)(v6 + 8), 0xF8830u, 0x1000000u, v19);
        return 0;
      }
      v11 = state;
      if ( a2 )
      {
        v12 = 1;
        v13 = 1;
      }
      else
      {
        v12 = 0;
        v13 = 0;
      }
      wcd_usbss_dpdm_switch_update(v12, v13);
      if ( v11 )
        goto LABEL_23;
    }
  }
  return 0;
}
