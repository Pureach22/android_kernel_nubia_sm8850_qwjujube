__int64 __fastcall kgsl_reclaim_proc_sysfs_init(__int64 a1)
{
  __int64 result; // x0

  result = sysfs_create_files(a1 + 104, proc_reclaim_attrs);
  if ( (_DWORD)result )
    __break(0x800u);
  return result;
}
