__int64 __fastcall ims_subscribe_for_indication_resp_cb(__int64 a1, __int64 a2, __int64 a3, unsigned __int16 *a4)
{
  __int64 result; // x0

  result = ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Received IMS subscribe indication response\n");
  if ( a3 )
  {
    if ( *a4 )
    {
      printk(
        "%sicnss2_qmi: IMS subscribe for indication request rejected, result:%d error:%d\n",
        byte_130B32,
        *a4,
        a4[1]);
      result = ipc_log_string(
                 icnss_ipc_log_context,
                 "%sicnss2_qmi: IMS subscribe for indication request rejected, result:%d error:%d\n",
                 (const char *)&unk_12DBF3,
                 *a4,
                 a4[1]);
      *(_DWORD *)(a3 + 48) = -*a4;
    }
  }
  else
  {
    printk("%sicnss2_qmi: spurious response\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: spurious response\n", (const char *)&unk_12DBF3);
  }
  return result;
}
