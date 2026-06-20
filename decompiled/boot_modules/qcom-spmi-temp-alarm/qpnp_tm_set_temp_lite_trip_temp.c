__int64 __fastcall qpnp_tm_set_temp_lite_trip_temp(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w20
  __int64 v5; // x21
  unsigned int v6; // w19

  v3 = *(_DWORD *)(a2 + 16);
  v5 = thermal_zone_device_priv();
  mutex_lock(v5 + 64);
  v6 = qpnp_tm_set_temp_lite_thresh(v5, v3, a3);
  mutex_unlock(v5 + 64);
  return v6;
}
