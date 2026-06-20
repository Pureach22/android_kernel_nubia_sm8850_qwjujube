__int64 __fastcall nl80211_send_station(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 *a9)
{
  __int64 v13; // x0
  __int64 v14; // x20
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9
  __int64 result; // x0
  __int64 v18; // x22
  __int64 v19; // x23
  _WORD *v20; // x22
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x21
  __int64 v24; // x23
  _WORD *v25; // x23
  __int64 v26; // x25
  unsigned int v27; // w21
  __int64 v28; // x23
  __int64 v29; // x25
  _WORD *v30; // x23
  char v31; // w8
  __int64 v32; // x26
  __int64 v33; // x27
  __int64 v34; // x28
  _WORD *v35; // x27
  int v36; // w8
  __int64 v37; // x2
  __int64 v38; // x2
  _QWORD v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = genlmsg_put(a1, a3, a4, &nl80211_fam, a5, a2);
  if ( !v13 )
  {
    kfree(a9[25]);
    result = 0xFFFFFFFFLL;
    goto LABEL_11;
  }
  v14 = v13;
  LODWORD(v39[0]) = *(_DWORD *)(a7 + 224);
  if ( (unsigned int)nla_put(a1, 3, 4, v39) )
    goto LABEL_5;
  if ( (unsigned int)nla_put(a1, 6, 6, a8) )
    goto LABEL_5;
  LODWORD(v39[0]) = *((_DWORD *)a9 + 29);
  if ( (unsigned int)nla_put(a1, 46, 4, v39) )
    goto LABEL_5;
  v18 = *(_QWORD *)(a1 + 216);
  v19 = *(unsigned int *)(a1 + 208);
  if ( (nla_put(a1, 21, 0, 0) & 0x80000000) != 0 )
    goto LABEL_5;
  v20 = (_WORD *)(v18 + v19);
  if ( !v20 )
    goto LABEL_5;
  v21 = *a9;
  if ( (*a9 & 0x10000) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 2);
    if ( (unsigned int)nla_put(a1, 16, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 2) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 3);
    if ( (unsigned int)nla_put(a1, 1, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x40000000000LL) != 0 )
  {
    v39[0] = a9[2];
    if ( (unsigned int)nla_put_64bit(a1, 42, 8, v39, 33) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x800004) != 0 )
  {
    LODWORD(v39[0]) = a9[3];
    if ( (unsigned int)nla_put(a1, 2, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x1000008) != 0 )
  {
    LODWORD(v39[0]) = a9[4];
    if ( (unsigned int)nla_put(a1, 3, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x800000) != 0 )
  {
    v39[0] = a9[3];
    if ( (unsigned int)nla_put_64bit(a1, 23, 8, v39, 33) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x1000000) != 0 )
  {
    v39[0] = a9[4];
    if ( (unsigned int)nla_put_64bit(a1, 24, 8, v39, 33) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x10) != 0 )
  {
    LOWORD(v39[0]) = *((_WORD *)a9 + 20);
    if ( (unsigned int)nla_put(a1, 4, 2, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x20) != 0 )
  {
    LOWORD(v39[0]) = *((_WORD *)a9 + 21);
    if ( (unsigned int)nla_put(a1, 5, 2, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x40) != 0 )
  {
    LOBYTE(v39[0]) = *((_BYTE *)a9 + 44);
    if ( (unsigned int)nla_put(a1, 6, 1, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x100000000LL) != 0 )
  {
    v39[0] = a9[22];
    if ( (unsigned int)nla_put_64bit(a1, 32, 8, v39, 33) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x8000000000LL) != 0 )
  {
    v39[0] = a9[21];
    if ( (unsigned int)nla_put_64bit(a1, 39, 8, v39, 33) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (*(_BYTE *)(a6 + 1108) & 2) != 0 && (v21 & 0x10000000000LL) != 0 )
  {
    LOWORD(v39[0]) = *((_WORD *)a9 + 105);
    if ( (unsigned int)nla_put(a1, 40, 2, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( *(_DWORD *)(a6 + 1120) == 1 )
  {
    if ( (v21 & 0x80) != 0 )
    {
      LOBYTE(v39[0]) = *((_BYTE *)a9 + 45);
      if ( (unsigned int)nla_put(a1, 7, 1, v39) )
        goto LABEL_5;
      v21 = *a9;
    }
    if ( (v21 & 0x2000) != 0 )
    {
      LOBYTE(v39[0]) = *((_BYTE *)a9 + 46);
      if ( (unsigned int)nla_put(a1, 13, 1, v39) )
        goto LABEL_5;
      v21 = *a9;
    }
  }
  if ( (v21 & 0x2000000) != 0 )
  {
    if ( (nl80211_put_signal(a1, *((unsigned __int8 *)a9 + 47), a9 + 6, 25) & 1) == 0 )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x4000000) != 0 )
  {
    if ( (nl80211_put_signal(a1, *((unsigned __int8 *)a9 + 47), (char *)a9 + 52, 26) & 1) == 0 )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x100) != 0 )
  {
    if ( (nl80211_put_sta_rate(a1, (__int16 *)a9 + 28, 8u) & 1) == 0 )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x4000) != 0 )
  {
    if ( (nl80211_put_sta_rate(a1, (__int16 *)a9 + 35, 0xEu) & 1) == 0 )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x200) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 21);
    if ( (unsigned int)nla_put(a1, 9, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x400) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 22);
    if ( (unsigned int)nla_put(a1, 10, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x800) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 23);
    if ( (unsigned int)nla_put(a1, 11, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x1000) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 24);
    if ( (unsigned int)nla_put(a1, 12, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x8000000) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 41);
    if ( (unsigned int)nla_put(a1, 27, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x20000000000LL) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 55);
    if ( (unsigned int)nla_put(a1, 41, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x40000) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 34);
    if ( (unsigned int)nla_put(a1, 18, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x100000) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 38);
    if ( (unsigned int)nla_put(a1, 20, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x200000) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 39);
    if ( (unsigned int)nla_put(a1, 21, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x400000) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 40);
    if ( (unsigned int)nla_put(a1, 22, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x4000000000LL) != 0 )
  {
    LOBYTE(v39[0]) = *((_BYTE *)a9 + 193);
    if ( (unsigned int)nla_put(a1, 38, 1, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x80000000000LL) != 0 )
  {
    LOBYTE(v39[0]) = *((_BYTE *)a9 + 224);
    if ( (unsigned int)nla_put(a1, 43, 1, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x8000) != 0 )
  {
    v28 = *(_QWORD *)(a1 + 216);
    v29 = *(unsigned int *)(a1 + 208);
    if ( (nla_put(a1, 15, 0, 0) & 0x80000000) != 0 )
      goto LABEL_5;
    v30 = (_WORD *)(v28 + v29);
    if ( !v30 )
      goto LABEL_5;
    v31 = *((_BYTE *)a9 + 104);
    if ( (v31 & 1) != 0 )
    {
      if ( (unsigned int)nla_put(a1, 1, 0, 0) )
        goto LABEL_5;
      v31 = *((_BYTE *)a9 + 104);
    }
    if ( (v31 & 2) != 0 )
    {
      if ( (unsigned int)nla_put(a1, 2, 0, 0) )
        goto LABEL_5;
      v31 = *((_BYTE *)a9 + 104);
    }
    if ( (v31 & 4) != 0 && (unsigned int)nla_put(a1, 3, 0, 0) )
      goto LABEL_5;
    LOBYTE(v39[0]) = *((_BYTE *)a9 + 105);
    if ( (unsigned int)nla_put(a1, 4, 1, v39) )
      goto LABEL_5;
    LOWORD(v39[0]) = *((_WORD *)a9 + 53);
    if ( (unsigned int)nla_put(a1, 5, 2, v39) )
      goto LABEL_5;
    *v30 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v30;
    v21 = *a9;
    if ( (*a9 & 0x20000) != 0 )
      goto LABEL_111;
  }
  else if ( (v21 & 0x20000) != 0 )
  {
LABEL_111:
    if ( (unsigned int)nla_put(a1, 17, 8, (char *)a9 + 108) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x80000) != 0 )
  {
    v39[0] = a9[18];
    if ( (unsigned int)nla_put_64bit(a1, 19, 8, v39, 33) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x10000000) != 0 )
  {
    v39[0] = *((unsigned int *)a9 + 25);
    if ( (unsigned int)nla_put_64bit(a1, 28, 8, v39, 33) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x20000000) != 0 )
  {
    v39[0] = a9[23];
    if ( (unsigned int)nla_put_64bit(a1, 29, 8, v39, 33) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x40000000) != 0 )
  {
    LOBYTE(v39[0]) = *((_BYTE *)a9 + 192);
    if ( (unsigned int)nla_put(a1, 30, 1, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x1000000000LL) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 53);
    if ( (unsigned int)nla_put(a1, 36, 4, v39) )
      goto LABEL_5;
    v21 = *a9;
  }
  if ( (v21 & 0x2000000000LL) != 0 )
  {
    LODWORD(v39[0]) = *((_DWORD *)a9 + 54);
    if ( (unsigned int)nla_put(a1, 37, 4, v39) )
      goto LABEL_5;
  }
  if ( (*(_BYTE *)(a6 + 1107) & 8) != 0 )
  {
    v22 = *a9;
    if ( (*a9 & 0x400000000LL) != 0 )
    {
      LOBYTE(v39[0]) = *((_BYTE *)a9 + 208);
      if ( (unsigned int)nla_put(a1, 34, 1, v39) )
        goto LABEL_5;
      v22 = *a9;
    }
    if ( (v22 & 0x800000000LL) != 0 )
    {
      LOBYTE(v39[0]) = *((_BYTE *)a9 + 209);
      if ( (unsigned int)nla_put(a1, 35, 1, v39) )
        goto LABEL_5;
    }
  }
  if ( !a9[25] )
    goto LABEL_175;
  v23 = *(_QWORD *)(a1 + 216);
  v24 = *(unsigned int *)(a1 + 208);
  if ( (nla_put(a1, 31, 0, 0) & 0x80000000) == 0 )
  {
    v25 = (_WORD *)(v23 + v24);
    if ( v25 )
    {
      v26 = 0;
      v27 = 1;
      do
      {
        v32 = a9[25];
        if ( *(_DWORD *)(v32 + v26) )
        {
          v33 = *(_QWORD *)(a1 + 216);
          v34 = *(unsigned int *)(a1 + 208);
          if ( (nla_put(a1, v27, 0, 0) & 0x80000000) != 0 )
            goto LABEL_5;
          v35 = (_WORD *)(v33 + v34);
          if ( !v35 )
            goto LABEL_5;
          v36 = *(_DWORD *)(v32 + v26);
          if ( (v36 & 2) != 0 )
          {
            v39[0] = *(_QWORD *)(v32 + v26 + 8);
            if ( (unsigned int)nla_put_64bit(a1, 1, 8, v39, 5) )
              goto LABEL_5;
            v36 = *(_DWORD *)(v32 + v26);
          }
          if ( (v36 & 4) != 0 )
          {
            v39[0] = *(_QWORD *)(v32 + v26 + 16);
            if ( (unsigned int)nla_put_64bit(a1, 2, 8, v39, 5) )
              goto LABEL_5;
            v36 = *(_DWORD *)(v32 + v26);
          }
          if ( (v36 & 8) != 0 )
          {
            v39[0] = *(_QWORD *)(v32 + v26 + 24);
            if ( (unsigned int)nla_put_64bit(a1, 3, 8, v39, 5) )
              goto LABEL_5;
            v36 = *(_DWORD *)(v32 + v26);
          }
          if ( (v36 & 0x10) != 0 )
          {
            v39[0] = *(_QWORD *)(v32 + v26 + 32);
            if ( (unsigned int)nla_put_64bit(a1, 4, 8, v39, 5) )
              goto LABEL_5;
            v36 = *(_DWORD *)(v32 + v26);
          }
          if ( (v36 & 0x40) != 0 && (nl80211_put_txq_stats(a1, v32 + v26 + 40, 6) & 1) == 0 )
            goto LABEL_5;
          *v35 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v35;
        }
        v26 += 88;
        ++v27;
      }
      while ( v26 != 1496 );
      *v25 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v25;
LABEL_175:
      *v20 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v20;
      v37 = a9[16];
      if ( !v37 || !(unsigned int)nla_put(a1, 42, v37, a9[15]) )
      {
        v38 = a9[31];
        if ( !v38 || !(unsigned int)nla_put(a1, 78, v38, a9[30]) )
        {
          if ( *((_BYTE *)a9 + 225) != 1
            || (LOBYTE(v39[0]) = *((_BYTE *)a9 + 226), !(unsigned int)nla_put(a1, 313, 1, v39))
            && (!(*((_DWORD *)a9 + 57) | *((unsigned __int16 *)a9 + 116))
             || !(unsigned int)nla_put(a1, 314, 6, (char *)a9 + 228)) )
          {
            kfree(a9[25]);
            result = 0;
            *(_DWORD *)(v14 - 20) = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (v14 - 20);
            goto LABEL_11;
          }
        }
      }
    }
  }
LABEL_5:
  kfree(a9[25]);
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
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
