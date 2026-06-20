__int64 __fastcall msm_vidc_process_streamon_output(__int64 a1)
{
  char v2; // w20
  int v3; // w8
  int v4; // w22
  __int64 result; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x4
  __int64 v11; // x2
  unsigned int v12; // w20
  __int64 v13; // x1

  msm_vidc_scale_power(a1, 1);
  if ( (is_sub_state(a1, 2) & 1) != 0 )
    v2 = is_sub_state(a1, 8);
  else
    v2 = 0;
  if ( (is_sub_state(a1, 1) & 1) != 0 )
  {
    if ( (is_sub_state(a1, 4) & 1) != 0 )
      v3 = 5;
    else
      v3 = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( (v2 & 1) != 0 )
    v4 = 10;
  else
    v4 = v3;
  if ( *(_DWORD *)(a1 + 308) != 2 || (is_sub_state(a1, 16) & 1) == 0 )
    goto LABEL_25;
  result = msm_vdec_get_input_internal_buffers(a1);
  if ( !(_DWORD)result )
  {
    result = msm_vdec_release_input_internal_buffers(a1, v6, v7, v8, v9);
    if ( !(_DWORD)result )
    {
      result = msm_vdec_create_input_internal_buffers(a1);
      if ( !(_DWORD)result )
      {
        result = msm_vdec_queue_input_internal_buffers(a1);
        if ( !(_DWORD)result )
        {
          result = msm_vidc_set_stage(a1);
          if ( !(_DWORD)result )
          {
            result = msm_vidc_set_pipe(a1);
            if ( !(_DWORD)result )
            {
              if ( a1 && (msm_vidc_debug & 4) != 0 )
                printk(&unk_9095C, "low ", a1 + 340, "msm_vidc_process_streamon_output", v10);
              result = msm_vdec_subscribe_metadata(a1, 0);
              if ( !(_DWORD)result )
              {
LABEL_25:
                if ( (is_sub_state(a1, 16) & 1) == 0 || (is_state(a1, 1) & 1) == 0 )
                  goto LABEL_34;
                if ( a1 && (msm_vidc_debug & 2) != 0 )
                  printk(&unk_96D72, "high", a1 + 340, "msm_vidc_process_streamon_output", v2 & 1);
                if ( (v2 & 1) != 0 )
                  v11 = 16777228;
                else
                  v11 = 16777223;
                result = venus_hfi_session_resume(a1, 0, v11);
                if ( !(_DWORD)result )
                {
                  v4 |= 0x10u;
LABEL_34:
                  if ( (is_sub_state(a1, 64) & 1) != 0 )
                    v12 = v4 | 0x40;
                  else
                    v12 = v4;
                  result = venus_hfi_start(a1, 1);
                  if ( !(_DWORD)result )
                  {
                    if ( (is_sub_state(a1, 32) & 1) == 0
                      || (result = msm_vidc_change_sub_state(a1, 32, 0, "msm_vidc_process_streamon_output"),
                          !(_DWORD)result) )
                    {
                      if ( (is_state(a1, 0) & 1) != 0 )
                      {
                        v13 = 2;
                      }
                      else if ( (is_state(a1, 1) & 1) != 0 )
                      {
                        v13 = 3;
                      }
                      else
                      {
                        v13 = 5;
                      }
                      result = msm_vidc_change_state(a1, v13, "msm_vidc_state_change_streamon");
                      if ( !(_DWORD)result )
                        return msm_vidc_change_sub_state(a1, v12, 0, "msm_vidc_process_streamon_output");
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
  return result;
}
