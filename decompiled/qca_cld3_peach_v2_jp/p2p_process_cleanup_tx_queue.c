__int64 __fastcall p2p_process_cleanup_tx_queue(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x28
  unsigned int v10; // w19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x1
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _QWORD *v29; // x22
  int v30; // w23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _QWORD *v39; // x26
  int v40; // w27
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  _QWORD *v59; // [xsp+0h] [xbp-10h] BYREF
  __int64 v60; // [xsp+8h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59 = nullptr;
  if ( a1 && (v9 = *a1) != 0 )
  {
    v10 = *((_DWORD *)a1 + 2);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: clean up tx queue wait for roc, size:%d, vdev_id:%d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_process_cleanup_tx_queue",
      *(unsigned int *)(v9 + 48),
      v10);
    if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v9 + 32), &v59) )
    {
      do
      {
        v29 = v59;
        v30 = qdf_list_peek_next((_QWORD *)(v9 + 32), v59, &v59);
        if ( v10 == -1 || v10 == *((_DWORD *)v29 + 6) )
        {
          if ( (unsigned int)qdf_list_remove_node(v9 + 32, v29) )
          {
            qdf_trace_msg(
              0x4Eu,
              2u,
              "%s: remove %pK from roc_q fail",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "p2p_process_cleanup_tx_queue",
              v29);
          }
          else
          {
            p2p_send_tx_conf((__int64)v29, 0, v21, v22, v23, v24, v25, v26, v27, v28);
            _qdf_mem_free(v29[6]);
            _qdf_mem_free((__int64)v29);
          }
        }
      }
      while ( !v30 );
    }
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: clean up tx queue wait for ack, size:%d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "p2p_process_cleanup_tx_queue",
      *(unsigned int *)(v9 + 72),
      v59,
      v60);
    if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v9 + 56), &v59) )
    {
      do
      {
        v39 = v59;
        v40 = qdf_list_peek_next((_QWORD *)(v9 + 56), v59, &v59);
        if ( v10 == -1 || v10 == *((_DWORD *)v39 + 6) )
        {
          if ( (unsigned int)qdf_list_remove_node(v9 + 56, v39) )
          {
            qdf_trace_msg(
              0x4Eu,
              2u,
              "%s: remove %pK from roc_q fail",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "p2p_process_cleanup_tx_queue",
              v39);
          }
          else
          {
            qdf_trace_msg(
              0x4Eu,
              8u,
              "%s: tx context:%pK",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "p2p_disable_tx_timer",
              v39);
            v41 = qdf_mc_timer_stop((__int64)(v39 + 9));
            if ( v41 )
              qdf_trace_msg(
                0x4Eu,
                2u,
                "%s: Failed to stop tx timer, status:%d",
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                "p2p_disable_tx_timer",
                v41);
            v50 = qdf_mc_timer_destroy((__int64)(v39 + 9));
            if ( v50 )
              qdf_trace_msg(
                0x4Eu,
                2u,
                "%s: Failed to destroy tx timer, status:%d",
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                "p2p_disable_tx_timer",
                v50);
            p2p_send_tx_conf((__int64)v39, 0, v51, v52, v53, v54, v55, v56, v57, v58);
            _qdf_mem_free(v39[6]);
            _qdf_mem_free((__int64)v39);
          }
        }
      }
      while ( !v40 );
    }
    qdf_event_set(v9 + 136, v19);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: Invalid cleanup param",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_process_cleanup_tx_queue",
      v59,
      v60);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
