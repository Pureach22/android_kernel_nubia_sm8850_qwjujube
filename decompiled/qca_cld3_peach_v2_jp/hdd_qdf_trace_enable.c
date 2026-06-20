__int64 __fastcall hdd_qdf_trace_enable(unsigned int a1, unsigned int a2)
{
  unsigned int v3; // w19
  __int64 pidx; // x0
  unsigned int v6; // w21
  unsigned int i; // w22
  bool v8; // cc

  if ( a2 == 0xFFFF )
    return 0;
  v3 = a2;
  pidx = qdf_get_pidx();
  v6 = pidx;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))qdf_print_set_category_verbose)(
                       pidx,
                       a1,
                       0,
                       0) )
    return 4294967274LL;
  if ( v3 )
  {
    for ( i = 0;
          (v3 & 1) == 0
       || !(unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64))qdf_print_set_category_verbose)(
                           v6,
                           a1,
                           i,
                           1);
          ++i )
    {
      v8 = v3 > 1;
      v3 >>= 1;
      if ( !v8 )
        return 0;
    }
    return 4294967274LL;
  }
  return 0;
}
