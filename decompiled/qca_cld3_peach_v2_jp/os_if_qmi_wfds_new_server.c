__int64 __fastcall os_if_qmi_wfds_new_server(
        __int64 *a1,
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
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  unsigned int v20; // w0

  v10 = os_if_qmi_connect_to_svc(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( v10 )
  {
    v19 = v10;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to connect to WFDS QMI service port",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "os_if_qmi_wfds_new_server");
    v20 = v19;
  }
  else
  {
    v20 = ucfg_dp_wfds_new_server();
  }
  return qdf_status_to_os_return(v20);
}
