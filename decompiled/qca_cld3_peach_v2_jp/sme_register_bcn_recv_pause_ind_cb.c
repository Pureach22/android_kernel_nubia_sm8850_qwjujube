__int64 __fastcall sme_register_bcn_recv_pause_ind_cb(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  const char *v21; // x2

  if ( !a1 )
  {
    v21 = "%s: Invalid mac context";
    v20 = 2;
    goto LABEL_8;
  }
  if ( !a2 )
  {
    ucfg_scan_unregister_event_handler(
      *(_QWORD *)(a1 + 21560),
      (__int64)sme_scan_event_handler,
      a1,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10);
    return 0;
  }
  if ( !(unsigned int)qdf_mutex_acquire(a1 + 12776) )
  {
    *(_QWORD *)(a1 + 14544) = a2;
    qdf_mutex_release(a1 + 12776);
  }
  v20 = ucfg_scan_register_event_handler(
          *(_QWORD *)(a1 + 21560),
          (__int64)sme_scan_event_handler,
          a1,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19);
  if ( v20 )
  {
    v21 = "%s: scan event register failed ";
LABEL_8:
    qdf_trace_msg(0x34u, 2u, v21, a3, a4, a5, a6, a7, a8, a9, a10, "sme_register_bcn_recv_pause_ind_cb");
  }
  return v20;
}
