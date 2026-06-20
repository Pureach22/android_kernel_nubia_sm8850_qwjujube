__int64 __fastcall sink_name_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  const char *v4; // x3
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 936);
  if ( v3 )
  {
    v4 = *(const char **)(v3 + 168);
    if ( !v4 )
      v4 = *(const char **)(v3 + 56);
    LODWORD(result) = scnprintf(a3, 4096, "%s\n", v4);
  }
  else
  {
    LODWORD(result) = scnprintf(a3, 4096, "\n");
  }
  return (int)result;
}
