__int64 __fastcall icnss_host_ramdump_dev_release(__int64 a1)
{
  ipc_log_string(icnss_ipc_log_context, "icnss2: free host ramdump device\n");
  return kfree(a1);
}
