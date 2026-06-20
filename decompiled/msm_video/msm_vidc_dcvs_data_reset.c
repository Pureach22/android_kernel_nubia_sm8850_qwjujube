unsigned int *__fastcall msm_vidc_dcvs_data_reset(unsigned int *result)
{
  __int64 v1; // x4
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x4
  unsigned int v5; // w8
  unsigned int v6; // w6
  unsigned int v7; // w8

  v1 = result[77];
  if ( (_DWORD)v1 == 1 )
  {
    v2 = 632;
    v3 = 630;
    goto LABEL_5;
  }
  if ( (_DWORD)v1 == 2 )
  {
    v2 = 642;
    v3 = 640;
LABEL_5:
    v4 = result[v3];
    v5 = result[v2];
    result[498] = 0;
    result[480] = v4;
    if ( (int)v4 + 4 >= v5 )
      v6 = v5;
    else
      v6 = v4 + 4;
    v7 = v6 - v4;
    result[482] = v6;
    if ( v6 < (unsigned int)v4 )
      v7 = 0;
    result[484] = v7;
    result[481] = v4 + (v7 >> 1);
    if ( result )
    {
      if ( (msm_vidc_debug & 8) != 0 )
        return (unsigned int *)printk(&unk_87744, "perf", result + 85, "msm_vidc_dcvs_data_reset", v4);
    }
    return result;
  }
  if ( result && (msm_vidc_debug & 1) != 0 )
    return (unsigned int *)printk(&unk_96F4A, "err ", result + 85, "msm_vidc_dcvs_data_reset", v1);
  return result;
}
