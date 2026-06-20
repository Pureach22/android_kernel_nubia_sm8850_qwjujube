__int64 __fastcall lim_process_mlm_deauth_cnf(
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
  __int64 session_by_session_id; // x0
  __int64 v13; // x2
  const char *v14; // x2
  int v16; // w8
  __int64 v17; // x4
  int v18; // w3
  unsigned int v19; // w21
  __int16 v20; // w2
  __int64 v21; // x22

  if ( !a2 )
  {
    v14 = "%s: Buffer is Pointing to NULL";
    return qdf_trace_msg(0x35u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_mlm_deauth_cnf");
  }
  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a2 + 16));
  if ( !session_by_session_id )
  {
    v14 = "%s: session does not exist for given session Id";
    return qdf_trace_msg(0x35u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_mlm_deauth_cnf");
  }
  if ( *(_WORD *)(a2 + 12) == 6 )
    v13 = 505;
  else
    v13 = *(unsigned int *)(a2 + 8);
  v16 = *(_DWORD *)(session_by_session_id + 88);
  if ( v16 == 2 )
  {
    if ( (*(_DWORD *)(session_by_session_id + 80) & 0xFFFFFFFE) != 0xC )
      return qdf_trace_msg(
               0x35u,
               2u,
               "%s: received unexpected MLM_DEAUTH_CNF in state %X",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_mlm_deauth_cnf");
    if ( *(_DWORD *)(a2 + 8) )
    {
      v18 = *(_DWORD *)(session_by_session_id + 84);
      v19 = v13;
    }
    else
    {
      v19 = v13;
      v18 = 1;
    }
    v20 = *(_WORD *)(session_by_session_id + 8);
    v21 = session_by_session_id;
    *(_DWORD *)(session_by_session_id + 80) = v18;
    qdf_trace(53, 1u, v20, v18);
    if ( *(_BYTE *)(a1 + 4012) )
    {
      v17 = 1;
      session_by_session_id = v21;
      v13 = v19;
      *(_BYTE *)(a1 + 4012) = 0;
      return lim_send_sme_deauth_ntf(
               a1,
               a2,
               v13,
               *(unsigned __int16 *)(a2 + 12),
               v17,
               *(unsigned __int8 *)(session_by_session_id + 10));
    }
    session_by_session_id = v21;
    v13 = v19;
LABEL_20:
    v17 = 1;
    return lim_send_sme_deauth_ntf(
             a1,
             a2,
             v13,
             *(unsigned __int16 *)(a2 + 12),
             v17,
             *(unsigned __int8 *)(session_by_session_id + 10));
  }
  if ( v16 != 1 )
    goto LABEL_20;
  v17 = *(unsigned __int16 *)(a2 + 14);
  return lim_send_sme_deauth_ntf(
           a1,
           a2,
           v13,
           *(unsigned __int16 *)(a2 + 12),
           v17,
           *(unsigned __int8 *)(session_by_session_id + 10));
}
