__int64 sub_A2B0()
{
  __int64 v0; // x12

  if ( (v0 & 0x80000000000000LL) != 0 )
    JUMPOUT(0x9330);
  return trace_event_raw_event_process_invoke_req_wait();
}
