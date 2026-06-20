__int64 __fastcall scheduler_set_watchdog_timeout(__int64 a1)
{
  int v1; // w19
  __int64 result; // x0

  v1 = a1;
  result = scheduler_get_context(a1);
  if ( result )
    *(_DWORD *)(result + 712) = v1;
  return result;
}
