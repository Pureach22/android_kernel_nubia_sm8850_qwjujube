__int64 __fastcall sme_set_listen_interval(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 session_by_vdev_id; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( session_by_vdev_id )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: Listen interval: %d vdev id: %d",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "sme_set_listen_interval",
             *(unsigned __int8 *)(session_by_vdev_id + 251),
             a2);
  else
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Session lookup fails for vdev %d",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "sme_set_listen_interval",
             a2);
}
