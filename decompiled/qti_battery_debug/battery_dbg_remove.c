__int64 __fastcall battery_dbg_remove(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD **)(a1 + 168);
  sysfs_remove_group(*v1, &battery_dbg_group);
  debugfs_remove(v1[526]);
  result = pmic_glink_unregister_client(v1[1]);
  if ( (result & 0x80000000) != 0 )
    return printk(&unk_7A85, "battery_dbg_remove", (unsigned int)result);
  return result;
}
