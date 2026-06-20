__int64 __fastcall hdd_register_bcn_cb(__int64 *a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19
  const char *v12; // x2

  v2 = ucfg_scan_register_bcn_cb(*a1, (__int64)wlan_cfg80211_inform_bss_frame, 0);
  if ( v2 )
  {
    v11 = v2;
    v12 = "%s: failed to register SCAN_CB_TYPE_INFORM_BCN with status code %08d [x%08x]";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, "hdd_register_bcn_cb", v11, v11);
    return v11;
  }
  v11 = ucfg_scan_register_bcn_cb(*a1, (__int64)wlan_cfg80211_unlink_bss_list, 2u);
  if ( v11 )
  {
    v12 = "%s: failed to refister SCAN_CB_TYPE_FLUSH_BSS with status code %08d [x%08x]";
    goto LABEL_5;
  }
  return v11;
}
