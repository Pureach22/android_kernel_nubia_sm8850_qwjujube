__int64 __fastcall lim_send_frame(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v16; // w8
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x23
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _QWORD *v36; // x0
  void *v37; // x0
  __int64 *v38; // x1
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 peer_link_addr; // x0
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // w9
  unsigned __int8 *peer_mld_addr; // x24
  unsigned int bss_peer_mac; // w24
  __int64 bsspeer; // x0
  unsigned int v61; // w8
  __int16 v62; // w8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned __int8 *v71; // x22
  __int64 v72; // x23
  __int64 v73; // x0
  __int16 v74; // w25
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x24
  int v84; // w26
  __int64 session_by_vdev_id; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  int v94; // w8
  unsigned int *v95; // x1
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 entry_by_bssid; // x0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  unsigned int v113; // w26
  __int64 v114; // x27
  __int64 v115; // x0
  int v116; // w9
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  const char *v133; // x2
  const char *v134; // x3
  __int64 v135; // x4
  __int64 v136; // x0
  __int64 v137; // x0
  __int64 v138; // x8
  _QWORD *context; // x0
  unsigned int v140; // w20
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  int v149; // [xsp+8h] [xbp-88h]
  int v150; // [xsp+10h] [xbp-80h]
  int v151; // [xsp+18h] [xbp-78h]
  int v152; // [xsp+20h] [xbp-70h]
  int v153; // [xsp+30h] [xbp-60h]
  int v154; // [xsp+38h] [xbp-58h]
  __int64 v155; // [xsp+50h] [xbp-40h] BYREF
  void *v156; // [xsp+58h] [xbp-38h] BYREF
  unsigned int v157; // [xsp+64h] [xbp-2Ch] BYREF
  __int64 v158; // [xsp+68h] [xbp-28h] BYREF
  __int64 v159; // [xsp+70h] [xbp-20h]
  __int64 v160; // [xsp+78h] [xbp-18h]
  __int64 v161; // [xsp+80h] [xbp-10h]
  __int64 v162; // [xsp+88h] [xbp-8h]

  v162 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(unsigned __int16 *)a3;
  v155 = 0;
  v156 = nullptr;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: sending fc->type: %d fc->subType: %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_send_frame",
    (v16 >> 2) & 3,
    (unsigned __int8)v16 >> 4);
  result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             *(_QWORD *)(a1 + 21624),
             a2,
             7);
  if ( !result )
    goto LABEL_53;
  v26 = result;
  WORD2(v158) = 0;
  LODWORD(v158) = 0;
  if ( (wlan_cm_is_sae_auth_addr_conversion_required(result, v18, v19, v20, v21, v22, v23, v24, v25) & 1) == 0 )
    goto LABEL_19;
  v27 = (unsigned int *)*(unsigned int *)(v26 + 16);
  if ( !(_DWORD)v27 )
  {
    if ( wlan_cm_is_vdev_active(v26, v28, v29, v30, v31, v32, v33, v34, v35) )
    {
      peer_link_addr = wlan_cm_roaming_get_peer_link_addr(v26, v39, v40, v41, v42, v43, v44, v45, v46);
      if ( peer_link_addr )
      {
        v57 = *(_DWORD *)peer_link_addr;
        WORD2(v158) = *(_WORD *)(peer_link_addr + 4);
        LODWORD(v158) = v57;
        peer_mld_addr = (unsigned __int8 *)wlan_cm_roaming_get_peer_mld_addr(
                                             v26,
                                             v49,
                                             v50,
                                             v51,
                                             v52,
                                             v53,
                                             v54,
                                             v55,
                                             v56);
        if ( !peer_mld_addr )
          goto LABEL_19;
LABEL_14:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev:%d DA: %02x:%02x:%02x:**:**:%02x mld addr: %02x:%02x:%02x:**:**:%02x Link addr: %02x:%02x:%02x:**:**:%02x",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "lim_update_mld_to_link_address",
          *(unsigned __int8 *)(v26 + 168),
          a3[4],
          a3[5],
          a3[6],
          a3[9],
          *peer_mld_addr,
          peer_mld_addr[1],
          peer_mld_addr[2],
          peer_mld_addr[5],
          (unsigned __int8)v158,
          BYTE1(v158),
          BYTE2(v158),
          BYTE5(v158));
        if ( !(unsigned int)qdf_mem_cmp(a3 + 4, peer_mld_addr, 6u) )
          qdf_mem_copy(a3 + 4, &v158, 6u);
        v37 = a3 + 16;
        v38 = &v158;
        goto LABEL_17;
      }
      bss_peer_mac = 16;
    }
    else
    {
      bss_peer_mac = wlan_vdev_get_bss_peer_mac(v26, &v158, v39, v40, v41, v42, v43, v44, v45, v46);
      if ( !bss_peer_mac )
      {
        bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v26, 0x43u);
        if ( !bsspeer )
          goto LABEL_19;
        peer_mld_addr = (unsigned __int8 *)(bsspeer + 792);
        wlan_objmgr_peer_release_ref(bsspeer, 0x43u, v28, v29, v30, v31, v32, v33, v34, v35);
        if ( !peer_mld_addr )
          goto LABEL_19;
        goto LABEL_14;
      }
    }
LABEL_37:
    wlan_objmgr_vdev_release_ref(v26, 7u, v48, v49, v50, v51, v52, v53, v54, v55, v56);
    v133 = "%s: SAE address conversion failure with status:%d";
    v134 = "lim_send_frame";
    v135 = bss_peer_mac;
    goto LABEL_38;
  }
  if ( (_DWORD)v27 != 1 )
    goto LABEL_19;
  v36 = lim_search_pre_auth_list_by_mld_addr(a1, a3 + 4);
  if ( v36 )
  {
    qdf_mem_copy(a3 + 4, v36 + 1, 6u);
    v37 = a3 + 16;
    v38 = (__int64 *)(v26 + 86);
LABEL_17:
    qdf_mem_copy(v37, v38, 6u);
    qdf_mem_copy(a3 + 10, (const void *)(v26 + 86), 6u);
    goto LABEL_19;
  }
  if ( !lim_search_pre_auth_list(a1, a3 + 4) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: pre_auth not found by MLD: %02x:%02x:%02x:**:**:%02x",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "lim_update_mld_to_link_address",
      a3[4],
      a3[5],
      a3[6],
      a3[9]);
    bss_peer_mac = 4;
    goto LABEL_37;
  }
LABEL_19:
  wlan_objmgr_vdev_release_ref(v26, 7u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
  v61 = *(unsigned __int16 *)(a1 + 21604);
  if ( v61 <= 0xFFE )
    v62 = v61 + 1;
  else
    v62 = 2048;
  *(_WORD *)(a1 + 21604) = v62;
  *((_WORD *)a3 + 11) = (16 * (v62 & 0xF)) | *((_WORD *)a3 + 11) & 0xFF0F;
  *((_WORD *)a3 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v62 & 0xF));
  if ( (unsigned int)cds_packet_alloc(a4, &v156, &v155) )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: call to bufAlloc failed for AUTH frame",
               v63,
               v64,
               v65,
               v66,
               v67,
               v68,
               v69,
               v70,
               "lim_send_frame");
    goto LABEL_53;
  }
  qdf_mem_copy(v156, a3, (unsigned __int16)a4);
  v72 = v155;
  v71 = (unsigned __int8 *)v156;
  v73 = *(_QWORD *)(a1 + 21632);
  v157 = 0;
  if ( (unsigned int)wlan_get_opmode_from_vdev_id(v73, a2) == 16 )
  {
    v74 = (unsigned __int8)a2;
    qdf_mtrace(53, 54, 2u, a2, 0);
    v83 = 0;
    v84 = 12;
    goto LABEL_51;
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( !session_by_vdev_id )
  {
    cds_packet_free(v72);
    v133 = "%s: session not found for given vdev_id %d";
    v134 = "lim_tx_mgmt_frame";
    v135 = (unsigned __int8)a2;
LABEL_38:
    result = qdf_trace_msg(0x35u, 2u, v133, v125, v126, v127, v128, v129, v130, v131, v132, v134, v135);
    goto LABEL_53;
  }
  v74 = *(_WORD *)(session_by_vdev_id + 8);
  v83 = session_by_vdev_id;
  qdf_mtrace(53, 54, 2u, v74, 0);
  if ( (*(_WORD *)v71 & 0xF0) != 0xB0 )
    goto LABEL_49;
  v94 = *((unsigned __int16 *)v71 + 12);
  v95 = nullptr;
  v160 = 0;
  v161 = 0;
  v158 = 0;
  v159 = 0;
  if ( v94 == 3 )
  {
    if ( wlan_cm_is_vdev_active(*(_QWORD *)(v83 + 16), v86, v87, v88, v89, v90, v91, v92, v93) )
    {
      entry_by_bssid = wlan_scan_get_entry_by_bssid(*(_QWORD *)(a1 + 21632), v71 + 16);
      if ( entry_by_bssid )
      {
        v113 = *(_DWORD *)(entry_by_bssid + 1192);
        v114 = entry_by_bssid;
        v157 = v113;
        if ( wlan_reg_is_24ghz_ch_freq(v113) )
        {
          v115 = *(_QWORD *)(a1 + 21624);
          v116 = *(_DWORD *)(v114 + 1888) + 65500;
          v158 = *(_QWORD *)(v114 + 1896) + 36LL;
          LODWORD(v159) = (unsigned __int16)v116;
          if ( (wlan_action_oui_search(v115, &v158, 17) & 1) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Send pre-auth with 6Mbps on freq %d",
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              "lim_tx_mgmt_frame",
              v113);
            util_scan_free_cache_entry_2(v114);
            v84 = 4;
            goto LABEL_51;
          }
        }
        v136 = *(_QWORD *)(v114 + 1320);
        if ( v136 )
          _qdf_mem_free(v136);
        v137 = *(_QWORD *)(v114 + 1896);
        if ( v137 )
          _qdf_mem_free(v137);
        _qdf_mem_free(v114);
LABEL_47:
        if ( v113 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: TX SAE pre-auth frame on freq %d",
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            "lim_tx_mgmt_frame",
            v113);
          v95 = &v157;
          goto LABEL_50;
        }
LABEL_49:
        v95 = nullptr;
        goto LABEL_50;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x scan entry not found",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "lim_tx_mgmt_frame",
        v71[16],
        v71[17],
        v71[18],
        v71[21]);
    }
    v138 = *(_QWORD *)(v83 + 7432);
    if ( !v138 )
      goto LABEL_49;
    v113 = *(unsigned __int16 *)(v138 + 10);
    v157 = v113;
    goto LABEL_47;
  }
LABEL_50:
  v84 = ((__int64 (__fastcall *)(__int64, unsigned int *))lim_get_min_session_txrate)(v83, v95);
LABEL_51:
  context = _cds_get_context(54, (__int64)"lim_tx_mgmt_frame", v75, v76, v77, v78, v79, v80, v81, v82);
  LOWORD(v152) = v157;
  LOWORD(v154) = 0;
  LOBYTE(v153) = 0;
  LOBYTE(v151) = 0;
  LOBYTE(v150) = a2;
  LOBYTE(v149) = 0;
  v140 = wma_tx_packet(
           context,
           v72,
           a4,
           3,
           1,
           7,
           lim_tx_complete,
           v71,
           lim_auth_tx_complete_cnf,
           v149,
           v150,
           v151,
           v152,
           v84,
           v153,
           v154);
  result = qdf_trace(53, 5u, v74, v140);
  if ( v140 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Could not send Auth frame, retCode=%X",
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      v147,
      v148,
      "lim_tx_mgmt_frame",
      v140);
    *(_DWORD *)(a1 + 21660) = 3;
    result = lim_diag_event_report(a1, 78, v83, 2);
  }
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
