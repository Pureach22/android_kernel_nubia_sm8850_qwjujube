__int64 __fastcall lim_process_sme_tdls_del_sta_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 session_by_bssid; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x0
  __int64 v23; // x4
  const char *v24; // x2
  char v25; // w21
  __int64 v26; // x22
  __int64 v27; // x23
  __int64 v28; // x0
  __int64 v29; // x20
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  const char *v40; // x2
  unsigned int v41; // w22
  char v42; // w21
  __int64 v43; // x23
  __int64 v44; // x24
  __int64 v45; // x0
  __int64 v46; // x20
  unsigned int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w9
  __int64 v57; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // [xsp+0h] [xbp-40h] BYREF
  __int64 v67; // [xsp+8h] [xbp-38h] BYREF
  __int64 v68; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v69)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v70; // [xsp+20h] [xbp-20h]
  __int64 v71; // [xsp+28h] [xbp-18h]
  __int64 v72; // [xsp+30h] [xbp-10h]
  __int64 v73; // [xsp+38h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOBYTE(v66) = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: TDLS Delete STA Request Received",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_sme_tdls_del_sta_req",
    v66);
  session_by_bssid = pe_find_session_by_bssid(a1, (unsigned __int8 *)(a2 + 8), (unsigned __int8 *)&v66);
  if ( !session_by_bssid )
  {
    v23 = *(unsigned __int8 *)(a2 + 4);
    v24 = "%s: PE Session does not exist for given vdev id: %d";
LABEL_8:
    qdf_trace_msg(0x35u, 2u, v24, v13, v14, v15, v16, v17, v18, v19, v20, "lim_process_sme_tdls_del_sta_req", v23);
    v25 = *(_BYTE *)(a2 + 4);
    v26 = *(unsigned __int16 *)(a2 + 18);
    v27 = *(unsigned int *)(a2 + 14);
    v71 = 0;
    v72 = 0;
    v69 = nullptr;
    v70 = 0;
    v67 = 0;
    v68 = 0;
    v28 = _qdf_mem_malloc(0x18u, "lim_send_sme_tdls_del_sta_rsp", 4121);
    if ( v28 )
    {
      *(_BYTE *)v28 = v25;
      v29 = v28;
      *(_DWORD *)(v28 + 4) = 16;
      *(_DWORD *)(v28 + 8) = v27;
      *(_WORD *)(v28 + 12) = (v27 | (unsigned __int64)(v26 << 32)) >> 32;
      *(_QWORD *)(v28 + 16) = *(_QWORD *)(a1 + 21552);
      v68 = v28;
      v69 = tgt_tdls_del_peer_rsp;
      v30 = scheduler_post_message_debug(
              0x35u,
              0,
              73,
              (unsigned __int16 *)&v67,
              0x1027u,
              (__int64)"lim_send_sme_tdls_del_sta_rsp");
      if ( v30 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: post msg fail, %d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "lim_send_sme_tdls_del_sta_rsp",
          v30);
        _qdf_mem_free(v29);
      }
    }
    result = 16;
    goto LABEL_21;
  }
  v21 = session_by_bssid;
  v22 = *(_QWORD *)(session_by_bssid + 16);
  if ( !v22 )
  {
    qdf_trace_msg(0, 2u, "%s: NULL vdev", v13, v14, v15, v16, v17, v18, v19, v20, "wlan_vdev_get_tdls_vdev_obj");
    goto LABEL_13;
  }
  if ( !wlan_objmgr_vdev_get_comp_private_obj(v22, 0xAu) )
  {
LABEL_13:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev_obj: %pK is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_process_sme_tdls_del_sta_req",
      0);
    result = 16;
    goto LABEL_21;
  }
  if ( *(_DWORD *)(v21 + 88) != 2 )
  {
    v40 = "%s: Del sta received in wrong system Role %d";
LABEL_15:
    qdf_trace_msg(0x35u, 2u, v40, v13, v14, v15, v16, v17, v18, v19, v20, "lim_process_sme_tdls_del_sta_req");
    goto LABEL_16;
  }
  if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(v21 + 16), v13, v14, v15, v16, v17, v18, v19, v20) )
  {
    v23 = *(unsigned __int8 *)(a2 + 4);
    v24 = "%s: roaming in progress, reject del sta! for session %d";
    goto LABEL_8;
  }
  if ( (*(_DWORD *)(v21 + 80) | 2) != 0xA )
  {
    v40 = "%s: Del Sta received in invalid LIMsme state: %d";
    goto LABEL_15;
  }
  v56 = *(_DWORD *)(a2 + 14);
  WORD2(v67) = *(_WORD *)(a2 + 18);
  LODWORD(v67) = v56;
  WORD2(v66) = 0;
  v57 = dph_lookup_hash_entry(
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          a1,
          (unsigned __int8 *)&v67,
          (_WORD *)&v66 + 2,
          v21 + 360);
  if ( v57 && *(_BYTE *)(v57 + 344) == 4 )
  {
    result = lim_del_sta(a1, v57, 1, v21);
    if ( !(_DWORD)result )
      goto LABEL_21;
    goto LABEL_17;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: TDLS peer %02x:%02x:%02x:**:**:%02x not found",
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    "lim_tdls_del_sta",
    (unsigned __int8)v67,
    BYTE1(v67),
    BYTE2(v67),
    BYTE5(v67));
LABEL_16:
  LODWORD(result) = 16;
LABEL_17:
  v41 = result;
  v42 = *(_BYTE *)(v21 + 10);
  v43 = *(unsigned __int16 *)(a2 + 18);
  v44 = *(unsigned int *)(a2 + 14);
  v71 = 0;
  v72 = 0;
  v69 = nullptr;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v45 = _qdf_mem_malloc(0x18u, "lim_send_sme_tdls_del_sta_rsp", 4121);
  if ( v45 )
  {
    *(_BYTE *)v45 = v42;
    v46 = v45;
    *(_DWORD *)(v45 + 4) = 16;
    *(_DWORD *)(v45 + 8) = v44;
    *(_WORD *)(v45 + 12) = (v44 | (unsigned __int64)(v43 << 32)) >> 32;
    *(_QWORD *)(v45 + 16) = *(_QWORD *)(a1 + 21552);
    v68 = v45;
    v69 = tgt_tdls_del_peer_rsp;
    v47 = scheduler_post_message_debug(
            0x35u,
            0,
            73,
            (unsigned __int16 *)&v67,
            0x1027u,
            (__int64)"lim_send_sme_tdls_del_sta_rsp");
    if ( v47 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: post msg fail, %d",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "lim_send_sme_tdls_del_sta_rsp",
        v47);
      _qdf_mem_free(v46);
    }
  }
  result = v41;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
