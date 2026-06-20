__int64 __usercall sub_764C4@<X0>(__int64 a1@<X8>)
{
  __arm_mte_increment_tag((void *)(a1 + 720), 3u);
  return venus_hfi_noc_error_info();
}
