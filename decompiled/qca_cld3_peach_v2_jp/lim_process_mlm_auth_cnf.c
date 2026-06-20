__int64 __fastcall lim_process_mlm_auth_cnf(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w5
  const char *v23; // x2
  int v24; // w8
  int v25; // w22
  __int64 v26; // x20
  __int64 v27; // x23
  __int16 v28; // w2
  __int16 v29; // w2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x1
  int v39; // w3
  __int16 v40; // w2
  __int64 v41; // x22
  _BYTE *v42; // x0
  _BYTE *v43; // x21

  if ( !a2 )
  {
    v23 = "%s: Buffer is Pointing to NULL";
    return qdf_trace_msg(0x35u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_mlm_auth_cnf");
  }
  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a2 + 18));
  if ( !session_by_session_id )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: SessionId:%d session doesn't exist",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "lim_process_mlm_auth_cnf",
             *(unsigned __int8 *)(a2 + 18));
  v21 = *(_DWORD *)(session_by_session_id + 80);
  if ( v21 != 11 && v21 != 4 || *(_DWORD *)(session_by_session_id + 88) == 1 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: SessionId:%d received MLM_AUTH_CNF in state %X",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "lim_process_mlm_auth_cnf",
             *(unsigned __int16 *)(session_by_session_id + 8));
  v24 = *(_DWORD *)(a2 + 12);
  if ( !v24 )
  {
    if ( v21 == 4 )
    {
      v26 = session_by_session_id;
      lim_deactivate_and_change_timer(a1, 5);
      return lim_send_mlm_assoc_req(a1, v26);
    }
    goto LABEL_25;
  }
  if ( v21 == 4 )
  {
    v25 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5439LL);
    if ( v25 != 9 )
      goto LABEL_20;
  }
  else
  {
    v25 = *(_DWORD *)(a1 + 11392);
    if ( v25 != 9 )
      goto LABEL_20;
  }
  if ( *(_DWORD *)(a2 + 8) == 1 && (v24 == 509 || *(_WORD *)(a2 + 16) == 13) )
  {
    v41 = session_by_session_id;
    v42 = (_BYTE *)_qdf_mem_malloc(0x10u, "lim_process_mlm_auth_cnf", 577);
    if ( v42 )
    {
      v43 = v42;
      if ( *(_DWORD *)(v41 + 80) == 4 )
      {
        *v42 = *(_BYTE *)(v41 + 24);
        v42[1] = *(_BYTE *)(v41 + 25);
        v42[2] = *(_BYTE *)(v41 + 26);
        v42[3] = *(_BYTE *)(v41 + 27);
        v42[4] = *(_BYTE *)(v41 + 28);
        v42[5] = *(_BYTE *)(v41 + 29);
      }
      else
      {
        qdf_mem_copy(v42, (const void *)(a1 + 11396), 6u);
      }
      *((_DWORD *)v43 + 2) = 0;
      v43[12] = *(_BYTE *)(a2 + 18);
      return lim_post_mlm_message(a1, 1006, v43);
    }
    v23 = "%s: mlmAuthReq :Memory alloc failed";
    return qdf_trace_msg(0x35u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_mlm_auth_cnf");
  }
LABEL_20:
  if ( v21 != 4 )
  {
LABEL_25:
    v39 = *(_DWORD *)(session_by_session_id + 84);
    v40 = *(_WORD *)(session_by_session_id + 8);
    *(_DWORD *)(session_by_session_id + 80) = v39;
    return qdf_trace(53, 1u, v40, v39);
  }
  v27 = session_by_session_id;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Auth Failure occurred",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "lim_process_mlm_auth_cnf");
  v28 = *(_WORD *)(v27 + 8);
  *(_DWORD *)(v27 + 80) = 7;
  qdf_trace(53, 1u, v28, 7);
  v29 = *(_WORD *)(v27 + 8);
  *(_DWORD *)(v27 + 72) = 1;
  qdf_trace(53, 0, v29, 1);
  v38 = *(unsigned int *)(a2 + 12);
  if ( v25 == 3 && (_DWORD)v38 != 518 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Send deauth for SAE auth failure",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "lim_process_mlm_auth_cnf");
    lim_send_deauth_mgmt_frame(a1, 39, a2, v27, 0);
    v38 = *(unsigned int *)(a2 + 12);
  }
  return lim_handle_sme_join_result(a1, v38, *(unsigned __int16 *)(a2 + 16), v27);
}
