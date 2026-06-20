__int64 __fastcall lim_process_ap_mlm_add_sta_rsp(
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
  __int64 v11; // x20
  __int64 hash_entry; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x23
  __int64 v25; // x4
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  unsigned int v35; // w24
  __int64 result; // x0
  __int16 v37; // w9
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x7
  int v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  v11 = *(_QWORD *)(a2 + 8);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid body pointer in message",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_process_ap_mlm_add_sta_rsp");
    v24 = 0;
    goto LABEL_11;
  }
  hash_entry = dph_get_hash_entry(a1, *(_WORD *)(v11 + 6), a3 + 360);
  v24 = hash_entry;
  if ( !hash_entry )
  {
    v25 = *(unsigned __int16 *)(v11 + 6);
    v34 = "%s: DPH Entry for STA %X missing";
LABEL_10:
    qdf_trace_msg(0x35u, 2u, v34, v16, v17, v18, v19, v20, v21, v22, v23, "lim_process_ap_mlm_add_sta_rsp", v25);
    goto LABEL_11;
  }
  v25 = *(unsigned int *)(hash_entry + 8);
  if ( (_DWORD)v25 != 21 )
  {
    v34 = "%s: Received unexpected WMA_ADD_STA_RSP in state %X";
    goto LABEL_10;
  }
  if ( *(_DWORD *)(v11 + 112) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Error! rcvd delSta rsp from HAL with status %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_process_ap_mlm_add_sta_rsp");
LABEL_6:
    lim_reject_association(
      a1,
      (unsigned __int8 *)(v24 + 350),
      *(_BYTE *)(v24 + 32) & 1,
      1u,
      *(_DWORD *)(v24 + 12),
      *(_WORD *)(v24 + 348),
      1u,
      1u,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      a3);
LABEL_11:
    v35 = 0;
    goto LABEL_12;
  }
  v37 = *(_WORD *)hash_entry;
  v38 = *(unsigned __int16 *)(hash_entry + 348);
  v39 = *(unsigned __int8 *)(hash_entry + 350);
  *(_BYTE *)(hash_entry + 659) = *(_BYTE *)(v11 + 163);
  v40 = *(unsigned __int8 *)(hash_entry + 351);
  v41 = *(unsigned __int8 *)(hash_entry + 352);
  *(_WORD *)hash_entry = v37 | 1;
  v42 = *(unsigned __int8 *)(hash_entry + 355);
  *(_DWORD *)(hash_entry + 8) = 15;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: AddStaRsp Success.STA AssocID %d sta mac%02x:%02x:%02x:**:**:%02x",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "lim_process_ap_mlm_add_sta_rsp",
    v38,
    v39,
    v40,
    v41,
    v42);
  if ( (lim_is_mlo_conn(a3, v24) & 1) == 0
    && (unsigned int)lim_send_mlm_assoc_ind(a1, v24, a3, v43, v44, v45, v46, v47, v48, v49, v50) )
  {
    goto LABEL_6;
  }
  v35 = 1;
LABEL_12:
  result = lim_is_mlo_conn(a3, v24);
  if ( (result & 1) != 0 )
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))lim_ap_mlo_sta_peer_ind)(a1, a3, v24, v35);
  if ( *(_QWORD *)(a2 + 8) )
  {
    result = _qdf_mem_free(v11);
    *(_QWORD *)(a2 + 8) = 0;
  }
  return result;
}
