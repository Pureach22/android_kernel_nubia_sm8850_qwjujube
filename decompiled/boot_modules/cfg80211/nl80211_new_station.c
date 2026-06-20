unsigned __int64 __fastcall nl80211_new_station(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x24
  _QWORD *v5; // x8
  __int64 v6; // x9
  int v7; // w9
  __int64 v8; // x9
  __int64 v9; // x21
  __int64 v10; // x9
  int v11; // w10
  __int64 v12; // x9
  __int64 v13; // x9
  int v14; // w9
  __int64 v15; // x9
  __int64 v16; // x9
  __int16 v17; // w9
  __int64 v18; // x9
  __int64 v19; // x9
  __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x10
  unsigned __int64 result; // x0
  unsigned __int8 v24; // w22
  int v25; // w8
  int v26; // w11
  int v27; // w8
  int v28; // w23
  __int16 v29; // w26
  _QWORD *v30; // x25
  int v31; // w0
  __int64 v32; // x9
  __int64 v33; // x9
  __int64 v34; // x9
  int v35; // w9
  __int64 v36; // x9
  _BYTE *v37; // x10
  __int64 v38; // x9
  __int64 v39; // x9
  __int16 v40; // w9
  __int64 v41; // x9
  _QWORD *v42; // x22
  __int64 v43; // x1
  __int64 v44; // x2
  _QWORD *v45; // x9
  unsigned int v46; // w10
  __int16 v47; // w9
  char v48; // w12
  int v49; // w10
  int v50; // w11
  __int64 v51; // x19
  unsigned __int64 v52; // [xsp+8h] [xbp-E8h] BYREF
  __int64 v53; // [xsp+10h] [xbp-E0h]
  __int64 v54; // [xsp+18h] [xbp-D8h]
  __int64 v55; // [xsp+20h] [xbp-D0h]
  __int64 v56; // [xsp+28h] [xbp-C8h]
  __int64 v57; // [xsp+30h] [xbp-C0h]
  __int64 v58; // [xsp+38h] [xbp-B8h]
  __int64 v59; // [xsp+40h] [xbp-B0h]
  __int64 v60; // [xsp+48h] [xbp-A8h]
  __int64 v61; // [xsp+50h] [xbp-A0h]
  __int64 v62; // [xsp+58h] [xbp-98h]
  __int64 v63; // [xsp+60h] [xbp-90h]
  __int64 v64; // [xsp+68h] [xbp-88h]
  __int64 v65; // [xsp+70h] [xbp-80h]
  __int64 v66; // [xsp+78h] [xbp-78h]
  __int64 v67; // [xsp+80h] [xbp-70h]
  __int64 v68; // [xsp+88h] [xbp-68h]
  __int64 v69; // [xsp+90h] [xbp-60h]
  __int128 v70; // [xsp+98h] [xbp-58h]
  __int64 v71; // [xsp+A8h] [xbp-48h]
  __int64 v72; // [xsp+B0h] [xbp-40h]
  __int64 v73; // [xsp+B8h] [xbp-38h]
  __int64 v74; // [xsp+C0h] [xbp-30h]
  __int64 v75; // [xsp+C8h] [xbp-28h]
  __int64 v76; // [xsp+D0h] [xbp-20h]
  __int64 v77; // [xsp+D8h] [xbp-18h]
  __int64 v78; // [xsp+E0h] [xbp-10h]
  __int64 v79; // [xsp+E8h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[6];
  v3 = a2[7];
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v4 = *(_QWORD *)(v3 + 992);
  v70 = 0u;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 136LL) )
    goto LABEL_64;
  v5 = (_QWORD *)a2[4];
  if ( !v5[6] || !v5[18] || !v5[19] || !v5[16] && !v5[181] )
    goto LABEL_75;
  v6 = v5[313];
  if ( v6 )
    v7 = *(unsigned __int8 *)(v6 + 4);
  else
    v7 = -1;
  LODWORD(v66) = v7;
  v8 = v5[314];
  if ( v8 )
  {
    v9 = v8 + 4;
    v65 = v8 + 4;
    v10 = v5[6];
    v67 = v10 + 4;
    v11 = *(_DWORD *)(v10 + 4);
    if ( (v11 & 1) != 0 || !(v11 | *(unsigned __int16 *)(v10 + 8)) )
      goto LABEL_75;
  }
  else
  {
    v9 = v5[6] + 4LL;
  }
  v68 = v5[19] + 4LL;
  LOBYTE(v69) = *(_BYTE *)v5[19] - 4;
  HIDWORD(v54) = *(unsigned __int16 *)(v5[18] + 4LL);
  v12 = v5[282];
  if ( v12 )
    WORD1(v55) = *(_WORD *)(v12 + 4);
  v13 = v5[228];
  if ( v13 )
    v14 = *(unsigned __int8 *)(v13 + 4);
  else
    v14 = *(_DWORD *)(v4 + 8) == 9;
  HIDWORD(v63) = v14;
  v15 = v5[181];
  if ( !v15 )
    v15 = v5[16];
  LOWORD(v55) = *(_WORD *)(v15 + 4);
  v16 = v5[171];
  if ( v16 )
  {
    v17 = *(_WORD *)(v16 + 4);
    LODWORD(v54) = 2;
    LOWORD(v57) = v17;
  }
  v18 = v5[172];
  if ( v18 )
  {
    v58 = v18 + 4;
    LOBYTE(v59) = *(_BYTE *)v5[172] - 4;
  }
  v19 = v5[31];
  if ( v19 )
    *(_QWORD *)&v70 = v19 + 4;
  v20 = v5[157];
  if ( v20 )
    *((_QWORD *)&v70 + 1) = v20 + 4;
  v21 = v5[269];
  if ( v21 )
  {
    v72 = v21 + 4;
    LOBYTE(v73) = *(_BYTE *)v5[269] - 4;
    v22 = v5[310];
    if ( v22 )
    {
      result = 4294967274LL;
      v76 = v22 + 4;
      v24 = *(_BYTE *)v5[310] - 4;
      LOBYTE(v77) = v24;
      if ( v21 == -4 || v24 < 0xBu )
        goto LABEL_76;
      v25 = *(unsigned __int8 *)(v21 + 10);
      if ( (v25 & 2) != 0 )
      {
        v28 = 14;
      }
      else
      {
        v26 = (v25 << 29 >> 31) & 3;
        if ( (v25 & 8) != 0 )
          v26 += 3;
        if ( (*(_BYTE *)(v22 + 6) & 2) != 0 )
          v27 = v26 + 3;
        else
          v27 = v26;
        if ( v27 )
          v28 = v27 + 11;
        else
          v28 = 15;
      }
      if ( (unsigned __int8)v28 > (unsigned int)v24 )
        goto LABEL_75;
      if ( (*(_BYTE *)(v22 + 11) & 8) != 0 )
      {
        if ( (unsigned __int64)(unsigned __int8)v28 + 2 > v24 )
          goto LABEL_75;
        v29 = *(_WORD *)(v22 + 4 + (unsigned __int8)v28);
        v30 = a2;
        v31 = _sw_hweight16(v29 & 0x1F0);
        a2 = v30;
        v28 += (v31 * (6 * (v29 & 0xFu) + 6) + 16) >> 3;
      }
      if ( (unsigned __int8)v28 > (unsigned int)v24 )
        goto LABEL_75;
      v5 = (_QWORD *)a2[4];
    }
  }
  v32 = v5[293];
  if ( v32 )
    v75 = v32 + 4;
  if ( v5[194] )
  {
    BYTE1(v71) = 1;
    LOBYTE(v71) = *(_BYTE *)(v5[194] + 4LL);
  }
  v33 = v5[25];
  if ( v33 )
    BYTE6(v55) = *(_BYTE *)(v33 + 4);
  v34 = v5[274];
  if ( v34 )
  {
    v35 = *(unsigned __int16 *)(v34 + 4);
    LOWORD(v64) = v35;
    if ( v35 )
    {
      if ( (*(_BYTE *)(v2 + 1108) & 2) == 0 )
        goto LABEL_64;
    }
  }
  v36 = v5[275];
  if ( v36 )
  {
    v37 = (_BYTE *)a2[6];
    if ( !*(_QWORD *)(*(_QWORD *)v37 + 424LL) || (v37[1108] & 0x20) == 0 )
      goto LABEL_64;
    LODWORD(v74) = *(unsigned __int8 *)(v36 + 4);
    if ( (_DWORD)v74 != 1 )
      goto LABEL_68;
    v38 = v5[276];
    if ( v38 )
    {
      WORD2(v73) = *(_WORD *)(v38 + 4);
LABEL_68:
      LOBYTE(v36) = 1;
      goto LABEL_69;
    }
LABEL_75:
    result = 4294967274LL;
    goto LABEL_76;
  }
LABEL_69:
  BYTE4(v74) = v36;
  v39 = v5[189];
  if ( v39 )
  {
    v60 = v39 + 4;
    v40 = *(_WORD *)v5[189];
    LOBYTE(v61) = v40 - 4;
    if ( (v40 & 1) != 0 )
      goto LABEL_75;
  }
  v41 = v5[190];
  v42 = a2;
  if ( v41 )
  {
    v62 = v41 + 4;
    LOBYTE(v63) = *(_BYTE *)v5[190] - 4;
  }
  result = nl80211_parse_sta_wme(a2, &v52);
  if ( !(_DWORD)result )
  {
    if ( (unsigned int)parse_station_flags(v42, *(unsigned int *)(*(_QWORD *)(v3 + 992) + 8LL), &v52) )
      goto LABEL_75;
    if ( (v53 & 0x800000000LL) != 0 )
    {
      v45 = v42;
      if ( v75 && v70 != 0 )
        goto LABEL_75;
    }
    else
    {
      result = 4294967274LL;
      v70 = 0u;
      if ( (_BYTE)v73 )
        goto LABEL_76;
      if ( v75 )
        goto LABEL_76;
      v45 = v42;
      if ( (_BYTE)v77 )
        goto LABEL_76;
    }
    result = 4294967201LL;
    v46 = *(_DWORD *)(*(_QWORD *)(v3 + 992) + 8LL);
    if ( v46 > 9 )
      goto LABEL_76;
    if ( ((1 << v46) & 0x218) == 0 )
    {
      if ( ((1 << v46) & 0x104) != 0 )
      {
        result = 4294967274LL;
        LODWORD(v54) = v54 & 0xFFFFFFFE;
        if ( (v53 & 0x4000000000LL) == 0 || (v53 & 0xA0) != 0 )
          goto LABEL_76;
        if ( (~*(_DWORD *)(v2 + 1092) & 0x18000) != 0 )
        {
LABEL_64:
          result = 4294967201LL;
          goto LABEL_76;
        }
        LODWORD(v53) = v53 & 0xFFFFFF5D;
      }
      else
      {
        if ( v46 != 7 )
          goto LABEL_76;
        LODWORD(v54) = v54 & 0xFFFFFFFE;
        if ( v53 & 0x80 | BYTE4(v53) & 0x40 || *(_QWORD *)(v45[4] + 1448LL) )
          goto LABEL_75;
      }
LABEL_107:
      if ( *(_WORD *)(v4 + 1472) )
      {
        if ( (v66 & 0x80000000) == 0 )
        {
          if ( (((unsigned __int64)*(unsigned __int16 *)(v4 + 1472) >> v66) & 1) == 0 )
          {
            v51 = 4294967229LL;
LABEL_114:
            dev_put(v52, v43, v44);
            result = v51;
            goto LABEL_76;
          }
LABEL_113:
          v51 = (unsigned int)rdev_add_station(v2, v3, v9, &v52);
          goto LABEL_114;
        }
      }
      else if ( (v66 & 0x80000000) != 0 )
      {
        goto LABEL_113;
      }
      v51 = 4294967274LL;
      goto LABEL_114;
    }
    if ( (v53 & 0x800000000LL) == 0 || (*(_DWORD *)(v2 + 1092) & 0x4000) == 0 )
      LODWORD(v54) = v54 & 0xFFFFFFFE;
    if ( (v53 & 0x4000000000LL) != 0 )
      goto LABEL_75;
    if ( *(_QWORD *)(v45[4] + 1448LL) )
      goto LABEL_75;
    v47 = v53;
    v48 = *(_BYTE *)(v2 + 1101);
    v49 = v53 & 0xFFFFFFBF;
    v50 = v53 & 0xA0;
    LODWORD(v53) = v53 & 0xFFFFFFBF;
    if ( (v48 & 0x80) == 0 )
    {
      if ( v50 )
        goto LABEL_75;
    }
    if ( (*(_BYTE *)(v2 + 1112) & 0x10) == 0 && (v47 & 0x100) != 0 )
      goto LABEL_75;
    if ( !v50 )
    {
      LODWORD(v53) = v49 | 0xA0;
      HIDWORD(v53) |= 0xA0u;
    }
    result = get_vlan(v42, v2);
    v52 = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
      goto LABEL_107;
  }
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
