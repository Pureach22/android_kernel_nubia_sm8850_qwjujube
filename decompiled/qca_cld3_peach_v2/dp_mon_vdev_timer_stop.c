__int64 __fastcall dp_mon_vdev_timer_stop(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v2; // w19

  v1 = *(_QWORD *)(a1 + 20112);
  v2 = *(unsigned __int8 *)(v1 + 408);
  if ( (v2 & 2) != 0 )
  {
    timer_delete_sync(v1 + 352);
    *(_BYTE *)(v1 + 408) &= ~2u;
  }
  return (v2 >> 1) & 1;
}
