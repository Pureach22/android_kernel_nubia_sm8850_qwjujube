__int64 __fastcall cds_disable(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19

  if ( a1 )
  {
    v1 = a1;
    hdd_component_psoc_disable();
    a1 = dispatcher_psoc_disable(v1);
  }
  v2 = wma_stop(a1);
  v11 = v2;
  if ( (_DWORD)v2 )
    v2 = qdf_trace_msg(0x38u, 2u, "%s: Failed to stop wma", v3, v4, v5, v6, v7, v8, v9, v10, "cds_disable");
  if ( !gp_cds_context )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "__cds_get_context",
      "cds_disable");
    return 4;
  }
  if ( !*(_QWORD *)(gp_cds_context + 8) )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "__cds_get_context",
      53,
      "cds_disable");
    return 4;
  }
  umac_stop(v2);
  return v11;
}
