__int64 __fastcall buffer_overflow_check(char *s, int a2, int a3)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( s && a2 < a3 )
  {
    if ( strlen(s) >= a3 )
      return 4294967274LL;
    else
      return 0;
  }
  return result;
}
