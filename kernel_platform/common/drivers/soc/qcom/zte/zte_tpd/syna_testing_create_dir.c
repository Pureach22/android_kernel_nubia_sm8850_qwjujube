__int64 __fastcall syna_testing_create_dir(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  unsigned int group; // w0
  __int64 v5; // x2
  unsigned int v7; // w20

  v2 = kobject_create_and_add("testing", *(_QWORD *)(a1 + 920));
  *(_QWORD *)(a1 + 936) = v2;
  if ( v2 )
  {
    group = sysfs_create_group(v2, &attr_testing_group);
    if ( (group & 0x80000000) != 0 )
    {
      v7 = group;
      printk(unk_34964, "syna_testing_create_dir", v5);
      kobject_put(*(_QWORD *)(a1 + 936));
      return v7;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    printk(unk_389E1, "syna_testing_create_dir", v3);
    return 4294967274LL;
  }
}
