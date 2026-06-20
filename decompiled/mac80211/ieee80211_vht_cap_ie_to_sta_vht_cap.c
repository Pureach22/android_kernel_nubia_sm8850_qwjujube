__int64 __fastcall ieee80211_vht_cap_ie_to_sta_vht_cap(__int64 result, __int64 a2, int *a3, _DWORD *a4, __int64 a5)
{
  __int64 v5; // x20
  _BYTE *v6; // x21
  __int64 v7; // x9
  unsigned __int8 *v8; // x10
  int v9; // t1
  int v10; // w9
  __int64 v11; // x8
  __int64 v12; // x19
  __int64 v13; // x22
  _DWORD *v14; // x24
  int *v15; // x23
  unsigned int v16; // w8
  unsigned int v17; // w10
  int v18; // w11
  int v19; // w10
  int v20; // w11
  int v21; // w10
  int v22; // w11
  int v23; // w9
  __int64 v24; // x12
  unsigned int v25; // w11
  unsigned int v26; // w10
  int i; // w12
  unsigned int v28; // w17
  unsigned int v29; // w1
  unsigned int v30; // w2
  int v31; // w6
  unsigned int v32; // w17
  int v33; // w5
  int v34; // w1
  int v35; // w5
  int v36; // w1
  int v37; // w2
  int v38; // w17
  int v39; // w17
  int v40; // w2
  int v41; // w9
  _DWORD *v42; // x19
  int v43; // w8
  bool v44; // zf
  __int64 v45; // x21
  unsigned int v46; // w9
  __int16 v47; // w11
  __int16 v48; // w9
  __int64 v49; // [xsp+8h] [xbp-18h] BYREF
  __int64 v50; // [xsp+10h] [xbp-10h]
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a5 + 920);
  *(_QWORD *)(v5 + 76) = 0;
  *(_QWORD *)(v5 + 68) = 0;
  v6 = (_BYTE *)(v5 + 68);
  if ( !a3 )
    goto LABEL_64;
  if ( (*(_BYTE *)(*(_QWORD *)(a5 + 920) + 46LL) & 1) == 0 )
    goto LABEL_64;
  if ( *(_BYTE *)(a2 + 52) != 1 )
    goto LABEL_64;
  v7 = *(unsigned int *)(a2 + 20);
  if ( !(_DWORD)v7 )
    goto LABEL_64;
  v8 = (unsigned __int8 *)(*(_QWORD *)a2 + 12LL);
  while ( 1 )
  {
    v9 = *v8;
    v8 += 64;
    if ( (v9 & 0xFFFFFF81) == 0 )
      break;
    if ( !--v7 )
      goto LABEL_64;
  }
  *v6 = 1;
  v10 = *(_DWORD *)(result + 4720);
  v11 = *(_QWORD *)(a2 + 60);
  v49 = *(_QWORD *)(a2 + 52);
  v50 = v11;
  if ( v10 == 2 && (*(_QWORD *)(*(_QWORD *)(a5 + 32) + 216LL) & 0x800) == 0 )
  {
    v12 = result;
    v13 = a5;
    v14 = a4;
    v15 = a3;
    ieee80211_apply_vhtcap_overrides(result, (__int64)&v49);
    a3 = v15;
    result = v12;
    a4 = v14;
    a5 = v13;
  }
  v16 = *a3;
  v17 = *a3 & 3;
  v18 = BYTE4(v49) & 0xC;
  if ( v17 >= (BYTE4(v49) & 3u) )
    v17 = BYTE4(v49) & 3;
  v19 = v17 | *a3 & 0x3FE00010;
  if ( v18 == 8 )
  {
    v20 = *a3 & 0xC;
    goto LABEL_18;
  }
  if ( v18 == 4 )
  {
    v20 = *a3 & 4;
LABEL_18:
    v19 |= v20;
  }
  v21 = v16 & ((int)(HIDWORD(v49) << 19) >> 31) & 0x70800 | (unsigned __int8)v16 & BYTE4(v49) & 0x60 | v19;
  v22 = *a3 & 0x80;
  if ( (v49 & 0x70000000000LL) == 0 )
    v22 = 0;
  v23 = v21
      | (unsigned __int16)v16 & (unsigned __int16)((__int16)(16 * WORD2(v49)) >> 15) & 0xF000
      | v16 & (2 * HIDWORD(v49)) & 0x100000
      | v16 & (HIDWORD(v49) >> 1) & 0x80000
      | (unsigned __int16)v16 & (unsigned __int16)(SBYTE4(v49) >> 7) & 0x700
      | v22;
  *(_DWORD *)(v5 + 72) = v23;
  v24 = *(_QWORD *)(a3 + 1);
  *(_QWORD *)(v5 + 76) = v24;
  v25 = (unsigned __int16)v24;
  v26 = WORD2(v24);
  if ( (*(_QWORD *)(*(_QWORD *)(result + 1616) + 96LL) & 0x40000000000LL) != 0 )
  {
    v23 |= v16 & 0xC0000000;
    *(_DWORD *)(v5 + 72) = v23;
  }
  else
  {
    *(_WORD *)(v5 + 82) = HIWORD(v24) & 0xDFFF;
  }
  for ( i = 0; i != 16; i += 2 )
  {
    v28 = ((unsigned __int16)v50 >> i) & 3;
    v29 = (v26 >> i) & 3;
    v30 = (WORD2(v50) >> i) & 3;
    if ( v28 >= v29 )
      v31 = (v26 >> i) & 3;
    else
      v31 = ((unsigned __int16)v50 >> i) & 3;
    v44 = v28 == 3;
    v32 = (v25 >> i) & 3;
    if ( v44 )
      v33 = 3;
    else
      v33 = v31;
    if ( v29 == 3 )
      v34 = 3;
    else
      v34 = v33;
    if ( v30 >= v32 )
      v35 = (v25 >> i) & 3;
    else
      v35 = (WORD2(v50) >> i) & 3;
    v36 = v34 << i;
    if ( v30 == 3 )
      v37 = 3;
    else
      v37 = v35;
    if ( v32 == 3 )
      v38 = 3;
    else
      v38 = v37;
    v39 = v38 << i;
    v40 = (unsigned __int16)~(3 << i);
    v26 = v26 & v40 | (unsigned __int16)v36;
    v25 = v25 & v40 | (unsigned __int16)v39;
  }
  *(_WORD *)(v5 + 76) = v25;
  *(_WORD *)(v5 + 80) = v26;
  if ( v25 == 0xFFFF )
  {
    *v6 = 0;
    result = printk(&unk_BC126, result + 1640, *(_QWORD *)(a5 + 32) + 64LL, a5);
  }
  else
  {
    v41 = v23 & 0xC;
    if ( v41 == 8 || v41 == 4 )
    {
      v42 = a4;
      v43 = 3;
    }
    else
    {
      v42 = a4;
      *(_DWORD *)(a5 + 912) = 2;
      if ( v16 >> 30 )
        v44 = (*(_WORD *)(v5 + 82) & 0x2000) == 0;
      else
        v44 = 1;
      if ( v44 )
        v43 = 2;
      else
        v43 = 3;
    }
    *(_DWORD *)(a5 + 912) = v43;
    v45 = a5;
    *(_DWORD *)(*(_QWORD *)(a5 + 920) + 232LL) = ieee80211_sta_cur_vht_bw(a5, 0);
    v46 = *(_DWORD *)(v5 + 72) & 3;
    if ( v42 && v46 >= (*v42 & 3u) )
      v46 = *v42 & 3;
    if ( v46 == 1 )
      v47 = 7991;
    else
      v47 = 3895;
    if ( v46 == 2 )
      v48 = 11454;
    else
      v48 = v47;
    *(_WORD *)(*(_QWORD *)(v45 + 920) + 194LL) = v48;
    result = ieee80211_sta_recalc_aggregates(*(_QWORD *)(v45 + 32) + 2688LL);
  }
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
