__int64 __fastcall syna_sysfs_create_dir(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x2
  unsigned int group; // w0
  __int64 v6; // x2
  unsigned int dir; // w0
  __int64 v8; // x2
  unsigned int v10; // w20

  v3 = kobject_create_and_add("sysfs", a2 + 16);
  *(_QWORD *)(a1 + 920) = v3;
  if ( !v3 )
  {
    printk(&unk_3CC3E, "syna_sysfs_create_dir", v4);
    return 4294967276LL;
  }
  group = sysfs_create_group(v3, &attr_group);
  if ( (group & 0x80000000) != 0 )
  {
    v10 = group;
    printk(&unk_34964, "syna_sysfs_create_dir", v6);
LABEL_9:
    kobject_put(*(_QWORD *)(a1 + 920));
    return v10;
  }
  dir = syna_testing_create_dir(a1);
  if ( (dir & 0x80000000) != 0 )
  {
    v10 = dir;
    printk(&unk_3B229, "syna_sysfs_create_dir", v8);
    sysfs_remove_group(*(_QWORD *)(a1 + 920), &attr_group);
    goto LABEL_9;
  }
  return 0;
}
