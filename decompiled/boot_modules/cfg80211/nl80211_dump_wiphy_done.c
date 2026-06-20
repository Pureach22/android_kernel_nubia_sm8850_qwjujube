__int64 __fastcall nl80211_dump_wiphy_done(__int64 a1)
{
  kfree(*(_QWORD *)(a1 + 80));
  return 0;
}
