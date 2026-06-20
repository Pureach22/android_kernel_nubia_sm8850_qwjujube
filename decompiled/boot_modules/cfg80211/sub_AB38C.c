__int64 __fastcall sub_AB38C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (a4 & 0x200000000000000LL) == 0 )
    JUMPOUT(0xAB914);
  return _bpf_trace_rdev_set_mcast_rate();
}
