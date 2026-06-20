__int64 __fastcall hif_apps_disable_irq_wake(__int64 a1)
{
  if ( a1 )
    return irq_set_irq_wake(*(unsigned int *)(a1 + 2572), 0);
  else
    return 4294967274LL;
}
