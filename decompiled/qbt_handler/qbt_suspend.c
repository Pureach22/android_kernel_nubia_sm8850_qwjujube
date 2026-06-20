__int64 __fastcall qbt_suspend(__int64 a1)
{
  __int64 v2; // x19

  printk(&unk_9DD2, "qbt_suspend");
  v2 = *(_QWORD *)(a1 + 168);
  if ( (unsigned int)mutex_trylock(v2 + 312) )
  {
    printk(&unk_9400, "qbt_suspend");
    if ( *(_BYTE *)(v2 + 1144) == 1 )
      irq_set_irq_wake(*(unsigned int *)(v2 + 512), 1);
    irq_set_irq_wake(*(unsigned int *)(v2 + 460), 1);
    mutex_unlock(v2 + 312);
    printk(&unk_9809, "qbt_suspend");
    return 0;
  }
  else
  {
    printk(&unk_A392, "qbt_suspend");
    return 4294967280LL;
  }
}
