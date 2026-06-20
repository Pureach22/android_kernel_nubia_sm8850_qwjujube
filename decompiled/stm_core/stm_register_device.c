__int64 __fastcall stm_register_device(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x22
  __int64 v7; // x20
  unsigned int v8; // w0
  int v9; // w8
  const char *v10; // x2
  unsigned int v11; // w0
  const char *v12; // x3
  unsigned int v13; // w19

  if ( !stm_core_up )
    return 4294966779LL;
  if ( !*(_QWORD *)(a2 + 40) || !*(_DWORD *)(a2 + 24) )
    return 4294967274LL;
  v6 = (unsigned int)(*(_DWORD *)(a2 + 20) - *(_DWORD *)(a2 + 16) + 1);
  v7 = vzalloc_noprof(8 * v6 + 1088);
  if ( !v7 )
    return 4294967284LL;
  v8 = _register_chrdev(0, 0, 256, *(_QWORD *)a2, &stm_fops);
  *(_DWORD *)(v7 + 976) = v8;
  if ( (v8 & 0x80000000) != 0 )
  {
    v13 = v8;
    vfree(v7);
    return v13;
  }
  device_initialize(v7);
  v9 = *(_DWORD *)(v7 + 976) << 20;
  *(_QWORD *)(v7 + 792) = &stm_class;
  *(_DWORD *)(v7 + 760) = v9;
  *(_QWORD *)(v7 + 96) = a1;
  *(_QWORD *)(v7 + 808) = stm_device_release;
  _mutex_init(v7 + 992, "&stm->link_mutex", &stm_register_device___key);
  *(_DWORD *)(v7 + 1040) = 0;
  *(_QWORD *)(v7 + 1048) = v7 + 1048;
  *(_QWORD *)(v7 + 1056) = v7 + 1048;
  *(_DWORD *)(v7 + 1080) = 0;
  _mutex_init(v7 + 928, "&stm->policy_mutex", &stm_register_device___key_5);
  v10 = *(const char **)a2;
  *(_DWORD *)(v7 + 980) = v6;
  *(_QWORD *)(v7 + 912) = a3;
  *(_QWORD *)(v7 + 984) = a2;
  *(_QWORD *)(a2 + 8) = v7;
  v11 = kobject_set_name(v7, "%s", v10);
  if ( v11 || (v11 = device_add(v7)) != 0 )
  {
    v12 = *(const char **)a2;
    v13 = v11;
    _unregister_chrdev(*(unsigned int *)(v7 + 976), 0, 256, v12);
    put_device(v7);
    return v13;
  }
  pm_runtime_no_callbacks(v7);
  _pm_runtime_use_autosuspend(v7, 1);
  pm_runtime_set_autosuspend_delay(v7, 2000);
  _pm_runtime_set_status(v7, 2);
  pm_runtime_enable(v7);
  return 0;
}
