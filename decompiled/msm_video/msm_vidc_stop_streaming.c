__int64 __fastcall msm_vidc_stop_streaming(__int64 result, int *a2)
{
  unsigned int v2; // w8
  __int64 v3; // x19
  const char *v4; // x0
  __int64 v5; // x4
  __int64 v6; // x19
  int v8; // w8
  __int64 v9; // x2
  void *v10; // x0
  const char *v11; // x0
  __int64 v12; // x4
  int v13; // w8
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  const char *v18; // x0
  __int64 v19; // x4

  v2 = *a2;
  if ( (unsigned int)(*a2 - 9) >= 2 )
  {
    if ( v2 - 13 <= 1 )
    {
      if ( !result )
        return result;
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v3 = result;
        v4 = v4l2_type_name(v2);
        printk(&unk_8876E, "high", v3 + 340, "msm_vidc_stop_streaming", v4);
      }
      return 0;
    }
    if ( !result || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v9 = result + 340;
    v10 = &unk_9531A;
    v5 = v2;
LABEL_35:
    printk(v10, "err ", v9, "msm_vidc_stop_streaming", v5);
    return 4294967274LL;
  }
  v5 = *(unsigned int *)(result + 308);
  if ( (unsigned int)(v5 - 1) >= 2 )
  {
    if ( !result || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v9 = result + 340;
    v10 = &unk_92A7E;
    goto LABEL_35;
  }
  v6 = result;
  if ( result && (msm_vidc_debug & 2) != 0 )
  {
    v11 = v4l2_type_name(v2);
    printk(&unk_90E71, "high", v6 + 340, v11, v12);
    v2 = *a2;
    result = v6;
    if ( *a2 != 9 )
    {
LABEL_10:
      if ( v2 == 10 )
      {
        v8 = *(_DWORD *)(result + 308);
        if ( v8 == 1 )
        {
          result = msm_venc_streamoff_input(result);
        }
        else
        {
          if ( v8 != 2 )
          {
LABEL_28:
            msm_vidc_flush_ts(v6);
            msm_vidc_flush_buffer_stats(v6, v14, v15, v16, v17);
            goto LABEL_29;
          }
          result = msm_vdec_streamoff_input(result);
        }
LABEL_26:
        if ( (_DWORD)result )
          return result;
        if ( *a2 != 10 )
          goto LABEL_29;
        goto LABEL_28;
      }
      goto LABEL_29;
    }
  }
  else if ( v2 != 9 )
  {
    goto LABEL_10;
  }
  v13 = *(_DWORD *)(result + 308);
  if ( v13 == 1 )
  {
    result = msm_venc_streamoff_output(result);
    goto LABEL_26;
  }
  if ( v13 == 2 )
  {
    result = msm_vdec_streamoff_output(result);
    goto LABEL_26;
  }
LABEL_29:
  msm_vidc_print_memory_stats(v6);
  if ( v6 && (msm_vidc_debug & 2) != 0 )
  {
    v18 = v4l2_type_name(*a2);
    printk(&unk_90E95, "high", v6 + 340, v18, v19);
  }
  return 0;
}
