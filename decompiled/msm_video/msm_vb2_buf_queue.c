unsigned __int64 __fastcall msm_vb2_buf_queue(__int64 a1)
{
  unsigned __int64 result; // x0
  __int64 v3; // x4
  __int64 v4; // x20
  __int64 v5; // x8
  unsigned __int64 v6; // x22
  unsigned int v7; // w0
  unsigned int v8; // w21
  unsigned __int64 v9; // x21
  int v10; // w8
  int v11; // w8
  unsigned __int64 v12; // x21
  char v13; // w0
  char v14; // w8

  result = ktime_get(a1);
  if ( a1 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)a1 + 72LL);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 320);
      if ( v5 )
      {
        if ( *(_QWORD *)(v5 + 4608) )
        {
          v6 = result;
          *(_BYTE *)(v4 + 1836) = 1;
          v7 = v4l2_ctrl_request_setup(*(_QWORD *)(a1 + 56), v4 + 1424);
          *(_BYTE *)(v4 + 1836) = 0;
          v8 = v7;
          v4l2_ctrl_request_complete(*(_QWORD *)(a1 + 56), v4 + 1424);
          result = v6;
          if ( v8 )
          {
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_8D014, "err ", v4 + 340, "msm_vb2_buf_queue", v8);
            goto LABEL_27;
          }
        }
        if ( *(_DWORD *)(a1 + 120) )
        {
LABEL_11:
          if ( *(_DWORD *)(v4 + 308) == 1 && *(_DWORD *)(a1 + 12) == 10 )
          {
            v9 = result;
            msm_vidc_set_auto_framerate(v4);
            result = v9;
          }
          if ( *(_DWORD *)(a1 + 12) == 10 && (unsigned int)msm_vidc_update_input_rate(v4, a1, result / 0x3E8) )
            goto LABEL_27;
          v10 = *(_DWORD *)(v4 + 308);
          if ( v10 == 1 )
          {
            result = msm_venc_qbuf(v4, a1);
          }
          else
          {
            if ( v10 != 2 )
            {
LABEL_26:
              print_vb2_buffer((__int64)"failed vb2-qbuf", v4, a1);
LABEL_27:
              msm_vidc_change_state(v4, 5u, (__int64)"msm_vb2_buf_queue");
              return vb2_buffer_done(a1, 6);
            }
            result = msm_vdec_qbuf(v4, a1);
          }
          if ( !(_DWORD)result )
            return result;
          goto LABEL_26;
        }
        v11 = *(_DWORD *)(a1 + 12);
        switch ( v11 )
        {
          case 14:
            v12 = result;
            v13 = is_any_meta_tx_inp_enabled(v4);
            break;
          case 13:
            v12 = result;
            v13 = is_any_meta_tx_out_enabled(v4);
            break;
          case 10:
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_80928, "err ", v4 + 340, "msm_vb2_buf_queue", v3);
            goto LABEL_27;
          default:
            goto LABEL_11;
        }
        v14 = v13;
        result = v12;
        if ( (v14 & 1) != 0 )
          *(_DWORD *)(a1 + 120) = *(_DWORD *)(a1 + 124);
        goto LABEL_11;
      }
    }
  }
  if ( (msm_vidc_debug & 1) != 0 )
    return printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vb2_buf_queue");
  return result;
}
