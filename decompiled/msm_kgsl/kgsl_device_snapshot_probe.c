__int64 __fastcall kgsl_device_snapshot_probe(__int64 *a1, unsigned int a2)
{
  __int64 v2; // x9
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 result; // x0
  __int64 v8; // x9
  __int64 v9; // x0

  v2 = a1[1396];
  *((_DWORD *)a1 + 2808) = a2;
  v5 = dma_alloc_attrs(v2 + 16, a2, a1 + 1403, 3264, 0);
  a1[1402] = v5;
  if ( a2 <= 0x100000 || v5 )
  {
    if ( v5 )
      goto LABEL_4;
    return dev_err(*a1, "KGSL failed to allocate memory for snapshot\n");
  }
  __break(0x800u);
  v8 = a1[1396];
  *((_DWORD *)a1 + 2808) = 0x100000;
  v9 = devm_kmalloc(v8 + 16, 0x100000, 3520);
  a1[1402] = v9;
  if ( !v9 )
    return dev_err(*a1, "KGSL failed to allocate memory for snapshot\n");
LABEL_4:
  v6 = *a1;
  *((_WORD *)a1 + 5652) = 256;
  a1[1406] = (__int64)kgsl_panic_notifier_callback;
  *((_DWORD *)a1 + 2816) = 1;
  a1[1405] = 0;
  *((_BYTE *)a1 + 11300) = 0;
  *((_BYTE *)a1 + 11306) = 0;
  a1[1414] = 0x10000;
  *((_BYTE *)a1 + 11302) = 0;
  *((_DWORD *)a1 + 2824) = 0;
  result = kobject_init_and_add(a1 + 1415, &ktype_snapshot, v6, "snapshot");
  if ( !(_DWORD)result )
  {
    if ( (unsigned int)sysfs_create_bin_file(a1 + 1415, &snapshot_attr) )
      __break(0x800u);
    if ( (unsigned int)sysfs_create_files(a1 + 1415, snapshot_attrs) )
      __break(0x800u);
    return atomic_notifier_chain_register(&panic_notifier_list, a1 + 1406);
  }
  return result;
}
