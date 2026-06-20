__int64 __fastcall lim_process_assoc_failure_timeout(__int64 a1, int a2)
{
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 session_by_session_id; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x4
  __int64 result; // x0
  __int16 v44; // w2
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x9
  __int64 v56; // x1
  int v57; // w3
  __int16 v58; // w2
  __int64 v59; // [xsp+10h] [xbp-10h] BYREF
  __int64 v60; // [xsp+18h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v4 = 594;
  else
    v4 = 330;
  v5 = *(unsigned __int8 *)(a1 + v4);
  v59 = 0;
  session_by_session_id = pe_find_session_by_session_id(a1, v5);
  if ( session_by_session_id )
  {
    v15 = session_by_session_id;
    lim_diag_event_report(a1, 74, session_by_session_id, 0);
    v16 = _qdf_mem_malloc(0xDu, "lim_process_assoc_failure_timeout", 2095);
    if ( v16 )
    {
      v25 = v16;
      host_diag_log_set_code(v16, 4948);
      host_diag_log_set_length(v25, 13);
      *(_BYTE *)(v25 + 12) = *(_BYTE *)(v15 + 7264);
      host_diag_log_submit(v25);
      _qdf_mem_free(v25);
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Re/Association Response not received before timeout",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_process_assoc_failure_timeout");
    if ( a2
      || (mlme_get_reconn_after_assoc_timeout_flag(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v15 + 10)) & 1) == 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev: %d try sending deauth on channel freq %d to BSSID: %02x:%02x:%02x:**:**:%02x",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_process_assoc_failure_timeout",
        *(unsigned __int8 *)(v15 + 10),
        *(unsigned int *)(v15 + 284),
        *(unsigned __int8 *)(v15 + 24),
        *(unsigned __int8 *)(v15 + 25),
        *(unsigned __int8 *)(v15 + 26),
        *(unsigned __int8 *)(v15 + 29),
        v59,
        v60);
      lim_send_deauth_mgmt_frame(a1, 1, v15 + 24, v15, 0);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev: %d skip sending deauth on channel freq %d to BSSID: %02x:%02x:%02x:**:**:%02x",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_process_assoc_failure_timeout",
        *(unsigned __int8 *)(v15 + 10),
        *(unsigned int *)(v15 + 284),
        *(unsigned __int8 *)(v15 + 24),
        *(unsigned __int8 *)(v15 + 25),
        *(unsigned __int8 *)(v15 + 26),
        *(unsigned __int8 *)(v15 + 29),
        v59,
        v60);
    }
    v42 = *(unsigned int *)(v15 + 72);
    if ( *(_DWORD *)(v15 + 88) == 1 || (unsigned int)v42 > 0x1C || ((1 << v42) & 0x10000C00) == 0 )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: received unexpected REASSOC failure timeout in state %X for role %d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "lim_process_assoc_failure_timeout",
        v42);
      result = lim_print_mlm_state(a1, 3, *(unsigned int *)(v15 + 72));
    }
    else if ( !a2 || a2 == 1 && (_DWORD)v42 == 28 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: (Re)Assoc Failure Timeout occurred",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "lim_process_assoc_failure_timeout");
      v44 = *(_WORD *)(v15 + 8);
      *(_DWORD *)(v15 + 72) = 1;
      qdf_trace(53, 0, v44, 1);
      lim_deactivate_and_change_timer(a1, 5);
      lim_stop_pmfcomeback_timer(v15);
      v45 = *(_QWORD *)(v15 + 128);
      if ( v45 )
      {
        _qdf_mem_free(v45);
        *(_QWORD *)(v15 + 128) = 0;
      }
      if ( lim_search_pre_auth_list(a1, v15 + 24) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: delete pre auth node for %02x:%02x:%02x:**:**:%02x",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "lim_process_assoc_failure_timeout",
          *(unsigned __int8 *)(v15 + 24),
          *(unsigned __int8 *)(v15 + 25),
          *(unsigned __int8 *)(v15 + 26),
          *(unsigned __int8 *)(v15 + 29));
        lim_delete_pre_auth_node(a1, v15 + 24);
      }
      v54 = *(unsigned int *)(a1 + 21664);
      v55 = 0xFFFCFFFDFFFEFFFDLL >> (16 * (unsigned __int8)v54);
      BYTE6(v59) = *(_BYTE *)(v15 + 8);
      LODWORD(v59) = 510;
      if ( v54 >= 4 )
        LOWORD(v55) = 1;
      WORD2(v59) = v55;
      if ( a2 )
      {
        v56 = 1015;
        LODWORD(v59) = 536;
      }
      else
      {
        v56 = 1010;
      }
      result = lim_process_mlm_rsp_messages(a1, v56, &v59);
    }
    else
    {
      v57 = *(_DWORD *)(v15 + 76);
      v58 = *(_WORD *)(v15 + 8);
      *(_DWORD *)(v15 + 72) = v57;
      result = qdf_trace(53, 0, v58, v57);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Session Does not exist for given sessionID",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "lim_process_assoc_failure_timeout");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
