__int64 __fastcall ieee80211_handle_pwr_constr(
        __int64 a1,
        int *a2,
        _WORD *a3,
        __int64 a4,
        int a5,
        unsigned __int8 *a6,
        __int64 a7)
{
  __int64 v8; // x19
  __int64 v9; // x23
  __int64 v12; // x22
  int v15; // w0
  int v16; // w10
  int v17; // w8
  int v18; // w11
  int v19; // w9
  int v20; // w13
  int v21; // w10
  unsigned __int8 *v22; // x9
  __int64 v23; // x11
  int v24; // w8
  int v25; // w12
  int v26; // w8
  __int64 v27; // x13
  unsigned int v28; // w15
  unsigned int v29; // t1
  int v30; // w14
  int v31; // w15
  int v32; // w10
  char v33; // w9
  char v34; // w11
  int v35; // w12

  if ( (*a3 & 0xFC) == 0x1C )
    return 0;
  v8 = *(_QWORD *)a1;
  if ( !a4 || (a3[17] & 0x1100) == 0 )
  {
    if ( !a7 )
      return 0;
    LOBYTE(v19) = 0;
    v24 = 0;
    goto LABEL_33;
  }
  v9 = a1;
  v12 = a7;
  v15 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * a2[1]));
  v16 = 0;
  if ( (unsigned __int8)a5 < 6u )
  {
    v18 = 0;
    v19 = 0;
    a1 = v9;
    a7 = v12;
    goto LABEL_32;
  }
  v17 = v15;
  v18 = 0;
  v19 = 0;
  a1 = v9;
  a7 = v12;
  if ( (a5 & 1) != 0 )
    goto LABEL_32;
  v20 = *a2;
  v21 = 1;
  if ( *a2 <= 1 )
  {
    v22 = a6;
    v23 = a4;
    if ( !v20 )
      goto LABEL_19;
    if ( v20 == 1 )
    {
      v21 = 4;
      goto LABEL_19;
    }
    goto LABEL_18;
  }
  v22 = a6;
  v23 = a4;
  if ( v20 != 2 )
  {
    if ( v20 == 3 )
    {
LABEL_29:
      v16 = 0;
      v18 = 0;
      v19 = 0;
      goto LABEL_32;
    }
    if ( v20 != 5 )
LABEL_18:
      __break(0x800u);
  }
LABEL_19:
  v25 = a5 - 3;
  v26 = v17 + v21;
  v27 = v23;
  while ( 1 )
  {
    v29 = *(unsigned __int8 *)(v27 + 3);
    v27 += 3;
    v28 = v29;
    if ( v29 <= 0xC8 )
    {
      v30 = *(unsigned __int8 *)(v23 + 4);
      if ( *(_BYTE *)(v23 + 4) )
        break;
    }
LABEL_20:
    v25 -= 3;
    v23 = v27;
    if ( (unsigned __int8)v25 <= 2u )
      goto LABEL_29;
  }
  v31 = v26 - v28;
  while ( 1 )
  {
    v31 -= v21;
    if ( !v31 )
      break;
    if ( !--v30 )
      goto LABEL_20;
  }
  v16 = *(char *)(v23 + 5);
  if ( v22 )
    v18 = *v22;
  else
    v18 = 0;
  v19 = 1;
LABEL_32:
  v24 = (v16 - v18) & ~((v16 - v18) >> 31);
  if ( a7 )
  {
LABEL_33:
    v32 = *(char *)(a7 + 4);
    v33 = v19 ^ 1;
    v34 = 1;
    goto LABEL_34;
  }
  if ( !v19 )
    return 0;
  v34 = 0;
  v33 = 0;
  v32 = 0;
LABEL_34:
  v35 = *(_DWORD *)(a1 + 452);
  if ( v24 <= v32 )
    v34 = 0;
  if ( (v33 & 1) != 0 || (v34 & 1) != 0 )
  {
    if ( v35 != v32 )
      goto LABEL_41;
    return 0;
  }
  v32 = v24;
  if ( v35 == v24 )
    return 0;
LABEL_41:
  *(_DWORD *)(a1 + 452) = v32;
  if ( (_ieee80211_recalc_txpower(v8, (__int64)a2) & 1) != 0 )
    return 0x40000;
  else
    return 0;
}
