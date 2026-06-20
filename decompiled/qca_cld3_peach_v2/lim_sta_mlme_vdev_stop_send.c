__int64 __fastcall lim_sta_mlme_vdev_stop_send(
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
  char is_connection_fail; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int assoc_type; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w20
  const char *v40; // x2

  if ( !a1 )
  {
    v40 = "%s: vdev_mlme is NULL";
LABEL_8:
    qdf_trace_msg(0x35u, 2u, v40, a2, a3, a4, a5, a6, a7, a8, a9, "lim_sta_mlme_vdev_stop_send");
    return 4;
  }
  if ( !a11 )
  {
    v40 = "%s: event_data is NULL";
    goto LABEL_8;
  }
  is_connection_fail = mlme_is_connection_fail(*(_QWORD *)(a1 + 520), a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Send vdev stop, connection_fail %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "lim_sta_mlme_vdev_stop_send",
    is_connection_fail & 1);
  if ( (is_connection_fail & 1) == 0 )
    return lim_sta_send_del_bss(a11);
  assoc_type = mlme_get_assoc_type(*(_QWORD *)(a1 + 520), v22, v23, v24, v25, v26, v27, v28, v29);
  if ( assoc_type - 1 >= 2 )
  {
    if ( assoc_type )
    {
      v39 = 4;
      qdf_trace_msg(
        0x35u,
        4u,
        "%s: Invalid assoc_type %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "lim_sta_mlme_vdev_stop_send",
        assoc_type);
    }
    else
    {
      v39 = lim_sta_handle_connect_fail(a11, v31, v32, v33, v34, v35, v36, v37, v38);
    }
  }
  else
  {
    v39 = 11;
  }
  mlme_set_connection_fail(*(_QWORD *)(a1 + 520), 0, v31, v32, v33, v34, v35, v36, v37, v38);
  return v39;
}
