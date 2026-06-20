__int64 __fastcall wlan_cfg80211_set_interop_issues_ap_config(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x8
  _DWORD *v14; // x8
  const char *v15; // x2
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  int v26; // w8
  int v27; // w8
  unsigned int v28; // w0
  unsigned int v29; // w21
  __int64 v33; // x0
  __int64 result; // x0
  __int64 v35; // x19
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w19
  __int64 vdev_by_user; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x8
  __int64 v55; // x19
  const char *v56; // x2
  int v57; // w24
  __int64 v58; // x20
  unsigned __int16 *v59; // x26
  unsigned __int64 v60; // x28
  unsigned int v61; // w9
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x0
  const char *v71; // x2
  int v72; // w30
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x8
  const char *v82; // x2
  __int64 v83; // [xsp+8h] [xbp-D8h] BYREF
  _QWORD v84[8]; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v85; // [xsp+50h] [xbp-90h]
  __int64 v86; // [xsp+58h] [xbp-88h]
  __int64 v87; // [xsp+60h] [xbp-80h]
  _QWORD v88[5]; // [xsp+68h] [xbp-78h] BYREF
  _QWORD v89[2]; // [xsp+90h] [xbp-50h] BYREF
  _WORD *v90; // [xsp+A0h] [xbp-40h]
  __int64 v91; // [xsp+A8h] [xbp-38h]
  _QWORD v92[3]; // [xsp+B0h] [xbp-30h] BYREF
  __int64 v93; // [xsp+C8h] [xbp-18h]
  __int64 v94; // [xsp+D0h] [xbp-10h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = *(_QWORD *)(a1 + 488);
  v83 = 0;
  result = _osif_psoc_sync_op_start(v33, &v83, (__int64)"wlan_cfg80211_set_interop_issues_ap_config");
  if ( (_DWORD)result )
    goto LABEL_54;
  v35 = *(_QWORD *)(a2 + 32);
  v90 = nullptr;
  v91 = 0;
  v89[0] = 0;
  v89[1] = 0;
  v87 = 0;
  memset(v88, 0, sizeof(v88));
  v85 = 0;
  v86 = 0;
  memset(v84, 0, sizeof(v84));
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Command not allowed in FTM mode",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "__wlan_cfg80211_set_interop_issues_ap_config");
    v44 = -1;
LABEL_13:
    _osif_psoc_sync_op_stop(v83, (__int64)"wlan_cfg80211_set_interop_issues_ap_config");
    result = v44;
    goto LABEL_54;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                   *(_QWORD *)(v35 + 55520),
                   0x33u,
                   (__int64)"__wlan_cfg80211_set_interop_issues_ap_config");
  if ( !vdev_by_user )
  {
    v56 = "%s: Invalid vdev";
    goto LABEL_12;
  }
  v54 = *(_QWORD *)(vdev_by_user + 216);
  if ( !v54 )
  {
    _hdd_objmgr_put_vdev_by_user(
      vdev_by_user,
      0x33u,
      (__int64)"__wlan_cfg80211_set_interop_issues_ap_config",
      nullptr,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53);
    goto LABEL_11;
  }
  v55 = *(_QWORD *)(v54 + 80);
  _hdd_objmgr_put_vdev_by_user(
    vdev_by_user,
    0x33u,
    (__int64)"__wlan_cfg80211_set_interop_issues_ap_config",
    (unsigned int *)v54,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53);
  if ( !v55 )
  {
LABEL_11:
    v56 = "%s: Invalid psoc";
    goto LABEL_12;
  }
  if ( (unsigned int)_nla_parse(v89, 3, a3, a4, &interop_issues_ap_policy, 31, 0) )
  {
    v56 = "%s: Invalid ATTR";
LABEL_12:
    qdf_trace_msg(
      0x48u,
      2u,
      v56,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "__wlan_cfg80211_set_interop_issues_ap_config");
    v44 = -22;
    goto LABEL_13;
  }
  if ( !v90 || (v57 = (unsigned __int16)(*v90 - 4), (unsigned int)v57 < 4) )
  {
    LODWORD(v58) = 0;
LABEL_29:
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Num of interop issues ap: %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "__wlan_cfg80211_set_interop_issues_ap_config",
      (unsigned int)v58);
    HIDWORD(v84[0]) = v58;
    LOBYTE(v84[0]) = 1;
    ucfg_set_interop_issues_ap_config(v55, (__int64)v84);
    v44 = 0;
    goto LABEL_13;
  }
  v58 = 0;
  v59 = v90 + 2;
  v60 = -120;
  v93 = 0;
  memset(v92, 0, sizeof(v92));
  while ( 1 )
  {
    v61 = *v59;
    if ( v61 < 4 || v57 < v61 )
      goto LABEL_29;
    if ( !v60 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Ignoring excess",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "wlan_parse_interop_issues_ap");
      LODWORD(v58) = 20;
      goto LABEL_29;
    }
    if ( (unsigned int)_nla_parse(v92, 3, v59 + 2, (unsigned __int16)(v61 - 4), &interop_issues_ap_policy, 31, 0) )
    {
      v82 = "%s: nla_parse failed";
LABEL_33:
      qdf_trace_msg(0x48u, 2u, v82, v62, v63, v64, v65, v66, v67, v68, v69, "wlan_parse_interop_issues_ap");
      LODWORD(v58) = -22;
      goto LABEL_29;
    }
    if ( !v93 )
    {
      v82 = "%s: attr addr failed";
      goto LABEL_33;
    }
    v70 = nla_memcpy((char *)v89 + v60, v93, 6);
    if ( v60 + 4 < 0xFFFFFFFFFFFFFF7FLL || v60 + 2 < 0xFFFFFFFFFFFFFF80LL || v60 <= 0xFFFFFFFFFFFFFF7ELL )
      break;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "wlan_parse_interop_issues_ap",
      *((unsigned __int8 *)v89 + v60),
      *((unsigned __int8 *)v89 + v60 + 1),
      *((unsigned __int8 *)v89 + v60 + 2),
      *((unsigned __int8 *)v89 + v60 + 5));
    ++v58;
    v60 += 6LL;
    v81 = (*v59 + 3) & 0x1FFFC;
    v57 -= v81;
    v59 = (unsigned __int16 *)((char *)v59 + v81);
    if ( v57 <= 3 )
      goto LABEL_29;
  }
  __break(1u);
  if ( v72 )
    return wlan_cfg80211_init_interop_issues_ap(v70);
  qdf_trace_msg(v70, 8u, v71, v73, v74, v75, v76, v77, v78, v79, v80);
  LODWORD(v88[0]) = 0;
  v12 = *(_QWORD *)(*(_QWORD *)(v55 + 8) + 20112LL);
  if ( !v12 )
  {
    v15 = "%s: mon soc is NULL";
    goto LABEL_44;
  }
  v13 = *(_QWORD *)(v12 + 416);
  if ( !v13 || (v14 = *(_DWORD **)(v13 + 888)) == nullptr )
  {
    v15 = "%s: callback not registered";
LABEL_44:
    qdf_trace_msg(0x92u, 8u, v15, v4, v5, v6, v7, v8, v9, v10, v11, "dp_mon_rx_config_packet_type_subtype");
    goto LABEL_45;
  }
  if ( *(v14 - 1) != 29831664 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, const char *, const char *))v14)(
    v88,
    "%s: %02x:%02x:%02x:**:**:%02x",
    "wlan_parse_interop_issues_ap");
LABEL_45:
  v16 = htt_htc_pkt_alloc(v55);
  if ( v16 )
  {
    *(_QWORD *)v16 = 0;
    *(_QWORD *)(v16 + 32) = dp_htt_h2t_send_complete_free_netbuf;
    v25 = v16;
    *(_QWORD *)(v16 + 48) = *(_QWORD *)(v58 + 224);
    if ( (*(_BYTE *)(v58 + 68) & 4) != 0 )
      v26 = *(unsigned __int16 *)(v58 + 66);
    else
      v26 = 0;
    *(_DWORD *)(v16 + 60) = *(_DWORD *)(v58 + 112) + v26;
    v27 = *(_DWORD *)(v55 + 64);
    *(_WORD *)(v16 + 72) = 13;
    *(_DWORD *)(v16 + 88) = 0;
    *(_BYTE *)(v16 + 80) = 0;
    *(_DWORD *)(v16 + 64) = v27;
    *(_QWORD *)(v16 + 112) = v58;
    v28 = htc_send_pkt(*(_QWORD *)(v55 + 48), v16 + 16);
    if ( v28 )
    {
      v29 = v28;
      ++*(_DWORD *)(v55 + 104);
      _qdf_nbuf_free(v58);
      htt_htc_pkt_free(v55, v25);
      result = v29;
    }
    else
    {
      result = 0;
      if ( (*(_DWORD *)(v25 + 68) | 8) == 9 )
        ++*(_DWORD *)(v55 + 104);
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: pkt alloc failed, ring_type %d ring_id %d htt_ring_id %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "htt_h2t_rx_ring_cfg",
      &interop_issues_ap_policy,
      BYTE4(v85),
      "wlan_parse_interop_issues_ap");
    _qdf_nbuf_free(v58);
    result = 16;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
