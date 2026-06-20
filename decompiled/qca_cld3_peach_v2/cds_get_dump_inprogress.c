__int64 __fastcall cds_get_dump_inprogress(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8

  if ( gp_cds_context )
  {
    v9 = *(_QWORD *)(gp_cds_context + 56);
    if ( v9 )
      return 4 * (unsigned int)((unsigned int)pld_get_dump_inprogress(*(_QWORD *)(v9 + 40), a1) != 0);
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__cds_get_context",
      64,
      "cds_get_dump_inprogress");
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__cds_get_context",
      "cds_get_dump_inprogress");
  }
  return 4;
}
