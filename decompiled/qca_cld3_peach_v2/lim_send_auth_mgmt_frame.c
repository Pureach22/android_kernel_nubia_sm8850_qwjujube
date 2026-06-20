__int64 __fastcall lim_send_auth_mgmt_frame(
        __int64 a1,
        unsigned __int16 *a2,
        const void *a3,
        unsigned __int8 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v13; // w24
  unsigned int v19; // w20
  int v20; // w21
  const void *v21; // x28
  unsigned int v22; // w27
  const char *v23; // x2
  unsigned int v24; // w8
  int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w8
  _QWORD *v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  size_t v44; // x0
  size_t v45; // x24
  __int64 result; // x0
  __int64 v47; // x8
  unsigned int v48; // w21
  unsigned int v49; // w20
  unsigned __int16 *v50; // x24
  char *v51; // x26
  char *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w8
  __int16 v62; // w8
  __int64 v63; // x5
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned __int16 *v72; // x25
  _WORD *v73; // x21
  _WORD *v74; // x23
  unsigned int v75; // w26
  int v76; // w8
  int v77; // w9
  int v78; // w10
  int v79; // w11
  __int64 v80; // x26
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x8
  char v90; // w21
  int v91; // w0
  char v92; // w23
  int v93; // w22
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x8
  __int16 v103; // w25
  _QWORD *context; // x0
  unsigned int v105; // w21
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  int v114; // w8
  __int64 v115; // x8
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  int v124; // w8
  __int64 v125; // x8
  int v126; // [xsp+8h] [xbp-78h]
  int v127; // [xsp+10h] [xbp-70h]
  int v128; // [xsp+18h] [xbp-68h]
  unsigned int v129; // [xsp+48h] [xbp-38h]
  int v130; // [xsp+4Ch] [xbp-34h]
  unsigned int v131; // [xsp+50h] [xbp-30h]
  __int64 v132; // [xsp+50h] [xbp-30h]
  size_t v133; // [xsp+58h] [xbp-28h]
  __int64 v134; // [xsp+60h] [xbp-20h] BYREF
  unsigned int v135; // [xsp+6Ch] [xbp-14h] BYREF
  void *v136[2]; // [xsp+70h] [xbp-10h] BYREF

  v136[1] = *(void **)(_ReadStatusReg(SP_EL0) + 1808);
  v136[0] = nullptr;
  v135 = 0;
  v134 = 0;
  if ( !a5 )
  {
    v23 = "%s: Error: psession Entry is NULL";
LABEL_38:
    result = qdf_trace_msg(0x35u, 2u, v23, a6, a7, a8, a9, a10, a11, a12, a13, "lim_send_auth_mgmt_frame");
    goto LABEL_39;
  }
  v13 = *(unsigned __int8 *)(a5 + 10);
  if ( !a4 )
  {
    v24 = a2[1];
    if ( v24 > 2 )
    {
      if ( v24 == 3 || v24 == 4 )
      {
LABEL_15:
        v19 = 0;
        v20 = 0;
        v25 = 30;
        goto LABEL_16;
      }
    }
    else
    {
      if ( v24 == 1 )
      {
        v135 = 30;
        result = lim_create_fils_auth_data(a1, a2, a5, &v135, 0);
        if ( (_DWORD)result )
          goto LABEL_39;
        if ( *a2 == 2 )
        {
          v47 = *(_QWORD *)(a5 + 7432);
          if ( v47 && *(_WORD *)(v47 + 36) )
          {
            v48 = *(unsigned __int16 *)(v47 + 36);
            v135 += v48;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Auth frame, FTIES length added=%d",
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              a13,
              "lim_send_auth_mgmt_frame");
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Auth frame, Does not contain FTIES!",
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              a13,
              "lim_send_auth_mgmt_frame");
            v48 = 0;
            v135 += 5;
          }
        }
        else
        {
          v48 = 0;
        }
        v125 = *(_QWORD *)(a5 + 112);
        if ( !v125 )
        {
          v22 = 6;
          v19 = v48;
          v20 = 0;
          goto LABEL_18;
        }
        v19 = v48;
        if ( *(_BYTE *)(a5 + 7041) != 1 || *a2 != 4 || !*(_BYTE *)(v125 + 4592) )
        {
LABEL_98:
          v20 = 0;
          goto LABEL_17;
        }
        v20 = 0;
        v25 = v135 + 5;
LABEL_16:
        v135 = v25;
LABEL_17:
        v22 = 6;
LABEL_18:
        if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a5 + 16), a6, a7, a8, a9, a10, a11, a12, a13) & 1) != 0 )
        {
          qdf_mem_set((void *)(a5 + 10874), 0x92Cu, 0);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Auth TX sys role: %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "lim_calculate_auth_mlo_ie_len",
            *(unsigned int *)(a5 + 88));
          v34 = *(_DWORD *)(a5 + 88);
          if ( v34 == 2 )
            goto LABEL_23;
          if ( v34 == 1 )
          {
            v35 = lim_search_pre_auth_list(a1, a3);
            if ( v35 )
            {
              if ( *((_BYTE *)v35 + 600) == 1 )
              {
LABEL_23:
                populate_dot11f_auth_mlo_ie(a1, a5, a5 + 10874);
                v44 = (unsigned __int16)((__int64 (__fastcall *)(__int64))lim_caculate_mlo_ie_length)(a5 + 10874);
                if ( (_DWORD)v44 )
                {
                  v131 = v13;
                  v45 = v44;
                  v21 = (const void *)_qdf_mem_malloc(v44, "lim_send_auth_mgmt_frame", 4465);
                  if ( v21 )
                  {
                    if ( (unsigned int)lim_fill_complete_mlo_ie(a5, (unsigned int)v45, v21) )
                    {
                      _qdf_mem_free((__int64)v21);
                      v45 = 0;
                    }
                    v133 = v45;
                    v135 += v45;
                  }
                  else
                  {
                    v133 = v45;
                  }
                  v13 = v131;
                  goto LABEL_36;
                }
              }
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: no pre-auth ctx with peer addr",
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                "lim_calculate_auth_mlo_ie_len");
            }
          }
        }
        v21 = nullptr;
        v133 = 0;
        goto LABEL_36;
      }
      if ( v24 == 2 )
      {
        if ( *a2 && !a2[2] )
        {
          if ( *a2 != 4 )
          {
            v19 = 0;
            v20 = 1;
            v22 = 136;
            v135 = 160;
            goto LABEL_18;
          }
          v135 = 30;
          if ( (unsigned int)lim_create_fils_auth_data(a1, a2, a5, &v135, a3) )
          {
            v23 = "%s: Failed to create FILS Data";
            goto LABEL_38;
          }
          v19 = 0;
          goto LABEL_98;
        }
        goto LABEL_15;
      }
    }
    v23 = "%s: Invalid auth transaction seq num";
    goto LABEL_38;
  }
  v19 = 0;
  v20 = 0;
  v21 = nullptr;
  v133 = 0;
  v22 = a4 + 16;
  v135 = a4 + 40;
LABEL_36:
  if ( (unsigned int)cds_packet_alloc(v135, v136, &v134) )
  {
    v23 = "%s: call to bufAlloc failed for AUTH frame";
    goto LABEL_38;
  }
  v129 = v19;
  v130 = v20;
  v49 = v13;
  v132 = a1;
  v50 = (unsigned __int16 *)(a1 + 21604);
  qdf_mem_set(v136[0], v135, 0);
  v51 = (char *)v136[0];
  v52 = (char *)v136[0] + 4;
  *(_BYTE *)v136[0] = -80;
  qdf_mem_copy(v52, a3, 6u);
  v51[10] = *(_BYTE *)(a5 + 30);
  v51[11] = *(_BYTE *)(a5 + 31);
  v51[12] = *(_BYTE *)(a5 + 32);
  v51[13] = *(_BYTE *)(a5 + 33);
  v51[14] = *(_BYTE *)(a5 + 34);
  v51[15] = *(_BYTE *)(a5 + 35);
  qdf_mem_copy(v51 + 16, a3, 6u);
  v61 = *v50;
  if ( v61 <= 0xFFE )
    v62 = v61 + 1;
  else
    v62 = 2048;
  *v50 = v62;
  *((_WORD *)v51 + 11) = (16 * (v62 & 0xF)) | *((_WORD *)v51 + 11) & 0xFF0F;
  v63 = (unsigned __int8)(*v50 >> 4);
  *((_WORD *)v51 + 11) = (16 * *v50) & 0xFF00 | (16 * (v62 & 0xF));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    "lim_populate_mac_header",
    v62 & 0xF,
    v63,
    *v50,
    0);
  v72 = (unsigned __int16 *)v136[0];
  *(_WORD *)v136[0] = *(_WORD *)v136[0] & 0xBFFF | ((a4 != 0) << 14);
  if ( *(_DWORD *)(a5 + 88) == 1 )
    qdf_mem_copy(v72 + 8, (const void *)(a5 + 24), 6u);
  v73 = v136[0];
  if ( a4 )
  {
    v74 = (char *)v136[0] + 24;
    qdf_mem_copy((char *)v136[0] + 24, a2, v22);
    v75 = v49;
  }
  else
  {
    v75 = v49;
    *((_WORD *)v136[0] + 12) = *a2;
    v73[13] = a2[1];
    v73[14] = a2[2];
    if ( v130 )
    {
      *((_BYTE *)v73 + 30) = *((_BYTE *)a2 + 6);
      *((_BYTE *)v73 + 31) = *((_BYTE *)a2 + 7);
      if ( v22 - 6 > 0xFE )
      {
        qdf_mem_copy(v73 + 16, a2 + 4, 0x80u);
        v74 = v73 + 80;
      }
      else
      {
        v80 = v22 - 8;
        qdf_mem_copy(v73 + 16, a2 + 4, (unsigned int)v80);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Incomplete challenge info: length: %d, expected: %d",
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          "lim_send_auth_mgmt_frame",
          (unsigned int)v80,
          255);
        v74 = (_WORD *)((char *)v73 + v80 + 32);
        v75 = v49;
      }
    }
    else
    {
      v74 = v73 + 15;
    }
    v114 = *a2;
    if ( v114 == 4 )
    {
      v124 = a2[1];
      if ( v124 == 2 )
      {
        if ( !a2[2] )
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: FILS: appending fils Auth data for Frame 2",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            "lim_send_auth_mgmt_frame");
      }
      else if ( v124 == 1 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FILS: appending fils Auth data",
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          "lim_send_auth_mgmt_frame");
        lim_add_fils_data_to_auth_frame(a5, (int)v74);
      }
    }
    else if ( v114 == 2 && a2[1] == 1 )
    {
      v115 = *(_QWORD *)(a5 + 7432);
      if ( v115 )
      {
        if ( v129 )
        {
          qdf_mem_copy(v74, (const void *)(v115 + 38), v129);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Auth1 Frame FTIE is: ",
            v116,
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            "lim_send_auth_mgmt_frame");
          ((void (__fastcall *)(__int64, __int64, _WORD *, _QWORD))qdf_trace_hex_dump)(53, 8, v74, v129);
        }
        else if ( *(_QWORD *)(v115 + 424) )
        {
          *v74++ = 822;
          qdf_mem_copy(v74, (const void *)(*(_QWORD *)(*(_QWORD *)(a5 + 7432) + 424LL) + 45LL), 3u);
        }
      }
    }
  }
  if ( v21 && (_DWORD)v133 )
  {
    qdf_mem_copy(v74, v21, v133);
    _qdf_mem_free((__int64)v21);
  }
  if ( v72 == (unsigned __int16 *)-4LL )
  {
    v78 = 0;
    v76 = 0;
    v77 = 0;
    v79 = 0;
  }
  else
  {
    v76 = *((unsigned __int8 *)v72 + 4);
    v77 = *((unsigned __int8 *)v72 + 5);
    v78 = *((unsigned __int8 *)v72 + 6);
    v79 = *((unsigned __int8 *)v72 + 9);
  }
  qdf_trace_msg(
    0x35u,
    4u,
    "Auth TX: vdev %d seq %d seq num %d status %d WEP %d to %02x:%02x:%02x:**:**:%02x",
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v75,
    a2[1],
    *v50,
    a2[2],
    (*v72 >> 14) & 1,
    v76,
    v77,
    v78,
    v79);
  v89 = *(_QWORD *)(a5 + 7432);
  if ( (!v89 || wlan_reg_is_24ghz_ch_freq(*(unsigned __int16 *)(v89 + 10)))
    && wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a5 + 284))
    && (*(_DWORD *)(a5 + 7036) & 0xFFFFFFFE) != 2 )
  {
    v90 = 0;
  }
  else
  {
    v90 = 64;
  }
  if ( (*(_DWORD *)(a5 + 7036) | 2) == 2 )
    v90 |= 0x80u;
  qdf_trace(53, 2u, *(_WORD *)(a5 + 8), (unsigned __int8)*v72 >> 4);
  if ( (*((_DWORD *)v50 + 14) & 0xFFFFFFFE) != 2 )
    *((_DWORD *)v50 + 14) = 0;
  v91 = ((__int64 (__fastcall *)(__int64, _QWORD))lim_get_min_session_txrate)(a5, 0);
  v92 = *(_BYTE *)(v132 + 12208);
  v93 = v91;
  v94 = lim_diag_mgmt_tx_event_report(v132, v72, a5, 0, 0);
  v102 = *(_QWORD *)(a5 + 7432);
  if ( v102 )
    v103 = *(_WORD *)(v102 + 10);
  else
    v103 = 0;
  context = _cds_get_context(54, (__int64)"lim_send_auth_mgmt_frame", v94, v95, v96, v97, v98, v99, v100, v101);
  LOBYTE(v127) = v75;
  LOBYTE(v126) = v90;
  LOBYTE(v128) = 0;
  v105 = wma_tx_packet(
           context,
           v134,
           v135,
           3,
           1,
           7,
           lim_tx_complete,
           v136[0],
           lim_auth_tx_complete_cnf,
           v126,
           v127,
           v128,
           v103,
           v93,
           v92,
           0);
  result = qdf_trace(53, 5u, *(_WORD *)(a5 + 8), v105);
  if ( v105 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: *** Could not send Auth frame, retCode=%X ***",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "lim_send_auth_mgmt_frame",
      v105);
    *((_DWORD *)v50 + 14) = 3;
    result = lim_diag_event_report(v132, 78, a5, 2);
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
