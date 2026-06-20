__int64 __fastcall lpass_cdc_va_macro_enable_dec(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x26
  __int64 device_ptr; // x0
  _QWORD *v7; // x22
  unsigned __int64 v8; // x24
  int v9; // w23
  __int64 v10; // x0
  char *v12; // x28
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x21
  unsigned int v16; // w8
  __int64 result; // x0
  __int64 v18; // x3
  __int64 v19; // x0
  __int64 v20; // x20
  unsigned int v21; // w0
  __int64 v22; // x21
  _BYTE *v23; // x21
  __int64 v24; // x0
  __int64 v25; // x20
  __int64 v26; // x0
  __int64 v27; // x20
  int v28; // w8
  __int64 v29; // x20
  __int64 v30; // x0
  int v31; // w8
  unsigned int v32; // w0
  _QWORD *v33; // x21
  int v34; // w20
  __int64 v35; // x0
  __int64 v36; // x20
  __int64 v37; // x1
  __int64 v38; // x0
  __int64 v39; // x3
  int v40; // w8
  int v41; // w8
  int v47; // [xsp+Ch] [xbp-4h]

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_va_macro_enable_dec");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v7 = *(_QWORD **)(device_ptr + 152);
  if ( !v7 || !v7[21] )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_enable_dec");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v8 = *(unsigned __int8 *)(a1 + 76);
  v9 = (_DWORD)v8 << 7;
  v10 = snd_soc_component_read(v3 - 208, (unsigned int)(((_DWORD)v8 << 7) + 13312));
  if ( v8 >= 4 )
  {
    __break(0x5512u);
    __asm { SUBG            SP, X6, #0xE0, #2 }
    return lpass_cdc_va_macro_mclk_event(v10);
  }
  v12 = (char *)v7 + 4 * v8;
  *((_DWORD *)v12 + 389) = v10 & 0xF;
  v47 = 8 * v8;
  v13 = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 3);
  if ( v13 )
  {
    v14 = *(_QWORD *)(v13 + 152);
    if ( v14 && *(_QWORD *)(v14 + 168) )
    {
      if ( (snd_soc_component_read(v3 - 208, v47 | 0x3104u) & 3) == 0 )
      {
        v15 = *(_QWORD *)(a1 + 40) - 208LL;
        v16 = snd_soc_component_read(v15, (unsigned int)(v47 + 12544));
        result = 0;
        if ( a3 > 3 )
        {
          if ( a3 == 4 )
            goto LABEL_73;
          if ( a3 != 8 )
            return result;
          v18 = 0;
        }
        else
        {
          if ( a3 != 1 )
            goto LABEL_21;
          v18 = 1;
        }
        lpass_cdc_dmic_clk_enable(v15, (v16 >> 4) - 1, 1, v18);
      }
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "is_msm_dmic_enabled");
    }
  }
  else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
  {
    dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "is_msm_dmic_enabled");
  }
  result = 0;
  if ( a3 > 3 )
  {
    if ( a3 != 4 )
    {
      if ( a3 != 8 )
        return result;
      snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13312), 32, 0);
      snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13312), 64, 64);
      snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13312), 64, 0);
      snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13312), 16, 0);
      return 0;
    }
LABEL_73:
    v33 = &v7[15 * (unsigned int)v8];
    v34 = *((unsigned __int8 *)v33 + 305);
    snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13312), 16, 16);
    if ( (cancel_delayed_work_sync(v33 + 39) & 1) == 0 || v34 == 2 )
      goto LABEL_86;
    snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13316), 96, (unsigned int)(32 * v34));
    v35 = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 3);
    if ( v35 )
    {
      v36 = *(_QWORD *)(v35 + 152);
      if ( v36 && *(_QWORD *)(v36 + 168) )
      {
        if ( (snd_soc_component_read(v3 - 208, v47 | 0x3104u) & 1) != 0 && (*(_BYTE *)(v36 + 1580) & 1) == 0 )
        {
          v37 = (unsigned int)(v9 + 13336);
          v38 = v3 - 208;
          v39 = 2;
LABEL_85:
          snd_soc_component_update_bits(v38, v37, 3, v39);
          usleep_range_state(1000, 1010, 2);
          snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13336), 3, 1);
LABEL_86:
          mutex_lock(v7 + 15);
          v40 = *((_DWORD *)v7 + 396) - 1;
          *((_DWORD *)v7 + 396) = v40;
          if ( !v40 )
          {
            pm_relax(*v7);
            v40 = *((_DWORD *)v7 + 396);
          }
          if ( v40 < 0 )
            *((_DWORD *)v7 + 396) = 0;
          mutex_unlock(v7 + 15);
          if ( (*((_BYTE *)v7 + 1580) & 1) == 0 )
          {
            cancel_delayed_work_sync(&v7[15 * (unsigned int)v8 + 99]);
            mutex_lock(v7 + 15);
            v41 = *((_DWORD *)v7 + 396) - 1;
            *((_DWORD *)v7 + 396) = v41;
            if ( !v41 )
            {
              pm_relax(*v7);
              v41 = *((_DWORD *)v7 + 396);
            }
            if ( v41 < 0 )
              *((_DWORD *)v7 + 396) = 0;
            mutex_unlock(v7 + 15);
          }
          return 0;
        }
      }
      else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      {
        dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "is_amic_enabled");
      }
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "is_amic_enabled");
    }
    v37 = (unsigned int)(v9 + 13336);
    v38 = v3 - 208;
    v39 = 3;
    goto LABEL_85;
  }
  if ( a3 != 1 )
  {
LABEL_21:
    if ( a3 != 2 )
      return result;
    snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13312), 32, 32);
    v19 = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 3);
    if ( v19 )
    {
      v20 = *(_QWORD *)(v19 + 152);
      if ( v20 && *(_QWORD *)(v20 + 168) )
      {
        if ( (snd_soc_component_read(v3 - 208, v47 | 0x3104u) & 1) != 0 && *(_BYTE *)(v20 + 1580) != 1 )
        {
LABEL_38:
          v21 = snd_soc_component_read(v3 - 208, (unsigned int)(v9 + 13316));
          v22 = (__int64)&v7[15 * (unsigned int)v8 + 37];
          *(_BYTE *)(v22 + 9) = (v21 >> 5) & 3;
          v23 = (_BYTE *)(v22 + 9);
          if ( ((v21 >> 5) & 3) != 2 )
            snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13316), 96, 64);
          v24 = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 3);
          if ( v24 )
          {
            v25 = *(_QWORD *)(v24 + 152);
            if ( v25 && *(_QWORD *)(v25 + 168) )
            {
              if ( (snd_soc_component_read(v3 - 208, v47 | 0x3104u) & 1) != 0
                && (*(_BYTE *)(v25 + 1580) & 1) == 0
                && va_tx_unmute_delay <= 99 )
              {
                va_tx_unmute_delay = 100;
              }
            }
            else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
            {
              dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "is_amic_enabled");
            }
          }
          else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
          {
            dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "is_amic_enabled");
          }
          snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13336), 3, 2);
          v26 = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 3);
          if ( v26 )
          {
            v27 = *(_QWORD *)(v26 + 152);
            if ( v27 && *(_QWORD *)(v27 + 168) )
            {
              if ( (snd_soc_component_read(v3 - 208, v47 | 0x3104u) & 1) != 0 && *(_BYTE *)(v27 + 1580) != 1 )
                goto LABEL_60;
            }
            else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
            {
              dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "is_amic_enabled");
            }
          }
          else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
          {
            dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "is_amic_enabled");
          }
          snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13336), 3, 0);
LABEL_60:
          usleep_range_state(1000, 1010, 2);
          snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13336), 3, 1);
          usleep_range_state(6000, 6010, 2);
          if ( (*((_BYTE *)v7 + 1580) & 1) == 0 )
          {
            mutex_lock(v7 + 15);
            v28 = *((_DWORD *)v7 + 396);
            *((_DWORD *)v7 + 396) = v28 + 1;
            if ( !v28 )
              pm_stay_awake(*v7);
            mutex_unlock(v7 + 15);
            v29 = system_freezable_wq;
            v30 = _msecs_to_jiffies((unsigned int)va_tx_unmute_delay);
            queue_delayed_work_on(32, v29, &v7[15 * (unsigned int)v8 + 99], v30);
          }
          if ( *v23 != 2 )
          {
            mutex_lock(v7 + 15);
            v31 = *((_DWORD *)v7 + 396);
            *((_DWORD *)v7 + 396) = v31 + 1;
            if ( !v31 )
              pm_stay_awake(*v7);
            mutex_unlock(v7 + 15);
            queue_delayed_work_on(32, system_freezable_wq, &v7[15 * (unsigned int)v8 + 39], 75);
          }
          v32 = snd_soc_component_read(v3 - 208, (unsigned int)(v9 + 13324));
          snd_soc_component_write(v3 - 208, (unsigned int)(v9 + 13324), v32);
          return 0;
        }
      }
      else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      {
        dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "is_amic_enabled");
      }
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "is_amic_enabled");
    }
    snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13336), 1, 0);
    usleep_range_state(1000, 1010, 2);
    goto LABEL_38;
  }
  snd_soc_component_update_bits(v3 - 208, (unsigned int)(v9 + 13316), 6, (unsigned int)(2 * *((_DWORD *)v12 + 385)));
  return 0;
}
