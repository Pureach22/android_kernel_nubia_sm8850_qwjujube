__int64 __fastcall sub_83EE0(double a1)
{
  __int64 v1; // x18

  *(double *)(v1 + 472) = a1;
  *(double *)(v1 + 480) = a1;
  return ieee80211_get_tkip_p1k_iv();
}
