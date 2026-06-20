__int64 __fastcall wlan_hdd_ll_lt_sap_get_valid_last_acs_freq(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v10; // x20
  const char *v11; // x2
  __int64 result; // x0
  __int64 v13; // x20
  __int64 v14; // x8
  int *v15; // x9
  int v16; // t1
  unsigned int v17; // w21
  unsigned int v18; // w22
  __int64 v19; // x23
  unsigned __int64 time_of_the_day_ms; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( !a1 )
  {
    v11 = "%s: link_info is NULL";
    goto LABEL_5;
  }
  v10 = *(__int64 **)(*a1 + 24);
  if ( (unsigned int)_wlan_hdd_validate_context(v10, "wlan_hdd_ll_lt_sap_get_valid_last_acs_freq") )
  {
    v11 = "%s: Invalid HDD context";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_ll_lt_sap_get_valid_last_acs_freq");
    return 0;
  }
  if ( !*((_DWORD *)a1 + 534) )
    return 0;
  if ( !a1[268] )
    return 0;
  if ( !policy_mgr_is_vdev_ll_lt_sap(*v10, *((unsigned __int8 *)a1 + 8)) )
    return 0;
  v13 = a1[34];
  if ( (__int64)(qdf_get_time_of_the_day_ms() - a1[268] - 5000) >= 0 )
    return 0;
  v14 = *((unsigned __int8 *)a1 + 1440);
  if ( !*((_BYTE *)a1 + 1440) )
    return 0;
  v15 = (int *)a1[179];
  while ( 1 )
  {
    v16 = *v15++;
    if ( v16 == *((_DWORD *)a1 + 534) )
      break;
    --v14;
    result = 0;
    if ( !v14 )
      return result;
  }
  wlansap_update_ll_lt_sap_acs_result(v13);
  v17 = *((unsigned __int8 *)a1 + 8);
  v18 = *((_DWORD *)a1 + 534);
  v19 = a1[268];
  time_of_the_day_ms = qdf_get_time_of_the_day_ms();
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev %d, return prev ACS freq %d stored at %lu, current time %lu",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "wlan_hdd_ll_lt_sap_get_valid_last_acs_freq",
    v17,
    v18,
    v19,
    time_of_the_day_ms);
  wlan_hdd_cfg80211_acs_ch_select_evt(a1, 0);
  ((void (__fastcall *)(__int64, __int64 *))wlansap_dcs_set_wlan_interference_mitigation_on_band)(v13, a1 + 35);
  return 1;
}
