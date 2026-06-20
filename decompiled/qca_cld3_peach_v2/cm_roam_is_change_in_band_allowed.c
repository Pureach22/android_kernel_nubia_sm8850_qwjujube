__int64 __fastcall cm_roam_is_change_in_band_allowed(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  unsigned __int16 *active_channel; // x20
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  unsigned int v36; // w1
  int v37; // w8

  if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0 )
    return 1;
  v7 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v7 )
  {
    v35 = "%s: vdev is NULL";
LABEL_12:
    v36 = 2;
LABEL_13:
    qdf_trace_msg(0x68u, v36, v35, v8, v9, v10, v11, v12, v13, v14, v15, "cm_roam_is_change_in_band_allowed");
    return 0;
  }
  v16 = v7;
  active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(v7);
  wlan_objmgr_vdev_release_ref(v16, 2u, v18, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( !active_channel )
  {
    v35 = "%s: no active channel";
    goto LABEL_12;
  }
  if ( (policy_mgr_concurrent_sta_on_different_mac(a1) & 1) == 0 )
    return 1;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: sta concurrency on different mac, ch freq %d, roam band:%d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "cm_roam_is_change_in_band_allowed",
    *active_channel,
    a3);
  if ( !((unsigned int)wlan_reg_freq_to_band(*active_channel) | a3 & 1) )
  {
    v35 = "%s: Change in band (2G to 5G/6G) not allowed";
LABEL_19:
    v36 = 8;
    goto LABEL_13;
  }
  if ( (unsigned int)wlan_reg_freq_to_band(*active_channel) == 1 )
  {
    if ( (a3 & 6) == 0 )
    {
LABEL_18:
      v35 = "%s: Change in band (5G/6G to 2G) not allowed";
      goto LABEL_19;
    }
    return 1;
  }
  v37 = wlan_reg_freq_to_band(*active_channel);
  result = 1;
  if ( (a3 & 6) == 0 && v37 == 2 )
    goto LABEL_18;
  return result;
}
