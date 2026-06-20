__int64 __fastcall ieee80211_process_neg_ttlm_req(__int64 result, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 v4; // x19
  int can_neg_ttlm; // w20
  char v6; // w22
  __int64 v7; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x9
  _BYTE *v10; // x11
  char v11; // w26
  int v12; // w25
  char v13; // w28
  unsigned __int8 *v14; // x30
  __int64 v15; // x27
  int v16; // w11
  int v17; // w11
  __int64 *v18; // x6
  unsigned __int8 *v19; // x30
  int v20; // w11
  char *v21; // x6
  unsigned __int8 *v22; // x30
  int v23; // w11
  char *v24; // x6
  unsigned __int8 *v25; // x30
  int v26; // w11
  char *v27; // x6
  unsigned __int8 *v28; // x30
  int v29; // w11
  __int64 *v30; // x6
  unsigned __int8 *v31; // x30
  int v32; // w11
  char *v33; // x6
  unsigned __int8 *v34; // x30
  int v35; // w11
  char *v36; // x6
  char *v37; // x6
  __int64 v38; // x23
  __int64 v39; // x8
  __int64 v40; // x21
  __int64 v41; // x9
  __int64 v42; // x0
  int v43; // w10
  int v44; // w8
  __int16 v45; // w9
  __int64 v46; // x21
  unsigned __int8 v47[4]; // [xsp+1Ch] [xbp-74h]
  __int64 v48; // [xsp+20h] [xbp-70h] BYREF
  __int64 v49; // [xsp+28h] [xbp-68h] BYREF
  __int64 v50; // [xsp+30h] [xbp-60h] BYREF
  __int64 v51; // [xsp+38h] [xbp-58h] BYREF
  __int16 v52; // [xsp+40h] [xbp-50h]
  __int64 v53; // [xsp+48h] [xbp-48h] BYREF
  __int64 v54; // [xsp+50h] [xbp-40h]
  __int64 v55; // [xsp+58h] [xbp-38h]
  _BYTE v56[17]; // [xsp+60h] [xbp-30h]
  _BYTE v57[31]; // [xsp+71h] [xbp-1Fh]

  *(_QWORD *)&v57[23] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int16 *)(result + 5800);
  *(_WORD *)v47 = 0;
  v52 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  if ( !v3 )
    goto LABEL_133;
  v4 = result;
  v53 = 5;
  v54 = a2 + 27;
  can_neg_ttlm = 1;
  v55 = a3 - 27;
  v6 = *(_BYTE *)(a2 + 26);
  v56[0] = 1;
  *(_QWORD *)&v56[1] = 0;
  *(_QWORD *)&v56[9] = 0;
  *(_QWORD *)v57 = 0;
  *(_QWORD *)&v57[7] = 0;
  *(_QWORD *)&v57[15] = 0xFFFFFFFFLL;
  v7 = ieee802_11_parse_elems_full(&v53);
  if ( !v7 )
    goto LABEL_124;
  v8 = *(unsigned __int8 *)(v7 + 736);
  if ( !*(_BYTE *)(v7 + 736) )
    goto LABEL_124;
  v9 = 0;
  do
  {
    if ( v9 == 2 )
      __break(0x5512u);
    v10 = *(_BYTE **)(v7 + 472 + 8 * v9);
    v11 = *v10;
    if ( (*v10 & 0x18) != 0 )
      goto LABEL_123;
    if ( (*v10 & 4) != 0 )
    {
      LOWORD(v17) = *(_WORD *)(v4 + 5800);
      v47[v9] = 2;
      LOWORD(v48) = v17;
      LOWORD(v50) = v17;
      WORD1(v48) = v17;
      WORD1(v50) = v17;
      WORD2(v48) = v17;
      WORD2(v50) = v17;
      HIWORD(v48) = v17;
      HIWORD(v50) = v17;
      LOWORD(v49) = v17;
      LOWORD(v51) = v17;
      WORD1(v49) = v17;
      WORD1(v51) = v17;
      WORD2(v49) = v17;
      WORD2(v51) = v17;
      goto LABEL_96;
    }
    v12 = v11 & 3;
    v47[v9] = v11 & 3;
    if ( v12 == 3 )
      goto LABEL_123;
    v13 = v10[1];
    v14 = v10 + 2;
    if ( (v11 & 0x20) != 0 )
      v15 = 1;
    else
      v15 = 2;
    if ( (v10[1] & 1) != 0 )
    {
      if ( (v11 & 0x20) != 0 )
        v16 = *v14;
      else
        v16 = *(unsigned __int16 *)v14;
      if ( !v16 )
        goto LABEL_123;
    }
    else
    {
      LOWORD(v16) = 0;
    }
    if ( (v11 & 3) != 0 )
    {
      if ( v12 != 1 )
      {
        if ( v12 != 2 )
          goto LABEL_123;
        LOWORD(v48) = v16;
      }
      v18 = &v50;
    }
    else
    {
      v18 = &v48;
    }
    v19 = &v14[v15];
    *(_WORD *)v18 = v16;
    if ( (v13 & 2) != 0 )
    {
      if ( (v11 & 0x20) != 0 )
        v20 = *v19;
      else
        v20 = *(unsigned __int16 *)v19;
      if ( !v20 )
        goto LABEL_123;
    }
    else
    {
      LOWORD(v20) = 0;
    }
    if ( v12 == 2 )
    {
      v21 = (char *)&v50 + 2;
      WORD1(v48) = v20;
    }
    else
    {
      v21 = (char *)&v50 + 2;
      if ( v12 != 1 )
        v21 = (char *)&v48 + 2;
    }
    v22 = &v19[v15];
    *(_WORD *)v21 = v20;
    if ( (v13 & 4) != 0 )
    {
      if ( (v11 & 0x20) != 0 )
        v23 = *v22;
      else
        v23 = *(unsigned __int16 *)v22;
      if ( !v23 )
        goto LABEL_123;
    }
    else
    {
      LOWORD(v23) = 0;
    }
    if ( v12 == 2 )
    {
      v24 = (char *)&v50 + 4;
      WORD2(v48) = v23;
    }
    else
    {
      v24 = (char *)&v50 + 4;
      if ( v12 != 1 )
        v24 = (char *)&v48 + 4;
    }
    v25 = &v22[v15];
    *(_WORD *)v24 = v23;
    if ( (v13 & 8) != 0 )
    {
      if ( (v11 & 0x20) != 0 )
        v26 = *v25;
      else
        v26 = *(unsigned __int16 *)v25;
      if ( !v26 )
        goto LABEL_123;
    }
    else
    {
      LOWORD(v26) = 0;
    }
    if ( v12 == 2 )
    {
      v27 = (char *)&v50 + 6;
      HIWORD(v48) = v26;
    }
    else
    {
      v27 = (char *)&v50 + 6;
      if ( v12 != 1 )
        v27 = (char *)&v48 + 6;
    }
    v28 = &v25[v15];
    *(_WORD *)v27 = v26;
    if ( (v13 & 0x10) != 0 )
    {
      if ( (v11 & 0x20) != 0 )
        v29 = *v28;
      else
        v29 = *(unsigned __int16 *)v28;
      if ( !v29 )
        goto LABEL_123;
    }
    else
    {
      LOWORD(v29) = 0;
    }
    if ( v12 == 2 )
    {
      v30 = &v51;
      LOWORD(v49) = v29;
    }
    else
    {
      v30 = &v51;
      if ( v12 != 1 )
        v30 = &v49;
    }
    v31 = &v28[v15];
    *(_WORD *)v30 = v29;
    if ( (v13 & 0x20) != 0 )
    {
      if ( (v11 & 0x20) != 0 )
        v32 = *v31;
      else
        v32 = *(unsigned __int16 *)v31;
      if ( !v32 )
        goto LABEL_123;
    }
    else
    {
      LOWORD(v32) = 0;
    }
    if ( v12 == 2 )
    {
      v33 = (char *)&v51 + 2;
      WORD1(v49) = v32;
    }
    else
    {
      v33 = (char *)&v51 + 2;
      if ( v12 != 1 )
        v33 = (char *)&v49 + 2;
    }
    v34 = &v31[v15];
    *(_WORD *)v33 = v32;
    if ( (v13 & 0x40) != 0 )
    {
      if ( (v11 & 0x20) != 0 )
        v35 = *v34;
      else
        v35 = *(unsigned __int16 *)v34;
      if ( !v35 )
        goto LABEL_123;
    }
    else
    {
      LOWORD(v35) = 0;
    }
    if ( v12 == 2 )
    {
      WORD2(v49) = v35;
      WORD2(v51) = v35;
      if ( (v13 & 0x80) == 0 )
        goto LABEL_87;
    }
    else
    {
      v36 = (char *)&v51 + 4;
      if ( v12 != 1 )
        v36 = (char *)&v49 + 4;
      *(_WORD *)v36 = v35;
      if ( (v13 & 0x80) == 0 )
      {
LABEL_87:
        LOWORD(v17) = 0;
        goto LABEL_93;
      }
    }
    if ( (v11 & 0x20) != 0 )
      v17 = v34[v15];
    else
      v17 = *(unsigned __int16 *)&v34[v15];
    if ( !v17 )
      goto LABEL_123;
LABEL_93:
    if ( v12 != 2 )
    {
      v37 = (char *)&v51 + 6;
      if ( v12 != 1 )
        v37 = (char *)&v49 + 6;
      *(_WORD *)v37 = v17;
      goto LABEL_6;
    }
LABEL_96:
    HIWORD(v49) = v17;
    HIWORD(v51) = v17;
    if ( (_DWORD)v8 != 1 )
      goto LABEL_123;
LABEL_6:
    ++v9;
  }
  while ( v9 < v8 );
  if ( !(_DWORD)v8
    || (_DWORD)v8 == 2 && v47[0] == v47[1]
    || (_WORD)v48 && ((unsigned __int16)v48 & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || (_WORD)v50 && ((unsigned __int16)v50 & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || WORD1(v48) && (WORD1(v48) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || WORD1(v50) && (WORD1(v50) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || WORD2(v48) && (WORD2(v48) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || WORD2(v50) && (WORD2(v50) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || HIWORD(v48) && (HIWORD(v48) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || HIWORD(v50) && (HIWORD(v50) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || (_WORD)v49 && ((unsigned __int16)v49 & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || (_WORD)v51 && ((unsigned __int16)v51 & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || WORD1(v49) && (WORD1(v49) & ~*(unsigned __int16 *)(v4 + 5800)) != 0 )
  {
LABEL_123:
    can_neg_ttlm = 1;
    goto LABEL_124;
  }
  v46 = v7;
  if ( WORD1(v51) && (WORD1(v51) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || WORD2(v49) && (WORD2(v49) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || WORD2(v51) && (WORD2(v51) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || HIWORD(v49) && (HIWORD(v49) & ~*(unsigned __int16 *)(v4 + 5800)) != 0
    || HIWORD(v51) && (HIWORD(v51) & ~*(unsigned __int16 *)(v4 + 5800)) != 0 )
  {
    can_neg_ttlm = 1;
    goto LABEL_145;
  }
  can_neg_ttlm = drv_can_neg_ttlm(*(_QWORD *)(v4 + 1616), v4);
  v7 = v46;
  if ( !can_neg_ttlm )
  {
    v55 = v50;
    *(_QWORD *)v56 = v51;
    *(_WORD *)&v56[8] = v52;
    v53 = v48;
    v54 = v49;
    ieee80211_apply_neg_ttlm(v4, (unsigned __int16 *)&v53);
LABEL_145:
    v7 = v46;
  }
LABEL_124:
  kfree(v7);
  v38 = *(_QWORD *)(v4 + 1616);
  result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v38 + 1508) + 65), 2080);
  if ( result )
  {
    v39 = *(int *)(v38 + 1508);
    v40 = result;
    v41 = *(_QWORD *)(result + 224) + v39;
    LODWORD(v39) = *(_DWORD *)(result + 208) + v39;
    *(_QWORD *)(result + 224) = v41;
    *(_DWORD *)(result + 208) = v39;
    v42 = skb_put(result, 28);
    *(_QWORD *)(v42 + 2) = 0;
    *(_QWORD *)(v42 + 10) = 0;
    *(_QWORD *)(v42 + 18) = 0;
    *(_WORD *)(v42 + 26) = 0;
    *(_WORD *)v42 = 208;
    v43 = *(_DWORD *)(v4 + 4802);
    *(_WORD *)(v42 + 8) = *(_WORD *)(v4 + 4806);
    *(_DWORD *)(v42 + 4) = v43;
    LOWORD(v43) = *(_WORD *)(v4 + 5846);
    *(_DWORD *)(v42 + 10) = *(_DWORD *)(v4 + 5842);
    *(_WORD *)(v42 + 14) = v43;
    v44 = *(_DWORD *)(v4 + 4802);
    v45 = *(_WORD *)(v4 + 4806);
    *(_BYTE *)(v42 + 26) = v6;
    *(_DWORD *)(v42 + 16) = v44;
    *(_WORD *)(v42 + 20) = v45;
    *(_WORD *)(v42 + 24) = 293;
    if ( can_neg_ttlm )
    {
      if ( can_neg_ttlm != 1 )
      {
        if ( can_neg_ttlm == 2 )
        {
          *(_BYTE *)(v42 + 27) = -122;
          ieee80211_neg_ttlm_add_suggested_map(v40, &v48);
          goto LABEL_132;
        }
        __break(0x800u);
      }
      *(_BYTE *)(v42 + 27) = -123;
    }
    else
    {
      *(_BYTE *)(v42 + 27) = 0;
    }
LABEL_132:
    result = ieee80211_tx_skb_tid(v4, v40, 7, 0xFFFFFFFFLL);
  }
LABEL_133:
  _ReadStatusReg(SP_EL0);
  return result;
}
