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
  unsigned int v13; // w20
  __int64 v18; // x21
  unsigned int v19; // w24
  int v20; // w28
  unsigned int v21; // w26
  const char *v22; // x2
  unsigned int v23; // w8
  int v24; // w8
  __int64 result; // x0
  unsigned __int16 *v26; // x27
  char *v27; // x24
  char *v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w8
  __int16 v38; // w8
  __int64 v39; // x5
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned __int16 *v48; // x25
  _WORD *v49; // x21
  unsigned int v50; // w26
  int v51; // w8
  int v52; // w9
  int v53; // w10
  int v54; // w11
  __int64 v55; // x26
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  _WORD *v64; // x23
  __int64 v65; // x8
  char v66; // w23
  int v67; // w22
  char v68; // w21
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x8
  __int16 v78; // w24
  _QWORD *context; // x0
  unsigned int v80; // w21
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x8
  int v98; // w8
  __int64 v99; // x8
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  int v108; // w8
  __int64 v109; // x8
  int v110; // [xsp+8h] [xbp-68h]
  int v111; // [xsp+10h] [xbp-60h]
  int v112; // [xsp+18h] [xbp-58h]
  unsigned int v113; // [xsp+44h] [xbp-2Ch]
  __int64 v114; // [xsp+48h] [xbp-28h]
  __int64 v115; // [xsp+50h] [xbp-20h] BYREF
  unsigned int v116; // [xsp+5Ch] [xbp-14h] BYREF
  void *v117[2]; // [xsp+60h] [xbp-10h] BYREF

  v117[1] = *(void **)(_ReadStatusReg(SP_EL0) + 1808);
  v117[0] = nullptr;
  v116 = 0;
  v115 = 0;
  if ( !a5 )
  {
    v22 = "%s: Error: psession Entry is NULL";
LABEL_20:
    result = qdf_trace_msg(0x35u, 2u, v22, a6, a7, a8, a9, a10, a11, a12, a13, "lim_send_auth_mgmt_frame");
    goto LABEL_21;
  }
  v13 = *(unsigned __int8 *)(a5 + 10);
  if ( a4 )
  {
    v18 = a1;
    v19 = 0;
    v20 = 0;
    v21 = a4 + 16;
    v116 = a4 + 40;
    goto LABEL_18;
  }
  v23 = a2[1];
  if ( v23 > 2 )
  {
    if ( v23 == 3 || v23 == 4 )
      goto LABEL_15;
LABEL_49:
    v22 = "%s: Invalid auth transaction seq num";
    goto LABEL_20;
  }
  if ( v23 == 1 )
  {
    v116 = 30;
    v18 = a1;
    result = lim_create_fils_auth_data(a1, a2, a5, &v116, 0);
    if ( (_DWORD)result )
      goto LABEL_21;
    if ( *a2 == 2 )
    {
      v97 = *(_QWORD *)(a5 + 7432);
      if ( v97 && (v19 = *(unsigned __int16 *)(v97 + 36), *(_WORD *)(v97 + 36)) )
      {
        v116 += v19;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Auth frame, FTIES length added=%d",
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          "lim_send_auth_mgmt_frame",
          v19);
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Auth frame, Does not contain FTIES!",
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          "lim_send_auth_mgmt_frame");
        v19 = 0;
        v116 += 5;
      }
    }
    else
    {
      v19 = 0;
    }
    v109 = *(_QWORD *)(a5 + 112);
    if ( !v109 || *(_BYTE *)(a5 + 7041) != 1 || *a2 != 4 || !*(_BYTE *)(v109 + 4408) )
    {
LABEL_80:
      v20 = 0;
      goto LABEL_17;
    }
    v20 = 0;
    v24 = v116 + 5;
LABEL_16:
    v116 = v24;
LABEL_17:
    v21 = 6;
    goto LABEL_18;
  }
  if ( v23 != 2 )
    goto LABEL_49;
  if ( !*a2 || a2[2] )
  {
LABEL_15:
    v18 = a1;
    v19 = 0;
    v20 = 0;
    v24 = 30;
    goto LABEL_16;
  }
  if ( *a2 == 4 )
  {
    v116 = 30;
    v18 = a1;
    if ( (unsigned int)lim_create_fils_auth_data(a1, a2, a5, &v116, a3) )
    {
      v22 = "%s: Failed to create FILS Data";
      goto LABEL_20;
    }
    v19 = 0;
    goto LABEL_80;
  }
  v18 = a1;
  v19 = 0;
  v20 = 1;
  v21 = 136;
  v116 = 160;
LABEL_18:
  if ( (unsigned int)cds_packet_alloc(v116, v117, &v115) )
  {
    v22 = "%s: call to bufAlloc failed for AUTH frame";
    goto LABEL_20;
  }
  v113 = v19;
  v114 = v18;
  v26 = (unsigned __int16 *)(v18 + 21532);
  qdf_mem_set(v117[0], v116, 0);
  v27 = (char *)v117[0];
  v28 = (char *)v117[0] + 4;
  *(_BYTE *)v117[0] = -80;
  qdf_mem_copy(v28, a3, 6u);
  v27[10] = *(_BYTE *)(a5 + 30);
  v27[11] = *(_BYTE *)(a5 + 31);
  v27[12] = *(_BYTE *)(a5 + 32);
  v27[13] = *(_BYTE *)(a5 + 33);
  v27[14] = *(_BYTE *)(a5 + 34);
  v27[15] = *(_BYTE *)(a5 + 35);
  qdf_mem_copy(v27 + 16, a3, 6u);
  v37 = *(unsigned __int16 *)(v18 + 21532);
  if ( v37 <= 0xFFE )
    v38 = v37 + 1;
  else
    v38 = 2048;
  *v26 = v38;
  *((_WORD *)v27 + 11) = (16 * (v38 & 0xF)) | *((_WORD *)v27 + 11) & 0xFF0F;
  v39 = (unsigned __int8)(*v26 >> 4);
  *((_WORD *)v27 + 11) = (16 * *v26) & 0xFF00 | (16 * (v38 & 0xF));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "lim_populate_mac_header",
    v38 & 0xF,
    v39,
    *v26,
    0);
  v48 = (unsigned __int16 *)v117[0];
  *(_WORD *)v117[0] = *(_WORD *)v117[0] & 0xBFFF | ((a4 != 0) << 14);
  if ( *(_DWORD *)(a5 + 88) == 1 )
    qdf_mem_copy(v48 + 8, (const void *)(a5 + 24), 6u);
  v49 = v117[0];
  if ( a4 )
  {
    qdf_mem_copy((char *)v117[0] + 24, a2, v21);
    v50 = v13;
  }
  else
  {
    *((_WORD *)v117[0] + 12) = *a2;
    v49[13] = a2[1];
    v49[14] = a2[2];
    if ( v20 )
    {
      *((_BYTE *)v49 + 30) = *((_BYTE *)a2 + 6);
      *((_BYTE *)v49 + 31) = *((_BYTE *)a2 + 7);
      if ( v21 - 6 > 0xFE )
      {
        qdf_mem_copy(v49 + 16, a2 + 4, 0x80u);
        v64 = v49 + 80;
      }
      else
      {
        v55 = v21 - 8;
        qdf_mem_copy(v49 + 16, a2 + 4, (unsigned int)v55);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Incomplete challenge info: length: %d, expected: %d",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "lim_send_auth_mgmt_frame",
          (unsigned int)v55,
          255);
        v64 = (_WORD *)((char *)v49 + v55 + 32);
      }
    }
    else
    {
      v64 = v49 + 15;
    }
    v98 = *a2;
    v50 = v13;
    if ( v98 == 4 )
    {
      v108 = a2[1];
      if ( v108 == 2 )
      {
        if ( !a2[2] )
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: FILS: appending fils Auth data for Frame 2",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "lim_send_auth_mgmt_frame");
      }
      else if ( v108 == 1 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FILS: appending fils Auth data",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "lim_send_auth_mgmt_frame");
        lim_add_fils_data_to_auth_frame(a5, (int)v64);
      }
    }
    else if ( v98 == 2 && a2[1] == 1 )
    {
      v99 = *(_QWORD *)(a5 + 7432);
      if ( v99 )
      {
        if ( v113 )
        {
          qdf_mem_copy(v64, (const void *)(v99 + 38), v113);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Auth1 Frame FTIE is: ",
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            "lim_send_auth_mgmt_frame");
          ((void (__fastcall *)(__int64, __int64, _WORD *, _QWORD))qdf_trace_hex_dump)(53, 8, v64, v113);
        }
        else if ( *(_QWORD *)(v99 + 424) )
        {
          *v64 = 822;
          qdf_mem_copy(v64 + 1, (const void *)(*(_QWORD *)(*(_QWORD *)(a5 + 7432) + 424LL) + 45LL), 3u);
        }
      }
    }
  }
  if ( v48 == (unsigned __int16 *)-4LL )
  {
    v53 = 0;
    v51 = 0;
    v52 = 0;
    v54 = 0;
  }
  else
  {
    v51 = *((unsigned __int8 *)v48 + 4);
    v52 = *((unsigned __int8 *)v48 + 5);
    v53 = *((unsigned __int8 *)v48 + 6);
    v54 = *((unsigned __int8 *)v48 + 9);
  }
  qdf_trace_msg(
    0x35u,
    4u,
    "Auth TX: vdev %d seq %d seq num %d status %d WEP %d to %02x:%02x:%02x:**:**:%02x",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v50,
    a2[1],
    *v26,
    a2[2],
    (*v48 >> 14) & 1,
    v51,
    v52,
    v53,
    v54);
  v65 = *(_QWORD *)(a5 + 7432);
  if ( (!v65 || wlan_reg_is_24ghz_ch_freq(*(unsigned __int16 *)(v65 + 10)))
    && wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a5 + 284))
    && (*(_DWORD *)(a5 + 7036) & 0xFFFFFFFE) != 2 )
  {
    v66 = 0;
  }
  else
  {
    v66 = 64;
  }
  if ( (*(_DWORD *)(a5 + 7036) | 2) == 2 )
    v66 |= 0x80u;
  qdf_trace(53, 2u, *(_WORD *)(a5 + 8), (unsigned __int8)*v48 >> 4);
  if ( (*((_DWORD *)v26 + 14) & 0xFFFFFFFE) != 2 )
    *((_DWORD *)v26 + 14) = 0;
  v67 = ((__int64 (__fastcall *)(__int64, _QWORD))lim_get_min_session_txrate)(a5, 0);
  v68 = *(_BYTE *)(v114 + 12208);
  v69 = lim_diag_mgmt_tx_event_report(v114, v48, a5, 0, 0);
  v77 = *(_QWORD *)(a5 + 7432);
  if ( v77 )
    v78 = *(_WORD *)(v77 + 10);
  else
    v78 = 0;
  context = _cds_get_context(54, (__int64)"lim_send_auth_mgmt_frame", v69, v70, v71, v72, v73, v74, v75, v76);
  LOBYTE(v111) = v50;
  LOBYTE(v110) = v66;
  LOBYTE(v112) = 0;
  v80 = wma_tx_packet(
          context,
          v115,
          v116,
          3,
          1,
          7,
          lim_tx_complete,
          v117[0],
          lim_auth_tx_complete_cnf,
          v110,
          v111,
          v112,
          v78,
          v67,
          v68,
          0);
  result = qdf_trace(53, 5u, *(_WORD *)(a5 + 8), v80);
  if ( v80 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: *** Could not send Auth frame, retCode=%X ***",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      "lim_send_auth_mgmt_frame",
      v80);
    *((_DWORD *)v26 + 14) = 3;
    result = lim_diag_event_report(v114, 78, a5, 2);
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
