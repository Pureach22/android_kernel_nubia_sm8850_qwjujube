__int64 __fastcall qpnp_tm_set_trip_temp(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x0
  __int64 v6; // x20
  unsigned int updated; // w19

  v5 = thermal_zone_device_priv();
  if ( *(_DWORD *)(a2 + 8) != 3 )
    return 0;
  v6 = v5;
  mutex_lock(v5 + 64);
  updated = qpnp_tm_update_critical_trip_temp(v6, a3);
  mutex_unlock(v6 + 64);
  return updated;
}
