__int64 __fastcall lim_process_sme_obss_scan_ind(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 session_by_bssid; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 result; // x0
  _BYTE v15[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 8);
  v15[0] = 0;
  session_by_bssid = pe_find_session_by_bssid(a1, v3 + 4, v15);
  if ( session_by_bssid )
  {
    v13 = session_by_bssid;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: OBSS Scan Req: vdev %d (pe session %d) htSupportedChannelWidthSet %d",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "lim_process_sme_obss_scan_ind",
               *(unsigned __int8 *)(session_by_bssid + 10),
               *(unsigned __int16 *)(session_by_bssid + 8),
               *(unsigned __int8 *)(session_by_bssid + 160));
    if ( *(_BYTE *)(v13 + 160) == 1 )
      result = lim_send_ht40_obss_scanind(a1, v13);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: OBSS Scan not started: session id is NULL",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "lim_process_sme_obss_scan_ind");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
