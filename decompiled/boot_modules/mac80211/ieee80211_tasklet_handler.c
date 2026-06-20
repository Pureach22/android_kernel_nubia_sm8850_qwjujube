__int64 __fastcall ieee80211_tasklet_handler(__int64 a1)
{
  return ieee80211_handle_queued_frames(a1 - 1512);
}
