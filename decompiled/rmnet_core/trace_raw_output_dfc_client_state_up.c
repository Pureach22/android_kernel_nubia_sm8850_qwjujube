__int64 __fastcall trace_raw_output_dfc_client_state_up(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(a1, "DFC Client[%d] connect: instance=%u ep_type=%u iface_id=%u\n", v1[2], v1[3], v1[4], v1[5]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
