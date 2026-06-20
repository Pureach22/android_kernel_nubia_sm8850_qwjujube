__int64 __fastcall p2p_process_cleanup_roc_queue(
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
  __int64 v9; // x24
  unsigned int v10; // w19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x1
  __int64 result; // x0
  int v29; // w0
  _QWORD *v30; // x23
  int v31; // w25
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int8 v40; // w23
  _QWORD *v41; // x22
  int v42; // w0
  int v43; // w8
  int v44; // w25
  __int64 v45; // [xsp+8h] [xbp-38h]
  __int64 v46; // [xsp+10h] [xbp-30h]
  __int64 v47; // [xsp+18h] [xbp-28h]
  __int64 v48; // [xsp+20h] [xbp-20h]
  __int64 v49; // [xsp+28h] [xbp-18h]
  _QWORD *v50[2]; // [xsp+30h] [xbp-10h] BYREF

  v50[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v50[0] = nullptr;
  if ( a1 )
  {
    v9 = *a1;
    if ( *a1 )
    {
      v10 = *((_DWORD *)a1 + 2);
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: clean up idle roc request, roc queue size:%d, vdev id:%d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "p2p_process_cleanup_roc_queue",
        *(unsigned int *)(v9 + 24),
        v10);
      if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v9 + 8), v50) )
      {
        do
        {
          v30 = v50[0];
          LODWORD(v48) = *((_DWORD *)v50[0] + 13);
          LODWORD(v49) = *((_DWORD *)v50[0] + 56);
          LODWORD(v47) = *((_DWORD *)v50[0] + 12);
          LODWORD(v46) = *((unsigned __int8 *)v50[0] + 44);
          LODWORD(v45) = *((_DWORD *)v50[0] + 10);
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: p2p soc obj:%pK, roc ctx:%pK, vdev_id:%d, scan_id:%d, tx ctx:%pK, freq:%d, phy_mode:%d, duration:%d, roc"
            "_type:%d, roc_state:%d",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "p2p_process_cleanup_roc_queue",
            v50[0][2],
            v50[0],
            *((unsigned int *)v50[0] + 6),
            *((unsigned int *)v50[0] + 7),
            v50[0][4],
            v45,
            v46,
            v47,
            v48,
            v49);
          v29 = qdf_list_peek_next((_QWORD *)(v9 + 8), v50[0], v50);
          if ( !*((_DWORD *)v30 + 56) && (v10 == -1 || v10 == *((_DWORD *)v30 + 6)) )
          {
            v31 = v29;
            if ( (unsigned int)qdf_list_remove_node(v9 + 8, v30) )
              qdf_trace_msg(
                0x4Eu,
                2u,
                "%s: Failed to remove roc ctx from queue",
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                "p2p_process_cleanup_roc_queue");
            else
              _qdf_mem_free((__int64)v30);
            v29 = v31;
          }
        }
        while ( !v29 );
      }
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: clean up started roc request, roc queue size:%d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "p2p_process_cleanup_roc_queue",
        *(unsigned int *)(v9 + 24));
      if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v9 + 8), v50) )
      {
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: count %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "p2p_process_cleanup_roc_queue",
          0);
      }
      else
      {
        v40 = 0;
        do
        {
          v41 = v50[0];
          LODWORD(v48) = *((_DWORD *)v50[0] + 13);
          LODWORD(v49) = *((_DWORD *)v50[0] + 56);
          LODWORD(v47) = *((_DWORD *)v50[0] + 12);
          LODWORD(v46) = *((unsigned __int8 *)v50[0] + 44);
          LODWORD(v45) = *((_DWORD *)v50[0] + 10);
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: p2p soc obj:%pK, roc ctx:%pK, vdev_id:%d, scan_id:%d, tx ctx:%pK, freq:%d, phy_mode:%d, duration:%d, roc"
            "_type:%d, roc_state:%d",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "p2p_process_cleanup_roc_queue",
            v50[0][2],
            v50[0],
            *((unsigned int *)v50[0] + 6),
            *((unsigned int *)v50[0] + 7),
            v50[0][4],
            v45,
            v46,
            v47,
            v48,
            v49);
          v42 = qdf_list_peek_next((_QWORD *)(v9 + 8), v50[0], v50);
          v43 = *((_DWORD *)v41 + 56);
          if ( v43 && (v10 == -1 || v10 == *((_DWORD *)v41 + 6)) )
          {
            if ( v43 != 4 )
            {
              v44 = v42;
              p2p_execute_cancel_roc_req(v41);
              v42 = v44;
            }
            ++v40;
          }
        }
        while ( !v42 );
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: count %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "p2p_process_cleanup_roc_queue",
          v40);
        if ( v40 )
          goto LABEL_26;
      }
      qdf_event_set(v9 + 96, v27);
LABEL_26:
      result = 0;
      goto LABEL_27;
    }
  }
  qdf_trace_msg(0x4Eu, 2u, "%s: Invalid cleanup param", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_process_cleanup_roc_queue");
  result = 16;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
