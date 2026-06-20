__int64 __fastcall lim_process_sta_mlm_del_sta_rsp(
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
  unsigned __int16 *v11; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v11 = *(unsigned __int16 **)(a2 + 8);
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
               "lim_process_sta_mlm_del_sta_rsp");
    if ( !*(_QWORD *)(a2 + 8) )
      return result;
LABEL_13:
    result = _qdf_mem_free((__int64)v11);
    *(_QWORD *)(a2 + 8) = 0;
    return result;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Del STA RSP received. Status: %d AssocID: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "lim_process_sta_mlm_del_sta_rsp",
    *((unsigned int *)v11 + 1),
    *v11);
  if ( *((_BYTE *)v11 + 11) == 4 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TDLS Del STA RSP received",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_process_sta_mlm_del_sta_rsp");
    return lim_process_tdls_del_sta_rsp(a1, a2, a3);
  }
  if ( *((_DWORD *)v11 + 1) )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Del STA failed! Status:%d, proceeding with Del BSS",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_process_sta_mlm_del_sta_rsp");
  v24 = *(unsigned int *)(a3 + 72);
  if ( (_DWORD)v24 != 22 )
  {
    v25 = lim_mlm_state_str(v24);
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Received unexpected WDA_DELETE_STA_RSP in state %s",
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               "lim_process_sta_mlm_del_sta_rsp",
               v25);
    if ( !*(_QWORD *)(a2 + 8) )
      return result;
    goto LABEL_13;
  }
  if ( *(_QWORD *)(a2 + 8) )
  {
    _qdf_mem_free((__int64)v11);
    *(_QWORD *)(a2 + 8) = 0;
  }
  return lim_disconnect_complete(a3, 1);
}
