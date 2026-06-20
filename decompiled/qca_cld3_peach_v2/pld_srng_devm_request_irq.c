__int64 __fastcall pld_srng_devm_request_irq(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v7; // x25
  __int64 v13; // x0
  __int64 v14; // x26
  __int64 v15; // x3
  __int64 result; // x0

  v7 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v13 = raw_spin_lock_irqsave(pld_ctx + 8);
    v14 = v7 + 16;
    while ( 1 )
    {
      v14 = *(_QWORD *)v14;
      if ( v14 == v7 + 16 )
        break;
      if ( *(_QWORD *)(v14 - 16) == a1 )
      {
        raw_spin_unlock_irqrestore(v7 + 8, v13);
        if ( v14 == 16 )
          goto LABEL_18;
        v15 = *(unsigned int *)(v14 + 16);
        result = 0;
        if ( (int)v15 > 5 )
        {
          if ( (_DWORD)v15 != 6 )
          {
            if ( (_DWORD)v15 == 7 )
              return result;
            goto LABEL_19;
          }
        }
        else if ( (_DWORD)v15 )
        {
          if ( (_DWORD)v15 == 5 )
            return result;
          if ( (unsigned int)(v15 - 1) < 4 )
          {
            printk(&unk_A0E3B2, "pld_srng_devm_request_irq", 1890, v15);
            return 4294967277LL;
          }
          goto LABEL_19;
        }
        return devm_request_threaded_irq(a1, a2, a3, 0, a4, a5, a6);
      }
    }
    raw_spin_unlock_irqrestore(v7 + 8, v13);
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
  }
LABEL_18:
  v15 = 0xFFFFFFFFLL;
LABEL_19:
  printk(&unk_9538F1, "pld_srng_devm_request_irq", 1898, v15);
  return 4294967274LL;
}
