__int64 __fastcall lim_handle80211_frames(__int64 a1, unsigned __int16 *a2, _BYTE *a3)
{
  unsigned __int16 *v3; // x25
  __int64 v5; // x1
  unsigned __int8 *v6; // x21
  unsigned int v7; // w22
  unsigned int v8; // w26
  char is_hw_sbs_capable; // w23
  __int64 v10; // x3
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 session_by_bssid; // x0
  unsigned int v20; // w8
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w20
  unsigned int *v31; // x26
  __int64 v32; // x23
  unsigned int v33; // w27
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD *v42; // x8
  int v43; // w20
  int v44; // w9
  int v45; // w25
  bool v46; // w21
  size_t v47; // x2
  bool v48; // w28
  unsigned __int8 *v49; // x20
  __int64 v50; // x24
  unsigned __int8 v51; // w9
  unsigned int v52; // w8
  unsigned int v53; // w23
  unsigned int v54; // w23
  __int64 v55; // x25
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  const char *v64; // x2
  unsigned __int8 v65; // w8
  int v66; // w8
  int v67; // w9
  int v68; // w10
  int v69; // w11
  bool is_mbo_ap_without_pmf; // w0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 session_by_peer_sta; // x0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x22
  __int64 v105; // x4
  __int64 v106; // x5
  __int64 v107; // x6
  __int64 v108; // x7
  unsigned int *v109; // x1
  __int64 v110; // x0
  unsigned __int8 v111; // w3
  bool v112; // w22
  unsigned int *v113; // x1
  __int64 v114; // x0
  unsigned int v115; // w2
  double preauth_vdev_session; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  char v124; // w21
  bool v125; // zf
  __int64 result; // x0
  const char *v128; // x2
  char v129; // w22
  unsigned __int16 *v130; // [xsp+28h] [xbp-78h]
  unsigned int v131; // [xsp+34h] [xbp-6Ch]
  unsigned int v132; // [xsp+38h] [xbp-68h]
  unsigned __int8 v133; // [xsp+3Ch] [xbp-64h]
  unsigned __int8 *v134; // [xsp+40h] [xbp-60h]
  unsigned __int16 *v135; // [xsp+48h] [xbp-58h]
  unsigned __int8 *v136; // [xsp+50h] [xbp-50h]
  _BYTE v137[4]; // [xsp+5Ch] [xbp-44h] BYREF
  unsigned int *v138; // [xsp+60h] [xbp-40h] BYREF
  _QWORD *v139; // [xsp+68h] [xbp-38h] BYREF
  _QWORD *v140; // [xsp+70h] [xbp-30h] BYREF
  __int64 v141; // [xsp+78h] [xbp-28h] BYREF
  __int64 v142; // [xsp+80h] [xbp-20h]
  __int64 v143; // [xsp+88h] [xbp-18h]
  __int64 v144; // [xsp+90h] [xbp-10h]
  __int64 v145; // [xsp+98h] [xbp-8h]

  v3 = a2;
  v145 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a3 = 0;
  v5 = *((_QWORD *)a2 + 1);
  v138 = nullptr;
  v137[0] = 0;
  lim_get_b_dfrom_rx_packet(a1, v5, &v138);
  v6 = *(unsigned __int8 **)((char *)&off_10 + (_QWORD)v138);
  v7 = *v138;
  v8 = *(unsigned __int16 *)v6;
  is_hw_sbs_capable = policy_mgr_is_hw_sbs_capable(*(_QWORD *)(a1 + 21552));
  if ( wlan_reg_is_5ghz_ch_freq(v7)
    && ((is_hw_sbs_capable & 1) == 0
     || (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21560), v7, v11, v12, v13, v14, v15, v16, v17, v18) & 1) != 0) )
  {
    if ( *(_BYTE *)(a1 + 14809) )
    {
      session_by_bssid = pe_find_session_by_bssid(a1, v6 + 16, v137);
      if ( session_by_bssid )
      {
        if ( *(_DWORD *)(session_by_bssid + 7036) == 1 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: CAC timer running - drop the frame",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "lim_handle80211_frames");
          goto LABEL_112;
        }
      }
    }
  }
  v131 = (v8 >> 2) & 3;
  if ( !v131 && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 1060LL) & 1) != 0 )
  {
    v20 = (unsigned __int8)v8 >> 4;
    if ( v20 > 0xD || ((1 << v20) & 0x2130) == 0 )
      mgmt_txrx_frame_hex_dump(
        (__int64)v6,
        *(_DWORD *)((char *)&qword_20 + (_QWORD)v138),
        0,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18);
  }
  v21 = pe_find_session_by_bssid(a1, v6 + 16, v137);
  if ( !v21 )
  {
    v30 = (unsigned __int8)v8 >> 4;
    if ( v30 <= 0xD )
    {
      if ( ((1 << v30) & 0x2130) != 0 )
      {
        v21 = 0;
        if ( v30 != 13 )
          goto LABEL_17;
        goto LABEL_16;
      }
      if ( v30 == 11 )
      {
        if ( v6 == (unsigned __int8 *)-16LL )
        {
          v68 = 0;
          v66 = 0;
          v67 = 0;
          v69 = 0;
        }
        else
        {
          v66 = v6[16];
          v67 = v6[17];
          v68 = v6[18];
          v69 = v6[21];
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: ProtVersion %d, Type %d, Subtype %d rateIndex=%d bssid=%02x:%02x:%02x:**:**:%02x",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "lim_handle80211_frames",
          v8 & 3,
          v131,
          11,
          0,
          v66,
          v67,
          v68,
          v69);
        if ( !(unsigned int)lim_process_auth_frame_no_session(a1, v138, v87, v88, v89, v90, v91, v92, v93, v94) )
          goto LABEL_112;
      }
    }
    session_by_peer_sta = pe_find_session_by_peer_sta(a1, v6 + 10, v137);
    if ( !session_by_peer_sta )
    {
      if ( v6 == (unsigned __int8 *)-10LL )
      {
        v107 = 0;
        v105 = 0;
        v106 = 0;
        v108 = 0;
      }
      else
      {
        v105 = v6[10];
        v106 = v6[11];
        v107 = v6[12];
        v108 = v6[15];
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: session does not exist for bssId: %02x:%02x:%02x:**:**:%02x",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        "lim_handle80211_frames",
        v105,
        v106,
        v107,
        v108);
      goto LABEL_112;
    }
    v104 = session_by_peer_sta;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: SessionId:%d exists for given Bssid",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "lim_handle80211_frames",
      *(unsigned __int16 *)(session_by_peer_sta + 8));
    v21 = v104;
    if ( v30 == 13 )
LABEL_16:
      v21 = pe_find_session_by_bssid(a1, v6 + 4, v137);
  }
LABEL_17:
  v133 = v8;
  v31 = v138;
  v139 = nullptr;
  v140 = nullptr;
  v32 = v21;
  v33 = *(unsigned __int16 *)((char *)&qword_28 + (_QWORD)v138);
  v134 = v6;
  v135 = v3;
  v130 = *(unsigned __int16 **)((char *)&off_10 + (_QWORD)v138);
  v136 = *(unsigned __int8 **)((char *)&off_10 + (_QWORD)v138 + 8);
  v132 = *v130;
  qdf_mutex_acquire(a1 + 12280);
  qdf_list_peek_front((_QWORD *)(a1 + 12344), &v140);
  qdf_mutex_release(a1 + 12280);
  v42 = v140;
  if ( !v140 )
  {
LABEL_28:
    v49 = v134;
    v3 = v135;
    v50 = v32;
    v51 = v133;
    goto LABEL_29;
  }
  v43 = (v132 >> 2) & 3;
  while ( 1 )
  {
    v44 = *((unsigned __int16 *)v42 + 8);
    v45 = (unsigned __int8)v44 >> 4;
    v46 = (v44 & 0xC) == 0;
    if ( (v44 & 0xC) == 0 && !v43 && v45 == 15 )
      break;
    if ( v44 == (v132 & 0xF0 | (4 * ((v132 >> 2) & 3))) )
    {
      v47 = *((unsigned __int16 *)v42 + 9);
      if ( !*((_WORD *)v42 + 9) || v33 >= (unsigned int)v47 && !(unsigned int)qdf_mem_cmp((char *)v42 + 22, v136, v47) )
      {
        v48 = v45 != 15;
        goto LABEL_39;
      }
    }
    qdf_mutex_acquire(a1 + 12280);
    qdf_list_peek_next((_QWORD *)(a1 + 12344), v140, &v139);
    qdf_mutex_release(a1 + 12280);
    v42 = v139;
    v139 = nullptr;
    v140 = v42;
    if ( !v42 )
      goto LABEL_28;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: rcvd frm match for SIR_MAC_MGMT_RESERVED15",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "lim_check_mgmt_registered_frames");
  v48 = 0;
  v46 = 1;
LABEL_39:
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: rcvd frame match with registered frame params",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "lim_check_mgmt_registered_frames");
  v50 = v32;
  if ( v32 )
  {
    if ( *(_DWORD *)(v32 + 88) == 2 )
    {
      v54 = *(unsigned __int8 *)(v32 + 10);
      v55 = *(_QWORD *)(a1 + 21552);
      v143 = 0;
      v144 = 0;
      v141 = 0;
      v142 = 0;
      wlan_cm_roam_cfg_get_value(v55, v54, 0x1Fu, &v141);
      if ( (unsigned __int8)v142 == 1 )
      {
        v64 = "%s: Drop BTM frame. vdev:%d BTM roam disabled by user";
LABEL_58:
        qdf_trace_msg(0x35u, 8u, v64, v56, v57, v58, v59, v60, v61, v62, v63, "lim_is_ignore_btm_frame", v54);
        v3 = v135;
        goto LABEL_112;
      }
      if ( (wlan_cm_get_assoc_btm_cap(v55, v54) & 1) == 0 )
      {
        v64 = "%s: Drop BTM frame. vdev:%d BTM not supported by AP";
        goto LABEL_58;
      }
      if ( (cfg_p2p_is_roam_config_disabled(v55) & 1) != 0 )
      {
        if ( (unsigned int)policy_mgr_mode_specific_connection_count(v55, 2, nullptr) )
        {
          is_mbo_ap_without_pmf = wlan_cm_is_mbo_ap_without_pmf(v55, v54);
          goto LABEL_94;
        }
        v112 = (unsigned int)policy_mgr_mode_specific_connection_count(v55, 3, nullptr) != 0;
      }
      else
      {
        v112 = 0;
      }
      is_mbo_ap_without_pmf = wlan_cm_is_mbo_ap_without_pmf(v55, v54);
      if ( v112 || is_mbo_ap_without_pmf )
      {
LABEL_94:
        if ( v136 && v33 >= 2 && (v132 & 0xFC) == 0xD0 && *v136 == 10 && (unsigned int)v136[1] - 6 <= 2 )
        {
          if ( v33 < 3 )
            v124 = 0;
          else
            v124 = v136[2];
          v3 = v135;
          if ( is_mbo_ap_without_pmf )
            v128 = "%s: Drop the BTM frame as it's received from MBO AP without PMF, vdev %d";
          else
            v128 = "%s: Drop the BTM frame as p2p session is active, vdev %d";
          if ( is_mbo_ap_without_pmf )
            v129 = 1;
          else
            v129 = 2;
          qdf_trace_msg(0x35u, 8u, v128, v71, v72, v73, v74, v75, v76, v77, v78, "lim_is_ignore_btm_frame", v54);
          wlan_cm_roam_btm_block_event(v54, v124, v129);
          goto LABEL_112;
        }
      }
    }
    v65 = *(_BYTE *)(v50 + 10);
    goto LABEL_102;
  }
  v65 = *((_BYTE *)v140 + 20);
LABEL_102:
  lim_send_sme_mgmt_frame_ind(
    a1,
    *(unsigned __int8 *)v130 >> 4,
    v130,
    (unsigned int)(*(_DWORD *)((char *)&qword_28 + (_QWORD)v31) + 24),
    v65,
    *v31,
    *(unsigned int *)((char *)&qword_8 + (_QWORD)v31),
    0);
  v3 = v135;
  if ( !v46 )
    goto LABEL_112;
  v125 = v43 == 0;
  v49 = v134;
  v51 = v133;
  if ( !v125 || v48 )
    goto LABEL_112;
LABEL_29:
  if ( (v51 & 3) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Unexpected frame with protVersion %d received",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "lim_handle80211_frames",
      v51 & 3);
    lim_pkt_free(a1, 3, v138, *((_QWORD *)v3 + 1));
    goto LABEL_112;
  }
  if ( v131 )
    goto LABEL_112;
  v52 = v51 >> 4;
  v53 = v51;
  if ( v52 > 4 )
  {
    if ( (unsigned __int8)(v51 >> 4) > 0xAu )
    {
      switch ( v52 )
      {
        case 0xBu:
          preauth_vdev_session = lim_get_preauth_vdev_session(a1, *(_QWORD *)(v50 + 16), v49);
          lim_process_auth_frame(a1, (__int64)v138, v50, preauth_vdev_session, v117, v118, v119, v120, v121, v122, v123);
          break;
        case 0xCu:
          lim_process_deauth_frame(a1, (__int64)v138, v50, v34, v35, v36, v37, v38, v39, v40, v41);
          break;
        case 0xDu:
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: RX MGMT - Type %hu, SubType %hu, seq num[%d]",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "lim_handle80211_frames",
            0,
            13,
            *((unsigned __int16 *)v49 + 11) >> 4);
          if ( v50 )
          {
            if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 1060LL) & 8) != 0 )
              v79 = ((double (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(
                      53,
                      8,
                      v49,
                      (unsigned int)(*(_DWORD *)((char *)&qword_28 + (_QWORD)v138) + 24));
            lim_process_action_frame(a1, (__int64)v138, v50, v79, v80, v81, v82, v83, v84, v85, v86);
          }
          else
          {
            lim_process_action_frame_no_session(a1, v138, v79, v80, v81, v82, v83, v84, v85, v86);
          }
          break;
      }
    }
    else
    {
      switch ( v52 )
      {
        case 5u:
          if ( v50 )
            lim_process_probe_rsp_frame(a1, v138, v50);
          break;
        case 8u:
          _lim_handle_beacon(a1, v3, v50);
          break;
        case 0xAu:
          lim_process_disassoc_frame(a1, (__int64)v138, v50, v34, v35, v36, v37, v38, v39, v40, v41);
          break;
      }
    }
    goto LABEL_109;
  }
  if ( (unsigned __int8)(v51 >> 4) > 1u )
  {
    if ( v52 != 2 )
    {
      if ( v52 != 3 )
      {
        if ( v52 == 4 )
          lim_process_probe_req_frame_multiple_bss(a1, v138, v50);
        goto LABEL_109;
      }
      v109 = v138;
      v110 = a1;
      v111 = 1;
      goto LABEL_81;
    }
    if ( *(_DWORD *)(v50 + 88) == 1 )
    {
      v113 = v138;
      v114 = a1;
      v115 = 1;
      goto LABEL_86;
    }
    goto LABEL_87;
  }
  if ( !(v51 >> 4) )
  {
    if ( *(_DWORD *)(v50 + 88) == 1 )
    {
      v113 = v138;
      v114 = a1;
      v115 = 0;
LABEL_86:
      lim_process_assoc_req_frame(v114, (__int64)v113, v115, v50, v34, v35, v36, v37, v38, v39, v40, v41);
      goto LABEL_109;
    }
LABEL_87:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: unexpected message received %X",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "lim_handle80211_frames",
      *v3);
    lim_print_msg_name(a1, 2, *v3);
    goto LABEL_109;
  }
  v109 = v138;
  v110 = a1;
  v111 = 0;
LABEL_81:
  lim_process_assoc_rsp_frame(
    v110,
    (__int64)v109,
    *(_DWORD *)((char *)&qword_28 + (_QWORD)v109),
    v111,
    v50,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41);
LABEL_109:
  if ( v53 >> 4 > 8 || ((1 << (v53 >> 4)) & 0x130) == 0 )
    lim_diag_mgmt_rx_event_report(a1, v49, v50, 0, 0);
LABEL_112:
  result = lim_pkt_free(a1, 3, v138, *((_QWORD *)v3 + 1));
  _ReadStatusReg(SP_EL0);
  return result;
}
