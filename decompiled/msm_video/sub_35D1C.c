__int64 __usercall sub_35D1C@<X0>(__int64 a1@<X8>)
{
  __arm_mte_increment_tag((void *)(a1 + 720), 3u);
  return _raise_interrupt_iris4();
}
