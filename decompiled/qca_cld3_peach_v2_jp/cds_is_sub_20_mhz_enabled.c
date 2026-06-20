bool __fastcall cds_is_sub_20_mhz_enabled(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x29
  __int64 v9; // x30
  __int64 v10; // x8

  if ( gp_cds_context )
  {
    v10 = *(_QWORD *)(gp_cds_context + 152);
    return v10 && *(_BYTE *)(v10 + 30) == 1 && *(_DWORD *)(v10 + 32) != 0;
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
      "cds_is_sub_20_mhz_enabled",
      v8,
      v9);
    return 0;
  }
}
