__int64 __fastcall rrm_process_neighbor_report_req(
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
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  char v22; // w9
  int v23; // w8
  __int64 result; // x0
  const char *v25; // x2
  unsigned __int8 v26[4]; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v27[4]; // [xsp+10h] [xbp-30h] BYREF
  int v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  memset(v27, 0, sizeof(v27));
  v26[0] = 0;
  if ( !a2 )
  {
    v25 = "%s: NeighborReq is NULL";
LABEL_8:
    qdf_trace_msg(0x35u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "rrm_process_neighbor_report_req");
    result = 16;
    goto LABEL_9;
  }
  session_by_bssid = pe_find_session_by_bssid(a1, (unsigned __int8 *)(a2 + 4), v26);
  if ( !session_by_bssid )
  {
    v25 = "%s: session does not exist for given bssId";
    goto LABEL_8;
  }
  v13 = session_by_bssid;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: SSID present: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "rrm_process_neighbor_report_req",
    *(unsigned __int16 *)(a2 + 10));
  qdf_mem_set(v27, 0x24u, 0);
  v22 = *(_BYTE *)(a1 + 20226) + 1;
  *(_BYTE *)(a1 + 20226) = v22;
  v23 = *(unsigned __int16 *)(a2 + 10);
  LOBYTE(v27[0]) = v22;
  BYTE1(v27[0]) = v23 == 0;
  if ( !v23 )
  {
    qdf_mem_copy((char *)v27 + 2, (const void *)(a2 + 12), 0x22u);
    v14 = ((double (__fastcall *)(__int64, __int64, char *, _QWORD))qdf_trace_hex_dump)(
            53,
            8,
            (char *)v27 + 3,
            BYTE2(v27[0]));
  }
  result = lim_send_neighbor_report_request_frame(
             a1,
             (char *)v27,
             (unsigned __int8 *)(a2 + 4),
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
