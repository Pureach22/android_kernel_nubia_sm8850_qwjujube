__int64 __fastcall qpnp_tm_isr(__int64 a1, __int64 a2)
{
  thermal_zone_device_update(*(_QWORD *)(a2 + 16), 0);
  return 1;
}
