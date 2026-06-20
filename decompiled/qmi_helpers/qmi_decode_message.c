__int64 __fastcall qmi_decode_message(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0

  if ( !a3 )
    return 4294967274LL;
  result = 4294967274LL;
  if ( a2 && a1 )
  {
    if ( a4 )
      return qmi_decode(a3, a4, a1 + 7, (unsigned int)(a2 - 7), 1);
  }
  return result;
}
