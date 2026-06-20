__int64 __fastcall hdd_register_policy_manager_callback(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 (__fastcall *v11)(__int64, __int64, unsigned int, unsigned int, char); // [xsp+0h] [xbp-70h] BYREF
  __int64 (__fastcall *v12)(__int64, unsigned int, unsigned int *, double, double, double, double, double, double, double, double); // [xsp+8h] [xbp-68h]
  __int64 (__fastcall *v13)(); // [xsp+10h] [xbp-60h]
  __int64 (__fastcall *v14)(_QWORD); // [xsp+18h] [xbp-58h]
  __int64 (__fastcall *v15)(double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-50h]
  __int64 (__fastcall *v16)(); // [xsp+28h] [xbp-48h]
  __int64 (__fastcall *v17)(__int64, unsigned __int8, unsigned __int8); // [xsp+30h] [xbp-40h]
  __int64 (__fastcall *v18)(__int64, __int64, double, double, double, double, double, double, double, double); // [xsp+38h] [xbp-38h]
  double (__fastcall *v19)(__int64, unsigned __int8, char, double, double, double, double, double, double, double, double); // [xsp+40h] [xbp-30h]
  __int64 (__fastcall *v20)(__int64, __int64, unsigned int, __int64); // [xsp+48h] [xbp-28h]
  __int64 (__fastcall *v21)(__int64, __int64, int *); // [xsp+50h] [xbp-20h]
  __int64 (__fastcall *v22)(__int64, __int64, _DWORD *); // [xsp+58h] [xbp-18h]
  __int64 (__fastcall *v23)(); // [xsp+60h] [xbp-10h]
  __int64 v24; // [xsp+68h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = nullptr;
  v23 = nullptr;
  v20 = nullptr;
  v21 = nullptr;
  v18 = nullptr;
  v19 = nullptr;
  v16 = nullptr;
  v17 = nullptr;
  v14 = nullptr;
  v15 = nullptr;
  v12 = nullptr;
  v13 = nullptr;
  v11 = nullptr;
  qdf_mem_set(&v11, 0x68u, 0);
  v11 = hdd_sap_restart_chan_switch_cb;
  v12 = wlan_hdd_get_channel_for_sap_restart;
  v13 = wlan_hdd_get_mode_for_non_connected_vdev;
  v14 = hdd_get_device_mode;
  v15 = hdd_is_chan_switch_in_progress;
  v16 = hdd_is_cac_in_progress;
  v17 = wlan_hdd_set_sap_csa_reason;
  v18 = hdd_get_ap_6ghz_capable;
  v19 = hdd_indicate_active_ndp_cnt;
  v20 = wlan_get_ap_prefer_conc_ch_params;
  v21 = wlan_get_sap_acs_band;
  v22 = wlan_hdd_check_cc_intf_cb;
  v23 = wlan_hdd_set_tx_rx_nss_cb;
  result = policy_mgr_register_hdd_cb(a1, &v11);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: HDD callback registration with policy manager failed",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "hdd_register_policy_manager_callback");
  _ReadStatusReg(SP_EL0);
  return result;
}
