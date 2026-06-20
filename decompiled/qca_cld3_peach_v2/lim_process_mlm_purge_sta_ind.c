__int64 __fastcall lim_process_mlm_purge_sta_ind(
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
  unsigned int v13; // w22
  __int64 v14; // x21
  __int16 v15; // w2
  __int64 result; // x0
  const char *v17; // x2
  __int64 v18; // [xsp+0h] [xbp-10h] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v18) = 0;
  LODWORD(v18) = 0;
  if ( !a2 )
  {
    v17 = "%s: Buffer is Pointing to NULL";
LABEL_11:
    result = qdf_trace_msg(0x35u, 2u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_mlm_purge_sta_ind", v18, v19);
    goto LABEL_12;
  }
  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a2 + 12));
  if ( !session_by_session_id )
  {
    v17 = "%s: session does not exist for given bssId";
    goto LABEL_11;
  }
  v13 = *(unsigned __int16 *)(a2 + 6);
  v14 = session_by_session_id;
  if ( *(_DWORD *)(session_by_session_id + 88) == 2 && (*(_DWORD *)(session_by_session_id + 80) & 0xFFFFFFFE) != 0xC )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: received unexpected MLM_PURGE_STA_IND in state %X",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_mlm_purge_sta_ind",
               v18,
               v19);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: *** Cleanup completed for staId=%d ***",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_process_mlm_purge_sta_ind",
      *(unsigned __int16 *)(a2 + 10),
      v18,
      v19);
    if ( *(_DWORD *)(v14 + 88) == 2 )
    {
      v15 = *(_WORD *)(v14 + 8);
      *(_DWORD *)(v14 + 80) = 1;
      qdf_trace(53, 1u, v15, 1);
    }
    if ( *(_WORD *)(a2 + 8) == 5 )
      result = lim_send_sme_deauth_ntf(a1, a2, v13, 5, *(unsigned __int16 *)(a2 + 10), *(unsigned __int8 *)(v14 + 10));
    else
      result = lim_send_sme_disassoc_ntf(a1, a2, &v18, v13);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
