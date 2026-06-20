__int64 __fastcall lim_process_mlm_start_req(
        __int64 a1,
        char *a2,
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
  __int64 v13; // x1
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 result; // x0
  char v24; // w8
  int v25; // w8
  char v26; // w9
  __int64 v27; // [xsp+0h] [xbp-10h] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  if ( a2 )
  {
    session_by_session_id = pe_find_session_by_session_id(a1, (unsigned __int8)*a2);
    if ( session_by_session_id )
    {
      v22 = session_by_session_id;
      if ( *(_DWORD *)(session_by_session_id + 72) == 1 )
      {
        result = lim_mlm_add_bss(a1, v14, v15, v16, v17, v18, v19, v20, v21, v13, session_by_session_id);
        v24 = *a2;
        LODWORD(v27) = result;
        BYTE4(v27) = v24;
        if ( !(_DWORD)result )
          goto LABEL_11;
        goto LABEL_10;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: received unexpected MLM_START_REQ in state %X",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_process_mlm_start_req",
        v27,
        v28);
      lim_print_mlm_state(a1, 2, *(unsigned int *)(v22 + 72));
      v25 = 504;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session Does not exist for given sessionID",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_process_mlm_start_req",
        v27,
        v28);
      v25 = 506;
    }
    v26 = *a2;
    LODWORD(v27) = v25;
    BYTE4(v27) = v26;
LABEL_10:
    result = lim_send_start_bss_confirm(a1, &v27);
    goto LABEL_11;
  }
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
             "lim_process_mlm_start_req",
             v27,
             v28);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
