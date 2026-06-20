__int64 __fastcall debug_symbol_lookup_name(const char *a1)
{
  char **v2; // x20
  __int64 result; // x0
  unsigned int v4; // w9
  unsigned __int64 v5; // x20
  unsigned __int8 *v6; // x10
  unsigned __int8 *v7; // x8
  int v8; // w25
  unsigned int v9; // w26
  __int64 v10; // x10
  __int64 v11; // x11
  int v12; // w15
  char *v13; // x9
  int v14; // w14
  unsigned __int64 v15; // x12
  unsigned int v16; // t1
  __int64 v17; // x16
  char v18; // w17
  unsigned __int8 *v19; // x15
  unsigned __int64 v20; // x16
  int v21; // t1
  char s[512]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v23; // [xsp+208h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !*a1 )
  {
LABEL_38:
    result = 0;
    goto LABEL_39;
  }
  v2 = &ds_entries;
  if ( strcmp(a1, ds_entries) )
  {
    v2 = &off_30;
    if ( strcmp(a1, off_30) )
    {
      v2 = &off_40;
      if ( strcmp(a1, off_40) )
      {
        v2 = &off_50;
        if ( strcmp(a1, off_50) )
        {
          v2 = &off_60;
          if ( strcmp(a1, off_60) )
          {
            v2 = &off_70;
            if ( strcmp(a1, off_70) )
            {
              v2 = (char **)&off_80;
              if ( strcmp(a1, (const char *)off_80) )
              {
                v2 = &off_90;
                if ( strcmp(a1, off_90) )
                {
                  v2 = &off_A0;
                  if ( strcmp(a1, off_A0) )
                  {
                    v2 = &off_B0;
                    if ( strcmp(a1, off_B0) )
                    {
                      v2 = &off_C0;
                      if ( strcmp(a1, off_C0) )
                        goto LABEL_14;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  result = (__int64)v2[1];
  if ( !result )
  {
LABEL_14:
    if ( !debug_symbol_3 )
      goto LABEL_38;
    v4 = 0;
    v5 = 0;
LABEL_16:
    v6 = (unsigned __int8 *)(debug_symbol_2 + v4);
    v7 = v6 + 1;
    v8 = *v6;
    if ( (char)*v6 < 0 )
    {
      v9 = v4 + 2;
      v8 = v8 & 0x7F | (v6[1] << 7);
      v7 = v6 + 2;
      if ( !v8 )
      {
LABEL_34:
        v13 = s;
LABEL_35:
        *v13 = 0;
        goto LABEL_36;
      }
    }
    else
    {
      v9 = v4 + 1;
      if ( !*v6 )
        goto LABEL_34;
    }
    v10 = debug_symbol_5;
    v11 = debug_symbol_6;
    v12 = 0;
    v13 = s;
    v14 = v8;
    v15 = 512;
    while ( 1 )
    {
      v16 = *v7++;
      v17 = *(unsigned __int16 *)(v11 + 2LL * v16);
      if ( *(_BYTE *)(v10 + v17) )
      {
        if ( v12 )
        {
          if ( v15 < 2 )
            goto LABEL_31;
          --v15;
          *v13++ = *(_BYTE *)(v10 + v17);
        }
        v18 = *(_BYTE *)(v10 + v17 + 1);
        if ( v18 )
        {
          v19 = (unsigned __int8 *)(v10 + 2 + v17);
          v20 = v15;
          while ( v20 >= 2 )
          {
            *v13++ = v18;
            --v20;
            v21 = *v19++;
            v18 = v21;
            if ( !v21 )
            {
              v12 = 1;
              v15 = v20;
              goto LABEL_20;
            }
          }
          v15 = v15 != 0;
LABEL_31:
          if ( v15 )
            goto LABEL_35;
LABEL_36:
          if ( strcmp(s, a1) )
          {
            ++v5;
            v4 = v8 + v9;
            if ( v5 >= (unsigned int)debug_symbol_3 )
              goto LABEL_38;
            goto LABEL_16;
          }
          result = debug_symbol_4 + *(unsigned int *)(debug_symbol_1 + 4LL * (int)v5);
          break;
        }
        v12 = 1;
      }
LABEL_20:
      if ( !--v14 )
        goto LABEL_31;
    }
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
