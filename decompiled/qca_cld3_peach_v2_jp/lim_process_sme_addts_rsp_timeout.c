__int64 __fastcall lim_process_sme_addts_rsp_timeout(__int64 a1, unsigned int a2)
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
  int v13; // w5
  __int64 v14; // x9
  __int64 v15; // x5
  __int64 v16; // x11
  __int16 v17; // w10
  __int64 v18; // x10
  __int64 v19; // x8
  __int64 v20; // x11
  __int64 result; // x0
  _QWORD v22[7]; // [xsp+8h] [xbp-48h] BYREF
  __int16 v23; // [xsp+40h] [xbp-10h]
  __int64 v24; // [xsp+48h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a1 + 1394));
  if ( session_by_session_id )
  {
    if ( *(_DWORD *)(session_by_session_id + 88) == 2 )
    {
      if ( *(_BYTE *)(a1 + 8876) )
      {
        v13 = *(unsigned __int8 *)(a1 + 8877);
        if ( v13 == a2 )
        {
          *(_BYTE *)(a1 + 8876) = 0;
          *(_BYTE *)(a1 + 8877) = v13 + 1;
          v14 = *(_QWORD *)(a1 + 8754);
          v15 = *(unsigned __int8 *)(session_by_session_id + 10);
          v16 = *(_QWORD *)(a1 + 8762);
          v22[4] = *(_QWORD *)(a1 + 8746);
          v22[5] = v14;
          v17 = *(_WORD *)(a1 + 8770);
          v22[6] = v16;
          v23 = v17;
          v18 = *(_QWORD *)(a1 + 8722);
          v20 = *(_QWORD *)(a1 + 8730);
          v19 = *(_QWORD *)(a1 + 8738);
          v22[0] = *(_QWORD *)(a1 + 8714);
          v22[1] = v18;
          v22[2] = v20;
          v22[3] = v19;
          result = lim_send_sme_addts_rsp(a1, 1, 525, session_by_session_id, v22, v15);
        }
        else
        {
          result = qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: Invalid AddtsRsp Timer count %d (exp %d)",
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     "lim_process_sme_addts_rsp_timeout",
                     a2);
        }
      }
      else
      {
        result = qdf_trace_msg(
                   0x35u,
                   3u,
                   "%s: AddtsRspTimeout but no AddtsSent",
                   v5,
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   "lim_process_sme_addts_rsp_timeout");
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x35u,
                 3u,
                 "%s: AddtsRspTimeout in non-Sta role (%d)",
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 "lim_process_sme_addts_rsp_timeout");
      *(_BYTE *)(a1 + 8876) = 0;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Session Does not exist for given sessionID",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "lim_process_sme_addts_rsp_timeout");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
