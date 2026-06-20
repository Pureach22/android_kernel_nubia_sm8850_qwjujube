__int64 __fastcall msm_vidc_mem_protect_video_regions_v1(__int64 a1)
{
  __int64 v1; // x8
  _DWORD *v2; // x23
  unsigned int v4; // w21
  unsigned int v5; // w20
  unsigned int v6; // w19
  int v7; // w8
  __int64 result; // x0
  unsigned int v9; // w19

  v1 = *(_QWORD *)(a1 + 3904);
  v2 = *(_DWORD **)(v1 + 112);
  if ( v2 < &v2[14 * *(unsigned int *)(v1 + 120)] )
  {
    v4 = 0;
    v5 = 0;
    v6 = 0;
    while ( 1 )
    {
      v7 = v2[10];
      if ( (v7 & 2) != 0 && (v6 = v2[2], (msm_vidc_debug & 2) != 0) )
      {
        printk(&unk_94257, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_mem_protect_video_regions_v1");
        if ( (v2[10] & 0x10) != 0 )
        {
LABEL_7:
          v5 = v2[2];
          v4 = v2[3];
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_84A8B, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_mem_protect_video_regions_v1");
        }
      }
      else if ( (v7 & 0x10) != 0 )
      {
        goto LABEL_7;
      }
      v2 += 14;
      if ( (unsigned __int64)v2 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 112LL)
                                 + 56 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 120LL) )
        goto LABEL_12;
    }
  }
  v6 = 0;
  v5 = 0;
  v4 = 0;
LABEL_12:
  result = qcom_scm_mem_protect_video_var(0, v6, v5, v4);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v9 = result;
      printk(&unk_81CAF, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)result);
      return v9;
    }
  }
  return result;
}
