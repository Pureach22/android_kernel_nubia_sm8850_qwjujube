__int64 __fastcall icnss_recovery_timeout_hdlr(__int64 result)
{
  __int64 v1; // x2
  __int64 v2; // x20

  if ( !*(_BYTE *)(result - 40) )
  {
    v1 = *(_QWORD *)(result - 4184);
    goto LABEL_5;
  }
  v1 = *(_QWORD *)(result - 4184);
  if ( (v1 & 0x1000000) != 0 )
  {
LABEL_5:
    v2 = result;
    printk("%sicnss2: Timeout waiting for FW Ready 0x%lx\n", byte_130B32, v1);
    return ipc_log_string(
             icnss_ipc_log_context,
             "%sicnss2: Timeout waiting for FW Ready 0x%lx\n",
             (const char *)&unk_12DBF3,
             *(_QWORD *)(v2 - 4184));
  }
  return result;
}
