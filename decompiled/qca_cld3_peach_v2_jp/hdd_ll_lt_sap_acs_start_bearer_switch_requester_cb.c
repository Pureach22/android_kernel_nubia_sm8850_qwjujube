__int64 __fastcall hdd_ll_lt_sap_acs_start_bearer_switch_requester_cb(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 *a14)
{
  __int64 link_info_by_vdev; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _BYTE v35[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Vdev %d Continue ACS post bearer switch",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "hdd_ll_lt_sap_acs_start_bearer_switch_requester_cb",
    a10);
  v35[0] = 0;
  link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)a14, a10);
  if ( link_info_by_vdev )
  {
    v25 = link_info_by_vdev;
    policy_mgr_get_mac_id_by_session_id(*a14, a10, v35);
    result = wlan_hdd_cfg80211_start_acs(v25);
    if ( (_DWORD)result )
    {
      hdd_switch_bearer_to_wlan_on_ll_lt_sap_acs_complete(*a14, a10);
      result = ucfg_config_dcs_event_data(*a14, v35[0], 1, v27, v28, v29, v30, v31, v32, v33, v34);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: ll_sap vdev_id %u does not exist with host",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "hdd_dcs_continue_csa_for_ll_lt_sap_post_bearer_switch",
               a10);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
