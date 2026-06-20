__int64 __fastcall dp_mon_vdev_timer_deinit(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 20056);
  if ( (*(_BYTE *)(v1 + 408) & 1) != 0 )
  {
    result = timer_delete_sync(v1 + 352);
    *(_BYTE *)(v1 + 408) = 0;
  }
  return result;
}
