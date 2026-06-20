__int64 __fastcall wlan_scan_release_wake_lock(__int64 result, __int64 a2)
{
  if ( result && a2 )
  {
    result = ucfg_scan_wake_lock_in_user_scan(result);
    if ( (result & 1) != 0 )
      return qdf_wake_lock_release(a2, 3);
  }
  return result;
}
