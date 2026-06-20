__int64 __fastcall lim_process_join_failure_timeout(__int64 a1)
{
  __int64 v2; // x1
  __int64 session_by_session_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  int v23; // w4
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int16 v32; // w2
  __int64 v33; // x0
  __int64 result; // x0
  int v35; // [xsp+0h] [xbp-20h]
  __int64 v36; // [xsp+8h] [xbp-18h]
  __int64 v37; // [xsp+10h] [xbp-10h] BYREF
  __int64 v38; // [xsp+18h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(a1 + 1122);
  v37 = 0xFFF8000001FCLL;
  session_by_session_id = pe_find_session_by_session_id(a1, v2);
  if ( session_by_session_id )
  {
    v12 = session_by_session_id;
    v13 = _qdf_mem_malloc(0xDu, "lim_process_join_failure_timeout", 1703);
    if ( v13 )
    {
      v22 = v13;
      host_diag_log_set_code(v13, 4948);
      host_diag_log_set_length(v22, 13);
      *(_BYTE *)(v22 + 12) = *(_BYTE *)(v12 + 7264);
      host_diag_log_submit(v22);
      _qdf_mem_free(v22);
    }
    v23 = *(_DWORD *)(v12 + 72);
    *(_BYTE *)(v12 + 13283) = 0;
    if ( v23 == 2 )
    {
      lim_deactivate_and_change_timer(a1, 2);
      lim_deactivate_and_change_timer(a1, 18);
      v35 = *(unsigned __int8 *)(v12 + 29);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Join Failure Timeout, In eLIM_MLM_WT_JOIN_BEACON_STATE session:%d %02x:%02x:%02x:**:**:%02x",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_process_join_failure_timeout",
        *(unsigned __int16 *)(v12 + 8),
        *(unsigned __int8 *)(v12 + 24),
        *(unsigned __int8 *)(v12 + 25),
        *(unsigned __int8 *)(v12 + 26),
        v35,
        v36,
        v37,
        v38);
      v32 = *(_WORD *)(v12 + 8);
      *(_DWORD *)(v12 + 72) = 1;
      qdf_trace(53, 0, v32, 1);
      v33 = *(_QWORD *)(v12 + 128);
      BYTE6(v37) = *(_BYTE *)(v12 + 8);
      if ( v33 )
      {
        _qdf_mem_free(v33);
        *(_QWORD *)(v12 + 128) = 0;
      }
      result = lim_process_mlm_rsp_messages(a1, 1005, &v37);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: received unexpected JOIN failure timeout in state %X",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_process_join_failure_timeout");
      result = lim_print_mlm_state(a1, 3, *(unsigned int *)(v12 + 72));
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Session Does not exist for given sessionID",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "lim_process_join_failure_timeout");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
