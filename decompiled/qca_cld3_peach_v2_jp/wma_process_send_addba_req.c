__int64 __fastcall wma_process_send_addba_req(
        __int64 *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7

  if ( a1 )
  {
    v11 = *a1;
    if ( !(unsigned int)_wmi_validate_handle(
                          *a1,
                          (__int64)"wma_process_send_addba_req",
                          a3,
                          a4,
                          a5,
                          a6,
                          a7,
                          a8,
                          a9,
                          a10) )
    {
      if ( (unsigned int)wmi_unified_addba_send_cmd_send(v11) )
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to process WMA_SEND_ADDBA_REQ",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wma_process_send_addba_req");
      if ( a2 )
      {
        v20 = *a2;
        v21 = a2[1];
        v22 = a2[2];
        v23 = a2[5];
      }
      else
      {
        v22 = 0;
        v20 = 0;
        v21 = 0;
        v23 = 0;
      }
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: sent ADDBA req to%02x:%02x:%02x:**:**:%02xtid %d buff_size %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wma_process_send_addba_req",
        v20,
        v21,
        v22,
        v23,
        a2[7],
        *((unsigned __int16 *)a2 + 4));
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__wma_validate_handle",
      "wma_process_send_addba_req");
  }
  return _qdf_mem_free((__int64)a2);
}
