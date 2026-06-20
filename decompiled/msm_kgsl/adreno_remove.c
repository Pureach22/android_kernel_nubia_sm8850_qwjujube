__int64 __fastcall adreno_remove(__int64 a1)
{
  return component_master_del(a1 + 16, adreno_ops);
}
