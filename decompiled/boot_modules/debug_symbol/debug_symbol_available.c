__int64 debug_symbol_available()
{
  __int64 result; // x0
  __int64 v1; // x14
  __int64 v2; // x12
  __int64 v3; // x13
  int v4; // w19
  __int64 v5; // x9
  __int64 v6; // x11
  __int64 v7; // x8
  unsigned int v8; // w9
  unsigned __int64 i; // x25
  unsigned __int8 *v10; // x10
  unsigned __int8 *v11; // x8
  int v12; // w27
  unsigned int v13; // w28
  int v14; // w15
  int v15; // w14
  __int64 v16; // x10
  unsigned __int64 v17; // x12
  __int64 v18; // x11
  char *v19; // x9
  __int64 v20; // x13
  unsigned int v21; // t1
  __int64 v22; // x16
  char v23; // w17
  unsigned __int8 *v24; // x15
  unsigned __int64 v25; // x16
  int v26; // t1
  __int64 v27; // x23
  __int64 v28; // x19
  __int64 v29; // x24
  char **v30; // x20
  char v31[512]; // [xsp+0h] [xbp-210h] BYREF
  __int64 v32; // [xsp+200h] [xbp-10h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( debug_symbol_vaddr && *(_DWORD *)debug_symbol_vaddr == -856760833 )
  {
    if ( !debug_symbol_0 )
    {
      v1 = *(_QWORD *)(debug_symbol_vaddr + 24);
      v2 = *(_QWORD *)(debug_symbol_vaddr + 80);
      v3 = *(_QWORD *)(debug_symbol_vaddr + 88);
      v4 = *(_DWORD *)(debug_symbol_vaddr + 12);
      debug_symbol_0 = kimage_voffset + *(_QWORD *)(debug_symbol_vaddr + 32);
      debug_symbol_2 = v3 + kimage_voffset;
      debug_symbol_4 = v1 + kimage_voffset;
      v6 = *(_QWORD *)(debug_symbol_vaddr + 96);
      v5 = *(_QWORD *)(debug_symbol_vaddr + 104);
      debug_symbol_1 = v2 + kimage_voffset;
      v7 = *(_QWORD *)(debug_symbol_vaddr + 112);
      debug_symbol_3 = v4;
      debug_symbol_5 = v6 + kimage_voffset;
      debug_symbol_6 = v5 + kimage_voffset;
      debug_symbol_7 = v7 + kimage_voffset;
      memset(v31, 0, sizeof(v31));
      if ( v4 )
      {
        v8 = 0;
        for ( i = 0; i < (unsigned int)debug_symbol_3; ++i )
        {
          v10 = (unsigned __int8 *)(debug_symbol_2 + v8);
          v11 = v10 + 1;
          v12 = *v10;
          if ( (char)*v10 < 0 )
          {
            v13 = v8 + 2;
            v12 = v12 & 0x7F | (v10[1] << 7);
            v11 = v10 + 2;
            if ( !v12 )
            {
LABEL_28:
              v19 = v31;
LABEL_29:
              *v19 = 0;
              goto LABEL_30;
            }
          }
          else
          {
            v13 = v8 + 1;
            if ( !*v10 )
              goto LABEL_28;
          }
          v14 = 0;
          v15 = v12;
          v16 = debug_symbol_5;
          v17 = 512;
          v18 = debug_symbol_6;
          v19 = v31;
          v20 = debug_symbol_5 + 2;
          while ( 1 )
          {
            v21 = *v11++;
            v22 = *(unsigned __int16 *)(v18 + 2LL * v21);
            if ( !*(_BYTE *)(v16 + v22) )
              goto LABEL_14;
            if ( v14 )
            {
              if ( v17 < 2 )
                goto LABEL_25;
              --v17;
              *v19++ = *(_BYTE *)(v16 + v22);
            }
            v23 = *(_BYTE *)(v16 + v22 + 1);
            if ( v23 )
              break;
            v14 = 1;
LABEL_14:
            if ( !--v15 )
              goto LABEL_25;
          }
          v24 = (unsigned __int8 *)(v20 + v22);
          v25 = v17;
          while ( v25 >= 2 )
          {
            *v19++ = v23;
            --v25;
            v26 = *v24++;
            v23 = v26;
            if ( !v26 )
            {
              v14 = 1;
              v17 = v25;
              goto LABEL_14;
            }
          }
          v17 = v17 != 0;
LABEL_25:
          if ( v17 )
            goto LABEL_29;
LABEL_30:
          v27 = debug_symbol_4;
          v28 = 0;
          v29 = debug_symbol_1;
          do
          {
            v30 = &(&ds_entries)[v28];
            if ( !(&ds_entries)[v28 + 1] && !strcmp(v31, *v30) )
              v30[1] = (char *)(v27 + *(unsigned int *)(v29 + 4LL * (int)i));
            v28 += 2;
          }
          while ( v28 != 22 );
          v8 = v12 + v13;
        }
      }
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
