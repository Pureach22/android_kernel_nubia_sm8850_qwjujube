__int64 __usercall sub_36D90@<X0>(__int64 a1@<X8>)
{
  __arm_mte_increment_tag((void *)(a1 + 720), 3u);
  return _power_off_iris4();
}
