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
  __int64 v24; // x4
  __int64 v25; // x23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // w8
  unsigned int v35; // w4
  unsigned __int8 *v36; // x1
  unsigned __int16 v37; // w5
  __int64 result; // x0
  const char *v39; // x2
  __int16 v40; // w9
  __int64 v41; // x4
  __int64 v42; // x5
  __int64 v43; // x6
  __int64 v44; // x7
  int v45; // w8
  __int64 v46; // x23
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7

  v11 = *(_QWORD *)(a2 + 8);
  if ( !v11 )
  {
    result = qdf_trace_msg(
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
    goto LABEL_13;
  }
  hash_entry = dph_get_hash_entry(a1, *(_WORD *)(v11 + 6), a3 + 360);
  if ( !hash_entry )
  {
    v24 = *(unsigned __int16 *)(v11 + 6);
    v39 = "%s: DPH Entry for STA %X missing";
LABEL_9:
    result = qdf_trace_msg(
               0x35u,
               2u,
               v39,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "lim_process_ap_mlm_add_sta_rsp",
               v24);
    goto LABEL_13;
  }
  v24 = *(unsigned int *)(hash_entry + 8);
  if ( (_DWORD)v24 != 21 )
  {
    v39 = "%s: Received unexpected WMA_ADD_STA_RSP in state %X";
    goto LABEL_9;
  }
  if ( *(_DWORD *)(v11 + 100) )
  {
    v25 = hash_entry;
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
    v34 = *(_BYTE *)(v25 + 32);
    v35 = *(_DWORD *)(v25 + 12);
    v36 = (unsigned __int8 *)(v25 + 338);
    v37 = *(_WORD *)(v25 + 336);
  }
  else
  {
    v40 = *(_WORD *)hash_entry;
    v41 = *(unsigned __int16 *)(hash_entry + 336);
    v42 = *(unsigned __int8 *)(hash_entry + 338);
    *(_BYTE *)(hash_entry + 643) = *(_BYTE *)(v11 + 151);
    v43 = *(unsigned __int8 *)(hash_entry + 339);
    v44 = *(unsigned __int8 *)(hash_entry + 340);
    *(_WORD *)hash_entry = v40 | 1;
    v45 = *(unsigned __int8 *)(hash_entry + 343);
    *(_DWORD *)(hash_entry + 8) = 15;
    v46 = hash_entry;
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
      v41,
      v42,
      v43,
      v44,
      v45);
    result = lim_send_mlm_assoc_ind(a1, v46, a3, v47, v48, v49, v50, v51, v52, v53, v54);
    if ( !(_DWORD)result )
      goto LABEL_13;
    v34 = *(_BYTE *)(v46 + 32);
    v35 = *(_DWORD *)(v46 + 12);
    v36 = (unsigned __int8 *)(v46 + 338);
    v37 = *(_WORD *)(v46 + 336);
  }
  result = lim_reject_association(a1, v36, v34 & 1, 1u, v35, v37, 1u, 1u, v26, v27, v28, v29, v30, v31, v32, v33, a3);
LABEL_13:
  if ( *(_QWORD *)(a2 + 8) )
  {
    result = _qdf_mem_free(v11);
    *(_QWORD *)(a2 + 8) = 0;
  }
  return result;
}
