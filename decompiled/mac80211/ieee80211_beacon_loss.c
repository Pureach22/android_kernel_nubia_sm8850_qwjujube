__int64 __fastcall ieee80211_beacon_loss(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 - 3104);
  *(_BYTE *)(a1 - 2243) &= ~1u;
  return wiphy_work_queue(*(_QWORD *)(v1 + 72), a1 - 2312);
}
