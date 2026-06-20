__int64 __fastcall lim_proc_assoc_req_frm_cmn(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int8 *a4,
        __int64 a5,
        unsigned __int16 a6)
{
  unsigned int *v10; // x8
  __int64 v11; // x28
  unsigned int v12; // w26
  unsigned int v14; // w20
  unsigned int v15; // w24
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  int v28; // w8
  int v29; // w20
  unsigned __int8 v30; // w24
  __int64 v31; // x9
  __int64 v32; // x28
  __int64 sta_ds; // x0
  __int64 v34; // x25
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x1
  unsigned __int8 *v38; // x3
  __int64 v39; // x4
  unsigned int v40; // w24
  __int64 v41; // x4
  __int64 v42; // x5
  __int64 v43; // x6
  __int64 v44; // x7
  __int64 v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  const char *v79; // x4
  int v80; // w9
  int v81; // w10
  int v82; // w11
  int v83; // w12
  int v84; // w8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  const char *v93; // x4
  __int64 v94; // x5
  __int64 v95; // x6
  __int64 v96; // x7
  int v97; // w8
  unsigned int v98; // w28
  size_t v99; // x20
  unsigned int v100; // w8
  __int64 v101; // x9
  char v102; // w11
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  char v111; // w28
  __int64 v112; // x0
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  const char *v121; // x4
  __int64 v122; // x5
  __int64 v123; // x6
  __int64 v124; // x7
  int v125; // w8
  __int64 v126; // x5
  __int64 v127; // x6
  __int64 v128; // x7
  int v129; // w8
  __int64 result; // x0
  char v131; // w24
  __int64 v132; // [xsp+0h] [xbp-80h]
  unsigned int v133; // [xsp+34h] [xbp-4Ch]
  __int64 v134; // [xsp+38h] [xbp-48h]
  __int64 v135; // [xsp+38h] [xbp-48h]
  _WORD v137[2]; // [xsp+50h] [xbp-30h] BYREF
  int v138; // [xsp+54h] [xbp-2Ch] BYREF
  _BYTE v139[4]; // [xsp+58h] [xbp-28h] BYREF
  char v140[12]; // [xsp+5Ch] [xbp-24h] BYREF
  _QWORD v141[3]; // [xsp+68h] [xbp-18h] BYREF

  v141[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (unsigned int *)(a3 + 7232);
  v11 = *(_QWORD *)(a5 + 3288);
  v12 = *(_DWORD *)(a5 + 3280);
  if ( !a3 )
    v10 = (unsigned int *)(a1 + 4840);
  v14 = *v10;
  v140[0] = 0;
  v139[0] = 0;
  v138 = 0;
  v137[0] = 0;
  if ( (_BYTE)a2 )
  {
    v15 = sir_convert_reassoc_req_frame2_struct();
    if ( v15 )
    {
LABEL_5:
      if ( a4 )
      {
        v24 = *a4;
        v25 = a4[1];
        v26 = a4[2];
        v27 = a4[5];
      }
      else
      {
        v26 = 0;
        v24 = 0;
        v25 = 0;
        v27 = 0;
      }
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Assoc Req rejected: frame parsing error. source addr:%02x:%02x:%02x:**:**:%02x",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "lim_chk_assoc_req_parse_error",
        v24,
        v25,
        v26,
        v27);
      v35 = a5 + 3608;
      v36 = a1;
      v37 = v15;
      v38 = a4;
      v39 = a2;
      goto LABEL_122;
    }
  }
  else
  {
    v15 = sir_convert_assoc_req_frame2_struct();
    if ( v15 )
      goto LABEL_5;
  }
  if ( !*(_BYTE *)(a5 + 3480) && *(_DWORD *)(a5 + 3608) | *(unsigned __int16 *)(a5 + 3612) )
  {
    if ( a4 )
    {
      v41 = *a4;
      v42 = a4[1];
      v43 = a4[2];
      v44 = a4[5];
    }
    else
    {
      v43 = 0;
      v41 = 0;
      v42 = 0;
      v44 = 0;
    }
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Assoc Req rejected: missing ETH IE %02x:%02x:%02x:**:**:%02x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_chk_assoc_req_parse_error",
      v41,
      v42,
      v43,
      v44);
    v36 = a1;
    v37 = 135;
    goto LABEL_120;
  }
  v133 = v14;
  v28 = *(unsigned __int16 *)(a1 + 3992);
  v29 = *(unsigned __int16 *)(a3 + 8);
  LOWORD(v141[0]) = 0;
  if ( v28 )
  {
    v30 = 0;
    v134 = v11;
    while ( 1 )
    {
      v31 = *(_QWORD *)(a1 + 12264);
      v32 = v31 + 10792LL * v30;
      if ( *(_BYTE *)(v32 + 70) )
      {
        if ( *(_DWORD *)(v32 + 7036) == 1 )
        {
          sta_ds = lim_get_sta_ds(a1, a4, a5 + 3608, v141, v31 + 10792LL * v30, v16, v17, v18, v19, v20, v21, v22, v23);
          if ( sta_ds )
          {
            v34 = sta_ds;
            if ( ((*(_WORD *)sta_ds & 0x400) == 0 || *(unsigned __int16 *)(v32 + 8) != v29) && LOWORD(v141[0]) != a6 )
              break;
          }
        }
      }
      if ( *(unsigned __int16 *)(a1 + 3992) <= (unsigned int)++v30 )
      {
        v40 = 0;
LABEL_22:
        v11 = v134;
        goto LABEL_27;
      }
    }
    v84 = *(_DWORD *)(sta_ds + 8);
    if ( v84 != 17 && v84 != 22 && (*(_BYTE *)(sta_ds + 645) & 1) == 0 )
    {
      *(_BYTE *)(sta_ds + 645) = 1;
      if ( a4 )
      {
        v126 = *a4;
        v127 = a4[1];
        v128 = a4[2];
        v129 = a4[5];
      }
      else
      {
        v128 = 0;
        v126 = 0;
        v127 = 0;
        v129 = 0;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Vdev %d Delete STA %02x:%02x:%02x:**:**:%02x",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "lim_check_sta_in_pe_entries",
        *(unsigned __int8 *)(v32 + 10),
        v126,
        v127,
        v128,
        v129);
      v40 = 1;
      lim_send_disassoc_mgmt_frame(a1, 1, a4, v32, 0);
      *(_WORD *)(v34 + 34) = 9;
      *(_DWORD *)(v34 + 24) = 4;
      lim_send_sme_disassoc_ind(a1, v34, v32);
      goto LABEL_22;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Deletion is in progress (%d) for peer:%02x:%02x:%02x:**:**:%02x in mlmState %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_check_sta_in_pe_entries",
      *(unsigned __int8 *)(sta_ds + 645),
      *(unsigned __int8 *)(sta_ds + 338),
      *(unsigned __int8 *)(sta_ds + 339),
      *(unsigned __int8 *)(sta_ds + 340),
      *(unsigned __int8 *)(sta_ds + 343),
      *(_DWORD *)(sta_ds + 8));
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Reject assoc as duplicate entry is present and is already being deleted, assoc will be accepted once deletion is completed",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "lim_proc_assoc_req_frm_cmn");
    v39 = a2;
    if ( a6 )
      goto LABEL_123;
    v36 = a1;
    v37 = 1;
    v38 = a4;
    goto LABEL_121;
  }
  v40 = 0;
LABEL_27:
  v45 = *(_QWORD *)(a3 + 8664);
  if ( v45 && *(_BYTE *)(a3 + 8672) == 1 )
  {
    if ( v12 <= 4 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Received action frame of invalid len %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "lim_proc_assoc_req_frm_cmn",
        v12);
      goto LABEL_123;
    }
    if ( !wlan_get_vendor_ie_ptr_from_oui(
            (const void *)(v45 + 2),
            3u,
            (unsigned __int8 *)(v11 + 4),
            (unsigned __int16)v12 - 4) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Vendor ie not present and access policy is %x, Rejected association",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "lim_proc_assoc_req_frm_cmn",
        *(unsigned __int8 *)(a3 + 8672));
      if ( a6 )
        goto LABEL_123;
LABEL_62:
      v36 = a1;
      v37 = 1;
LABEL_120:
      v38 = a4;
      v39 = a2;
LABEL_121:
      v35 = a5 + 3608;
LABEL_122:
      lim_send_assoc_rsp_mgmt_frame(v36, v37, 1, v38, v39, 0, a3, 0, v35);
      goto LABEL_123;
    }
  }
  LOWORD(v141[0]) = 0;
  if ( (unsigned int)lim_get_capability_info(a1, v141, a3) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not retrieve Capabilities",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "lim_chk_capab");
    goto LABEL_123;
  }
  v137[0] = v141[0];
  if ( !(unsigned __int8)lim_compare_capabilities(a1, (_WORD *)a5, v137, a3, v54, v55, v56, v57, v58, v59, v60, v61) )
  {
    if ( (_BYTE)a2 )
      v93 = "ReAssoc";
    else
      v93 = "Assoc";
    if ( a4 )
    {
      v94 = *a4;
      v95 = a4[1];
      v96 = a4[2];
      v97 = a4[5];
    }
    else
    {
      v96 = 0;
      v94 = 0;
      v95 = 0;
      v97 = 0;
    }
    LODWORD(v132) = v97;
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Rcvd %s Req with unsupported capab from%02x:%02x:%02x:**:**:%02x",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "lim_chk_capab",
      v93,
      v94,
      v95,
      v96,
      v132);
    v36 = a1;
    v37 = 10;
    goto LABEL_120;
  }
  v70 = lim_cmp_ssid((unsigned __int8 *)(a5 + 10), a3);
  if ( (_DWORD)v70 )
  {
    if ( (_BYTE)a2 )
      v79 = "ReAssoc";
    else
      v79 = "Assoc";
    if ( a4 )
    {
      v80 = *a4;
      v81 = a4[1];
      v82 = a4[2];
      v83 = a4[5];
    }
    else
    {
      v82 = 0;
      v80 = 0;
      v81 = 0;
      v83 = 0;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: %s Req with ssid wrong(Rcvd: %.*s self: %.*s) from %02x:%02x:%02x:**:**:%02x",
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      "lim_chk_ssid",
      v79,
      *(unsigned __int8 *)(a5 + 10),
      a5 + 11,
      *(unsigned __int8 *)(a3 + 36),
      a3 + 37,
      v80,
      v81,
      v82,
      v83);
    goto LABEL_62;
  }
  v135 = v11;
  v98 = *(unsigned __int8 *)(a5 + 44);
  memset(v141, 0, 13);
  if ( v98 )
  {
    if ( v98 >= 0xC )
      v99 = 12;
    else
      v99 = v98;
    v70 = (__int64)memcpy((char *)v141 + 1, (const void *)(a5 + 45), v99);
  }
  else
  {
    LODWORD(v99) = 0;
  }
  if ( (unsigned int)v99 > 0xB || (v100 = *(unsigned __int8 *)(a5 + 57), !*(_BYTE *)(a5 + 57)) )
  {
    v102 = v99;
    goto LABEL_98;
  }
  if ( v98 >= 0xC )
    v101 = 12;
  else
    v101 = v98;
  if ( v98 <= 0xB )
  {
    *((_BYTE *)v141 + v101 + 1) = *(_BYTE *)(a5 + 58);
    v102 = v99 + 1;
    if ( v98 == 11 )
      goto LABEL_98;
    if ( v100 < 2 )
      goto LABEL_98;
    *((_BYTE *)v141 + v101 + 2) = *(_BYTE *)(a5 + 59);
    v102 = v99 + 2;
    if ( v98 > 9 )
      goto LABEL_98;
    if ( v100 < 3 )
      goto LABEL_98;
    *((_BYTE *)v141 + v101 + 3) = *(_BYTE *)(a5 + 60);
    v102 = v99 + 3;
    if ( v98 > 8 )
      goto LABEL_98;
    if ( v100 < 4 )
      goto LABEL_98;
    *((_BYTE *)v141 + v101 + 4) = *(_BYTE *)(a5 + 61);
    v102 = v99 + 4;
    if ( v98 > 7 )
      goto LABEL_98;
    if ( v100 < 5 )
      goto LABEL_98;
    *((_BYTE *)v141 + v101 + 5) = *(_BYTE *)(a5 + 62);
    v102 = v99 + 5;
    if ( v98 > 6 )
      goto LABEL_98;
    if ( v100 < 6 )
      goto LABEL_98;
    *((_BYTE *)v141 + v101 + 6) = *(_BYTE *)(a5 + 63);
    v102 = v99 + 6;
    if ( v98 > 5 )
      goto LABEL_98;
    if ( v100 < 7 )
      goto LABEL_98;
    *((_BYTE *)v141 + v101 + 7) = *(_BYTE *)(a5 + 64);
    v102 = v99 + 7;
    if ( v98 > 4 || v100 < 8 )
      goto LABEL_98;
    if ( (v101 | 8uLL) <= 0xD )
    {
      *((_BYTE *)&v141[1] + v101) = *(_BYTE *)(a5 + 65);
      v102 = v99 + 8;
      if ( v98 > 3 )
        goto LABEL_98;
      if ( v100 < 9 )
        goto LABEL_98;
      *((_BYTE *)v141 + (v101 | 8) + 1) = *(_BYTE *)(a5 + 66);
      v102 = v99 + 9;
      if ( (v101 | 8uLL) > 0xA || v100 < 0xA )
        goto LABEL_98;
      if ( v98 <= 2 )
      {
        *((_BYTE *)&v141[1] + v101 + 2) = *(_BYTE *)(a5 + 67);
        v102 = v99 + 10;
        if ( v98 != 2 && v100 >= 0xB )
        {
          *((_BYTE *)&v141[1] + v101 + 3) = *(_BYTE *)(a5 + 68);
          v102 = v99 + 11;
          if ( !v98 && v100 >= 0xC )
          {
            v102 = v99 + 12;
            BYTE4(v141[1]) = *(_BYTE *)(a5 + 69);
          }
        }
LABEL_98:
        LOBYTE(v141[0]) = v102;
        if ( (unsigned __int8)((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int64, __int64))lim_check_rx_basic_rates)(
                                a1,
                                v141[0],
                                LODWORD(v141[1]) | ((unsigned __int64)BYTE4(v141[1]) << 32),
                                a3) != 1 )
        {
          if ( (_BYTE)a2 )
            v121 = "ReAssoc";
          else
            v121 = "Assoc";
          if ( a4 )
          {
            v122 = *a4;
            v123 = a4[1];
            v124 = a4[2];
            v125 = a4[5];
          }
          else
          {
            v124 = 0;
            v122 = 0;
            v123 = 0;
            v125 = 0;
          }
          LODWORD(v132) = v125;
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Assoc Req rejected: unsupported rates, source addr: %s%02x:%02x:%02x:**:**:%02x",
            v103,
            v104,
            v105,
            v106,
            v107,
            v108,
            v109,
            v110,
            "lim_chk_rates",
            v121,
            v122,
            v123,
            v124,
            v132);
          v36 = a1;
          v37 = 18;
          goto LABEL_120;
        }
        v111 = v40;
        if ( (lim_chk_11g_only(a1) & 1) == 0 )
          goto LABEL_123;
        if ( (lim_chk_11n_only(a1, a4, a3, a5, a2) & 1) == 0 )
          goto LABEL_123;
        if ( (lim_chk_11ac_only(a1, a4, a3, a5, a2) & 1) == 0 )
          goto LABEL_123;
        if ( (lim_chk_11ax_only(a1, a4, a3, a5, a2) & 1) == 0 )
          goto LABEL_123;
        if ( (lim_check_11ax_basic_mcs(a1, a4, a3, a5, a2) & 1) == 0 )
          goto LABEL_123;
        lim_process_for_spectrum_mgmt(a1, a4, a3, a5, a2, v137[0]);
        if ( (lim_chk_mcs(a1, a4, a3, a5, a2) & 1) == 0 )
          goto LABEL_123;
        if ( (lim_chk_is_11b_sta_supported(a1, a4, a3, a5, a2, v133) & 1) == 0 )
          goto LABEL_123;
        lim_print_ht_cap(a3, a5);
        if ( (lim_chk_n_process_wpa_rsn_ie(a1, a4, a3, a5, a2, v140, &v138) & 1) == 0 )
          goto LABEL_123;
        lim_update_ap_ext_cap(a3, a5);
        v112 = lim_search_pre_auth_list(a1, a4);
        if ( v112 && *(_DWORD *)(v112 + 16) == 3 && *(_DWORD *)(v112 + 20) == 29 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Received assoc request frame while SAE authentication is in progress; Defer association request handling"
            " till SAE auth status is received",
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            v119,
            v120,
            "lim_proc_assoc_req_frm_cmn");
          LOWORD(v132) = a6;
          lim_defer_sme_indication(a1, a3, a2, a4, a5, (unsigned __int8)v140[0], 0, v40, v132);
        }
        else
        {
          if ( *(_DWORD *)(a3 + 7036) == 3 )
          {
            v131 = wlan_p2p_check_oui_and_force_1x1((unsigned __int8 *)(v135 + 4), v12 - 4);
            if ( (*(_BYTE *)(a3 + 10080) & 1) != 0
              && (!*(_BYTE *)(a5 + 3268)
               || (unsigned int)wlan_p2p_extract_ap_assist_dfs_params(
                                  *(_QWORD *)(a3 + 16),
                                  a5 + 1006,
                                  *(_WORD *)(a5 + 1004),
                                  0,
                                  *(_DWORD *)(a3 + 284),
                                  0)) )
            {
              goto LABEL_123;
            }
          }
          else
          {
            v131 = 0;
          }
          if ( (lim_send_assoc_ind_to_sme(
                  a1,
                  a3,
                  a2,
                  a4,
                  (_WORD *)a5,
                  v138,
                  v140[0],
                  v139,
                  v113,
                  v114,
                  v115,
                  v116,
                  v117,
                  v118,
                  v119,
                  v120,
                  v111,
                  v131 & 1,
                  a6)
              & 1) == 0 )
          {
LABEL_123:
            result = 16;
LABEL_124:
            _ReadStatusReg(SP_EL0);
            return result;
          }
        }
        result = 0;
        goto LABEL_124;
      }
    }
  }
  __break(1u);
  return lim_chk_11g_only(v70);
}
