__int64 os_if_qmi_wfds_init()
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
  unsigned int v9; // w19
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v0 = os_if_qmi_handle_init();
  if ( v0 )
  {
    v9 = v0;
    qdf_trace_msg(0x48u, 2u, "%s: WFDS QMI handle init failed", v1, v2, v3, v4, v5, v6, v7, v8, "os_if_qmi_wfds_init");
  }
  else
  {
    result = os_if_qmi_add_lookup();
    if ( !(_DWORD)result )
      return result;
    v9 = result;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: WFDS QMI add lookup failed",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "os_if_qmi_wfds_init");
    os_if_qmi_handle_release();
  }
  return v9;
}
