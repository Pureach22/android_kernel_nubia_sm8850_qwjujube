__int64 __fastcall lim_ll_sap_continue_vdev_restart(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  context = _cds_get_context(53, (__int64)"lim_ll_sap_continue_vdev_restart", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    if ( pe_find_session_by_vdev_id(context, *(unsigned __int8 *)(a1 + 168)) )
    {
      lim_process_ap_ecsa_timeout();
      return 0;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session not found for vdev_id: %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "lim_ll_sap_continue_vdev_restart",
      *(unsigned __int8 *)(a1 + 168));
  }
  return 16;
}
