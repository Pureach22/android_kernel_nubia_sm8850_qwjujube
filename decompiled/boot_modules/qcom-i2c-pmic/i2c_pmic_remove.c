__int64 __fastcall i2c_pmic_remove(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD **)(a1 + 184);
  of_platform_depopulate(*v1);
  result = v1[2];
  if ( result )
    result = irq_domain_remove();
  *(_QWORD *)(a1 + 184) = 0;
  return result;
}
