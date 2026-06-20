_QWORD *__fastcall ifas_sysfs_remove_dir(_QWORD *result)
{
  _QWORD *v1; // x19

  if ( result )
  {
    v1 = result;
    result = (_QWORD *)kobject_put(*result);
    *v1 = 0;
  }
  return result;
}
