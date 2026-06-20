__int64 cleanup_module()
{
  __int64 v0; // x19
  __int64 result; // x0

  gunyah_qtvm_unregister_notifier(&gh_hvc_vm_nb);
  gh_rm_unregister_notifier(&gh_hvc_nb);
  v0 = 0x1FFFFFFFFFFFFAC4LL;
  do
  {
    result = gh_hvc_data[v0 + 1340];
    if ( result )
    {
      result = hvc_remove(result);
      gh_hvc_data[v0 + 1340] = 0;
    }
    v0 += 268;
  }
  while ( v0 * 8 );
  return result;
}
