__int64 __fastcall dp_mon_vdev_timer_init(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 20056);
  *(_QWORD *)(v1 + 392) = dp_mon_vdev_timer;
  *(_QWORD *)(v1 + 400) = a1;
  result = init_timer_key(v1 + 352, _os_timer_shim_15, 0, 0, 0);
  *(_BYTE *)(v1 + 408) |= 1u;
  return result;
}
