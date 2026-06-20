__int64 __fastcall wlfw_qdss_trace_free_ind_cb(__int64 a1)
{
  return icnss_driver_event_post(a1 - 624, 0xCu, 0, 0);
}
