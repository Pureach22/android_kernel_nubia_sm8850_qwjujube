__int64 __fastcall ieee80211_report_low_ack(__int64 a1)
{
  return cfg80211_cqm_pktloss_notify(*(_QWORD *)(*(_QWORD *)(a1 - 2608) + 1608LL), a1);
}
