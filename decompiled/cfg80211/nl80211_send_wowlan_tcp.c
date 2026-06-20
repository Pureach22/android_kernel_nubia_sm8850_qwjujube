__int64 __fastcall nl80211_send_wowlan_tcp(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x21
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v3 = *(_QWORD *)(a1 + 216);
    v4 = *(unsigned int *)(a1 + 208);
    v6 = nla_put(a1, 14, 0, 0);
    result = 4294967191LL;
    if ( (v6 & 0x80000000) == 0 )
    {
      v8 = (_WORD *)(v3 + v4);
      if ( v8 )
      {
        v9 = *(_DWORD *)(a2 + 8);
        if ( (unsigned int)nla_put(a1, 1, 4, &v9)
          || (v9 = *(_DWORD *)(a2 + 12), (unsigned int)nla_put(a1, 2, 4, &v9))
          || (unsigned int)nla_put(a1, 3, 6, a2 + 20)
          || (LOWORD(v9) = *(_WORD *)(a2 + 16), (unsigned int)nla_put(a1, 4, 2, &v9))
          || (LOWORD(v9) = *(_WORD *)(a2 + 18), (unsigned int)nla_put(a1, 5, 2, &v9))
          || (unsigned int)nla_put(a1, 6, *(unsigned int *)(a2 + 28), *(_QWORD *)(a2 + 32))
          || (v9 = *(_DWORD *)(a2 + 52), (unsigned int)nla_put(a1, 9, 4, &v9))
          || (unsigned int)nla_put(a1, 10, *(unsigned int *)(a2 + 56), *(_QWORD *)(a2 + 64))
          || (unsigned int)nla_put(a1, 11, (unsigned int)(*(_DWORD *)(a2 + 56) + 7) >> 3, *(_QWORD *)(a2 + 72))
          || *(_DWORD *)(a2 + 48) && (unsigned int)nla_put(a1, 7, 12, a2 + 40)
          || *(_DWORD *)(a2 + 88) && (unsigned int)nla_put(a1, 8, (unsigned int)(*(_DWORD *)(a2 + 80) + 8), a2 + 84) )
        {
          result = 4294967191LL;
        }
        else
        {
          result = 0;
          *v8 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v8;
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
