const char *__fastcall v4l2_pixelfmt_name(__int64 a1, int a2)
{
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 i; // x8
  __int64 v5; // x10
  const char *result; // x0

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 320) + 3912LL) + 336LL);
  v3 = *(unsigned int *)(v2 + 8);
  if ( (_DWORD)v3 )
  {
    i = *(_QWORD *)v2 + 8LL;
    while ( *(_DWORD *)(i - 8) != a2 )
    {
      --v3;
      i += 16;
      if ( !v3 )
        goto LABEL_5;
    }
    return *(const char **)i;
  }
LABEL_5:
  v5 = *(unsigned int *)(v2 + 24);
  if ( (_DWORD)v5 )
  {
    result = "UNKNOWN";
    for ( i = *(_QWORD *)(v2 + 16) + 8LL; *(_DWORD *)(i - 8) != a2; i += 16 )
    {
      if ( !--v5 )
        return result;
    }
    return *(const char **)i;
  }
  return "UNKNOWN";
}
