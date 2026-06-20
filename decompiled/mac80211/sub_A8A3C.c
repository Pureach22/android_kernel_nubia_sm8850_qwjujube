__int64 __fastcall sub_A8A3C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x3

  _T1 = *(_QWORD *)(a4 + 108);
  v8 = a4 + 108;
  __asm { STGP            X25, X26, [X3,#0x6C]! }
  return ieee80211_ctstoself_get(a1, a2, a3, v8);
}
