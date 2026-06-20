__int64 __fastcall ieee80211_ml_reconfiguration(__int64 result, __int64 a2)
{
  int v2; // w9
  unsigned __int16 *v3; // x10
  unsigned __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  char v7; // w14
  unsigned int v8; // w9
  bool v9; // cf
  unsigned __int64 v10; // x14
  unsigned __int64 v11; // x14
  __int64 v12; // x15
  unsigned int v13; // w15
  unsigned int v14; // w16
  __int64 v15; // x10
  __int64 v16; // x20
  __int64 v17; // x19
  __int64 v18; // x0
  unsigned int v19; // w11
  unsigned int v20; // w12
  __int64 v21; // x8
  int v22; // w11
  bool v23; // zf
  unsigned __int64 v24; // x11
  int v25; // w12
  __int64 v26; // x9
  char *i; // x13
  __int64 v28; // x16
  __int64 v29; // x14
  __int64 v30; // x16
  __int64 v31; // x15
  char v32; // w17
  unsigned __int8 v33; // w16
  __int64 v34; // x15
  __int64 v35; // x16
  __int64 v36; // x14
  char v37; // w17
  unsigned __int8 v38; // w16
  __int64 v39; // x16
  unsigned __int64 v40; // x14
  unsigned int v41; // w16
  int v42; // w17
  int v43; // w3
  __int64 v44; // x17
  __int64 v45; // x17
  _QWORD v46[5]; // [xsp+8h] [xbp-28h] BYREF

  v46[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int16 *)(result + 5800);
  memset(v46, 0, 30);
  if ( !v2 )
    goto LABEL_30;
  v3 = *(unsigned __int16 **)(a2 + 456);
  if ( !v3 )
    goto LABEL_30;
  v4 = *(_QWORD *)(a2 + 728);
  if ( v4 < 2 )
  {
LABEL_4:
    LODWORD(v5) = 0;
    goto LABEL_5;
  }
  v19 = *v3;
  v20 = v19 & 7;
  if ( v20 <= 1 )
  {
    if ( (v19 & 7) != 0 )
    {
      if ( v20 != 1 )
        goto LABEL_48;
      if ( (v19 & 0x10) != 0 )
        LOBYTE(v22) = 2;
      else
        LOBYTE(v22) = 1;
    }
    else
    {
      if ( (v19 & 0x10) != 0 )
        v25 = 8;
      else
        v25 = 7;
      v22 = v25
          + (((unsigned __int8)(v19 & 0xE0) >> 5) & 1)
          + (((unsigned __int8)v19 >> 5) & 2)
          + ((v19 >> 6) & 2)
          + ((v19 >> 7) & 2)
          + ((v19 >> 9) & 1);
    }
LABEL_45:
    if ( (unsigned __int64)(unsigned __int8)v22 + 2 > v4
      || *((unsigned __int8 *)v3 + 2) < (unsigned int)(unsigned __int8)v22 )
    {
      goto LABEL_4;
    }
    goto LABEL_47;
  }
  if ( v20 != 2 )
  {
    if ( v20 != 3 )
    {
      if ( v20 == 4 )
      {
        if ( v4 < 9 )
          goto LABEL_4;
        goto LABEL_47;
      }
LABEL_48:
      v26 = 0;
      __break(0x800u);
      goto LABEL_49;
    }
    LOBYTE(v22) = 7;
    goto LABEL_45;
  }
  v23 = (v19 & 0x10) == 0;
  v24 = 8;
  if ( v23 )
    v24 = 2;
  if ( v24 > v4 )
    goto LABEL_4;
LABEL_47:
  v26 = (unsigned __int8)(*((_BYTE *)v3 + 2) + 2);
LABEL_49:
  v5 = 0;
  for ( i = (char *)v3 + v26; ; i += v40 + 2 )
  {
    v29 = *(_QWORD *)(a2 + 456);
    if ( (*(_WORD *)v29 & 7u) <= 4 )
    {
      v30 = v29 + (unsigned __int8)(*(_BYTE *)(v29 + 2) + 2);
      v31 = *(_QWORD *)(a2 + 728);
LABEL_59:
      v32 = *(_BYTE *)(v29 + 2);
      v29 = v30;
      v33 = v32 + 2;
      goto LABEL_61;
    }
    __break(0x800u);
    v31 = *(_QWORD *)(a2 + 728);
    if ( (**(_WORD **)(a2 + 456) & 7u) < 5 )
    {
      v30 = v29;
      v29 = *(_QWORD *)(a2 + 456);
      goto LABEL_59;
    }
    v33 = 0;
    __break(0x800u);
LABEL_61:
    if ( v29 + v31 - v33 - (__int64)i < 2 )
      goto LABEL_78;
    v34 = *(_QWORD *)(a2 + 456);
    if ( (*(_WORD *)v34 & 7u) <= 4 )
    {
      v35 = v34 + (unsigned __int8)(*(_BYTE *)(v34 + 2) + 2);
      v36 = *(_QWORD *)(a2 + 728);
LABEL_66:
      v37 = *(_BYTE *)(v34 + 2);
      v34 = v35;
      v38 = v37 + 2;
      goto LABEL_68;
    }
    __break(0x800u);
    v36 = *(_QWORD *)(a2 + 728);
    if ( (**(_WORD **)(a2 + 456) & 7u) < 5 )
    {
      v35 = v34;
      v34 = *(_QWORD *)(a2 + 456);
      goto LABEL_66;
    }
    v38 = 0;
    __break(0x800u);
LABEL_68:
    v39 = v36 - v38;
    v40 = (unsigned __int8)i[1];
    if ( v34 + v39 - (__int64)i < (__int64)(v40 + 2) )
      goto LABEL_78;
    if ( !*i )
    {
      if ( (unsigned int)v40 < 3 )
        goto LABEL_30;
      v41 = *((unsigned __int16 *)i + 1);
      v42 = (v41 >> 5) & 2;
      v43 = v42 + 7;
      if ( (v41 & 0x20) == 0 )
        v43 = v42 + 1;
      v44 = (unsigned __int8)i[4];
      if ( (unsigned int)v44 < v43 + ((v41 >> 10) & 2) || v44 + 2 > v40 )
        goto LABEL_30;
      v45 = v41 & 0xF;
      v5 |= 1LL << (v41 & 0xF);
      if ( (v41 & 0x40) != 0 )
        break;
    }
LABEL_54:
    ;
  }
  if ( (_DWORD)v45 != 15 )
  {
    if ( (v41 & 0x20) != 0 )
      v28 = 11;
    else
      v28 = 5;
    *((_WORD *)v46 + v45) = *(_WORD *)&i[v28];
    goto LABEL_54;
  }
  __break(0x5512u);
LABEL_78:
  v2 = *(unsigned __int16 *)(result + 5800);
LABEL_5:
  v6 = (unsigned int)v5 & v2;
  if ( v6 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      v10 = (unsigned __int16)v6 & (unsigned __int16)(-1LL << v7) & 0x7FFF;
      if ( !v10 )
        break;
      v11 = __clz(__rbit64(v10));
      v12 = *(_QWORD *)(result + 5680 + 8 * v11);
      if ( v12 )
      {
        if ( v11 > 0xE )
          __break(1u);
        v13 = *((_WORD *)v46 + v11) ? (*((unsigned __int16 *)v46 + v11) - 1) * *(unsigned __int16 *)(v12 + 50) : 0;
        v14 = v8 >= v13 ? v13 : v8;
        v8 = v8 ? v14 : v13;
      }
      else
      {
        v6 &= ~(1LL << v11);
      }
      v9 = v11 >= 0xE;
      v7 = v11 + 1;
    }
    while ( !v9 );
    v15 = *(_QWORD *)(result + 1616);
    *(_WORD *)(result + 3032) = v6;
    v16 = result;
    v17 = *(_QWORD *)(v15 + 72);
    v18 = _usecs_to_jiffies(v8 << 10);
    result = wiphy_delayed_work_queue(v17, v16 + 2960, v18);
  }
  else if ( *(_WORD *)(result + 3032) )
  {
    v21 = *(_QWORD *)(result + 1616);
    *(_WORD *)(result + 3032) = 0;
    result = wiphy_delayed_work_cancel(*(_QWORD *)(v21 + 72), result + 2960);
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
