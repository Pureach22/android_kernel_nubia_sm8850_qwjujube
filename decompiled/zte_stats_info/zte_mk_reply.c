__int64 __fastcall zte_mk_reply(__int64 a1, unsigned int a2, int a3)
{
  __int64 v5; // x21
  __int64 v6; // x22
  int v7; // w8
  __int64 result; // x0
  _WORD *v9; // x21
  __int64 v10; // x0
  unsigned __int64 v11; // x8
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 216);
  v6 = *(unsigned int *)(a1 + 208);
  v12 = a3;
  v7 = ((__int64 (*)(void))nla_put)();
  result = 0;
  if ( (v7 & 0x80000000) == 0 )
  {
    v9 = (_WORD *)(v5 + v6);
    if ( v9 )
    {
      if ( (nla_put(a1, a2, 4, &v12) & 0x80000000) != 0 )
      {
        v11 = *(_QWORD *)(a1 + 224);
        if ( v11 <= (unsigned __int64)v9 )
          goto LABEL_9;
      }
      else
      {
        v10 = nla_reserve_64bit(a1, 3, 352, 6);
        if ( v10 )
        {
          result = v10 + 4;
          *v9 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v9;
          goto LABEL_10;
        }
        v11 = *(_QWORD *)(a1 + 224);
        if ( v11 <= (unsigned __int64)v9 )
        {
LABEL_9:
          skb_trim(a1, (unsigned int)((_DWORD)v9 - v11));
          result = 0;
          goto LABEL_10;
        }
      }
      __break(0x800u);
      v11 = *(_QWORD *)(a1 + 224);
      goto LABEL_9;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
