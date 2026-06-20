__int64 __fastcall ieee80211_ie_build_ht_cap(__int64 a1, __int64 a2, __int16 a3)
{
  __int64 v5; // x10

  *(_QWORD *)(a1 + 4) = 0;
  *(_WORD *)a1 = 6701;
  *(_QWORD *)(a1 + 12) = 0;
  *(_QWORD *)(a1 + 20) = 0;
  *(_WORD *)(a1 + 2) = a3;
  *(_BYTE *)(a1 + 4) = *(_BYTE *)(a2 + 3) | (4 * *(_BYTE *)(a2 + 4));
  v5 = *(_QWORD *)(a2 + 5);
  *(_QWORD *)(a1 + 13) = *(_QWORD *)(a2 + 13);
  *(_QWORD *)(a1 + 5) = v5;
  return a1 + 28;
}
