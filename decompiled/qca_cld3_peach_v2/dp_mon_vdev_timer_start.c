__int64 __fastcall dp_mon_vdev_timer_start(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned int multiplier; // w0

  v1 = *(_QWORD *)(result + 20112);
  if ( (*(_BYTE *)(v1 + 408) & 1) != 0 )
  {
    v2 = jiffies;
    multiplier = qdf_timer_get_multiplier();
    result = mod_timer(v1 + 352, v2 + 2LL * multiplier);
    *(_BYTE *)(v1 + 408) |= 2u;
  }
  return result;
}
