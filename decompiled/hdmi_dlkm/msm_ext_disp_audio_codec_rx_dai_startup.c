__int64 __fastcall msm_ext_disp_audio_codec_rx_dai_startup(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  _QWORD *v4; // x20
  __int64 v5; // x8
  int v6; // w9
  char *v7; // x8
  int v8; // w0
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x0
  _QWORD *v11; // x21
  int v12; // w0
  __int64 v13; // x8
  __int64 v14; // x8
  int v15; // w8
  __int64 result; // x0
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  int v20; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v21; // [xsp+10h] [xbp-10h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 96);
  v21 = 0;
  v4 = *(_QWORD **)(*(_QWORD *)(v3 + 24) + 152LL);
  if ( !v4 )
  {
    if ( (unsigned int)__ratelimit(
                         &msm_ext_disp_audio_codec_rx_dai_startup__rs,
                         "msm_ext_disp_audio_codec_rx_dai_startup") )
      dev_err(*(_QWORD *)(a2 + 16), "%s() codec_data is null\n", "msm_ext_disp_audio_codec_rx_dai_startup");
    goto LABEL_22;
  }
  if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 16LL) + 144LL) & 0x80) == 0 )
    snd_soc_set_runtime_hwparams();
  mutex_lock(v4 + 8);
  v5 = *(unsigned int *)(a2 + 8);
  if ( (_DWORD)v5 == 4 )
    v6 = 40;
  else
    v6 = 44;
  v20 = v6;
  if ( (unsigned int)v5 >= 5 )
    goto LABEL_33;
  v7 = (char *)v4 + 4 * v5;
  LODWORD(v21) = *((_DWORD *)v7 + 38);
  HIDWORD(v21) = *((_DWORD *)v7 + 33);
  v8 = msm_ext_disp_select_audio_codec(*v4, &v20);
  v9 = (__int64 (__fastcall *)(__int64, __int64))v4[3];
  if ( !v9 || v8 )
  {
    if ( (unsigned int)__ratelimit(
                         &msm_ext_disp_audio_codec_rx_dai_startup__rs_84,
                         "msm_ext_disp_audio_codec_rx_dai_startup") )
      dev_err(*(_QWORD *)(a2 + 16), "%s() cable_status is null\n", "msm_ext_disp_audio_codec_rx_dai_startup");
    mutex_unlock(v4 + 8);
LABEL_22:
    result = 4294967274LL;
    goto LABEL_23;
  }
  v11 = v4 + 14;
  v10 = *v4;
  if ( *((_DWORD *)v9 - 1) != 1323373652 )
    __break(0x8228u);
  v12 = v9(v10, 1);
  v13 = *(unsigned int *)(a2 + 8);
  if ( (unsigned int)v13 > 4 )
    goto LABEL_33;
  *((_DWORD *)v11 + v13) = v12;
  mutex_unlock(v4 + 8);
  v14 = *(unsigned int *)(a2 + 8);
  if ( (unsigned int)v14 > 4 )
    goto LABEL_33;
  v15 = *((_DWORD *)v11 + v14);
  if ( v15 < 0 )
  {
    if ( (unsigned int)__ratelimit(
                         &msm_ext_disp_audio_codec_rx_dai_startup__rs_86,
                         "msm_ext_disp_audio_codec_rx_dai_startup") )
    {
      v18 = *(unsigned int *)(a2 + 8);
      if ( (unsigned int)v18 > 4 )
        goto LABEL_33;
      dev_err(
        *(_QWORD *)(a2 + 16),
        "%s() ext disp core is not ready (ret val = %d)\n",
        "msm_ext_disp_audio_codec_rx_dai_startup",
        *((_DWORD *)v11 + v18));
    }
    v17 = *(unsigned int *)(a2 + 8);
    if ( (unsigned int)v17 <= 4 )
    {
      result = *((unsigned int *)v11 + v17);
      goto LABEL_23;
    }
LABEL_33:
    __break(0x5512u);
  }
  if ( !v15 )
  {
    if ( !(unsigned int)__ratelimit(
                          &msm_ext_disp_audio_codec_rx_dai_startup__rs_88,
                          "msm_ext_disp_audio_codec_rx_dai_startup") )
    {
LABEL_28:
      result = 4294967277LL;
      goto LABEL_23;
    }
    v19 = *(unsigned int *)(a2 + 8);
    if ( (unsigned int)v19 <= 4 )
    {
      dev_err(
        *(_QWORD *)(a2 + 16),
        "%s() ext disp cable is not connected (ret val = %d)\n",
        "msm_ext_disp_audio_codec_rx_dai_startup",
        *((_DWORD *)v11 + v19));
      goto LABEL_28;
    }
    goto LABEL_33;
  }
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
