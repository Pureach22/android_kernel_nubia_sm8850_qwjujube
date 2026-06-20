__int64 __fastcall stm_source_register_device(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  const char *v6; // x2
  __int64 result; // x0
  unsigned int v8; // w19

  if ( !stm_core_up )
    return 4294966779LL;
  v4 = _kmalloc_cache_noprof(kobject_set_name, 3520, 976);
  v5 = v4;
  if ( !v4 )
    return 4294967284LL;
  device_initialize(v4);
  v6 = *(const char **)a2;
  *(_QWORD *)(v5 + 792) = &stm_source_class;
  *(_QWORD *)(v5 + 96) = a1;
  *(_QWORD *)(v5 + 808) = stm_source_device_release;
  LODWORD(result) = kobject_set_name(v5, "%s", v6);
  if ( (_DWORD)result || (pm_runtime_no_callbacks(v5), pm_runtime_forbid(v5), result = device_add(v5), (_DWORD)result) )
  {
    v8 = result;
    put_device(v5);
    return v8;
  }
  else
  {
    *(_DWORD *)(v5 + 952) = 0;
    *(_DWORD *)(v5 + 920) = 0;
    *(_QWORD *)(v5 + 936) = v5 + 936;
    *(_QWORD *)(v5 + 944) = v5 + 936;
    *(_QWORD *)(v5 + 912) = a2;
    *(_QWORD *)(a2 + 8) = v5;
  }
  return result;
}
