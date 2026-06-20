__int64 __fastcall pdm_notify_unprepare(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 64);
  if ( result )
  {
    device_del();
    result = put_device(*(_QWORD *)(a1 + 64));
    *(_QWORD *)(a1 + 64) = 0;
  }
  return result;
}
