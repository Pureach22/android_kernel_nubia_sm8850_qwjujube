__int64 init_module()
{
  return _platform_driver_register(gh_tlmm_vm_mem_access_driver, &_this_module);
}
