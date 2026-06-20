__int64 __fastcall lim_process_mlm_assoc_cnf(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 session_by_session_id; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v22; // x5
  __int64 v23; // x4
  __int64 v24; // x21
  int v25; // w3
  __int16 v26; // w2

  if ( !a2 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Buffer is Pointing to NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_process_mlm_assoc_cnf");
  session_by_session_id = pe_find_session_by_session_id(a1, *((unsigned __int8 *)a2 + 6));
  if ( !session_by_session_id )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: SessionId:%d Session does not exist",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "lim_process_mlm_assoc_cnf",
             *((unsigned __int8 *)a2 + 6));
  if ( *(_DWORD *)(session_by_session_id + 80) != 5 || *(_DWORD *)(session_by_session_id + 88) == 1 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: SessionId:%d Received MLM_ASSOC_CNF in state %X",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "lim_process_mlm_assoc_cnf",
             *(unsigned __int16 *)(session_by_session_id + 8));
  v22 = *a2;
  v23 = *(unsigned __int16 *)(session_by_session_id + 8);
  v24 = session_by_session_id;
  if ( (_DWORD)v22 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: SessionId:%d Association failure resultCode: %d limSmeState:%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_process_mlm_assoc_cnf",
      v23,
      v22,
      5);
    if ( *a2 != 507 )
      *(_DWORD *)(v24 + 80) = 7;
    v25 = *(_DWORD *)(a1 + 4056);
    v26 = *(_WORD *)(v24 + 8);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: SessionId:%d Associated with BSS",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_process_mlm_assoc_cnf",
      v23);
    v26 = *(_WORD *)(v24 + 8);
    v25 = 10;
    *(_DWORD *)(v24 + 80) = 10;
  }
  qdf_trace(53, 1u, v26, v25);
  return lim_handle_sme_join_result(a1, *a2, *((unsigned __int16 *)a2 + 2), v24);
}
