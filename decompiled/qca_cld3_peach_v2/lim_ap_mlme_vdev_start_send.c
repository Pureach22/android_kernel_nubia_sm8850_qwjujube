__int64 __fastcall lim_ap_mlme_vdev_start_send(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned __int8 *a11)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 session_by_session_id; // x0
  const char *v23; // x2

  if ( !a11 )
  {
    v23 = "%s: data is NULL";
LABEL_7:
    qdf_trace_msg(0x35u, 2u, v23, a1, a2, a3, a4, a5, a6, a7, a8, "lim_ap_mlme_vdev_start_send");
    return 4;
  }
  context = _cds_get_context(53, (__int64)"lim_ap_mlme_vdev_start_send", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    session_by_session_id = pe_find_session_by_session_id(
                              (__int64)context,
                              *a11,
                              v13,
                              v14,
                              v15,
                              v16,
                              v17,
                              v18,
                              v19,
                              v20);
    if ( session_by_session_id )
    {
      lim_process_mlm_start_req(*(_QWORD *)(session_by_session_id + 8608), (char *)a11, a1, a2, a3, a4, a5, a6, a7, a8);
      return 0;
    }
    v23 = "%s: session is NULL";
    goto LABEL_7;
  }
  return 4;
}
