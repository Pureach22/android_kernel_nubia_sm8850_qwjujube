__int64 __fastcall wlfw_qdss_trace_stop(__int64 a1, __int64 a2)
{
  return wlfw_send_qdss_trace_mode_req(a1, 0, a2);
}
