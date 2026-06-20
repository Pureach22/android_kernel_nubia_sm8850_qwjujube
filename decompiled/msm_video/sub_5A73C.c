__int64 __usercall sub_5A73C@<X0>(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __arm_mte_increment_tag((void *)(a2 + 720), 3u);
  return msm_vidc_init_core_caps(a1);
}
