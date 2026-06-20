__int64 __fastcall qdf_get_hash(__int64 a1, unsigned __int8 a2, __int64 a3, unsigned int *a4)
{
  __int64 result; // x0
  _QWORD *v5; // x9
  __int64 v6; // x10
  unsigned int v7; // t1
  _QWORD v8[11]; // [xsp+8h] [xbp-58h] BYREF

  v8[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 <= 0xAu )
  {
    memset(v8, 0, 80);
    if ( a2 )
    {
      v5 = v8;
      v6 = a2;
      do
      {
        v7 = *a4++;
        --v6;
        *v5++ = v7;
      }
      while ( v6 );
    }
    result = qdf_get_keyed_hash(a1, 0, 0, a3, v8);
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: Invalid element count %d", "qdf_get_hmac_hash", a2);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
