__int64 __fastcall lim_process_mlm_disassoc_ind(__int64 a1, __int64 a2)
{
  __int64 session_by_session_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int16 v12; // w2

  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a2 + 12));
  if ( !session_by_session_id )
    return qdf_trace_msg(
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
             "lim_process_mlm_disassoc_ind");
  if ( *(_DWORD *)(session_by_session_id + 88) != 2 )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: *** Peer staId=%d Disassociated ***",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "lim_process_mlm_disassoc_ind",
             *(unsigned __int16 *)(a2 + 10));
  v12 = *(_WORD *)(session_by_session_id + 8);
  *(_DWORD *)(session_by_session_id + 80) = 12;
  return qdf_trace(53, 1u, v12, 12);
}
