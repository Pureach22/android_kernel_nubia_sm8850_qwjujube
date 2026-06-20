__int64 __fastcall msm_vidc_start_streaming(__int64 a1, int *a2, __int64 a3, __int64 a4)
{
  unsigned int v5; // w0
  __int64 result; // x0
  __int64 v7; // x4
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  int v17; // w8
  void *v18; // x0
  int v19; // w8
  const char *v20; // x0
  unsigned int v21; // w0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x4
  __int64 v26; // x8
  const char *v27; // x0
  __int64 v28; // x4
  int v29; // w8
  __int64 v30; // x0
  unsigned int v31; // w1
  const char *v32; // x0
  __int64 v33; // x4

  v5 = *a2;
  if ( (unsigned int)(*a2 - 9) >= 2 )
  {
    if ( v5 - 13 <= 1 )
    {
      if ( a1 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
        {
          v20 = v4l2_type_name(v5);
          printk(&unk_85E18, "high", a1 + 340, "msm_vidc_start_streaming", v20);
        }
      }
      return 0;
    }
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v7 = v5;
    v18 = &unk_9531A;
LABEL_46:
    printk(v18, "err ", a1 + 340, "msm_vidc_start_streaming", v7);
    return 4294967274LL;
  }
  v7 = *(unsigned int *)(a1 + 308);
  if ( (unsigned int)(v7 - 1) >= 2 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      v18 = &unk_92A7E;
      goto LABEL_46;
    }
    return 4294967274LL;
  }
  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    v27 = v4l2_type_name(v5);
    printk(&unk_94D86, "high", a1 + 340, v27, v28);
    if ( (*(_BYTE *)(a1 + 4104) & 1) != 0 )
      goto LABEL_11;
  }
  else if ( (*(_BYTE *)(a1 + 4104) & 1) != 0 )
  {
    goto LABEL_11;
  }
  *(_BYTE *)(a1 + 4104) = 1;
  result = msm_vidc_session_set_codec();
  if ( (_DWORD)result )
    return result;
  result = msm_vidc_session_set_secure_mode();
  if ( (_DWORD)result )
    return result;
  v29 = *(_DWORD *)(a1 + 308);
  if ( v29 == 2 )
  {
    result = msm_vidc_session_set_default_header(a1);
    if ( (_DWORD)result )
      return result;
    v30 = a1;
    v31 = 13;
  }
  else
  {
    if ( v29 != 1 )
      goto LABEL_13;
    v30 = a1;
    v31 = 8;
  }
  result = msm_vidc_alloc_and_queue_session_internal_buffers(v30, v31);
  if ( (_DWORD)result )
    return result;
LABEL_11:
  if ( *(_DWORD *)(a1 + 308) == 2 )
    *(_BYTE *)(a1 + 3680) = msm_vidc_allow_decode_batch(a1, (__int64)a2, a3, a4, v7) & 1;
LABEL_13:
  msm_vidc_allow_dcvs(a1, (__int64)a2, a3, a4, v7);
  msm_vidc_power_data_reset(a1, v9, v10, v11, v12);
  if ( *a2 == 9 )
  {
    v19 = *(_DWORD *)(a1 + 308);
    if ( v19 == 1 )
    {
      result = msm_venc_streamon_output(a1, v13, v14, v15, v16);
    }
    else
    {
      if ( v19 != 2 )
        goto LABEL_31;
      result = ((__int64 (__fastcall *)(__int64))msm_vdec_streamon_output)(a1);
    }
  }
  else
  {
    if ( *a2 != 10 )
      goto LABEL_31;
    v17 = *(_DWORD *)(a1 + 308);
    if ( v17 == 1 )
    {
      result = msm_venc_streamon_input(a1, v13, v14, v15, v16);
    }
    else
    {
      if ( v17 != 2 )
        goto LABEL_31;
      result = msm_vdec_streamon_input(a1, v13, v14, v15, v16);
    }
  }
  if ( (_DWORD)result )
    return result;
LABEL_31:
  msm_vidc_print_buffer_info(a1);
  msm_vidc_print_memory_stats(a1);
  v21 = v4l2_type_to_driver(*a2, (__int64)"msm_vidc_start_streaming");
  if ( !v21 )
    return 4294967274LL;
  result = msm_vidc_queue_deferred_buffers((__int64 ***)a1, v21);
  if ( !(_DWORD)result )
  {
    if ( !*(_QWORD *)(a1 + 4304) )
      *(_QWORD *)(a1 + 4304) = ktime_get(result) / 0xF4240uLL;
    result = schedule_stats_work((_QWORD *)a1, v22, v23, v24, v25);
    if ( !(_DWORD)result )
    {
      if ( *a2 == 9 )
      {
        v26 = *(_QWORD *)(a1 + 1840);
      }
      else
      {
        if ( *a2 != 10 )
          goto LABEL_53;
        v26 = *(_QWORD *)(a1 + 1848);
      }
      if ( (*(_WORD *)(v26 + 320) & 1) == 0 )
      {
LABEL_53:
        if ( !a1 )
          return 0;
LABEL_57:
        if ( (msm_vidc_debug & 2) != 0 )
        {
          v32 = v4l2_type_name(*a2);
          printk(&unk_89F29, "high", a1 + 340, v32, v33);
        }
        return 0;
      }
      result = msm_vidc_get_properties(a1);
      if ( a1 && !(_DWORD)result )
        goto LABEL_57;
    }
  }
  return result;
}
