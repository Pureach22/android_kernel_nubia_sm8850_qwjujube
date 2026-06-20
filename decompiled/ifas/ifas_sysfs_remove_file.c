__int64 __fastcall ifas_sysfs_remove_file(__int64 result, __int64 a2)
{
  if ( a2 )
  {
    if ( !result )
      result = ifas_kobj;
    return sysfs_remove_file_ns(result);
  }
  return result;
}
