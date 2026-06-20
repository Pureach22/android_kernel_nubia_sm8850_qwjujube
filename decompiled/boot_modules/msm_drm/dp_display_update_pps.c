__int64 __fastcall dp_display_update_pps(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int *v4; // x23
  int v5; // w19
  void (__fastcall *v6)(__int64, __int64); // x9
  __int64 v7; // x0
  __int64 v9; // x0
  __int64 v10; // x20
  int v11; // w21
  const char *v12; // x0
  int v13; // w6
  int v14; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  v3 = *(_QWORD *)(a2 + 2768);
  if ( v3 )
  {
    v4 = (int *)(a1 - 1156);
    v5 = *(_DWORD *)(a1 - 1156);
    if ( (v5 & 0x40) != 0 )
    {
      v6 = *(void (__fastcall **)(__int64, __int64))(v3 + 1144);
      v7 = *(_QWORD *)(a2 + 2768);
      if ( *((_DWORD *)v6 - 1) != 1414176868 )
        __break(0x8229u);
      v6(v7, a3);
    }
    else
    {
      if ( !g_dp_display || (v10 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v10 = 0;
      v11 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      v12 = dp_display_state_name(v5);
      ipc_log_string(v10, "[e][%-4d]%s: state (0x%x): %s\n", v11, "[not enabled]", v5, v12);
      dp_display_state_name(*v4);
      printk(&unk_24548C, "dp_display_update_pps");
      sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_update_pps", 3850, 8, *v4, -1059143953, v13, v14, vars0);
    }
    return 0;
  }
  else
  {
    if ( !g_dp_display || (v9 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v9 = 0;
    ipc_log_string(
      v9,
      "[e][%-4d]invalid panel for connector:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a2 + 64));
    printk(&unk_272CEF, "dp_display_update_pps");
    return 4294967274LL;
  }
}
