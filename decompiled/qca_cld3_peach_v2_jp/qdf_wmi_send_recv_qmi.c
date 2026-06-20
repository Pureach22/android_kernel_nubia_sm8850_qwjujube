__int64 __fastcall qdf_wmi_send_recv_qmi(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 (*v8)(void); // x8

  v8 = (__int64 (*)(void))wmi_send_recv_qmi_cb;
  if ( wmi_send_recv_qmi_cb )
  {
    if ( *((_DWORD *)wmi_send_recv_qmi_cb - 1) != -322960547 )
      __break(0x8228u);
    return v8();
  }
  else
  {
    qdf_trace_msg(0x38u, 2u, "Platform callback for WMI over QMI not registered", a1, a2, a3, a4, a5, a6, a7, a8);
    return 4;
  }
}
