__int64 __fastcall ieee80211_ie_build_vht_cap(__int64 a1, __int64 a2, int a3)
{
  *(_QWORD *)(a1 + 6) = 0;
  *(_WORD *)a1 = 3263;
  *(_DWORD *)(a1 + 2) = a3;
  *(_QWORD *)(a1 + 6) = *(_QWORD *)(a2 + 8);
  return a1 + 14;
}
