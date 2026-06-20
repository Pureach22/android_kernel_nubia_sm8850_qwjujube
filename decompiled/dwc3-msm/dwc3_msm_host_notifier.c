__int64 __fastcall dwc3_msm_host_notifier(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  __int64 v4; // x21
  __int64 v8; // x8
  const char **v9; // x8
  const char *v10; // x0
  const char **v11; // x8
  const char *v12; // x1
  _QWORD *v13; // x21
  __int64 v14; // x8
  __int64 v15; // x24
  __int64 v17; // x1

  v3 = *(_QWORD *)(*(_QWORD *)(a1 - 760) + 168LL);
  v4 = *(_QWORD *)(v3 + 384);
  if ( v4 )
  {
    v8 = a3;
    if ( (unsigned __int64)(a2 - 1) <= 1 )
      v8 = *(_QWORD *)(a3 + 80);
    v9 = *(const char ***)(v8 + 8);
    v10 = v9[14];
    if ( !v10 )
      v10 = *v9;
    v11 = *(const char ***)(v3 + 376);
    v12 = v11[14];
    if ( v12 )
    {
      if ( strcmp(v10, v12) )
        return 0;
    }
    else if ( strcmp(v10, *v11) )
    {
      return 0;
    }
    v13 = *(_QWORD **)(v4 + 168);
    if ( a2 == 3 )
    {
      if ( (unsigned int)usb_hcd_is_primary_hcd(v13) )
      {
        if ( !(unsigned int)usb_hcd_is_primary_hcd(v13) )
          v13 = (_QWORD *)v13[73];
        if ( *(_BYTE *)(a1 - 40) == 1 )
          v13[397] |= 0x20000uLL;
      }
    }
    else if ( (unsigned __int64)(a2 - 3) >= 0xFFFFFFFFFFFFFFFELL )
    {
      if ( a2 == 1 )
      {
        v15 = a3 + 72;
        v14 = *(_QWORD *)(a3 + 72);
        *(_BYTE *)(a3 + 504) |= 2u;
        if ( !v14 )
        {
          _pm_runtime_use_autosuspend(a3 + 168, 1);
          pm_runtime_set_autosuspend_delay(a3 + 168, 1000);
          return 0;
        }
      }
      else
      {
        v15 = a3 + 72;
        v14 = *(_QWORD *)(a3 + 72);
        if ( !v14 )
          return 0;
      }
      if ( !*(_QWORD *)(v14 + 72) && *(_QWORD *)(*(_QWORD *)(a3 + 264) + 96LL) == *(_QWORD *)(v3 + 384) + 16LL )
      {
        if ( a2 == 1 )
        {
          if ( (dwc3_msm_is_ss_rhport_connected(a1 - 800) & 1) != 0 )
          {
            *(_DWORD *)(a1 - 60) = 5;
          }
          else
          {
            if ( (*(_BYTE *)(a1 + 2004) & 1) == 0 )
              clk_set_rate(*(_QWORD *)(a1 - 464), *(_QWORD *)(a1 - 448));
            *(_DWORD *)(a1 - 60) = 3;
            dwc3_msm_update_bus_bw(a1 - 800, 2);
            dwc3_msm_host_ss_powerdown(a1 - 800);
            if ( *(_BYTE *)(a1 + 1781) == 1 )
              wcd_usbss_dpdm_switch_update(1, *(_DWORD *)(a3 + 28) == 3);
            ((void (__fastcall *)(__int64))dwc3_msm_update_interfaces)(a3);
          }
        }
        else
        {
          if ( (*(_BYTE *)(a1 + 2004) & 1) == 0 )
            clk_set_rate(*(_QWORD *)(a1 - 464), *(_QWORD *)(a1 - 456));
          v17 = *(unsigned int *)(a1 - 96);
          *(_DWORD *)(a1 - 60) = 0;
          dwc3_msm_update_bus_bw(a1 - 800, v17);
          dwc3_msm_host_ss_powerup(a1 - 800);
          if ( *(_DWORD *)(*(_QWORD *)v15 + 28LL) >= 5u )
            usb_redriver_host_powercycle(*(_QWORD *)(a1 - 336));
          if ( *(_BYTE *)(a1 + 1781) == 1 )
            wcd_usbss_dpdm_switch_update(1, 1);
          if ( v13 && (v13[47] & 0x40) != 0 )
            queue_work_on(32, system_wq, a1 - 200);
        }
      }
    }
  }
  return 0;
}
