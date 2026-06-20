__int64 __fastcall tdls_set_mode_in_vdev(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int64 v27; // x10
  unsigned __int64 v34; // x10
  unsigned __int64 v37; // x10

  result = qdf_trace_msg(
             0,
             8u,
             "%s: set tdls mode: %d source:%d",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "tdls_set_mode_in_vdev",
             a3,
             a4);
  if ( a3 - 3 < 2 )
  {
    _X9 = (unsigned __int64 *)(a2 + 24 + 8LL * (a4 >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v27 = __ldxr(_X9);
    while ( __stxr(v27 & ~(1LL << a4), _X9) );
    if ( *(_QWORD *)(a2 + 24) )
    {
      return qdf_trace_msg(
               0,
               4u,
               "%s: Don't enable TDLS, source bitmap: %lu",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "tdls_set_mode_in_vdev");
    }
    else
    {
      result = tdls_implicit_enable(a1, v17, v18, v19, v20, v21, v22, v23, v24);
      *(_BYTE *)(a2 + 212) = 1;
    }
  }
  else
  {
    if ( !a3 )
    {
      _X9 = (unsigned __int64 *)(a2 + 24 + 8LL * (a4 >> 6));
      __asm { PRFM            #0x11, [X9] }
      do
        v37 = __ldxr(_X9);
      while ( __stxr(v37 | (1LL << a4), _X9) );
      goto LABEL_8;
    }
    if ( a3 == 2 )
    {
      _X9 = (unsigned __int64 *)(a2 + 24 + 8LL * (a4 >> 6));
      __asm { PRFM            #0x11, [X9] }
      do
        v34 = __ldxr(_X9);
      while ( __stxr(v34 & ~(1LL << a4), _X9) );
LABEL_8:
      result = tdls_implicit_disable(a1, v17, v18, v19, v20, v21, v22, v23, v24);
      *(_BYTE *)(a2 + 212) = 0;
    }
  }
  return result;
}
