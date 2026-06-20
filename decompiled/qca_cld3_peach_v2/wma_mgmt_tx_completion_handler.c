__int64 __fastcall wma_mgmt_tx_completion_handler(
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
  if ( a1 && a2 )
  {
    wma_process_mgmt_tx_completion();
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid mgmt Tx completion event",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_mgmt_tx_completion_handler");
    return 4294967274LL;
  }
}
