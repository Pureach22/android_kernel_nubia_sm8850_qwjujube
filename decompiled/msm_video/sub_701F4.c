__int64 __usercall sub_701F4@<X0>(__int64 a1@<X8>)
{
  __arm_mte_increment_tag((void *)(a1 + 720), 3u);
  return _hand_off_power_domains();
}
