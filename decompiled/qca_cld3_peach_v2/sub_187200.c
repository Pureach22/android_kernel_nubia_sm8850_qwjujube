// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_187200(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6)
{
  unsigned int v7; // w22
  unsigned int v8; // w22
  unsigned int v9; // w22
  unsigned int v10; // w21
  int v11; // w19
  unsigned __int8 *v12; // x21
  __int64 v13; // x22
  __int64 result; // x0

  if ( (v13 & 0x100000000000000LL) == 0 )
    return wlan_cfg80211_cleanup_scan_queue();
  qdf_trace_msg(72, 8, "%s: link_add id %d vdev %d, num_links %d", "osif_update_link_add_partner_links", v13, a6, v11);
  result = mlo_mgr_osif_update_connect_info(a1, (unsigned int)v13);
  if ( v11 )
  {
    v7 = v12[174];
    if ( mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a1 + 1360), v12[174]) )
    {
      qdf_trace_msg(72, 8, "%s: partner link_add id %d ", "osif_update_link_add_partner_links", v7);
      result = mlo_mgr_osif_update_connect_info(a1, v7);
      if ( v11 == 1 )
        return result;
    }
    else
    {
      result = qdf_trace_msg(72, 8, "%s: no found link info for %d", "osif_update_link_add_partner_links", v7);
      if ( v11 == 1 )
        return result;
    }
    v8 = v12[222];
    if ( mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a1 + 1360), v12[222]) )
    {
      qdf_trace_msg(72, 8, "%s: partner link_add id %d ", "osif_update_link_add_partner_links", v8);
      result = mlo_mgr_osif_update_connect_info(a1, v8);
      if ( v11 == 2 )
        return result;
    }
    else
    {
      result = qdf_trace_msg(72, 8, "%s: no found link info for %d", "osif_update_link_add_partner_links", v8);
      if ( v11 == 2 )
        return result;
    }
    v9 = v12[270];
    if ( mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a1 + 1360), v12[270]) )
    {
      qdf_trace_msg(72, 8, "%s: partner link_add id %d ", "osif_update_link_add_partner_links", v9);
      result = mlo_mgr_osif_update_connect_info(a1, v9);
      if ( v11 == 3 )
        return result;
    }
    else
    {
      result = qdf_trace_msg(72, 8, "%s: no found link info for %d", "osif_update_link_add_partner_links", v9);
      if ( v11 == 3 )
        return result;
    }
    v10 = v12[318];
    if ( mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a1 + 1360), v10) )
    {
      qdf_trace_msg(72, 8, "%s: partner link_add id %d ", "osif_update_link_add_partner_links", v10);
      result = mlo_mgr_osif_update_connect_info(a1, v10);
    }
    else
    {
      result = qdf_trace_msg(72, 8, "%s: no found link info for %d", "osif_update_link_add_partner_links", v10);
    }
    if ( v11 != 4 )
    {
      __break(0x5512u);
      JUMPOUT(0x182870);
    }
  }
  return result;
}
