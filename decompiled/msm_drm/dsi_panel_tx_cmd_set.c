__int64 __fastcall dsi_panel_tx_cmd_set(const char **a1, unsigned int a2, char a3)
{
  const char *v3; // x25
  __int64 v5; // x8
  int v8; // w23
  int v9; // w24
  __int64 v10; // x22
  int v11; // w0
  int v12; // w8
  unsigned int v14; // w20
  char vars0; // [xsp+0h] [xbp+0h]

  v3 = a1[178];
  if ( !v3 )
    return 4294967274LL;
  if ( a2 >= 0x3B )
  {
    __break(0x5512u);
    return dsi_panel_set_backlight();
  }
  else
  {
    v5 = *((_QWORD *)v3 + 23) + 40LL * a2;
    v9 = *(_DWORD *)(v5 + 4);
    v8 = *(_DWORD *)(v5 + 8);
    v10 = *(_QWORD *)(v5 + 16);
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_panel_tx_cmd_set", 558, -1, a2, v9, v8, -1059143953, vars0);
    if ( v8 )
    {
      if ( *(_BYTE *)(*((_QWORD *)v3 + 23) + 40LL * a2 + 32) == 1 )
        printk(&unk_21F26E, *a1);
      while ( 1 )
      {
        *(_DWORD *)(v10 + 52) = 0;
        if ( v9 )
          break;
        *(_WORD *)(v10 + 2) |= 2u;
        if ( (a2 == 12) | a3 & 1 )
          goto LABEL_10;
LABEL_11:
        v11 = ((__int64 (__fastcall *)(const char *, __int64, _QWORD))dsi_host_transfer_sub)(a1[151], v10, a3 & 1);
        if ( v11 < 0 )
        {
          v14 = v11;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set cmds(%d), rc=%d\n", a2, v11);
          return v14;
        }
        v12 = *(_DWORD *)(v10 + 44);
        if ( v12 )
          usleep_range_state((unsigned int)(1000 * v12), (unsigned int)(1000 * v12 + 10), 2);
        --v8;
        v10 += 64;
        if ( !v8 )
          return 0;
      }
      if ( !((a2 == 12) | a3 & 1) )
        goto LABEL_11;
LABEL_10:
      *(_WORD *)(v10 + 2) |= 0x10u;
      goto LABEL_11;
    }
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] No commands to be sent for state(%d)\n", *a1, a2);
    return 0;
  }
}
