__int64 __fastcall wlan_hdd_cfg80211_coap_offload(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w0
  __int64 vdev_by_user; // x0
  __int64 v29; // x22
  int v30; // w19
  unsigned int *v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w19
  __int64 *v41[2]; // [xsp+0h] [xbp-10h] BYREF

  v41[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v41[0] = nullptr;
  result = _osif_vdev_sync_op_start(v8, v41, (__int64)"wlan_hdd_cfg80211_coap_offload");
  if ( (_DWORD)result )
  {
LABEL_12:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_coap_offload",
      v18 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__wlan_hdd_cfg80211_coap_offload");
      v27 = -1;
    }
    else
    {
      v27 = _wlan_hdd_validate_context(
              a1 + 1536,
              (__int64)"__wlan_hdd_cfg80211_coap_offload",
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26);
      if ( !v27 )
      {
        if ( *(_DWORD *)(v18 + 2728) )
        {
          v27 = -524;
        }
        else
        {
          vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                           *(_QWORD *)(v18 + 55512),
                           0x63u,
                           (__int64)"__wlan_hdd_cfg80211_coap_offload");
          if ( vdev_by_user )
          {
            v29 = vdev_by_user;
            v30 = wlan_cfg80211_coap_offload(a1, vdev_by_user, a3, a4);
            _hdd_objmgr_put_vdev_by_user(
              v29,
              0x63u,
              (__int64)"__wlan_hdd_cfg80211_coap_offload",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39);
            v27 = v30;
          }
          else
          {
            v27 = -22;
          }
        }
      }
    }
    v40 = v27;
    _osif_vdev_sync_op_stop((__int64)v41[0], (__int64)"wlan_hdd_cfg80211_coap_offload");
    result = v40;
    goto LABEL_12;
  }
  __break(0x800u);
  __ldaxr((unsigned int *)v41);
  return ((__int64 (*)(void))wlan_cfg80211_coap_offload)();
}
