__int64 __fastcall msm_vdec_codec_change(__int64 a1, unsigned int a2)
{
  int v2; // w22
  __int64 result; // x0
  int v6; // w0
  __int64 v7; // x21

  v2 = *(_DWORD *)(a1 + 312);
  if ( v2 && *(_DWORD *)(a1 + 400) == a2 )
    return 0;
  if ( a1 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v7 = v4l2_pixelfmt_name(a1, *(unsigned int *)(a1 + 400));
      v4l2_pixelfmt_name(a1, a2);
      printk(&unk_91338, "high", a1 + 340, "msm_vdec_codec_change", v7);
    }
    v6 = v4l2_codec_to_driver(a1, a2, "msm_vdec_codec_change");
    *(_DWORD *)(a1 + 312) = v6;
    if ( !v6 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_865E6, "err ", a1 + 340, "msm_vdec_codec_change", a2);
      return 4294967274LL;
    }
  }
  else
  {
    unk_138 = v4l2_codec_to_driver(0, a2, "msm_vdec_codec_change");
    if ( !unk_138 )
      return 4294967274LL;
  }
  *(_DWORD *)(a1 + 400) = a2;
  result = msm_vidc_update_debug_str(a1);
  if ( !(_DWORD)result )
  {
    result = msm_vidc_get_inst_capability(a1);
    if ( !(_DWORD)result )
    {
      result = msm_vidc_ctrl_handler_init(a1, v2 == 0);
      if ( !(_DWORD)result )
      {
        result = msm_vidc_update_buffer_count(a1, 0);
        if ( !(_DWORD)result )
          return msm_vidc_update_buffer_count(a1, 1);
      }
    }
  }
  return result;
}
