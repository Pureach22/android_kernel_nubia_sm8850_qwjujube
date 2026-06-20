__int64 __fastcall sub_690C8(__int64 a1, __int64 a2)
{
  if ( !(_DWORD)a2 )
    JUMPOUT(0x553AC);
  return ieee80211_roc_purge(a1, a2);
}
