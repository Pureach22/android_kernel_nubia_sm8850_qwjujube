__int64 __fastcall coresight_find_csdev_by_fwnode(__int64 a1)
{
  __int64 device; // x0
  __int64 v2; // x19

  device = bus_find_device(&coresight_bustype, 0, a1, &device_match_fwnode);
  if ( !device )
    return 0;
  v2 = device - 56;
  put_device(device);
  return v2;
}
