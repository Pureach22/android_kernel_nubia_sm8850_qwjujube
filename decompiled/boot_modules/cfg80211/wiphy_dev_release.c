__int64 __fastcall wiphy_dev_release(__int64 a1)
{
  return cfg80211_dev_free((_QWORD *)(a1 - 1384));
}
