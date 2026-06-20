__int64 __fastcall msm_ext_disp_audio_codec_rx_dai_hw_params(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  int v5; // w20
  _QWORD *v6; // x21
  __int64 v8; // x8
  int v9; // w22
  int v10; // w0
  __int64 v11; // x8
  _QWORD *v12; // x26
  int v13; // w8
  __int64 v14; // x8
  int v15; // w9
  __int64 result; // x0
  __int64 v17; // x8
  int v18; // w10
  int v19; // w8
  __int64 v20; // x8
  unsigned int v21; // w0
  __int64 v22; // x0
  _DWORD *v23; // x8
  unsigned int v24; // w20
  __int64 v25; // x8
  __int64 v26; // x8
  _DWORD v27[4]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h] BYREF
  int v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a3 + 96);
  v5 = *(_DWORD *)(a2 + 284);
  v30 = 0;
  v28 = 0;
  v29 = 0;
  v6 = *(_QWORD **)(*(_QWORD *)(v4 + 24) + 152LL);
  if ( !v6 )
  {
    if ( (unsigned int)__ratelimit(
                         &msm_ext_disp_audio_codec_rx_dai_hw_params__rs,
                         "msm_ext_disp_audio_codec_rx_dai_hw_params") )
    {
      dev_err(*(_QWORD *)(a3 + 16), "%s() codec_data is null\n", "msm_ext_disp_audio_codec_rx_dai_hw_params");
      result = 4294967274LL;
      goto LABEL_50;
    }
    goto LABEL_16;
  }
  mutex_lock(v6 + 8);
  v8 = *(unsigned int *)(a3 + 8);
  if ( (_DWORD)v8 == 4 )
    v9 = 40;
  else
    v9 = 44;
  LODWORD(v29) = v9;
  if ( (unsigned int)v8 >= 5 )
    goto LABEL_55;
  HIDWORD(v29) = *((_DWORD *)v6 + v8 + 38);
  v30 = *((_DWORD *)v6 + v8 + 33);
  v10 = msm_ext_disp_select_audio_codec(*v6, &v29);
  if ( v6[1] && !v10 )
  {
    mutex_unlock(v6 + 8);
    v11 = *(unsigned int *)(a3 + 8);
    if ( (unsigned int)v11 > 4 )
      goto LABEL_55;
    v12 = v6 + 14;
    v13 = *((_DWORD *)v6 + v11 + 28);
    if ( v13 < 0 )
    {
      if ( (unsigned int)__ratelimit(
                           &msm_ext_disp_audio_codec_rx_dai_hw_params__rs_97,
                           "msm_ext_disp_audio_codec_rx_dai_hw_params") )
      {
        v25 = *(unsigned int *)(a3 + 8);
        if ( (unsigned int)v25 > 4 )
          goto LABEL_55;
        dev_err(
          *(_QWORD *)(a3 + 16),
          "%s() ext disp core is not ready (ret val = %d)\n",
          "msm_ext_disp_audio_codec_rx_dai_hw_params",
          *((_DWORD *)v12 + v25));
      }
      v17 = *(unsigned int *)(a3 + 8);
      if ( (unsigned int)v17 <= 4 )
      {
        result = *((unsigned int *)v12 + v17);
        goto LABEL_50;
      }
LABEL_55:
      __break(0x5512u);
    }
    if ( !v13 )
    {
      if ( !(unsigned int)__ratelimit(
                            &msm_ext_disp_audio_codec_rx_dai_hw_params__rs_98,
                            "msm_ext_disp_audio_codec_rx_dai_hw_params") )
      {
        result = 4294967277LL;
        goto LABEL_50;
      }
      v26 = *(unsigned int *)(a3 + 8);
      if ( (unsigned int)v26 <= 4 )
      {
        dev_err(
          *(_QWORD *)(a3 + 16),
          "%s() ext disp cable is not connected (ret val = %d)\n",
          "msm_ext_disp_audio_codec_rx_dai_hw_params",
          *((_DWORD *)v12 + v26));
        result = 4294967277LL;
        goto LABEL_50;
      }
      goto LABEL_55;
    }
    if ( v5 <= 4 )
    {
      v14 = a2;
      switch ( v5 )
      {
        case 2:
          v15 = 0;
          goto LABEL_41;
        case 3:
          v15 = 2;
          v18 = 3;
          goto LABEL_40;
        case 4:
          v15 = 6;
LABEL_37:
          v18 = 7;
          goto LABEL_40;
      }
    }
    else
    {
      v14 = a2;
      if ( v5 <= 6 )
      {
        if ( v5 == 5 )
          v15 = 10;
        else
          v15 = 11;
        goto LABEL_37;
      }
      if ( v5 == 7 )
      {
        v15 = 18;
        v18 = 15;
        goto LABEL_40;
      }
      if ( v5 == 8 )
      {
        v15 = 19;
        v18 = 15;
LABEL_40:
        HIDWORD(v28) = v18;
LABEL_41:
        v19 = *(_DWORD *)(v14 + 296);
        v27[2] = v15;
        v27[3] = 0;
        LOBYTE(v28) = 0;
        v27[0] = v19;
        v27[1] = v5;
        mutex_lock(v6 + 8);
        v20 = *(unsigned int *)(a3 + 8);
        LODWORD(v29) = v9;
        if ( (unsigned int)v20 <= 4 )
        {
          HIDWORD(v29) = *((_DWORD *)v6 + v20 + 38);
          v30 = *((_DWORD *)v6 + v20 + 33);
          v21 = msm_ext_disp_select_audio_codec(*v6, &v29);
          if ( !v21 )
          {
            v22 = *v6;
            v23 = (_DWORD *)v6[1];
            if ( *(v23 - 1) != -587465522 )
              __break(0x8228u);
            v21 = ((__int64 (__fastcall *)(__int64, _DWORD *))v23)(v22, v27);
          }
          v24 = v21;
          mutex_unlock(v6 + 8);
          if ( (v24 & 0x80000000) != 0
            && (unsigned int)__ratelimit(
                               &msm_ext_disp_audio_codec_rx_dai_hw_params__rs_101,
                               "msm_ext_disp_audio_codec_rx_dai_hw_params") )
          {
            dev_err(
              *(_QWORD *)(a3 + 16),
              "%s() ext disp core is not ready, rc: %d\n",
              "msm_ext_disp_audio_codec_rx_dai_hw_params",
              v24);
          }
          result = v24;
          goto LABEL_50;
        }
        goto LABEL_55;
      }
    }
    if ( (unsigned int)__ratelimit(
                         &msm_ext_disp_audio_codec_rx_dai_hw_params__rs_99,
                         "msm_ext_disp_audio_codec_rx_dai_hw_params") )
    {
      dev_err(*(_QWORD *)(a3 + 16), "invalid Channels = %u\n", v5);
      result = 4294967274LL;
      goto LABEL_50;
    }
LABEL_16:
    result = 4294967274LL;
    goto LABEL_50;
  }
  if ( (unsigned int)__ratelimit(
                       &msm_ext_disp_audio_codec_rx_dai_hw_params__rs_95,
                       "msm_ext_disp_audio_codec_rx_dai_hw_params") )
    dev_err(*(_QWORD *)(a3 + 16), "%s: audio_info_setup is null\n", "msm_ext_disp_audio_codec_rx_dai_hw_params");
  mutex_unlock(v6 + 8);
  result = 4294967274LL;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
