__int64 __fastcall regmap_qti_debugfs_unregister(unsigned __int64 a1)
{
  _UNKNOWN **v2; // x0

  if ( !a1 || a1 >= 0xFFFFFFFFFFFFF001LL )
    return printk(&unk_78E9, "regmap_qti_debugfs_unregister");
  mutex_lock(&regmap_qti_debugfs_lock);
  v2 = &regmap_qti_debugfs_list;
  while ( 1 )
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &regmap_qti_debugfs_list )
      break;
    if ( v2[2] == (_UNKNOWN *)a1 )
    {
      regmap_qti_debugfs_remove();
      return mutex_unlock(&regmap_qti_debugfs_lock);
    }
  }
  return mutex_unlock(&regmap_qti_debugfs_lock);
}
