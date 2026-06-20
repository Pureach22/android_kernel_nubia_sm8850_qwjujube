__int64 __fastcall fastrpc_get_static_pd_session(__int64 a1, unsigned int *a2)
{
  _QWORD *v4; // x21
  const char *v5; // x8
  const char *v6; // x1
  const char *v7; // x1
  const char *v8; // x1
  unsigned int v10; // w8

  v4 = (_QWORD *)(*(_QWORD *)(a1 + 128) + 49152LL);
  v5 = *(const char **)(*(_QWORD *)(a1 + 128) + 51376LL);
  if ( v5 && !strcmp(*(const char **)(a1 + 312), v5) )
  {
    v10 = 0;
  }
  else
  {
    v6 = (const char *)v4[285];
    if ( v6 && !strcmp(*(const char **)(a1 + 312), v6) )
    {
      v10 = 1;
    }
    else
    {
      v7 = (const char *)v4[292];
      if ( v7 && !strcmp(*(const char **)(a1 + 312), v7) )
      {
        v10 = 2;
      }
      else
      {
        v8 = (const char *)v4[299];
        if ( !v8 || strcmp(*(const char **)(a1 + 312), v8) )
          return 4294967209LL;
        v10 = 3;
      }
    }
  }
  *a2 = v10;
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 128) + 56LL * v10 + 51416) )
    return 0;
  else
    return 4294967189LL;
}
