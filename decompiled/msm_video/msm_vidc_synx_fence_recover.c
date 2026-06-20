__int64 __fastcall msm_vidc_synx_fence_recover(__int64 a1)
{
  __int64 result; // x0

  result = synx_recover(*(unsigned int *)(a1 + 6616));
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      return printk(&unk_8DB79, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_synx_fence_recover");
  }
  return result;
}
