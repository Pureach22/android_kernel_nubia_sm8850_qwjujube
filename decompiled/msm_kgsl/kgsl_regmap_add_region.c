__int64 __fastcall kgsl_regmap_add_region(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 *resource_byname; // x0
  __int64 v10; // x24
  __int64 *v11; // x22
  __int64 v12; // x0
  __int64 v13; // x9
  __int64 v14; // x8
  _QWORD *v15; // x10
  __int64 v17; // x8
  __int64 v18; // x10

  resource_byname = (__int64 *)platform_get_resource_byname(a2, 512, a3);
  if ( !resource_byname )
    return 4294967277LL;
  v10 = *(unsigned int *)(a1 + 168);
  if ( (unsigned int)v10 >= 5 )
  {
    __break(0x800u);
    return 4294967277LL;
  }
  else
  {
    v11 = resource_byname;
    v12 = devm_ioremap(a2 + 16, *resource_byname, resource_byname[1] - *resource_byname + 1);
    if ( v12 )
    {
      v13 = a1 + 32 * v10;
      v14 = v12;
      v15 = *(_QWORD **)a1;
      *(_QWORD *)(v13 + 8) = v14;
      *(_DWORD *)(v13 + 16) = (unsigned __int64)(*v11 - *v15) >> 2;
      v18 = *v11;
      v17 = v11[1];
      *(_QWORD *)(v13 + 24) = a4;
      *(_QWORD *)(v13 + 32) = a5;
      ++*(_DWORD *)(a1 + 168);
      *(_DWORD *)(v13 + 20) = (unsigned __int64)(v17 - v18 + 1) >> 2;
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
}
