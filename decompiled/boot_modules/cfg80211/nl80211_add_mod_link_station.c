__int64 __fastcall nl80211_add_mod_link_station(
        _QWORD *a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  _QWORD *v9; // x0
  __int64 v10; // x19
  __int64 v11; // x8
  _QWORD *v12; // x8
  _QWORD *v13; // x21
  __int64 v14; // x9
  __int64 v15; // x9
  int v16; // w10
  __int64 v17; // x9
  _BYTE *v18; // x9
  __int64 v19; // x9
  __int64 v20; // x9
  _BYTE *v21; // x11
  _BYTE *v22; // x10
  unsigned __int8 v23; // w22
  unsigned int v24; // w8
  int v25; // w8
  int v26; // w11
  int v27; // w8
  int v28; // w23
  __int16 v29; // w26
  _QWORD *v30; // x24
  char v31; // w25
  int v32; // w8
  _QWORD *v33; // x8
  __int64 v34; // x9
  __int64 v35; // x9
  __int64 v36; // x9
  _BYTE *v37; // x10
  char v38; // w8
  __int64 v39; // x8
  unsigned int v40; // w0
  __int64 v42; // [xsp+0h] [xbp-80h] BYREF
  __int64 v43; // [xsp+8h] [xbp-78h]
  __int64 v44; // [xsp+10h] [xbp-70h]
  _BYTE *v45; // [xsp+18h] [xbp-68h]
  __int64 v46; // [xsp+20h] [xbp-60h]
  __int64 v47; // [xsp+28h] [xbp-58h]
  __int64 v48; // [xsp+30h] [xbp-50h]
  __int64 v49; // [xsp+38h] [xbp-48h]
  _BYTE *v50; // [xsp+40h] [xbp-40h]
  __int64 v51; // [xsp+48h] [xbp-38h]
  __int64 v52; // [xsp+50h] [xbp-30h]
  __int64 v53; // [xsp+58h] [xbp-28h]
  _BYTE *v54; // [xsp+60h] [xbp-20h]
  __int64 v55; // [xsp+68h] [xbp-18h]
  __int64 v56; // [xsp+70h] [xbp-10h]
  __int64 v57; // [xsp+78h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = (_QWORD *)a1[6];
  v55 = 0;
  v56 = 0;
  v10 = a1[7];
  v53 = 0;
  v54 = nullptr;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = nullptr;
  v47 = 0;
  v48 = 0;
  v45 = nullptr;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v11 = *v9;
  if ( (a2 & 1) != 0 )
  {
    if ( *(_QWORD *)(v11 + 960) )
    {
      v13 = a1 + 4;
      v12 = (_QWORD *)a1[4];
      if ( !v12[6] )
        goto LABEL_53;
      v14 = v12[314];
      if ( !v14 || !v12[19] )
        goto LABEL_53;
      goto LABEL_9;
    }
LABEL_45:
    v24 = -95;
    goto LABEL_54;
  }
  if ( !*(_QWORD *)(v11 + 968) )
    goto LABEL_45;
  v13 = a1 + 4;
  v12 = (_QWORD *)a1[4];
  v14 = v12[314];
  if ( !v14 )
    goto LABEL_53;
LABEL_9:
  v42 = v14 + 4;
  v15 = v12[6];
  if ( v15 )
  {
    v44 = v15 + 4;
    v16 = *(_DWORD *)(v15 + 4);
    if ( (v16 & 1) != 0 || !(v16 | *(unsigned __int16 *)(v15 + 8)) )
      goto LABEL_53;
  }
  v17 = v12[313];
  if ( !v17 )
    goto LABEL_53;
  LODWORD(v43) = *(unsigned __int8 *)(v17 + 4);
  v18 = (_BYTE *)v12[19];
  if ( v18 )
  {
    v45 = v18 + 4;
    LOBYTE(v46) = *v18 - 4;
  }
  v19 = v12[31];
  if ( v19 )
    v47 = v19 + 4;
  v20 = v12[157];
  if ( v20 )
    v48 = v20 + 4;
  v21 = (_BYTE *)v12[269];
  if ( v21 )
  {
    v50 = v21 + 4;
    LOBYTE(v51) = *v21 - 4;
    v22 = (_BYTE *)v12[310];
    if ( v22 )
    {
      v54 = v22 + 4;
      v23 = *v22 - 4;
      v24 = -22;
      LOBYTE(v55) = v23;
      if ( v21 == (_BYTE *)-4LL || v23 < 0xBu )
        goto LABEL_54;
      v25 = (unsigned __int8)v21[10];
      if ( (v25 & 2) != 0 )
      {
        v28 = 14;
      }
      else
      {
        v26 = (v25 << 29 >> 31) & 3;
        if ( (v25 & 8) != 0 )
          v26 += 3;
        if ( (v22[6] & 2) != 0 )
          v27 = v26 + 3;
        else
          v27 = v26;
        if ( v27 )
          v28 = v27 + 11;
        else
          v28 = 15;
      }
      if ( (unsigned __int8)v28 > (unsigned int)v23 )
        goto LABEL_53;
      if ( (v22[11] & 8) != 0 )
      {
        if ( (unsigned __int64)(unsigned __int8)v28 + 2 > v23 )
          goto LABEL_53;
        v29 = *(_WORD *)&v22[(unsigned __int8)v28 + 4];
        v30 = v9;
        v31 = a2;
        v32 = _sw_hweight16(v29 & 0x1F0);
        a2 = v31;
        v9 = v30;
        v28 += (v32 * (6 * (v29 & 0xFu) + 6) + 16) >> 3;
      }
      if ( (unsigned __int8)v28 > (unsigned int)v23 )
        goto LABEL_53;
    }
  }
  v33 = (_QWORD *)*v13;
  v34 = *(_QWORD *)(*v13 + 2344LL);
  if ( v34 )
    v53 = v34 + 4;
  v35 = v33[194];
  if ( v35 )
  {
    BYTE1(v49) = 1;
    LOBYTE(v49) = *(_BYTE *)(v35 + 4);
  }
  v36 = v33[275];
  if ( v36 )
  {
    v37 = (_BYTE *)a1[6];
    if ( !*(_QWORD *)(*(_QWORD *)v37 + 424LL) || (v37[1108] & 0x20) == 0 )
      goto LABEL_45;
    LODWORD(v52) = *(unsigned __int8 *)(v36 + 4);
    if ( (_DWORD)v52 != 1 )
      goto LABEL_50;
    v39 = v33[276];
    if ( v39 )
    {
      WORD2(v51) = *(_WORD *)(v39 + 4);
LABEL_50:
      v38 = 1;
      goto LABEL_51;
    }
LABEL_53:
    v24 = -22;
    goto LABEL_54;
  }
  v38 = 0;
LABEL_51:
  BYTE4(v52) = v38;
  if ( (a2 & 1) != 0 )
    v40 = rdev_add_link_station(v9, v10, &v42, a4, a5, a6, a7, a8, v42, v43, v44, v45, v46, v47, v48, v49);
  else
    v40 = rdev_mod_link_station(v9, v10, &v42, a4, a5, a6, a7, a8, v42, v43, v44, v45, v46, v47, v48, v49);
  v24 = v40;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return v24;
}
