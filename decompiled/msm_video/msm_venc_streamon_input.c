__int64 __fastcall msm_venc_streamon_input(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int64 v6; // x10
  _BYTE *v7; // x8
  bool v8; // w12
  bool v9; // cf
  __int64 result; // x0
  unsigned int v11; // w20
  void *v12; // x0
  __int64 v13; // x4
  unsigned int hfi_port; // w0
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v6 = 1;
  v7 = (_BYTE *)(a1 + 4536);
  v8 = 1;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  do
  {
    if ( (*v7 & 0x80) != 0
      && ((~*((_DWORD *)v7 - 4) & 9LL) == 0 || (*((_QWORD *)v7 - 2) & 3LL) == 3
                                            || (*((_QWORD *)v7 - 2) & 0x22LL) == 0x22) )
    {
      break;
    }
    v9 = v6++ >= 0xC4;
    v7 += 168;
    v8 = !v9;
  }
  while ( v6 != 197 );
  if ( !v8 || (*(_WORD *)(*(_QWORD *)(a1 + 1856) + 320LL) & 1) != 0 )
  {
    result = msm_vidc_check_session_supported(a1);
    if ( (_DWORD)result )
      goto LABEL_37;
    result = msm_vidc_check_scaling_supported(a1);
    if ( (_DWORD)result )
      goto LABEL_37;
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_9602D, "high", a1 + 340, "msm_venc_set_input_properties", a5);
    result = msm_venc_set_colorformat(a1, 0);
    if ( (_DWORD)result )
      goto LABEL_37;
    v13 = *(unsigned int *)(a1 + 392);
    v15 = *(_DWORD *)(a1 + 396) | ((_DWORD)v13 << 16);
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_802B8, "high", a1 + 340, "msm_venc_set_raw_resolution", v13);
    hfi_port = get_hfi_port(a1, 0);
    result = venus_hfi_session_property(a1, 50332024, 0, hfi_port, 10, &v15, 4);
    if ( (_DWORD)result )
      goto LABEL_37;
    result = msm_venc_set_crop_offsets(a1, 0);
    if ( (_DWORD)result )
      goto LABEL_37;
    result = msm_venc_set_stride_scanline(a1, 0);
    if ( (_DWORD)result )
      goto LABEL_37;
    result = msm_venc_set_colorspace(a1, 0);
    if ( (_DWORD)result )
      goto LABEL_37;
    result = msm_vidc_get_internal_buffers(a1, 14);
    if ( (_DWORD)result
      || (result = msm_venc_destroy_internal_buffers(a1, 0), (_DWORD)result)
      || (result = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_create_internal_buffers)(a1, 14), (_DWORD)result)
      || (result = msm_vidc_queue_internal_buffers(a1, 14), (_DWORD)result)
      || (result = msm_venc_property_subscription(a1, 0), (_DWORD)result)
      || (result = msm_venc_metadata_delivery(a1), (_DWORD)result)
      || (result = msm_venc_dynamic_metadata_delivery(a1), (_DWORD)result)
      || (result = msm_vidc_process_streamon_input(a1), (_DWORD)result) )
    {
LABEL_37:
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v11 = result;
        v12 = &unk_8B2F9;
        goto LABEL_41;
      }
    }
  }
  else if ( a1 )
  {
    result = 4294967274LL;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v11 = -22;
      v12 = &unk_8651D;
LABEL_41:
      printk(v12, "err ", a1 + 340, "msm_venc_streamon_input", a5);
      result = v11;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
