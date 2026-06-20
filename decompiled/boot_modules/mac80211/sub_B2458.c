__int64 __fastcall sub_B2458(__int64 a1, __int64 a2)
{
  if ( !(_DWORD)a2 )
    JUMPOUT(0x9E73C);
  return ieee80211_recalc_dtim(a1, a2);
}
