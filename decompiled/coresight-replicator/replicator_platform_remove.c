unsigned __int64 __fastcall replicator_platform_remove(unsigned __int64 result)
{
  __int64 v1; // x20
  unsigned __int64 v2; // x19

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    v2 = result;
    if ( *(_QWORD *)(v1 + 24) )
      coresight_unregister();
    _pm_runtime_disable(v2 + 16, 1);
    result = *(_QWORD *)(v1 + 16);
    if ( result )
    {
      if ( result <= 0xFFFFFFFFFFFFF000LL )
        return clk_put(result);
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
