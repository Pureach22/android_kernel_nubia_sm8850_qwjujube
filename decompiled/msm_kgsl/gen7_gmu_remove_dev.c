__int64 __fastcall gen7_gmu_remove_dev(__int64 a1)
{
  return component_del(a1 + 16, gen7_gmu_component_ops);
}
