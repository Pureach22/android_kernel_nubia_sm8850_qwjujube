__int64 __fastcall msm_vidc_mem_protect_video_regions_v2(__int64 a1)
{
  __int64 v1; // x8
  unsigned int *v2; // x23
  unsigned int v4; // w8
  unsigned int v5; // w20
  __int64 result; // x0
  unsigned int v7; // w19

  v1 = *(_QWORD *)(a1 + 3904);
  v2 = *(unsigned int **)(v1 + 112);
  if ( v2 >= &v2[14 * *(unsigned int *)(v1 + 120)] )
    return 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v4 = v2[10];
    if ( (v4 & 2) != 0 )
      break;
    if ( (v4 & 0x10) != 0 )
    {
      v5 = 1;
      goto LABEL_8;
    }
LABEL_3:
    v2 += 14;
    if ( (unsigned __int64)v2 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 112LL)
                               + 56 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 120LL) )
      return 0;
  }
  v5 = 5;
LABEL_8:
  result = qcom_scm_mem_protect_video_var(v5, 0, v2[2], v2[3]);
  if ( !(_DWORD)result )
    goto LABEL_3;
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v7 = result;
    printk(&unk_81CE8, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_mem_protect_video_regions_v2");
    return v7;
  }
  return result;
}
