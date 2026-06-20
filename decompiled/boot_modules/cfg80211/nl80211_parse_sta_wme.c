__int64 __fastcall nl80211_parse_sta_wme(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  _WORD *v3; // x2
  __int64 result; // x0
  unsigned int v6; // w8
  unsigned int v7; // w8
  __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  __int64 v9; // [xsp+8h] [xbp-18h]
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 32);
  v9 = 0;
  v10 = 0;
  v8 = 0;
  v3 = *(_WORD **)(v2 + 1032);
  if ( v3 )
  {
    result = _nla_parse(&v8, 2, v3 + 2, (unsigned __int16)(*v3 - 4), &nl80211_sta_wme_policy, 0, *(_QWORD *)(a1 + 64));
    if ( !(_DWORD)result )
    {
      if ( v9 )
      {
        v6 = *(unsigned __int8 *)(v9 + 4);
        *(_BYTE *)(a2 + 32) = v6;
        if ( v6 > 0xF )
          goto LABEL_12;
      }
      else if ( *(unsigned __int8 *)(a2 + 32) > 0xFu )
      {
        goto LABEL_12;
      }
      if ( v10 )
      {
        v7 = *(unsigned __int8 *)(v10 + 4);
        *(_BYTE *)(a2 + 33) = v7;
        if ( v7 <= 3 )
        {
LABEL_10:
          result = 0;
          *(_DWORD *)(a2 + 16) |= 1u;
          goto LABEL_13;
        }
      }
      else if ( *(unsigned __int8 *)(a2 + 33) <= 3u )
      {
        goto LABEL_10;
      }
LABEL_12:
      result = 4294967274LL;
    }
  }
  else
  {
    result = 0;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
