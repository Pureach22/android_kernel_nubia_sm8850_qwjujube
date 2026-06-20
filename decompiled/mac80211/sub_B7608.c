__int64 __fastcall sub_B7608(
        long double a1,
        long double a2,
        long double a3,
        double a4,
        double a5,
        double a6,
        double a7)
{
  unsigned __int64 v7; // d29

  return ieee80211_report_wowlan_wakeup(a1, a2, a3, COERCE_DOUBLE(vqsubd_u64(*(unsigned __int64 *)&a7, v7)));
}
