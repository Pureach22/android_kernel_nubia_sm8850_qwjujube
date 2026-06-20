__int64 __fastcall kgsl_regmap_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 *resource_byname; // x0
  __int64 *v10; // x22
  __int64 v11; // x0
  __int64 v12; // x8
  _QWORD *v13; // x9
  __int64 v15; // x8
  __int64 v16; // x9

  resource_byname = (__int64 *)platform_get_resource_byname(a1, 512, a3);
  if ( !resource_byname )
    return 4294967277LL;
  *(_QWORD *)a2 = resource_byname;
  v10 = resource_byname;
  v11 = devm_ioremap(a1 + 16, *resource_byname, resource_byname[1] - *resource_byname + 1);
  if ( !v11 )
    return 4294967284LL;
  v12 = v11;
  v13 = *(_QWORD **)a2;
  *(_QWORD *)(a2 + 8) = v12;
  *(_DWORD *)(a2 + 16) = (unsigned __int64)(*v10 - *v13) >> 2;
  v16 = *v10;
  v15 = v10[1];
  *(_QWORD *)(a2 + 24) = a4;
  *(_QWORD *)(a2 + 32) = a5;
  *(_DWORD *)(a2 + 168) = 1;
  *(_DWORD *)(a2 + 20) = (unsigned __int64)(v15 - v16 + 1) >> 2;
  return 0;
}
