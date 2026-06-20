__int64 __fastcall nb_fan_remove(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD **)(a1 + 168);
  result = sysfs_remove_group(v1[2], &chip_attr_group);
  *(_QWORD *)(*v1 + 152LL) = 0;
  return result;
}
