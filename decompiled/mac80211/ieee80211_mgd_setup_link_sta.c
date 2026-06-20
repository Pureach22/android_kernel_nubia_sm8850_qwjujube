__int64 __fastcall ieee80211_mgd_setup_link_sta(__int64 *a1, __int64 a2, __int64 a3, unsigned int **a4)
{
  int v4; // w11
  __int64 v5; // x10
  __int64 v6; // x8
  int v7; // w11
  __int64 v8; // x11
  unsigned int v9; // w8
  int v10; // w8
  int v11; // w21
  __int64 v12; // x22
  char v13; // w19
  int v14; // w9
  __int64 v15; // x10
  int v16; // w23
  int v17; // w11
  __int64 v18; // x20
  __int64 v19; // x1
  int v20; // w16
  int v21; // w16
  unsigned int v22; // w1
  bool v23; // w15
  __int64 v25; // x5
  int v26; // w4
  __int64 v27; // x17
  unsigned __int16 *v28; // x6
  int v29; // t1
  __int64 v30; // x8
  __int64 v32; // x8
  __int64 v33; // x8
  unsigned int **v34; // x24
  __int64 v35; // x25
  __int64 *v36; // x26
  __int64 v37; // x9
  __int64 *v38; // x21

  v4 = *((_DWORD *)a4 + 18);
  v5 = *(_QWORD *)(*a1 + 1616);
  *(_WORD *)(a3 + 4) = *((_WORD *)a4 + 38);
  v6 = *(_QWORD *)(a3 + 920);
  *(_DWORD *)a3 = v4;
  v7 = *((_DWORD *)a4 + 18);
  *(_WORD *)(v6 + 12) = *((_WORD *)a4 + 38);
  *(_DWORD *)(v6 + 8) = v7;
  v8 = **a4;
  if ( (_DWORD)v8 == 4 )
  {
    ieee80211_s1g_sta_rate_init(a2);
    return 0;
  }
  if ( (unsigned int)v8 >= 6 )
    goto LABEL_39;
  v10 = *((_DWORD *)a4 + 36);
  if ( !v10 )
    goto LABEL_27;
  v11 = 0;
  LODWORD(v12) = 0;
  v13 = 0;
  v14 = 0;
  v15 = *(_QWORD *)(v5 + 72) + 8 * v8;
  v16 = -1;
  v17 = 0x7FFFFFFF;
  v18 = *(_QWORD *)(v15 + 328);
  do
  {
    v21 = *((unsigned __int8 *)a4 + v14 + 106);
    v22 = v21 & 0x7F;
    v23 = v22 > 0x16;
    if ( (unsigned int)(v21 - 249) > 6 || ((1 << (v21 + 7)) & 0x67) == 0 )
    {
      v25 = *(unsigned int *)(v18 + 24);
      if ( (int)v25 >= 1 )
      {
        v26 = 5 * v22;
        v27 = 0;
        v28 = (unsigned __int16 *)(*(_QWORD *)(v18 + 8) + 4LL);
        while ( 1 )
        {
          v29 = *v28;
          v28 += 6;
          if ( (858993460 * (unsigned __int64)(unsigned int)(v29 + 4)) >> 32 == v22 )
            break;
          if ( v25 == ++v27 )
            goto LABEL_9;
        }
        v19 = 1LL << v27;
        v20 = v21 << 24;
        if ( v26 < v17 )
        {
          v17 = v26;
          v16 = v27;
        }
        v11 |= v19;
        LODWORD(v12) = v19 & (v20 >> 31) | v12;
      }
    }
LABEL_9:
    ++v14;
    v13 |= v23;
  }
  while ( v14 != v10 );
  if ( v16 < 0 )
  {
LABEL_27:
    v32 = *a1;
    if ( *(_WORD *)(*a1 + 5800) )
      printk(&unk_BACB8, v32 + 1640, *((unsigned int *)a1 + 2), a4);
    else
      printk(&unk_B9895, v32 + 1640, a3, a4);
    return (unsigned int)-22;
  }
  if ( (_DWORD)v12 )
  {
    if ( v11 )
      goto LABEL_23;
LABEL_35:
    v37 = *a1;
    v38 = a1;
    if ( *(_WORD *)(*a1 + 5800) )
      printk(&unk_BC38B, v37 + 1640, *((unsigned int *)a1 + 2), a4);
    else
      printk(&unk_BBD02, v37 + 1640, a3, a4);
    a1 = v38;
    goto LABEL_25;
  }
  v33 = *a1;
  v34 = a4;
  v35 = a3;
  v36 = a1;
  if ( *(_WORD *)(*a1 + 5800) )
    printk(&unk_B8EF1, v33 + 1640, *((unsigned int *)a1 + 2), a4);
  else
    printk(&unk_B9A92, v33 + 1640, a3, a4);
  a1 = v36;
  a3 = v35;
  v12 = 1LL << v16;
  a4 = v34;
  if ( !v11 )
    goto LABEL_35;
LABEL_23:
  v30 = **a4;
  if ( (unsigned int)v30 <= 5 )
  {
    *(_DWORD *)(*(_QWORD *)(a3 + 920) + 4 * v30 + 20) = v11;
LABEL_25:
    v9 = 0;
    *(_DWORD *)(a1[118] + 72) = v12;
    *((_BYTE *)a1 + 136) = (*(_DWORD *)(v18 + 16) == 0) & v13;
    return v9;
  }
LABEL_39:
  __break(0x5512u);
  return ieee80211_chswitch_post_beacon(a1);
}
