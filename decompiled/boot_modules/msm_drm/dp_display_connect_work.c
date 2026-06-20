__int64 __fastcall dp_display_connect_work(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int64 StatusReg; // x22
  int *v4; // x24
  int v5; // w20
  __int64 v6; // x19
  int v7; // w21
  const char *v8; // x0
  int v9; // w6
  int v10; // w7
  int v11; // w20
  int v12; // w19
  const char *v13; // x0
  void (*v15)(void); // x8
  __int64 v16; // x0
  void *v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !g_dp_display || (v2 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v2 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v2, "[i][%-4d]: +\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_2378FD, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_234328, "dp_display_connect_work");
  v4 = (int *)(a1 - 1620);
  v5 = *(_DWORD *)(a1 - 1620);
  if ( (v5 & 0x800) == 0 )
  {
    if ( (v5 & 0x100) != 0 )
    {
      if ( !g_dp_display || (v18 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v18 = 0;
      ipc_log_string(v18, "[w][%-4d]HPD off requested\n", *(_DWORD *)(StatusReg + 1800));
      v17 = &unk_24F0F2;
    }
    else if ( (*(_BYTE *)(*(_QWORD *)(a1 - 1504) + 8LL) & 1) != 0 )
    {
      if ( !(unsigned int)dp_display_process_hpd_high(a1 - 1632) && *(_BYTE *)(*(_QWORD *)(a1 - 1456) + 872LL) == 1 )
      {
        v15 = *(void (**)(void))(*(_QWORD *)(a1 - 1464) + 184LL);
        if ( *((_DWORD *)v15 - 1) != 1968921649 )
          __break(0x8228u);
        v15();
      }
      if ( !g_dp_display || (v16 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v16 = 0;
      ipc_log_string(v16, "[i][%-4d]: -\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        return printk(&unk_252BBB, *(unsigned int *)(StatusReg + 1800));
      v17 = &unk_248849;
    }
    else
    {
      if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v19 = 0;
      ipc_log_string(v19, "[w][%-4d]Sink disconnected\n", *(_DWORD *)(StatusReg + 1800));
      v17 = &unk_21C813;
    }
    return printk(v17, "dp_display_connect_work");
  }
  if ( !g_dp_display || (v6 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v6 = 0;
  v7 = *(_DWORD *)(StatusReg + 1800);
  v8 = dp_display_state_name(v5);
  ipc_log_string(v6, "[d][%-4d]%s: state (0x%x): %s\n", v7, "[TUI is active]", v5, v8);
  if ( (_drm_debug & 4) != 0 )
  {
    v11 = *v4;
    v12 = *(_DWORD *)(StatusReg + 1800);
    v13 = dp_display_state_name(*v4);
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v12, "[TUI is active]", v11, v13);
  }
  return sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_connect_work", 2132, 8, *v4, -1059143953, v9, v10, vars0);
}
