__int64 __fastcall hdd_prevent_suspend(unsigned int a1)
{
  return qdf_wake_lock_acquire((__int64)&wlan_wake_lock, a1);
}
