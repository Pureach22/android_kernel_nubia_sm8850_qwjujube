__int64 __fastcall coresight_register(int *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x11
  __int64 v5; // x10
  unsigned int v6; // w9
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  const char *v14; // x2
  int v15; // w0
  int v16; // w21
  int v17; // w0
  int conns_sysfs_group; // w0
  int v19; // w20
  void (__fastcall *v20)(_QWORD); // x8

  v2 = _kmalloc_cache_noprof(idr_remove, 3520, 1056);
  v3 = v2;
  if ( !v2 )
  {
    v3 = -12;
    goto LABEL_18;
  }
  v4 = *((_QWORD *)a1 + 2);
  v5 = *(_QWORD *)(a1 + 1);
  v6 = *a1;
  *(_QWORD *)v2 = *((_QWORD *)a1 + 3);
  *(_QWORD *)(v2 + 12) = v5;
  v7 = *((_QWORD *)a1 + 7);
  v8 = *((_QWORD *)a1 + 8);
  *(_DWORD *)(v2 + 8) = v6;
  *(_QWORD *)(v2 + 24) = v4;
  *(_QWORD *)(v2 + 32) = v7;
  v9 = *((_QWORD *)a1 + 9);
  *(_QWORD *)(v2 + 40) = v8;
  *(_QWORD *)(v2 + 48) = v9;
  v10 = *((_QWORD *)a1 + 4);
  v11 = *((_QWORD *)a1 + 5);
  *(_BYTE *)(v3 + 980) = 1;
  *(_QWORD *)(v3 + 856) = v11;
  *(_QWORD *)(v3 + 864) = coresight_device_release;
  *(_QWORD *)(v3 + 152) = v10;
  *(_QWORD *)(v3 + 176) = &(&coresight_dev_type)[6 * v6];
  *(_QWORD *)(v3 + 184) = &coresight_bustype;
  v12 = _dev_fwnode(v10);
  v13 = fwnode_handle_get(v12);
  v14 = *((const char **)a1 + 6);
  *(_QWORD *)(v3 + 808) = v13;
  dev_set_name(v3 + 56, "%s", v14);
  mutex_lock(&coresight_mutex);
  v15 = device_register(v3 + 56);
  if ( v15 )
  {
    v16 = v15;
    put_device(v3 + 56);
LABEL_4:
    mutex_unlock(&coresight_mutex);
    v3 = v16;
LABEL_18:
    coresight_release_platform_data(0, *((_QWORD *)a1 + 4), *((_QWORD *)a1 + 3));
    return v3;
  }
  if ( (*(_DWORD *)(v3 + 8) | 2) == 2 )
  {
    v17 = etm_perf_add_symlink_sink(v3);
    if ( v17 )
    {
      v16 = v17;
      device_unregister(v3 + 56);
      goto LABEL_4;
    }
  }
  conns_sysfs_group = coresight_create_conns_sysfs_group(v3);
  if ( conns_sysfs_group )
  {
    v19 = conns_sysfs_group;
    mutex_unlock(&coresight_mutex);
LABEL_11:
    coresight_unregister(v3);
    return v19;
  }
  v19 = bus_for_each_dev(&coresight_bustype, 0, v3, coresight_orphan_match);
  mutex_unlock(&coresight_mutex);
  if ( v19 )
    goto LABEL_11;
  if ( cti_assoc_ops )
  {
    v20 = *(void (__fastcall **)(_QWORD))cti_assoc_ops;
    if ( *(_QWORD *)cti_assoc_ops )
    {
      if ( *((_DWORD *)v20 - 1) != 538919244 )
        __break(0x8228u);
      v20(v3);
    }
  }
  return v3;
}
