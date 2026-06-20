__int64 __fastcall wlan_hdd_cfg80211_p2p_lo_stop(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  unsigned int v15; // w8
  __int64 v16; // x0
  unsigned int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  const char *v27; // x3
  __int64 *v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 32);
  v28[0] = nullptr;
  result = _osif_vdev_sync_op_start(v3, v28, (__int64)"wlan_hdd_cfg80211_p2p_lo_stop");
  if ( !(_DWORD)result )
  {
    v5 = *(_QWORD *)(a2 + 32);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "__wlan_hdd_cfg80211_p2p_lo_stop");
      v14 = -1;
LABEL_14:
      _osif_vdev_sync_op_stop((__int64)v28[0], (__int64)"wlan_hdd_cfg80211_p2p_lo_stop");
      result = v14;
      goto LABEL_15;
    }
    v15 = *(_DWORD *)(v5 + 2728);
    if ( v15 <= 7 && ((1 << v15) & 0x8C) != 0 )
    {
      if ( v5 == -2688 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: adapter is null, adapter:%pK",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "wlan_hdd_listen_offload_stop",
          0);
LABEL_13:
        v14 = -22;
        goto LABEL_14;
      }
      v16 = **(_QWORD **)(v5 + 2712);
      if ( v16 )
      {
        v17 = ucfg_p2p_lo_stop(
                v16,
                *(unsigned __int8 *)(*(_QWORD *)(v5 + 55512) + 8LL),
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                v13);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: p2p listen offload stop, status:%d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "wlan_hdd_listen_offload_stop",
          v17);
        v14 = qdf_status_to_os_return(v17);
        goto LABEL_14;
      }
      v26 = "%s: psoc is null";
      v27 = "wlan_hdd_listen_offload_stop";
    }
    else
    {
      v26 = "%s: Invalid device mode";
      v27 = "__wlan_hdd_cfg80211_p2p_lo_stop";
    }
    qdf_trace_msg(0x33u, 2u, v26, v6, v7, v8, v9, v10, v11, v12, v13, v27);
    goto LABEL_13;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
