__int64 __fastcall hif_apps_wake_irq_disable(__int64 a1)
{
  if ( !a1 )
    return 4294967274LL;
  disable_irq(*(unsigned int *)(a1 + 2572));
  return 0;
}
