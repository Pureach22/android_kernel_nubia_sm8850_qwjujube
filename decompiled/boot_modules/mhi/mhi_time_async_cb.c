__int64 __fastcall mhi_time_async_cb(__int64 result, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8

  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 16) + 16LL) + 192LL);
  if ( v4 )
  {
    if ( *(_DWORD *)(v4 + 24) <= 1u )
      return ipc_log_string(
               *(_QWORD *)(v4 + 32),
               "[I][%s] Time response: seq:%x local: %llu remote: %llu (ticks)\n",
               "mhi_time_async_cb",
               a2,
               a3,
               a4);
  }
  return result;
}
