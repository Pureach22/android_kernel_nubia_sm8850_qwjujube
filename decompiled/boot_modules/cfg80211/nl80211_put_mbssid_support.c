__int64 __fastcall nl80211_put_mbssid_support(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x21
  unsigned __int64 v9; // x8
  _BYTE v10[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 1488) )
  {
    v4 = *(_QWORD *)(a2 + 216);
    v5 = *(unsigned int *)(a2 + 208);
    v6 = nla_put(a2, 33074, 0, 0);
    result = 4294967191LL;
    if ( (v6 & 0x80000000) == 0 )
    {
      v8 = (_WORD *)(v4 + v5);
      if ( v8 )
      {
        v10[0] = *(_BYTE *)(a1 + 1488);
        if ( (unsigned int)nla_put(a2, 1, 1, v10)
          || *(_BYTE *)(a1 + 1489) && (v11[0] = *(_BYTE *)(a1 + 1489), (unsigned int)nla_put(a2, 2, 1, v11)) )
        {
          v9 = *(_QWORD *)(a2 + 224);
          if ( v9 > (unsigned __int64)v8 )
          {
            __break(0x800u);
            v9 = *(_QWORD *)(a2 + 224);
          }
          skb_trim(a2, (unsigned int)((_DWORD)v8 - v9));
          result = 4294967191LL;
        }
        else
        {
          result = 0;
          *v8 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v8;
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
