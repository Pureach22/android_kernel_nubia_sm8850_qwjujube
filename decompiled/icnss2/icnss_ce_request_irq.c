__int64 __fastcall icnss_ce_request_irq(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x20
  __int64 v12; // x26
  unsigned int v13; // w20
  int v14; // w0
  unsigned int v16; // w21

  v6 = *(_QWORD *)(a1 + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 8) )
    return 4294967277LL;
  ipc_log_string(icnss_ipc_log_long_context, "icnss2: CE request IRQ: %d, state: 0x%lx\n", a2, *(_QWORD *)(v6 + 1832));
  if ( a2 >= 0xC )
  {
    printk("%sicnss2: Invalid CE ID, ce_id: %d\n", byte_130B32, a2);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid CE ID, ce_id: %d\n", (const char *)&unk_12DBF3, a2);
    return 4294967274LL;
  }
  else
  {
    v12 = v6 + 16LL * a2;
    v13 = *(_DWORD *)(v6 + 4LL * a2 + 348);
    if ( *(_QWORD *)(v12 + 32) || *(_DWORD *)(v12 + 24) )
    {
      printk("%sicnss2: IRQ already requested: %d, ce_id: %d\n", byte_130B32, v13, a2);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: IRQ already requested: %d, ce_id: %d\n",
        (const char *)&unk_12DBF3,
        v13,
        a2);
      return 4294967279LL;
    }
    else
    {
      v14 = request_threaded_irq(v13, a3, 0, a4 | 0x200000, a5, a6);
      if ( v14 )
      {
        v16 = v14;
        printk("%sicnss2: IRQ request failed: %d, ce_id: %d, ret: %d\n", byte_130B32, v13, a2, v14);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: IRQ request failed: %d, ce_id: %d, ret: %d\n",
          (const char *)&unk_12DBF3,
          v13,
          a2,
          v16);
        return v16;
      }
      else
      {
        *(_DWORD *)(v12 + 24) = v13;
        *(_QWORD *)(v12 + 32) = a3;
        ipc_log_string(icnss_ipc_log_long_context, "icnss2: IRQ requested: %d, ce_id: %d\n", v13, a2);
        ++*(_DWORD *)(penv + 16LL * a2 + 2316);
        return 0;
      }
    }
  }
}
