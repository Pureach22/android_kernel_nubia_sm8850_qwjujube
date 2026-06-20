__int64 init_module()
{
  return _cpuhp_setup_state(58, "mm/zsmalloc:prepare", 1, zs_cpu_prepare, zs_cpu_dead, 0);
}
