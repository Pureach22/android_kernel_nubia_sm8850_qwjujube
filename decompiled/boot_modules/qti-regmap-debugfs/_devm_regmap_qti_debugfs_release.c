_QWORD *__fastcall devm_regmap_qti_debugfs_release(__int64 a1, _QWORD **a2)
{
  _QWORD *result; // x0
  _UNKNOWN **v3; // x9

  result = *a2;
  v3 = &regmap_qti_debugfs_list;
  while ( 1 )
  {
    v3 = (_UNKNOWN **)*v3;
    if ( v3 == &regmap_qti_debugfs_list )
      break;
    if ( v3 == result )
      return (_QWORD *)regmap_qti_debugfs_remove(result);
  }
  return result;
}
