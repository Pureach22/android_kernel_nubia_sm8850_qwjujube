__int64 __fastcall msm_venc_g_selection(__int64 result, unsigned int *a2)
{
  __int64 v2; // x4
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x11
  void *v7; // x8

  v2 = *a2;
  if ( ((unsigned int)v2 | 8) != 0xA )
  {
    if ( !result || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v7 = &unk_9531A;
    goto LABEL_18;
  }
  v2 = a2[1];
  if ( (unsigned int)(v2 - 256) < 4 )
  {
    v3 = 1908;
    v4 = 1904;
    v5 = 1900;
    v6 = 1896;
    goto LABEL_9;
  }
  if ( (unsigned int)v2 >= 3 )
  {
    if ( !result || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v7 = &unk_8B32F;
LABEL_18:
    printk(v7, "err ", result + 340, "msm_venc_g_selection", v2);
    return 4294967274LL;
  }
  v3 = 1892;
  v4 = 1888;
  v5 = 1884;
  v6 = 1880;
LABEL_9:
  a2[3] = *(_DWORD *)(result + v6);
  a2[4] = *(_DWORD *)(result + v5);
  a2[5] = *(_DWORD *)(result + v4);
  a2[6] = *(_DWORD *)(result + v3);
  if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_83439, "high", result + 340, "msm_venc_g_selection", v2);
    return 0;
  }
  return result;
}
