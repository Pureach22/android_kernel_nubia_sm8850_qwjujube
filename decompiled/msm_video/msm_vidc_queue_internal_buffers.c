__int64 __fastcall msm_vidc_queue_internal_buffers(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  _QWORD *v4; // x24
  _QWORD *v5; // x23
  _QWORD *v6; // x28
  __int64 v7; // x8
  const char *v8; // x4
  const char *v9; // x4

  if ( a2 - 7 >= 9 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      if ( a2 <= 0xF )
        v9 = buf_type_name_arr[a2];
      else
        v9 = "UNKNOWN BUF";
      printk(&unk_9490C, "err ", a1 + 340, "msm_vidc_queue_internal_buffers", v9);
    }
    return 0;
  }
  if ( a2 != 9 || *(_DWORD *)(a1 + 308) != 2 )
  {
    v4 = (_QWORD *)(a1 + 40 * (a2 - 7) + 2704);
    if ( !v4 )
      return 4294967274LL;
    goto LABEL_11;
  }
  result = msm_vdec_set_num_comv(a1);
  if ( (_DWORD)result )
    return result;
  v4 = (_QWORD *)(a1 + 2784);
  if ( a1 != -2784 )
  {
LABEL_11:
    v5 = (_QWORD *)*v4;
    if ( (_QWORD *)*v4 != v4 )
    {
      while ( 1 )
      {
        v6 = (_QWORD *)*v5;
        if ( (v5[10] & 0xC) == 0 )
        {
          result = venus_hfi_queue_internal_buffer(a1, v5);
          if ( (_DWORD)result )
            return result;
          *((_DWORD *)v5 + 20) |= 8u;
          if ( a1 && (msm_vidc_debug & 2) != 0 )
          {
            v7 = *((unsigned int *)v5 + 6);
            v8 = "UNKNOWN BUF";
            if ( (unsigned int)v7 <= 0xF )
              v8 = buf_type_name_arr[v7];
            printk(&unk_85A5B, "high", a1 + 340, "msm_vidc_queue_internal_buffers", v8);
          }
        }
        v5 = v6;
        if ( v6 == v4 )
          return 0;
      }
    }
    return 0;
  }
  return 4294967274LL;
}
