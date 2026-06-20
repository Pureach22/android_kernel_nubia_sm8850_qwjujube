__int64 tsens_get_temp()
{
  __int64 (*v0)(void); // x8

  v0 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)thermal_zone_device_priv() + 2560LL) + 16LL);
  if ( *((_DWORD *)v0 - 1) != 484183290 )
    __break(0x8228u);
  return v0();
}
