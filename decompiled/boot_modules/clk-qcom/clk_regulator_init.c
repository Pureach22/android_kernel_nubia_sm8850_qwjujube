unsigned __int64 __fastcall clk_regulator_init(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  __int64 v5; // x9
  unsigned int v6; // w23
  int i; // w22
  __int64 v8; // x24
  int v9; // w9
  __int64 v10; // x25
  const char *v11; // x21
  unsigned __int64 result; // x0
  __int64 v13; // x21
  unsigned __int64 v14; // x20
  unsigned __int64 v15; // x24

  v2 = *(_QWORD *)(a2 + 96);
  if ( !v2 )
    return 0;
  v5 = 0;
  v6 = 0;
  for ( i = 1; ; ++i )
  {
    v8 = *(_QWORD *)(*(_QWORD *)(a2 + 88) + 8 * v5);
    v9 = *(_DWORD *)(v8 + 24);
    if ( v9 >= 1 )
      break;
LABEL_4:
    v5 = (int)++v6;
    if ( v2 <= (int)v6 )
      return 0;
  }
  v10 = 0;
  while ( *(_QWORD *)(*(_QWORD *)(v8 + 8) + 8 * v10) )
  {
LABEL_7:
    if ( ++v10 >= v9 )
    {
      v2 = *(_QWORD *)(a2 + 96);
      goto LABEL_4;
    }
  }
  v11 = *(const char **)(*(_QWORD *)(v8 + 16) + 8 * v10);
  result = devm_regulator_get(a1, v11);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(*(_QWORD *)(v8 + 8) + 8 * v10) = result;
    v9 = *(_DWORD *)(v8 + 24);
    goto LABEL_7;
  }
  if ( result == -517 )
  {
    if ( (v6 & 0x80000000) == 0 )
    {
LABEL_13:
      v13 = 8LL * v6;
      v14 = result;
      do
      {
        memset(
          *(void **)(*(_QWORD *)(*(_QWORD *)(a2 + 88) + v13) + 8LL),
          0,
          8LL * *(int *)(*(_QWORD *)(*(_QWORD *)(a2 + 88) + v13) + 24LL));
        --i;
        v13 -= 8;
      }
      while ( i > 0 );
      return v14;
    }
  }
  else
  {
    v15 = result;
    dev_err(a1, "%s error %s regulator\n", "clk_regulator_init", v11);
    result = v15;
    if ( (v6 & 0x80000000) == 0 )
      goto LABEL_13;
  }
  return result;
}
