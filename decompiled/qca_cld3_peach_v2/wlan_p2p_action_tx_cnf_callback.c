__int64 __fastcall wlan_p2p_action_tx_cnf_callback(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  __int64 v13; // x19
  __int64 v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 *v23; // x8
  __int64 p2p_wdev; // x21
  unsigned int v25; // w9
  __int64 v26; // x10
  __int64 v27; // x8
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  __int64 result; // x0
  const char *v39; // x2
  _QWORD v40[6]; // [xsp+0h] [xbp-40h] BYREF
  int v41; // [xsp+30h] [xbp-10h] BYREF
  __int16 v42; // [xsp+34h] [xbp-Ch]
  __int64 v43; // [xsp+38h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v41 = 0;
  if ( a1 )
  {
    v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 15);
    if ( v12 )
    {
      v13 = v12;
      wlan_mlme_get_p2p_device_mac_addr(v12, (__int64)&v41, a3, a4, a5, a6, a7, a8, a9, a10);
      v14 = *((_QWORD *)a2 + 3);
      if ( (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(a1) & 1) == 0
        || v14 == -10
        || (unsigned int)qdf_mem_cmp((const void *)(v14 + 10), &v41, 6u) )
      {
        v23 = *(__int64 **)(v13 + 680);
        if ( !v23 )
        {
          v39 = "%s: osif_priv is null";
LABEL_15:
          qdf_trace_msg(0x48u, 2u, v39, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_p2p_action_tx_cnf_callback");
          goto LABEL_16;
        }
        p2p_wdev = *v23;
        if ( *v23 )
        {
LABEL_8:
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: send indication to %s interface",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "wlan_p2p_action_tx_cnf_callback",
            *(_QWORD *)(p2p_wdev + 32) + 296LL);
          v26 = a2[4];
          v25 = a2[5];
          v40[0] = *((_QWORD *)a2 + 1);
          v40[1] = 0;
          v27 = *((_QWORD *)a2 + 3);
          v40[2] = 0;
          v40[3] = v27;
          v40[4] = v26;
          v40[5] = v25 == 0;
          cfg80211_mgmt_tx_status_ext(p2p_wdev, v40, 3264);
LABEL_16:
          result = wlan_objmgr_vdev_release_ref(v13, 0xFu, v28, v29, v30, v31, v32, v33, v34, v35, v36);
          goto LABEL_17;
        }
      }
      else
      {
        p2p_wdev = osif_vdev_mgr_get_p2p_wdev();
        if ( p2p_wdev )
          goto LABEL_8;
      }
      v39 = "%s: wireless dev is null";
      goto LABEL_15;
    }
    v37 = "%s: vdev is null";
  }
  else
  {
    v37 = "%s: psoc is null";
  }
  result = qdf_trace_msg(0x48u, 2u, v37, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_p2p_action_tx_cnf_callback");
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
