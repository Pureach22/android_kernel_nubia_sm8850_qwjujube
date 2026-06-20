__int64 __fastcall wlan_hdd_cfg80211_set_default_key(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        char a6)
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
  unsigned int v20; // w26
  const char *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 vdev_by_user; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x22
  __int64 vdev_by_link_id; // x24
  __int64 key; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x24
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w8
  int v68; // w8
  unsigned int v69; // w23
  unsigned int *v70; // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // [xsp+8h] [xbp-18h] BYREF
  int v80; // [xsp+10h] [xbp-10h] BYREF
  __int16 v81; // [xsp+14h] [xbp-Ch]
  __int64 v82; // [xsp+18h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v79 = 0;
  result = _osif_vdev_sync_op_start(a2, &v79, "wlan_hdd_cfg80211_set_default_key");
  if ( !(_DWORD)result )
  {
    v81 = -1;
    v80 = -1;
    if ( (unsigned int)hdd_get_conparam(result) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "__wlan_hdd_cfg80211_set_default_key");
      v20 = -22;
    }
    else
    {
      if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                            *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
                            "__wlan_hdd_cfg80211_set_default_key") )
      {
        qdf_mtrace(51, 51, 0x20u, *(_BYTE *)(*(_QWORD *)(a2 + 55520) + 8LL), (unsigned __int8)a4);
        v21 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Device_mode %s(%d) key_index = %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "__wlan_hdd_cfg80211_set_default_key",
          v21,
          *(unsigned int *)(a2 + 2728),
          (unsigned __int8)a4);
        if ( (unsigned __int8)a4 >= 8u )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid key index: %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "__wlan_hdd_cfg80211_set_default_key",
            (unsigned __int8)a4);
          v20 = -22;
          goto LABEL_9;
        }
        v20 = _wlan_hdd_validate_context(*(_QWORD *)(a2 + 2712), "__wlan_hdd_cfg80211_set_default_key");
        if ( v20 )
          goto LABEL_9;
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55520), 6, "wlan_key_get_link_vdev");
        if ( vdev_by_user )
        {
          v47 = vdev_by_user;
          if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v39, v40, v41, v42, v43, v44, v45, v46) & 1) == 0
            || (vdev_by_link_id = mlo_get_vdev_by_link_id(v47, a3, 6),
                _hdd_objmgr_put_vdev_by_user(v47, 6, "wlan_key_get_link_vdev"),
                (v47 = vdev_by_link_id) != 0) )
          {
            key = wlan_crypto_get_key(v47, 0, a4);
            if ( key )
            {
              v58 = key;
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: unicast %d, multicast %d cipher %d",
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                "__wlan_hdd_cfg80211_set_default_key",
                a5 & 1,
                a6 & 1,
                *(unsigned int *)(key + 8));
              v67 = *(_DWORD *)(v58 + 8);
              v20 = 0;
              if ( v67 <= 0x10 && ((1 << v67) & 0x18001) != 0 )
              {
                v68 = *(_DWORD *)(a2 + 2728);
                if ( (v68 | 2) == 2 )
                {
                  v69 = wlan_cfg80211_crypto_add_key(v47, v58 + 16, (a5 & 1) == 0, a4, 1);
                  wma_update_set_key(
                    *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
                    a5 & 1,
                    a4,
                    v58 + 16,
                    *(unsigned int *)(v58 + 8));
                  v68 = *(_DWORD *)(a2 + 2728);
                  v20 = v69;
                }
                else
                {
                  v20 = 0;
                }
                if ( (v68 | 2) == 3 )
                {
                  if ( (unsigned int)wlan_cfg80211_set_default_key(v47, a4, (__int64)&v80) )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: ret fail status %d",
                      v59,
                      v60,
                      v61,
                      v62,
                      v63,
                      v64,
                      v65,
                      v66,
                      "__wlan_hdd_cfg80211_set_default_key",
                      v20);
                    v20 = -22;
                  }
                  else
                  {
                    *(_BYTE *)(*(_QWORD *)(a2 + 55520) + 268LL) = a4;
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
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                "__wlan_hdd_cfg80211_set_default_key");
              v20 = -22;
            }
            if ( (wlan_vdev_mlme_is_mlo_vdev(v47, v59, v60, v61, v62, v63, v64, v65, v66) & 1) != 0 )
              wlan_objmgr_vdev_release_ref(v47, 6u, v70, v71, v72, v73, v74, v75, v76, v77, v78);
            else
              _hdd_objmgr_put_vdev_by_user(v47, 6, "wlan_key_put_link_vdev");
            goto LABEL_9;
          }
        }
      }
      v20 = -22;
    }
LABEL_9:
    _osif_vdev_sync_op_stop(v79, "wlan_hdd_cfg80211_set_default_key");
    result = v20;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
