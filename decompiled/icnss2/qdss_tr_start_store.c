__int64 __fastcall qdss_tr_start_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  wlfw_qdss_trace_start(*(_QWORD *)(a1 + 152));
  ipc_log_string(icnss_ipc_log_context, "icnss2: Received QDSS start command\n");
  return a4;
}
