__int64 __fastcall dsi_display_mgr_phy_disable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x20
  int v9; // w6
  int v10; // w7
  char v12; // [xsp+0h] [xbp+0h]
  char v13; // [xsp+0h] [xbp+0h]

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 2212LL) & 1) == 0 )
    return dsi_display_phy_disable(a1);
  v8 = a1;
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_mgr_phy_disable", 431, -1, 4369, -1059143953, a7, a8, v12);
  LODWORD(v8) = dsi_display_mgr_phy_control_disable(v8, 0);
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_mgr_phy_disable", 435, -1, 8738, -1059143953, v9, v10, v13);
  return (unsigned int)v8;
}
