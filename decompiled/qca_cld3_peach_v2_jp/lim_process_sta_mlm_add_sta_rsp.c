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
  __int64 v39; // x2
  __int64 v40; // x1
  __int64 v41; // [xsp+8h] [xbp-18h]
  __int64 v42; // [xsp+10h] [xbp-10h] BYREF
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 8);
  v42 = 0;
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
    if ( !*(_DWORD *)(v11 + 100) )
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
        v41,
        v42,
        v43);
      v25 = *(_DWORD *)(a3 + 80);
      LODWORD(v42) = 507;
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
    LODWORD(v42) = v27;
LABEL_16:
    WORD2(v42) = 1;
    goto LABEL_17;
  }
  if ( *(_DWORD *)(v11 + 100) )
    goto LABEL_12;
  if ( *(_DWORD *)(a3 + 72) == 21 )
  {
    hash_entry = dph_get_hash_entry(a1, 1u, a3 + 360);
    v37 = hash_entry;
    if ( hash_entry )
    {
      *(_DWORD *)(hash_entry + 8) = 14;
      *(_BYTE *)(hash_entry + 643) = *(_BYTE *)(v11 + 151);
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
    lim_init_tdls_data(a1, a3);
    LODWORD(v42) = 0;
    lim_send_obss_color_collision_cfg(a1, a3, 1);
    if ( !v37 || (v13[1413] & 1) == 0 )
      goto LABEL_17;
    if ( *(_BYTE *)(a1 + 21701) == 1 )
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
      v39 = *(unsigned __int8 *)(a3 + 10);
      v40 = a1 + 21681;
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
      v39 = *(unsigned __int8 *)(a3 + 10);
      v40 = a3 + 10021;
    }
    v17 = lim_send_edca_params(a1, v40, v39, 1);
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
  LODWORD(v42) = 506;
LABEL_17:
  if ( *(_QWORD *)(a2 + 8) )
  {
    _qdf_mem_free(v11);
    *(_QWORD *)(a2 + 8) = 0;
  }
  BYTE6(v42) = *(_BYTE *)(a3 + 8);
  result = lim_process_mlm_rsp_messages(a1, v16, (unsigned __int8 *)&v42, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( *v13 == 1 )
    *v13 = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
