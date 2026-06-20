__int64 __usercall sub_3DBEE8@<X0>(__int64 a1@<X8>)
{
  if ( (a1 & 0x4000000000000LL) == 0 )
    JUMPOUT(0x3DC9DC);
  return dot11f_unpack_ff_sm_power_mode_set();
}
