__int64 __fastcall sub_7B740(_QWORD *a1)
{
  __int64 v1; // x13
  __int64 v2; // x17

  *a1 = v2;
  a1[1] = v1;
  return ieee80211_sta_last_active(a1);
}
