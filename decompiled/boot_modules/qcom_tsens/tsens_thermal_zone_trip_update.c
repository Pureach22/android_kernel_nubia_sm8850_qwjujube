__int64 __fastcall tsens_thermal_zone_trip_update(_DWORD *a1, __int64 a2)
{
  const char *v4; // x0
  const char *v5; // x21
  size_t v6; // x0
  int v7; // w8

  v4 = (const char *)thermal_zone_device_type(a2);
  if ( a1[2] != 3 )
  {
    v5 = v4;
    v6 = strlen(v4);
    if ( strnstr(v5, "cpu", v6) )
      v7 = 5000;
    else
      v7 = 10000;
    thermal_zone_set_trip_temp(a2, a1, (unsigned int)(v7 + *a1));
    thermal_zone_device_update(a2, 3);
  }
  return 0;
}
