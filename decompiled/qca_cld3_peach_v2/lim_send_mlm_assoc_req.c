__int64 __fastcall lim_send_mlm_assoc_req(
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
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
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
  __int16 v47; // [xsp+4h] [xbp-3Ch] BYREF
  _QWORD v48[7]; // [xsp+8h] [xbp-38h] BYREF

  v48[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 112);
  v47 = 0;
  if ( !v10 )
  {
    v27 = "%s: Join Request is NULL";
LABEL_17:
    result = qdf_trace_msg(0x35u, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, "lim_send_mlm_assoc_req");
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
  if ( (unsigned int)lim_get_capability_info(a1, &v47, a2) )
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
  v23 = v47;
  v24 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 112) + 4566LL);
  if ( (v24 & 0x100) == 0 )
    v23 = v47 & 0xFEFF;
  if ( (v24 & 0x1000) == 0 )
    v23 &= ~0x1000u;
  if ( (~v24 & 0x1100) == 0 )
  {
    if ( (v24 & 0x20) != 0 )
      goto LABEL_11;
LABEL_19:
    v47 = v23 & 0xFFDF;
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
    v23 = v47;
    if ( (*(_WORD *)(*(_QWORD *)(a2 + 112) + 4566LL) & 0x8000) != 0 )
      goto LABEL_13;
    goto LABEL_12;
  }
  v47 = v23;
  if ( (v24 & 0x20) == 0 )
    goto LABEL_19;
LABEL_11:
  if ( (v24 & 0x8000) == 0 )
  {
LABEL_12:
    v47 = v23 & 0x7FFF;
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
    v23 = v47;
  }
LABEL_13:
  *((_WORD *)v14 + 3) = v23;
  v25 = *(_QWORD *)(a1 + 8);
  if ( *(_BYTE *)(v25 + 3412) == 1 )
    v26 = *(unsigned __int8 *)(v25 + 3413);
  else
    v26 = *(unsigned __int16 *)(v25 + 3404);
  lim_diag_event_report(a1, 62, a2, 0);
  *((_WORD *)v14 + 4) = v26;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Listen Interval : %d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "lim_send_mlm_assoc_req",
    v26);
  v14[10] = *(_BYTE *)(a2 + 8);
  v37 = *(_DWORD *)(a2 + 80);
  v38 = *(_WORD *)(a2 + 8);
  *(_DWORD *)(a2 + 80) = 5;
  *(_DWORD *)(a2 + 84) = v37;
  qdf_trace(53, 1u, v38, 5);
  memset(&v48[2], 0, 32);
  v48[1] = v14;
  v48[0] = 1009;
  mac_trace_msg_rx(a1, 255, 1009);
  result = lim_process_mlm_req_messages(a1, (unsigned __int16 *)v48, v39, v40, v41, v42, v43, v44, v45, v46);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
