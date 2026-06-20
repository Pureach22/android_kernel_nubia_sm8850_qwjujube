void __fastcall perf_trace_process_accept_req_wait(__int64 a1)
{
  _ReadStatusReg(SP_EL0);
  _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(a1 + 112) )
    JUMPOUT(0xAAE4);
  JUMPOUT(0xAAEC);
}
