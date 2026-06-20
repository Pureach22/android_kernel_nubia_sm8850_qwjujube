__int64 __fastcall cam_req_mgr_debug_record_bind_time(__int64 result)
{
  cam_driver_bind_latency_in_usec = result;
  return result;
}
