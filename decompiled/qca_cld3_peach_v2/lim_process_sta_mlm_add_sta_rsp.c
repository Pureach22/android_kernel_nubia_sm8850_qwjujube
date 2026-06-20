__int64 __fastcall lim_process_sta_mlm_add_sta_rsp(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x22
  _BYTE *v13; // x25
  int v16; // w23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  __int64 result; // x0
  int v27; // w8
  __int64 hash_entry; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x24
  __int16 v38; // w2
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  char v47; // w8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x2
  __int64 v57; // x1
  __int64 v58; // [xsp+8h] [xbp-18h]
  __int64 v59; // [xsp+10h] [xbp-10h] BYREF
  __int64 v60; // [xsp+18h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 8);
  v59 = 0;
  if ( !v11 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Encountered NULL Pointer",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_process_sta_mlm_add_sta_rsp");
    goto LABEL_21;
  }
  v13 = (_BYTE *)(a3 + 7263);
  if ( *(_DWORD *)(a3 + 80) == 6 )
    v16 = 1015;
  else
    v16 = 1010;
  if ( *(_BYTE *)(a3 + 7263) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Received Deauth frame in ADD_STA_RESP state",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_process_sta_mlm_add_sta_rsp");
    if ( !*(_DWORD *)(v11 + 112) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: ADD_STA success, send update result code with eSIR_SME_JOIN_DEAUTH_FROM_AP_DURING_ADD_STA limMlmState: %d bs"
        "sid %02x:%02x:%02x:**:**:%02x",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "lim_process_sta_mlm_add_sta_rsp",
        *(unsigned int *)(a3 + 72),
        *(unsigned __int8 *)(v11 + 9),
        *(unsigned __int8 *)(v11 + 10),
        *(unsigned __int8 *)(v11 + 11),
        *(unsigned __int8 *)(v11 + 14),
        v58,
        v59,
        v60);
      v25 = *(_DWORD *)(a3 + 80);
      LODWORD(v59) = 507;
      if ( v25 == 6 )
        v16 = 1015;
      goto LABEL_16;
    }
LABEL_12:
    qdf_trace_msg(0x35u, 2u, "%s: ADD_STA failed!", a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_sta_mlm_add_sta_rsp");
    if ( *(_DWORD *)(a3 + 80) == 6 )
      v27 = 537;
    else
      v27 = 506;
    LODWORD(v59) = v27;
LABEL_16:
    WORD2(v59) = 1;
    goto LABEL_17;
  }
  if ( *(_DWORD *)(v11 + 112) )
    goto LABEL_12;
  if ( *(_DWORD *)(a3 + 72) == 21 )
  {
    hash_entry = dph_get_hash_entry(a1, 1u, a3 + 360);
    v37 = hash_entry;
    if ( hash_entry )
    {
      *(_DWORD *)(hash_entry + 8) = 14;
      *(_BYTE *)(hash_entry + 659) = *(_BYTE *)(v11 + 163);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Fail to get DPH Hash Entry for AID - %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "lim_process_sta_mlm_add_sta_rsp",
        1);
    }
    v38 = *(_WORD *)(a3 + 8);
    *(_DWORD *)(a3 + 72) = 14;
    qdf_trace(53, 0, v38, 14);
    if ( (*(_BYTE *)(*(_QWORD *)(a3 + 16) + 60LL) & 2) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: sending assoc cnf for MLO link vdev",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "lim_process_add_sta_rsp_mlo");
      v47 = *(_BYTE *)(a3 + 8);
      LODWORD(v59) = 0;
      BYTE6(v59) = v47;
      qdf_trace(53, 0xAu, 0, 1010);
      lim_process_mlm_assoc_cnf(a1, (unsigned int *)&v59, v48, v49, v50, v51, v52, v53, v54, v55);
    }
    lim_init_tdls_data(a1, a3);
    LODWORD(v59) = 0;
    lim_send_obss_color_collision_cfg(a1, a3, 1);
    if ( !v37 || (v13[1413] & 1) == 0 )
      goto LABEL_17;
    if ( *(_BYTE *)(a1 + 21773) == 1 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Send user cfg MU EDCA params to FW",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_process_sta_mlm_add_sta_rsp");
      v56 = *(unsigned __int8 *)(a3 + 10);
      v57 = a1 + 21753;
    }
    else
    {
      if ( v13[2778] != 1 )
        goto LABEL_17;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Send MU EDCA params to FW",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_process_sta_mlm_add_sta_rsp");
      v56 = *(unsigned __int8 *)(a3 + 10);
      v57 = a3 + 10021;
    }
    v17 = lim_send_edca_params(a1, v57, v56, 1);
    goto LABEL_17;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Received WMA_ADD_STA_RSP in state %X",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "lim_process_sta_mlm_add_sta_rsp");
  LODWORD(v59) = 506;
LABEL_17:
  if ( *(_QWORD *)(a2 + 8) )
  {
    _qdf_mem_free(v11);
    *(_QWORD *)(a2 + 8) = 0;
  }
  BYTE6(v59) = *(_BYTE *)(a3 + 8);
  result = lim_process_mlm_rsp_messages(a1, v16, (unsigned __int8 *)&v59, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( *v13 == 1 )
    *v13 = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
