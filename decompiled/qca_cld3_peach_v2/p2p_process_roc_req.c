__int64 __fastcall p2p_process_roc_req(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  unsigned int inserted; // w0
  unsigned int v12; // w21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v9 = *(_QWORD *)(a1 + 16);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: p2p soc obj:%pK, roc ctx:%pK, vdev_id:%d, scan_id:%d, tx_ctx:%pK, freq:%d, phy_mode:%d, duration:%d, roc_type:%d, roc_state:%d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_process_roc_req",
    v9,
    a1,
    *(unsigned int *)(a1 + 24),
    *(unsigned int *)(a1 + 28),
    *(_QWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 40),
    *(unsigned __int8 *)(a1 + 44),
    *(_DWORD *)(a1 + 48),
    *(_DWORD *)(a1 + 52),
    *(_DWORD *)(a1 + 224));
  inserted = qdf_list_insert_back((_QWORD *)(v9 + 8), (_QWORD *)a1);
  if ( inserted )
  {
    v12 = inserted;
    p2p_destroy_roc_ctx(a1, 1, 0);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: Failed to insert roc req, status %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "p2p_process_roc_req",
      v12);
  }
  else
  {
    v12 = *(_DWORD *)(v9 + 24);
    if ( v12 )
    {
      if ( v12 == 1 )
      {
        return (unsigned int)p2p_execute_roc_req(a1);
      }
      else
      {
        p2p_find_current_roc_ctx(v9);
        return 0;
      }
    }
  }
  return v12;
}
