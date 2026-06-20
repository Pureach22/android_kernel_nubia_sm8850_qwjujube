void __fastcall lim_send_mlm_assoc_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  _BYTE *v13; // x0
  _BYTE *v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int16 v23; // w9
  int v24; // w8
  __int64 v25; // x8
  unsigned int v26; // w22
  const char *v27; // x2
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w8
  __int16 v37; // w2
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int16 v46; // [xsp+4h] [xbp-3Ch] BYREF
  _QWORD v47[7]; // [xsp+8h] [xbp-38h] BYREF

  v47[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 112);
  v46 = 0;
  if ( !v10 )
  {
    v27 = "%s: Join Request is NULL";
LABEL_17:
    qdf_trace_msg(0x35u, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, "lim_send_mlm_assoc_req");
    goto LABEL_23;
  }
  v13 = (_BYTE *)_qdf_mem_malloc(0xCu, "lim_send_mlm_assoc_req", 387);
  if ( !v13 )
  {
    v27 = "%s: call to AllocateMemory failed for mlmAssocReq";
    goto LABEL_17;
  }
  v14 = v13;
  *v13 = *(_BYTE *)(a2 + 24);
  v13[1] = *(_BYTE *)(a2 + 25);
  v13[2] = *(_BYTE *)(a2 + 26);
  v13[3] = *(_BYTE *)(a2 + 27);
  v13[4] = *(_BYTE *)(a2 + 28);
  v13[5] = *(_BYTE *)(a2 + 29);
  if ( (unsigned int)lim_get_capability_info(a1, &v46, a2) )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not retrieve Capabilities value",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_send_mlm_assoc_req");
  v23 = v46;
  v24 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 112) + 4382LL);
  if ( (v24 & 0x100) == 0 )
    v23 = v46 & 0xFEFF;
  if ( (v24 & 0x1000) == 0 )
    v23 &= ~0x1000u;
  if ( (~v24 & 0x1100) == 0 )
  {
    if ( (v24 & 0x20) != 0 )
      goto LABEL_11;
LABEL_19:
    v46 = v23 & 0xFFDF;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Clearing short preamble:no AP support",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_send_mlm_assoc_req");
    v23 = v46;
    if ( (*(_WORD *)(*(_QWORD *)(a2 + 112) + 4382LL) & 0x8000) != 0 )
      goto LABEL_13;
    goto LABEL_12;
  }
  v46 = v23;
  if ( (v24 & 0x20) == 0 )
    goto LABEL_19;
LABEL_11:
  if ( (v24 & 0x8000) == 0 )
  {
LABEL_12:
    v46 = v23 & 0x7FFF;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Clearing Immed Blk Ack:no AP support",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_send_mlm_assoc_req");
    v23 = v46;
  }
LABEL_13:
  *((_WORD *)v14 + 3) = v23;
  v25 = *(_QWORD *)(a1 + 8);
  if ( *(_BYTE *)(v25 + 3212) == 1 )
    v26 = *(unsigned __int8 *)(v25 + 3213);
  else
    v26 = *(unsigned __int16 *)(v25 + 3204);
  lim_diag_event_report(a1, 62, a2, 0);
  *((_WORD *)v14 + 4) = v26;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Listen Interval : %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "lim_send_mlm_assoc_req",
    v26);
  v14[10] = *(_BYTE *)(a2 + 8);
  v36 = *(_DWORD *)(a2 + 80);
  v37 = *(_WORD *)(a2 + 8);
  *(_DWORD *)(a2 + 80) = 5;
  *(_DWORD *)(a2 + 84) = v36;
  qdf_trace(53, 1u, v37, 5);
  memset(&v47[2], 0, 32);
  v47[1] = v14;
  v47[0] = 1009;
  mac_trace_msg_rx(a1, 255, 1009);
  lim_process_mlm_req_messages(a1, (unsigned __int16 *)v47, v38, v39, v40, v41, v42, v43, v44, v45);
LABEL_23:
  _ReadStatusReg(SP_EL0);
}
