__int64 __fastcall get_ss_symbol_from_rproc_name(__int64 a1)
{
  __int64 v1; // x8
  const char *v2; // x19

  if ( !a1 )
    return 57;
  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
    return 57;
  v2 = *(const char **)(v1 + 24);
  if ( !v2 )
    return 57;
  if ( strstr(*(const char **)(v1 + 24), "remoteproc-mss") )
    return 77;
  if ( strstr(v2, "remoteproc-adsp") )
    return 65;
  if ( strstr(v2, "remoteproc-slpi") )
    return 83;
  if ( strstr(v2, "remoteproc-cdsp") )
    return 67;
  if ( strstr(v2, "remoteproc-spss") )
    return 69;
  if ( strstr(v2, "remoteproc-soccp") )
    return 79;
  return 85;
}
