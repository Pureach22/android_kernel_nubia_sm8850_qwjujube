__int64 __fastcall hdd_get_station_assoc_fail(_DWORD *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 vdev_by_user; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  int v30; // w21
  unsigned int *v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w20
  __int64 result; // x0
  unsigned int v50; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _cfg80211_alloc_reply_skb(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 24LL), 103, 197, 20);
  if ( v2 )
  {
    v11 = v2;
    v50 = a1[211];
    if ( (unsigned int)nla_put(v2, 9, 4, &v50) )
    {
LABEL_10:
      qdf_trace_msg(0x33u, 2u, "%s: put fail", v12, v13, v14, v15, v16, v17, v18, v19, "hdd_get_station_assoc_fail");
      sk_skb_reason_drop(0, v11, 2);
      result = 4294967274LL;
      goto LABEL_11;
    }
    v50 = 0;
    vdev_by_user = _hdd_objmgr_get_vdev_by_user((__int64)a1, 0x51u, (__int64)"hdd_get_sta_congestion");
    if ( vdev_by_user )
    {
      v29 = vdev_by_user;
      v30 = ucfg_mc_cp_stats_cca_stats_get(vdev_by_user, &v50, v21, v22, v23, v24, v25, v26, v27, v28);
      _hdd_objmgr_put_vdev_by_user(
        v29,
        0x51u,
        (__int64)"hdd_get_sta_congestion",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39);
      if ( !v30 )
      {
        v48 = v50;
        goto LABEL_9;
      }
    }
    else
    {
      qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v21, v22, v23, v24, v25, v26, v27, v28, "hdd_get_sta_congestion");
    }
    v48 = 0;
LABEL_9:
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: congestion:%d",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "hdd_get_station_assoc_fail",
      v48);
    v50 = v48;
    if ( !(unsigned int)nla_put(v11, 5, 4, &v50) )
    {
      result = cfg80211_vendor_cmd_reply(v11);
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "hdd_get_station_assoc_fail");
  result = 4294967284LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
