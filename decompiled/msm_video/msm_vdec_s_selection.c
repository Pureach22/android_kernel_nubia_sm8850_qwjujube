__int64 __fastcall msm_vdec_s_selection(__int64 result, unsigned int *a2)
{
  __int64 v2; // x4
  unsigned int *v3; // x20
  __int64 v4; // x19
  void *v5; // x8
  const char *v6; // x4

  v2 = *a2;
  if ( ((unsigned int)v2 | 8) != 9 )
  {
    if ( !result || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v5 = &unk_9531A;
    goto LABEL_25;
  }
  v2 = a2[1];
  if ( (unsigned int)(v2 - 256) < 4 )
  {
    if ( *(__int64 *)(result + 20128) >= 2 )
    {
      v3 = a2;
      v4 = result;
      *(_DWORD *)(result + 1896) = a2[3];
      *(_DWORD *)(result + 1900) = a2[4];
      *(_DWORD *)(result + 1904) = a2[5];
      *(_DWORD *)(result + 1908) = a2[6];
      if ( result && (msm_vidc_debug & 2) != 0 )
        printk(&unk_8D60E, "high", result + 340, "msm_vdec_s_selection", v2);
      ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
        v4,
        95,
        1,
        "msm_vdec_s_selection");
      result = v4;
      a2 = v3;
    }
    goto LABEL_13;
  }
  if ( (unsigned int)v2 > 2 )
  {
    if ( !result || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v5 = &unk_8B32F;
LABEL_25:
    printk(v5, "err ", result + 340, "msm_vdec_s_selection", v2);
    return 4294967274LL;
  }
  *(_DWORD *)(result + 1880) = a2[3];
  *(_DWORD *)(result + 1884) = a2[4];
  *(_DWORD *)(result + 1888) = a2[5];
  *(_DWORD *)(result + 1892) = a2[6];
LABEL_13:
  if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      if ( a2[1] >= 0x100 )
        v6 = "compose";
      else
        v6 = "crop";
      printk(&unk_8BE52, "high", result + 340, "msm_vdec_s_selection", v6);
    }
    return 0;
  }
  return result;
}
