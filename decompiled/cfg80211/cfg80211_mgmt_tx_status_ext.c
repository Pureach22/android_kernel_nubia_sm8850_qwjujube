__int64 __fastcall cfg80211_mgmt_tx_status_ext(__int64 a1, __int64 a2, __int64 a3)
{
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))nl80211_frame_tx_status)(a1, a2, a3, 60);
}
