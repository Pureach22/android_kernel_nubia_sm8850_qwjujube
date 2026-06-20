__int64 __usercall sub_30040@<X0>(__int64 a1@<X8>)
{
  __arm_mte_increment_tag((void *)(a1 + 720), 3u);
  return msm_vidc_mem_protect_video_regions_v1();
}
