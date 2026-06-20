__int64 __fastcall wma_register_tx_ops_handler(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
  {
    *a1 = wma_mgmt_unified_cmd_send;
    a1[3] = wma_mgmt_nbuf_unmap_cb;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: pointer to lmac if tx ops is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_register_tx_ops_handler",
      v9,
      v10);
    return 4;
  }
}
