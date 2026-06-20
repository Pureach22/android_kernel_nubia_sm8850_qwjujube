__int64 __fastcall msm_venc_streamon_output(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int64 v6; // x10
  _BYTE *v7; // x9
  bool v8; // w13
  bool v9; // cf
  __int64 result; // x0
  int v11; // w8
  int v12; // w9
  unsigned int hfi_port; // w0
  __int64 v14; // x4
  __int64 v15; // x8
  __int64 v16; // x8
  unsigned int (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x4
  __int64 v19; // x4
  unsigned int v20; // w21
  __int64 (__fastcall *v21)(__int64, __int64); // x8
  __int64 v22; // x2
  __int64 v23; // x3
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v6 = 1;
  v7 = (_BYTE *)(a1 + 4536);
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 1;
  do
  {
    if ( (*v7 & 0x80) != 0
      && ((~*((_DWORD *)v7 - 4) & 0x11LL) == 0
       || (*((_QWORD *)v7 - 2) & 5LL) == 5
       || (*((_QWORD *)v7 - 2) & 0x24LL) == 0x24) )
    {
      break;
    }
    v9 = v6++ >= 0xC4;
    v7 += 168;
    v8 = !v9;
  }
  while ( v6 != 197 );
  if ( !v8 || (*(_WORD *)(*(_QWORD *)(a1 + 1864) + 320LL) & 1) != 0 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        printk(&unk_9602D, "high", a1 + 340, "msm_venc_set_output_properties", a5);
        v18 = *(unsigned int *)(a1 + 600);
        v24 = *(_DWORD *)(a1 + 604) | ((_DWORD)v18 << 16);
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_802B8, "high", a1 + 340, "msm_venc_set_bitstream_resolution", v18);
LABEL_20:
        hfi_port = get_hfi_port(a1, 1u);
        LODWORD(result) = venus_hfi_session_property(a1, 50331907, 0, hfi_port, 10, &v24, 4);
        if ( (_DWORD)result )
          goto LABEL_43;
        LODWORD(result) = msm_venc_set_crop_offsets(a1, 1);
        if ( (_DWORD)result )
          goto LABEL_43;
        LODWORD(result) = msm_vidc_set_v4l2_properties(a1);
        if ( (_DWORD)result )
          goto LABEL_43;
        if ( a1 && (msm_vidc_debug & 2) != 0 )
        {
          printk(&unk_9602D, "high", a1 + 340, "msm_venc_set_internal_properties", v14);
          v15 = *(_QWORD *)(a1 + 320);
          if ( !v15 )
            goto LABEL_39;
        }
        else
        {
          v15 = *(_QWORD *)(a1 + 320);
          if ( !v15 )
            goto LABEL_39;
        }
        v16 = *(_QWORD *)(v15 + 6560);
        if ( v16 )
        {
          v17 = *(unsigned int (__fastcall **)(_QWORD))(v16 + 32);
          if ( v17 )
          {
            if ( *((_DWORD *)v17 - 1) != 1661903850 )
              __break(0x8228u);
            if ( v17(a1) )
            {
              if ( a1 && (msm_vidc_debug & 1) != 0 )
                printk(&unk_80088, "err ", a1 + 340, "msm_venc_set_quality_mode", v14);
              LODWORD(result) = -22;
              goto LABEL_43;
            }
          }
        }
LABEL_39:
        v19 = *(unsigned int *)(a1 + 33248);
        v24 = *(_DWORD *)(a1 + 33248);
        if ( a1 && (msm_vidc_debug & 2) != 0 )
          printk(&unk_8C931, "high", a1 + 340, "msm_venc_set_quality_mode", v19);
        LODWORD(result) = venus_hfi_session_property(a1, 50331976, 0, 1, 9, &v24, 4);
        if ( !(_DWORD)result )
        {
          v21 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 21616);
          if ( !v21 )
            goto LABEL_56;
          if ( *((_DWORD *)v21 - 1) != 1301911631 )
            __break(0x8228u);
          LODWORD(result) = v21(a1, 102);
          if ( a1 && (_DWORD)result )
          {
            v20 = result;
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_82A66, "err ", a1 + 340, "msm_venc_set_ring_buffer_count", v14);
            goto LABEL_44;
          }
          if ( !(_DWORD)result )
          {
LABEL_56:
            LODWORD(result) = msm_vidc_get_internal_buffers(a1, 7);
            if ( !(_DWORD)result )
            {
              LODWORD(result) = msm_vidc_get_internal_buffers(a1, 9);
              if ( !(_DWORD)result )
              {
                LODWORD(result) = msm_vidc_get_internal_buffers(a1, 10);
                if ( !(_DWORD)result )
                {
                  LODWORD(result) = msm_vidc_get_internal_buffers(a1, 11);
                  if ( !(_DWORD)result )
                  {
                    LODWORD(result) = msm_vidc_get_internal_buffers(a1, 12);
                    if ( !(_DWORD)result )
                    {
                      LODWORD(result) = msm_venc_destroy_internal_buffers(a1, &qword_1);
                      if ( !(_DWORD)result )
                      {
                        LODWORD(result) = msm_venc_create_output_internal_buffers(a1);
                        if ( !(_DWORD)result )
                        {
                          LODWORD(result) = msm_venc_queue_output_internal_buffers(a1);
                          if ( !(_DWORD)result )
                          {
                            LODWORD(result) = msm_venc_property_subscription(a1, 1u, v22, v23, v14);
                            if ( !(_DWORD)result )
                            {
                              LODWORD(result) = msm_venc_metadata_subscription(a1);
                              if ( !(_DWORD)result )
                              {
                                result = msm_vidc_process_streamon_output(a1);
                                if ( !(_DWORD)result )
                                  goto LABEL_47;
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
LABEL_43:
        v20 = result;
        if ( !a1 )
        {
LABEL_46:
          *(_QWORD *)(a1 + 15256) = *(_QWORD *)(*(_QWORD *)(a1 + 320) + 4256LL);
          msm_vidc_session_streamoff(a1, 1);
          result = v20;
          goto LABEL_47;
        }
LABEL_44:
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_8B2F9, "err ", a1 + 340, "msm_venc_streamon_output", v14);
        goto LABEL_46;
      }
      v11 = *(_DWORD *)(a1 + 600);
      v12 = *(_DWORD *)(a1 + 604);
    }
    else
    {
      v11 = dword_258;
      v12 = dword_25C;
    }
    v24 = v12 | (v11 << 16);
    goto LABEL_20;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_8651D, "err ", a1 + 340, "msm_venc_streamon_output", a5);
    result = 4294967274LL;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
