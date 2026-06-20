bool __fastcall ieee80211_ht_cap_ie_to_sta_ht_cap(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x22
  int v7; // w10
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x11
  __int64 v11; // x21
  unsigned int v12; // w11
  int v13; // w9
  char v14; // w10
  int v15; // w11
  unsigned int v16; // w23
  char v17; // w9
  int v18; // w9
  unsigned __int8 v19; // w10
  char v20; // w8
  __int64 v21; // x8
  __int64 v22; // x11
  __int64 v23; // x12
  __int64 v24; // x14
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x13
  __int64 v28; // x24
  _BOOL4 v29; // w21
  __int64 lock; // x0
  unsigned __int64 v31; // x8
  __int64 v32; // x8
  unsigned int v33; // w8
  int v34; // w8
  int v35; // w25
  __int64 v36; // x9
  int v37; // w8
  int v38; // w10
  char v41; // w15
  char v42; // w11
  char v43; // w11
  char v44; // w14
  __int64 v45; // x9
  __int16 v46; // w10
  __int64 v47; // [xsp+8h] [xbp-38h] BYREF
  _BYTE v48[14]; // [xsp+10h] [xbp-30h]
  __int64 v49; // [xsp+20h] [xbp-20h]
  _QWORD v50[3]; // [xsp+28h] [xbp-18h] BYREF

  v5 = a1;
  v50[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a4 + 32);
  v49 = 0;
  memset(v50, 0, 14);
  if ( a3 && *(_BYTE *)(a2 + 30) == 1 )
  {
    v7 = *(_DWORD *)(a1 + 4720);
    v8 = *(_QWORD *)(a2 + 28);
    BYTE2(v49) = 1;
    v9 = *(_QWORD *)(a2 + 36);
    v10 = *(_QWORD *)(a2 + 42);
    v47 = v8;
    *(_QWORD *)v48 = v9;
    *(_QWORD *)&v48[6] = v10;
    if ( (unsigned int)(v7 - 1) <= 1 )
    {
      v11 = a3;
      a1 = ieee80211_apply_htcap_overrides(a1, (__int64)&v47);
      a3 = v11;
    }
    v12 = *(unsigned __int8 *)(a3 + 2);
    v13 = ((unsigned __int16)v47 | 0xEF8C) & *(_WORD *)a3;
    v14 = v12 & 3;
    v15 = (v12 >> 2) & 7;
    BYTE3(v49) = v14;
    if ( (v47 & 0x80) == 0 )
      v13 &= 0xFFFFFCFF;
    BYTE4(v49) = v15;
    if ( (v47 & 0x300) != 0 )
      v16 = v13;
    else
      v16 = v13 & 0xFFFFFF7F;
    v17 = *(_BYTE *)(a3 + 15);
    LOWORD(v49) = v16;
    BYTE1(v50[1]) = v17;
    if ( (v48[9] & 1) == 0 )
      goto LABEL_22;
    if ( (v48[9] & 2) != 0 )
      v18 = ((v48[9] >> 2) & 3) + 1;
    else
      v18 = 4;
    BYTE5(v49) = *(_BYTE *)(a3 + 3) & BYTE5(v47);
    if ( v18 != 1 )
    {
      BYTE6(v49) = *(_BYTE *)(a3 + 4) & BYTE6(v47);
      if ( v18 != 2 )
      {
        HIBYTE(v49) = *(_BYTE *)(a3 + 5) & HIBYTE(v47);
        if ( v18 != 3 )
          LOBYTE(v50[0]) = *(_BYTE *)(a3 + 6) & v48[0];
      }
    }
    v19 = *(_BYTE *)(a3 + 7);
    if ( (v48[9] & 0x10) != 0 )
    {
      v41 = *(_BYTE *)(a3 + 10);
      v42 = *(_BYTE *)(a3 + 9) & v48[3];
      BYTE2(v50[0]) = *(_BYTE *)(a3 + 8) & v48[2];
      BYTE3(v50[0]) = v42;
      v43 = *(_BYTE *)(a3 + 11);
      BYTE4(v50[0]) = v41 & v48[4];
      v44 = *(_BYTE *)(a3 + 12);
      BYTE1(v50[0]) = v19 & v48[1];
      BYTE5(v50[0]) = v43 & v48[5];
      v20 = v19 & v48[1] | 1;
      BYTE6(v50[0]) = v44 & v48[6];
      if ( (v48[1] & v19 & 1) == 0 )
      {
LABEL_41:
        v45 = *(_QWORD *)(a4 + 920);
        if ( (v16 & 0x800) != 0 )
          v46 = 7935;
        else
          v46 = 3839;
        *(_WORD *)((char *)v50 + 7) = *(_WORD *)(a3 + 13);
        *(_WORD *)(v45 + 194) = v46;
        a1 = ieee80211_sta_recalc_aggregates(v6 + 2688);
        goto LABEL_22;
      }
    }
    else
    {
      v20 = 1;
      if ( (v48[1] & *(_BYTE *)(a3 + 7) & 1) == 0 )
        goto LABEL_41;
    }
    BYTE1(v50[0]) = v20;
    goto LABEL_41;
  }
  v16 = 0;
LABEL_22:
  v21 = *(_QWORD *)(a4 + 920);
  v22 = v49;
  v23 = v50[0];
  v24 = *(_QWORD *)((char *)v50 + 6);
  v25 = *(_QWORD *)(v21 + 44);
  v26 = *(_QWORD *)(v21 + 52);
  v27 = *(_QWORD *)(v21 + 58);
  *(_QWORD *)(v21 + 44) = v49;
  *(_QWORD *)(v21 + 52) = v23;
  v28 = v25 ^ v22 | v26 ^ v23 | v27 ^ v24;
  *(_QWORD *)(v21 + 58) = v24;
  v29 = v28 != 0;
  lock = _rcu_read_lock(a1, a2);
  v31 = *(unsigned __int8 *)(a4 + 6);
  if ( v31 > 0xF )
    __break(0x5512u);
  v32 = *(_QWORD *)(v5 + 8 * v31 + 5680);
  if ( !v32 )
    goto LABEL_29;
  v33 = *(_DWORD *)(v32 + 144);
  if ( v33 > 0xD )
    goto LABEL_29;
  v34 = 1 << v33;
  if ( (v34 & 0x203C) != 0 )
  {
    v35 = (v16 >> 1) & 1;
    goto LABEL_30;
  }
  if ( (v34 & 3) != 0 )
  {
    v35 = 0;
  }
  else
  {
LABEL_29:
    v35 = 0;
    __break(0x800u);
  }
LABEL_30:
  _rcu_read_unlock(lock);
  *(_DWORD *)(*(_QWORD *)(a4 + 920) + 232LL) = v35;
  *(_DWORD *)(a4 + 912) = (v16 >> 1) & 1;
  if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)(v6 + 80) + 4720LL) - 3) > 1 )
  {
    *(_DWORD *)(*(_QWORD *)(a4 + 920) + 16LL) = 1;
  }
  else
  {
    v36 = *(_QWORD *)(a4 + 920);
    v37 = dword_C1530[(v16 >> 2) & 3];
    v38 = *(_DWORD *)(v36 + 16);
    *(_DWORD *)(v36 + 16) = v37;
    v29 = v37 != v38 || v28 != 0;
  }
  _ReadStatusReg(SP_EL0);
  return v29;
}
