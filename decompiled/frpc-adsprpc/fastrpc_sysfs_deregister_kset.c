__int64 fastrpc_sysfs_deregister_kset()
{
  __int64 result; // x0

  result = fastrpc_kset;
  if ( fastrpc_kset )
    return kset_unregister();
  return result;
}
