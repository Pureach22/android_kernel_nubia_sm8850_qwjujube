__int64 __fastcall msm_vidc_g_param(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x4

  if ( *a2 - 9 <= 1 )
  {
    v2 = *(unsigned int *)(a1 + 308);
    if ( (_DWORD)v2 == 1 )
      return msm_venc_g_param(a1, a2);
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_801EE, "err ", a1 + 340, "msm_vidc_g_param", v2);
    }
  }
  return 4294967274LL;
}
