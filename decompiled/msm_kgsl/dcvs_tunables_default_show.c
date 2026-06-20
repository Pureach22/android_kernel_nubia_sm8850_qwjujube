__int64 __fastcall dcvs_tunables_default_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x23
  __int64 v5; // x20
  __int64 v6; // x25

  v4 = 0;
  v5 = 0;
  v6 = a1 + 232;
  do
  {
    if ( (unsigned __int64)(v4 - 15) >= 3 )
      v5 += (int)scnprintf(
                   a3 + v5,
                   4096 - v5,
                   "%30s: %10d          Status: %s\n",
                   dcvs_tunables_strings[v4],
                   *(_DWORD *)(v6 + 4 * v4),
                   "Active");
    ++v4;
  }
  while ( v4 != 17 );
  return v5;
}
