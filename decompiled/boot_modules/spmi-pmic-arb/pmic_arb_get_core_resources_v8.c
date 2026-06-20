unsigned __int64 __fastcall pmic_arb_get_core_resources_v8(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned __int64 result; // x0
  unsigned __int64 *v6; // x20
  __int64 resource_byname; // x0
  unsigned __int64 *v8; // x8

  v2 = *(_QWORD *)(a1 + 168);
  result = devm_platform_ioremap_resource_byname(a1, "chnl_map");
  *(_QWORD *)(v2 + 40) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v2 + 24) = a2;
    *(_DWORD *)(v2 + 64) = 0x2000;
    v6 = *(unsigned __int64 **)(a1 + 168);
    result = devm_platform_ioremap_resource_byname(a1, "obsrvr");
    *v6 = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      result = devm_platform_ioremap_resource_byname(a1, "chnls");
      v6[1] = result;
      if ( result < 0xFFFFFFFFFFFFF001LL )
      {
        resource_byname = platform_get_resource_byname(a1, 512, "chnls");
        if ( resource_byname )
        {
          v8 = (unsigned __int64 *)resource_byname;
          v6[2] = *v8;
          return 0;
        }
        else
        {
          return 4294967274LL;
        }
      }
    }
  }
  return result;
}
