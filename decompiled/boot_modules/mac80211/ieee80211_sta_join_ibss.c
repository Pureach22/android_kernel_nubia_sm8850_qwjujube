__int64 __fastcall ieee80211_sta_join_ibss(__int64 a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // x20
  __int64 v3; // x19
  __int64 v4; // x2
  unsigned int v5; // w22
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 v8; // x1
  __int64 v9; // x11
  int v10; // w9
  __int64 v11; // x8
  int v12; // w9
  __int64 v13; // x10
  unsigned int v14; // w21
  unsigned __int16 *v15; // x13
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x16
  __int64 lock; // x0
  __int64 v20; // x23
  __int64 result; // x0
  __int64 v22; // [xsp+8h] [xbp-28h] BYREF
  __int64 v23; // [xsp+10h] [xbp-20h]
  __int64 v24; // [xsp+18h] [xbp-18h]
  __int64 v25; // [xsp+20h] [xbp-10h]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v2 = a2;
  v3 = a1;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a1 + 2408);
  v5 = *(a2 - 14);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  if ( (int)v4 <= 2 )
  {
    if ( (unsigned int)v4 >= 2 )
    {
      if ( (_DWORD)v4 != 2 )
      {
LABEL_12:
        v8 = *((_QWORD *)a2 - 12);
        v4 = 0;
        goto LABEL_13;
      }
      if ( *(_DWORD *)(a1 + 2412) <= *(_DWORD *)(*(_QWORD *)(a1 + 2400) + 4LL) )
        v4 = 2;
      else
        v4 = 3;
    }
    v8 = *((_QWORD *)a2 - 12);
LABEL_13:
    a1 = cfg80211_chandef_create(&v22, v8, v4);
    goto LABEL_14;
  }
  if ( (unsigned int)(v4 - 3) >= 3 )
  {
    if ( (unsigned int)(v4 - 6) < 2 )
    {
      a1 = cfg80211_chandef_create(&v22, *((_QWORD *)a2 - 12), 0);
      LODWORD(v23) = *(_DWORD *)(v3 + 2408);
      goto LABEL_14;
    }
    goto LABEL_12;
  }
  v6 = *(_QWORD *)(a1 + 2424);
  v7 = *(_QWORD *)(a1 + 2408);
  v24 = *(_QWORD *)(a1 + 2416);
  v25 = v6;
  v22 = *((_QWORD *)a2 - 12);
  v23 = v7;
LABEL_14:
  v9 = **((unsigned int **)v2 - 12);
  if ( (unsigned int)v9 >= 6 )
    goto LABEL_32;
  v10 = *(_DWORD *)(v3 + 2408);
  v11 = *((_QWORD *)v2 + 6);
  if ( v10 == 6 )
    v12 = 32;
  else
    v12 = (v10 == 7) << 6;
  if ( !v11 )
  {
    v14 = 0;
    goto LABEL_29;
  }
  if ( (unsigned __int64)(v11 - 33) < 0xFFFFFFFFFFFFFFE0LL )
LABEL_32:
    __break(0x5512u);
  v13 = 0;
  v14 = 0;
  v15 = v2 + 5;
  v16 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 1616) + 72LL) + 8 * v9 + 328);
  v17 = *(unsigned int *)(v16 + 24);
  do
  {
    if ( (int)v17 >= 1 )
    {
      v18 = 0;
      a1 = *((_BYTE *)v15 + v13) & 0x7F;
      a2 = (unsigned __int16 *)(*(_QWORD *)(v16 + 8) + 4LL);
      while ( (v12 & ~*((_DWORD *)a2 - 1)) != 0
           || (858993460 * (unsigned __int64)((unsigned int)*a2 + 4)) >> 32 != (_DWORD)a1 )
      {
        ++v18;
        a2 += 6;
        if ( v17 == v18 )
          goto LABEL_21;
      }
      v14 |= (1LL << v18) & (*((char *)v15 + v13) >> 31);
    }
LABEL_21:
    ++v13;
  }
  while ( v13 != v11 );
LABEL_29:
  if ( v5 <= 0xA )
    v5 = 10;
  lock = _rcu_read_lock(a1, a2);
  v20 = **((_QWORD **)v2 - 11);
  _rcu_read_unlock(lock);
  result = _ieee80211_sta_join_ibss(v3, v2 - 12, v5, &v22, v14, *(v2 - 13), v20, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
