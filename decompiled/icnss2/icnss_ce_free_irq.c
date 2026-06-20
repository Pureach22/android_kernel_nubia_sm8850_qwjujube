__int64 __fastcall icnss_ce_free_irq(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x22
  __int64 v8; // x0
  int v9; // w21

  if ( !penv )
    return 4294967277LL;
  result = 4294967277LL;
  if ( a1 && *(_QWORD *)(penv + 8) )
  {
    ipc_log_string(icnss_ipc_log_long_context, "icnss2: CE free IRQ: %d, state: 0x%lx\n", a2, *(_QWORD *)(penv + 1832));
    if ( a2 >= 0xC )
    {
      printk("%sicnss2: Invalid CE ID to free, ce_id: %d\n", byte_130B32, a2);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Invalid CE ID to free, ce_id: %d\n",
        (const char *)&unk_12DBF3,
        a2);
      return 4294967274LL;
    }
    else
    {
      v7 = penv + 16LL * a2;
      v8 = *(unsigned int *)(penv + 4LL * a2 + 348);
      if ( *(_QWORD *)(v7 + 32) && *(_DWORD *)(v7 + 24) )
      {
        free_irq(v8, a3);
        *(_DWORD *)(v7 + 24) = 0;
        *(_QWORD *)(v7 + 32) = 0;
        ++*(_DWORD *)(penv + 16LL * a2 + 2320);
        return 0;
      }
      else
      {
        v9 = *(_DWORD *)(penv + 4LL * a2 + 348);
        printk("%sicnss2: IRQ not requested: %d, ce_id: %d\n", byte_130B32, v8, a2);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: IRQ not requested: %d, ce_id: %d\n",
          (const char *)&unk_12DBF3,
          v9,
          a2);
        return 4294967279LL;
      }
    }
  }
  return result;
}
