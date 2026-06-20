__int64 __fastcall sme_get_link_speed(
        __int64 a1,
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
  _QWORD *context; // x0
  _QWORD *v17; // x21
  const char *v18; // x2
  unsigned int link_speed; // w20

  if ( !a2 || !a1 || !a4 )
  {
    v18 = "%s: Invalid parameter";
LABEL_8:
    qdf_trace_msg(0x34u, 2u, v18, a5, a6, a7, a8, a9, a10, a11, a12, "sme_get_link_speed");
    return 16;
  }
  context = _cds_get_context(54, (__int64)"sme_get_link_speed", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( context )
  {
    v17 = context;
    if ( !(unsigned int)qdf_mutex_acquire(a1 + 12848) )
    {
      *(_QWORD *)(a1 + 13112) = a3;
      *(_QWORD *)(a1 + 13104) = a4;
      link_speed = wma_get_link_speed(v17, a2);
      qdf_mutex_release(a1 + 12848);
      return link_speed;
    }
    v18 = "%s: Failed to acquire global lock";
    goto LABEL_8;
  }
  return 16;
}
