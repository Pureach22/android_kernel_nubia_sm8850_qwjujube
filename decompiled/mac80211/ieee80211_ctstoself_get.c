__int64 __fastcall ieee80211_ctstoself_get(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 result; // x0
  __int16 v9; // w9

  *(_WORD *)a6 = 196;
  result = ieee80211_ctstoself_duration(a1, a2, a4, a5);
  *(_WORD *)(a6 + 2) = result;
  v9 = *(_WORD *)(a3 + 8);
  *(_DWORD *)(a6 + 4) = *(_DWORD *)(a3 + 4);
  *(_WORD *)(a6 + 8) = v9;
  return result;
}
