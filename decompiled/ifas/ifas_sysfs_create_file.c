__int64 __fastcall ifas_sysfs_create_file(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v3; // x1

  if ( !a2 )
    return printk(&unk_10A7E, "ifas");
  if ( !a1 )
    a1 = ifas_kobj;
  result = sysfs_create_file_ns(a1);
  if ( (_DWORD)result )
    return printk(&unk_10205, v3);
  return result;
}
