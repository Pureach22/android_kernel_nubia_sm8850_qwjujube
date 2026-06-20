__int64 os_if_qmi_handle_init()
{
  unsigned int v0; // w0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  unsigned int v10; // w19

  v0 = qmi_handle_init();
  if ( (v0 & 0x80000000) == 0 )
    return 0;
  v10 = v0;
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: QMI handle initialization failed %d",
    v1,
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    "os_if_qmi_handle_init",
    v0);
  return qdf_status_from_os_return(v10);
}
