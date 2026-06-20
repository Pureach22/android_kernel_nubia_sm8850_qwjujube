__int64 __fastcall msm_vidc_g_selection(__int64 a1, unsigned int *a2)
{
  int v2; // w8
  __int64 result; // x0

  v2 = *(_DWORD *)(a1 + 308);
  if ( v2 != 2 )
  {
    result = 0;
    if ( v2 != 1 )
      return result;
    return msm_venc_g_selection(a1, a2);
  }
  result = msm_vdec_g_selection(a1, a2);
  if ( *(_DWORD *)(a1 + 308) == 1 )
    return msm_venc_g_selection(a1, a2);
  return result;
}
