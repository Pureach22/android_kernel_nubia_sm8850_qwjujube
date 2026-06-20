__int64 __fastcall lim_process_add_sta_rsp(
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
  _BYTE *v10; // x20
  __int64 session_by_session_id; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w9

  v10 = *(_BYTE **)(a2 + 8);
  session_by_session_id = pe_find_session_by_session_id(a1, v10[112], a3, a4, a5, a6, a7, a8, a9, a10);
  if ( session_by_session_id )
  {
    v22 = *(_DWORD *)(session_by_session_id + 88);
    *(_BYTE *)(session_by_session_id + 7276) = v10[114];
    if ( v22 == 6 )
    {
      return lim_ndp_add_sta_rsp(a1, session_by_session_id, *(_QWORD *)(a2 + 8));
    }
    else if ( v10[8] == 4 )
    {
      return lim_process_tdls_add_sta_rsp(a1, *(_QWORD *)(a2 + 8), session_by_session_id);
    }
    else
    {
      return lim_process_mlm_add_sta_rsp(a1, a2, session_by_session_id, v14, v15, v16, v17, v18, v19, v20, v21);
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session Does not exist for given sessionID",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "lim_process_add_sta_rsp");
    return _qdf_mem_free((__int64)v10);
  }
}
