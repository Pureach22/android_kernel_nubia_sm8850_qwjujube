__int64 sub_6D2D8()
{
  __asm { STTR            Q10, [X26,#0xEC] }
  return ieee80211_sta_uapsd_trigger();
}
