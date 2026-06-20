__int64 *__fastcall msm_vidc_stability_handler(__int64 a1)
{
  __int64 *result; // x0
  unsigned int *v2; // x19
  __int64 v3; // x4
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4

  result = get_inst_ref(g_core, (__int64 *)(a1 - 3920));
  if ( result )
  {
    v2 = (unsigned int *)result;
    mutex_lock(result + 2);
    if ( (unsigned int)venus_hfi_trigger_stability(v2, v2[988], v2[989], v2[990]) )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_813C2, "err ", v2 + 85, "msm_vidc_stability_handler", v3);
    }
    mutex_unlock(v2 + 4);
    return (__int64 *)put_inst((__int64)v2, v4, v5, v6, v7);
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    return (__int64 *)printk(&unk_86867, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_stability_handler");
  }
  return result;
}
