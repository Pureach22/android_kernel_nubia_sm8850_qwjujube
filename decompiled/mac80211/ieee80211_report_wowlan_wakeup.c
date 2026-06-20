__int64 __fastcall ieee80211_report_wowlan_wakeup(__int64 a1)
{
  return cfg80211_report_wowlan_wakeup(a1 - 4704);
}
