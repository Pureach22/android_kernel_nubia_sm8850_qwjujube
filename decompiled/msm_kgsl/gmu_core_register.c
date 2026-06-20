__int64 gmu_core_register()
{
  __int64 result; // x0
  _QWORD v1[2]; // [xsp+0h] [xbp-10h] BYREF

  v1[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1[0] = 0;
  result = of_find_matching_node_and_match(0, &gmu_match_table, v1);
  if ( result )
    result = _platform_driver_register(*(__int64 *)((char *)&qword_C0 + v1[0]), &_this_module);
  _ReadStatusReg(SP_EL0);
  return result;
}
