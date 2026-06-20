void __fastcall lim_process_channel_vacate_timeout(__int64 a1)
{
  unsigned int v1; // w19
  __int64 session_by_session_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v1 = *(unsigned __int8 *)(a1 + 3770);
  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a1 + 3770));
  if ( session_by_session_id )
  {
    if ( *(_DWORD *)(session_by_session_id + 7036) == 2 )
      lim_handle_heart_beat_failure(a1, session_by_session_id);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session does not exist for given session id %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "lim_process_channel_vacate_timeout",
      v1);
  }
}
