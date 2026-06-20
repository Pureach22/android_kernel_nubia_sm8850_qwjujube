__int64 __fastcall lim_process_mlm_join_req(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v2; // w20
  __int64 session_by_session_id; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20

  v2 = *a2;
  session_by_session_id = pe_find_session_by_session_id(a1, *a2);
  if ( !session_by_session_id )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: SessionId:%d does not exist",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "lim_process_mlm_join_req",
             v2);
  *(_QWORD *)(session_by_session_id + 128) = a2;
  v14 = session_by_session_id;
  lim_deactivate_and_change_timer(a1, 2);
  *(_BYTE *)(a1 + 1122) = *(_BYTE *)(v14 + 8);
  *(_WORD *)(v14 + 152) = 1;
  *(_QWORD *)(v14 + 136) = 0;
  return lim_send_switch_chnl_params(a1, v14);
}
