__int64 __fastcall sched_get_cluster_util_pct(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(unsigned int *)(a1 + 32);
  if ( (int)v1 > 3 )
    return 0;
  if ( (unsigned int)v1 >= 4 )
  {
    __break(0x5512u);
    JUMPOUT(0x2E794);
  }
  return cstats_util_pct[v1];
}
