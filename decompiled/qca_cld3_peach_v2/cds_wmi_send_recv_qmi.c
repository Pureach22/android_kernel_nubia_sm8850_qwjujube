__int64 __fastcall cds_wmi_send_recv_qmi(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8

  if ( gp_cds_context )
  {
    v12 = *(_QWORD *)(gp_cds_context + 56);
    if ( v12 )
      return 4 * (unsigned int)((unsigned int)pld_qmi_send(*(_QWORD *)(v12 + 40), 0, a1, a2, a3, a4) != 0);
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "__cds_get_context",
      64,
      "cds_wmi_send_recv_qmi");
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "__cds_get_context",
      "cds_wmi_send_recv_qmi");
  }
  return 4;
}
