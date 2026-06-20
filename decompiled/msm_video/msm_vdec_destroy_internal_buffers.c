__int64 __fastcall msm_vdec_destroy_internal_buffers(__int64 result, int a2)
{
  __int64 v3; // x20
  unsigned __int64 v4; // x28
  unsigned __int64 v5; // x22
  _DWORD *v6; // x23
  unsigned int v7; // w27
  __int64 buffers; // x0
  __int64 v9; // x26
  __int64 v10; // x0
  __int64 *v11; // x1
  __int64 *v13; // x27

  v3 = result;
  v4 = 0;
  if ( a2 )
    v5 = 4;
  else
    v5 = 20;
  if ( a2 )
    v6 = &msm_vdec_output_internal_buffer_type;
  else
    v6 = &msm_vdec_internal_buffer_type;
  while ( 1 )
  {
    if ( v5 <= 4 * v4 )
    {
      __break(1u);
      return msm_vdec_subscribe_input_port_settings_change(result);
    }
    v7 = v6[v4];
    buffers = msm_vidc_get_buffers(v3, v7, "msm_vdec_destroy_internal_buffers");
    if ( !buffers )
      return 4294967274LL;
    v9 = buffers;
    if ( *(_BYTE *)(buffers + 32) == 1 )
    {
      if ( v3 && (msm_vidc_debug & 4) != 0 )
      {
        v10 = buf_name(v7);
        printk(&unk_8812E, "low ", v3 + 340, "msm_vdec_destroy_internal_buffers", v10);
      }
      goto LABEL_14;
    }
    v11 = *(__int64 **)buffers;
    if ( *(_QWORD *)buffers != buffers )
      break;
LABEL_14:
    result = 0;
    if ( !a2 && v4++ < 4 )
      continue;
    return result;
  }
  while ( 1 )
  {
    v13 = (__int64 *)*v11;
    if ( (v11[10] & 8) == 0 )
    {
      if ( v3 && (msm_vidc_debug & 2) != 0 )
        printk(&unk_8FB9B, "high", v3 + 340, "msm_vdec_destroy_internal_buffers", *((unsigned int *)v11 + 6));
      result = ((__int64 (__fastcall *)(__int64))msm_vidc_destroy_internal_buffer)(v3);
      if ( (_DWORD)result )
        return result;
    }
    v11 = v13;
    if ( v13 == (__int64 *)v9 )
      goto LABEL_14;
  }
}
