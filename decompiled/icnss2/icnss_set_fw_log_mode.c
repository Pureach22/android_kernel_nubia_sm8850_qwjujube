__int64 __fastcall icnss_set_fw_log_mode(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 result; // x0
  unsigned int v5; // w20

  if ( !a1 )
    return 4294967277LL;
  v2 = *(_QWORD *)(a1 + 152);
  if ( v2 )
  {
    if ( (*(_QWORD *)(penv + 1832) & 0x2000) != 0 || (*(_QWORD *)(penv + 1832) & 4) == 0 )
    {
      printk("%sicnss2: FW down, ignoring fw_log_mode state: 0x%lx\n", byte_130B32, *(_QWORD *)(v2 + 1832));
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: FW down, ignoring fw_log_mode state: 0x%lx\n",
        (const char *)&unk_12DBF3,
        *(_QWORD *)(v2 + 1832));
      return 4294967274LL;
    }
    else
    {
      ipc_log_string(icnss_ipc_log_context, "icnss2: FW log mode: %u\n", (unsigned __int8)a2);
      result = wlfw_ini_send_sync_msg(v2, a2);
      if ( (_DWORD)result )
      {
        v5 = result;
        printk("%sicnss2: Fail to send ini, ret = %d, fw_log_mode: %u\n", byte_130B32, result, (unsigned __int8)a2);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: Fail to send ini, ret = %d, fw_log_mode: %u\n",
          (const char *)&unk_12DBF3,
          v5,
          (unsigned __int8)a2);
        return v5;
      }
    }
  }
  else
  {
    printk("%sicnss2: Platform driver not initialized\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Platform driver not initialized\n", (const char *)&unk_12DBF3);
    return 4294967274LL;
  }
  return result;
}
