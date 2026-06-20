__int64 __fastcall pm8941_pwrkey_resume(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  const char *v4; // x1
  unsigned int v5; // w20

  v1 = *(_QWORD *)(a1 + 152);
  if ( pm_suspend_target_state == 3 )
  {
    LODWORD(result) = pm8941_pwrkey_hw_init((__int64 *)v1);
    if ( (_DWORD)result )
    {
      v4 = "Failed to initialize H/W error :%d\n";
      goto LABEL_11;
    }
    result = devm_request_threaded_irq(
               a1,
               *(unsigned int *)(v1 + 8),
               0,
               pm8941_pwrkey_irq,
               0x2000,
               *(_QWORD *)(*(_QWORD *)(v1 + 96) + 16LL),
               v1);
    if ( (_DWORD)result )
    {
      v4 = "failed requesting IRQ: %d\n";
LABEL_11:
      v5 = result;
      dev_err(a1, v4, (unsigned int)result);
      return v5;
    }
  }
  else
  {
    if ( (*(_WORD *)(a1 + 268) & 1) != 0 )
    {
      if ( *(_QWORD *)(a1 + 328) )
        irq_set_irq_wake(*(unsigned int *)(v1 + 8), 0);
    }
    return 0;
  }
  return result;
}
