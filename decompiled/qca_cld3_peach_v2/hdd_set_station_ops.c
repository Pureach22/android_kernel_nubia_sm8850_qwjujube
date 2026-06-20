__int64 __fastcall hdd_set_station_ops(__int64 a1)
{
  __int64 result; // x0
  void *v3; // x8

  result = cds_get_conparam();
  v3 = &wlan_drv_ops;
  if ( (_DWORD)result == 4 )
    v3 = &wlan_mon_drv_ops;
  *(_QWORD *)(a1 + 8) = v3;
  return result;
}
