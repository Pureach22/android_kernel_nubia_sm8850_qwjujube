__int64 telemetry_memory_deallocation()
{
  __int64 result; // x0

  kfree(fid);
  kfree(cluster_dir);
  kfree(core_dir);
  if ( telemetry )
    iounmap();
  if ( pname )
    iounmap();
  result = pvalue;
  if ( pvalue )
    return iounmap();
  return result;
}
