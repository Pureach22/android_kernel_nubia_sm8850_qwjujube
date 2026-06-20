__int64 __fastcall msm_vidc_fence_create_fd(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x4
  unsigned int v6; // w19

  result = msm_vidc_get_sw_fence_fd(a1, a2);
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v5 = a2 + 16;
    v6 = result;
    printk(&unk_82C7A, "err ", a1 + 340, "msm_vidc_fence_create_fd", v5);
    return v6;
  }
  return result;
}
