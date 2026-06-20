__int64 __fastcall msm_venc_destroy_internal_buffers(__int64 result, __int64 *a2)
{
  int v2; // w19
  __int64 v3; // x20
  unsigned __int64 v4; // x28
  unsigned __int64 v5; // x22
  _DWORD *v6; // x23
  unsigned int v7; // w27
  __int64 buffers; // x0
  __int64 v9; // x26
  __int64 *v11; // x27
  __int64 v12; // x0

  v2 = (int)a2;
  v3 = result;
  v4 = 0;
  if ( (_DWORD)a2 )
    v5 = 20;
  else
    v5 = 4;
  if ( (_DWORD)a2 )
    v6 = &msm_venc_output_internal_buffer_type;
  else
    v6 = &msm_venc_input_internal_buffer_type;
  while ( v5 > 4 * v4 )
  {
    v7 = v6[v4];
    buffers = msm_vidc_get_buffers(v3, v7, "msm_venc_destroy_internal_buffers");
    if ( !buffers )
      return 4294967274LL;
    v9 = buffers;
    if ( *(_BYTE *)(buffers + 32) == 1 )
    {
      if ( v3 && (msm_vidc_debug & 4) != 0 )
      {
        v12 = buf_name(v7);
        printk(&unk_8812E, "low ", v3 + 340, "msm_venc_destroy_internal_buffers", v12);
      }
    }
    else
    {
      a2 = *(__int64 **)buffers;
      while ( a2 != (__int64 *)v9 )
      {
        v11 = (__int64 *)*a2;
        if ( v3 && (msm_vidc_debug & 2) != 0 )
          printk(&unk_8FB9B, "high", v3 + 340, "msm_venc_destroy_internal_buffers", *((unsigned int *)a2 + 6));
        result = ((__int64 (__fastcall *)(__int64))msm_vidc_destroy_internal_buffer)(v3);
        a2 = v11;
        if ( (_DWORD)result )
          return result;
      }
    }
    result = 0;
    if ( v2 )
    {
      if ( v4++ < 4 )
        continue;
    }
    return result;
  }
  __break(1u);
  return msm_venc_property_subscription(result, a2);
}
