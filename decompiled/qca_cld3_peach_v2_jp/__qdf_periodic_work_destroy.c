__int64 __fastcall _qdf_periodic_work_destroy(__int64 a1)
{
  __int64 result; // x0

  *(_DWORD *)(a1 + 120) = 0;
  do
    result = cancel_delayed_work_sync(a1);
  while ( (result & 1) != 0 );
  return result;
}
