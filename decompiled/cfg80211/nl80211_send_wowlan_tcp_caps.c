__int64 __fastcall nl80211_send_wowlan_tcp_caps(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v4; // x20
  __int64 v5; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x20
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 1240) + 24LL);
  if ( v2 )
  {
    v4 = *(_QWORD *)(a2 + 216);
    v5 = *(unsigned int *)(a2 + 208);
    v6 = nla_put(a2, 14, 0, 0);
    result = 4294967191LL;
    if ( (v6 & 0x80000000) == 0 )
    {
      v8 = (_WORD *)(v4 + v5);
      if ( v8 )
      {
        v9 = *(_DWORD *)(v2 + 8);
        if ( (unsigned int)nla_put(a2, 6, 4, &v9)
          || (v9 = *(_DWORD *)(v2 + 8), (unsigned int)nla_put(a2, 6, 4, &v9))
          || *(_BYTE *)(v2 + 20) == 1 && (unsigned int)nla_put(a2, 7, 0, 0)
          || *(_QWORD *)v2 && (unsigned int)nla_put(a2, 8, 12, *(_QWORD *)v2)
          || (v9 = *(_DWORD *)(v2 + 12), (unsigned int)nla_put(a2, 9, 4, &v9))
          || (v9 = *(_DWORD *)(v2 + 16), result = nla_put(a2, 10, 4, &v9), (_DWORD)result) )
        {
          result = 4294967191LL;
        }
        else
        {
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
