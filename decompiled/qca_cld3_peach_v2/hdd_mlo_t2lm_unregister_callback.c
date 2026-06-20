__int64 __fastcall hdd_mlo_t2lm_unregister_callback(__int64 result)
{
  if ( result )
  {
    result = *(_QWORD *)(result + 1360);
    if ( result )
      return wlan_unregister_t2lm_link_update_notify_handler(result, 0);
  }
  return result;
}
