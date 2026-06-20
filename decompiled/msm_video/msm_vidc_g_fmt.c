__int64 __fastcall msm_vidc_g_fmt(__int64 a1, unsigned int *a2)
{
  int v2; // w8
  __int64 result; // x0
  unsigned int v6; // w8
  __int64 v7; // x21
  __int64 v8; // x0

  v2 = *(_DWORD *)(a1 + 308);
  if ( v2 != 2 )
  {
    result = 0;
    if ( v2 != 1 )
      goto LABEL_6;
    goto LABEL_5;
  }
  result = ((__int64 (__fastcall *)(__int64, unsigned int *))msm_vdec_g_fmt)(a1, a2);
  if ( *(_DWORD *)(a1 + 308) == 1 )
LABEL_5:
    result = ((__int64 (__fastcall *)(__int64, unsigned int *))msm_venc_g_fmt)(a1, a2);
LABEL_6:
  if ( (_DWORD)result )
    return result;
  v6 = *a2;
  if ( *a2 - 9 >= 2 )
  {
    if ( v6 == 14 )
    {
      if ( !a1 )
        return result;
    }
    else if ( !a1 || v6 != 13 )
    {
      return result;
    }
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v8 = v4l2_type_name(v6);
      printk(&unk_80381, "high", a1 + 340, "msm_vidc_g_fmt", v8);
      return 0;
    }
  }
  else if ( a1 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v7 = v4l2_type_name(v6);
      v4l2_pixelfmt_name(a1, a2[4]);
      printk(&unk_945EE, "high", a1 + 340, "msm_vidc_g_fmt", v7);
      return 0;
    }
  }
  return result;
}
