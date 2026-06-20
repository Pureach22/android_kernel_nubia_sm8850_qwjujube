__int64 __fastcall msm_minidump_clear_headers(char *s2)
{
  __int64 v2; // x11
  __int64 v3; // x8
  __int64 v4; // x24
  _QWORD *v5; // x25
  __int64 v6; // x28
  __int64 v7; // x26
  __int64 v8; // x23
  unsigned __int64 v9; // x21
  _QWORD *v10; // x27
  _QWORD *v11; // x22
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  char *v14; // x20
  int v15; // w0
  int v16; // w19
  int v17; // w8
  bool v18; // cc
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x10
  _QWORD *v22; // x11
  __int64 v23; // x12
  __int64 v24; // x14
  __int64 v25; // x12
  __int64 v26; // x15
  __int64 v27; // x14
  __int64 v29; // x1
  _QWORD *v30; // x8
  __int64 v31; // x8
  unsigned __int64 v32; // x9
  __int64 v33; // x10
  _QWORD *v34; // x11
  __int64 v35; // x12
  __int64 v36; // x13
  __int64 v37; // x14
  __int64 v38; // x15
  __int64 v39; // x16
  __int64 v40; // x12
  __int64 v41; // x14
  _QWORD *v42; // x8
  __int64 v43; // x10
  __int64 v44; // [xsp+0h] [xbp-10h]
  __int64 v45; // [xsp+8h] [xbp-8h]

  v2 = minidump_elfheader;
  v3 = *(unsigned __int16 *)(minidump_elfheader + 56);
  if ( !*(_WORD *)(minidump_elfheader + 56) )
    goto LABEL_28;
  v4 = 0;
  v5 = (_QWORD *)(*(_QWORD *)(minidump_elfheader + 32) + minidump_elfheader);
  while ( v5[3] != *((_QWORD *)s2 + 4) || v5[5] != *((_QWORD *)s2 + 5) )
  {
    ++v4;
    v5 += 7;
    if ( v3 == v4 )
      goto LABEL_28;
  }
  if ( (_DWORD)v4 == (_DWORD)v3 )
    goto LABEL_28;
  v6 = *(unsigned __int16 *)(minidump_elfheader + 60);
  v44 = *((_QWORD *)s2 + 5);
  v45 = minidump_elfheader;
  if ( !*(_WORD *)(minidump_elfheader + 60) )
    goto LABEL_28;
  v7 = *(unsigned __int16 *)(minidump_elfheader + 62);
  v8 = 0;
  v9 = qword_10040;
  v10 = (_QWORD *)(*(_QWORD *)(minidump_elfheader + 40) + minidump_elfheader);
  v11 = &v10[8 * v7];
  while ( 1 )
  {
    if ( (_DWORD)v7 )
    {
      v12 = v2 + v11[3];
      if ( v12 )
      {
        v13 = *(int *)v10;
        if ( v9 >= v13 )
        {
          v14 = (char *)(v12 + v13);
          if ( v12 + v13 )
          {
            v15 = strcmp((const char *)(v12 + v13), s2);
            v2 = v45;
            if ( !v15 && v10[2] == *((_QWORD *)s2 + 3) && v10[4] == v44 )
              break;
          }
        }
      }
    }
    ++v8;
    v10 += 8;
    if ( v6 == v8 )
      goto LABEL_28;
  }
  if ( (_DWORD)v8 == (_DWORD)v6 )
  {
LABEL_28:
    printk_deferred("Cannot find entry in elf\n");
    return 4294967274LL;
  }
  if ( v10[3] != v5[1] )
  {
    printk_deferred("Invalid entry details in elf, Minidump broken..\n");
    return 4294967274LL;
  }
  v16 = strlen(v14) + 1;
  memmove(v14, &v14[v16], qword_10040 - *(unsigned int *)v10);
  v17 = *(unsigned __int16 *)(v45 + 56);
  qword_10040 -= v16;
  v18 = (int)v4 < v17 - 1;
  v19 = (unsigned int)v4;
  if ( v18 )
  {
    v29 = v44;
    v20 = 56LL * (unsigned int)v4;
    do
    {
      ++v19;
      v21 = *(_QWORD *)(v45 + 32) + v45;
      v22 = (_QWORD *)(v21 + v20);
      v20 += 56;
      v23 = v22[13];
      v22[5] = v22[12];
      v22[6] = v23;
      v24 = v22[11];
      v26 = v22[8];
      v25 = v22[9];
      v22[3] = v22[10];
      v22[4] = v24;
      v27 = v22[7];
      v22[2] = v25;
      *v22 = v27;
      v22[1] = v26 - v44;
    }
    while ( v19 < *(unsigned __int16 *)(v45 + 56) - 1LL );
    v30 = (_QWORD *)(v21 + v20);
  }
  else
  {
    v29 = v44;
    v30 = (_QWORD *)(*(_QWORD *)(v45 + 32) + v45 + 56LL * (unsigned int)v4);
  }
  v30[5] = 0;
  v30[6] = 0;
  v30[3] = 0;
  v30[4] = 0;
  v30[1] = 0;
  v30[2] = 0;
  *v30 = 0;
  v18 = (int)v8 < *(unsigned __int16 *)(v45 + 60) - 1;
  v31 = (unsigned int)v8;
  --*(_WORD *)(v45 + 56);
  if ( v18 )
  {
    v32 = (unsigned __int64)(unsigned int)v8 << 6;
    do
    {
      ++v31;
      v33 = *(_QWORD *)(v45 + 40) + v45;
      v34 = (_QWORD *)(v33 + v32);
      v32 += 64LL;
      v35 = v34[15];
      v36 = v34[8];
      v37 = v34[9];
      v34[6] = v34[14];
      v34[7] = v35;
      v38 = v34[10];
      v39 = v34[11];
      *v34 = v36;
      v34[1] = v37;
      v41 = v34[12];
      v40 = v34[13];
      *(_DWORD *)v34 = v36 - v16;
      v34[4] = v41;
      v34[5] = v40;
      v34[2] = v38;
      v34[3] = v39 - v29;
    }
    while ( v31 < *(unsigned __int16 *)(v45 + 60) - 1LL );
    v42 = (_QWORD *)(v33 + v32);
  }
  else
  {
    v42 = (_QWORD *)(*(_QWORD *)(v45 + 40) + v45 + ((unsigned __int64)(unsigned int)v8 << 6));
  }
  v42[6] = 0;
  v42[7] = 0;
  v42[4] = 0;
  v42[5] = 0;
  v42[2] = 0;
  v42[3] = 0;
  *v42 = 0;
  v42[1] = 0;
  v43 = qword_10038;
  --*(_WORD *)(v45 + 60);
  qword_10038 = v43 - v29;
  return 0;
}
