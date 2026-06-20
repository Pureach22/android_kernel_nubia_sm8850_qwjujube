__int64 __fastcall pld_exit_power_save(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3

  v2 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v3 = raw_spin_lock_irqsave(pld_ctx + 8);
    v4 = v2 + 16;
    do
    {
      v4 = *(_QWORD *)v4;
      if ( v4 == v2 + 16 )
      {
        raw_spin_unlock_irqrestore(v2 + 8, v3);
        goto LABEL_11;
      }
    }
    while ( *(_QWORD *)(v4 - 16) != a1 );
    raw_spin_unlock_irqrestore(v2 + 8, v3);
    if ( v4 == 16 )
      goto LABEL_11;
    v5 = *(unsigned int *)(v4 + 16);
    if ( (unsigned int)v5 < 8 )
      return 0;
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
LABEL_11:
    v5 = 0xFFFFFFFFLL;
  }
  printk(&unk_886A85, "pld_exit_power_save", 1217, v5);
  return 4294967274LL;
}
