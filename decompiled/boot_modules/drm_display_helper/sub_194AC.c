__int64 __usercall sub_194AC@<X0>(__int64 a1@<X8>)
{
  if ( (a1 & 0x40000000000000LL) != 0 )
    JUMPOUT(0x16640);
  return drm_dsc_pps_payload_pack();
}
