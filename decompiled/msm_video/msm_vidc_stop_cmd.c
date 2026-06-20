__int64 __fastcall msm_vidc_stop_cmd(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x4
  __int64 result; // x0

  v4 = *(unsigned int *)(a1 + 308);
  if ( (_DWORD)v4 == 1 )
  {
    result = msm_venc_stop_cmd(a1, a2, a3, a4, v4);
    if ( (_DWORD)result )
      return result;
    return 0;
  }
  if ( (_DWORD)v4 == 2 )
  {
    result = msm_vdec_stop_cmd(a1, a2, a3, a4, v4);
    if ( (_DWORD)result )
      return result;
    return 0;
  }
  if ( a1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_92A7E, "err ", a1 + 340, "msm_vidc_stop_cmd", v4);
  }
  return 4294967274LL;
}
