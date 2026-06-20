__int64 __fastcall isdb_set(__int64 a1, __int64 a2)
{
  _QWORD *resource_byname; // x0
  __int64 v5; // x0

  if ( !*(_QWORD *)(a1 + 32) )
  {
    resource_byname = (_QWORD *)platform_get_resource_byname(*(_QWORD *)(a1 + 11168), 512, "qdss_gfx");
    if ( resource_byname )
    {
      v5 = devm_ioremap(*(_QWORD *)(a1 + 11168) + 16LL, *resource_byname, resource_byname[1] - *resource_byname + 1LL);
      *(_QWORD *)(a1 + 32) = v5;
      if ( !v5 )
        dev_warn(*(_QWORD *)a1, "qdss_gfx ioremap failed\n");
    }
  }
  *(_BYTE *)(a1 + 11303) = a2 != 0;
  return 0;
}
