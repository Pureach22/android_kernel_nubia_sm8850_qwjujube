__int64 __fastcall lim_process_mlm_join_cnf(__int64 a1, __int64 a2)
{
  __int64 session_by_session_id; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 v14; // x4
  unsigned int v15; // w22
  __int64 result; // x0
  __int16 v17; // w2
  const char *v18; // x2

  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a2 + 6));
  if ( !session_by_session_id )
  {
    v14 = *(unsigned __int8 *)(a2 + 6);
    v18 = "%s: SessionId:%d does not exist";
    return qdf_trace_msg(0x35u, 2u, v18, v5, v6, v7, v8, v9, v10, v11, v12, "lim_process_mlm_join_cnf", v14);
  }
  v13 = session_by_session_id;
  wlan_connectivity_sta_info_event(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(session_by_session_id + 10), 0);
  wlan_connectivity_connecting_event(*(_QWORD *)(v13 + 16), 0);
  v14 = *(unsigned int *)(v13 + 80);
  *(_BYTE *)(v13 + 13283) = 0;
  if ( (_DWORD)v14 != 3 )
  {
    v18 = "%s: received unexpected MLM_JOIN_CNF in state %X";
    return qdf_trace_msg(0x35u, 2u, v18, v5, v6, v7, v8, v9, v10, v11, v12, "lim_process_mlm_join_cnf", v14);
  }
  v15 = *(_DWORD *)a2;
  if ( !*(_DWORD *)a2 )
  {
    result = lim_sta_send_add_bss_pre_assoc(a1, v13, v5, v6, v7, v8, v9, v10, v11, v12);
    if ( !(_DWORD)result )
      return result;
    v15 = 506;
  }
  v17 = *(_WORD *)(v13 + 8);
  *(_DWORD *)(v13 + 80) = 7;
  qdf_trace(53, 1u, v17, 7);
  return lim_handle_sme_join_result(a1, v15, *(unsigned __int16 *)(a2 + 4), v13);
}
