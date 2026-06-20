__int64 __fastcall nl80211_send_mpath(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int *a8)
{
  __int64 v13; // x0
  __int64 v14; // x20
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9
  __int64 result; // x0
  __int64 v18; // x22
  __int64 v19; // x23
  _WORD *v20; // x22
  int v21; // w8
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = genlmsg_put(a1, a2, a3, &nl80211_fam, a4, 23);
  if ( !v13 )
  {
    result = 0xFFFFFFFFLL;
    goto LABEL_12;
  }
  v14 = v13;
  v22 = *(_DWORD *)(a5 + 224);
  if ( !(unsigned int)nla_put(a1, 3, 4, &v22)
    && !(unsigned int)nla_put(a1, 6, 6, a6)
    && !(unsigned int)nla_put(a1, 26, 6, a7) )
  {
    v22 = a8[8];
    if ( !(unsigned int)nla_put(a1, 46, 4, &v22) )
    {
      v18 = *(_QWORD *)(a1 + 216);
      v19 = *(unsigned int *)(a1 + 208);
      if ( (nla_put(a1, 27, 0, 0) & 0x80000000) == 0 )
      {
        v20 = (_WORD *)(v18 + v19);
        if ( v20 )
        {
          v21 = *a8;
          if ( (*a8 & 1) != 0 )
          {
            v22 = a8[1];
            if ( (unsigned int)nla_put(a1, 1, 4, &v22) )
              goto LABEL_6;
            v21 = *a8;
          }
          if ( (v21 & 2) != 0 )
          {
            v22 = a8[2];
            if ( (unsigned int)nla_put(a1, 2, 4, &v22) )
              goto LABEL_6;
            v21 = *a8;
          }
          if ( (v21 & 4) != 0 )
          {
            v22 = a8[3];
            if ( (unsigned int)nla_put(a1, 3, 4, &v22) )
              goto LABEL_6;
            v21 = *a8;
          }
          if ( (v21 & 8) != 0 )
          {
            v22 = a8[4];
            if ( (unsigned int)nla_put(a1, 4, 4, &v22) )
              goto LABEL_6;
            v21 = *a8;
          }
          if ( (v21 & 0x40) != 0 )
          {
            LOBYTE(v22) = *((_BYTE *)a8 + 25);
            if ( (unsigned int)nla_put(a1, 5, 1, &v22) )
              goto LABEL_6;
            v21 = *a8;
          }
          if ( (v21 & 0x10) != 0 )
          {
            v22 = a8[5];
            if ( (unsigned int)nla_put(a1, 6, 4, &v22) )
              goto LABEL_6;
            v21 = *a8;
          }
          if ( (v21 & 0x20) != 0 )
          {
            LOBYTE(v22) = *((_BYTE *)a8 + 24);
            if ( (unsigned int)nla_put(a1, 7, 1, &v22) )
              goto LABEL_6;
            v21 = *a8;
          }
          if ( (v21 & 0x80) == 0 )
          {
LABEL_39:
            if ( (v21 & 0x100) == 0 || (v22 = a8[7], !(unsigned int)nla_put(a1, 9, 4, &v22)) )
            {
              result = 0;
              *v20 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v20;
              *(_DWORD *)(v14 - 20) = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (v14 - 20);
              goto LABEL_12;
            }
            goto LABEL_6;
          }
          LOBYTE(v22) = *((_BYTE *)a8 + 26);
          if ( !(unsigned int)nla_put(a1, 8, 1, &v22) )
          {
            v21 = *a8;
            goto LABEL_39;
          }
        }
      }
    }
  }
LABEL_6:
  v15 = v14 - 20;
  if ( v14 != 20 )
  {
    v16 = *(_QWORD *)(a1 + 224);
    if ( v16 > v15 )
    {
      __break(0x800u);
      v16 = *(_QWORD *)(a1 + 224);
    }
    skb_trim(a1, (unsigned int)(v15 - v16));
  }
  result = 4294967206LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
