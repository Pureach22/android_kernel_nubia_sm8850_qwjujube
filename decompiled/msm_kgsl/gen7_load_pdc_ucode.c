__int64 __fastcall gen7_load_pdc_ucode(__int64 a1)
{
  __int64 *v2; // x21
  __int64 v3; // x0
  __int64 v4; // x19
  _QWORD *resource_byname; // x0
  unsigned int v6; // w20

  v2 = (__int64 *)(a1 - 560);
  v3 = *(_QWORD *)(a1 - 560);
  v4 = *(_QWORD *)(a1 + 1544);
  if ( v3 )
    goto LABEL_4;
  resource_byname = (_QWORD *)platform_get_resource_byname(*(_QWORD *)(a1 + 1544), 512, "gmu_pdc");
  if ( !resource_byname )
  {
    v3 = *v2;
    if ( *v2 )
      goto LABEL_4;
LABEL_7:
    dev_err(v4 + 16, "Failed to map PDC CFG\n");
    return (unsigned int)-19;
  }
  v3 = devm_ioremap(v4 + 16, *resource_byname, resource_byname[1] - *resource_byname + 1LL);
  *v2 = v3;
  if ( !v3 )
    goto LABEL_7;
LABEL_4:
  v6 = 0;
  *(_DWORD *)(v3 + 17696) = 0;
  *(_DWORD *)(*v2 + 17664) = -2147483647;
  devm_iounmap(v4 + 16, *v2);
  *v2 = 0;
  return v6;
}
