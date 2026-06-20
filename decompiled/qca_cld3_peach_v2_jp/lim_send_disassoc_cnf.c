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
  __int16 *v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int16 v32; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v33; // [xsp+10h] [xbp-20h] BYREF
  __int64 v34; // [xsp+18h] [xbp-18h]
  __int64 v35; // [xsp+20h] [xbp-10h]
  __int64 v36; // [xsp+28h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 12392);
  if ( !v1 )
    goto LABEL_12;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  if ( (tx_timer_running(a1 + 2400) & 1) != 0 )
    lim_deactivate_and_change_timer(a1, 16);
  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(v1 + 12));
  if ( !session_by_session_id )
  {
    v22 = "%s: No session for given sessionId";
LABEL_10:
    qdf_trace_msg(0x35u, 2u, v22, v4, v5, v6, v7, v8, v9, v10, v11, "lim_send_disassoc_cnf");
    HIDWORD(v34) = 500;
    goto LABEL_11;
  }
  v12 = session_by_session_id;
  v13 = (__int16 *)dph_lookup_hash_entry(
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
                     &v32,
                     session_by_session_id + 360);
  if ( !v13 )
  {
    v22 = "%s: StaDs Null";
    goto LABEL_10;
  }
  if ( (unsigned int)lim_cleanup_rx_path(a1, v13, v12, 1, v4, v5, v6, v7, v8, v9, v10, v11) )
  {
    HIDWORD(v34) = 502;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: cleanup_rx_path error",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "lim_send_disassoc_cnf");
LABEL_11:
    qdf_mem_copy(&v33, (const void *)v1, 6u);
    LODWORD(v35) = *(_DWORD *)(v1 + 8);
    BYTE4(v35) = *(_BYTE *)(v1 + 12);
    _qdf_mem_free(v1);
    *(_QWORD *)(a1 + 12392) = 0;
    lim_process_mlm_rsp_messages(a1, 1013, (unsigned __int8 *)&v33, v23, v24, v25, v26, v27, v28, v29, v30);
    goto LABEL_12;
  }
  if ( *(_DWORD *)(v12 + 88) == 2 && *(_WORD *)(v1 + 6) != 46 )
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: FT Preauth Session (%pK %d) Clean up",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "lim_send_disassoc_cnf",
      v12,
      *(unsigned __int16 *)(v12 + 8));
  _qdf_mem_free(v1);
  *(_QWORD *)(a1 + 12392) = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return 0;
}
