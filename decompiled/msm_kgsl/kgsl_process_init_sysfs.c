__int64 __fastcall kgsl_process_init_sysfs(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x8
  int v5; // w4
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x2
  __int64 v9; // x8
  __int64 v10; // x2

  v2 = *(_QWORD *)(a2 + 8);
  if ( v2 )
    v5 = *(_DWORD *)(v2 + 112);
  else
    v5 = 0;
  if ( (unsigned int)kobject_init_and_add(a2 + 104, process_ktype, qword_3A7F0, "%d", v5) )
  {
    v7 = *(_QWORD *)(a2 + 8);
    if ( v7 )
      v8 = *(unsigned int *)(v7 + 112);
    else
      v8 = 0;
    return dev_err(*a1, "Unable to add sysfs for process %d\n", v8);
  }
  else
  {
    kgsl_reclaim_proc_sysfs_init(a2);
    result = kobject_init_and_add(a2 + 504, &ktype_memtype, a2 + 104, "memtype");
    if ( (_DWORD)result )
    {
      v9 = *(_QWORD *)(a2 + 8);
      if ( v9 )
        v10 = *(unsigned int *)(v9 + 112);
      else
        v10 = 0;
      return dev_err(*a1, "Unable to add memtype sysfs for process %d\n", v10);
    }
  }
  return result;
}
