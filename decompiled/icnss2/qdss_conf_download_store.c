__int64 __fastcall qdss_conf_download_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  icnss_wlfw_qdss_dnld_send_sync(*(_QWORD *)(a1 + 152));
  ipc_log_string(icnss_ipc_log_context, "icnss2: Received QDSS download config command\n");
  return a4;
}
