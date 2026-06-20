__int64 __fastcall kgsl_mmu_dev_remove(__int64 a1)
{
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760)) )
    return component_del(a1 + 16, kgsl_mmu_cb_component_ops);
  component_del(a1 + 16, kgsl_mmu_component_ops);
  return of_platform_depopulate(a1 + 16);
}
