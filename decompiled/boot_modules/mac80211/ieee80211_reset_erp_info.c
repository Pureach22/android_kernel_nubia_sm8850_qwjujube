__int64 __fastcall ieee80211_reset_erp_info(__int64 a1)
{
  *(_WORD *)(a1 + 4853) = 0;
  *(_BYTE *)(a1 + 4855) = 0;
  return 14;
}
