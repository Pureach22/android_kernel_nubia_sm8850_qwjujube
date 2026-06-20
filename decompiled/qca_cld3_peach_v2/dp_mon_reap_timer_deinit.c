__int64 __fastcall dp_mon_reap_timer_deinit(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 20112);
  if ( *(_BYTE *)(v1 + 320) )
  {
    *(_BYTE *)(v1 + 320) = 0;
    return timer_delete_sync(v1 + 264);
  }
  return result;
}
