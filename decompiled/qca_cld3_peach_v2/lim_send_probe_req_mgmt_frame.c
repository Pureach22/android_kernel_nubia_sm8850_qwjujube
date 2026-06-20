__int64 __fastcall lim_send_probe_req_mgmt_frame(
        __int64 a1,
        __int64 a2,
        _WORD *a3,
        unsigned __int8 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v15; // w22
  __int16 v16; // w8
  int v17; // w9
  __int64 v18; // x0
  int v19; // w28
  unsigned int v20; // w25
  unsigned int v21; // w21
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x19
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  unsigned int v33; // w20
  unsigned int mgmt_tx_power; // w0
  __int16 v35; // w10
  __int16 v36; // w11
  __int16 v37; // w10
  __int16 v38; // w8
  __int64 v39; // x1
  unsigned int v40; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int16 v50; // w3
  _BOOL4 v51; // w25
  char v52; // w0
  unsigned __int8 *v53; // x0
  __int64 v54; // x2
  _BYTE *v55; // x26
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  bool is_24ghz_ch_freq; // w0
  __int64 v65; // x9
  __int64 v66; // x10
  __int64 v67; // x9
  __int64 v68; // x9
  __int64 v69; // x9
  __int64 v70; // x8
  __int64 v71; // x11
  __int64 v72; // x8
  __int64 v73; // x11
  __int64 v74; // x8
  __int64 v75; // x8
  char v76; // w8
  unsigned __int8 v77; // w28
  unsigned int packed_probe_request_size; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w25
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  char *v96; // x25
  void *v97; // x0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int v106; // w8
  __int16 v107; // w8
  __int64 v108; // x5
  unsigned int v109; // w0
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  unsigned int v118; // w8
  unsigned int v119; // w0
  unsigned __int16 v120; // w9
  __int64 v121; // x3
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  char v138; // w20
  _QWORD *context; // x0
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  int v149; // [xsp+8h] [xbp-138h]
  unsigned int v151; // [xsp+50h] [xbp-F0h]
  int n[3]; // [xsp+54h] [xbp-ECh] BYREF
  int v153[2]; // [xsp+60h] [xbp-E0h] BYREF
  unsigned int v154; // [xsp+6Ch] [xbp-D4h] BYREF
  _DWORD v155[2]; // [xsp+70h] [xbp-D0h] BYREF
  _QWORD v156[7]; // [xsp+78h] [xbp-C8h] BYREF
  int v157; // [xsp+B0h] [xbp-90h]
  _QWORD v158[11]; // [xsp+B8h] [xbp-88h] BYREF
  int v159; // [xsp+110h] [xbp-30h]
  __int128 v160; // [xsp+118h] [xbp-28h] BYREF
  char v161; // [xsp+128h] [xbp-18h]
  __int64 v162; // [xsp+130h] [xbp-10h]

  v162 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOWORD(n[0]) = 0;
  if ( a2 )
  {
    if ( a3 )
      LOWORD(n[0]) = *a3;
    v16 = *(_WORD *)(a2 + 24);
    v17 = *(_DWORD *)(a2 + 26);
    v18 = *(_QWORD *)(a1 + 21632);
    v19 = *(unsigned __int8 *)(a2 + 154);
    v15 = *(_DWORD *)(a2 + 284);
    v154 = 0;
    *(_QWORD *)&n[1] = 0;
    *(_QWORD *)v153 = 0;
    v160 = 0u;
    v161 = 0;
    LOWORD(v155[0]) = v16;
    *(_DWORD *)((char *)v155 + 2) = v17;
    v20 = wlan_reg_freq_to_chan(v18, v15, a5, a6, a7, a8, a9, a10, a11, a12);
    if ( wlan_reg_is_24ghz_ch_freq(v15) && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2875LL) & 1) == 0 && (v19 & 0xFE) == 8 )
      v19 = 5;
    v21 = *(unsigned __int8 *)(a2 + 10);
    v22 = _qdf_mem_malloc(0x488u, "lim_send_probe_req_mgmt_frame", 222);
    if ( v22 )
    {
      v31 = v22;
      if ( !wlan_reg_is_6ghz_chan_freq(v15) && *(unsigned __int8 *)(a2 + 13283) >= 3u )
        memset(v155, 255, 6);
      populate_dot11f_ssid(a1, a2 + 36, v31);
      if ( a4
        && LOWORD(n[0])
        && (vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_969516, 4u, a4, n[0]), v19 != 3)
        && vendor_ie_ptr_from_oui
        && *(_DWORD *)(a2 + 7036) == 2 )
      {
        populate_dot11f_supp_rates(a1, 15, v31 + 34, a2);
      }
      else
      {
        populate_dot11f_supp_rates(a1, v20, v31 + 34, a2);
        if ( v19 != 3 )
          populate_dot11f_ext_supp_rates1(a1, v20, v31 + 305);
      }
      populate_dot11f_ds_params(a1, v31 + 319, v15);
      mgmt_tx_power = rrm_get_mgmt_tx_power(a1, a2);
      populate_dot11f_wfatpc(a1, v31 + 1082, mgmt_tx_power, 0);
      if ( *(_BYTE *)(a2 + 155) && !wlan_reg_is_6ghz_chan_freq(v15) )
        populate_dot11f_ht_caps(a1, a2, v31 + 324);
      if ( wlan_reg_is_24ghz_ch_freq(v15) )
      {
        v35 = *(_WORD *)(v31 + 325);
        v36 = v35 & 0xFFBD;
        v37 = v35 | 2;
        if ( *(_DWORD *)(a1 + 17192) )
          v38 = v37;
        else
          v38 = v36;
        *(_WORD *)(v31 + 325) = v38;
      }
      if ( *(_BYTE *)(a2 + 7170) && !wlan_reg_is_6ghz_chan_freq(v15) )
      {
        populate_dot11f_vht_caps(a1, a2, v31 + 404);
        v39 = 1;
      }
      else
      {
        v39 = 0;
      }
      populate_dot11f_ext_cap(a1, v39, v31 + 384, a2);
      if ( (unsigned int)(v19 - 10) < 4 || !v19 )
      {
        lim_update_session_he_capable(a1, a2);
        populate_dot11f_he_caps(a1, a2, *(_DWORD *)(a2 + 7036), v15, *(_DWORD *)(a2 + 7176), v31 + 420);
        populate_dot11f_he_6ghz_cap(a1, a2, v31 + 480);
        v40 = 0;
        if ( ((1 << v19) & 0x3001) == 0 )
        {
LABEL_45:
          v151 = v40;
          if ( (unsigned int)(v19 - 10) < 4 || !v19 )
            populate_dot11f_reg_connectivity(a1, v31 + 833);
          if ( !a4 || !LOWORD(n[0]) )
          {
            populate_dot11f_qcn_ie(a1, a2, v31 + 1116, 255);
            goto LABEL_60;
          }
          qdf_mem_set(&v160, 0x11u, 0);
          if ( (unsigned int)lim_strip_extcap_update_struct(a1, a4, n, &v160) )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Unable to Stripoff ExtCap IE from Probe Req",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              "lim_send_probe_req_mgmt_frame");
            v50 = n[0];
            v51 = 0;
          }
          else
          {
            if ( (*(_DWORD *)((_BYTE *)&v160 + 2) & 0x80000000) != 0 )
              *(_QWORD *)((char *)&v160 + 2) |= 0x100000000uLL;
            v52 = lim_compute_ext_cap_ie_length(&v160);
            v50 = n[0];
            v51 = v52 != 0;
            BYTE1(v160) = v52;
            if ( a3 )
              *a3 = n[0];
          }
          v53 = wlan_get_vendor_ie_ptr_from_oui(&unk_977A7E, 4u, a4, v50);
          v54 = v31 + 1116;
          if ( v53 )
          {
            populate_dot11f_qcn_ie(a1, a2, v54, 2);
            if ( !v51 )
              goto LABEL_60;
          }
          else
          {
            populate_dot11f_qcn_ie(a1, a2, v54, 255);
            if ( !v51 )
            {
LABEL_60:
              populate_dot11f_btm_extended_caps(a1, a2, v31 + 384);
              if ( *(_BYTE *)(a2 + 10071) == 1 )
              {
                v55 = (_BYTE *)_qdf_mem_malloc(0x101u, "lim_send_probe_req_mgmt_frame", 380);
                if ( !v55 )
                {
                  v33 = 2;
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: malloc failed for eht_cap_ie",
                    v56,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    "lim_send_probe_req_mgmt_frame");
                  goto LABEL_98;
                }
                is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v15);
                v65 = *(_QWORD *)(v31 + 548);
                v66 = *(_QWORD *)(v31 + 556);
                v158[10] = *(_QWORD *)(v31 + 564);
                v158[8] = v65;
                v158[9] = v66;
                v159 = *(_DWORD *)(v31 + 572);
                v67 = *(_QWORD *)(v31 + 524);
                v158[4] = *(_QWORD *)(v31 + 516);
                v158[5] = v67;
                v68 = *(_QWORD *)(v31 + 540);
                v158[6] = *(_QWORD *)(v31 + 532);
                v158[7] = v68;
                v69 = *(_QWORD *)(v31 + 492);
                v71 = *(_QWORD *)(v31 + 500);
                v70 = *(_QWORD *)(v31 + 508);
                v158[0] = *(_QWORD *)(v31 + 484);
                v158[1] = v69;
                v158[2] = v71;
                v158[3] = v70;
                v72 = *(_QWORD *)(v31 + 460);
                v73 = *(_QWORD *)(v31 + 468);
                v156[4] = *(_QWORD *)(v31 + 452);
                v156[5] = v72;
                LODWORD(v72) = *(_DWORD *)(v31 + 476);
                v156[6] = v73;
                v157 = v72;
                v74 = *(_QWORD *)(v31 + 428);
                v156[0] = *(_QWORD *)(v31 + 420);
                v156[1] = v74;
                v75 = *(_QWORD *)(v31 + 444);
                v156[2] = *(_QWORD *)(v31 + 436);
                v156[3] = v75;
                lim_ieee80211_pack_ehtcap(v55, v158, v156, is_24ghz_ch_freq, 1);
                v76 = v55[1];
                *(_BYTE *)(v31 + 484) = 0;
                v77 = v76 + 2;
              }
              else
              {
                v55 = nullptr;
                v77 = 0;
              }
              packed_probe_request_size = dot11f_get_packed_probe_request_size(a1, v31, &v154);
              if ( (packed_probe_request_size & 0x10000000) != 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Failed to calculate the packed size for a Probe Request (0x%08x)",
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  "lim_send_probe_req_mgmt_frame",
                  packed_probe_request_size);
                v154 = 1160;
              }
              else if ( packed_probe_request_size )
              {
                qdf_trace_msg(
                  0x35u,
                  3u,
                  "%s: There were warnings while calculating the packed size for a Probe Request (0x%08x)",
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  "lim_send_probe_req_mgmt_frame");
              }
              v87 = v77 + (unsigned __int16)v151 + v154 + LOWORD(n[0]);
              if ( (unsigned int)cds_packet_alloc(
                                   v77 + (unsigned __int16)v151 + (unsigned __int16)v154 + LOWORD(n[0]) + 24,
                                   v153,
                                   &n[1]) )
              {
                v33 = 2;
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Failed to allocate %d bytes for a Probe Request",
                  v88,
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  "lim_send_probe_req_mgmt_frame",
                  (unsigned int)(v87 + 24));
LABEL_98:
                _qdf_mem_free((__int64)v55);
                _qdf_mem_free(v31);
                goto LABEL_99;
              }
              qdf_mem_set(*(void **)v153, (unsigned int)(v87 + 24), 0);
              v96 = *(char **)v153;
              v97 = (void *)(*(_QWORD *)v153 + 4LL);
              **(_BYTE **)v153 = 64;
              qdf_mem_copy(v97, v155, 6u);
              v96[10] = *(_BYTE *)(a2 + 30);
              v96[11] = *(_BYTE *)(a2 + 31);
              v96[12] = *(_BYTE *)(a2 + 32);
              v96[13] = *(_BYTE *)(a2 + 33);
              v96[14] = *(_BYTE *)(a2 + 34);
              v96[15] = *(_BYTE *)(a2 + 35);
              qdf_mem_copy(v96 + 16, v155, 6u);
              v106 = *(unsigned __int16 *)(a1 + 21604);
              if ( v106 <= 0xFFE )
                v107 = v106 + 1;
              else
                v107 = 2048;
              *(_WORD *)(a1 + 21604) = v107;
              *((_WORD *)v96 + 11) = (16 * (v107 & 0xF)) | *((_WORD *)v96 + 11) & 0xFF0F;
              v108 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
              *((_WORD *)v96 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v107 & 0xF));
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
                v98,
                v99,
                v100,
                v101,
                v102,
                v103,
                v104,
                v105,
                "lim_populate_mac_header",
                v107 & 0xF,
                v108,
                *(unsigned __int16 *)(a1 + 21604),
                0);
              v109 = dot11f_pack_probe_request(a1, v31, *(_QWORD *)v153 + 24LL, v154, &v154);
              if ( (v109 & 0x10000000) != 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Failed to pack a Probe Request (0x%08x)",
                  v110,
                  v111,
                  v112,
                  v113,
                  v114,
                  v115,
                  v116,
                  v117,
                  "lim_send_probe_req_mgmt_frame",
                  v109);
                cds_packet_free(*(__int64 *)&n[1]);
LABEL_97:
                v33 = 16;
                goto LABEL_98;
              }
              if ( v109 )
                qdf_trace_msg(
                  0x35u,
                  3u,
                  "%s: There were warnings while packing a Probe Request (0x%08x)",
                  v110,
                  v111,
                  v112,
                  v113,
                  v114,
                  v115,
                  v116,
                  v117,
                  "lim_send_probe_req_mgmt_frame");
              v118 = v154;
              if ( v77 )
              {
                qdf_mem_copy((void *)(*(_QWORD *)v153 + v154 + 24LL), v55, v77);
                v118 = v154 + v77;
                v154 = v118;
              }
              if ( LOWORD(n[0]) )
              {
                qdf_mem_copy((void *)(*(_QWORD *)v153 + v118 + 24LL), a4, LOWORD(n[0]));
                v118 = v154 + LOWORD(n[0]);
                v154 = v118;
              }
              if ( (_WORD)v151 )
              {
                v119 = lim_fill_complete_mlo_ie(a2, v151, *(_QWORD *)v153 + v118 + 24LL);
                v120 = v151;
                if ( v119 )
                {
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: assemble ml ie error, status %d",
                    v110,
                    v111,
                    v112,
                    v113,
                    v114,
                    v115,
                    v116,
                    v117,
                    "lim_send_probe_req_mgmt_frame",
                    v119);
                  v120 = 0;
                }
                v118 = v154 + v120;
                v154 = v118;
              }
              qdf_trace_msg(
                0x35u,
                8u,
                "Probe req TX: vdev %d seq num %d to %02x:%02x:%02x:**:**:%02x len %d",
                v110,
                v111,
                v112,
                v113,
                v114,
                v115,
                v116,
                v117,
                v21,
                *(unsigned __int16 *)(a1 + 21604),
                LOBYTE(v155[0]),
                BYTE1(v155[0]),
                BYTE2(v155[0]),
                BYTE1(v155[1]),
                v118 + 24);
              mgmt_txrx_frame_hex_dump(
                *(__int64 *)v153,
                v154 + 24,
                1,
                v121,
                v122,
                v123,
                v124,
                v125,
                v126,
                v127,
                v128,
                v129);
              if ( !wlan_reg_is_6ghz_chan_freq(v15) )
              {
                if ( wlan_reg_is_5ghz_ch_freq(v15) )
                  goto LABEL_88;
                wlan_reg_is_24ghz_ch_freq(v15);
              }
              if ( *(_DWORD *)(a2 + 7036) != 2 )
              {
                v138 = 0;
                goto LABEL_95;
              }
LABEL_88:
              v138 = 64;
LABEL_95:
              context = _cds_get_context(
                          54,
                          (__int64)"lim_send_probe_req_mgmt_frame",
                          v130,
                          v131,
                          v132,
                          v133,
                          v134,
                          v135,
                          v136,
                          v137);
              LOBYTE(v149) = v138;
              if ( !(unsigned int)wma_tx_packet(
                                    context,
                                    *(_QWORD *)&n[1],
                                    (unsigned int)(unsigned __int16)v154 + 24,
                                    3,
                                    1,
                                    7,
                                    lim_tx_complete,
                                    *(_QWORD *)v153,
                                    0,
                                    v149,
                                    (_BYTE)v21,
                                    0,
                                    0,
                                    12,
                                    0,
                                    0) )
              {
                v33 = 0;
                goto LABEL_98;
              }
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: could not send Probe Request frame!",
                v140,
                v141,
                v142,
                v143,
                v144,
                v145,
                v146,
                v147,
                "lim_send_probe_req_mgmt_frame");
              goto LABEL_97;
            }
          }
          lim_merge_extcap_struct(v31 + 384, &v160, 1);
          goto LABEL_60;
        }
        if ( *(_QWORD *)(a2 + 112) )
        {
          if ( v155[0] != -1 || SLOWORD(v155[1]) != -1 )
          {
            lim_update_session_eht_capable(a2, 1);
            populate_dot11f_eht_caps(a1, a2, v31 + 484);
            if ( *(_DWORD *)(*(_QWORD *)(a2 + 112) + 4648LL) )
            {
              if ( *(_BYTE *)(a2 + 13285) != 2 )
              {
                v40 = lim_send_probe_req_frame_mlo(a1, a2);
                goto LABEL_45;
              }
            }
          }
        }
      }
      v40 = 0;
      goto LABEL_45;
    }
    v33 = 2;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: memory alloc failed for probe request",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_send_probe_req_mgmt_frame");
  }
  else
  {
    v33 = 29;
  }
LABEL_99:
  _ReadStatusReg(SP_EL0);
  return v33;
}
