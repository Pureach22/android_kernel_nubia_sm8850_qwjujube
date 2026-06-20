// Alternative name is 'cleanup_module'
__int64 gh_vcpu_mgr_exit()
{
  __int64 result; // x0

  xa_destroy(gh_vms + 8);
  xa_destroy(gh_vms + 48);
  xa_destroy(gh_vms + 88);
  xa_destroy(gh_vms + 128);
  xa_destroy(gh_vms + 168);
  result = kfree(gh_vms);
  init_done = 0;
  return result;
}
