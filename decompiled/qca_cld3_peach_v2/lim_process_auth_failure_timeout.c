__int64 __fastcall lim_process_auth_failure_timeout(__int64 a1)
{
  __int64 session_by_session_id; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  int v22; // w8
  unsigned __int64 v23; // x8
  __int64 v24; // x2
  __int64 result; // x0

  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a1 + 858));
  if ( !session_by_session_id )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Session Does not exist for given sessionID",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "lim_process_auth_failure_timeout");
  v11 = session_by_session_id;
  qdf_trace_msg(
    0x35u,
    3u,
    "%s: received AUTH failure timeout in sessionid %d limMlmstate %X limSmeState %X",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "lim_process_auth_failure_timeout",
    *(unsigned __int16 *)(session_by_session_id + 8),
    *(unsigned int *)(session_by_session_id + 72),
    *(unsigned int *)(session_by_session_id + 80));
  lim_diag_event_report(a1, 75, v11, 0);
  v12 = _qdf_mem_malloc(0xDu, "lim_process_auth_failure_timeout", 1960);
  if ( v12 )
  {
    v21 = v12;
    host_diag_log_set_code(v12, 4948);
    host_diag_log_set_length(v21, 13);
    *(_BYTE *)(v21 + 12) = *(_BYTE *)(v11 + 7264);
    host_diag_log_submit(v21);
    _qdf_mem_free(v21);
  }
  if ( (*(_DWORD *)(v11 + 72) | 2) == 7 )
  {
    if ( *(_DWORD *)(v11 + 7036) == 2 )
    {
      v22 = *(_DWORD *)(v11 + 7092);
      if ( v22 )
      {
        if ( (unsigned int)(v22 - 500) >= 0x1195 )
        {
          v22 = 1000;
          *(_DWORD *)(v11 + 7092) = 1000;
        }
        *(_DWORD *)(*(_QWORD *)(a1 + 8) + 3692LL) = v22;
      }
    }
    v23 = *(unsigned int *)(a1 + 21660);
    if ( v23 >= 4 )
      v24 = 1;
    else
      v24 = (unsigned int)(0xFFF9FFFAFFFBFFFALL >> (16 * (unsigned __int8)v23));
    result = lim_restore_from_auth_state(a1, 509, v24, v11);
    *(_DWORD *)(a1 + 21660) = 0;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received unexpected AUTH failure timeout in state %X",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_process_auth_failure_timeout");
    return lim_print_mlm_state(a1, 2, *(unsigned int *)(v11 + 72));
  }
  return result;
}
