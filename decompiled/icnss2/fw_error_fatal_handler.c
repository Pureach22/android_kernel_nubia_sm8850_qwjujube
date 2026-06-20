__int64 __fastcall fw_error_fatal_handler(__int64 a1, __int64 a2)
{
  if ( a2 )
    *(_BYTE *)(a2 + 2976) = 1;
  printk("%sicnss2: Received force error fatal request from FW\n", byte_130B32);
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: Received force error fatal request from FW\n",
    (const char *)&unk_12DBF3);
  return 1;
}
