__int64 __fastcall adsp_loader_remove(__int64 result)
{
  _QWORD *v1; // x19

  v1 = *(_QWORD **)(result + 168);
  if ( v1 )
  {
    if ( *v1 )
    {
      rproc_shutdown();
      *v1 = 0;
    }
    result = v1[1];
    if ( result )
    {
      sysfs_remove_group(result, v1[2]);
      result = kobject_del(v1[1]);
      v1[1] = 0;
    }
  }
  return result;
}
