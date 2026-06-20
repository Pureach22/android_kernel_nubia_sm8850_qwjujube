__int64 __fastcall ieee80211_beacon_get_tim(unsigned __int64 a1, _DWORD *a2, _WORD *a3, _WORD *a4, unsigned int a5)
{
  __int64 result; // x0
  __int64 v9; // x20
  __int64 v10; // x1
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  __int16 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v11 = 0;
  result = _ieee80211_beacon_get(a1, a2, (__int64)&v11, 0, a5, -1, nullptr);
  if ( result )
  {
    if ( a3 )
      *a3 = v11;
    if ( a4 )
      *a4 = WORD1(v11);
    if ( (*(_QWORD *)(a1 + 96) & 0x80000000) == 0 )
    {
      if ( *(_DWORD *)(a1 + 1320) )
      {
        v9 = result;
        v10 = skb_copy(result, 2080);
        result = v9;
        if ( v10 )
        {
          ieee80211_tx_monitor(a1, v10, 1, 0, 0);
          result = v9;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
