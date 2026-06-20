__int64 __fastcall pe_roam_synch_callback(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int16 a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v16; // w24
  __int64 session_by_vdev_id; // x0
  __int64 v19; // x20
  _BYTE *v20; // x26
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  __int64 result; // x0
  __int16 v31; // w9
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  unsigned __int8 *v41; // x23
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w19
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x21
  _BYTE *v62; // x28
  char v63; // w9
  unsigned int v64; // w27
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  size_t v81; // x2
  unsigned __int8 *v82; // x25
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  char v99; // w9
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x26
  double v110; // d0
  __int64 v111; // x27
  __int64 v112; // x3
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  unsigned int v120; // w0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 v129; // x4
  __int64 v130; // x5
  __int64 v131; // x6
  __int64 v132; // x7
  unsigned int ielen_from_bss_description; // w0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  char v142; // w8
  unsigned int v143; // w23
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  unsigned __int16 v160; // w23
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  void *v169; // x0
  size_t v170; // x2
  size_t v171; // x2
  __int64 v172; // x8
  __int64 v173; // x9
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  __int64 v182; // [xsp+18h] [xbp-28h]
  _BYTE v183[4]; // [xsp+24h] [xbp-1Ch] BYREF
  _WORD v184[2]; // [xsp+28h] [xbp-18h] BYREF
  _BYTE v185[4]; // [xsp+2Ch] [xbp-14h] BYREF
  int v186; // [xsp+30h] [xbp-10h] BYREF
  __int16 v187; // [xsp+34h] [xbp-Ch]
  __int64 v188; // [xsp+38h] [xbp-8h]

  v188 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v185[0] = 0;
  v184[0] = 0;
  v187 = 0;
  v186 = 0;
  v183[0] = 0;
  if ( !a3 )
  {
    v29 = "%s: LFR3:roam_sync_ind_ptr is NULL";
    goto LABEL_9;
  }
  v16 = a2;
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( !session_by_vdev_id )
  {
    v29 = "%s: LFR3:Unable to find session";
    goto LABEL_9;
  }
  v19 = session_by_vdev_id;
  if ( *(_DWORD *)(session_by_vdev_id + 88) != 2 )
  {
    v29 = "%s: LFR3:session is not in STA mode";
    goto LABEL_9;
  }
  v20 = (_BYTE *)(session_by_vdev_id + 7041);
  if ( (is_multi_link_roam(a3) & 1) != 0 )
  {
    mlo_get_sta_link_mac_addr(v16, a3, &v186);
  }
  else
  {
    v31 = *(_WORD *)(a3 + 18);
    v186 = *(_DWORD *)(a3 + 14);
    v187 = v31;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: LFR3: PE callback reason: %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "pe_roam_synch_callback",
    a5);
  if ( a5 == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: LFR3:Received ROAM SYNCH IND bssid %02x:%02x:%02x:**:**:%02x auth: %d vdevId: %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "pe_roam_synch_callback",
      *(unsigned __int8 *)(a3 + 14),
      *(unsigned __int8 *)(a3 + 15),
      *(unsigned __int8 *)(a3 + 16),
      *(unsigned __int8 *)(a3 + 19),
      *(_DWORD *)(a3 + 56),
      (unsigned __int8)v16);
    if ( *(_DWORD *)(v19 + 80) == 10 )
    {
      v40 = _qdf_mem_malloc(a4 + 108LL, "pe_roam_synch_callback", 3148);
      if ( !v40 )
      {
        result = 4294967294LL;
        goto LABEL_11;
      }
      v41 = (unsigned __int8 *)v40;
      v42 = lim_roam_fill_bss_descr(a1, a3, v40, v19);
      if ( v42 )
      {
        v51 = v42;
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: LFR3:Failed to fill Bss Descr",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "pe_roam_synch_callback");
        _qdf_mem_free((__int64)v41);
        result = v51;
        goto LABEL_11;
      }
      v52 = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, _BYTE *, _QWORD, _QWORD, _QWORD))pe_create_session)(
              a1,
              v41 + 2,
              v185,
              *(unsigned __int8 *)(a1 + 12272),
              *(unsigned int *)(v19 + 92),
              *(unsigned __int8 *)(v19 + 10));
      if ( !v52 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: LFR3:Cannot create PE Session bssid: %02x:%02x:%02x:**:**:%02x",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "pe_roam_synch_callback",
          v41[2],
          v41[3],
          v41[4],
          v41[7]);
        _qdf_mem_free((__int64)v41);
        goto LABEL_10;
      }
      v61 = v52;
      v62 = (_BYTE *)(v52 + 7276);
      lim_set_bcn_probe_filter(a1, v52, 0);
      *(_BYTE *)(v61 + 182) = v41[2];
      *(_BYTE *)(v61 + 183) = v41[3];
      *(_BYTE *)(v61 + 184) = v41[4];
      *(_BYTE *)(v61 + 185) = v41[5];
      *(_BYTE *)(v61 + 186) = v41[6];
      *(_BYTE *)(v61 + 187) = v41[7];
      *(_BYTE *)(v19 + 7425) = 1;
      v62[149] = 1;
      *(_DWORD *)(v61 + 88) = 2;
      v63 = *(_BYTE *)(v19 + 7276);
      *(_BYTE *)(v19 + 182) = v41[2];
      *(_BYTE *)(v19 + 183) = v41[3];
      *(_BYTE *)(v19 + 184) = v41[4];
      *(_BYTE *)(v19 + 185) = v41[5];
      *(_BYTE *)(v19 + 186) = v41[6];
      *(_BYTE *)(v19 + 187) = v41[7];
      *v62 = v63;
      v64 = lim_fill_ft_session(a1, v41, v61, v19, *(unsigned int *)(a3 + 2460));
      if ( v64 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to fill ft session for vdev id %d",
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          "pe_roam_synch_callback",
          *(unsigned __int8 *)(v61 + 10));
LABEL_29:
        _qdf_mem_free((__int64)v41);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Roam sync failure status %d session vdev %d",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "pe_roam_synch_callback",
          v64,
          *(unsigned __int8 *)(v19 + 10));
LABEL_30:
        pe_delete_session(a1);
        result = v64;
        goto LABEL_11;
      }
      if ( *(unsigned __int8 *)(v61 + 36) >= 0x20u )
        v81 = 32;
      else
        v81 = *(unsigned __int8 *)(v61 + 36);
      *(_BYTE *)(a3 + 20) = v81;
      qdf_mem_copy((void *)(a3 + 21), (const void *)(v61 + 37), v81);
      pe_update_crypto_params(a1, v61, a3);
      wlan_mlme_set_sae_single_pmk_bss_cap(*(_QWORD *)(a1 + 21624), v16, 0);
      lim_ft_prepare_add_bss_req(a1, v61, v41);
      lim_process_tpe_ie_from_beacon(a1, v61, v41, v183);
      if ( *v20 == 1 )
        lim_fill_fils_ft(v19, v61);
      v82 = *(unsigned __int8 **)(v61 + 7832);
      *(_QWORD *)(a3 + 272) = v82;
      lim_delete_tdls_peers(a1, v19, 1);
      wlan_tdls_notify_sta_disconnect(v16, 1, 0, *(_QWORD *)(v19 + 16));
      v182 = dph_lookup_hash_entry(
               v83,
               v84,
               v85,
               v86,
               v87,
               v88,
               v89,
               v90,
               a1,
               (unsigned __int8 *)(v19 + 24),
               v184,
               v19 + 360);
      if ( !v182 && (is_multi_link_roam(a3) & 1) == 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: LFR3:failed to lookup hash entry",
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          "pe_roam_synch_callback");
        v62[149] = 0;
        goto LABEL_29;
      }
      v99 = v62[1469];
      *(_DWORD *)(v61 + 10016) = *(_DWORD *)(v19 + 10016);
      v62[1469] = v99 & 0xC0 | *(_BYTE *)(v19 + 8745) & 0x3F;
      v100 = dph_add_hash_entry(v91, v92, v93, v94, v95, v96, v97, v98, a1, (unsigned __int8 *)&v186, 1u, v61 + 360);
      if ( !v100 )
      {
        if ( v82 == (unsigned __int8 *)-33LL )
        {
          v131 = 0;
          v129 = 0;
          v130 = 0;
          v132 = 0;
        }
        else
        {
          v129 = v82[33];
          v130 = v82[34];
          v131 = v82[35];
          v132 = v82[38];
        }
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: LFR3:failed to add hash entry for %02x:%02x:%02x:**:**:%02x",
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          "pe_roam_synch_callback",
          v129,
          v130,
          v131,
          v132);
        v62[149] = 0;
        goto LABEL_29;
      }
      v109 = v100;
      if ( *(_DWORD *)(a3 + 56) == 2 )
        *(_BYTE *)(v100 + 657) = 1;
      v110 = mlo_roam_copy_partner_info(v61 + 10696, a3, *(unsigned __int8 *)(a3 + 13), 0);
      v111 = *(unsigned __int16 *)(a3 + 4);
      mgmt_txrx_frame_hex_dump(
        a3 + v111,
        *(unsigned __int16 *)(a3 + 6),
        0,
        v112,
        v110,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119);
      if ( (wlan_vdev_mlme_get_is_mlo_link(*(_QWORD *)(a1 + 21624), v16) & 1) != 0 )
      {
        v120 = lim_gen_link_specific_assoc_rsp(a1, v61, a3 + v111, *(unsigned __int16 *)(a3 + 6));
        if ( *(_BYTE *)(v61 + 13282) )
          v64 = 16;
        else
          v64 = v120;
        if ( v64 )
        {
          _qdf_mem_free((__int64)v41);
LABEL_67:
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Roam sync failure status %d session vdev %d",
            v121,
            v122,
            v123,
            v124,
            v125,
            v126,
            v127,
            v128,
            "pe_roam_synch_callback",
            v64,
            *(unsigned __int8 *)(v19 + 10));
          lim_cleanup_rx_path(a1, v109, v61, 0);
          lim_delete_dph_hash_entry(a1, v109 + 350, *(unsigned __int16 *)(v109 + 348), v61);
          goto LABEL_30;
        }
      }
      else
      {
        lim_process_assoc_rsp_frame(a1, a3 + v111, *(unsigned __int16 *)(a3 + 6), 1, v61);
        if ( *(_BYTE *)(v61 + 13282) == 1 )
        {
          _qdf_mem_free((__int64)v41);
          v64 = 16;
          goto LABEL_67;
        }
      }
      ielen_from_bss_description = wlan_get_ielen_from_bss_description(v41);
      lim_enable_cts_to_self_for_exempted_iot_ap(a1, v61, v41 + 104, ielen_from_bss_description);
      _qdf_mem_free((__int64)v41);
      lim_check_ft_initial_im_association(a3, v61, v134, v135, v136, v137, v138, v139, v140, v141);
      lim_copy_and_free_hlp_data_from_session(v61, a3);
      *(_WORD *)(a3 + 304) = *(_WORD *)(v61 + 180);
      *(_DWORD *)(v109 + 8) = 14;
      v142 = v62[1359];
      *(_BYTE *)(v109 + 659) = v142;
      *(_BYTE *)(a3 + 392) = v142;
      *(_QWORD *)(v61 + 72) = 0xE0000000ELL;
      lim_init_tdls_data(a1, v61);
      v143 = *(_DWORD *)(v61 + 392);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: LFR3: Session RicLength: %d",
        v144,
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        "pe_roam_synch_callback",
        v143);
      lim_handle_sr_cap(*(_QWORD *)(v61 + 16), 0, v152, v153, v154, v155, v156, v157, v158, v159);
      v160 = *(_DWORD *)(v61 + 408) + v143;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: LFR3: tspecLen: %d",
        v161,
        v162,
        v163,
        v164,
        v165,
        v166,
        v167,
        v168,
        "pe_roam_synch_callback");
      if ( v160 )
      {
        v169 = (void *)_qdf_mem_malloc(v160, "pe_roam_synch_callback", 3309);
        *(_QWORD *)(a3 + 296) = v169;
        if ( !v169 )
        {
          v62[149] = 0;
          v64 = 2;
          goto LABEL_67;
        }
        if ( *(_QWORD *)(v61 + 400) )
        {
          v170 = *(unsigned int *)(v61 + 392);
          *(_DWORD *)(a3 + 288) = v170;
          qdf_mem_copy(v169, *(const void **)(v61 + 400), v170);
          _qdf_mem_free(*(_QWORD *)(v61 + 400));
          *(_QWORD *)(v61 + 400) = 0;
          *(_DWORD *)(v61 + 392) = 0;
        }
        if ( *(_QWORD *)(v61 + 416) )
        {
          v171 = *(unsigned int *)(v61 + 408);
          v172 = *(_QWORD *)(a3 + 296);
          v173 = *(unsigned int *)(a3 + 288);
          *(_DWORD *)(a3 + 292) = v171;
          qdf_mem_copy((void *)(v172 + v173), *(const void **)(v61 + 416), v171);
          _qdf_mem_free(*(_QWORD *)(v61 + 416));
          *(_QWORD *)(v61 + 416) = 0;
          *(_DWORD *)(v61 + 408) = 0;
        }
      }
      *(_DWORD *)(a3 + 280) = *(_DWORD *)(v61 + 7176);
      *(_DWORD *)(a3 + 284) = lim_get_max_rate_flags(a1, v109);
      v62[149] = 0;
      *(_QWORD *)(v61 + 80) = 0xA0000000ALL;
      *(_DWORD *)(v19 + 80) = 1;
      if ( v182 )
      {
        if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(v19 + 16), v174, v175, v176, v177, v178, v179, v180, v181) & 1) == 0 )
        {
          lim_mlo_notify_peer_disconn(v19, v182);
          lim_mlo_roam_delete_link_peer(v19, v182);
        }
        lim_cleanup_rx_path(a1, v182, v19, 0);
        lim_delete_dph_hash_entry(a1, v182 + 350, v184[0], v19);
      }
      pe_delete_session(a1);
      goto LABEL_19;
    }
    v29 = "%s: LFR3: Not in Link est state";
LABEL_9:
    qdf_trace_msg(0x35u, 2u, v29, a6, a7, a8, a9, a10, a11, a12, a13, "pe_roam_synch_callback");
    goto LABEL_10;
  }
  if ( a5 == 4 )
  {
    if ( *(_BYTE *)(v19 + 10009) == 1 )
      lim_perform_deauth(a1, v19, *(unsigned __int16 *)(v19 + 10012), v19 + 24, 0);
    if ( *(_BYTE *)(v19 + 10010) == 1 )
    {
      lim_disassoc_tdls_peers(a1, v19, v19 + 24);
      lim_perform_disassoc(a1, 0, *(unsigned __int16 *)(v19 + 10012), v19, v19 + 24);
    }
LABEL_19:
    result = 0;
    goto LABEL_11;
  }
LABEL_10:
  result = 16;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
