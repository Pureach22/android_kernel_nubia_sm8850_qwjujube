__int64 __fastcall qcom_glink_register_signals_cb(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      *(_QWORD *)(a1 + 448) = a2;
      return 0;
    }
  }
  return result;
}
