__int64 __fastcall pld_srng_free_irq(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v4; // x21
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 v9; // x3
  __int64 result; // x0

  v4 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v7 = raw_spin_lock_irqsave(pld_ctx + 8);
    v8 = v4 + 16;
    while ( 1 )
    {
      v8 = *(_QWORD *)v8;
      if ( v8 == v4 + 16 )
        break;
      if ( *(_QWORD *)(v8 - 16) == a1 )
      {
        raw_spin_unlock_irqrestore(v4 + 8, v7);
        if ( v8 == 16 )
          goto LABEL_18;
        v9 = *(unsigned int *)(v8 + 16);
        result = 0;
        if ( (int)v9 > 5 )
        {
          if ( (_DWORD)v9 != 6 )
          {
            if ( (_DWORD)v9 == 7 )
              return result;
            goto LABEL_19;
          }
        }
        else if ( (_DWORD)v9 )
        {
          if ( (_DWORD)v9 == 5 )
            return result;
          if ( (unsigned int)(v9 - 1) < 4 )
          {
            printk(&unk_92F235, "pld_srng_free_irq", 1960, v9);
            return 4294967277LL;
          }
          goto LABEL_19;
        }
        free_irq(a2, a3);
        return 0;
      }
    }
    raw_spin_unlock_irqrestore(v4 + 8, v7);
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
  }
LABEL_18:
  v9 = 0xFFFFFFFFLL;
LABEL_19:
  printk(&unk_886A85, "pld_srng_free_irq", 1967, v9);
  return 4294967274LL;
}
