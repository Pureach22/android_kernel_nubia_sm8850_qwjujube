__int64 __fastcall dsi_display_mgr_phy_enable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  unsigned int v9; // w20
  unsigned int v10; // w19
  int v11; // w6
  int v12; // w7
  char v14; // [xsp+0h] [xbp+0h]
  char v15; // [xsp+0h] [xbp+0h]

  v9 = *(_DWORD *)(a1 + 160) != 1;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 2212LL) & 1) != 0 || (unsigned int)dsi_display_phy_sw_reset(a1) )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_mgr_phy_enable", 415, -1, 4369, -1059143953, a7, a8, v14);
    v10 = dsi_display_mgr_phy_control_enable(a1, 0);
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_mgr_phy_enable", 419, -1, 8738, -1059143953, v11, v12, v15);
  }
  else
  {
    return (unsigned int)dsi_display_phy_enable(a1, v9);
  }
  return v10;
}
