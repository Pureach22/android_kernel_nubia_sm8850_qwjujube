__int64 __fastcall sub_4033C(__int64 a1, __int64 a2, __int64 a3)
{
  if ( !a3 )
    JUMPOUT(0xC7698);
  return _bpf_trace_sched_get_nr_running_avg();
}
