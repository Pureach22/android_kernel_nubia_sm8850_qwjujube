__int64 __fastcall gh_dbgfs_hyp_uart_set(__int64 a1, int a2)
{
  void *v2; // x0

  if ( a2 )
  {
    if ( a2 != 1 )
    {
      v2 = &unk_6CAF;
      goto LABEL_10;
    }
    if ( (hyp_uart_enable & 1) != 0 )
    {
      v2 = &unk_6B43;
LABEL_10:
      printk(v2);
      return 0;
    }
    hyp_uart_enable = 1;
    printk(&unk_6C2A);
    __asm { SMC             #0 }
  }
  else
  {
    if ( hyp_uart_enable != 1 )
    {
      v2 = &unk_6BFD;
      goto LABEL_10;
    }
    hyp_uart_enable = 0;
    printk(&unk_6C89);
    __asm { SMC             #0 }
  }
  return 0;
}
