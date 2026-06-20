__int64 __fastcall lim_process_sme_del_all_tdls_peers(
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
  __int64 session_by_bssid; // x0
  __int64 v12; // x20
  __int64 result; // x0
  const char *v14; // x2
  unsigned int v15; // w1
  unsigned __int8 v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  if ( !a2 )
  {
    v14 = "%s: NULL msg";
    v15 = 2;
LABEL_6:
    qdf_trace_msg(0x35u, v15, v14, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_sme_del_all_tdls_peers");
    result = 16;
    goto LABEL_7;
  }
  session_by_bssid = pe_find_session_by_bssid(a1, (unsigned __int8 *)(a2 + 4), v16);
  if ( !session_by_bssid )
  {
    v14 = "%s: NULL pe_session";
    v15 = 8;
    goto LABEL_6;
  }
  v12 = session_by_bssid;
  lim_check_aid_and_delete_peer(a1, session_by_bssid);
  tgt_tdls_peers_deleted_notification(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v12 + 10));
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
