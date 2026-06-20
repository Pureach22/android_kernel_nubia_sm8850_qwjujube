__int64 __fastcall wlan_hdd_cfg80211_exttdls_disable(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x23
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w19
  _DWORD *v33; // x20
  __int64 vdev_by_user; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x21
  char tdls_chan_switch_prohibited; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  char is_mlo_vdev; // w22
  unsigned int *v70; // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x8
  __int64 v80; // x9
  __int64 v81; // x10
  __int64 *v82[2]; // [xsp+0h] [xbp-10h] BYREF

  v82[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 32);
  v82[0] = nullptr;
  result = _osif_vdev_sync_op_start(v4, v82, (__int64)"wlan_hdd_cfg80211_exttdls_disable");
  if ( !(_DWORD)result )
  {
    if ( !a1 )
    {
      __break(0x800u);
      JUMPOUT(0x6362B8);
    }
    v14 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "__wlan_hdd_cfg80211_exttdls_disable",
      v14 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "__wlan_hdd_cfg80211_exttdls_disable");
      v23 = -1;
    }
    else
    {
      if ( !(unsigned int)_wlan_hdd_validate_context(
                            a1 + 1536,
                            (__int64)"__wlan_hdd_cfg80211_exttdls_disable",
                            v15,
                            v16,
                            v17,
                            v18,
                            v19,
                            v20,
                            v21,
                            v22) )
      {
        if ( (*(_DWORD *)(v14 + 2728) | 2) != 2 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Failed to get TDLS info due to opmode:%d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "__wlan_hdd_cfg80211_exttdls_disable");
          v23 = -95;
          goto LABEL_7;
        }
        v23 = v14 + 2688;
        if ( v14 == -2688 )
          goto LABEL_7;
        if ( (*(_QWORD *)(v14 + 4328) & 1) != 0 )
        {
          v33 = (_DWORD *)(v14 + 55528);
          goto LABEL_21;
        }
        v33 = (_DWORD *)(v14 + 61616);
        if ( v14 == -61616 || (*(_QWORD *)(v14 + 4328) & 2) == 0 )
        {
          v33 = (_DWORD *)(v14 + 67704);
          v23 = 0;
          if ( v14 == -67704 || (*(_QWORD *)(v14 + 4328) & 4) == 0 )
            goto LABEL_7;
        }
LABEL_21:
        while ( 1 )
        {
          vdev_by_user = _hdd_objmgr_get_vdev_by_user((__int64)v33, 0x11u, (__int64)"wlan_hdd_tdls_disable");
          if ( !vdev_by_user )
            break;
          v43 = vdev_by_user;
          tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                          vdev_by_user,
                                          v35,
                                          v36,
                                          v37,
                                          v38,
                                          v39,
                                          v40,
                                          v41,
                                          v42);
          wlan_tdls_notify_sta_disconnect(
            *(_BYTE *)(v43 + 168),
            tdls_chan_switch_prohibited & 1,
            1,
            v43,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52);
          ucfg_tdls_set_user_tdls_enable(v43, 0, v53, v54, v55, v56, v57, v58, v59, v60);
          is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v43, v61, v62, v63, v64, v65, v66, v67, v68);
          _hdd_objmgr_put_vdev_by_user(
            v43,
            0x11u,
            (__int64)"wlan_hdd_tdls_disable",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78);
          if ( (is_mlo_vdev & 1) == 0
            || (unsigned __int8)(73 * ((unsigned int)((_DWORD)v33 - *v33 - 52840) >> 3) + 1) > 2u )
          {
            v23 = 0;
            goto LABEL_7;
          }
          v79 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v33 - *v33 - 52840) >> 3) + 1);
          v33 = nullptr;
          v80 = v14 + 55528 + 6088LL * (unsigned int)v79;
          do
          {
            if ( v33 )
              break;
            v81 = *(_QWORD *)(v14 + 4328) >> v79++;
            v33 = (_DWORD *)((v81 << 63 >> 63) & v80);
            v80 += 6088;
          }
          while ( v79 != 3 );
          v23 = 0;
          if ( !v33 )
            goto LABEL_7;
        }
      }
      v23 = -22;
    }
LABEL_7:
    v32 = v23;
    _osif_vdev_sync_op_stop((__int64)v82[0], (__int64)"wlan_hdd_cfg80211_exttdls_disable");
    result = v32;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
