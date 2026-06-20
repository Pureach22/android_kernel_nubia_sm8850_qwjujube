__int64 __fastcall lpass_cdc_rx_macro_hw_params(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x22
  int v9; // w21
  _DWORD *v10; // x9
  char v11; // w8
  int v12; // w23
  __int64 v13; // x21
  __int64 v14; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // x24
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x26
  int v19; // w27
  unsigned __int8 v20; // w22
  unsigned __int8 v21; // w0
  unsigned __int8 v24; // w22
  unsigned __int8 v25; // w0
  unsigned __int8 v26; // w22
  unsigned __int8 v27; // w0
  __int64 v28; // x21
  __int64 v29; // x8
  unsigned __int64 v30; // x9
  __int64 v31; // x22
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x25
  int v34; // w26
  unsigned int v35; // w8
  int v36; // w9
  __int64 v37; // x0
  __int16 v38; // w0
  __int64 v39; // x9
  __int16 v40; // w8
  __int64 v41; // [xsp+8h] [xbp-38h] BYREF
  __int64 v42; // [xsp+10h] [xbp-30h] BYREF
  __int64 v43; // [xsp+18h] [xbp-28h] BYREF
  __int64 v44; // [xsp+20h] [xbp-20h] BYREF
  __int64 v45; // [xsp+28h] [xbp-18h] BYREF
  __int64 v46[2]; // [xsp+30h] [xbp-10h] BYREF

  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a3 + 96);
  v41 = 0;
  if ( (lpass_cdc_rx_macro_get_data(v6, &v42, &v41, (__int64)"lpass_cdc_rx_macro_hw_params") & 1) == 0 )
  {
LABEL_78:
    result = 4294967274LL;
    goto LABEL_79;
  }
  if ( !*(_DWORD *)(a1 + 60) )
  {
    v8 = *(_QWORD *)(a3 + 96);
    v9 = a2[74];
    v43 = 0;
    if ( (lpass_cdc_rx_macro_get_data(v8, &v44, &v43, (__int64)"lpass_cdc_rx_macro_set_interpolator_rate") & 1) == 0 )
      goto LABEL_76;
    if ( v9 <= 88199 )
    {
      if ( v9 <= 31999 )
      {
        if ( v9 == 8000 )
        {
          v11 = 0;
          v10 = &sr_val_tbl;
          goto LABEL_31;
        }
        if ( v9 == 16000 )
        {
          v11 = 0;
          v10 = &unk_1FF80;
          goto LABEL_31;
        }
      }
      else
      {
        switch ( v9 )
        {
          case 32000:
            v11 = 0;
            v10 = &unk_1FF88;
            goto LABEL_31;
          case 44100:
            v10 = &unk_1FFB0;
            goto LABEL_30;
          case 48000:
            v11 = 0;
            v10 = &unk_1FF90;
            goto LABEL_31;
        }
      }
    }
    else if ( v9 > 191999 )
    {
      switch ( v9 )
      {
        case 192000:
          v11 = 0;
          v10 = &unk_1FFA0;
          goto LABEL_31;
        case 352800:
          v10 = &unk_1FFC8;
          goto LABEL_30;
        case 384000:
          v11 = 0;
          v10 = &unk_1FFA8;
          goto LABEL_31;
      }
    }
    else
    {
      switch ( v9 )
      {
        case 88200:
          v10 = &unk_1FFB8;
          goto LABEL_30;
        case 96000:
          v11 = 0;
          v10 = &unk_1FF98;
          goto LABEL_31;
        case 176400:
          v10 = &unk_1FFC0;
LABEL_30:
          v11 = 1;
LABEL_31:
          v12 = v10[1];
          byte_56[v43] = v11;
          if ( (v12 & 0x80000000) == 0 )
          {
            v13 = *(_QWORD *)(a3 + 96);
            v45 = 0;
            if ( (lpass_cdc_rx_macro_get_data(v13, v46, &v45, (__int64)"lpass_cdc_rx_macro_set_prim_interpolator_rate")
                & 1) != 0 )
            {
              v14 = *(unsigned int *)(a3 + 8);
              if ( (unsigned int)v14 > 8 )
                goto LABEL_81;
              v15 = 0;
              v16 = v45 + 312;
              while ( v15 <= 5 )
              {
                v17 = (unsigned __int8)(-1LL << v15) & (unsigned __int8)*(_QWORD *)(v16 + 8 * v14) & 0x3F;
                if ( !v17 )
                  break;
                v18 = __clz(__rbit64(v17));
                v19 = v18 + 5;
                v20 = snd_soc_component_read(v13, 4480);
                v21 = snd_soc_component_read(v13, 4484);
                if ( (v20 & 0xF) == (_DWORD)v18 + 5 || v20 >> 4 == v19 || v21 >> 4 == v19 )
                  snd_soc_component_update_bits(v13, 5120, 15, (unsigned __int8)v12);
                v24 = snd_soc_component_read(v13, 4488);
                v25 = snd_soc_component_read(v13, 4492);
                if ( (v24 & 0xF) == v19 || v24 >> 4 == v19 || v25 >> 4 == v19 )
                  snd_soc_component_update_bits(v13, 5312, 15, (unsigned __int8)v12);
                v26 = snd_soc_component_read(v13, 4496);
                v27 = snd_soc_component_read(v13, 4500);
                if ( (v26 & 0xF) == v19 || v26 >> 4 == v19 || v27 >> 4 == v19 )
                  snd_soc_component_update_bits(v13, 5504, 15, (unsigned __int8)v12);
                v14 = *(unsigned int *)(a3 + 8);
                v15 = v18 + 1;
                if ( (unsigned int)v14 >= 9 )
                  goto LABEL_81;
              }
              v28 = *(_QWORD *)(a3 + 96);
              v45 = 0;
              if ( (lpass_cdc_rx_macro_get_data(v28, v46, &v45, (__int64)"lpass_cdc_rx_macro_set_mix_interpolator_rate")
                  & 1) != 0 )
              {
                v29 = *(unsigned int *)(a3 + 8);
                if ( (unsigned int)v29 > 8 )
                  goto LABEL_81;
                v30 = 0;
                v31 = v45 + 312;
                while ( v30 <= 5 )
                {
                  v32 = (unsigned __int8)(-1LL << v30) & (unsigned __int8)*(_QWORD *)(v31 + 8 * v29) & 0x3F;
                  if ( !v32 )
                    break;
                  v33 = __clz(__rbit64(v32));
                  v34 = v33 + 1;
                  if ( (snd_soc_component_read(v28, 4484) & 0xF) == (_DWORD)v33 + 1 )
                    snd_soc_component_update_bits(v28, 5144, 15, (unsigned __int8)v12);
                  if ( (snd_soc_component_read(v28, 4492) & 0xF) == v34 )
                    snd_soc_component_update_bits(v28, 5336, 15, (unsigned __int8)v12);
                  if ( (snd_soc_component_read(v28, 4500) & 0xF) == v34 )
                    snd_soc_component_update_bits(v28, 5528, 15, (unsigned __int8)v12);
                  v29 = *(unsigned int *)(a3 + 8);
                  v30 = v33 + 1;
                  if ( (unsigned int)v29 >= 9 )
                    goto LABEL_81;
                }
                v35 = a2[9];
                if ( v35 )
                {
                  v36 = 0;
                }
                else
                {
                  v35 = a2[10];
                  if ( !v35 )
                  {
                    v37 = 0;
LABEL_73:
                    v38 = snd_pcm_format_width(v37);
                    v39 = *(unsigned int *)(a3 + 8);
                    if ( (unsigned int)v39 < 8 )
                    {
                      v40 = v38;
                      result = 0;
                      *(_WORD *)(v41 + 2 * v39 + 440) = v40;
                      goto LABEL_79;
                    }
LABEL_81:
                    __break(0x5512u);
                  }
                  v36 = 32;
                }
                v37 = __clz(__rbit32(v35)) | v36;
                goto LABEL_73;
              }
            }
            goto LABEL_76;
          }
          break;
      }
    }
    dev_err(*(_QWORD *)(v8 + 24), "%s: Unsupported sample rate: %d\n", "lpass_cdc_rx_macro_set_interpolator_rate", v9);
LABEL_76:
    if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_hw_params__rs, "lpass_cdc_rx_macro_hw_params") )
      printk(&unk_FD64, "lpass_cdc_rx_macro_hw_params");
    goto LABEL_78;
  }
  result = 0;
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return result;
}
