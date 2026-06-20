__int64 __fastcall msm_vidc_s_fmt(__int64 a1, unsigned int *a2)
{
  int v2; // w8
  __int64 result; // x0
  __int64 v6; // x2
  unsigned int v7; // w19

  v2 = *(_DWORD *)(a1 + 308);
  if ( v2 == 2 )
  {
    result = msm_vdec_s_fmt(a1, a2);
    if ( *(_DWORD *)(a1 + 308) != 1 )
      goto LABEL_6;
    goto LABEL_5;
  }
  result = 0;
  if ( v2 == 1 )
LABEL_5:
    result = msm_venc_s_fmt(a1, a2);
LABEL_6:
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v6 = a1 + 340;
    v7 = result;
    printk(&unk_945C0, "err ", v6, "msm_vidc_s_fmt", *a2);
    return v7;
  }
  return result;
}
