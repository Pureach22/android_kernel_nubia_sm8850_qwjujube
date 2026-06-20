__int64 __fastcall if_mgr_enable_roaming_on_connected_sta(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x19
  unsigned int v6; // w20

  if ( *(_DWORD *)(a2 + 16) )
    return 16;
  v3 = *(_QWORD *)(a2 + 152);
  if ( !v3 )
    return 16;
  v4 = *(_QWORD *)(v3 + 80);
  if ( !v4 )
    return 16;
  v6 = *(unsigned __int8 *)(a2 + 104);
  if ( (policy_mgr_is_sta_active_connection_exists(*(_QWORD *)(v3 + 80)) & 1) != 0 )
  {
    wlan_cm_enable_roaming_on_connected_sta(a1, v6);
    policy_mgr_set_pcl_for_connected_vdev(v4, v6, 1);
  }
  return 0;
}
