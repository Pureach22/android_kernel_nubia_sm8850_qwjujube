__int64 __fastcall syna_testing_remove_dir(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 936);
  if ( result )
  {
    sysfs_remove_group(result, &attr_testing_group);
    kobject_put(*(_QWORD *)(a1 + 936));
    return 0;
  }
  return result;
}
