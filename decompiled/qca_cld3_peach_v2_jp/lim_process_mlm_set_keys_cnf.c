__int64 __fastcall lim_process_mlm_set_keys_cnf(
        __int64 a1,
        unsigned __int8 *a2,
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x0
  int v23; // w11
  __int64 result; // x0
  __int16 v25; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  if ( a2 )
  {
    session_by_session_id = pe_find_session_by_session_id(a1, a2[10]);
    if ( session_by_session_id )
    {
      v21 = session_by_session_id;
      if ( *((_WORD *)a2 + 3) )
      {
        v22 = 0;
      }
      else
      {
        v22 = dph_lookup_hash_entry(v13, v14, v15, v16, v17, v18, v19, v20, a1, a2, &v25, session_by_session_id + 360);
        if ( v22 && a2[11] == 1 )
          *(_BYTE *)(v22 + 641) = 1;
      }
      if ( v22 )
        v23 = *(unsigned __int8 *)(v22 + 641);
      else
        v23 = 0;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev %d: %02x:%02x:%02x:**:**:%02x Status %d key_len_nonzero %d key installed %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_process_mlm_set_keys_cnf",
        *(unsigned __int8 *)(v21 + 10),
        *a2,
        a2[1],
        a2[2],
        a2[5],
        *((unsigned __int16 *)a2 + 3),
        a2[11],
        v23);
      result = lim_send_sme_set_context_rsp(
                 a1,
                 *(unsigned int *)a2 | ((unsigned __int64)*((unsigned __int16 *)a2 + 2) << 32),
                 1,
                 *((unsigned __int16 *)a2 + 3),
                 v21,
                 *(unsigned __int8 *)(v21 + 10));
    }
    else
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: session does not exist for given sessionId %d",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "lim_process_mlm_set_keys_cnf",
                 a2[10]);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Buffer is Pointing to NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_mlm_set_keys_cnf");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
