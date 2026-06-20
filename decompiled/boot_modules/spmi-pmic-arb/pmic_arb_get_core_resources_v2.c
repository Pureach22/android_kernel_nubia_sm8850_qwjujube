unsigned __int64 __fastcall pmic_arb_get_core_resources_v2(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  unsigned __int64 *v4; // x20
  unsigned __int64 result; // x0
  __int64 resource_byname; // x0
  unsigned __int64 *v7; // x8

  v2 = *(_QWORD *)(a1 + 168);
  *(_QWORD *)(v2 + 24) = a2;
  *(_DWORD *)(v2 + 64) = 512;
  v4 = *(unsigned __int64 **)(a1 + 168);
  result = ((__int64 (*)(void))devm_platform_ioremap_resource_byname)();
  *v4 = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    result = devm_platform_ioremap_resource_byname(a1, "chnls");
    v4[1] = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      resource_byname = platform_get_resource_byname(a1, 512, "chnls");
      if ( resource_byname )
      {
        v7 = (unsigned __int64 *)resource_byname;
        v4[2] = *v7;
        return 0;
      }
      else
      {
        return 4294967274LL;
      }
    }
  }
  return result;
}
