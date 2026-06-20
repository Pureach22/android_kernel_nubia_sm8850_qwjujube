__int64 __fastcall sap_signal_hdd_event(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        const void *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x4
  __int64 v36; // x19
  const char *v37; // x5
  const char *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // w8
  const char *v58; // x5
  __int64 v59; // x6
  int v60; // w22
  __int64 v61; // x8
  __int16 v62; // w10
  char v63; // w9
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  int v80; // w9
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  int v89; // w9
  int v90; // w8
  int v91; // w8
  const void *v92; // x1
  void *v93; // x0
  __int64 v94; // x8
  __int64 v95; // x9
  __int64 v96; // x8
  int v97; // w9
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  const char *v106; // x2
  int v107; // w8
  int v108; // w9
  char v109; // w8
  __int64 v110; // x9
  __int64 v111; // x11
  __int64 v112; // x12
  __int64 v113; // x11
  __int64 v114; // x8
  __int64 v115; // x10
  __int64 v116; // x9
  __int64 (__fastcall *v117)(__int64, __int64); // x8
  unsigned int v118; // w20
  const char *v119; // x2

  if ( !*(_QWORD *)(a1 + 720) )
    return 16;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid MAC context", v17, v18, v19, v20, v21, v22, v23, v24, "sap_signal_hdd_event");
    return 16;
  }
  v25 = (__int64)context;
  v26 = _qdf_mem_malloc(0x218u, "sap_signal_hdd_event", 2797);
  if ( !v26 )
    return 2;
  v35 = *(unsigned __int8 *)(a1 + 12);
  v36 = v26;
  v37 = "eSAP_DFS_CAC_START";
  v38 = "eSAP_STA_ASSOC_EVENT";
  switch ( a3 )
  {
    case 0u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_START_BSS_EVENT",
        0);
      *(_DWORD *)v36 = 0;
      v47 = *(unsigned __int8 *)(a1 + 12);
      *(_BYTE *)(v36 + 22) = v47;
      if ( v47 == 255 )
      {
        v106 = "%s: Invalid sessionId";
        goto LABEL_72;
      }
      *(_BYTE *)(v36 + 8) = (_BYTE)a4;
      *(_WORD *)(v36 + 20) = *(unsigned __int8 *)(a1 + 1626);
      *(_DWORD *)(v36 + 12) = *(_DWORD *)a1;
      *(_DWORD *)(v36 + 16) = *(_DWORD *)(a1 + 1500);
      if ( !(_BYTE)a4 )
      {
        sap_update_cac_history(a1, 0);
        sap_update_mcs_rate(a1, 1);
      }
      goto LABEL_75;
    case 1u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_STOP_BSS_EVENT",
        1);
      *(_DWORD *)v36 = 1;
      *(_BYTE *)(v36 + 8) = (_BYTE)a4;
      goto LABEL_75;
    case 2u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_STA_ASSOC_IND",
        2);
      if ( !a2 )
        goto LABEL_52;
      *(_DWORD *)v36 = 2;
      v61 = a2;
      v62 = *(_WORD *)(a2 + 27);
      *(_DWORD *)(v36 + 8) = *(_DWORD *)(a2 + 23);
      *(_WORD *)(v36 + 12) = v62;
      v63 = *(_BYTE *)(a2 + 41);
      *(_BYTE *)(v36 + 15) = 0;
      *(_BYTE *)(v36 + 14) = v63;
      *(_DWORD *)(v36 + 16) = *(_DWORD *)(a2 + 112);
      *(_QWORD *)(v36 + 24) = *(_QWORD *)(a2 + 120);
      *(_BYTE *)(v36 + 32) = *(_BYTE *)(a2 + 96);
      *(_BYTE *)(v36 + 33) = *(_BYTE *)(a2 + 294);
      if ( !*(_QWORD *)(a2 + 336) )
        goto LABEL_22;
      if ( (sap_fill_owe_ie_in_assoc_ind() & 1) == 0 )
      {
        v119 = "%s: Failed to fill OWE IE";
LABEL_81:
        qdf_trace_msg(0x39u, 2u, v119, v64, v65, v66, v67, v68, v69, v70, v71, "sap_signal_hdd_event");
        _qdf_mem_free(*(_QWORD *)(a2 + 336));
        *(_QWORD *)(a2 + 336) = 0;
        goto LABEL_82;
      }
      if ( (sap_save_owe_pending_assoc_ind(a1, *(_QWORD *)(a2 + 336)) & 1) == 0 )
      {
        v119 = "%s: Failed to save assoc ind";
        goto LABEL_81;
      }
      v61 = a2;
      *(_QWORD *)(a2 + 336) = 0;
LABEL_22:
      if ( *(_QWORD *)(v61 + 344) )
      {
        if ( (sap_save_ft_pending_assoc_ind(a1) & 1) != 0 )
        {
          *(_QWORD *)(a2 + 344) = 0;
          goto LABEL_75;
        }
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: Failed to save ft assoc ind",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          "sap_signal_hdd_event");
        _qdf_mem_free(*(_QWORD *)(a2 + 344));
        *(_QWORD *)(a2 + 344) = 0;
LABEL_82:
        _qdf_mem_free(v36);
        return 4;
      }
      else
      {
LABEL_75:
        v117 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 720);
        if ( *((_DWORD *)v117 - 1) != 1853351263 )
          __break(0x8228u);
        v118 = v117(a1, v36);
        _qdf_mem_free(v36);
        return v118;
      }
    case 3u:
      goto LABEL_26;
    case 4u:
      v38 = "eSAP_STA_REASSOC_EVENT";
LABEL_26:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        v38,
        a3);
      if ( a2 )
      {
        if ( *(_DWORD *)(a1 + 728) == 3 )
        {
          qdf_trace_msg(
            0x39u,
            2u,
            "%s: SAP is stopping, not able to handle any incoming (re)assoc req",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "sap_signal_hdd_event");
          _qdf_mem_free(v36);
          return 10;
        }
        if ( !(unsigned int)sap_populate_peer_assoc_info(v25, a2, v36) )
        {
          if ( *(_BYTE *)(a2 + 16) )
            v107 = 4;
          else
            v107 = 3;
          *(_DWORD *)v36 = v107;
          v108 = *(_DWORD *)(a2 + 23);
          *(_WORD *)(v36 + 12) = *(_WORD *)(a2 + 27);
          *(_DWORD *)(v36 + 8) = v108;
          *(_BYTE *)(v36 + 20) = *(_BYTE *)(a2 + 41);
          *(_DWORD *)(v36 + 36) = *(_DWORD *)(a2 + 32);
          *(_DWORD *)(v36 + 44) = *(_DWORD *)(a2 + 140);
          *(_DWORD *)(v36 + 56) = *(_DWORD *)(a2 + 152);
          *(_DWORD *)(v36 + 48) = *(_DWORD *)(a2 + 144);
          *(_DWORD *)(v36 + 52) = *(_DWORD *)(a2 + 148);
          *(_DWORD *)(v36 + 60) = *(_DWORD *)(a2 + 156);
          *(_DWORD *)(v36 + 64) = *(_DWORD *)(a2 + 160);
          *(_BYTE *)(v36 + 68) = *(_BYTE *)(a2 + 164);
          *(_DWORD *)(v36 + 72) = *(_DWORD *)(a2 + 168);
          v109 = *(_BYTE *)(a2 + 96);
          *(_BYTE *)(v36 + 21) = (_BYTE)a4;
          *(_BYTE *)(v36 + 40) = v109;
          *(_BYTE *)(v36 + 41) = *(_BYTE *)(a2 + 136);
          *(_BYTE *)(v36 + 84) = *(_BYTE *)(a2 + 274);
          *(_BYTE *)(v36 + 85) = *(_BYTE *)(a2 + 275);
          *(_BYTE *)(v36 + 86) = *(_BYTE *)(a2 + 276);
          *(_BYTE *)(v36 + 87) = *(_BYTE *)(a2 + 277);
          *(_DWORD *)(v36 + 88) = *(_DWORD *)(a2 + 280);
          *(_DWORD *)(v36 + 92) = *(_DWORD *)(a2 + 284);
          *(_BYTE *)(v36 + 96) = *(_BYTE *)(a2 + 288);
          *(_BYTE *)(v36 + 97) = *(_BYTE *)(a2 + 289);
          *(_BYTE *)(v36 + 98) = *(_BYTE *)(a2 + 291);
          *(_BYTE *)(v36 + 99) = *(_BYTE *)(a2 + 290);
          *(_BYTE *)(v36 + 100) = *(_BYTE *)(a2 + 292);
          *(_BYTE *)(v36 + 101) = *(_BYTE *)(a2 + 293);
          *(_BYTE *)(v36 + 102) = *(_BYTE *)(a2 + 294);
          *(_DWORD *)(v36 + 104) = *(_DWORD *)(a2 + 296);
          *(_BYTE *)(v36 + 108) = *(_BYTE *)(a2 + 300);
          if ( *(_BYTE *)(a2 + 196) )
          {
            v110 = *(_QWORD *)(a2 + 220);
            v111 = *(_QWORD *)(a2 + 196);
            v112 = *(_QWORD *)(a2 + 204);
            *(_QWORD *)(v36 + 128) = *(_QWORD *)(a2 + 212);
            *(_QWORD *)(v36 + 136) = v110;
            *(_QWORD *)(v36 + 112) = v111;
            *(_QWORD *)(v36 + 120) = v112;
            v113 = *(_QWORD *)(a2 + 228);
            v114 = *(_QWORD *)(a2 + 236);
            v115 = *(_QWORD *)(a2 + 244);
            *(_DWORD *)(v36 + 168) = *(_DWORD *)(a2 + 252);
            *(_QWORD *)(v36 + 144) = v113;
            *(_QWORD *)(v36 + 152) = v114;
            *(_QWORD *)(v36 + 160) = v115;
          }
          if ( *(_BYTE *)(a2 + 256) )
          {
            v116 = *(_QWORD *)(a2 + 256);
            *(_QWORD *)(v36 + 180) = *(_QWORD *)(a2 + 264);
            *(_QWORD *)(v36 + 172) = v116;
          }
          *(_BYTE *)(v36 + 191) = *(_BYTE *)(a2 + 272);
          *(_BYTE *)(v36 + 188) = *(_BYTE *)(a2 + 273);
          *(_WORD *)(v36 + 189) = *(_WORD *)(a2 + 316);
          *(_BYTE *)(v36 + 198) = *(_BYTE *)(a2 + 376);
          *(_BYTE *)(v36 + 199) = *(_BYTE *)(a2 + 377);
          *(_WORD *)(v36 + 200) = *(_WORD *)(a2 + 378);
          goto LABEL_75;
        }
      }
      else
      {
        v106 = "%s: Invalid CSR Roam Info";
LABEL_72:
        qdf_trace_msg(0x39u, 2u, v106, v39, v40, v41, v42, v43, v44, v45, v46, "sap_signal_hdd_event");
      }
      goto LABEL_82;
    case 5u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_STA_DISASSOC_EVENT",
        5);
      if ( !a2 )
        goto LABEL_52;
      *(_DWORD *)v36 = 5;
      v89 = *(_DWORD *)(a2 + 23);
      *(_WORD *)(v36 + 12) = *(_WORD *)(a2 + 27);
      *(_DWORD *)(v36 + 8) = v89;
      *(_BYTE *)(v36 + 14) = *(_BYTE *)(a2 + 41);
      if ( *(_DWORD *)(a2 + 36) == 2 )
        v90 = 65537;
      else
        v90 = 0x10000;
      *(_DWORD *)(v36 + 24) = v90;
      v91 = *(_DWORD *)(a2 + 32);
      *(_BYTE *)(v36 + 15) = (_BYTE)a4;
      *(_DWORD *)(v36 + 16) = v91;
      *(_DWORD *)(v36 + 28) = *(_DWORD *)(a2 + 304);
      *(_DWORD *)(v36 + 36) = *(_DWORD *)(a2 + 312);
      *(_DWORD *)(v36 + 32) = *(_DWORD *)(a2 + 308);
      *(_DWORD *)(v36 + 40) = *(_DWORD *)(a2 + 320);
      *(_DWORD *)(v36 + 44) = *(_DWORD *)(a2 + 324);
      *(_DWORD *)(v36 + 20) = *(unsigned __int8 *)(a2 + 40);
      goto LABEL_75;
    case 6u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_STA_SET_KEY_EVENT",
        6);
      if ( !a2 )
        goto LABEL_52;
      *(_DWORD *)v36 = 6;
      *(_BYTE *)(v36 + 8) = (_BYTE)a4;
      v97 = *(_DWORD *)(a2 + 23);
      *(_WORD *)(v36 + 13) = *(_WORD *)(a2 + 27);
      *(_DWORD *)(v36 + 9) = v97;
      goto LABEL_75;
    case 7u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_STA_MIC_FAILURE_EVENT",
        7);
      if ( !a2 )
        goto LABEL_52;
      *(_DWORD *)v36 = 7;
      qdf_mem_copy((void *)(v36 + 8), *(const void **)(a2 + 88), 6u);
      qdf_mem_copy((void *)(v36 + 14), (const void *)(*(_QWORD *)(a2 + 88) + 6LL), 6u);
      qdf_mem_copy((void *)(v36 + 20), (const void *)(*(_QWORD *)(a2 + 88) + 12LL), 6u);
      v93 = (void *)(v36 + 29);
      *(_BYTE *)(v36 + 26) = *(_BYTE *)(*(_QWORD *)(a2 + 88) + 18LL);
      *(_BYTE *)(v36 + 27) = *(_BYTE *)(*(_QWORD *)(a2 + 88) + 19LL);
      *(_BYTE *)(v36 + 28) = *(_BYTE *)(*(_QWORD *)(a2 + 88) + 20LL);
      v92 = (const void *)(*(_QWORD *)(a2 + 88) + 21LL);
      goto LABEL_46;
    case 8u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_WPS_PBC_PROBE_REQ_EVENT",
        8);
      if ( !a2 )
        goto LABEL_52;
      *(_DWORD *)v36 = 8;
      qdf_mem_copy((void *)(v36 + 16), *(const void **)(a2 + 88), 0x208u);
      goto LABEL_75;
    case 9u:
      v58 = "eSAP_DISCONNECT_ALL_P2P_CLIENT";
      v59 = 9;
      v60 = 9;
      goto LABEL_49;
    case 0xAu:
      v58 = "eSAP_MAC_TRIG_STOP_BSS_EVENT";
      v59 = 10;
      v60 = 10;
LABEL_49:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        v58,
        v59);
      *(_DWORD *)v36 = v60;
      *(_DWORD *)(v36 + 8) = (_DWORD)a4;
      goto LABEL_75;
    case 0xBu:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_UNKNOWN_STA_JOIN",
        11);
      v92 = a4;
      *(_DWORD *)v36 = 11;
      v93 = (void *)(v36 + 8);
LABEL_46:
      qdf_mem_copy(v93, v92, 6u);
      goto LABEL_75;
    case 0xCu:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_MAX_ASSOC_EXCEEDED",
        12);
      if ( !a2 )
        goto LABEL_52;
      *(_DWORD *)v36 = 12;
      v80 = *(_DWORD *)(a2 + 23);
      *(_WORD *)(v36 + 12) = *(_WORD *)(a2 + 27);
      *(_DWORD *)(v36 + 8) = v80;
      goto LABEL_75;
    case 0xDu:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_CHANNEL_CHANGE_EVENT",
        13);
      *(_DWORD *)(*(_QWORD *)(a1 + 1536) + 564LL) = *(_DWORD *)a1;
      *(_WORD *)(*(_QWORD *)(a1 + 1536) + 42LL) = *(_DWORD *)(a1 + 1500);
      sap_config_acs_result(v25, a1, *(_DWORD *)(a1 + 4));
      *(_DWORD *)v36 = 13;
      *(_DWORD *)(v36 + 8) = *(_DWORD *)a1;
      v57 = *(_DWORD *)(a1 + 4);
      goto LABEL_74;
    case 0xEu:
      goto LABEL_55;
    case 0xFu:
      v37 = "eSAP_DFS_CAC_INTERRUPTED";
      goto LABEL_55;
    case 0x10u:
      v37 = "eSAP_DFS_CAC_END";
      goto LABEL_55;
    case 0x11u:
      v37 = "eSAP_DFS_RADAR_DETECT";
      goto LABEL_55;
    case 0x12u:
      v37 = "eSAP_DFS_NO_AVAILABLE_CHANNEL";
LABEL_55:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        v37,
        a3);
      *(_DWORD *)v36 = a3;
      *(_BYTE *)(v36 + 8) = (_BYTE)a4;
      sap_update_cac_history(a1, a3);
      goto LABEL_75;
    case 0x13u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_STOP_BSS_DUE_TO_NO_CHNL",
        19);
      *(_DWORD *)v36 = 19;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: stopping vdev %d, bssid %02x:%02x:%02x:**:**:%02x freq %d",
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        "sap_signal_hdd_event",
        *(unsigned __int8 *)(a1 + 12),
        *(unsigned __int8 *)(a1 + 24),
        *(unsigned __int8 *)(a1 + 25),
        *(unsigned __int8 *)(a1 + 26),
        *(unsigned __int8 *)(a1 + 29),
        *(_DWORD *)a1);
      goto LABEL_75;
    case 0x15u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_ACS_CHANNEL_SELECTED",
        21);
      *(_DWORD *)v36 = 21;
      if ( (_DWORD)a4 )
      {
        if ( (_DWORD)a4 == 1 )
          *(_DWORD *)(v36 + 8) = 0;
      }
      else
      {
        *(_DWORD *)(v36 + 8) = *(_DWORD *)(*(_QWORD *)(a1 + 1536) + 564LL);
        v57 = *(_DWORD *)(*(_QWORD *)(a1 + 1536) + 568LL);
LABEL_74:
        *(_DWORD *)(v36 + 12) = v57;
        *(_WORD *)(v36 + 20) = *(_WORD *)(*(_QWORD *)(a1 + 1536) + 42LL);
        *(_WORD *)(v36 + 16) = *(_DWORD *)(*(_QWORD *)(a1 + 1536) + 572LL);
        *(_WORD *)(v36 + 18) = *(_DWORD *)(*(_QWORD *)(a1 + 1536) + 576LL);
      }
      goto LABEL_75;
    case 0x16u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_ECSA_CHANGE_CHAN_IND",
        22);
      if ( !a2 )
        goto LABEL_52;
      *(_DWORD *)v36 = 22;
      *(_DWORD *)(v36 + 8) = *(_DWORD *)(a2 + 180);
      goto LABEL_75;
    case 0x17u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_DFS_NEXT_CHANNEL_REQ",
        23);
      *(_DWORD *)v36 = 23;
      goto LABEL_75;
    case 0x18u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_CHANNEL_CHANGE_RESP",
        24);
      *(_DWORD *)v36 = 24;
      *(_DWORD *)(v36 + 24) = (_DWORD)a4;
      *(_DWORD *)(v36 + 8) = *(_DWORD *)a1;
      *(_DWORD *)(v36 + 12) = *(_DWORD *)(a1 + 4);
      *(_WORD *)(v36 + 20) = *(_DWORD *)(a1 + 1500);
      *(_WORD *)(v36 + 16) = *(_DWORD *)(a1 + 1508);
      *(_WORD *)(v36 + 18) = *(_DWORD *)(a1 + 1512);
      sap_update_cac_history(a1, 24);
      goto LABEL_75;
    case 0x19u:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Vdev %d: %s(%d)",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sap_signal_hdd_event",
        v35,
        "eSAP_CHANNEL_SWITCH_STARTED_NOTIFY",
        25);
      if ( a2 )
      {
        *(_DWORD *)v36 = 25;
        *(_DWORD *)(v36 + 8) = *(_DWORD *)(*(_QWORD *)(a2 + 368) + 8LL);
        v94 = *(_QWORD *)(a2 + 368);
        v95 = *(_QWORD *)(v94 + 20);
        v96 = *(_QWORD *)(v94 + 12);
        *(_QWORD *)(v36 + 20) = v95;
        *(_QWORD *)(v36 + 12) = v96;
        goto LABEL_75;
      }
LABEL_52:
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Invalid CSR Roam Info",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "sap_signal_hdd_event");
      goto LABEL_82;
    default:
      qdf_trace_msg(0x39u, 8u, "%s: Vdev %d: %s(%d)", v27, v28, v29, v30, v31, v32, v33, v34, "sap_signal_hdd_event");
      if ( a3 != 20 )
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: SAP Unknown callback event = %d",
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          "sap_signal_hdd_event",
          a3);
      goto LABEL_75;
  }
}
