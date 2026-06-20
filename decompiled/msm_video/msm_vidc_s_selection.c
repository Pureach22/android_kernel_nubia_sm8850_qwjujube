__int64 __fastcall msm_vidc_s_selection(_DWORD *a1, unsigned int *a2)
{
  int v2; // w8
  __int64 result; // x0

  v2 = a1[77];
  if ( v2 != 2 )
  {
    result = 0;
    if ( v2 != 1 )
      return result;
    return msm_venc_s_selection(a1, a2);
  }
  result = msm_vdec_s_selection((__int64)a1, a2);
  if ( a1[77] == 1 )
    return msm_venc_s_selection(a1, a2);
  return result;
}
