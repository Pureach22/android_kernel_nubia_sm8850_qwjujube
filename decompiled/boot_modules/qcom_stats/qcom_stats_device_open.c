__int64 __fastcall qcom_stats_device_open(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x8

  if ( !a1 )
    return 4294967274LL;
  result = 4294967274LL;
  if ( a2 )
  {
    v4 = *(_QWORD *)(a1 + 656);
    if ( v4 )
    {
      result = 0;
      *(_QWORD *)(a2 + 32) = v4 - 56;
    }
  }
  return result;
}
