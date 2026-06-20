__int64 __fastcall nl80211_put_tid_config_support(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x21
  unsigned __int64 v9; // x8
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a1 + 2440) || *(_QWORD *)(a1 + 2432) )
  {
    v4 = *(_QWORD *)(a2 + 216);
    v5 = *(unsigned int *)(a2 + 208);
    v6 = nla_put(a2, 33053, 0, 0);
    result = 4294967268LL;
    if ( (v6 & 0x80000000) == 0 )
    {
      v8 = (_WORD *)(v4 + v5);
      if ( v8 )
      {
        if ( *(_QWORD *)(a1 + 2440) && (v10[0] = *(_QWORD *)(a1 + 2440), (unsigned int)nla_put_64bit(a2, 2, 8, v10, 1))
          || *(_QWORD *)(a1 + 2432) && (v10[0] = *(_QWORD *)(a1 + 2432), (unsigned int)nla_put_64bit(a2, 3, 8, v10, 1))
          || (LOBYTE(v10[0]) = *(_BYTE *)(a1 + 2448), (unsigned int)nla_put(a2, 7, 1, v10))
          || (LOBYTE(v10[0]) = *(_BYTE *)(a1 + 2448), result = nla_put(a2, 8, 1, v10), (_DWORD)result) )
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
