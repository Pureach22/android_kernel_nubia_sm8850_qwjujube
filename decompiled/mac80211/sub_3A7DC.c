__int64 __fastcall sub_3A7DC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // w10
  int v9; // w19

  *(_DWORD *)(a8 - 120) = v9;
  *(_DWORD *)(a8 - 116) = v8;
  return ieee80211_set_radar_background(a1, a2, a3, a4, a5, a6, a7, a8 - 120);
}
