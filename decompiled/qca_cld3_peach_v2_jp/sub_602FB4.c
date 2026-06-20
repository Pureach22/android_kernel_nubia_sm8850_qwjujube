// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_602FB4(
        unsigned __int8 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w0
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
  unsigned int v36; // w19
  __int64 v37; // x4
  __int64 v38; // x5
  unsigned int v39; // w8
  unsigned int v40; // w20
  unsigned int v41; // w21
  __int64 v42; // x6
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x4
  const char *v52; // x2
  __int64 v53; // x19
  unsigned int v54; // w20
  __int64 v55; // x21
  __int64 v56; // x22
  __int64 v57; // x23
  int v58; // w30
  __int64 v60; // [xsp-98h] [xbp-98h]
  __int64 v61; // [xsp-90h] [xbp-90h] BYREF
  char v62; // [xsp-88h] [xbp-88h]
  char v63; // [xsp-87h] [xbp-87h]
  char v64; // [xsp-86h] [xbp-86h]
  __int64 v65; // [xsp-80h] [xbp-80h] BYREF
  __int64 v66; // [xsp-78h] [xbp-78h]
  __int64 v67; // [xsp-70h] [xbp-70h]
  __int64 v68; // [xsp-68h] [xbp-68h]
  __int64 v69; // [xsp-60h] [xbp-60h]

  if ( v58 )
    return tgt_cfr_update_global_cfg();
  if ( (unsigned int)_wlan_hdd_validate_vdev_id(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) )
    goto LABEL_4;
  v18 = _wlan_hdd_validate_context(
          v53 + 1536,
          (__int64)"__wlan_hdd_cfg80211_monitor_rssi",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17);
  if ( v18 )
    goto LABEL_11;
  if ( !hdd_cm_is_vdev_associated(*(_DWORD **)(v56 + v57)) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Not in Connected state!",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "__wlan_hdd_cfg80211_monitor_rssi");
    v18 = -524;
    goto LABEL_11;
  }
  if ( !(unsigned int)_nla_parse(&v65, 6, v55, v54, &moitor_rssi_policy, 31, 0) )
  {
    if ( !v67 )
    {
      v35 = "%s: attr request id failed";
      goto LABEL_9;
    }
    if ( !v66 )
    {
      v35 = "%s: attr control failed";
      goto LABEL_9;
    }
    v37 = *(unsigned int *)(v67 + 4);
    v38 = *(unsigned __int8 *)(*(_QWORD *)(v56 + v57) + 8LL);
    LODWORD(v61) = *(_DWORD *)(v67 + 4);
    HIDWORD(v61) = v38;
    v39 = *(_DWORD *)(v66 + 4);
    if ( v39 == 2 )
    {
      v42 = 0;
      v64 = 0;
    }
    else
    {
      if ( v39 != 1 )
      {
        v52 = "%s: Invalid control cmd: %d";
        v51 = v39;
LABEL_26:
        qdf_trace_msg(0x33u, 2u, v52, v27, v28, v29, v30, v31, v32, v33, v34, "__wlan_hdd_cfg80211_monitor_rssi", v51);
        goto LABEL_4;
      }
      v64 = 1;
      if ( !v69 )
      {
        v35 = "%s: attr min rssi failed";
        goto LABEL_9;
      }
      if ( !v68 )
      {
        v35 = "%s: attr max rssi failed";
        goto LABEL_9;
      }
      v62 = *(_BYTE *)(v69 + 4);
      v63 = *(_BYTE *)(v68 + 4);
      if ( v62 >= v63 )
      {
        qdf_trace_msg(
          0x33u,
          3u,
          "%s: min_rssi: %d must be less than max_rssi: %d",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "__wlan_hdd_cfg80211_monitor_rssi",
          (unsigned int)v62,
          (unsigned int)v63);
        goto LABEL_4;
      }
      v40 = v37;
      v41 = v38;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Min_rssi: %d Max_rssi: %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "__wlan_hdd_cfg80211_monitor_rssi",
        (unsigned int)v62,
        (unsigned int)v63);
      v38 = v41;
      v37 = v40;
      v42 = 1;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Request Id: %u vdev id: %d Control: %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "__wlan_hdd_cfg80211_monitor_rssi",
      v37,
      v38,
      v42);
    v18 = sme_set_rssi_monitoring(*(_QWORD *)(v53 + 1552), &v61, v43, v44, v45, v46, v47, v48, v49, v50);
    if ( !v18 )
      goto LABEL_11;
    v51 = v18;
    v52 = "%s: sme_set_rssi_monitoring failed(err=%d)";
    goto LABEL_26;
  }
  v35 = "%s: Invalid ATTR";
LABEL_9:
  qdf_trace_msg(0x33u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, "__wlan_hdd_cfg80211_monitor_rssi");
LABEL_4:
  v18 = -22;
LABEL_11:
  v36 = v18;
  _osif_vdev_sync_op_stop(v60, (__int64)"wlan_hdd_cfg80211_monitor_rssi");
  _ReadStatusReg(SP_EL0);
  return v36;
}
