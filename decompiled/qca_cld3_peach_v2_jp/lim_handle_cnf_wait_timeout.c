__int64 __fastcall lim_handle_cnf_wait_timeout(__int64 a1, unsigned __int16 a2)
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
  __int64 v13; // x20
  __int64 hash_entry; // x0
  __int64 v15; // x21
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2

  session_by_session_id = pe_find_session_by_session_id(
                            a1,
                            *(unsigned __int8 *)(*(_QWORD *)(a1 + 1336) + 264LL * a2 + 50));
  if ( !session_by_session_id )
  {
    v25 = "%s: Session Does not exist for given sessionID";
    return qdf_trace_msg(0x35u, 2u, v25, v5, v6, v7, v8, v9, v10, v11, v12, "lim_handle_cnf_wait_timeout");
  }
  v13 = session_by_session_id;
  hash_entry = dph_get_hash_entry(a1, a2, session_by_session_id + 360);
  if ( !hash_entry )
  {
    v25 = "%s: No STA context in SIR_LIM_CNF_WAIT_TIMEOUT";
    return qdf_trace_msg(0x35u, 2u, v25, v5, v6, v7, v8, v9, v10, v11, v12, "lim_handle_cnf_wait_timeout");
  }
  if ( *(_DWORD *)(hash_entry + 8) != 15 )
    return qdf_trace_msg(
             0x35u,
             3u,
             "%s: Received CNF_WAIT_TIMEOUT in state %d",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "lim_handle_cnf_wait_timeout");
  v15 = hash_entry;
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: Did not receive Assoc Cnf in eLIM_MLM_WT_ASSOC_CNF_STATE sta Assoc id %d and STA: %02x:%02x:%02x:**:**:%02x",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "lim_handle_cnf_wait_timeout",
             *(unsigned __int16 *)(hash_entry + 336),
             *(unsigned __int8 *)(hash_entry + 338),
             *(unsigned __int8 *)(hash_entry + 339),
             *(unsigned __int8 *)(hash_entry + 340),
             *(unsigned __int8 *)(hash_entry + 343));
  if ( *(_DWORD *)(v13 + 88) == 1 )
    return lim_reject_association(
             a1,
             (unsigned __int8 *)(v15 + 338),
             *(_BYTE *)(v15 + 32) & 1,
             1u,
             *(_DWORD *)(v15 + 12),
             *(_WORD *)(v15 + 336),
             1u,
             1u,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v13);
  return result;
}
