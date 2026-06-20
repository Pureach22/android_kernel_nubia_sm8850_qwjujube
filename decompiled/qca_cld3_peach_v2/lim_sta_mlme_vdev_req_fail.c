__int64 __fastcall lim_sta_mlme_vdev_req_fail(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  unsigned int assoc_type; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v22; // x2

  if ( !a1 )
  {
    v22 = "%s: vdev_mlme is NULL";
LABEL_7:
    qdf_trace_msg(0x35u, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "lim_sta_mlme_vdev_req_fail");
    return 4;
  }
  if ( !a11 )
  {
    v22 = "%s: event_data is NULL";
    goto LABEL_7;
  }
  assoc_type = mlme_get_assoc_type(*(_QWORD *)(a1 + 520), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( assoc_type - 1 < 2 )
    return 11;
  if ( !assoc_type )
    return lim_sta_handle_connect_fail(a11, v13, v14, v15, v16, v17, v18, v19, v20);
  qdf_trace_msg(
    0x35u,
    4u,
    "%s: Invalid assoc_type %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "lim_sta_mlme_vdev_req_fail",
    assoc_type);
  return 4;
}
