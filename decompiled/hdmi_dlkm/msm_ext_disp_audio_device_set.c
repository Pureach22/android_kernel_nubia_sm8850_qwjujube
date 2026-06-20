__int64 __fastcall msm_ext_disp_audio_device_set(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v7; // x9

  v2 = *(_QWORD *)(a1 + 128);
  v3 = **(unsigned int **)(a1 + 120);
  if ( (unsigned int)v3 < 3 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
    if ( v4 )
    {
      if ( !*(_QWORD *)(a2 + 72) && *(_QWORD *)(a2 + 80) < 3u )
      {
        mutex_lock(v4 + 64);
        v7 = v4 + 4 * v3;
        *(_DWORD *)(v7 + 152) = *(_QWORD *)(a2 + 72);
        *(_DWORD *)(v7 + 132) = *(_QWORD *)(a2 + 80);
        mutex_unlock(v4 + 64);
        return 0;
      }
      if ( (unsigned int)__ratelimit(&msm_ext_disp_audio_device_set__rs_62, "msm_ext_disp_audio_device_set") )
        dev_err(*(_QWORD *)(v2 + 24), "%s: DP audio control index invalid\n", "msm_ext_disp_audio_device_set");
    }
    else if ( (unsigned int)__ratelimit(&msm_ext_disp_audio_device_set__rs_61, "msm_ext_disp_audio_device_set") )
    {
      dev_err(*(_QWORD *)(v2 + 24), "%s: codec_data or ops acknowledge() is NULL\n", "msm_ext_disp_audio_device_set");
    }
  }
  else if ( (unsigned int)__ratelimit(&msm_ext_disp_audio_device_set__rs, "msm_ext_disp_audio_device_set") )
  {
    dev_err(*(_QWORD *)(v2 + 24), "%s: invalid dai id: %d\n", "msm_ext_disp_audio_device_set", v3);
  }
  return 4294967274LL;
}
