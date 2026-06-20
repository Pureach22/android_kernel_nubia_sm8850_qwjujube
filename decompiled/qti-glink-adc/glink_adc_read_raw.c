__int64 __fastcall glink_adc_read_raw(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x0
  __int64 v6; // x3
  __int64 result; // x0

  v5 = *(_QWORD *)(a1 + 1040);
  v6 = a3;
  if ( a5 )
  {
    if ( a5 != 1 )
      return 4294967274LL;
    v6 = 0;
  }
  else
  {
    a3 = 0;
  }
  LODWORD(result) = glink_adc_read_channel(v5, a2, a3, v6);
  if ( (int)result >= 0 )
    return 1;
  else
    return (unsigned int)result;
}
