__int64 __fastcall lim_process_sae_auth_timeout(__int64 a1)
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
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 v21; // x8
  __int64 v22; // x2

  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a1 + 3242));
  if ( !session_by_session_id )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Session does not exist for given session id",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "lim_process_sae_auth_timeout");
  v11 = session_by_session_id;
  result = qdf_trace_msg(
             0x35u,
             3u,
             "%s: SAE auth timeout sessionid %d mlmstate %X SmeState %X",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "lim_process_sae_auth_timeout",
             *(unsigned __int16 *)(session_by_session_id + 8),
             *(unsigned int *)(session_by_session_id + 72),
             *(unsigned int *)(session_by_session_id + 80));
  if ( *(_DWORD *)(v11 + 72) == 29 )
  {
    if ( (*(_DWORD *)(v11 + 7036) | 2) == 2 )
    {
      v21 = *(unsigned int *)(a1 + 21588);
      if ( v21 >= 4 )
        v22 = 1;
      else
        v22 = (unsigned int)(0xFFF9FFFAFFFBFFFALL >> (16 * (unsigned __int8)v21));
      return lim_restore_from_auth_state(a1, 509, v22, v11);
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received unexpected SAE auth timeout in state %X",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_process_sae_auth_timeout");
    return lim_print_mlm_state(a1, 2, *(unsigned int *)(v11 + 72));
  }
  return result;
}
