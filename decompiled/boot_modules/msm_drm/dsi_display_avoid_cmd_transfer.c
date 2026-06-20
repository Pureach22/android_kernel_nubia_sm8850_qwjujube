__int64 __fastcall dsi_display_avoid_cmd_transfer(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x19
  __int64 v10; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967274LL;
  v8 = *(_QWORD *)(a1 + 264);
  if ( !v8 )
    return 4294967274LL;
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_avoid_cmd_transfer", 8073, -1, a2 & 1, -1059143953, a7, a8, vars0);
  v10 = v8 + 1040;
  if ( (a2 & 1) != 0 )
    mutex_lock(v10);
  else
    mutex_unlock(v10);
  return 0;
}
