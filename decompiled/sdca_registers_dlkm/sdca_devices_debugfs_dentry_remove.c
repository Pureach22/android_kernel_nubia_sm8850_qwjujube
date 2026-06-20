_QWORD *__fastcall sdca_devices_debugfs_dentry_remove(_QWORD *result)
{
  _QWORD *v1; // x19

  if ( result )
  {
    v1 = result;
    result = (_QWORD *)debugfs_remove(*result);
    *v1 = 0;
  }
  return result;
}
