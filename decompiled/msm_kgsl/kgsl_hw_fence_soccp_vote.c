__int64 __fastcall kgsl_hw_fence_soccp_vote(unsigned int a1)
{
  return synx_enable_resources(1024, 1, a1);
}
