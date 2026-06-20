unsigned __int64 __fastcall tmc_platform_remove(unsigned __int64 result)
{
  unsigned __int64 *v1; // x20
  unsigned __int64 v2; // x19

  v1 = *(unsigned __int64 **)(result + 168);
  if ( v1 )
  {
    v2 = result;
    _tmc_remove(result + 16);
    _pm_runtime_disable(v2 + 16, 1);
    result = *v1;
    if ( *v1 )
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
