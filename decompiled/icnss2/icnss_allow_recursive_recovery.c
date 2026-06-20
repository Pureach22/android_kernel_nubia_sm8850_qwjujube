__int64 __fastcall icnss_allow_recursive_recovery(__int64 a1)
{
  *(_BYTE *)(*(_QWORD *)(a1 + 152) + 2977LL) = 1;
  printk("%sicnss2: Recursive recovery allowed for WLAN\n", byte_13289B);
  return ipc_log_string(
           icnss_ipc_log_context,
           "%sicnss2: Recursive recovery allowed for WLAN\n",
           (const char *)&unk_12DBF3);
}
