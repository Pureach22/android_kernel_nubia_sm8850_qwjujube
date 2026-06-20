__int64 __fastcall qdf_get_hmac_hash(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        __int64 a5,
        unsigned int *a6)
{
  __int64 result; // x0
  _QWORD *v7; // x10
  __int64 v8; // x9
  unsigned int v9; // t1
  _QWORD v10[11]; // [xsp+8h] [xbp-58h] BYREF

  v10[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 <= 0xAu )
  {
    memset(v10, 0, 80);
    if ( a4 )
    {
      v7 = v10;
      v8 = a4;
      do
      {
        v9 = *a6++;
        --v8;
        *v7++ = v9;
      }
      while ( v8 );
    }
    result = qdf_get_keyed_hash(a1, a2, a3, a5, v10);
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: Invalid element count %d", "qdf_get_hmac_hash", a4);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
