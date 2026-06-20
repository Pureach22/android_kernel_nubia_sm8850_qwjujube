__int64 __fastcall msm_vidc_try_fmt(_DWORD *a1, unsigned int *a2)
{
  int v2; // w8
  __int64 result; // x0
  _DWORD *v6; // x2
  unsigned int v7; // w19

  v2 = a1[77];
  if ( v2 == 2 )
  {
    result = msm_vdec_try_fmt((__int64)a1, a2);
    if ( a1[77] != 1 )
      goto LABEL_6;
    goto LABEL_5;
  }
  result = 0;
  if ( v2 == 1 )
LABEL_5:
    result = msm_venc_try_fmt(a1, a2);
LABEL_6:
  if ( a1 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
  {
    v6 = a1 + 85;
    v7 = result;
    printk(&unk_834A4, "err ", v6, "msm_vidc_try_fmt", *a2);
    return v7;
  }
  return result;
}
