__int64 __fastcall ifas_sysfs_create_dir(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v5; // x1
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 result; // x0

  if ( a2 && a3 )
  {
    if ( a1 )
      v5 = a1;
    else
      v5 = ifas_kobj;
    v6 = kobject_create_and_add(a2, v5);
    if ( v6 )
    {
      v7 = v6;
      result = 0;
      *a3 = v7;
    }
    else
    {
      printk(&unk_F1A9, a2);
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    printk(&unk_FF8B, a2);
    return 0xFFFFFFFFLL;
  }
  return result;
}
