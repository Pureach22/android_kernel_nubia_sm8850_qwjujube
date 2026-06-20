__int64 __fastcall btfm_slim_dai_get_channel_map(__int64 a1, int *a2, _DWORD *a3, int *a4, _DWORD *a5, unsigned int a6)
{
  __int64 v6; // x10
  char v7; // w8
  int v8; // w9
  int *v9; // x10
  int v10; // w11
  _DWORD *v11; // x12
  int v12; // w11
  int *v13; // x9
  int *v15; // x8
  int v16; // w10
  void *v17; // x0
  void *v18; // x0

  v6 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  if ( !v6 )
    return 4294967274LL;
  if ( a6 - 2 >= 2 )
  {
    if ( a6 == 1 )
    {
      v7 = 1;
      v8 = 1;
    }
    else
    {
      if ( a6 )
      {
        v17 = &unk_8659;
        goto LABEL_44;
      }
      v7 = 0;
      v8 = 2;
    }
    if ( a2 && a3 )
    {
      v9 = *(int **)(v6 + 1104);
      if ( v9 )
      {
        v10 = 0;
        v11 = a5;
        goto LABEL_15;
      }
      return 4294967274LL;
    }
    v18 = &unk_8404;
LABEL_42:
    printk(v18, "btfm_slim_dai_get_channel_map", a3);
    return 4294967274LL;
  }
  if ( !a4 || !a5 )
  {
    v18 = &unk_85D7;
    a3 = a5;
    goto LABEL_42;
  }
  v9 = *(int **)(v6 + 1096);
  if ( v9 )
  {
    v8 = 0;
    v10 = 1;
    v11 = a3;
    v7 = 1;
    a3 = a5;
LABEL_15:
    *v11 = 0;
    *a2 = v8;
    *a4 = v10;
    v12 = *v9;
    if ( *v9 == 4 || v12 == a6 )
    {
      v13 = v9;
    }
    else
    {
      v13 = v9 + 18;
      v12 = v9[18];
      if ( v12 != 4 && v12 != a6 )
      {
        v13 = v9 + 36;
        v12 = v9[36];
        if ( v12 != 4 && v12 != a6 )
        {
          v12 = v9[54];
          v13 = v9 + 54;
          if ( v12 != 4 && v12 != a6 )
          {
LABEL_39:
            v17 = &unk_8C58;
LABEL_44:
            printk(v17, "btfm_slim_dai_get_channel_map", a6);
            return 4294967274LL;
          }
        }
      }
    }
    if ( v12 != 4 )
    {
      *a3 = *((unsigned __int8 *)v13 + 18);
      if ( (v7 & 1) != 0 )
        return 0;
      v15 = v13 + 18;
      if ( v13 == (int *)-72LL )
        return 4294967274LL;
      v16 = *v15;
      if ( *v15 == 4
        || v16 == a6
        || (v15 = v13 + 36, v16 = v13[36], v16 == 4)
        || v16 == a6
        || (v15 = v13 + 54, v16 = v13[54], v16 == 4)
        || v16 == a6
        || (v16 = v13[72], v15 = v13 + 72, v16 == 4)
        || v16 == a6 )
      {
        if ( v16 != 4 )
        {
          a3[1] = *((unsigned __int8 *)v15 + 18);
          return 0;
        }
      }
    }
    goto LABEL_39;
  }
  return 4294967274LL;
}
