__int64 __fastcall dsi_display_set_power(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x0
  unsigned int v6; // w21
  __int64 v7; // x1
  __int64 v9; // x1
  __int64 v10; // x0
  __int64 v11; // x1
  const char *v12; // x6
  __int64 v13; // x8
  char v14; // [xsp+0h] [xbp+0h]

  if ( !a3 || (v3 = *(_QWORD *)(a3 + 264)) == 0 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display/panel\n");
    return (unsigned int)-22;
  }
  v6 = 0;
  if ( a2 <= 1 )
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        return v6;
      if ( *(_DWORD *)(v3 + 2220) == 2 && (unsigned int)dsi_display_set_lp2_load(a3, 0) )
        printk(&unk_2408D8, v7);
      v6 = dsi_panel_set_lp1(*(_QWORD *)(a3 + 264));
      zte_aod_handler(*(_QWORD *)(a3 + 264), 3);
      *(_BYTE *)(*(_QWORD *)(a3 + 264) + 2559LL) = 0;
    }
    else
    {
      if ( *(_DWORD *)(v3 + 2220) == 2 && (unsigned int)dsi_display_set_lp2_load(a3, 0) )
        printk(&unk_2408D8, v9);
      v10 = *(_QWORD *)(a3 + 264);
      if ( (unsigned int)(*(_DWORD *)(v10 + 2220) - 1) > 1 || (*(_BYTE *)(v10 + 2559) & 1) != 0 )
      {
        v6 = 0;
      }
      else
      {
        v6 = dsi_panel_set_nolp();
        zte_aod_handler(*(_QWORD *)(a3 + 264), 4);
        *(_BYTE *)(*(_QWORD *)(a3 + 264) + 2558LL) = 0;
      }
    }
    goto LABEL_24;
  }
  if ( a2 == 2 )
  {
    v6 = dsi_panel_set_lp2();
    if ( (unsigned int)dsi_display_set_lp2_load(a3, 1) )
      printk(&unk_26A5F2, v11);
LABEL_24:
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dsi_display_set_power",
      1616,
      -1,
      *(_DWORD *)(*(_QWORD *)(a3 + 264) + 2220LL),
      a2,
      v6,
      -1059143953,
      v14);
    if ( v6 )
      v12 = "failed";
    else
      v12 = "successful";
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: Power mode transition from %d to %d %s",
      *(unsigned int *)(*(_QWORD *)(a3 + 264) + 2220LL),
      (unsigned int)a2,
      v12);
    if ( !v6 )
      *(_DWORD *)(*(_QWORD *)(a3 + 264) + 2220LL) = a2;
    v13 = *(_QWORD *)(a3 + 264);
    if ( *(_DWORD *)(v13 + 2236) == 1 )
    {
      v6 = dsi_hfi_transition(a3, *(_DWORD *)(v13 + 2220));
      if ( v6 )
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to send hfi transition cmd, rc=%d\n", v6);
    }
    return v6;
  }
  if ( a2 == 5 )
  {
    ((void (*)(void))zte_aod_handler)();
    v6 = 0;
    *(_BYTE *)(*(_QWORD *)(a3 + 264) + 2558LL) = 0;
  }
  return v6;
}
