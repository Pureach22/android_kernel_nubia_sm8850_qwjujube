__int64 __fastcall trace_raw_output_cam_req_mgr_add_req(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "ReqMgr AddRequest devname=%s devid=%d request=%lld slot=%d pd=%d readymap=%x devicemap=%d link=%pK session=%pK link_hdl=0x%x\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      *(_DWORD *)(v1 + 12),
      *(_QWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_DWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 36),
      *(const void **)(v1 + 40),
      *(const void **)(v1 + 48),
      *(_DWORD *)(v1 + 56));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
