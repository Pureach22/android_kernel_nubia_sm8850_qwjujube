__int64 __fastcall a6xx_rgmu_probe_dev(__int64 a1)
{
  return component_add(a1 + 16, &a6xx_rgmu_component_ops);
}
