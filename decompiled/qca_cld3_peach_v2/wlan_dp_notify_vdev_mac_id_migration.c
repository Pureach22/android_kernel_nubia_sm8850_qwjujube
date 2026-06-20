__int64 __fastcall wlan_dp_notify_vdev_mac_id_migration(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0

  result = dp_get_context();
  if ( result )
  {
    result = *(_QWORD *)(result + 3000);
    if ( result )
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))wlan_dp_resource_mgr_notify_vdev_mac_id_migration)(
               result,
               a1,
               a2,
               a3);
  }
  return result;
}
