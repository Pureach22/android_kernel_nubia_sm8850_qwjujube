__int64 __fastcall ipa3_interrupts_destroy(__int64 a1, __int64 a2)
{
  unsigned int v3; // w19
  __int64 result; // x0

  if ( *(_DWORD *)(ipa3_ctx + 32248) != 3 )
  {
    v3 = a1;
    irq_set_irq_wake(a1, 0);
    free_irq(v3, a2);
  }
  result = destroy_workqueue(ipa_interrupt_wq);
  ipa_interrupt_wq = 0;
  return result;
}
