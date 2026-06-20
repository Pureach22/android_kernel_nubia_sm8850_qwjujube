__int64 __fastcall cds_qmi_indication(
        __int64 a1,
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
  __int64 v10; // x8

  if ( gp_cds_context )
  {
    v10 = *(_QWORD *)(gp_cds_context + 56);
    if ( v10 )
      return 4 * (unsigned int)((unsigned int)pld_qmi_indication(*(_QWORD *)(v10 + 40), a1, a2) != 0);
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__cds_get_context",
      64,
      "cds_qmi_indication");
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__cds_get_context",
      "cds_qmi_indication");
  }
  return 4;
}
