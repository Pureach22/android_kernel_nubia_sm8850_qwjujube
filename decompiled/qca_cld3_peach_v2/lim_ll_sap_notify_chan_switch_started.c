__int64 __fastcall lim_ll_sap_notify_chan_switch_started(
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
  _QWORD *context; // x0
  _QWORD *v11; // x20
  __int64 session_by_vdev_id; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  context = _cds_get_context(53, (__int64)"lim_ll_sap_notify_chan_switch_started", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v11 = context;
    session_by_vdev_id = pe_find_session_by_vdev_id(context, *(unsigned __int8 *)(a1 + 168));
    if ( session_by_vdev_id )
    {
      lim_notify_channel_switch_started(v11, session_by_vdev_id);
      return 0;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session not found for vdev_id: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_ll_sap_notify_chan_switch_started",
      *(unsigned __int8 *)(a1 + 168));
  }
  return 16;
}
