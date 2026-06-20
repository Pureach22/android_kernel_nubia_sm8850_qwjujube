__int64 __fastcall coresight_get_aggre_atid(_QWORD *a1)
{
  const char *v1; // x20
  size_t v3; // x0
  __int64 result; // x0
  const char *v5; // x20
  size_t v6; // x0
  __int64 v7; // x8
  __int64 i; // x20
  __int64 v9; // x0

  v1 = (const char *)a1[21];
  if ( !v1 )
    v1 = (const char *)a1[7];
  v3 = strlen(v1);
  if ( strnstr(v1, "tpda", v3) )
    return *(unsigned __int8 *)(*(_QWORD *)(a1[19] + 152LL) + 28LL);
  v5 = (const char *)a1[21];
  if ( !v5 )
    v5 = (const char *)a1[7];
  v6 = strlen(v5);
  if ( !strnstr(v5, "tracenoc", v6) || (result = *(unsigned int *)(*(_QWORD *)(a1[19] + 152LL) + 36LL), !(_DWORD)result) )
  {
    v7 = *a1;
    if ( *(int *)(*a1 + 4LL) >= 1 )
    {
      for ( i = 0; i < *(int *)(v7 + 4); ++i )
      {
        v9 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 8) + 8 * i) + 16LL);
        if ( v9 )
        {
          result = coresight_get_aggre_atid(v9);
          if ( (int)result > 0 )
            return result;
          v7 = *a1;
        }
      }
    }
    return 4294967274LL;
  }
  return result;
}
