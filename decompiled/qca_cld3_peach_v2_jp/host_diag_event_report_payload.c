__int64 __fastcall host_diag_event_report_payload(
        __int16 a1,
        int a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  unsigned __int16 *v15; // x21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  result = cds_get_driver_state(a4, a5, a6, a7, a8, a9, a10, a11);
  if ( (result & 6) == 0 )
  {
    result = nl_srv_is_initialized();
    if ( !(_DWORD)result )
    {
      result = cds_is_multicast_logging();
      if ( (_BYTE)result )
      {
        result = _qdf_mem_malloc((unsigned __int16)(a2 + 12), "host_diag_event_report_payload", 211);
        if ( result )
        {
          *(_WORD *)result = 20560;
          v15 = (unsigned __int16 *)result;
          *(_WORD *)(result + 8) = a1;
          *(_DWORD *)(result + 4) = 2;
          *(_WORD *)(result + 2) = bswap32(a2 + 12) >> 16;
          *(_WORD *)(result + 10) = a2;
          memcpy((void *)(result + 12), a3, (unsigned __int16)a2);
          v24 = ptt_sock_send_msg_to_app(v15, 0, v16, v17, v18, v19, v20, v21, v22, v23, 17, 0xFFFFFFFF);
          if ( v24 < 0 && v24 != -3 )
            qdf_trace_msg(
              0x33u,
              3u,
              "Ptt Socket error sending message to the app!!",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32);
          return _qdf_mem_free((__int64)v15);
        }
      }
    }
  }
  return result;
}
