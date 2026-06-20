__int64 __fastcall cds_alloc_context(
        unsigned int a1,
        __int64 *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  __int64 v12; // x21
  const char *v13; // x2
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v11 = gp_cds_context;
  if ( !gp_cds_context )
  {
    v13 = "%s: cds context is null";
LABEL_9:
    qdf_trace_msg(0x38u, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "cds_alloc_context");
    return 16;
  }
  if ( !a2 )
  {
    v13 = "%s: null param passed";
    goto LABEL_9;
  }
  switch ( a1 )
  {
    case '6':
      v12 = 24;
      break;
    case 'B':
      v12 = 48;
      break;
    case '=':
      v12 = 32;
      break;
    default:
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Module ID %i does not have its context allocated by CDS",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "cds_alloc_context",
        a1);
      return 4;
  }
  if ( *(_QWORD *)(gp_cds_context + v12) )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %i context has already been allocated",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "cds_alloc_context",
      a1);
    return 14;
  }
  else
  {
    v17 = _qdf_mem_malloc(a3, "cds_alloc_context", 1779);
    *a2 = v17;
    if ( v17 )
    {
      *(_QWORD *)(v11 + v12) = v17;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Failed to allocate Context for module ID %i",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "cds_alloc_context",
        a1);
      return 2;
    }
  }
}
