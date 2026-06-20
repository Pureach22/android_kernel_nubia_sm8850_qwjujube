__int64 __fastcall kgsl_mmu_dev_probe(__int64 a1)
{
  __int64 (__fastcall **v2)(); // x1

  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760)) )
  {
    v2 = kgsl_mmu_cb_component_ops;
  }
  else
  {
    of_platform_populate(*(_QWORD *)(a1 + 760), 0, 0, a1 + 16);
    v2 = kgsl_mmu_component_ops;
  }
  return component_add(a1 + 16, v2);
}
