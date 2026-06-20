__int64 __fastcall syna_sysfs_remove_dir(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x0

  if ( !result )
    return printk(&unk_3365A, "syna_sysfs_remove_dir", a3);
  v3 = result;
  if ( *(_QWORD *)(result + 920) )
  {
    syna_testing_remove_dir(result);
    v4 = *(_QWORD *)(v3 + 928);
    if ( v4 )
    {
      sysfs_remove_group(v4, &attr_debug_group);
      kobject_put(*(_QWORD *)(v3 + 928));
    }
    sysfs_remove_group(*(_QWORD *)(v3 + 920), &attr_group);
    return kobject_put(*(_QWORD *)(v3 + 920));
  }
  return result;
}
