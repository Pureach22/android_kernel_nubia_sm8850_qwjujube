__int64 __fastcall devm_regmap_qti_debugfs_unregister(unsigned __int64 a1)
{
  _QWORD *v2; // x3
  _UNKNOWN **v3; // x23

  if ( !a1 || a1 >= 0xFFFFFFFFFFFFF001LL )
    return printk(&unk_78E9, "devm_regmap_qti_debugfs_unregister");
  mutex_lock(&regmap_qti_debugfs_lock);
  v2 = regmap_qti_debugfs_list;
  if ( regmap_qti_debugfs_list != (_UNKNOWN *)&regmap_qti_debugfs_list )
  {
    do
    {
      v3 = (_UNKNOWN **)*v2;
      if ( v2[2] == a1 )
        devres_release(v2[3], devm_regmap_qti_debugfs_release, devm_regmap_qti_debugfs_match);
      v2 = v3;
    }
    while ( v3 != &regmap_qti_debugfs_list );
  }
  return mutex_unlock(&regmap_qti_debugfs_lock);
}
