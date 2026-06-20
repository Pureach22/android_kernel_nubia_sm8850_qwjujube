__int64 __fastcall lpass_cdc_wsa_macro_hw_params(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v3; // x23
  __int64 device_ptr; // x0
  __int64 v8; // x24
  int v9; // w8
  int v10; // w25
  _DWORD *v11; // x8
  int v12; // w26
  __int64 v13; // x21
  __int64 v14; // x0
  __int64 v15; // x10
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // x27
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x22
  unsigned int v22; // w8
  int v23; // w9
  __int64 v24; // x0
  int v25; // w0
  __int64 v26; // x8
  __int64 v27; // x8
  __int16 v28; // w9
  unsigned int v29; // w8
  __int64 v30; // x20
  __int64 v31; // x0
  _DWORD *v32; // x8
  int v33; // w25
  __int64 v34; // x21
  __int64 v35; // x0
  __int64 v36; // x10
  __int64 v37; // x8
  unsigned __int64 v38; // x9
  __int64 v39; // x26
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x28
  int v42; // w27
  unsigned int v43; // w22
  unsigned int v44; // w0
  unsigned int v47; // w22
  unsigned int v48; // w0
  unsigned int v49; // w8
  int v50; // w9
  __int64 v51; // x0
  int v52; // w0
  __int64 v53; // x8
  __int64 v54; // x8
  int v55; // w9
  __int64 v56; // x3
  __int64 v57; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(a3 + 96);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 + 24), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_hw_params");
    return 4294967274LL;
  }
  v8 = *(_QWORD *)(device_ptr + 152);
  if ( !v8 || !*(_QWORD *)(v8 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_hw_params");
    return 4294967274LL;
  }
  v9 = *(_DWORD *)(a1 + 60);
  if ( v9 != 1 )
  {
    if ( v9 )
      return 0;
    v10 = a2[74];
    if ( v10 == 48000 )
    {
      v11 = &int_mix_sample_rate_val;
    }
    else
    {
      if ( v10 <= 44099 )
      {
        if ( v10 > 23999 )
        {
          if ( v10 == 24000 )
          {
            v32 = &unk_20968;
          }
          else
          {
            if ( v10 != 32000 )
              goto LABEL_105;
            v32 = &unk_20970;
          }
        }
        else if ( v10 == 8000 )
        {
          v32 = &int_prim_sample_rate_val;
        }
        else
        {
          if ( v10 != 16000 )
            goto LABEL_105;
          v32 = &unk_20960;
        }
LABEL_78:
        v33 = v32[1];
        if ( (v33 & 0x80000000) == 0 )
        {
          v34 = *(_QWORD *)(a3 + 96);
          v35 = lpass_cdc_get_device_ptr(*(_QWORD *)(v34 + 24), 2);
          if ( v35 )
          {
            v36 = *(_QWORD *)(v35 + 152);
            if ( v36 && *(_QWORD *)(v36 + 360) )
            {
              v37 = *(unsigned int *)(a3 + 8);
              if ( (unsigned int)v37 > 8 )
                goto LABEL_130;
              v38 = 0;
              v39 = v36 + 376;
              while ( v38 <= 8 )
              {
                v40 = (unsigned __int16)(-1LL << v38) & (unsigned __int16)*(_QWORD *)(v39 + 8 * v37) & 0x1FF;
                if ( !v40 )
                  break;
                v41 = __clz(__rbit64(v40));
                v42 = v41 + 1;
                v43 = snd_soc_component_read(v34, 8448);
                v44 = snd_soc_component_read(v34, 8452);
                if ( (v43 & 7) == (_DWORD)v41 + 1 || ((v43 >> 3) & 7) == v42 || ((v44 >> 3) & 7) == v42 )
                  snd_soc_component_update_bits(v34, 9216, 15, (unsigned __int8)v33);
                v47 = snd_soc_component_read(v34, 8456);
                v48 = snd_soc_component_read(v34, 8460);
                if ( (v47 & 7) == v42 || ((v47 >> 3) & 7) == v42 || ((v48 >> 3) & 7) == v42 )
                  snd_soc_component_update_bits(v34, 9344, 15, (unsigned __int8)v33);
                v37 = *(unsigned int *)(a3 + 8);
                v38 = v41 + 1;
                if ( (unsigned int)v37 >= 9 )
                  goto LABEL_130;
              }
              v49 = a2[9];
              if ( v49 )
              {
                v50 = 0;
              }
              else
              {
                v49 = a2[10];
                if ( !v49 )
                {
                  v51 = 0;
LABEL_112:
                  v52 = snd_pcm_format_width(v51);
                  if ( v52 != 32 )
                  {
                    if ( v52 != 24 )
                    {
                      if ( v52 == 16 )
                      {
                        v26 = *(unsigned int *)(a3 + 8);
                        if ( (unsigned int)v26 >= 8 )
                          goto LABEL_130;
                        goto LABEL_44;
                      }
                      if ( (unsigned int)__ratelimit(
                                           &lpass_cdc_wsa_macro_hw_params__rs_294,
                                           "lpass_cdc_wsa_macro_hw_params") )
                      {
                        v29 = a2[9];
                        v30 = *(_QWORD *)(v3 + 24);
                        if ( !v29 )
                        {
                          v29 = a2[10];
                          if ( v29 )
                            goto LABEL_125;
                          goto LABEL_52;
                        }
                        goto LABEL_127;
                      }
                      return 4294967274LL;
                    }
                    goto LABEL_117;
                  }
LABEL_119:
                  v54 = *(unsigned int *)(a3 + 8);
                  if ( (unsigned int)v54 <= 7 )
                  {
                    v27 = v8 + 2 * v54;
                    v28 = 32;
                    goto LABEL_121;
                  }
                  goto LABEL_130;
                }
                v50 = 32;
              }
              v51 = __clz(__rbit32(v49)) | v50;
              goto LABEL_112;
            }
            if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
              dev_err(
                *(_QWORD *)(v34 + 24),
                "%s: priv is null for macro!\n",
                "lpass_cdc_wsa_macro_set_prim_interpolator_rate");
          }
          else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
          {
            dev_err(
              *(_QWORD *)(v34 + 24),
              "%s: null device for macro!\n",
              "lpass_cdc_wsa_macro_set_prim_interpolator_rate");
          }
        }
LABEL_105:
        if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_hw_params__rs, "lpass_cdc_wsa_macro_hw_params") )
          dev_err(
            *(_QWORD *)(v3 + 24),
            "%s: cannot set sample rate: %u\n",
            "lpass_cdc_wsa_macro_hw_params",
            (unsigned int)a2[74]);
        return 4294967274LL;
      }
      if ( v10 > 191999 )
      {
        if ( v10 == 384000 )
        {
          v32 = &unk_20990;
          goto LABEL_78;
        }
        if ( v10 != 192000 )
          goto LABEL_105;
        v11 = &unk_20950;
      }
      else
      {
        if ( v10 == 44100 )
        {
          v32 = &unk_20998;
          goto LABEL_78;
        }
        if ( v10 != 96000 )
          goto LABEL_105;
        v11 = &unk_20948;
      }
    }
    v12 = v11[1];
    if ( (v12 & 0x80000000) == 0 )
    {
      v13 = *(_QWORD *)(a3 + 96);
      v14 = lpass_cdc_get_device_ptr(*(_QWORD *)(v13 + 24), 2);
      if ( v14 )
      {
        v15 = *(_QWORD *)(v14 + 152);
        if ( v15 && *(_QWORD *)(v15 + 360) )
        {
          v16 = *(unsigned int *)(a3 + 8);
          v57 = v14;
          if ( (unsigned int)v16 > 8 )
            goto LABEL_130;
          v17 = 0;
          v18 = v15 + 376;
          while ( v17 <= 8 )
          {
            v20 = (unsigned __int16)(-1LL << v17) & (unsigned __int16)*(_QWORD *)(v18 + 8 * v16) & 0x1FF;
            if ( !v20 )
              break;
            v21 = __clz(__rbit64(v20));
            if ( (unsigned int)v21 > 3 )
            {
              if ( (unsigned int)__ratelimit(
                                   &lpass_cdc_wsa_macro_set_mix_interpolator_rate__rs,
                                   "lpass_cdc_wsa_macro_set_mix_interpolator_rate") )
                dev_err(
                  v57,
                  "%s: Invalid RX port, Dai ID is %d\n",
                  "lpass_cdc_wsa_macro_set_mix_interpolator_rate",
                  *(_DWORD *)(a3 + 8));
              break;
            }
            if ( (snd_soc_component_read(v13, 8452) & 7) == (_DWORD)v21 + 1 )
              snd_soc_component_update_bits(v13, 9240, 15, (unsigned __int8)v12);
            if ( (snd_soc_component_read(v13, 8460) & 7) == (_DWORD)v21 + 1 )
              snd_soc_component_update_bits(v13, 9368, 15, (unsigned __int8)v12);
            v16 = *(unsigned int *)(a3 + 8);
            v17 = v21 + 1;
            if ( (unsigned int)v16 >= 9 )
              goto LABEL_130;
          }
        }
        else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
        {
          dev_err(
            *(_QWORD *)(v13 + 24),
            "%s: priv is null for macro!\n",
            "lpass_cdc_wsa_macro_set_mix_interpolator_rate");
        }
      }
      else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      {
        dev_err(*(_QWORD *)(v13 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_set_mix_interpolator_rate");
      }
    }
    if ( v10 == 48000 )
    {
      v32 = &unk_20978;
    }
    else if ( v10 > 191999 )
    {
      v32 = &unk_20988;
    }
    else
    {
      v32 = &unk_20980;
    }
    goto LABEL_78;
  }
  if ( *(_DWORD *)(a3 + 8) == 3 )
    *(_DWORD *)(v8 + 636) = a2[74];
  v22 = a2[9];
  if ( v22 )
  {
    v23 = 0;
LABEL_39:
    v24 = __clz(__rbit32(v22)) | v23;
    goto LABEL_40;
  }
  v22 = a2[10];
  if ( v22 )
  {
    v23 = 32;
    goto LABEL_39;
  }
  v24 = 0;
LABEL_40:
  v25 = snd_pcm_format_width(v24);
  if ( v25 == 32 )
    goto LABEL_119;
  if ( v25 == 24 )
  {
LABEL_117:
    v53 = *(unsigned int *)(a3 + 8);
    if ( (unsigned int)v53 <= 7 )
    {
      v27 = v8 + 2 * v53;
      v28 = 24;
      goto LABEL_121;
    }
    goto LABEL_130;
  }
  if ( v25 != 16 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_hw_params__rs_296, "lpass_cdc_wsa_macro_hw_params") )
    {
      v29 = a2[9];
      v30 = *(_QWORD *)(v3 + 24);
      if ( !v29 )
      {
        v29 = a2[10];
        if ( v29 )
        {
LABEL_125:
          v55 = 32;
LABEL_128:
          v31 = __clz(__rbit32(v29)) | v55;
          goto LABEL_129;
        }
LABEL_52:
        v31 = 0;
LABEL_129:
        v56 = (unsigned int)snd_pcm_format_width(v31);
        dev_err(v30, "%s: Invalid format 0x%x\n", "lpass_cdc_wsa_macro_hw_params", v56);
        return 4294967274LL;
      }
LABEL_127:
      v55 = 0;
      goto LABEL_128;
    }
    return 4294967274LL;
  }
  v26 = *(unsigned int *)(a3 + 8);
  if ( (unsigned int)v26 <= 7 )
  {
LABEL_44:
    v27 = v8 + 2 * v26;
    v28 = 16;
LABEL_121:
    *(_WORD *)(v27 + 504) = v28;
    return 0;
  }
LABEL_130:
  __break(0x5512u);
  return readl();
}
