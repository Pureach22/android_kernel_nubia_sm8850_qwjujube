__int64 __fastcall ieee80211_calc_hw_conf_chan(unsigned int *a1, __int64 *a2)
{
  int v2; // w8
  unsigned int v3; // w22
  __int64 *v4; // x20
  int v6; // w21
  __int64 v7; // x8
  unsigned int v8; // w20
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x10
  __int64 v18; // x8
  unsigned int v19; // w8
  __int64 v20; // x8
  __int64 v21; // x10
  int v22; // w8
  int v23; // w9
  int v24; // w21
  __int64 lock; // x0
  int *i; // x8
  int v27; // w11
  int v28; // w12
  int v30; // w1
  int v31; // w2
  __int64 v32; // [xsp+8h] [xbp-28h] BYREF
  __int64 v33; // [xsp+10h] [xbp-20h]
  __int64 v34; // [xsp+18h] [xbp-18h]
  __int64 v35; // [xsp+20h] [xbp-10h]
  __int64 v36; // [xsp+28h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((unsigned __int8 *)a1 + 1400);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  if ( v2 != 1 )
  {
    v8 = 0;
    goto LABEL_63;
  }
  v3 = *a1;
  v4 = a2;
  if ( !a2 )
  {
LABEL_19:
    v6 = 2;
    if ( *((_QWORD *)a1 + 596) )
      goto LABEL_20;
    goto LABEL_6;
  }
  if ( !*a2 )
  {
    v4 = nullptr;
    __break(0x800u);
    goto LABEL_19;
  }
  if ( *((unsigned __int8 *)a2 + 100) > 1u )
  {
    v6 = 1;
    if ( !*((_QWORD *)a1 + 596) )
      goto LABEL_6;
LABEL_20:
    v17 = *((_QWORD *)a1 + 597);
    v32 = *((_QWORD *)a1 + 596);
    v33 = v17;
    v18 = *((_QWORD *)a1 + 599);
    v34 = *((_QWORD *)a1 + 598);
    v35 = v18;
    goto LABEL_21;
  }
  if ( *((unsigned __int8 *)a2 + 101) <= 1u )
    v6 = 2;
  else
    v6 = 3;
  if ( *((_QWORD *)a1 + 596) )
    goto LABEL_20;
LABEL_6:
  v7 = *((_QWORD *)a1 + 622);
  if ( v7 )
  {
    v32 = *((_QWORD *)a1 + 622);
    LODWORD(v33) = 0;
    HIDWORD(v33) = *(_DWORD *)(v7 + 4);
    WORD2(v35) = *(_WORD *)(v7 + 8);
  }
  else
  {
    if ( !v4 )
    {
      v12 = *((_QWORD *)a1 + 172);
      v13 = *((_QWORD *)a1 + 173);
      v32 = *((_QWORD *)a1 + 171);
      v33 = v12;
      v14 = *((_QWORD *)a1 + 174);
      v34 = v13;
      v35 = v14;
      v15 = cfg80211_chandef_valid(&v32);
      if ( (v15 & 1) != 0 )
      {
LABEL_29:
        v19 = *a1 | 8;
        goto LABEL_30;
      }
LABEL_66:
      if ( v32 )
      {
        v30 = *(_DWORD *)(v32 + 4);
        v31 = *(unsigned __int16 *)(v32 + 8);
      }
      else
      {
        v31 = 0;
        v30 = -1;
      }
      _warn_printk("control:%d.%03d MHz width:%d center: %d.%03d/%d MHz", v30, v31, v33, HIDWORD(v33), WORD2(v35), v34);
      v8 = 0;
      __break(0x800u);
      goto LABEL_63;
    }
    v9 = v4[3];
    v10 = *v4;
    v11 = v4[1];
    v34 = v4[2];
    v35 = v9;
    v32 = v10;
    v33 = v11;
  }
LABEL_21:
  v15 = cfg80211_chandef_valid(&v32);
  if ( (v15 & 1) == 0 )
    goto LABEL_66;
  if ( !v4
    || v32 != *v4
    || v33 != v4[1]
    || WORD2(v35) != *((unsigned __int16 *)v4 + 14)
    || (_DWORD)v34 != *((_DWORD *)v4 + 4)
    || HIWORD(v35) != *((unsigned __int16 *)v4 + 15) )
  {
    goto LABEL_29;
  }
  v19 = *a1 & 0xFFFFFFF7;
LABEL_30:
  *a1 = v19;
  if ( ((v19 ^ v3) & 8) == 0
    && !*((_QWORD *)a1 + 587)
    && (*((_BYTE *)a1 + 1470) & 1) == 0
    && *((_QWORD *)a1 + 3) == v32
    && (LODWORD(v20) = a1[8], *((_QWORD *)a1 + 4) == v33)
    && *((unsigned __int16 *)a1 + 26) == WORD2(v35)
    && a1[10] == (_DWORD)v34
    && *((unsigned __int16 *)a1 + 27) == HIWORD(v35) )
  {
    v8 = 0;
  }
  else
  {
    v20 = v33;
    v8 = 64;
    *((_QWORD *)a1 + 3) = v32;
    *((_QWORD *)a1 + 4) = v20;
    v21 = v35;
    *((_QWORD *)a1 + 5) = v34;
    *((_QWORD *)a1 + 6) = v21;
  }
  if ( (unsigned int)v20 <= 7 && ((1 << v20) & 0xC1) != 0 )
  {
    a1[15] = 2;
  }
  else if ( a1[15] != v6 )
  {
    v8 |= 2u;
    a1[15] = v6;
  }
  if ( (_DWORD)v33 == 7 )
  {
    v22 = *(_DWORD *)(v32 + 20);
    v23 = *(_DWORD *)(v32 + 24) - 3;
LABEL_47:
    if ( v23 >= v22 )
      v24 = v22;
    else
      v24 = v23;
    goto LABEL_51;
  }
  if ( (_DWORD)v33 == 6 )
  {
    v22 = *(_DWORD *)(v32 + 20);
    v23 = *(_DWORD *)(v32 + 24) - 6;
    goto LABEL_47;
  }
  v24 = *(_DWORD *)(v32 + 20);
LABEL_51:
  lock = _rcu_read_lock(v15, v16);
  for ( i = *((int **)a1 + 577); i != (int *)(a1 + 1154); i = *(int **)i )
  {
    if ( *((_QWORD *)i + 705) && i[1180] != 4 )
    {
      v27 = i[1259];
      v28 = v24 >= v27 ? i[1259] : v24;
      if ( v27 != 0x80000000 )
        v24 = v28;
    }
  }
  _rcu_read_unlock(lock);
  if ( a1[1] != v24 )
  {
    v8 |= 0x20u;
    a1[1] = v24;
  }
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return v8;
}
