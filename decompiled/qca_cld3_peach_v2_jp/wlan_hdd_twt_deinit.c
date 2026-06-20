__int64 __fastcall wlan_hdd_twt_deinit(__int64 a1)
{
  flush_work(a1 + 7040);
  return cancel_work_sync(a1 + 7040);
}
