__int64 event_or_word_error_interrupt_handler()
{
  unsigned int v0; // w0
  __int64 v1; // x20
  unsigned int v2; // w0

  v0 = readl((unsigned int *)(qpace_gen_cmd_regs + 12));
  if ( (v0 & 1) != 0 )
  {
    v1 = 0;
    v2 = 1;
LABEL_7:
    writel(v2, (unsigned int *)(qpace_gen_cmd_regs + 20));
    complete(ev_rings + (v1 << 6));
    return 1;
  }
  if ( (v0 & 2) != 0 )
  {
    v2 = 2;
    v1 = 1;
    goto LABEL_7;
  }
  if ( v0 >> 30 )
    panic("%s: word error detected, unrecoverable\n", "event_or_word_error_interrupt_handler");
  return 1;
}
