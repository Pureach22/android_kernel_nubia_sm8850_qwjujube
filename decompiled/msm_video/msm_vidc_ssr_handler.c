__int64 __fastcall msm_vidc_ssr_handler(__int64 result)
{
  __int64 v1; // x21
  unsigned int *v2; // x20
  void *v3; // x0

  v1 = result - 6336;
  if ( result != 6336 )
  {
    v2 = (unsigned int *)result;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      core_state_name(*(unsigned int *)(result - 2632));
      printk(&unk_8F140, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_ssr_handler");
    }
    mutex_lock(v2 - 620);
    if ( (is_core_state(v1, 2) & 1) != 0 )
    {
      if ( !(unsigned int)venus_hfi_trigger_ssr(v1, v2[24], v2[25], v2[26]) || (msm_vidc_debug & 1) == 0 )
        return mutex_unlock(v2 - 620);
      v3 = &unk_8B5A5;
    }
    else
    {
      if ( (msm_vidc_debug & 1) == 0 )
        return mutex_unlock(v2 - 620);
      v3 = &unk_9245D;
    }
    printk(v3, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_ssr_handler");
    return mutex_unlock(v2 - 620);
  }
  if ( (msm_vidc_debug & 1) != 0 )
    return printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_ssr_handler");
  return result;
}
