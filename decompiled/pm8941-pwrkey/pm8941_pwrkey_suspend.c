__int64 __fastcall pm8941_pwrkey_suspend(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8

  v1 = *(_QWORD *)(a1 + 152);
  if ( pm_suspend_target_state == 3 )
  {
    v2 = *(_DWORD *)(v1 + 8);
    if ( v2 >= 1 )
    {
      disable_irq((unsigned int)v2);
      devm_free_irq(a1, *(unsigned int *)(v1 + 8), v1);
    }
  }
  else if ( (*(_WORD *)(a1 + 268) & 1) != 0 && *(_QWORD *)(a1 + 328) )
  {
    irq_set_irq_wake(*(unsigned int *)(v1 + 8), 1);
  }
  return 0;
}
