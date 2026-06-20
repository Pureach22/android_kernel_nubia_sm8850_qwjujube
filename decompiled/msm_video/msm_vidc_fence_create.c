__int64 __fastcall msm_vidc_fence_create(__int64 a1, __int64 a2, int a3, int a4, unsigned int a5)
{
  __int64 result; // x0
  __int64 v7; // x4

  result = msm_vidc_get_sw_fence(a1, a2, a3, a4, a5);
  if ( a1 && !result && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_93108, "err ", a1 + 340, "msm_vidc_fence_create", v7);
    return 0;
  }
  return result;
}
