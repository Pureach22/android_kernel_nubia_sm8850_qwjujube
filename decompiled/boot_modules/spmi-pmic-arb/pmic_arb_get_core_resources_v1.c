__int64 __fastcall pmic_arb_get_core_resources_v1(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 resource_byname; // x0
  _QWORD *v4; // x8

  v2 = *(_QWORD *)(a1 + 168);
  *(_QWORD *)v2 = a2;
  *(_QWORD *)(v2 + 8) = a2;
  *(_DWORD *)(v2 + 64) = 512;
  resource_byname = platform_get_resource_byname(a1, 512, "core");
  if ( !resource_byname )
    return 4294967274LL;
  v4 = (_QWORD *)resource_byname;
  *(_QWORD *)(v2 + 16) = *v4;
  return 0;
}
