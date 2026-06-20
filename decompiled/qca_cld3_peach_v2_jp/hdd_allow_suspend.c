__int64 __fastcall hdd_allow_suspend(unsigned int a1)
{
  return qdf_wake_lock_release((__int64)&wlan_wake_lock, a1);
}
