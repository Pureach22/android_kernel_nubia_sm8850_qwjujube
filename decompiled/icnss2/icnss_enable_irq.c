__int64 __fastcall icnss_enable_irq(__int64 a1, unsigned int a2)
{
  __int64 v3; // x0

  if ( penv && a1 && *(_QWORD *)(penv + 8) )
  {
    ipc_log_string(
      icnss_ipc_log_long_context,
      "icnss2: Enable IRQ: ce_id: %d, state: 0x%lx\n",
      a2,
      *(_QWORD *)(penv + 1832));
    if ( a2 >= 0xC )
    {
      printk("%sicnss2: Invalid CE ID to enable IRQ, ce_id: %d\n", byte_130B32, a2);
      return ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2: Invalid CE ID to enable IRQ, ce_id: %d\n",
               (const char *)&unk_12DBF3,
               a2);
    }
    else
    {
      v3 = *(unsigned int *)(penv + 4LL * a2 + 348);
      ++*(_DWORD *)(penv + 16LL * a2 + 2324);
      return enable_irq(v3);
    }
  }
  else
  {
    printk("%sicnss2: Platform driver not initialized\n", byte_130B32);
    return ipc_log_string(
             icnss_ipc_log_context,
             "%sicnss2: Platform driver not initialized\n",
             (const char *)&unk_12DBF3);
  }
}
