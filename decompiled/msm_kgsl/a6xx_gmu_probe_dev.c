__int64 __fastcall a6xx_gmu_probe_dev(__int64 a1)
{
  return component_add(a1 + 16, a6xx_gmu_component_ops);
}
