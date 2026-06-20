__int64 __fastcall wlan_hdd_cfg80211_set_default_key(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        char a5,
        char a6)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w24
  const char *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 vdev_by_user; // x0
  __int64 v38; // x22
  __int64 key; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x24
  unsigned int v49; // w8
  unsigned int v50; // w23
  int v51; // w8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // [xsp+8h] [xbp-18h] BYREF
  int v61; // [xsp+10h] [xbp-10h] BYREF
  __int16 v62; // [xsp+14h] [xbp-Ch]
  __int64 v63; // [xsp+18h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = 0;
  result = _osif_vdev_sync_op_start(a2, &v60, "wlan_hdd_cfg80211_set_default_key");
  if ( !(_DWORD)result )
  {
    v62 = -1;
    v61 = -1;
    if ( (unsigned int)hdd_get_conparam(result) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "__wlan_hdd_cfg80211_set_default_key");
      v19 = -22;
    }
    else
    {
      if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                            *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
                            "__wlan_hdd_cfg80211_set_default_key") )
      {
        qdf_mtrace(51, 51, 0x20u, *(_BYTE *)(*(_QWORD *)(a2 + 55512) + 8LL), (unsigned __int8)a4);
        v20 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Device_mode %s(%d) key_index = %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "__wlan_hdd_cfg80211_set_default_key",
          v20,
          *(unsigned int *)(a2 + 2728),
          (unsigned __int8)a4);
        if ( (unsigned __int8)a4 >= 8u )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid key index: %d",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "__wlan_hdd_cfg80211_set_default_key",
            (unsigned __int8)a4);
          v19 = -22;
          goto LABEL_22;
        }
        v19 = _wlan_hdd_validate_context(*(_QWORD *)(a2 + 2712), "__wlan_hdd_cfg80211_set_default_key");
        if ( v19 )
          goto LABEL_22;
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55512), 6, "wlan_key_get_link_vdev");
        if ( vdev_by_user )
        {
          v38 = vdev_by_user;
          key = wlan_crypto_get_key(vdev_by_user, 0, a4);
          if ( key )
          {
            v48 = key;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: unicast %d, multicast %d cipher %d",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "__wlan_hdd_cfg80211_set_default_key",
              a5 & 1,
              a6 & 1,
              *(unsigned int *)(key + 8));
            v49 = *(_DWORD *)(v48 + 8);
            v50 = 0;
            if ( v49 <= 0x10 && ((1 << v49) & 0x18001) != 0 )
            {
              v51 = *(_DWORD *)(a2 + 2728);
              if ( (v51 | 2) == 2 )
              {
                v50 = wlan_cfg80211_crypto_add_key(v38, v48 + 16, (a5 & 1) == 0, a4, 1);
                wma_update_set_key(
                  *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
                  a5 & 1,
                  a4,
                  v48 + 16,
                  *(unsigned int *)(v48 + 8));
                v51 = *(_DWORD *)(a2 + 2728);
              }
              else
              {
                v50 = 0;
              }
              if ( (v51 | 2) == 3 )
              {
                if ( (unsigned int)wlan_cfg80211_set_default_key(v38, a4, (__int64)&v61) )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: ret fail status %d",
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    "__wlan_hdd_cfg80211_set_default_key",
                    v50);
                  v50 = -22;
                }
                else
                {
                  *(_BYTE *)(*(_QWORD *)(a2 + 55512) + 268LL) = a4;
                }
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Invalid NULL key info",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "__wlan_hdd_cfg80211_set_default_key");
            v50 = -22;
          }
          v19 = v50;
          _hdd_objmgr_put_vdev_by_user(v38, 6, "wlan_key_put_link_vdev");
          goto LABEL_22;
        }
      }
      v19 = -22;
    }
LABEL_22:
    _osif_vdev_sync_op_stop(v60, "wlan_hdd_cfg80211_set_default_key");
    result = v19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
