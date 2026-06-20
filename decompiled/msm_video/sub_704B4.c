__int64 __usercall sub_704B4@<X0>(__int64 a1@<X8>)
{
  __arm_mte_increment_tag((void *)(a1 + 720), 3u);
  return _acquire_power_domains();
}
