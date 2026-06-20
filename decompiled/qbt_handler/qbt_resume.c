__int64 __fastcall qbt_resume(__int64 a1)
{
  __int64 v2; // x19

  printk(&unk_9DD2, "qbt_resume");
  v2 = *(_QWORD *)(a1 + 168);
  if ( *(_BYTE *)(v2 + 1144) == 1 )
  {
    printk(&unk_9B98, "qbt_resume");
    irq_set_irq_wake(*(unsigned int *)(v2 + 512), 0);
  }
  irq_set_irq_wake(*(unsigned int *)(v2 + 460), 0);
  return 0;
}
