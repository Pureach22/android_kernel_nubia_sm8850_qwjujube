__int64 __fastcall wlan_dp_notify_ndp_channel_info(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0

  result = dp_get_context();
  if ( result )
  {
    result = *(_QWORD *)(result + 3000);
    if ( result )
      return wlan_dp_resource_mgr_notify_ndp_channel_info(result, a1, a2, a3);
  }
  return result;
}
