__int64 __fastcall cscfg_cfg_feature_refs_show(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v4; // x23
  __int64 v5; // x20
  int v6; // w0

  v2 = *(_QWORD *)(a1 - 8);
  if ( *(int *)(v2 + 32) < 1 )
    return 0;
  v4 = 0;
  v5 = 0;
  do
  {
    v6 = scnprintf(a2 + v5, 4096 - v5, "%s\n", *(const char **)(*(_QWORD *)(v2 + 40) + 8 * v4++));
    v5 += v6;
  }
  while ( v4 < *(int *)(v2 + 32) );
  return v5;
}
