__int64 __fastcall canoe_ssr_enable(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x2
  __int64 v3; // x3
  __int64 v4; // x23
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 pcm_runtime; // x21
  __int64 v8; // x20
  const char *v9; // x22
  __int64 result; // x0
  __int64 v12; // x22
  __int64 v13; // x2
  const char *v14; // x8
  void *v15; // x0
  __int64 v16; // x21
  __int64 v17; // x9
  __int64 v18; // x8
  unsigned __int8 (__fastcall *v19)(_QWORD); // x8
  unsigned int v20; // w20
  int v21; // w21
  const char *v22; // x0
  int v23; // w0
  int v24; // w10
  unsigned int v25; // w21
  int v26; // w8
  __int128 v27; // [xsp+0h] [xbp-20h] BYREF
  int v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
  {
    if ( (unsigned int)__ratelimit(&canoe_ssr_enable__rs, "canoe_ssr_enable") )
      dev_err(a1, "%s: card is NULL\n", "canoe_ssr_enable");
    result = 4294967274LL;
    goto LABEL_58;
  }
  snd_card_notify_user(1);
  v4 = v1[98];
  if ( !v4 )
    goto LABEL_57;
  pcm_runtime = snd_soc_get_pcm_runtime(v1, v1[44], v2, v3);
  if ( !*(_DWORD *)(v4 + 92) )
  {
    v8 = 0;
    v9 = *(const char **)(v4 + 136);
    if ( v9 )
      goto LABEL_10;
LABEL_57:
    result = 0;
    goto LABEL_58;
  }
  v8 = snd_soc_get_pcm_runtime(v1, v1[44] + 896LL, v5, v6);
  v9 = *(const char **)(v4 + 136);
  if ( !v9 )
    goto LABEL_57;
LABEL_10:
  if ( !strcmp(v9, "wsa") )
  {
    if ( !v8 )
      goto LABEL_57;
    goto LABEL_17;
  }
  if ( !strcmp(v9, "wcd") )
  {
    v8 = pcm_runtime;
    if ( !pcm_runtime )
    {
      if ( !*(_DWORD *)(v4 + 96) || !(unsigned int)__ratelimit(&msm_set_upd_config__rs, "msm_set_upd_config") )
        goto LABEL_57;
      v15 = &unk_12DE2;
      goto LABEL_56;
    }
LABEL_17:
    v28 = 0;
    v27 = 0u;
    v12 = *(_QWORD *)(*(_QWORD *)(v8 + 8) + 784LL);
    if ( v12 )
    {
      if ( *(_DWORD *)(v12 + 116) && *(_DWORD *)(v12 + 120) && *(_DWORD *)(v12 + 132) )
      {
        if ( !strcmp(*(const char **)(v12 + 136), "wsa") )
        {
          if ( *(_DWORD *)(v12 + 92) )
          {
            v16 = snd_soc_rtdcom_lookup(v8, "wsa-codec.1");
            if ( !v16 )
            {
              printk(&unk_136DE, "msm_set_upd_config", "wsa-codec.1");
              goto LABEL_57;
            }
            goto LABEL_36;
          }
          v15 = &unk_14000;
        }
        else
        {
          if ( *(_DWORD *)(v12 + 148) == 2 )
            v14 = "wcd9378_codec";
          else
            v14 = "wcd939x_codec";
          v17 = *(_QWORD *)v14;
          v18 = *(_QWORD *)(v14 + 6);
          *(_QWORD *)&v27 = v17;
          *(_QWORD *)((char *)&v27 + 6) = v18;
          v16 = snd_soc_rtdcom_lookup(v8, &v27);
          if ( v16 )
          {
LABEL_36:
            if ( !strcmp(*(const char **)(v12 + 136), "wsa") )
            {
              if ( strstr(**(const char ***)(v8 + 8), "wsa883x") )
                v19 = (unsigned __int8 (__fastcall *)(_QWORD))&wsa883x_codec_get_dev_num;
              else
                v19 = (unsigned __int8 (__fastcall *)(_QWORD))&wsa884x_codec_get_dev_num;
            }
            else if ( *(_DWORD *)(v12 + 148) == 2 )
            {
              v19 = (unsigned __int8 (__fastcall *)(_QWORD))&wcd9378_codec_get_dev_num;
            }
            else
            {
              v19 = (unsigned __int8 (__fastcall *)(_QWORD))&wcd939x_codec_get_dev_num;
            }
            *(_QWORD *)(v12 + 104) = v19;
            if ( *((_DWORD *)v19 - 1) != -725583242 )
              __break(0x8228u);
            v20 = v19(v16);
            if ( v20 >= 7 )
            {
              if ( (unsigned int)__ratelimit(&msm_set_upd_config__rs_329, "msm_set_upd_config") )
                printk(&unk_12D1F, "msm_set_upd_config", v20);
              goto LABEL_57;
            }
            v21 = *(unsigned __int16 *)(v12 + 132);
            v22 = *(const char **)(v12 + 136);
            *(_DWORD *)(v12 + 124) = v21;
            *(_DWORD *)(v12 + 128) = v21;
            v23 = strcmp(v22, "wsa");
            v24 = (v20 << 20) | v21;
            v25 = v21 & 0xF00FFFFF | ((unsigned __int8)v20 << 20);
            if ( v23 )
              v26 = -2147418112;
            else
              v26 = 16842752;
            *(_DWORD *)(v12 + 124) = v24 | v26;
            *(_DWORD *)(v12 + 128) = v25 | 0x10000;
            if ( (audio_prm_set_cdc_earpa_duty_cycling_req(v12 + 116, 1) & 0x80000000) == 0
              || !(unsigned int)__ratelimit(&msm_set_upd_config__rs_331, "msm_set_upd_config") )
            {
              goto LABEL_57;
            }
            v15 = &unk_13C65;
            goto LABEL_56;
          }
          v15 = &unk_12349;
        }
      }
      else
      {
        if ( !(unsigned int)__ratelimit(&msm_set_upd_config__rs_324, "msm_set_upd_config") )
          goto LABEL_57;
        v15 = &unk_1333C;
      }
    }
    else
    {
      if ( !(unsigned int)__ratelimit(&msm_set_upd_config__rs_322, "msm_set_upd_config") )
        goto LABEL_57;
      v15 = &unk_138D3;
    }
LABEL_56:
    printk(v15, "msm_set_upd_config", v13);
    goto LABEL_57;
  }
  result = __ratelimit(&canoe_ssr_enable__rs_319, "canoe_ssr_enable");
  if ( (_DWORD)result )
  {
    dev_err(v1[9], "%s: Invalid backend to set UPD config\n", "canoe_ssr_enable");
    goto LABEL_57;
  }
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
