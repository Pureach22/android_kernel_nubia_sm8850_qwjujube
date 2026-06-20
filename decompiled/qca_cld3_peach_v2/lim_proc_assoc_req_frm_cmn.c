__int64 __fastcall lim_proc_assoc_req_frm_cmn(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int8 *a4,
        __int64 a5,
        unsigned __int16 a6)
{
  unsigned int *v11; // x8
  __int64 v12; // x27
  unsigned int v13; // w26
  unsigned int v14; // w25
  unsigned int v15; // w28
  unsigned int v16; // w24
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w8
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  __int64 v30; // x4
  __int64 v31; // x10
  __int64 v32; // x11
  __int64 v33; // x10
  __int64 v34; // x9
  __int64 v35; // x12
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  const char *v45; // x3
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x1
  unsigned __int8 *v49; // x3
  __int64 v50; // x4
  __int64 result; // x0
  int v52; // w8
  int v53; // w28
  unsigned __int8 v54; // w20
  __int64 v55; // x9
  __int64 v56; // x25
  __int64 sta_ds; // x0
  __int64 v58; // x24
  unsigned int v59; // w28
  __int64 v60; // x8
  __int64 v61; // x4
  __int64 v62; // x5
  __int64 v63; // x6
  __int64 v64; // x7
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
  __int64 v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  const char *v90; // x4
  int v91; // w9
  int v92; // w10
  int v93; // w11
  int v94; // w12
  int v95; // w8
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  const char *v104; // x4
  __int64 v105; // x5
  __int64 v106; // x6
  __int64 v107; // x7
  int v108; // w8
  unsigned int v109; // w24
  size_t v110; // x20
  unsigned int v111; // w8
  __int64 v112; // x9
  char v113; // w11
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  const char *v131; // x4
  __int64 v132; // x5
  __int64 v133; // x6
  __int64 v134; // x7
  int v135; // w8
  __int64 v136; // x5
  __int64 v137; // x6
  __int64 v138; // x7
  int v139; // w8
  char v140; // w24
  __int64 v141; // [xsp+0h] [xbp-B0h]
  unsigned int v142; // [xsp+2Ch] [xbp-84h]
  unsigned int v143; // [xsp+38h] [xbp-78h]
  unsigned __int16 v144; // [xsp+3Ch] [xbp-74h]
  _WORD v145[2]; // [xsp+48h] [xbp-68h] BYREF
  int v146; // [xsp+4Ch] [xbp-64h] BYREF
  _BYTE v147[4]; // [xsp+50h] [xbp-60h] BYREF
  char v148[12]; // [xsp+54h] [xbp-5Ch] BYREF
  __int128 v149; // [xsp+60h] [xbp-50h] BYREF
  __int64 v150; // [xsp+70h] [xbp-40h]
  __int64 v151; // [xsp+78h] [xbp-38h]
  __int64 v152; // [xsp+80h] [xbp-30h]
  __int64 v153; // [xsp+88h] [xbp-28h]
  __int64 v154; // [xsp+90h] [xbp-20h]
  int v155; // [xsp+98h] [xbp-18h]
  __int64 v156; // [xsp+A0h] [xbp-10h]

  v156 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = (unsigned int *)(a3 + 7232);
  v12 = *(_QWORD *)(a5 + 3288);
  v13 = *(_DWORD *)(a5 + 3280);
  if ( !a3 )
    v11 = (unsigned int *)(a1 + 4840);
  v14 = a2;
  v15 = *v11;
  v148[0] = 0;
  v147[0] = 0;
  v146 = 0;
  v145[0] = 0;
  if ( (_BYTE)a2 )
  {
    v16 = sir_convert_reassoc_req_frame2_struct();
    v25 = 10;
    if ( v16 )
    {
LABEL_5:
      if ( a4 )
      {
        v26 = *a4;
        v27 = a4[1];
        v28 = a4[2];
        v29 = a4[5];
      }
      else
      {
        v28 = 0;
        v26 = 0;
        v27 = 0;
        v29 = 0;
      }
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Assoc Req rejected: frame parsing error. source addr:%02x:%02x:%02x:**:**:%02x",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_chk_assoc_req_parse_error",
        v26,
        v27,
        v28,
        v29);
      v46 = a5 + 3756;
      v47 = a1;
      v48 = v16;
      v49 = a4;
      v50 = v14;
      goto LABEL_13;
    }
  }
  else
  {
    v16 = sir_convert_assoc_req_frame2_struct();
    v25 = 4;
    if ( v16 )
      goto LABEL_5;
  }
  v30 = *(unsigned int *)(a3 + 284);
  v31 = *(_QWORD *)(a5 + 3404);
  v32 = *(_QWORD *)(a5 + 3412);
  v154 = *(_QWORD *)(a5 + 3420);
  v152 = v31;
  v153 = v32;
  v155 = *(_DWORD *)(a5 + 3428);
  v33 = *(_QWORD *)(a5 + 3380);
  v35 = *(_QWORD *)(a5 + 3388);
  v34 = *(_QWORD *)(a5 + 3396);
  *(_QWORD *)&v149 = *(_QWORD *)(a5 + 3372);
  *((_QWORD *)&v149 + 1) = v33;
  v150 = v35;
  v151 = v34;
  if ( (unsigned int)lim_strip_and_decode_eht_cap(v12 + v25, v13 - v25, a5 + 3480, &v149, v30, 1) )
  {
    v44 = "%s: Failed to extract eht cap";
    v45 = "lim_chk_assoc_req_parse_error";
LABEL_10:
    qdf_trace_msg(0x35u, 2u, v44, v36, v37, v38, v39, v40, v41, v42, v43, v45);
    goto LABEL_14;
  }
  if ( !*(_BYTE *)(a5 + 3480) && *(_DWORD *)(a5 + 3756) | *(unsigned __int16 *)(a5 + 3760) )
  {
    if ( a4 )
    {
      v61 = *a4;
      v62 = a4[1];
      v63 = a4[2];
      v64 = a4[5];
    }
    else
    {
      v63 = 0;
      v61 = 0;
      v62 = 0;
      v64 = 0;
    }
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Assoc Req rejected: missing ETH IE %02x:%02x:%02x:**:**:%02x",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "lim_chk_assoc_req_parse_error",
      v61,
      v62,
      v63,
      v64);
    v47 = a1;
    v48 = 135;
    goto LABEL_125;
  }
  v142 = v15;
  v52 = *(unsigned __int16 *)(a1 + 3992);
  v53 = *(unsigned __int16 *)(a3 + 8);
  v144 = a6;
  LOWORD(v149) = 0;
  if ( v52 )
  {
    v54 = 0;
    v143 = v14;
    while ( 1 )
    {
      v55 = *(_QWORD *)(a1 + 12264);
      v56 = v55 + 14000LL * v54;
      if ( *(_BYTE *)(v56 + 70) )
      {
        if ( *(_DWORD *)(v56 + 7036) == 1 )
        {
          sta_ds = lim_get_sta_ds(
                     a1,
                     a4,
                     (unsigned __int8 *)(a5 + 3756),
                     &v149,
                     v55 + 14000LL * v54,
                     v36,
                     v37,
                     v38,
                     v39,
                     v40,
                     v41,
                     v42,
                     v43);
          if ( sta_ds )
          {
            v58 = sta_ds;
            if ( ((*(_WORD *)sta_ds & 0x400) == 0 || *(unsigned __int16 *)(v56 + 8) != v53)
              && (unsigned __int16)v149 != v144 )
            {
              break;
            }
          }
        }
      }
      if ( *(unsigned __int16 *)(a1 + 3992) <= (unsigned int)++v54 )
      {
        v14 = v143;
        goto LABEL_28;
      }
    }
    v95 = *(_DWORD *)(sta_ds + 8);
    if ( v95 == 17 || v95 == 22 || (*(_BYTE *)(sta_ds + 661) & 1) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Deletion is in progress (%d) for peer:%02x:%02x:%02x:**:**:%02x in mlmState %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "lim_check_sta_in_pe_entries",
        *(unsigned __int8 *)(sta_ds + 661),
        *(unsigned __int8 *)(sta_ds + 350),
        *(unsigned __int8 *)(sta_ds + 351),
        *(unsigned __int8 *)(sta_ds + 352),
        *(unsigned __int8 *)(sta_ds + 355),
        *(_DWORD *)(sta_ds + 8));
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Reject assoc as duplicate entry is present and is already being deleted, assoc will be accepted once deletion is completed",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        "lim_proc_assoc_req_frm_cmn");
      v50 = v143;
      if ( v144 )
        goto LABEL_14;
      v47 = a1;
      v48 = 1;
      v49 = a4;
      goto LABEL_126;
    }
    *(_BYTE *)(sta_ds + 661) = 1;
    if ( a4 )
    {
      v136 = *a4;
      v137 = a4[1];
      v138 = a4[2];
      v139 = a4[5];
    }
    else
    {
      v138 = 0;
      v136 = 0;
      v137 = 0;
      v139 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Vdev %d Delete STA %02x:%02x:%02x:**:**:%02x",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "lim_check_sta_in_pe_entries",
      *(unsigned __int8 *)(v56 + 10),
      v136,
      v137,
      v138,
      v139);
    v59 = 1;
    lim_send_disassoc_mgmt_frame(a1, 1, a4, v56, 0);
    *(_WORD *)(v58 + 34) = 9;
    *(_DWORD *)(v58 + 24) = 4;
    lim_send_sme_disassoc_ind(a1, v58, v56);
    v14 = v143;
    v60 = *(_QWORD *)(a3 + 8664);
    if ( !v60 )
      goto LABEL_36;
  }
  else
  {
LABEL_28:
    v59 = 0;
    v60 = *(_QWORD *)(a3 + 8664);
    if ( !v60 )
      goto LABEL_36;
  }
  if ( *(_BYTE *)(a3 + 8672) == 1 )
  {
    if ( v13 <= 4 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Received action frame of invalid len %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "lim_proc_assoc_req_frm_cmn",
        v13);
      goto LABEL_14;
    }
    if ( !wlan_get_vendor_ie_ptr_from_oui(
            (const void *)(v60 + 2),
            3u,
            (unsigned __int8 *)(v12 + 4),
            (unsigned __int16)v13 - 4) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Vendor ie not present and access policy is %x, Rejected association",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "lim_proc_assoc_req_frm_cmn",
        *(unsigned __int8 *)(a3 + 8672));
      if ( v144 )
        goto LABEL_14;
      goto LABEL_66;
    }
  }
LABEL_36:
  LOWORD(v149) = 0;
  if ( (unsigned int)lim_get_capability_info(a1, &v149, a3) )
  {
    v44 = "%s: could not retrieve Capabilities";
    v45 = "lim_chk_capab";
    goto LABEL_10;
  }
  v145[0] = v149;
  if ( !(unsigned __int8)lim_compare_capabilities(a1, (_WORD *)a5, v145, a3, v36, v37, v38, v39, v40, v41, v42, v43) )
  {
    if ( (_BYTE)v14 )
      v104 = "ReAssoc";
    else
      v104 = "Assoc";
    if ( a4 )
    {
      v105 = *a4;
      v106 = a4[1];
      v107 = a4[2];
      v108 = a4[5];
    }
    else
    {
      v107 = 0;
      v105 = 0;
      v106 = 0;
      v108 = 0;
    }
    LODWORD(v141) = v108;
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Rcvd %s Req with unsupported capab from%02x:%02x:%02x:**:**:%02x",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "lim_chk_capab",
      v104,
      v105,
      v106,
      v107,
      v141);
    v47 = a1;
    v48 = 10;
    goto LABEL_125;
  }
  v81 = lim_cmp_ssid((unsigned __int8 *)(a5 + 10), a3);
  if ( (_DWORD)v81 )
  {
    if ( (_BYTE)v14 )
      v90 = "ReAssoc";
    else
      v90 = "Assoc";
    if ( a4 )
    {
      v91 = *a4;
      v92 = a4[1];
      v93 = a4[2];
      v94 = a4[5];
    }
    else
    {
      v93 = 0;
      v91 = 0;
      v92 = 0;
      v94 = 0;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: %s Req with ssid wrong(Rcvd: %.*s self: %.*s) from %02x:%02x:%02x:**:**:%02x",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      "lim_chk_ssid",
      v90,
      *(unsigned __int8 *)(a5 + 10),
      a5 + 11,
      *(unsigned __int8 *)(a3 + 36),
      a3 + 37,
      v91,
      v92,
      v93,
      v94);
LABEL_66:
    v47 = a1;
    v48 = 1;
LABEL_125:
    v49 = a4;
    v50 = v14;
LABEL_126:
    v46 = a5 + 3756;
LABEL_13:
    lim_send_assoc_rsp_mgmt_frame(v47, v48, 1, v49, v50, 0, a3, 0, v46);
    goto LABEL_14;
  }
  v109 = *(unsigned __int8 *)(a5 + 44);
  *(_QWORD *)((char *)&v149 + 5) = 0;
  *(_QWORD *)&v149 = 0;
  if ( v109 )
  {
    if ( v109 >= 0xC )
      v110 = 12;
    else
      v110 = v109;
    v81 = (__int64)memcpy((char *)&v149 + 1, (const void *)(a5 + 45), v110);
  }
  else
  {
    LODWORD(v110) = 0;
  }
  if ( (unsigned int)v110 > 0xB || (v111 = *(unsigned __int8 *)(a5 + 57), !*(_BYTE *)(a5 + 57)) )
  {
    v113 = v110;
    goto LABEL_102;
  }
  if ( v109 >= 0xC )
    v112 = 12;
  else
    v112 = v109;
  if ( v109 > 0xB )
    goto LABEL_139;
  *((_BYTE *)&v149 + v112 + 1) = *(_BYTE *)(a5 + 58);
  v113 = v110 + 1;
  if ( v109 == 11 )
    goto LABEL_102;
  if ( v111 < 2 )
    goto LABEL_102;
  *((_BYTE *)&v149 + v112 + 2) = *(_BYTE *)(a5 + 59);
  v113 = v110 + 2;
  if ( v109 > 9 )
    goto LABEL_102;
  if ( v111 < 3 )
    goto LABEL_102;
  *((_BYTE *)&v149 + v112 + 3) = *(_BYTE *)(a5 + 60);
  v113 = v110 + 3;
  if ( v109 > 8 )
    goto LABEL_102;
  if ( v111 < 4 )
    goto LABEL_102;
  *((_BYTE *)&v149 + v112 + 4) = *(_BYTE *)(a5 + 61);
  v113 = v110 + 4;
  if ( v109 > 7 )
    goto LABEL_102;
  if ( v111 < 5 )
    goto LABEL_102;
  *((_BYTE *)&v149 + v112 + 5) = *(_BYTE *)(a5 + 62);
  v113 = v110 + 5;
  if ( v109 > 6 )
    goto LABEL_102;
  if ( v111 < 6 )
    goto LABEL_102;
  *((_BYTE *)&v149 + v112 + 6) = *(_BYTE *)(a5 + 63);
  v113 = v110 + 6;
  if ( v109 > 5 )
    goto LABEL_102;
  if ( v111 < 7 )
    goto LABEL_102;
  *((_BYTE *)&v149 + v112 + 7) = *(_BYTE *)(a5 + 64);
  v113 = v110 + 7;
  if ( v109 > 4 || v111 < 8 )
    goto LABEL_102;
  if ( (v112 | 8uLL) > 0xD )
    goto LABEL_139;
  *((_BYTE *)&v149 + v112 + 8) = *(_BYTE *)(a5 + 65);
  v113 = v110 + 8;
  if ( v109 > 3
    || v111 < 9
    || (*((_BYTE *)&v149 + (v112 | 8) + 1) = *(_BYTE *)(a5 + 66), v113 = v110 + 9, (v112 | 8uLL) > 0xA)
    || v111 < 0xA )
  {
LABEL_102:
    LOBYTE(v149) = v113;
    if ( (unsigned __int8)((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int64, __int64))lim_check_rx_basic_rates)(
                            a1,
                            v149,
                            DWORD2(v149) | ((unsigned __int64)BYTE12(v149) << 32),
                            a3) == 1 )
    {
      if ( (lim_chk_11g_only(a1) & 1) == 0 )
        goto LABEL_14;
      if ( (lim_chk_11n_only(a1, a4, a3, a5, v14) & 1) == 0 )
        goto LABEL_14;
      if ( (lim_chk_11ac_only(a1, a4, a3, a5, v14) & 1) == 0 )
        goto LABEL_14;
      if ( (lim_chk_11ax_only(a1, a4, a3, a5, v14) & 1) == 0 )
        goto LABEL_14;
      if ( (lim_chk_11be_only(a1, a4, a3, a5, v14) & 1) == 0 )
        goto LABEL_14;
      if ( (lim_check_11ax_basic_mcs(a1, a4, a3, a5, v14) & 1) == 0 )
        goto LABEL_14;
      lim_process_for_spectrum_mgmt(a1, a4, a3, a5, v14, v145[0]);
      if ( (lim_chk_mcs(a1, a4, a3, a5, v14) & 1) == 0 )
        goto LABEL_14;
      if ( (lim_chk_is_11b_sta_supported(a1, a4, a3, a5, v14, v142) & 1) == 0 )
        goto LABEL_14;
      lim_print_ht_cap(a3, a5);
      if ( (lim_chk_n_process_wpa_rsn_ie(a1, a4, a3, a5, v14, v148, &v146) & 1) == 0 )
        goto LABEL_14;
      lim_update_ap_ext_cap(a3, a5);
      v122 = lim_search_pre_auth_list(a1, a4);
      if ( v122 && *(_DWORD *)(v122 + 16) == 3 && *(_DWORD *)(v122 + 20) == 29 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Received assoc request frame while SAE authentication is in progress; Defer association request handling t"
          "ill SAE auth status is received",
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          "lim_proc_assoc_req_frm_cmn");
        LOWORD(v141) = v144;
        lim_defer_sme_indication(a1, a3, v14, a4, a5, (unsigned __int8)v148[0], 0, v59, v141);
      }
      else
      {
        if ( *(_DWORD *)(a3 + 7036) == 3 )
        {
          v140 = wlan_p2p_check_oui_and_force_1x1((unsigned __int8 *)(v12 + 4), v13 - 4);
          if ( (*(_BYTE *)(a3 + 13288) & 1) != 0
            && (!*(_BYTE *)(a5 + 3268)
             || (unsigned int)wlan_p2p_extract_ap_assist_dfs_params(
                                *(_QWORD *)(a3 + 16),
                                a5 + 1006,
                                *(_WORD *)(a5 + 1004),
                                0,
                                *(_DWORD *)(a3 + 284),
                                0)) )
          {
            goto LABEL_14;
          }
        }
        else
        {
          v140 = 0;
        }
        if ( (lim_send_assoc_ind_to_sme(
                a1,
                a3,
                v14,
                a4,
                (_WORD *)a5,
                v146,
                v148[0],
                v147,
                v123,
                v124,
                v125,
                v126,
                v127,
                v128,
                v129,
                v130,
                v59,
                v140 & 1,
                v144)
            & 1) == 0 )
        {
LABEL_14:
          result = 16;
LABEL_15:
          _ReadStatusReg(SP_EL0);
          return result;
        }
      }
      result = 0;
      goto LABEL_15;
    }
    if ( (_BYTE)v14 )
      v131 = "ReAssoc";
    else
      v131 = "Assoc";
    if ( a4 )
    {
      v132 = *a4;
      v133 = a4[1];
      v134 = a4[2];
      v135 = a4[5];
    }
    else
    {
      v134 = 0;
      v132 = 0;
      v133 = 0;
      v135 = 0;
    }
    LODWORD(v141) = v135;
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Assoc Req rejected: unsupported rates, source addr: %s%02x:%02x:%02x:**:**:%02x",
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      "lim_chk_rates",
      v131,
      v132,
      v133,
      v134,
      v141);
    v47 = a1;
    v48 = 18;
    goto LABEL_125;
  }
  if ( v109 <= 2 )
  {
    *((_BYTE *)&v149 + v112 + 10) = *(_BYTE *)(a5 + 67);
    v113 = v110 + 10;
    if ( v109 != 2 && v111 >= 0xB )
    {
      *((_BYTE *)&v149 + v112 + 11) = *(_BYTE *)(a5 + 68);
      v113 = v110 + 11;
      if ( !v109 && v111 >= 0xC )
      {
        v113 = v110 + 12;
        BYTE12(v149) = *(_BYTE *)(a5 + 69);
      }
    }
    goto LABEL_102;
  }
LABEL_139:
  __break(1u);
  return lim_chk_11g_only(v81);
}
