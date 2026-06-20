__int64 __fastcall swr_driver_register(__int64 *a1)
{
  __int64 v1; // x8

  v1 = *a1;
  a1[10] = (__int64)&soundwire_type;
  if ( v1 )
    a1[16] = (__int64)swr_drv_probe;
  if ( a1[1] )
    a1[18] = (__int64)swr_drv_remove;
  if ( a1[2] )
    a1[19] = (__int64)swr_drv_shutdown;
  return driver_register(a1 + 9);
}
