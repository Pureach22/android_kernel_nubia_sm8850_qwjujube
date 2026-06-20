__int64 __fastcall rate_control_cap_mask(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x8
  int v8; // w8
  int v9; // w10
  unsigned int v10; // w9
  int v11; // w10
  __int64 v12; // x11
  unsigned __int64 i; // x12
  int v14; // w9
  __int64 v15; // x8
  unsigned int v16; // w8
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 result; // x0
  __int64 v25; // x8
  char v26; // w9
  char v27; // w8
  char v28; // w9
  char v29; // w8
  char v30; // w9
  char v31; // w8
  char v32; // w9
  char v33; // w8
  char v34; // w9
  char v35; // w8
  char v36; // w9
  char v37; // w8
  char v38; // w9
  char v39; // w8
  char v40; // w9
  char v41; // w8
  char v42; // w9
  __int16 v43; // w12
  __int16 v44; // w13
  __int16 v45; // w14
  __int16 v46; // w9
  __int16 v47; // w10
  __int16 v48; // w8
  __int16 v49; // w11
  __int16 v50; // w15
  __int16 v51; // w16
  __int16 v52; // w9
  __int16 v53; // w8
  __int16 v54; // w11
  __int16 v55; // w9
  __int16 v56; // w12
  __int64 v57; // [xsp+8h] [xbp-18h] BYREF
  __int64 v58; // [xsp+10h] [xbp-10h]
  __int64 v59; // [xsp+18h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned int *)(a2 + 16);
  if ( (unsigned int)v6 >= 6 )
    goto LABEL_30;
  v8 = *(_DWORD *)(a1 + 4 * v6 + 2040);
  *a4 = v8;
  v9 = *(_DWORD *)(a1 + 4952);
  v10 = *(_DWORD *)(a2 + 24);
  if ( v9 == 6 )
    v11 = 32;
  else
    v11 = (v9 == 7) << 6;
  if ( v10 )
  {
    v12 = 0;
    for ( i = 0; i < v10; ++i )
    {
      if ( (v11 & ~*(_DWORD *)(*(_QWORD *)(a2 + 8) + v12)) != 0 )
      {
        v8 &= ~(unsigned int)(1LL << i);
        *a4 = v8;
        v10 = *(_DWORD *)(a2 + 24);
      }
      v12 += 12;
    }
  }
  v14 = v8 ^ (-1 << v10);
  v15 = *(unsigned int *)(a2 + 16);
  if ( v14 == -1 )
  {
    if ( (unsigned int)v15 > 5 )
      goto LABEL_30;
    if ( (*(_BYTE *)(a1 + v15 + 2064) & 1) == 0 && (*(_BYTE *)(a1 + v15 + 2130) & 1) == 0 )
    {
      result = 0;
      goto LABEL_28;
    }
  }
  else if ( (unsigned int)v15 > 5 )
  {
    goto LABEL_30;
  }
  if ( *(_BYTE *)(a1 + v15 + 2064) == 1 )
  {
    v16 = *(_DWORD *)(a2 + 16);
    if ( v16 > 6 )
      goto LABEL_30;
    v17 = a1 + 10LL * v16;
    v18 = *(_QWORD *)(v17 + 2070);
    *(_WORD *)(a5 + 8) = *(_WORD *)(v17 + 2078);
    *(_QWORD *)a5 = v18;
  }
  else
  {
    *(_QWORD *)a5 = -1;
    *(_WORD *)(a5 + 8) = -1;
  }
  v19 = *(unsigned int *)(a2 + 16);
  if ( (unsigned int)v19 > 5 )
LABEL_30:
    __break(0x5512u);
  if ( *(_BYTE *)(a1 + v19 + 2130) == 1 )
  {
    v20 = *(unsigned int *)(a2 + 16);
    if ( (unsigned int)v20 > 6 )
      goto LABEL_30;
    v21 = a1 + 16 * v20;
    v22 = *(_QWORD *)(v21 + 2144);
    v23 = *(_QWORD *)(v21 + 2136);
    *(_QWORD *)(a6 + 8) = v22;
    *(_QWORD *)a6 = v23;
    if ( !a3 )
      goto LABEL_24;
  }
  else
  {
    *(_QWORD *)(a6 + 8) = -1;
    *(_QWORD *)a6 = -1;
    if ( !a3 )
    {
LABEL_24:
      result = 1;
      goto LABEL_28;
    }
  }
  v25 = *(unsigned int *)(a2 + 16);
  v57 = 0;
  v58 = 0;
  if ( (unsigned int)v25 > 5 )
    goto LABEL_30;
  *a4 &= *(_DWORD *)(a3 + 4 * v25 + 212);
  v26 = *(_BYTE *)(a5 + 1);
  *(_BYTE *)a5 &= *(_BYTE *)(a3 + 241);
  v27 = v26 & *(_BYTE *)(a3 + 242);
  v28 = *(_BYTE *)(a5 + 2);
  *(_BYTE *)(a5 + 1) = v27;
  v29 = v28 & *(_BYTE *)(a3 + 243);
  v30 = *(_BYTE *)(a5 + 3);
  *(_BYTE *)(a5 + 2) = v29;
  v31 = v30 & *(_BYTE *)(a3 + 244);
  v32 = *(_BYTE *)(a5 + 4);
  *(_BYTE *)(a5 + 3) = v31;
  v33 = v32 & *(_BYTE *)(a3 + 245);
  v34 = *(_BYTE *)(a5 + 5);
  *(_BYTE *)(a5 + 4) = v33;
  v35 = v34 & *(_BYTE *)(a3 + 246);
  v36 = *(_BYTE *)(a5 + 6);
  *(_BYTE *)(a5 + 5) = v35;
  v37 = v36 & *(_BYTE *)(a3 + 247);
  v38 = *(_BYTE *)(a5 + 7);
  *(_BYTE *)(a5 + 6) = v37;
  v39 = v38 & *(_BYTE *)(a3 + 248);
  v40 = *(_BYTE *)(a5 + 8);
  *(_BYTE *)(a5 + 7) = v39;
  v41 = v40 & *(_BYTE *)(a3 + 249);
  v42 = *(_BYTE *)(a5 + 9);
  *(_BYTE *)(a5 + 8) = v41;
  *(_BYTE *)(a5 + 9) = v42 & *(_BYTE *)(a3 + 250);
  ieee80211_get_vht_mask_from_cap(*(unsigned __int16 *)(a3 + 268), &v57);
  result = 1;
  v43 = WORD2(v57);
  v44 = *(_WORD *)(a6 + 4);
  v45 = *(_WORD *)(a6 + 8);
  v46 = *(_WORD *)(a6 + 2) & WORD1(v57);
  v47 = HIWORD(v57);
  *(_WORD *)a6 &= v57;
  v48 = *(_WORD *)(a6 + 6);
  v49 = v58;
  *(_WORD *)(a6 + 2) = v46;
  v50 = WORD1(v58);
  v51 = *(_WORD *)(a6 + 10);
  v52 = v45 & v49;
  *(_WORD *)(a6 + 4) = v44 & v43;
  *(_WORD *)(a6 + 6) = v48 & v47;
  v53 = WORD2(v58);
  v54 = *(_WORD *)(a6 + 12);
  *(_WORD *)(a6 + 8) = v52;
  v55 = HIWORD(v58);
  v56 = *(_WORD *)(a6 + 14);
  *(_WORD *)(a6 + 10) = v51 & v50;
  *(_WORD *)(a6 + 12) = v54 & v53;
  *(_WORD *)(a6 + 14) = v56 & v55;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
