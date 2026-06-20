__int64 cleanup_module()
{
  return platform_driver_unregister(gh_tlmm_vm_mem_access_driver);
}
