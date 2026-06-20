__int64 __fastcall hdd_update_tdls_config(__int64 *a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x3
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _QWORD v14[13]; // [xsp+8h] [xbp-118h] BYREF
  __int64 v15; // [xsp+70h] [xbp-B0h]
  __int64 (__fastcall *v16)(); // [xsp+78h] [xbp-A8h]
  __int64 v17; // [xsp+80h] [xbp-A0h]
  __int64 (__fastcall *v18)(); // [xsp+88h] [xbp-98h]
  __int64 v19; // [xsp+90h] [xbp-90h]
  __int64 (__fastcall *v20)(); // [xsp+98h] [xbp-88h]
  __int64 v21; // [xsp+A0h] [xbp-80h]
  __int64 *v22; // [xsp+A8h] [xbp-78h]
  __int64 (__fastcall *v23)(); // [xsp+B0h] [xbp-70h]
  __int64 (__fastcall *v24)(__int64, unsigned int, unsigned int, char, double, double, double, double, double, double, double, double); // [xsp+B8h] [xbp-68h]
  __int64 (__fastcall *v25)(); // [xsp+C0h] [xbp-60h]
  __int64 (__fastcall *v26)(); // [xsp+C8h] [xbp-58h]
  __int64 (__fastcall *v27)(); // [xsp+D0h] [xbp-50h]
  __int64 (__fastcall *v28)(); // [xsp+D8h] [xbp-48h]
  _QWORD v29[3]; // [xsp+E0h] [xbp-40h] BYREF
  __int64 v30; // [xsp+F8h] [xbp-28h]
  __int64 v31; // [xsp+100h] [xbp-20h]
  __int64 v32; // [xsp+108h] [xbp-18h]
  __int64 v33; // [xsp+110h] [xbp-10h]
  __int64 v34; // [xsp+118h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v3 = a1[2];
  v4 = *((unsigned int *)a1 + 312);
  v27 = nullptr;
  v28 = nullptr;
  v25 = nullptr;
  v26 = nullptr;
  v23 = nullptr;
  v24 = nullptr;
  v21 = 0;
  v22 = nullptr;
  v19 = 0;
  v20 = nullptr;
  v17 = 0;
  v18 = nullptr;
  v15 = 0;
  v16 = nullptr;
  memset(v14, 0, sizeof(v14));
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  memset(v29, 0, sizeof(v29));
  sme_populate_nss_chain_params(v3, v29, 15, v4);
  cfg_tdls_set_vdev_nss_2g(*a1, (unsigned int)v30);
  cfg_tdls_set_vdev_nss_5g(*a1, HIDWORD(v30));
  hdd_init_tdls_config(v14);
  LOWORD(v15) = 5255;
  v20 = wlan_cfg80211_tdls_event_callback;
  v21 = v2;
  v22 = a1;
  v23 = hdd_tdls_register_peer;
  v18 = hdd_wmm_is_acm_allowed;
  v19 = v2;
  HIDWORD(v15) = 6;
  v16 = wlan_cfg80211_tdls_rx_callback;
  v17 = v2;
  v24 = hdd_update_dp_vdev_flags;
  v25 = wlan_cfg80211_tdls_osif_priv_init;
  v26 = wlan_cfg80211_tdls_osif_priv_deinit;
  v27 = hdd_check_and_set_tdls_conn_params;
  v28 = hdd_check_and_set_tdls_disconn_params;
  result = ucfg_tdls_update_config(v2, v14);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed pmo psoc configuration",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_update_tdls_config");
    result = 4294967274LL;
  }
  else
  {
    *((_WORD *)a1 + 900) = 257;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
