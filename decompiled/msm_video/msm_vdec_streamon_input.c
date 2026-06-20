__int64 __fastcall msm_vdec_streamon_input(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int64 v6; // x10
  __int64 v7; // x19
  _BYTE *v8; // x8
  bool v9; // w12
  bool v10; // cf
  __int64 result; // x0
  unsigned int v12; // w20
  void *v13; // x0

  v6 = 1;
  v7 = a1 + 340;
  v8 = (_BYTE *)(a1 + 4536);
  v9 = 1;
  do
  {
    if ( (*v8 & 0x80) != 0
      && ((~*((_DWORD *)v8 - 4) & 9LL) == 0 || (*((_QWORD *)v8 - 2) & 3LL) == 3
                                            || (*((_QWORD *)v8 - 2) & 0x22LL) == 0x22) )
    {
      break;
    }
    v10 = v6++ >= 0xC4;
    v8 += 168;
    v9 = !v10;
  }
  while ( v6 != 197 );
  if ( v9 && (*(_WORD *)(*(_QWORD *)(a1 + 1856) + 320LL) & 1) == 0 )
  {
    if ( !a1 )
      return 4294967274LL;
    result = 4294967274LL;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v12 = -22;
      v13 = &unk_8651D;
LABEL_45:
      printk(v13, "err ", v7, "msm_vdec_streamon_input", a5);
      return v12;
    }
    return result;
  }
  result = msm_vidc_check_session_supported(a1);
  if ( !(_DWORD)result )
  {
    result = msm_vidc_set_v4l2_properties(a1);
    if ( !(_DWORD)result )
    {
      if ( *(_QWORD *)(a1 + 13928) && (msm_vidc_check_input_fence_allowed(a1) & 1) == 0 )
      {
        result = 4294967274LL;
      }
      else
      {
        result = msm_vidc_get_internal_buffers(a1, 7);
        if ( !(_DWORD)result )
        {
          result = msm_vidc_get_internal_buffers(a1, 9);
          if ( !(_DWORD)result )
          {
            result = msm_vidc_get_internal_buffers(a1, 10);
            if ( !(_DWORD)result )
            {
              result = msm_vidc_get_internal_buffers(a1, 11);
              if ( !(_DWORD)result )
              {
                result = msm_vidc_get_internal_buffers(a1, 15);
                if ( !(_DWORD)result )
                {
                  result = msm_vdec_destroy_internal_buffers(a1, 0);
                  if ( !(_DWORD)result )
                  {
                    result = msm_vdec_create_input_internal_buffers(a1);
                    if ( !(_DWORD)result )
                    {
                      result = msm_vdec_queue_input_internal_buffers(a1);
                      if ( !(_DWORD)result )
                      {
                        if ( (*(_BYTE *)(v7 + 3765) & 1) != 0 )
                        {
LABEL_30:
                          result = msm_vdec_subscribe_property(a1, 0);
                          if ( !(_DWORD)result )
                          {
                            result = msm_vdec_subscribe_metadata(a1, 0);
                            if ( !(_DWORD)result )
                            {
                              result = msm_vdec_subscribe_metadata(a1, 1u);
                              if ( !(_DWORD)result )
                              {
                                result = msm_vdec_set_delivery_mode_property(a1, 0);
                                if ( !(_DWORD)result )
                                {
                                  result = msm_vdec_set_delivery_mode_metadata(a1, 0);
                                  if ( !(_DWORD)result )
                                  {
                                    result = msm_vidc_process_streamon_input(a1);
                                    if ( !(_DWORD)result )
                                    {
                                      result = msm_vidc_flush_ts(a1);
                                      if ( !(_DWORD)result )
                                      {
                                        result = msm_vidc_ts_reorder_flush(a1);
                                        if ( !(_DWORD)result )
                                          return result;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          goto LABEL_41;
                        }
                        result = msm_vdec_subscribe_input_port_settings_change(a1);
                        if ( !(_DWORD)result )
                        {
                          *(_BYTE *)(v7 + 3765) = 1;
                          goto LABEL_30;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_41:
  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    v12 = result;
    v13 = &unk_8B2F9;
    goto LABEL_45;
  }
  return result;
}
