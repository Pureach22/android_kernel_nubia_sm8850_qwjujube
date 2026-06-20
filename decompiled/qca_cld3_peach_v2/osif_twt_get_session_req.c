__int64 __fastcall osif_twt_get_session_req(__int64 a1, _WORD *a2)
{
  unsigned int v4; // w0
  int v5; // w8
  __int64 result; // x0
  __int64 v7; // x8
  unsigned int v8; // w20
  int v9; // w22
  __int64 v10; // x20
  const char *v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  _DWORD *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w4
  __int64 v41; // x21
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x7
  __int64 v51; // x4
  __int64 v52; // x5
  __int64 v53; // x6
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x5
  __int64 v63; // x6
  __int64 v64; // x7
  int v65; // w9
  __int64 v66; // x8
  __int64 v67; // x0
  unsigned int v68; // w0
  __int64 v69; // x2
  __int64 v70; // x0
  unsigned int v71; // w0
  __int64 v72; // x8
  __int64 v73; // x0
  unsigned int peer_session_params; // w0
  unsigned int params_resp; // w19
  __int64 v76; // x21
  int v77; // [xsp+10h] [xbp-150h] BYREF
  __int16 v78; // [xsp+14h] [xbp-14Ch]
  __int64 v79; // [xsp+18h] [xbp-148h] BYREF
  __int64 v80; // [xsp+20h] [xbp-140h]
  __int64 v81; // [xsp+28h] [xbp-138h]
  __int64 v82; // [xsp+30h] [xbp-130h]
  __int64 v83; // [xsp+38h] [xbp-128h]
  __int64 v84; // [xsp+40h] [xbp-120h]
  int v85; // [xsp+48h] [xbp-118h]
  _QWORD s[34]; // [xsp+50h] [xbp-110h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 16);
  if ( v4 == 1 )
  {
    memset(s, 0, 0x108u);
    if ( ((__int16)a2[1] & 0x80000000) == 0 )
      goto LABEL_10;
    result = _nla_parse(s, 32, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_add_dialog_policy, 31, 0);
    if ( (_DWORD)result )
      goto LABEL_14;
    v20 = *(_QWORD *)(a1 + 216);
    if ( !v20 || !*(_QWORD *)(v20 + 80) )
    {
LABEL_31:
      result = 4294967274LL;
      goto LABEL_14;
    }
    v21 = (_DWORD *)_qdf_mem_malloc(52LL * *(unsigned __int16 *)(a1 + 224), "osif_twt_sap_get_session_params", 2480);
    if ( !v21 )
    {
      result = 4294967284LL;
      goto LABEL_14;
    }
    v30 = (__int64)v21;
    *v21 = *(unsigned __int8 *)(a1 + 168);
    if ( !s[5] || !s[15] )
    {
      v41 = jiffies;
      if ( osif_twt_sap_get_session_params___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: TWT: get_params dialog_id or mac_addr is missing",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "osif_twt_sap_get_session_params");
        osif_twt_sap_get_session_params___last_ticks = v41;
      }
      goto LABEL_75;
    }
    v21[5] = *(unsigned __int8 *)(s[5] + 4LL);
    nla_memcpy(v21 + 1, s[15], 6);
    v39 = *(_DWORD *)(v30 + 20);
    if ( *(_DWORD *)(v30 + 4) == -1 && *(__int16 *)(v30 + 8) == -1 )
    {
      if ( v39 != 255 )
      {
        v76 = jiffies;
        if ( osif_twt_sap_get_session_params___last_ticks_148 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: Bcast MAC valid with dlg_id:%d but here dlg_id is:%d",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "osif_twt_sap_get_session_params",
            255,
            v39);
          osif_twt_sap_get_session_params___last_ticks_148 = v76;
        }
        goto LABEL_75;
      }
    }
    else if ( !v39 )
    {
      *(_DWORD *)(v30 + 20) = 255;
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT: get_params dialog_id %d and mac_addr %02x:%02x:%02x:**:**:%02x",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "osif_twt_sap_get_session_params",
      *(unsigned __int8 *)(v30 + 9));
    v72 = *(_QWORD *)(a1 + 216);
    if ( v72 )
    {
      v73 = *(_QWORD *)(v72 + 80);
      if ( v73 )
      {
        peer_session_params = ucfg_cp_stats_twt_get_peer_session_params(v73, v30);
        if ( peer_session_params )
        {
          params_resp = osif_twt_send_get_params_resp(a1, v30, peer_session_params);
LABEL_76:
          _qdf_mem_free(v30);
          result = qdf_status_to_os_return(params_resp);
          goto LABEL_14;
        }
      }
    }
LABEL_75:
    params_resp = 4;
    goto LABEL_76;
  }
  if ( v4 )
  {
    v10 = jiffies;
    if ( osif_twt_get_session_req___last_ticks - jiffies + 125 < 0 )
    {
      v11 = qdf_opmode_str(v4);
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: TWT get session params is not supported on %s",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "osif_twt_get_session_req",
        v11);
      osif_twt_get_session_req___last_ticks = v10;
    }
    result = 4294967201LL;
    goto LABEL_14;
  }
  memset(s, 0, 0x108u);
  v5 = (__int16)a2[1];
  v85 = 0;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v78 = 0;
  v77 = 0;
  if ( (v5 & 0x80000000) == 0 )
  {
LABEL_10:
    do_trace_netlink_extack("NLA_F_NESTED is missing");
    result = 4294967274LL;
    goto LABEL_14;
  }
  result = _nla_parse(s, 32, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_add_dialog_policy, 31, 0);
  if ( !(_DWORD)result )
  {
    v7 = *(_QWORD *)(a1 + 216);
    if ( !v7 || !*(_QWORD *)(v7 + 80) )
      goto LABEL_31;
    v8 = *(unsigned __int8 *)(a1 + 168);
    LODWORD(v79) = v8;
    v9 = s[5] ? *(unsigned __int8 *)(s[5] + 4LL) : 0;
    HIDWORD(v81) = v9;
    if ( (unsigned int)osif_fill_peer_macaddr(a1, &v77) )
      goto LABEL_31;
    if ( v9 == 255 )
    {
      LOWORD(v80) = -1;
      HIDWORD(v79) = -1;
    }
    else
    {
      LOWORD(v80) = v78;
      HIDWORD(v79) = v77;
      if ( &v79 == (__int64 *)-4LL )
        v50 = 0;
      else
        v50 = HIBYTE(v78);
      if ( &v79 == (__int64 *)-4LL )
        v51 = 0;
      else
        v51 = (unsigned __int8)v77;
      if ( &v79 == (__int64 *)-4LL )
        v52 = 0;
      else
        v52 = BYTE1(v77);
      if ( &v79 == (__int64 *)-4LL )
        v53 = 0;
      else
        v53 = BYTE2(v77);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: TWT: get_params peer mac_addr %02x:%02x:%02x:**:**:%02x",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "osif_twt_sta_get_session_params",
        v51,
        v52,
        v53,
        v50);
    }
    if ( (ucfg_twt_is_setup_done() & 1) != 0 )
    {
      if ( &v79 == (__int64 *)-4LL )
        v62 = 0;
      else
        v62 = BYTE4(v79);
      if ( &v79 == (__int64 *)-4LL )
        v63 = 0;
      else
        v63 = BYTE5(v79);
      if ( &v79 == (__int64 *)-4LL )
        v64 = 0;
      else
        v64 = BYTE6(v79);
      if ( &v79 == (__int64 *)-4LL )
        v65 = 0;
      else
        v65 = BYTE1(v80);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: TWT: get_params dialog_id %d and mac_addr %02x:%02x:%02x:**:**:%02x",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "osif_twt_sta_get_session_params",
        HIDWORD(v81),
        v62,
        v63,
        v64,
        v65);
      v66 = *(_QWORD *)(a1 + 216);
      if ( !v66
        || (v67 = *(_QWORD *)(v66 + 80)) == 0
        || (v68 = ucfg_cp_stats_twt_get_peer_session_params(v67, (__int64)&v79)) == 0 )
      {
        result = qdf_status_to_os_return(4u);
        goto LABEL_14;
      }
      v69 = v68;
      v70 = a1;
    }
    else
    {
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: vdev%d: TWT session %d setup incomplete",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "osif_twt_sta_get_session_params",
        v8,
        HIDWORD(v81));
      v70 = a1;
      HIDWORD(v80) = 3;
      v69 = 1;
    }
    v71 = osif_twt_send_get_params_resp(v70, &v79, v69);
    result = qdf_status_to_os_return(v71);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
