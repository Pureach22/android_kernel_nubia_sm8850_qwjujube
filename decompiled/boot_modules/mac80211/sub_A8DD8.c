__int64 sub_A8DD8()
{
  __asm { STTR            Q10, [X26,#0xEC] }
  return ieee80211_unreserve_tid();
}
