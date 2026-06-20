__int64 __fastcall lim_process_modify_add_ies(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w4
  __int64 result; // x0
  _BYTE v22[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  if ( a2 )
  {
    session_by_bssid = pe_find_session_by_bssid(a1, a2 + 8, v22);
    if ( session_by_bssid )
    {
      if ( *(_WORD *)(a2 + 20) && *(_BYTE *)(a2 + 18) && *(_QWORD *)(a2 + 24) )
      {
        v20 = *(_DWORD *)(a2 + 40);
        if ( (unsigned int)(v20 - 1) >= 2 )
        {
          if ( v20 == 3 )
          {
            if ( !*(_WORD *)(session_by_bssid + 7304) )
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: assoc resp add ie not present",
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                "lim_process_modify_add_ies");
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: unhandled buffer type %d",
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              "lim_process_modify_add_ies");
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid request pIEBuffer %pK ieBufferlength %d ieIDLen %d ieID %d. update Type %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "lim_process_modify_add_ies",
          *(_QWORD *)(a2 + 24),
          *(unsigned __int16 *)(a2 + 20),
          *(unsigned __int8 *)(a2 + 17),
          *(unsigned __int8 *)(a2 + 18),
          *(_DWORD *)(a2 + 40));
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session not found for given bssid%02x:%02x:%02x:**:**:%02x",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_process_modify_add_ies",
        *(unsigned __int8 *)(a2 + 8),
        *(unsigned __int8 *)(a2 + 9),
        *(unsigned __int8 *)(a2 + 10),
        *(unsigned __int8 *)(a2 + 13));
    }
    result = _qdf_mem_free(*(_QWORD *)(a2 + 24));
    *(_QWORD *)(a2 + 24) = 0;
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: msg_buf is NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_modify_add_ies");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
