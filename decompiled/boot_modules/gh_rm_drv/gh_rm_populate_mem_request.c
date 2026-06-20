char *__fastcall gh_rm_populate_mem_request(
        char *result,
        int a2,
        unsigned int *a3,
        unsigned int *a4,
        __int16 a5,
        unsigned __int16 *a6)
{
  __int64 v6; // x8
  unsigned int v7; // w9
  int v8; // w10
  __int64 v9; // x11
  __int64 v10; // x9
  char *v11; // x12
  char *v12; // x8
  __int64 v13; // x10
  _BYTE *v14; // x12
  char *v15; // x11
  char v16; // t1
  char *v17; // x19
  unsigned int v18; // w10
  int v19; // w9
  unsigned __int16 *v20; // x20
  __int64 v21; // x8

  if ( a3 )
  {
    v6 = 4LL * *a3 + 4;
    if ( a4 )
    {
LABEL_3:
      v7 = *a4;
      goto LABEL_6;
    }
  }
  else
  {
    v6 = 4;
    if ( a4 )
      goto LABEL_3;
  }
  v7 = 0;
LABEL_6:
  if ( v7 >= 0x200 )
    v7 = 512;
  v8 = a2 - 1358954512;
  if ( (unsigned int)(a2 - 1358954512) <= 0xA && ((0x40Fu >> v8) & 1) != 0 )
  {
    v9 = qword_14180[v8];
    v10 = (16 * v7) | 4;
    v11 = &result[v9];
    v12 = &result[v9 + v6];
    if ( a3 )
    {
      v13 = *a3;
      *(_DWORD *)v11 = v13;
      if ( (_DWORD)v13 )
      {
        v14 = (char *)a3 + 6;
        v15 = &result[v9 + 6];
        do
        {
          --v13;
          *((_WORD *)v15 - 1) = *((_WORD *)v14 - 1);
          v16 = *v14;
          v14 += 4;
          *v15 = v16;
          v15 += 4;
        }
        while ( v13 );
      }
      v17 = &v12[v10];
      if ( a4 )
      {
LABEL_15:
        v18 = *a4;
        *((_WORD *)v12 + 1) = a5;
        if ( v18 >= 0x200 )
          v19 = 512;
        else
          v19 = v18;
        *(_WORD *)v12 = v19;
        if ( v18 )
        {
          v20 = a6;
          result = (char *)memcpy(v12 + 4, (char *)a4 + 6, (unsigned int)(16 * v19));
          a6 = v20;
        }
        if ( a6 )
          goto LABEL_21;
        goto LABEL_25;
      }
    }
    else
    {
      *(_DWORD *)v11 = 0;
      v17 = &v12[v10];
      if ( a4 )
        goto LABEL_15;
    }
    *(_WORD *)v12 = 0;
    *((_WORD *)v12 + 1) = a5;
    if ( a6 )
    {
LABEL_21:
      v21 = *a6;
      *(_WORD *)v17 = v21;
      if ( v21 )
        return (char *)memcpy(v17 + 4, a6 + 2, 4 * v21);
      return result;
    }
LABEL_25:
    *(_WORD *)v17 = 0;
  }
  return result;
}
