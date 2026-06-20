__int64 __fastcall msm_ext_disp_audio_device_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x8

  v2 = *(_QWORD *)(a1 + 128);
  v3 = **(unsigned int **)(a1 + 120);
  if ( (unsigned int)v3 < 3 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
    if ( v4 )
    {
      v5 = v4 + 4 * v3;
      *(_QWORD *)(a2 + 72) = *(int *)(v5 + 152);
      *(_QWORD *)(a2 + 80) = *(int *)(v5 + 132);
      return 0;
    }
    if ( (unsigned int)__ratelimit(&msm_ext_disp_audio_device_get__rs_59, "msm_ext_disp_audio_device_get") )
      dev_err(*(_QWORD *)(v2 + 24), "%s: codec_data or ops acknowledge() is NULL\n", "msm_ext_disp_audio_device_get");
  }
  else if ( (unsigned int)__ratelimit(&msm_ext_disp_audio_device_get__rs, "msm_ext_disp_audio_device_get") )
  {
    dev_err(*(_QWORD *)(v2 + 24), "%s: invalid dai id: %d\n", "msm_ext_disp_audio_device_get", v3);
  }
  return 4294967274LL;
}
