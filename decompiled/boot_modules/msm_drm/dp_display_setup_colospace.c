__int64 __fastcall dp_display_setup_colospace(__int64 a1, __int64 a2, unsigned int a3)
{
  int *v3; // x23
  int v4; // w19
  _DWORD *v5; // x8
  __int64 v7; // x0
  __int64 v8; // x20
  int v9; // w21
  const char *v10; // x0
  int v11; // w6
  int v12; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 && a2 )
  {
    v3 = (int *)(a1 - 1156);
    v4 = *(_DWORD *)(a1 - 1156);
    if ( (v4 & 0x40) != 0 )
    {
      v5 = *(_DWORD **)(a2 + 1072);
      if ( *(v5 - 1) != -511227187 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, _QWORD))v5)(a2, a3);
    }
    else
    {
      if ( !g_dp_display || (v8 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v8 = 0;
      v9 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      v10 = dp_display_state_name(v4);
      ipc_log_string(v8, "[e][%-4d]%s: state (0x%x): %s\n", v9, "[not enabled]", v4, v10);
      dp_display_state_name(*v3);
      printk(&unk_24548C, "dp_display_setup_colospace");
      sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_setup_colospace", 3556, 8, *v3, -1059143953, v11, v12, vars0);
      return 0;
    }
  }
  else
  {
    if ( !g_dp_display || (v7 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v7 = 0;
    ipc_log_string(v7, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_setup_colospace");
    return 4294967274LL;
  }
}
