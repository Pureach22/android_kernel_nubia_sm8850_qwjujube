__int64 __fastcall trace_raw_output_cam_isp_activated_irq(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "ISP: IRQ ctx=%p ctx_state=%u substate=%u event=%u ts=%llu link_hdl=0x%x\n",
      *(const void **)(v1 + 8),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 24),
      *(_QWORD *)(v1 + 32),
      *(_DWORD *)(v1 + 40));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
