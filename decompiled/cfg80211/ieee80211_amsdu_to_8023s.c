_QWORD *__fastcall ieee80211_amsdu_to_8023s(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        __int64 a6,
        __int64 a7,
        unsigned __int8 a8)
{
  unsigned __int8 v8; // w21
  __int64 v9; // x26
  char v12; // w9
  unsigned int v13; // w25
  int v14; // w9
  unsigned int v15; // w22
  _QWORD *result; // x0
  int v17; // w9
  int v18; // w8
  unsigned __int16 v19; // w9
  int v20; // w10
  __int16 v21; // w11
  __int16 v22; // w10
  unsigned int v23; // w24
  unsigned int v24; // w12
  int v25; // w23
  unsigned int v26; // w28
  char v27; // w9
  __int64 v28; // x27
  int v29; // w8
  unsigned int v30; // w28
  __int64 v31; // x0
  __int64 v32; // x9
  int v33; // w10
  __int64 v34; // x0
  signed int v35; // w21
  __int64 v36; // x9
  int v37; // w11
  int v38; // w12
  unsigned __int64 v39; // x2
  __int64 v40; // x8
  int v41; // w8
  int v42; // w5
  __int64 v43; // x26
  unsigned __int64 v44; // x10
  __int64 v45; // x10
  __int64 v46; // x11
  __int64 v47; // x13
  unsigned int v48; // w28
  unsigned __int64 v49; // x12
  int v50; // w21
  __int64 v51; // x26
  int v52; // w28
  __int64 v53; // x2
  __int64 v54; // x9
  __int64 v55; // x10
  __int64 v56; // x11
  __int64 v57; // x11
  unsigned int v60; // w12
  __int64 v61; // x8
  int v62; // w10
  int v63; // w9
  int v64; // w11
  __int64 v65; // x9
  __int64 *v66; // x8
  unsigned int v73; // w13
  __int64 *i; // x1
  __int64 v75; // x8
  _QWORD *v76; // x9
  char v79; // [xsp+10h] [xbp-40h]
  unsigned int v80; // [xsp+14h] [xbp-3Ch]
  __int64 v81; // [xsp+18h] [xbp-38h]
  _BOOL4 v82; // [xsp+24h] [xbp-2Ch]
  int v85; // [xsp+34h] [xbp-1Ch]
  _QWORD v86[3]; // [xsp+38h] [xbp-18h] BYREF

  v8 = a8;
  v9 = a7;
  v86[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_BYTE *)(a1 + 126);
  *(_QWORD *)((char *)v86 + 7) = 0;
  v86[0] = 0;
  v82 = (v12 & 0x20) != 0 && *(_QWORD *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 8LL) == 0;
  v13 = 0;
  v79 = 0;
  if ( a4 == 7 )
    v14 = 15;
  else
    v14 = 14;
  v81 = (int)(((a5 + 3) & 0xFFFFFFFC) + 16);
  v85 = v14;
  do
  {
    while ( 1 )
    {
      v15 = *(_DWORD *)(a1 + 112) - v13;
      if ( v85 > (int)v15 )
        goto LABEL_90;
      result = (_QWORD *)skb_copy_bits(a1, v13, v86, (unsigned int)v85);
      if ( a4 == 7 )
      {
        if ( (BYTE6(v86[1]) & 3) == 1 )
          v17 = 12;
        else
          v17 = 6;
        if ( (BYTE6(v86[1]) & 3) == 2 )
          v18 = 18;
        else
          v18 = v17;
      }
      else
      {
        v18 = 0;
      }
      v19 = WORD2(v86[1]);
      if ( v8 > 1u || (v19 = __rev16(WORD2(v86[1])), v8) )
      {
        v20 = BYTE6(v86[1]) & 3;
        if ( v20 == 1 )
          v21 = 12;
        else
          v21 = 6;
        if ( v20 == 2 )
          v22 = 18;
        else
          v22 = v21;
        v19 += v22;
      }
      v23 = v19;
      v24 = v19 + 14;
      if ( v24 > v15 || !(LODWORD(v86[0]) ^ 0x3AAAA | WORD2(v86[0])) )
      {
LABEL_90:
        for ( i = *(__int64 **)a2; *(_QWORD *)a2 != a2 && i; i = *(__int64 **)a2 )
        {
          --*(_DWORD *)(a2 + 16);
          v75 = *i;
          v76 = (_QWORD *)i[1];
          *i = 0;
          i[1] = 0;
          *(_QWORD *)(v75 + 8) = v76;
          *v76 = v75;
          sk_skb_reason_drop(0, i, 85);
        }
        goto LABEL_96;
      }
      v13 += 14;
      v25 = (2 - (_BYTE)v19) & 3;
      v26 = v24 + v25;
      if ( (!a6
         || (v86[0] & 1) != 0
         || !(*(_DWORD *)a6 ^ LODWORD(v86[0]) | *(unsigned __int16 *)(a6 + 4) ^ WORD2(v86[0])))
        && (!v9 || !(*(_DWORD *)((char *)v86 + 6) ^ *(_DWORD *)v9 | WORD1(v86[1]) ^ *(unsigned __int16 *)(v9 + 4))) )
      {
        break;
      }
      v13 += v19 + v25;
      if ( v15 <= v26 )
        goto LABEL_95;
    }
    v27 = v82;
    if ( *(_DWORD *)(a1 + 116) )
      v27 = 1;
    if ( (v27 & 1) != 0 || v15 > v26 )
    {
      v80 = v24 + v25;
      if ( *(_DWORD *)(a1 + 112) - v13 < v23 )
        goto LABEL_90;
      v29 = v18 | 0x20;
      if ( (int)v23 < v29 )
        v29 = v23;
      v30 = v82 ? v29 : v23;
      v31 = _netdev_alloc_skb(0, v30 + (unsigned int)v81, 2080);
      if ( !v31 )
        goto LABEL_90;
      v32 = *(_QWORD *)(v31 + 224);
      v33 = *(_DWORD *)(v31 + 208);
      v28 = v31;
      *(_DWORD *)(v31 + 144) = *(_DWORD *)(a1 + 144);
      *(_QWORD *)(v31 + 224) = v32 + v81;
      *(_DWORD *)(v31 + 208) = v33 + v81;
      v34 = skb_put();
      skb_copy_bits(a1, v13, v34, v30);
      v35 = v23 - v30;
      if ( v23 != v30 )
      {
        v36 = *(_QWORD *)(a1 + 216);
        v37 = *(_DWORD *)(a1 + 112);
        v38 = *(_DWORD *)(a1 + 116);
        v39 = ((unsigned __int64)((v36 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
        v40 = *(_QWORD *)(((unsigned __int64)((v36 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x13FFFFFF8LL);
        if ( (v40 & 1) != 0 )
          v39 = v40 - 1;
        v41 = v30 + v13;
        v42 = v37 - v38;
        v43 = v36 + *(unsigned int *)(a1 + 212) + 88;
        if ( v37 - v38 <= (int)(v30 + v13) )
        {
          do
          {
            v44 = *(_QWORD *)v43;
            v41 -= v42;
            v42 = *(_DWORD *)(v43 + 8);
            v43 += 16;
          }
          while ( v41 >= v42 );
          if ( (v44 & 1) != 0 )
            v39 = 0;
          else
            v39 = v44;
        }
        v45 = *(_QWORD *)(v28 + 216);
        v46 = *(unsigned int *)(v28 + 212);
        v47 = *(_QWORD *)(v39 + 8);
        if ( v42 - v41 >= v35 )
          v48 = v23 - v30;
        else
          v48 = v42 - v41;
        v49 = v39;
        if ( (v47 & 1) != 0 )
          v49 = v47 - 1;
        _X12 = (unsigned int *)(v49 + 52);
        __asm { PRFM            #0x11, [X12] }
        do
          v73 = __ldxr(_X12);
        while ( __stxr(v73 + 1, _X12) );
        skb_add_rx_frag_netmem(v28, *(unsigned __int8 *)(v45 + v46 + 2));
        v50 = v35 - v48;
        if ( v50 >= 1 )
        {
          v51 = v43 + 12;
          do
          {
            if ( v50 >= *(_DWORD *)(v51 - 4) )
              v52 = *(_DWORD *)(v51 - 4);
            else
              v52 = v50;
            if ( (*(_QWORD *)(v51 - 12) & 1LL) != 0 )
              v53 = 0;
            else
              v53 = *(_QWORD *)(v51 - 12);
            v54 = *(_QWORD *)(v28 + 216);
            v55 = *(unsigned int *)(v28 + 212);
            v56 = *(_QWORD *)(v53 + 8);
            if ( (v56 & 1) != 0 )
              v57 = v56 - 1;
            else
              v57 = v53;
            _X11 = (unsigned int *)(v57 + 52);
            __asm { PRFM            #0x11, [X11] }
            do
              v60 = __ldxr(_X11);
            while ( __stxr(v60 + 1, _X11) );
            skb_add_rx_frag_netmem(v28, *(unsigned __int8 *)(v54 + v55 + 2));
            v50 -= v52;
            v51 += 16;
          }
          while ( v50 > 0 );
        }
      }
      v8 = a8;
      v9 = a7;
      v26 = v80;
      v13 += v23 + v25;
    }
    else
    {
      skb_pull(a1, v13);
      v28 = a1;
      v79 = 1;
    }
    v61 = *(_QWORD *)(v28 + 224);
    *(_WORD *)(v28 + 184) = v61 - *(_DWORD *)(v28 + 216);
    *(_QWORD *)(v28 + 16) = *(_QWORD *)(a1 + 16);
    *(_DWORD *)(v28 + 144) = *(_DWORD *)(a1 + 144);
    if ( a4 != 7 )
    {
      v62 = *(unsigned __int16 *)(v61 + 4);
      v63 = *(_DWORD *)v61 ^ 0x3AAAA;
      if ( v63 | v62 || (v64 = *(unsigned __int16 *)(v61 + 6), v64 == 62336) || v64 == 14209 )
      {
        if ( v63 | v62 ^ 0xF800 )
          goto LABEL_86;
        LOWORD(v64) = *(_WORD *)(v61 + 6);
      }
      WORD2(v86[1]) = v64;
      skb_pull(v28, 8);
    }
LABEL_86:
    result = (_QWORD *)skb_push(v28, 14);
    v65 = *(_QWORD *)((char *)v86 + 6);
    *result = v86[0];
    *(_QWORD *)((char *)result + 6) = v65;
    v66 = *(__int64 **)(a2 + 8);
    *(_QWORD *)v28 = a2;
    *(_QWORD *)(v28 + 8) = v66;
    *(_QWORD *)(a2 + 8) = v28;
    *v66 = v28;
    ++*(_DWORD *)(a2 + 16);
  }
  while ( v15 > v26 );
LABEL_95:
  if ( (v79 & 1) != 0 )
    goto LABEL_97;
LABEL_96:
  result = (_QWORD *)consume_skb(a1);
LABEL_97:
  _ReadStatusReg(SP_EL0);
  return result;
}
