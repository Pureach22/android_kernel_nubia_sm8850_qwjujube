__int64 __fastcall hdd_wiphy_init(__int64 *a1)
{
  __int64 v2; // x20
  unsigned int v3; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w21
  const char *v13; // x2
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[3];
  v23 = 0;
  v3 = hdd_regulatory_init();
  if ( v3 )
  {
    v12 = v3;
    v13 = "%s: regulatory init failed";
  }
  else
  {
    if ( (unsigned int)ucfg_pmo_get_suspend_mode(*a1) == 2 )
      *(_QWORD *)(v2 + 248) = &wowlan_support_reg_init;
    ucfg_mlme_get_channel_bonding_24ghz(*a1, &v23);
    if ( *((_BYTE *)a1 + 3489) == 1 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: wmi_service_obss_scan supported",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_wiphy_init");
    }
    else if ( v23 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: enable wpa_supp obss_scan",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_wiphy_init");
      *(_DWORD *)(v2 + 108) |= 0x400u;
    }
    if ( *((_DWORD *)a1 + 312) == 2 && (wlan_mlme_is_chain_mask_supported(*a1) & 1) != 0 )
      *(_QWORD *)(v2 + 268) = 0x300000003LL;
    v12 = wlan_hdd_cfg80211_register(v2, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( (v12 & 0x80000000) == 0 )
    {
      hdd_send_wiphy_regd_sync_event(a1, 1);
      cnss_utils_increment_driver_load_cnt(a1[12]);
      goto LABEL_15;
    }
    v13 = "%s: wiphy registration failed";
  }
  qdf_trace_msg(0x33u, 2u, v13, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_wiphy_init");
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v12;
}
