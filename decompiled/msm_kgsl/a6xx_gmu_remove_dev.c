__int64 __fastcall a6xx_gmu_remove_dev(__int64 a1)
{
  return component_del(a1 + 16, a6xx_gmu_component_ops);
}
