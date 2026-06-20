__int64 __fastcall lim_process_sta_add_bss_rsp_pre_assoc(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _BYTE *v23; // x8
  int v24; // w22
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  char v35; // w8
  __int16 v36; // w2
  int v37; // w8
  __int16 v38; // w2
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 result; // x0
  __int16 v48; // w2
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v57; // x2
  const char *v58; // x3
  _QWORD v59[7]; // [xsp+8h] [xbp-38h] BYREF

  v59[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid body pointer in message",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_process_sta_add_bss_rsp_pre_assoc");
    goto LABEL_14;
  }
  if ( a4 )
  {
LABEL_14:
    v48 = *(_WORD *)(a3 + 8);
    *(_DWORD *)(a3 + 80) = 7;
    qdf_trace(53, 1u, v48, 7);
    result = lim_handle_sme_join_result(a1, 506, 1u, a3, v49, v50, v51, v52, v53, v54, v55, v56);
    goto LABEL_15;
  }
  if ( !dph_add_hash_entry(a5, a6, a7, a8, a9, a10, a11, a12, a1, a2 + 33, 1u, a3 + 360) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not add hash entry at DPH for STA: %02x:%02x:%02x:**:**:%02x",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_process_sta_add_bss_rsp_pre_assoc",
      a2[33],
      a2[34],
      a2[35],
      a2[38]);
    goto LABEL_14;
  }
  v23 = *(_BYTE **)(a3 + 9976);
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5655LL) == 9 )
    v24 = 1;
  else
    v24 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5655LL);
  if ( v23 && *v23 == 1 )
    v24 = (unsigned __int8)v23[18];
  v25 = _qdf_mem_malloc(0x10u, "lim_process_sta_add_bss_rsp_pre_assoc", 2282);
  if ( !v25 )
  {
    v57 = "%s: Allocate Memory failed for mlmAuthReq";
    v58 = "lim_process_sta_add_bss_rsp_pre_assoc";
LABEL_19:
    result = qdf_trace_msg(0x35u, 2u, v57, v26, v27, v28, v29, v30, v31, v32, v33, v58);
    goto LABEL_15;
  }
  v34 = v25;
  *(_BYTE *)v25 = *(_BYTE *)(a3 + 24);
  *(_BYTE *)(v25 + 1) = *(_BYTE *)(a3 + 25);
  *(_BYTE *)(v25 + 2) = *(_BYTE *)(a3 + 26);
  *(_BYTE *)(v25 + 3) = *(_BYTE *)(a3 + 27);
  *(_BYTE *)(v25 + 4) = *(_BYTE *)(a3 + 28);
  v35 = *(_BYTE *)(a3 + 29);
  *(_DWORD *)(v25 + 8) = v24;
  *(_BYTE *)(v25 + 5) = v35;
  v36 = *(_WORD *)(a3 + 8);
  *(_DWORD *)(a3 + 72) = 3;
  qdf_trace(53, 0, v36, 3);
  *(_BYTE *)(v34 + 12) = *(_BYTE *)(a3 + 8);
  v37 = *(_DWORD *)(a3 + 80);
  v38 = *(_WORD *)(a3 + 8);
  *(_DWORD *)(a3 + 80) = 4;
  *(_DWORD *)(a3 + 84) = v37;
  qdf_trace(53, 1u, v38, 4);
  if ( (*(_BYTE *)(*(_QWORD *)(a3 + 16) + 60LL) & 2) != 0 )
  {
    _qdf_mem_free(v34);
    v57 = "%s: vdev is an MLO link, skip Auth";
    v58 = "lim_process_mlo_sta_add_bss_skip_auth";
    goto LABEL_19;
  }
  memset(&v59[2], 0, 32);
  v59[1] = v34;
  v59[0] = 1006;
  mac_trace_msg_rx(a1, 255, 1006);
  result = lim_process_mlm_req_messages(a1, (unsigned __int16 *)v59, v39, v40, v41, v42, v43, v44, v45, v46);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
