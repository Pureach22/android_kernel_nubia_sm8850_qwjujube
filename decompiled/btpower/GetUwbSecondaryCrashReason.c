char *__fastcall GetUwbSecondaryCrashReason(int a1)
{
  char *result; // x0
  __int64 v3; // x10

  result = aDefault;
  v3 = 116;
  while ( *((_DWORD *)result - 1) != a1 )
  {
    --v3;
    result += 56;
    if ( !v3 )
      return "Crash reason not found";
  }
  return result;
}
