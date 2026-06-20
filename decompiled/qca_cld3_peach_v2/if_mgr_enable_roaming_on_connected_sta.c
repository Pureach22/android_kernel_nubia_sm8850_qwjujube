__int64 __fastcall if_mgr_enable_roaming_on_connected_sta(__int64 a1, __int64 a2)
{
  unsigned int v4; // w19
  __int64 v6; // x8
  __int64 v7; // x21

  if ( *(_DWORD *)(a2 + 16) )
    return 16;
  v4 = *(unsigned __int8 *)(a2 + 168);
  if ( (mlo_mgr_is_link_switch_in_progress(a2) & 1) != 0 )
    return 0;
  v6 = *(_QWORD *)(a2 + 216);
  if ( v6 )
  {
    v7 = *(_QWORD *)(v6 + 80);
    if ( v7 )
    {
      if ( (policy_mgr_is_sta_active_connection_exists(*(_QWORD *)(v6 + 80)) & 1) != 0
        && (mlo_is_enable_roaming_on_connected_sta_allowed(a2) & 1) != 0 )
      {
        wlan_cm_enable_roaming_on_connected_sta(a1, v4);
        policy_mgr_set_pcl_for_connected_vdev(v7, v4, 1);
      }
      return 0;
    }
  }
  return 16;
}
