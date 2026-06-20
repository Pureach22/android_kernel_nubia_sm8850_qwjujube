__int64 __fastcall wlan_add_key_standby_link(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        __int64 a6)
{
  __int64 *v6; // x24
  __int64 ap_link_by_link_id; // x0
  unsigned int v13; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v6 = *(__int64 **)(a1 + 24);
  ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(a2 + 1360), a3);
  if ( ap_link_by_link_id )
  {
    v13 = wlan_cfg80211_store_link_key(*v6, a4, (a5 & 1) == 0, ap_link_by_link_id + 24, a6, ap_link_by_link_id, a3);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: ml defer set key link id %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_add_key_standby_link",
      a3);
    mlo_defer_set_keys(a2, a3, 1);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v13;
}
