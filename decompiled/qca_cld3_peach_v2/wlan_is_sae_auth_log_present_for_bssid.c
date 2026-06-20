__int64 __fastcall wlan_is_sae_auth_log_present_for_bssid(__int64 a1, unsigned int *a2, unsigned __int8 *a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  unsigned __int8 v35; // w22
  __int64 v36; // x8
  char is_log_record_present_for_bssid; // w0
  __int64 v38; // x21
  __int64 v40; // x23

  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a3, 67);
  if ( !v6 )
  {
    v38 = jiffies;
    if ( wlan_is_sae_auth_log_present_for_bssid___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: Invalid vdev:%d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "wlan_is_sae_auth_log_present_for_bssid",
        *a3);
      is_log_record_present_for_bssid = 0;
      wlan_is_sae_auth_log_present_for_bssid___last_ticks = v38;
      return is_log_record_present_for_bssid & 1;
    }
    goto LABEL_10;
  }
  v15 = v6;
  if ( (wlan_vdev_mlme_is_mlo_vdev(v6, v7, v8, v9, v10, v11, v12, v13, v14) & 1) == 0 )
  {
    wlan_objmgr_vdev_release_ref(v15, 0x43u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
LABEL_12:
    is_log_record_present_for_bssid = wlan_is_log_record_present_for_bssid(a1, a2, *a3);
    return is_log_record_present_for_bssid & 1;
  }
  v25 = *(_QWORD *)(v15 + 1360);
  wlan_objmgr_vdev_release_ref(v15, 0x43u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( !v25 )
  {
    v40 = jiffies;
    if ( wlan_is_sae_auth_log_present_for_bssid___last_ticks_7 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: mlo_dev ctx is NULL for vdev:%d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlan_is_sae_auth_log_present_for_bssid",
        *a3);
      wlan_is_sae_auth_log_present_for_bssid___last_ticks_7 = v40;
    }
    goto LABEL_12;
  }
  v34 = *(_QWORD *)(v25 + 24);
  if ( !v34 || (v35 = *(_BYTE *)(v34 + 168), (wlan_is_log_record_present_for_bssid(a1, a2, v35) & 1) == 0) )
  {
    v36 = *(_QWORD *)(v25 + 32);
    if ( !v36 || (v35 = *(_BYTE *)(v36 + 168), (wlan_is_log_record_present_for_bssid(a1, a2, v35) & 1) == 0) )
    {
LABEL_10:
      is_log_record_present_for_bssid = 0;
      return is_log_record_present_for_bssid & 1;
    }
  }
  *a3 = v35;
  is_log_record_present_for_bssid = 1;
  return is_log_record_present_for_bssid & 1;
}
