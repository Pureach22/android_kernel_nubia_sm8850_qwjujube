__int64 __fastcall coresight_validate_sink(__int64 a1, __int64 a2)
{
  const char *v5; // x2

  if ( (of_coresight_secure_node(a2) & 1) == 0 || (of_coresight_secure_node(a1) & 1) != 0 )
    return 0;
  v5 = *(const char **)(a1 + 168);
  if ( !v5 )
    v5 = *(const char **)(a1 + 56);
  dev_err(a2 + 56, "dont support this source: %s\n", v5);
  return 4294967274LL;
}
