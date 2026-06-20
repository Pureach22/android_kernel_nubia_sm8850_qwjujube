__int64 __fastcall ieee80211_get_stats(__int64 a1, __int64 a2, _QWORD *a3)
{
  _QWORD *v6; // x19
  __int64 v7; // x0
  __int64 bss; // x0
  __int64 v9; // x1
  __int64 v10; // x23
  __int64 v11; // x12
  __int64 v12; // x13
  __int64 v13; // x14
  __int64 v14; // x10
  __int16 v15; // w8
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x10
  __int64 v19; // x15
  __int64 v20; // x14
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x13
  __int64 v24; // x12
  __int64 v25; // x10
  _QWORD *i; // x23
  __int64 v27; // x12
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x10
  __int64 v32; // x13
  __int64 v33; // x14
  __int64 v34; // x12
  __int64 v35; // x13
  __int64 v36; // x8
  __int64 v37; // x9
  __int64 v38; // x12
  __int64 v39; // x11
  __int64 v40; // x9
  __int16 v41; // w8
  __int64 lock; // x0
  __int64 *v43; // x8
  __int64 v44; // x24
  unsigned int v45; // w23
  _DWORD *v46; // x8
  int v47; // w0
  char v48; // w8
  __int64 v49; // x9
  __int64 v50; // x10
  __int64 v51; // x11
  __int64 v52; // x9
  __int64 v53; // x11
  __int64 v54; // x10
  __int64 v55; // x12
  __int64 v56; // x9
  __int64 v57; // x8
  __int64 v58; // x23
  __int64 v59; // x0
  _DWORD *v60; // x8
  __int64 result; // x0
  __int64 v62; // [xsp+8h] [xbp-158h] BYREF
  __int64 v63; // [xsp+10h] [xbp-150h]
  __int64 v64; // [xsp+18h] [xbp-148h]
  __int64 v65; // [xsp+20h] [xbp-140h]
  __int64 v66; // [xsp+28h] [xbp-138h]
  __int64 v67; // [xsp+30h] [xbp-130h]
  __int64 v68; // [xsp+38h] [xbp-128h]
  __int64 v69; // [xsp+40h] [xbp-120h]
  __int64 v70; // [xsp+48h] [xbp-118h]
  _QWORD s[34]; // [xsp+50h] [xbp-110h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD **)(a1 + 4304);
  memset(s, 0, 0x108u);
  *a3 = 0;
  a3[1] = 0;
  a3[2] = 0;
  a3[3] = 0;
  a3[4] = 0;
  a3[5] = 0;
  a3[6] = 0;
  a3[7] = 0;
  a3[8] = 0;
  a3[9] = 0;
  a3[10] = 0;
  a3[11] = 0;
  a3[12] = 0;
  a3[13] = 0;
  a3[14] = 0;
  a3[15] = 0;
  a3[16] = 0;
  a3[17] = 0;
  a3[18] = 0;
  a3[19] = 0;
  a3[20] = 0;
  v7 = v6[9];
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v64 = 0;
  v62 = 0;
  v63 = 0;
  bss = mutex_lock(v7);
  if ( *(_DWORD *)(a1 + 7408) == 2 )
  {
    bss = sta_info_get_bss(a1 + 2688, a1 + 6840);
    if ( !bss )
      goto LABEL_16;
    v10 = bss;
    if ( *(_QWORD *)(*(_QWORD *)(bss + 80) + 1608LL) != a1 )
    {
      __break(0x800u);
      goto LABEL_16;
    }
    memset(s, 0, 0x108u);
    bss = sta_set_sinfo(v10, s, 0);
    v11 = LODWORD(s[11]);
    v12 = a3[4];
    v13 = a3[5];
    v14 = a3[1] + s[3];
    v15 = s[0];
    *a3 += HIDWORD(s[10]);
    a3[1] = v14;
    v16 = a3[3];
    v17 = v13 + v11;
    v18 = s[4];
    a3[2] += *(_QWORD *)(v10 + 1768);
    v19 = a3[7];
    v20 = *(_QWORD *)(v10 + 1776);
    v21 = a3[6] + v18;
    v22 = HIDWORD(s[12]);
    a3[5] = v17;
    a3[6] = v21;
    a3[3] = v16 + v20;
    a3[4] = v12 + v22;
    v23 = a3[9];
    v24 = HIDWORD(s[11]);
    v25 = a3[8] + LODWORD(s[12]);
    a3[7] = v19 + *(_QWORD *)(v10 + 1992);
    a3[8] = v25;
    a3[9] = v23 + v24;
    a3[10] = *(unsigned int *)(v10 + 208);
    if ( (v15 & 0x100) != 0 )
    {
      bss = cfg80211_calculate_bitrate(&s[7]);
      v15 = s[0];
      a3[11] = 100000LL * (unsigned int)bss;
      if ( (v15 & 0x4000) == 0 )
      {
LABEL_6:
        if ( (v15 & 0x2000) == 0 )
          goto LABEL_16;
LABEL_15:
        a3[13] = BYTE6(s[5]);
        goto LABEL_16;
      }
    }
    else if ( (v15 & 0x4000) == 0 )
    {
      goto LABEL_6;
    }
    bss = cfg80211_calculate_bitrate((char *)&s[8] + 6);
    v41 = s[0];
    a3[12] = 100000LL * (unsigned int)bss;
    if ( (v41 & 0x2000) == 0 )
      goto LABEL_16;
    goto LABEL_15;
  }
  for ( i = (_QWORD *)v6[202]; i != v6 + 202; i = (_QWORD *)*i )
  {
    if ( *(_QWORD *)(i[10] + 1608LL) == a1 )
    {
      memset(s, 0, 0x108u);
      bss = sta_set_sinfo(i, s, 0);
      v27 = LODWORD(s[11]);
      v28 = s[4];
      v29 = a3[1] + s[3];
      *a3 += HIDWORD(s[10]);
      a3[1] = v29;
      v30 = a3[3];
      v31 = a3[4];
      v32 = a3[5];
      a3[2] += i[221];
      v33 = a3[7];
      v34 = v32 + v27;
      v35 = i[222];
      v36 = a3[6] + v28;
      v37 = HIDWORD(s[12]);
      a3[5] = v34;
      a3[6] = v36;
      a3[3] = v30 + v35;
      a3[4] = v31 + v37;
      v38 = a3[9];
      v39 = HIDWORD(s[11]);
      v40 = a3[8] + LODWORD(s[12]);
      a3[7] = v33 + i[249];
      a3[8] = v40;
      a3[9] = v38 + v39;
    }
  }
LABEL_16:
  LODWORD(v70) = 0;
  lock = _rcu_read_lock(bss, v9);
  v43 = *(__int64 **)(a1 + 8328);
  if ( v43 )
  {
    v44 = *v43;
    _rcu_read_unlock(lock);
    if ( v44 )
    {
      v45 = 0;
      _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        LODWORD(v70) = 0;
        v46 = *(_DWORD **)(v6[58] + 392LL);
        if ( v46 )
        {
          if ( *(v46 - 1) != -1997129224 )
            __break(0x8228u);
          v47 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64 *))v46)(v6, v45, &v62);
        }
        else
        {
          v47 = -95;
        }
        if ( v47 )
          break;
        ++v45;
        if ( v44 == v62 )
          goto LABEL_28;
      }
      LODWORD(v70) = 0;
      goto LABEL_32;
    }
  }
  else
  {
    _rcu_read_unlock(lock);
  }
LABEL_28:
  v48 = v70;
  if ( !(_DWORD)v70 )
  {
LABEL_32:
    v48 = 0;
    a3[14] = 0;
    goto LABEL_33;
  }
  a3[14] = *(unsigned int *)(v62 + 4);
  if ( (v48 & 1) != 0 )
  {
    v49 = BYTE4(v70);
    goto LABEL_34;
  }
LABEL_33:
  v49 = -1;
LABEL_34:
  v50 = v63;
  v51 = v64;
  if ( (v48 & 4) == 0 )
    v50 = -1;
  a3[15] = v49;
  a3[16] = v50;
  if ( (v48 & 8) != 0 )
    v52 = v51;
  else
    v52 = -1;
  v53 = v66;
  if ( (v48 & 0x10) != 0 )
    v54 = v65;
  else
    v54 = -1;
  v55 = v67;
  a3[17] = v52;
  a3[18] = v54;
  if ( (v48 & 0x20) != 0 )
    v56 = v53;
  else
    v56 = -1;
  if ( (v48 & 0x40) != 0 )
    v57 = v55;
  else
    v57 = -1;
  a3[19] = v56;
  a3[20] = v57;
  v58 = *(_QWORD *)(a1 + 4304);
  if ( *(_QWORD *)(*(_QWORD *)(v58 + 464) + 552LL) )
  {
    v59 = *(_QWORD *)(a1 + 4304);
    v60 = *(_DWORD **)(*(_QWORD *)(v58 + 464) + 552LL);
    if ( *(v60 - 1) != -1766845299 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD *))v60)(v59, a1 + 7408, a2, a3 + 21);
  }
  result = mutex_unlock(v6[9]);
  _ReadStatusReg(SP_EL0);
  return result;
}
