__int64 __usercall sub_5B974@<X0>(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __arm_mte_increment_tag((void *)(a2 + 720), 3u);
  return msm_vidc_reset_residency_stats(a1);
}
