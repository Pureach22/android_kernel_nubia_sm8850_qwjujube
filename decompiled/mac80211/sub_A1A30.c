__int64 __fastcall sub_A1A30(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { STZG            X21, [X13,#-0xEC0]! }
  return ieee80211_xmit(a1, a2, a3);
}
