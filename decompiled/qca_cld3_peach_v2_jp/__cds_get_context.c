_QWORD *__fastcall _cds_get_context(
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
  _QWORD *v10; // x8
  const char *v11; // x2

  v10 = (_QWORD *)gp_cds_context;
  if ( !gp_cds_context )
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
      a2);
    return nullptr;
  }
  if ( a1 > 61 )
  {
    if ( a1 <= 64 )
    {
      if ( a1 == 62 )
      {
        v10 = *(_QWORD **)(gp_cds_context + 40);
        if ( !v10 )
          goto LABEL_31;
        return v10;
      }
      if ( a1 == 64 )
      {
        v10 = *(_QWORD **)(gp_cds_context + 56);
        if ( !v10 )
          goto LABEL_31;
        return v10;
      }
      goto LABEL_24;
    }
    if ( a1 != 65 )
    {
      if ( a1 == 66 )
      {
        v10 = *(_QWORD **)(gp_cds_context + 48);
        if ( !v10 )
          goto LABEL_31;
        return v10;
      }
      if ( a1 == 71 )
      {
        v10 = *(_QWORD **)(gp_cds_context + 64);
        if ( !v10 )
          goto LABEL_31;
        return v10;
      }
      goto LABEL_24;
    }
    v10 = (_QWORD *)(gp_cds_context + 72);
  }
  else
  {
    if ( a1 > 53 )
    {
      switch ( a1 )
      {
        case '6':
          v10 = *(_QWORD **)(gp_cds_context + 24);
          if ( v10 )
            return v10;
          goto LABEL_31;
        case '8':
          return v10;
        case '=':
          v10 = *(_QWORD **)(gp_cds_context + 32);
          if ( !v10 )
            goto LABEL_31;
          return v10;
      }
      goto LABEL_24;
    }
    if ( (unsigned int)(a1 - 52) < 2 )
    {
      v10 = *(_QWORD **)(gp_cds_context + 8);
      if ( !v10 )
        goto LABEL_31;
      return v10;
    }
    if ( a1 != 51 )
    {
LABEL_24:
      v11 = "%s: Module ID %d does not have its context maintained by CDS (via %s)";
LABEL_32:
      qdf_trace_msg(0x38u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "__cds_get_context");
      return nullptr;
    }
  }
  v10 = (_QWORD *)*v10;
  if ( !v10 )
  {
LABEL_31:
    v11 = "%s: Module ID %d context is Null (via %s)";
    goto LABEL_32;
  }
  return v10;
}
