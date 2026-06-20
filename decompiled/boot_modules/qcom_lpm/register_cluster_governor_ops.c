__int64 __fastcall register_cluster_governor_ops(__int64 result)
{
  if ( result )
    cluster_gov_ops = result;
  return result;
}
