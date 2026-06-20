__int64 __fastcall hdd_mlo_t2lm_register_callback(__int64 result)
{
  if ( result )
  {
    if ( *(_QWORD *)(result + 1360) )
      return wlan_register_t2lm_link_update_notify_handler(hdd_mlo_dev_t2lm_notify_link_update);
  }
  return result;
}
