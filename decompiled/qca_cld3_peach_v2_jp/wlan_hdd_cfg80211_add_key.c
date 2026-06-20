__int64 __fastcall wlan_hdd_cfg80211_add_key(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        char a5,
        const void *a6,
        __int64 a7)
{
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w25
  __int64 v23; // x26
  unsigned int v24; // w25
  const char *v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x25
  __int64 vdev_by_user; // x0
  int v36; // w8
  __int64 *v37; // x23
  __int64 v38; // x21
  __int64 v39; // x26
  __int64 *v40; // x27
  __int64 bsspeer; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x24
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  __int64 v60; // x24
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w24
  unsigned int param; // w0
  unsigned int v71; // w25
  unsigned int v72; // w24
  _QWORD *context; // x0
  __int64 v74; // x8
  void (*v75)(void); // x8
  const char *v76; // x2
  int v77; // w8
  unsigned int cmd; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x25
  __int64 v88; // x0
  __int64 v89; // x22
  int v90; // w23
  __int64 v91; // x0
  __int64 v92; // x0
  char is_multipass_sap; // w0
  __int64 v94; // x2
  unsigned int v95; // w0
  __int64 v96; // [xsp+30h] [xbp-30h] BYREF
  _BYTE v97[4]; // [xsp+3Ch] [xbp-24h] BYREF
  int v98; // [xsp+40h] [xbp-20h] BYREF
  __int16 v99; // [xsp+44h] [xbp-1Ch]
  unsigned int v100; // [xsp+48h] [xbp-18h] BYREF
  unsigned __int16 v101; // [xsp+4Ch] [xbp-14h]
  __int64 v102; // [xsp+58h] [xbp-8h]

  v102 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v96 = 0;
  result = _osif_vdev_sync_op_start(a2, &v96, "wlan_hdd_cfg80211_add_key");
  if ( !(_DWORD)result )
  {
    v99 = -1;
    v98 = -1;
    if ( (unsigned int)hdd_get_conparam(result) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "__wlan_hdd_cfg80211_add_key");
      v22 = -22;
LABEL_62:
      _osif_vdev_sync_op_stop(v96, "wlan_hdd_cfg80211_add_key");
      result = v22;
      goto LABEL_63;
    }
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
                         "__wlan_hdd_cfg80211_add_key") )
      goto LABEL_5;
    qdf_mtrace(51, 51, 0x1Eu, *(_BYTE *)(*(_QWORD *)(a2 + 55512) + 8LL), *(_DWORD *)(a7 + 16));
    v23 = *(_QWORD *)(a2 + 2712);
    v22 = _wlan_hdd_validate_context(v23, "__wlan_hdd_cfg80211_add_key");
    if ( v22 )
      goto LABEL_62;
    if ( a6 )
      qdf_mem_copy(&v98, a6, 6u);
    v24 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL);
    v25 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d mode %s(%d) index %d, pairwise %d mac: %02x:%02x:%02x:**:**:%02x link_id %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "__wlan_hdd_cfg80211_add_key",
      v24,
      v25,
      *(unsigned int *)(a2 + 2728),
      (unsigned __int8)a4,
      a5 & 1,
      (unsigned __int8)v98,
      BYTE1(v98),
      BYTE2(v98),
      HIBYTE(v99),
      a3);
    v34 = *(_QWORD *)(v23 + 16);
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55512), 6, "__wlan_hdd_cfg80211_add_key");
    if ( !vdev_by_user )
    {
LABEL_5:
      v22 = -22;
      goto LABEL_62;
    }
    v36 = *(_DWORD *)(a7 + 28);
    v37 = *(__int64 **)(a2 + 55512);
    v38 = vdev_by_user;
    v101 = 0;
    v100 = 0;
    if ( v36 == 4232959 )
    {
      v22 = sme_add_key_krk(v34, *(unsigned __int8 *)(vdev_by_user + 104), *(_QWORD *)a7, *(unsigned int *)(a7 + 16));
      goto LABEL_61;
    }
    if ( v36 == 4232958 )
    {
      v22 = sme_add_key_btk(v34, *(unsigned __int8 *)(vdev_by_user + 104), *(_QWORD *)a7, *(unsigned int *)(a7 + 16));
LABEL_61:
      _hdd_objmgr_put_vdev_by_user(v38, 6, "__wlan_hdd_cfg80211_add_key");
      goto LABEL_62;
    }
    v39 = *v37;
    v40 = *(__int64 **)(*v37 + 24);
    if ( (a5 & 1) != 0 || (*(_DWORD *)(vdev_by_user + 16) | 2) != 2 )
    {
      if ( a6 )
        qdf_mem_copy(&v100, a6, 6u);
    }
    else
    {
      bsspeer = wlan_objmgr_vdev_try_get_bsspeer(vdev_by_user, 6u);
      if ( !bsspeer
        || (v50 = bsspeer,
            qdf_mem_copy(&v100, (const void *)(bsspeer + 48), 6u),
            wlan_objmgr_peer_release_ref(v50, 6u, v51, v52, v53, v54, v55, v56, v57, v58),
            (v59 = wlan_objmgr_vdev_try_get_bsspeer(v38, 6u)) == 0) )
      {
        v76 = "%s: Peer is null return";
LABEL_33:
        qdf_trace_msg(0x33u, 2u, v76, v42, v43, v44, v45, v46, v47, v48, v49, "wlan_hdd_add_key_vdev");
        v22 = -22;
        goto LABEL_61;
      }
      v60 = v59;
      qdf_mem_copy(&v100, (const void *)(v59 + 48), 6u);
      wlan_objmgr_peer_release_ref(v60, 6u, v61, v62, v63, v64, v65, v66, v67, v68);
    }
    v69 = wlan_cfg80211_store_key(v38, a4, (a5 & 1) == 0, (__int64)&v100, a7);
    param = wlan_crypto_get_param(v38, 4u);
    v22 = v69;
    if ( v69 )
      goto LABEL_61;
    v71 = param;
    v72 = osif_nl_to_crypto_cipher_type(*(_DWORD *)(a7 + 28));
    if ( (a5 & 1) != 0 )
      wma_set_peer_ucast_cipher(&v100, (unsigned int)(1 << v72), v71);
    if ( v100 | v101 )
    {
      context = _cds_get_context(71, (__int64)"wlan_hdd_add_key_vdev", v42, v43, v44, v45, v46, v47, v48, v49);
      if ( context && *context && (v74 = *(_QWORD *)(*context + 72LL)) != 0 )
      {
        v75 = *(void (**)(void))(v74 + 176);
        if ( v75 )
        {
          if ( *((_DWORD *)v75 - 1) != -187609570 )
            __break(0x8228u);
          v75();
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v42, v43, v44, v45, v46, v47, v48, v49, "cdp_peer_flush_frags");
      }
    }
    v77 = *(_DWORD *)(v39 + 40);
    if ( v77 <= 1 )
    {
      if ( v77 )
      {
        if ( v77 != 1 )
        {
LABEL_56:
          if ( v77 != 1 )
            wma_update_set_key(*(unsigned __int8 *)(v38 + 104), a5 & 1, a4, &v100, v72);
          v90 = 0;
          goto LABEL_60;
        }
        goto LABEL_42;
      }
    }
    else if ( v77 != 2 )
    {
      if ( v77 != 16 )
      {
        if ( v77 != 3 )
          goto LABEL_56;
LABEL_42:
        if ( *((_BYTE *)v37 + 2367) == 1 )
        {
          v76 = "%s: don't need install key during auth";
          goto LABEL_33;
        }
        v92 = *v40;
        v97[0] = a4;
        is_multipass_sap = wlan_mlme_is_multipass_sap(v92, v42, v43, v44, v45, v46, v47, v48, v49);
        v94 = a4;
        if ( (is_multipass_sap & 1) != 0 )
        {
          v94 = a4;
          if ( *(_WORD *)(a7 + 24) )
          {
            v95 = wlan_hdd_add_vlan(v38, v37[34], a7, a4, v97);
            if ( (v95 & 0x80000000) != 0 )
            {
              v22 = v95;
              goto LABEL_61;
            }
            v94 = v97[0];
          }
        }
        v90 = wlan_hdd_add_key_sap(v37, a5 & 1, v94, v72);
        if ( v90 )
          goto LABEL_60;
        goto LABEL_55;
      }
      cmd = ucfg_nan_send_pasn_peer_create_cmd(*v40, v38, v100 | ((unsigned __int64)v101 << 32));
      if ( cmd )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: PASN peer creation fails %d",
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          "wlan_hdd_add_key_vdev",
          cmd);
        v22 = -22;
        goto LABEL_61;
      }
    }
    v87 = *v37;
    v88 = _hdd_objmgr_get_vdev_by_user(v37, 6, "wlan_hdd_add_key_sta");
    if ( v88 )
    {
      v89 = v88;
      v90 = wlan_cfg80211_crypto_add_key(v88, (__int64)&v100, (a5 & 1) == 0, a4, 1);
      v91 = _hdd_objmgr_put_vdev_by_user(v89, 6, "wlan_hdd_add_key_sta");
      if ( !v90 )
      {
        if ( *(_BYTE *)(v87 + 52208) == 1 )
        {
          ((void (__fastcall *)(__int64))wlan_hdd_send_mode_change_event)(v91);
          *(_BYTE *)(v87 + 52208) = 0;
        }
LABEL_55:
        v77 = *(_DWORD *)(v39 + 40);
        goto LABEL_56;
      }
    }
    else
    {
      v90 = -22;
    }
LABEL_60:
    v22 = v90;
    qdf_trace_msg(0x33u, 8u, "%s: exit", v42, v43, v44, v45, v46, v47, v48, v49, "wlan_hdd_add_key_vdev");
    goto LABEL_61;
  }
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return result;
}
