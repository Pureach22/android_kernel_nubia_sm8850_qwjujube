__int64 __fastcall gh_irq_vm_nb_handler(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  unsigned int v4; // w19
  __int64 v5; // x20
  int *v6; // x23
  __int64 v7; // x1
  __int64 v8; // x2

  if ( !a3 || a2 != 3 )
    return 0;
  v4 = *a3;
  v5 = 0;
  v6 = &dword_6E58;
  do
  {
    v7 = raw_spin_lock_irqsave(&gh_irq_lend_lock);
    if ( v4 != *((unsigned __int16 *)v6 - 16) || (unsigned int)*v6 > 5 || ((1 << *v6) & 0x3A) == 0 )
      goto LABEL_6;
    raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v7);
    if ( !(unsigned int)gh_rm_vm_irq_reclaim((unsigned int)v6[1]) )
    {
      v7 = raw_spin_lock_irqsave(&gh_irq_lend_lock);
      *v6 = 0;
LABEL_6:
      raw_spin_unlock_irqrestore(&gh_irq_lend_lock, v7);
      goto LABEL_7;
    }
    printk(&unk_6F79, (unsigned int)v5, *((unsigned __int16 *)v6 - 16));
LABEL_7:
    ++v5;
    v6 += 10;
  }
  while ( v5 != 6 );
  printk(&unk_6FA6, v4, v8);
  return 0;
}
