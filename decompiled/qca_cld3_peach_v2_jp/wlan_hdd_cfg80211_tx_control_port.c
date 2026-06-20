__int64 __fastcall wlan_hdd_cfg80211_tx_control_port(
        __int64 a1,
        __int64 a2,
        const void *a3,
        unsigned int a4,
        const void *a5,
        __int16 a6)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v21; // x21
  int v22; // w9
  void *v23; // x0
  _WORD *v24; // x23
  int v25; // w8
  int v26; // w9
  void (__fastcall *v27)(__int64, __int64); // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w19
  _QWORD v37[3]; // [xsp+8h] [xbp-18h] BYREF

  v37[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v37, "_wlan_hdd_cfg80211_tx_control_port");
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v12, v13, v14, v15, v16, v17, v18, v19, "__wlan_hdd_cfg80211_tx_control_port");
    v20 = _netdev_alloc_skb(0, a4 + 14, 2080);
    if ( v20 )
    {
      v21 = v20;
      v22 = *(_DWORD *)(v20 + 208) + 14;
      *(_QWORD *)(v20 + 224) += 14LL;
      *(_DWORD *)(v20 + 208) = v22;
      v23 = (void *)skb_put(v20, a4);
      memcpy(v23, a3, a4);
      v24 = (_WORD *)skb_push(v21, 14);
      qdf_mem_copy(v24, a5, 6u);
      qdf_mem_copy(v24 + 3, (const void *)(a2 + 4305), 6u);
      v24[6] = a6;
      v25 = *(_DWORD *)(v21 + 224);
      v26 = *(_DWORD *)(v21 + 216);
      *(_QWORD *)(v21 + 16) = a2;
      *(_WORD *)(v21 + 180) = -29048;
      LOWORD(v25) = v25 - v26;
      *(_WORD *)(v21 + 184) = v25;
      *(_WORD *)(v21 + 186) = v25;
      netif_tx_lock(a2);
      *(_WORD *)(v21 + 124) = ((__int64 (__fastcall *)(__int64, __int64))hdd_wmm_select_queue)(a2, v21);
      v27 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a2 + 8) + 32LL);
      if ( *((_DWORD *)v27 - 1) != -998155505 )
        __break(0x8228u);
      v27(v21, a2);
      netif_tx_unlock(a2);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: exit",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "__wlan_hdd_cfg80211_tx_control_port");
      v36 = 0;
    }
    else
    {
      v36 = -12;
    }
    _osif_vdev_sync_op_stop(v37[0], "_wlan_hdd_cfg80211_tx_control_port");
    result = v36;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
