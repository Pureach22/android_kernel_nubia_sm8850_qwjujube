__int64 __fastcall lim_start(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w20

  qdf_trace_msg(0x35u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "lim_start");
  if ( *(_DWORD *)(a1 + 4056) )
  {
    qdf_trace_msg(0x35u, 3u, "%s: Invalid SME state: %X", v10, v11, v12, v13, v14, v15, v16, v17, "lim_start");
    v26 = 16;
  }
  else
  {
    *(_DWORD *)(a1 + 4056) = 1;
    qdf_trace(53, 1u, 255, 1);
    if ( (unsigned int)lim_init_mlm(a1) )
    {
      qdf_trace_msg(0x35u, 2u, "%s: Init MLM failed", v18, v19, v20, v21, v22, v23, v24, v25, "lim_start");
      return 16;
    }
    v26 = 0;
  }
  *(_WORD *)(a1 + 12434) = wlan_scan_register_requester(
                             *(_QWORD *)(a1 + 21552),
                             "LIM",
                             (__int64)lim_process_rx_scan_handler,
                             a1,
                             v18,
                             v19,
                             v20,
                             v21,
                             v22,
                             v23,
                             v24,
                             v25);
  return v26;
}
