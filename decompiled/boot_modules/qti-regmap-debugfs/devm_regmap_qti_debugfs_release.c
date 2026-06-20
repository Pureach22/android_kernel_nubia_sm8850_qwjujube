__int64 __fastcall devm_regmap_qti_debugfs_release(__int64 a1, _QWORD **a2)
{
  _QWORD *v3; // x0
  _UNKNOWN **v4; // x9

  mutex_lock(&regmap_qti_debugfs_lock);
  v3 = *a2;
  v4 = &regmap_qti_debugfs_list;
  while ( 1 )
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &regmap_qti_debugfs_list )
      break;
    if ( v4 == v3 )
    {
      regmap_qti_debugfs_remove(v3);
      return mutex_unlock(&regmap_qti_debugfs_lock);
    }
  }
  return mutex_unlock(&regmap_qti_debugfs_lock);
}
