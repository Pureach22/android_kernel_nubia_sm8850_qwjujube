_QWORD *__fastcall gmu_core_rdpm_probe(_QWORD *a1)
{
  _QWORD *resource_byname; // x0
  _QWORD *result; // x0

  resource_byname = (_QWORD *)platform_get_resource_byname(a1[1396], 512, "rdpm_cx");
  if ( resource_byname )
    a1[1036] = devm_ioremap(a1[1396] + 16LL, *resource_byname, resource_byname[1] - *resource_byname + 1LL);
  result = (_QWORD *)platform_get_resource_byname(a1[1396], 512, "rdpm_mx");
  if ( result )
  {
    result = (_QWORD *)devm_ioremap(a1[1396] + 16LL, *result, result[1] - *result + 1LL);
    a1[1037] = result;
  }
  return result;
}
