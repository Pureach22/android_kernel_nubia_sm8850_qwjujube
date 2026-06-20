__int64 __fastcall cds_set_sub_20_support(
        char a1,
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
    v9 = *(_QWORD *)(gp_cds_context + 152);
    if ( v9 )
    {
      *(_BYTE *)(v9 + 30) = a1 & 1;
      qdf_trace_msg(
        0x38u,
        8u,
        "%s: sub 20 MHz channel width support: %d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "cds_set_sub_20_support",
        a1 & 1);
      return 0;
    }
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
      "cds_set_sub_20_support");
  }
  return 28;
}
