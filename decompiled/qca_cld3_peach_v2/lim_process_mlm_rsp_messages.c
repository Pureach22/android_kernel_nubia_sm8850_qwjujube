__int64 __fastcall lim_process_mlm_rsp_messages(
        __int64 a1,
        int a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  const char *v15; // x2
  const char *v16; // x3
  __int64 session_by_session_id; // x0
  __int16 v18; // w2
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int16 v27; // w2
  _BYTE v28[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
  {
    v15 = "%s: Buffer is Pointing to NULL";
    v16 = "lim_process_mlm_rsp_messages";
    goto LABEL_9;
  }
  result = qdf_trace(53, 0xAu, 0, a2);
  if ( a2 <= 1012 )
  {
    if ( a2 <= 1006 )
    {
      if ( a2 == 1003 )
      {
        result = lim_process_mlm_start_cnf(a1, a3);
      }
      else if ( a2 == 1005 )
      {
        result = lim_process_mlm_join_cnf(a1, a3);
      }
    }
    else
    {
      switch ( a2 )
      {
        case 1007:
          result = lim_process_mlm_auth_cnf(a1, a3);
          break;
        case 1010:
          result = lim_process_mlm_assoc_cnf(a1, a3);
          break;
        case 1011:
          result = lim_process_mlm_assoc_ind(a1, a3);
          break;
      }
    }
  }
  else
  {
    if ( a2 <= 1018 )
    {
      if ( a2 == 1013 )
      {
        result = lim_process_mlm_disassoc_cnf(a1, a3);
        goto LABEL_10;
      }
      if ( a2 != 1014 )
      {
        if ( a2 == 1018 )
          result = lim_process_mlm_deauth_cnf(a1, a3);
        goto LABEL_10;
      }
      session_by_session_id = pe_find_session_by_session_id(a1, a3[12]);
      if ( session_by_session_id )
      {
        if ( *(_DWORD *)(session_by_session_id + 88) == 2 )
        {
          v18 = *(_WORD *)(session_by_session_id + 8);
          *(_DWORD *)(session_by_session_id + 80) = 12;
          result = qdf_trace(53, 1u, v18, 12);
        }
        else
        {
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: *** Peer staId=%d Disassociated ***",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "lim_process_mlm_disassoc_ind",
                     *((unsigned __int16 *)a3 + 5));
        }
        goto LABEL_10;
      }
      v15 = "%s: Session Does not exist for given sessionID";
      v16 = "lim_process_mlm_disassoc_ind";
LABEL_9:
      result = qdf_trace_msg(0x35u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, v16);
      goto LABEL_10;
    }
    switch ( a2 )
    {
      case 1019:
        v28[0] = 0;
        result = pe_find_session_by_bssid(a1, a3, v28);
        if ( result )
        {
          if ( *(_DWORD *)(result + 88) == 2 )
          {
            v27 = *(_WORD *)(result + 8);
            *(_DWORD *)(result + 80) = 13;
            result = qdf_trace(53, 1u, v27, 13);
          }
        }
        else
        {
          result = qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: session does not exist for Addr:%02x:%02x:%02x:**:**:%02x",
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     v24,
                     v25,
                     v26,
                     "lim_process_mlm_deauth_ind",
                     *a3,
                     a3[1],
                     a3[2],
                     a3[5]);
        }
        break;
      case 1024:
        result = lim_process_mlm_set_keys_cnf(a1, a3);
        break;
      case 1031:
        result = lim_process_mlm_purge_sta_ind(a1, a3);
        break;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
