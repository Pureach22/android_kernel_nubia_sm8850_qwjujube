__int64 __fastcall msm_vidc_subscribe_event(__int64 a1, unsigned int *a2)
{
  int v4; // w8
  __int64 result; // x0

  if ( a1 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_857D6, "high", a1 + 340, "msm_vidc_subscribe_event", *a2);
  }
  v4 = *(_DWORD *)(a1 + 308);
  if ( v4 != 2 )
  {
    result = 0;
    if ( v4 != 1 )
      return result;
    return msm_venc_subscribe_event(a1, a2);
  }
  result = msm_vdec_subscribe_event(a1, a2);
  if ( *(_DWORD *)(a1 + 308) == 1 )
    return msm_venc_subscribe_event(a1, a2);
  return result;
}
