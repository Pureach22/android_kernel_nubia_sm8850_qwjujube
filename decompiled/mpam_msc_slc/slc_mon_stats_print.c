__int64 __fastcall slc_mon_stats_print(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x28
  _DWORD *v6; // x9
  int v8; // w23
  unsigned int v9; // w20
  _DWORD *v10; // x8
  unsigned int v11; // w8
  int v12; // w24
  __int64 v13; // x26
  int v14; // w0
  unsigned int v15; // w8
  _DWORD *v16; // x24
  unsigned int v17; // w23
  unsigned __int64 v18; // x8
  __int64 v19; // x20
  unsigned __int64 v20; // x20
  __int64 v21; // x25
  int v22; // w0
  _DWORD *v23; // x24
  unsigned int v24; // w23
  unsigned int v25; // w8
  __int64 v26; // x20
  unsigned int v27; // w20
  int v28; // w0
  __int64 v29; // x25
  _DWORD *v30; // [xsp+0h] [xbp-30h]
  _DWORD *v31; // [xsp+8h] [xbp-28h]
  _QWORD *v32; // [xsp+10h] [xbp-20h]
  _DWORD *v33; // [xsp+18h] [xbp-18h]
  int v34; // [xsp+20h] [xbp-10h]
  int v35; // [xsp+24h] [xbp-Ch]
  unsigned int *v36; // [xsp+28h] [xbp-8h]

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 || (v36 = *(unsigned int **)(v3 + 16)) == nullptr || (*(_BYTE *)(v3 + 88) & 2) == 0 )
  {
    LODWORD(v4) = -22;
    return (unsigned int)v4;
  }
  v6 = *(_DWORD **)(v3 + 64);
  v8 = 0;
  v9 = v36[8];
  v10 = v6 + 42;
  if ( v9 )
    v10 = v6 + 2;
  v32 = v10;
  v33 = v6;
  v30 = v6 + 2;
  v31 = v6 + 6;
  while ( 1 )
  {
    v11 = 0;
    while ( 1 )
    {
      v12 = *v6;
      if ( (*v6 & 1) == 0 )
        break;
      if ( ++v11 == 5001 )
        goto LABEL_80;
    }
    if ( v11 >> 3 >= 0x271 )
    {
LABEL_80:
      printk(&unk_872F);
      LODWORD(v4) = -5;
      return (unsigned int)v4;
    }
    v13 = *(_QWORD *)(v36 + 1);
    v14 = scnprintf(a3, 4096, "timestamp=%llu\n", *v32);
    v15 = *v36;
    v4 = v14;
    v34 = v12;
    v35 = v8;
    if ( v9 )
    {
      if ( v15 )
      {
        v16 = v31;
        v17 = 0;
        while ( 1 )
        {
          v18 = *(unsigned __int16 *)(v13 + 2);
          if ( !*(_WORD *)(v13 + 2) )
            goto LABEL_19;
          if ( v18 != 1 )
          {
            v20 = 0;
            v21 = 12;
            do
            {
              if ( *(_DWORD *)(*(_QWORD *)(v13 + 4) + v21) )
              {
                if ( *((_WORD *)v16 + 5) )
                {
                  if ( !v20 )
                  {
                    if ( (*((_WORD *)v16 + 5) & 0xC) != 0 )
                      v4 += (int)scnprintf(a3 + v4, 4096 - v4, "%s:\n", *(const char **)(v13 + 13));
                    if ( (*((_WORD *)v16 + 5) & 4) != 0 )
                      v4 += (int)scnprintf(
                                   a3 + v4,
                                   4096 - v4,
                                   "fe_bytes=%llu,",
                                   *((_QWORD *)v16 + 4) + *((_QWORD *)v16 + 3));
                    if ( (*((_WORD *)v16 + 5) & 8) != 0 )
                      v4 += (int)scnprintf(
                                   a3 + v4,
                                   4096 - v4,
                                   "be_bytes=%llu,",
                                   *((_QWORD *)v16 + 6) + *((_QWORD *)v16 + 5));
                    v4 = v4 - 1 + (int)scnprintf(a3 + v4 - 1, 4097 - v4, "\n");
                  }
                  if ( (*((_WORD *)v16 + 5) & 3) != 0 )
                    v4 += (int)scnprintf(a3 + v4, 4096 - v4, "%s part %d:\n", *(const char **)(v13 + 13), v20);
                  if ( (*((_WORD *)v16 + 5) & 1) != 0 )
                    v4 += (int)scnprintf(a3 + v4, 4096 - v4, "cap_cnt=%d,", v16[3]);
                  if ( (*((_WORD *)v16 + 5) & 2) != 0 )
                    v4 += (int)scnprintf(a3 + v4, 4096 - v4, "miss_cnt=%llu,", *((_QWORD *)v16 + 2));
                  v22 = scnprintf(a3 + v4 - 1, 4097 - v4, "\n");
                  v18 = *(unsigned __int16 *)(v13 + 2);
                  v4 = v4 - 1 + v22;
                }
                v16 += 22;
              }
              ++v20;
              v21 += 16;
            }
            while ( v20 < v18 );
            goto LABEL_19;
          }
          if ( *((_WORD *)v16 + 5) )
            break;
LABEL_18:
          v16 += 22;
LABEL_19:
          ++v17;
          v13 += 21;
          if ( v17 >= *v36 )
            goto LABEL_74;
        }
        v19 = v4 + (int)scnprintf(a3 + v4, 4096 - v4, "%s:\n", *(const char **)(v13 + 13));
        if ( (*((_WORD *)v16 + 5) & 1) != 0 )
        {
          v19 += (int)scnprintf(a3 + v19, 4096 - v19, "cap_cnt=%d,", v16[3]);
          if ( (*((_WORD *)v16 + 5) & 2) == 0 )
          {
LABEL_25:
            if ( (*((_WORD *)v16 + 5) & 4) == 0 )
              goto LABEL_26;
            goto LABEL_50;
          }
        }
        else if ( (*((_WORD *)v16 + 5) & 2) == 0 )
        {
          goto LABEL_25;
        }
        v19 += (int)scnprintf(a3 + v19, 4096 - v19, "miss_cnt=%llu,", *((_QWORD *)v16 + 2));
        if ( (*((_WORD *)v16 + 5) & 4) == 0 )
        {
LABEL_26:
          if ( (*((_WORD *)v16 + 5) & 8) != 0 )
            goto LABEL_51;
          goto LABEL_17;
        }
LABEL_50:
        v19 += (int)scnprintf(a3 + v19, 4096 - v19, "fe_bytes=%llu,", *((_QWORD *)v16 + 4) + *((_QWORD *)v16 + 3));
        if ( (*((_WORD *)v16 + 5) & 8) != 0 )
LABEL_51:
          v19 += (int)scnprintf(a3 + v19, 4096 - v19, "be_bytes=%llu,", *((_QWORD *)v16 + 6) + *((_QWORD *)v16 + 5));
LABEL_17:
        v4 = v19 - 1 + (int)scnprintf(a3 + v19 - 1, 4097 - v19, "\n");
        goto LABEL_18;
      }
    }
    else if ( v15 )
    {
      v23 = v30;
      v24 = 0;
      do
      {
        v25 = *(unsigned __int16 *)(v13 + 2);
        if ( *(_WORD *)(v13 + 2) )
        {
          if ( v25 == 1 )
          {
            if ( v23[3] || v23[7] )
            {
              v26 = v4 + (int)scnprintf(a3 + v4, 4096 - v4, "%s:\n", *(const char **)(v13 + 13));
              if ( v23[3] )
                v26 += (int)scnprintf(a3 + v26, 4096 - v26, "cap_cnt=%d,", v23[2]);
              if ( v23[7] )
                v26 += (int)scnprintf(a3 + v26, 4096 - v26, "miss_cnt=%llu,", *((_QWORD *)v23 + 2));
              v4 = v26 - 1 + (int)scnprintf(a3 + v26 - 1, 4097 - v26, "\n");
            }
            v23 += 8;
          }
          else
          {
            v27 = 0;
            do
            {
              if ( v23[3] || v23[7] )
              {
                v29 = v4 + (int)scnprintf(a3 + v4, 4096 - v4, "%s part %d:\n", *(const char **)(v13 + 13), v27);
                if ( v23[3] )
                  v29 += (int)scnprintf(a3 + v29, 4096 - v29, "cap_cnt=%d,", v23[2]);
                if ( v23[7] )
                  v29 += (int)scnprintf(a3 + v29, 4096 - v29, "miss_cnt=%llu,", *((_QWORD *)v23 + 2));
                v28 = scnprintf(a3 + v29 - 1, 4097 - v29, "\n");
                v25 = *(unsigned __int16 *)(v13 + 2);
                v4 = v29 - 1 + v28;
              }
              ++v27;
              v23 += 8;
            }
            while ( v27 < v25 );
          }
        }
        ++v24;
        v13 += 21;
      }
      while ( v24 < *v36 );
    }
LABEL_74:
    v6 = v33;
    if ( v34 == *v33 )
      break;
    if ( v35 == 10 )
      return (unsigned int)v4;
    v8 = v35 + 1;
    v9 = v36[8];
  }
  if ( v35 == 10 )
    LODWORD(v4) = -5;
  return (unsigned int)v4;
}
