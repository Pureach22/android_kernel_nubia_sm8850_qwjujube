__int64 __fastcall pm8941_pwrkey_freeze(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(unsigned int *)(v1 + 8);
  if ( (int)v3 >= 1 )
  {
    disable_irq(v3);
    devm_free_irq(a1, *(unsigned int *)(v1 + 8), v1);
  }
  return 0;
}
