__int64 __fastcall wma_data_tx_ack_work_handler(
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
  _QWORD *v9; // x20
  const char *v11; // x2
  __int64 v12; // x0
  __int64 result; // x0
  _DWORD *v14; // x8
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2

  v9 = *(_QWORD **)a1;
  if ( *(_QWORD *)a1 && (cds_get_driver_state(a2, a3, a4, a5, a6, a7, a8, a9) & 6) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Data Tx Ack Cb Status %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_data_tx_ack_work_handler",
      *(unsigned int *)(a1 + 12));
    v14 = (_DWORD *)v9[53];
    if ( v14 )
    {
      v15 = v9[2];
      v16 = *(_QWORD *)(a1 + 64);
      v17 = *(unsigned int *)(a1 + 12);
      if ( *(v14 - 1) != -1755906178 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v14)(v15, v16, v17, 0);
      result = _qdf_mem_free(a1);
      goto LABEL_12;
    }
    v11 = "%s: Data Tx Ack Cb is NULL";
  }
  else
  {
    v11 = "%s: Driver load/unload in progress";
  }
  qdf_trace_msg(0x36u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wma_data_tx_ack_work_handler");
  v12 = *(_QWORD *)(a1 + 64);
  if ( v12 )
    _qdf_nbuf_free(v12);
  result = _qdf_mem_free(a1);
  if ( v9 )
  {
LABEL_12:
    v9[53] = 0;
    v9[55] = 0;
    v9[78] = 0;
  }
  return result;
}
