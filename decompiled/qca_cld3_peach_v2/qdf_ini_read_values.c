__int64 __fastcall qdf_ini_read_values(_BYTE **a1, const char **a2, __int64 *a3, _BYTE *a4)
{
  _BYTE *j; // x23
  char v9; // w26
  __int64 v10; // x24
  _BYTE *i; // x25
  unsigned int v12; // w8
  const char *v13; // x0
  int v14; // w8
  __int64 result; // x0
  const char *v16; // x22
  const char *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x8

  j = *a1;
  if ( !**a1 )
    return 16;
  while ( 2 )
  {
    v9 = 0;
    v10 = 0;
    for ( i = j; ; ++i )
    {
      v12 = (unsigned __int8)*i;
      if ( v12 > 0x22 )
      {
        if ( v12 == 35 )
        {
          v9 = 1;
        }
        else
        {
          if ( v12 != 61 || (v10 != 0) | v9 & 1 )
            continue;
          v10 = strim(i + 1);
        }
        *i = 0;
        continue;
      }
      if ( !*i )
        goto LABEL_16;
      if ( v12 == 10 || v12 == 13 )
        break;
    }
    *i++ = 0;
LABEL_16:
    v13 = (const char *)strim(j);
    if ( v10 )
    {
      v26 = v13;
      result = 0;
      *a2 = v26;
      *a3 = v10;
      *a4 = 0;
LABEL_28:
      *a1 = i;
    }
    else
    {
      if ( !*v13 )
      {
        for ( j = i; ; ++j )
        {
          v14 = (unsigned __int8)*j;
          if ( v14 != 10 && v14 != 13 )
            break;
        }
        if ( !*j )
          return 16;
        continue;
      }
      if ( *v13 == 91 )
      {
        v16 = v13;
        v17 = &v13[strlen(v13)];
        if ( *(v17 - 1) == 93 )
        {
          *((_BYTE *)v17 - 1) = 0;
          result = 0;
          *a2 = v16 + 1;
          *a4 = 1;
          goto LABEL_28;
        }
LABEL_30:
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Invalid *.ini syntax '%s'",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "qdf_ini_read_values",
          v16);
        return 4;
      }
      else
      {
        v16 = v13;
        result = strcmp(v13, "END");
        if ( (_DWORD)result )
          goto LABEL_30;
        *((_BYTE *)v16 + 3) = 0;
        *a4 = 0;
        *a1 = i;
        *a2 = v16;
      }
    }
    return result;
  }
}
