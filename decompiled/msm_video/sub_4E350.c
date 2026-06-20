__int64 __usercall sub_4E350@<X0>(__int64 a1@<X8>)
{
  if ( a1 < 0 )
    JUMPOUT(0x49BEC);
  return msm_vidc_debugfs_init_core();
}
