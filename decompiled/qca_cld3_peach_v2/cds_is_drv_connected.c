bool __fastcall cds_is_drv_connected(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x8

  if ( gp_cds_context )
  {
    v8 = *(_QWORD *)(gp_cds_context + 56);
    if ( v8 )
      return (int)pld_is_drv_connected(*(_QWORD *)(v8 + 40)) > 0;
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "__cds_get_context",
      64,
      "cds_is_drv_connected");
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "__cds_get_context",
      "cds_is_drv_connected");
  }
  return 0;
}
