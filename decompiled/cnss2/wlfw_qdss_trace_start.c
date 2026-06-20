__int64 __fastcall wlfw_qdss_trace_start(__int64 a1)
{
  return wlfw_send_qdss_trace_mode_req(a1, 1, 0);
}
