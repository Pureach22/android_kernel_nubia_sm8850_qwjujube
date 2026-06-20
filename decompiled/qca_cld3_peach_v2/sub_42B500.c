__int64 __usercall sub_42B500@<X0>(__int64 a1@<X8>)
{
  if ( (a1 & 0x4000000000000LL) == 0 )
    JUMPOUT(0x42BFF4);
  return dot11f_unpack_ff_sm_power_mode_set();
}
