__int64 __fastcall msm_vdec_start_cmd(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int v6; // w8
  __int64 v7; // x4
  __int64 result; // x0
  __int64 buffers; // x0
  __int64 v10; // x20
  unsigned int v11; // w21
  _QWORD *v12; // x8
  unsigned int v13; // w5

  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_871F7, "high", a1 + 340, a4, a5);
  *(_WORD *)(*(_QWORD *)(a1 + 1864) + 320LL) &= ~0x200u;
  *(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) &= ~0x200u;
  if ( *(_QWORD *)(a1 + 31904) == 1 )
  {
    v6 = *(_DWORD *)(a1 + 18128);
    if ( (v6 > 0x20 || ((1LL << v6) & 0x100000102LL) == 0) && v6 != 128 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_8D5C0, "err ", a1 + 340, "msm_vdec_start_cmd", a5);
      return 4294967274LL;
    }
  }
  *(_BYTE *)(a1 + 3680) = msm_vidc_allow_decode_batch(a1) & 1;
  msm_vidc_allow_dcvs(a1);
  msm_vidc_power_data_reset(a1);
  if ( (is_sub_state(a1, 2) & 1) != 0 && (is_sub_state(a1, 8) & 1) != 0 && (is_sub_state(a1, 16) & 1) != 0 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_96B7C, "high", a1 + 340, "msm_vdec_start_cmd", v7);
    result = msm_vidc_alloc_and_queue_input_internal_buffers(a1);
    if ( (_DWORD)result )
      return result;
    result = msm_vidc_set_stage(a1);
    if ( (_DWORD)result )
      return result;
    result = msm_vidc_set_pipe(a1);
    if ( (_DWORD)result )
      return result;
  }
  result = msm_vidc_get_internal_buffers(a1, 12);
  if ( (_DWORD)result )
    return result;
  buffers = msm_vidc_get_buffers(a1, 12, "msm_vdec_alloc_and_queue_additional_dpb_buffers");
  if ( !buffers )
    return 4294967274LL;
  v10 = buffers;
  v11 = -1;
  v12 = (_QWORD *)buffers;
  do
  {
    v12 = (_QWORD *)*v12;
    ++v11;
  }
  while ( v12 != (_QWORD *)buffers );
  v13 = *(_DWORD *)(buffers + 16);
  if ( v11 >= v13 )
  {
LABEL_28:
    result = msm_vidc_queue_deferred_buffers(a1, 2);
    if ( !(_DWORD)result )
    {
      msm_vidc_print_buffer_info(a1);
      msm_vidc_print_memory_stats(a1);
      return msm_vidc_process_resume(a1);
    }
    return result;
  }
  if ( !a1 || (msm_vidc_debug & 2) == 0 )
  {
    if ( v11 < v13 )
      goto LABEL_25;
LABEL_27:
    result = msm_vidc_queue_internal_buffers(a1, 12);
    if ( (_DWORD)result )
      return result;
    goto LABEL_28;
  }
  printk(&unk_938AC, "high", a1 + 340, "msm_vdec_alloc_and_queue_additional_dpb_buffers", v11);
  if ( v11 >= *(_DWORD *)(v10 + 16) )
    goto LABEL_27;
LABEL_25:
  while ( 1 )
  {
    result = msm_vidc_create_internal_buffer(a1, 12, v11);
    if ( (_DWORD)result )
      return result;
    if ( ++v11 >= *(_DWORD *)(v10 + 16) )
      goto LABEL_27;
  }
}
