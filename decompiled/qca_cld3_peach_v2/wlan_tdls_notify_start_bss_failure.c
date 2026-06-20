__int64 __fastcall wlan_tdls_notify_start_bss_failure(__int64 a1)
{
  return tdls_notify_decrement_session(a1);
}
