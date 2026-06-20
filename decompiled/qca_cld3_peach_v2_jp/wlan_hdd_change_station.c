__int64 __fastcall wlan_hdd_change_station(__int64 a1, __int64 a2, unsigned __int8 *a3, __int64 a4)
{
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  unsigned int v26; // w1
  unsigned int v27; // w24
  __int64 *v28; // x22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 sta_info_by_mac; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  int v50; // w8
  __int64 v51; // x21
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 vdev_by_user; // x0
  __int64 v61; // x19
  unsigned int updated; // w20
  __int64 v63; // [xsp+0h] [xbp-20h] BYREF
  __int64 v64; // [xsp+8h] [xbp-18h] BYREF
  int v65; // [xsp+10h] [xbp-10h] BYREF
  __int16 v66; // [xsp+14h] [xbp-Ch]
  __int64 v67; // [xsp+18h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  result = _osif_vdev_sync_op_start(a2, &v63, "wlan_hdd_change_station");
  if ( !(_DWORD)result )
  {
    v66 = 0;
    v65 = 0;
    v16 = qdf_trace_msg(0x33u, 8u, "%s: enter", v8, v9, v10, v11, v12, v13, v14, v15, "__wlan_hdd_change_station");
    if ( (unsigned int)hdd_get_conparam(v16) == 5 )
    {
      v25 = "%s: Command not allowed in FTM mode";
      v26 = 2;
LABEL_4:
      qdf_trace_msg(0x33u, v26, v25, v17, v18, v19, v20, v21, v22, v23, v24, "__wlan_hdd_change_station");
      v27 = -22;
LABEL_32:
      _osif_vdev_sync_op_stop(v63, "wlan_hdd_change_station");
      result = v27;
      goto LABEL_33;
    }
    qdf_mtrace(51, 51, 0x2Au, *(_BYTE *)(*(_QWORD *)(a2 + 55512) + 8LL), *(_DWORD *)(a4 + 20));
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
                         "__wlan_hdd_change_station") )
    {
LABEL_6:
      v27 = -22;
      goto LABEL_32;
    }
    v28 = *(__int64 **)(a2 + 2712);
    v27 = _wlan_hdd_validate_context(v28, "__wlan_hdd_change_station");
    if ( v27 )
      goto LABEL_32;
    qdf_mem_copy(&v65, a3, 6u);
    if ( *(_WORD *)(a4 + 26) )
    {
      sta_info_by_mac = hdd_get_sta_info_by_mac(a2 + 41536, a3, 22, 3);
      v64 = sta_info_by_mac;
      if ( sta_info_by_mac )
      {
        *(_WORD *)(sta_info_by_mac + 496) = *(_WORD *)(a4 + 26);
        hdd_put_sta_info_ref(a2 + 41536, &v64, 1, 22);
      }
      else
      {
        if ( a3 )
        {
          v46 = *a3;
          v47 = a3[1];
          v48 = a3[2];
          v49 = a3[5];
        }
        else
        {
          v48 = 0;
          v46 = 0;
          v47 = 0;
          v49 = 0;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to find right station MAC: %02x:%02x:%02x:**:**:%02x",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wlan_hdd_set_vlan_id",
          v46,
          v47,
          v48,
          v49);
      }
    }
    v50 = *(_DWORD *)(a2 + 2728);
    v27 = 0;
    if ( v50 > 1 )
    {
      if ( v50 != 2 )
      {
        if ( v50 == 3 )
          goto LABEL_21;
LABEL_31:
        qdf_trace_msg(0x33u, 8u, "%s: exit", v29, v30, v31, v32, v33, v34, v35, v36, "__wlan_hdd_change_station");
        goto LABEL_32;
      }
    }
    else if ( v50 )
    {
      if ( v50 != 1 )
        goto LABEL_31;
LABEL_21:
      if ( (*(_BYTE *)(a4 + 12) & 2) != 0 )
      {
        v51 = *(_QWORD *)(a2 + 55512);
        if ( (wlan_mlme_is_multipass_sap(*v28, v29, v30, v31, v32, v33, v34, v35, v36) & 1) != 0
          && (unsigned int)wlan_hdd_set_vlan_config(a2 + 2688, a3) )
        {
          goto LABEL_26;
        }
        if ( *(_DWORD *)(v51 + 264) )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Encrypt type %d, not setting peer authorized now",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "__wlan_hdd_change_station");
LABEL_26:
          v27 = 0;
          goto LABEL_32;
        }
        if ( (unsigned int)hdd_softap_change_sta_state(*(_QWORD *)(a2 + 55512), &v65, 3) )
        {
          v25 = "%s: Not able to change TL state to AUTHENTICATED";
          v26 = 8;
          goto LABEL_4;
        }
        if ( (unsigned int)wlan_hdd_send_sta_authorized_event(
                             a2 + 2688,
                             (__int64)v28,
                             (__int64)&v65,
                             v17,
                             v18,
                             v19,
                             v20,
                             v21,
                             v22,
                             v23,
                             v24) )
          goto LABEL_6;
      }
      goto LABEL_28;
    }
    if ( (*(_BYTE *)(a4 + 12) & 0x40) == 0 )
    {
LABEL_28:
      v27 = 0;
      goto LABEL_31;
    }
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55512), 87, "__wlan_hdd_change_station");
    if ( !vdev_by_user )
      goto LABEL_6;
    v61 = vdev_by_user;
    updated = wlan_cfg80211_tdls_update_peer(vdev_by_user, a3, a4);
    _hdd_objmgr_put_vdev_by_user(v61, 87, "__wlan_hdd_change_station");
    v27 = updated;
    goto LABEL_31;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
