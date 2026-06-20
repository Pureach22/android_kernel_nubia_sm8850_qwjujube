__int64 __fastcall wma_data_tx_ack_comp_hdlr(__int64 *a1, __int64 a2, int a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  const char *v16; // x4
  __int64 v17; // x0
  __int64 v18; // x8
  _QWORD *v19; // x20
  __int64 v20; // x1
  __int64 v21; // x22

  result = _wma_validate_handle(a1, "wma_data_tx_ack_comp_hdlr");
  if ( !(_DWORD)result )
  {
    if ( a2 )
    {
      v15 = a1[53];
      if ( a1[55] != a2 )
      {
        if ( v15 )
          v16 = "not";
        else
          v16 = (const char *)&unk_98C763;
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: nbuf does not match but umac_data_ota_ack_cb is %s null",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "wma_data_tx_ack_comp_hdlr",
          v16);
        goto LABEL_8;
      }
      if ( !v15 )
      {
        v21 = jiffies;
        if ( wma_data_tx_ack_comp_hdlr___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: ota_ack cb not registered",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "wma_data_tx_ack_comp_hdlr");
          wma_data_tx_ack_comp_hdlr___last_ticks = v21;
        }
        goto LABEL_8;
      }
      v17 = _qdf_mem_malloc(0x48u, "wma_data_tx_ack_comp_hdlr", 1036);
      if ( !v17 )
      {
LABEL_8:
        _qdf_nbuf_unmap_single(a1[23], a2, 1);
        return _qdf_nbuf_free(a2);
      }
      a1[78] = v17;
      *(_QWORD *)v17 = a1;
      *(_WORD *)(v17 + 8) = 0;
      *(_DWORD *)(v17 + 12) = a3;
      *(_QWORD *)(v17 + 64) = a2;
      v18 = a1[23];
      v19 = (_QWORD *)v17;
      _qdf_nbuf_unmap_single(v18, a2, 1);
      v19[6] = wma_data_tx_ack_work_handler;
      v19[7] = v19;
      v19[2] = 0xFFFFFFFE00000LL;
      v19[3] = v19 + 3;
      v19[4] = v19 + 3;
      v20 = system_wq;
      v19[5] = _qdf_defer_func;
      return queue_work_on(32, v20, v19 + 2);
    }
    else
    {
      return qdf_trace_msg(
               0x36u,
               8u,
               "%s: netbuf is NULL",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "wma_data_tx_ack_comp_hdlr");
    }
  }
  return result;
}
