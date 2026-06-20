__int64 *__fastcall cfg80211_mlme_down(__int64 *result, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w9
  __int16 v4; // w8
  int v5; // [xsp+0h] [xbp-10h] BYREF
  __int16 v6; // [xsp+4h] [xbp-Ch]
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(*result + 352) )
  {
    v2 = *(_QWORD *)(a2 + 992);
    if ( (*(_BYTE *)(v2 + 164) & 1) != 0 )
    {
      v3 = *(_DWORD *)(v2 + 280);
      v4 = *(_WORD *)(v2 + 284);
      v5 = v3;
      v6 = v4;
      result = (__int64 *)cfg80211_mlme_deauth(result, a2, &v5, 0, 0, 3, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
