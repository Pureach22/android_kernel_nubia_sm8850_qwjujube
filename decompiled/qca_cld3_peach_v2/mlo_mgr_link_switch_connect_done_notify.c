__int64 __fastcall mlo_mgr_link_switch_connect_done_notify(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( (wlan_cm_is_link_switch_connect_resp(a2) & 1) != 0 )
  {
    wlan_cm_reset_active_cm_id(a1, *(_DWORD *)(a2 + 4), v4, v5, v6, v7, v8, v9, v10, v11);
    return mlo_mgr_link_switch_connect_done(a1, *(unsigned int *)(a2 + 52));
  }
  else
  {
    result = wlan_cm_is_link_add_connect_resp(a2);
    if ( (result & 1) != 0 )
    {
      wlan_cm_reset_active_cm_id(a1, *(_DWORD *)(a2 + 4), v13, v14, v15, v16, v17, v18, v19, v20);
      return mlo_link_recfg_add_connect_done_indication(a1, *(unsigned int *)(a2 + 52));
    }
  }
  return result;
}
