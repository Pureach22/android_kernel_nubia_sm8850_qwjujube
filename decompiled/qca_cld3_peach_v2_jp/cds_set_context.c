__int64 __fastcall cds_set_context(
        unsigned int a1,
        __int64 a2,
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
  _QWORD *v13; // x8
  __int64 v15; // x21

  v13 = (_QWORD *)gp_cds_context;
  if ( gp_cds_context
    || (v15 = a2,
        printk(&unk_94D98D, "cds_get_global_context", a3, a4),
        v13 = (_QWORD *)gp_cds_context,
        a2 = v15,
        gp_cds_context) )
  {
    if ( a1 == 61 )
    {
      v13[4] = a2;
      return 0;
    }
    else if ( a1 == 51 )
    {
      *v13 = a2;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Module ID %i does not have its context managed by CDS",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "cds_set_context",
        a1);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(0x38u, 2u, "%s: cds context is Invalid", a5, a6, a7, a8, a9, a10, a11, a12, "cds_set_context");
    return 28;
  }
}
