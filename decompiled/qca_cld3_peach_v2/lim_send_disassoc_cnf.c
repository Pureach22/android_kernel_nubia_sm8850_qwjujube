__int64 __fastcall lim_send_disassoc_cnf(__int64 a1)
{
  __int64 v1; // x20
  __int64 session_by_session_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  __int64 v13; // x0
  __int16 *v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int16 v41; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v42; // [xsp+10h] [xbp-20h] BYREF
  __int64 v43; // [xsp+18h] [xbp-18h]
  __int64 v44; // [xsp+20h] [xbp-10h]
  __int64 v45; // [xsp+28h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 12392);
  if ( !v1 )
    goto LABEL_12;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  if ( (tx_timer_running(a1 + 2400) & 1) != 0 )
    lim_deactivate_and_change_timer(a1, 16);
  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(v1 + 12));
  if ( !session_by_session_id )
  {
    v31 = "%s: No session for given sessionId";
LABEL_10:
    qdf_trace_msg(0x35u, 2u, v31, v4, v5, v6, v7, v8, v9, v10, v11, "lim_send_disassoc_cnf");
    HIDWORD(v43) = 500;
    goto LABEL_11;
  }
  v12 = session_by_session_id;
  v13 = dph_lookup_hash_entry(
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          a1,
          (unsigned __int8 *)v1,
          &v41,
          session_by_session_id + 360);
  if ( !v13 )
  {
    v31 = "%s: StaDs Null";
    goto LABEL_10;
  }
  v14 = (__int16 *)v13;
  lim_mlo_notify_peer_disconn(v12, v13);
  if ( (unsigned int)lim_cleanup_rx_path(a1, v14, v12, 1, v15, v16, v17, v18, v19, v20, v21, v22) )
  {
    HIDWORD(v43) = 502;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: cleanup_rx_path error",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_send_disassoc_cnf");
LABEL_11:
    qdf_mem_copy(&v42, (const void *)v1, 6u);
    LODWORD(v44) = *(_DWORD *)(v1 + 8);
    BYTE4(v44) = *(_BYTE *)(v1 + 12);
    _qdf_mem_free(v1);
    *(_QWORD *)(a1 + 12392) = 0;
    lim_process_mlm_rsp_messages(a1, 1013, (unsigned __int8 *)&v42, v32, v33, v34, v35, v36, v37, v38, v39);
    goto LABEL_12;
  }
  if ( *(_DWORD *)(v12 + 88) == 2 && *(_WORD *)(v1 + 6) != 46 )
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: FT Preauth Session (%pK %d) Clean up",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_send_disassoc_cnf",
      v12,
      *(unsigned __int16 *)(v12 + 8));
  _qdf_mem_free(v1);
  *(_QWORD *)(a1 + 12392) = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return 0;
}
