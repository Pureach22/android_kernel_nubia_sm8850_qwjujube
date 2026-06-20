__int64 __fastcall cds_free_context(
        int a1,
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
  __int64 v10; // x19
  __int64 v11; // x20
  __int64 v12; // x8
  const char *v13; // x2

  v10 = gp_cds_context;
  if ( !gp_cds_context )
  {
    v13 = "%s: cds context is null";
LABEL_13:
    qdf_trace_msg(0x38u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "cds_free_context");
    return 16;
  }
  if ( !a2 )
  {
    v13 = "%s: Null param";
    goto LABEL_13;
  }
  if ( a1 == 54 )
  {
    v11 = 24;
    v12 = *(_QWORD *)(gp_cds_context + 24);
    if ( v12 )
      goto LABEL_11;
    goto LABEL_16;
  }
  if ( a1 == 66 )
  {
    v11 = 48;
    v12 = *(_QWORD *)(gp_cds_context + 48);
    if ( v12 )
      goto LABEL_11;
LABEL_16:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %i context has not been allocated or freed already",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cds_free_context");
    return 16;
  }
  if ( a1 != 61 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %i does not have its context allocated by CDS",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cds_free_context");
    return 4;
  }
  v11 = 32;
  v12 = *(_QWORD *)(gp_cds_context + 32);
  if ( !v12 )
    goto LABEL_16;
LABEL_11:
  if ( v12 != a2 )
  {
    v13 = "%s: cds_mod_context != module_context";
    goto LABEL_13;
  }
  _qdf_mem_free(a2);
  *(_QWORD *)(v10 + v11) = 0;
  return 0;
}
