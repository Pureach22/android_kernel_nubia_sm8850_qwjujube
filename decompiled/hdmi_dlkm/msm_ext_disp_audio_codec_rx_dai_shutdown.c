__int64 __fastcall msm_ext_disp_audio_codec_rx_dai_shutdown(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x20
  __int64 v4; // x0
  __int64 v5; // x8
  int v6; // w9
  char *v7; // x8
  int v8; // w0
  _DWORD *v9; // x8
  __int64 v10; // x0
  void (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x0
  __int64 result; // x0
  _DWORD v14[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(a2 + 96) + 24LL) + 152LL);
  if ( !v3 )
  {
    result = __ratelimit(&msm_ext_disp_audio_codec_rx_dai_shutdown__rs, "msm_ext_disp_audio_codec_rx_dai_shutdown");
    if ( (_DWORD)result )
      result = dev_err(*(_QWORD *)(a2 + 16), "%s() codec_data is null\n", "msm_ext_disp_audio_codec_rx_dai_shutdown");
    goto LABEL_22;
  }
  v4 = mutex_lock(v3 + 8);
  v5 = *(unsigned int *)(a2 + 8);
  if ( (_DWORD)v5 == 4 )
    v6 = 40;
  else
    v6 = 44;
  v14[0] = v6;
  if ( (unsigned int)v5 < 5 )
  {
    v7 = (char *)v3 + 4 * v5;
    v14[1] = *((_DWORD *)v7 + 38);
    v14[2] = *((_DWORD *)v7 + 33);
    v8 = msm_ext_disp_select_audio_codec(*v3, v14);
    if ( v3[5] && (v9 = (_DWORD *)v3[3]) != nullptr && !v8 )
    {
      v10 = *v3;
      if ( *(v9 - 1) != 1323373652 )
        __break(0x8228u);
      if ( (((__int64 (__fastcall *)(__int64, _QWORD))v9)(v10, 0) & 0x80000000) != 0
        && (unsigned int)__ratelimit(
                           &msm_ext_disp_audio_codec_rx_dai_shutdown__rs_93,
                           "msm_ext_disp_audio_codec_rx_dai_shutdown") )
      {
        dev_err(
          *(_QWORD *)(a2 + 16),
          "%s: ext disp core had problems releasing audio flag\n",
          "msm_ext_disp_audio_codec_rx_dai_shutdown");
      }
      v11 = (void (__fastcall *)(_QWORD))v3[5];
      v12 = *v3;
      if ( *((_DWORD *)v11 - 1) != 614538169 )
        __break(0x8228u);
      v11(v12);
    }
    else if ( (unsigned int)__ratelimit(
                              &msm_ext_disp_audio_codec_rx_dai_shutdown__rs_91,
                              "msm_ext_disp_audio_codec_rx_dai_shutdown") )
    {
      dev_err(
        *(_QWORD *)(a2 + 16),
        "%s: teardown_done or cable_status is null\n",
        "msm_ext_disp_audio_codec_rx_dai_shutdown");
    }
    result = mutex_unlock(v3 + 8);
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return msm_ext_disp_audio_codec_rx_dai_hw_params(v4);
}
