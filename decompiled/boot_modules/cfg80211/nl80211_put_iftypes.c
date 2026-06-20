__int64 __fastcall nl80211_put_iftypes(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  __int64 v4; // x21
  __int64 v5; // x22
  int v7; // w8
  __int64 result; // x0
  _WORD *v9; // x21
  unsigned int v10; // w22
  unsigned int v11; // w20
  bool v12; // cc

  v4 = *(_QWORD *)(a1 + 216);
  v5 = *(unsigned int *)(a1 + 208);
  v7 = nla_put(a1, a2, 0, 0);
  result = 4294967191LL;
  if ( (v7 & 0x80000000) == 0 )
  {
    v9 = (_WORD *)(v4 + v5);
    if ( v9 )
    {
      v10 = a3;
      if ( a3 )
      {
        v11 = 0;
        while ( (v10 & 1) == 0 || !(unsigned int)nla_put(a1, v11, 0, 0) )
        {
          v12 = v10 > 1;
          ++v11;
          v10 >>= 1;
          if ( !v12 )
            goto LABEL_10;
        }
        return 4294967191LL;
      }
      else
      {
LABEL_10:
        *v9 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v9;
        return 0;
      }
    }
  }
  return result;
}
