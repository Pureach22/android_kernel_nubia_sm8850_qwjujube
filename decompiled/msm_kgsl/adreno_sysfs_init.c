__int64 __fastcall adreno_sysfs_init(_QWORD *a1)
{
  __int64 v2; // x21
  unsigned int files; // w20

  v2 = a1[193];
  files = sysfs_create_files(*a1, attr_list);
  if ( !files )
  {
    kobject_uevent(*a1, 0);
    files = sysfs_create_file_ns(a1 + 1624, &gpu_sysfs_attr_gpu_model, 0);
  }
  if ( (unsigned int)sysfs_create_link(*a1, v2 + 16, "gmu") )
    __break(0x800u);
  return files;
}
