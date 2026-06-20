__int64 __fastcall lpass_cdc_tx_macro_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  _QWORD *v4; // x21
  __int64 v5; // x0
  unsigned int variable_u32_array; // w0
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 v9; // x22
  __int64 v10; // x0
  unsigned int v11; // w23
  __int64 v12; // x0
  int *v13; // x24
  int v14; // w3
  __int16 v15; // w8
  __int64 result; // x0
  unsigned int v17; // w20
  __int16 v18; // w8
  __int16 v19; // w8
  int v20; // w0
  unsigned int v21; // w0
  unsigned int v22; // w20
  __int64 v23; // [xsp+0h] [xbp-80h] BYREF
  __int64 (__fastcall *v24)(); // [xsp+8h] [xbp-78h] BYREF
  __int64 (__fastcall *v25)(); // [xsp+10h] [xbp-70h]
  __int64 v26; // [xsp+18h] [xbp-68h]
  __int64 v27; // [xsp+20h] [xbp-60h]
  char **v28; // [xsp+28h] [xbp-58h]
  __int64 v29; // [xsp+30h] [xbp-50h]
  __int64 (__fastcall *v30)(); // [xsp+38h] [xbp-48h]
  __int64 v31; // [xsp+40h] [xbp-40h]
  __int64 v32; // [xsp+48h] [xbp-38h]
  __int64 (__fastcall *v33)(); // [xsp+50h] [xbp-30h]
  __int64 v34; // [xsp+58h] [xbp-28h]
  __int64 (__fastcall *v35)(); // [xsp+60h] [xbp-20h]
  __int64 v36; // [xsp+68h] [xbp-18h]
  __int64 v37; // [xsp+70h] [xbp-10h]
  __int64 v38; // [xsp+78h] [xbp-8h]

  v1 = a1 + 16;
  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = nullptr;
  v32 = 0;
  v33 = nullptr;
  v30 = nullptr;
  v31 = 0;
  v28 = nullptr;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = nullptr;
  v25 = nullptr;
  v23 = 0;
  if ( (lpass_cdc_is_va_macro_registered(a1 + 16) & 1) == 0 )
  {
    dev_err(v1, "%s: va-macro not registered yet, defer\n", "lpass_cdc_tx_macro_probe");
    result = 4294966779LL;
    goto LABEL_78;
  }
  v3 = devm_kmalloc(v1, 2856, 3520);
  if ( !v3 )
    goto LABEL_14;
  v4 = (_QWORD *)v3;
  *(_QWORD *)(a1 + 168) = v3;
  v5 = *(_QWORD *)(a1 + 760);
  *v4 = v1;
  variable_u32_array = of_property_read_variable_u32_array(v5, "reg", (char *)&v23 + 4, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v17 = variable_u32_array;
    dev_err(v1, "%s: could not find %s entry in dt\n", "lpass_cdc_tx_macro_probe", "reg");
    result = v17;
    goto LABEL_78;
  }
  v7 = HIDWORD(v23);
  *(_QWORD *)(a1 + 168) = v4;
  v8 = devm_ioremap(v1, v7, 4096);
  if ( !v8 )
  {
    dev_err(v1, "%s: ioremap failed\n", "lpass_cdc_tx_macro_probe");
    result = 4294967284LL;
    goto LABEL_78;
  }
  v9 = v8;
  v4[326] = v8;
  v10 = *(_QWORD *)(a1 + 760);
  *((_WORD *)v4 + 1360) = 0;
  *((_DWORD *)v4 + 681) = 0;
  v4[316] = 0;
  if ( !of_find_property(v10, "qcom,tx-dmic-clk-div-factor", &v23) )
  {
    dev_err(v1, "%s: could not find div_clk_factor entry in dt\n", "lpass_cdc_tx_macro_probe");
    goto LABEL_74;
  }
  v11 = v23;
  v12 = devm_kmalloc(v1, (unsigned int)v23, 3520);
  if ( !v12 )
  {
LABEL_14:
    result = 4294967284LL;
    goto LABEL_78;
  }
  v13 = (int *)v12;
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(a1 + 760),
          "qcom,tx-dmic-clk-div-factor",
          v12,
          (unsigned __int64)(unsigned int)v23 >> 2,
          0)
      & 0x80000000) == 0 )
  {
    if ( v11 < 4 )
      goto LABEL_84;
    v14 = *v13;
    if ( *v13 > 5 )
    {
      switch ( v14 )
      {
        case 6:
          v15 = 3;
          goto LABEL_26;
        case 8:
          v15 = 4;
          goto LABEL_26;
        case 16:
          v15 = 5;
          goto LABEL_26;
      }
    }
    else
    {
      switch ( v14 )
      {
        case 2:
          *((_WORD *)v4 + 1264) = 0;
          goto LABEL_27;
        case 3:
          v15 = 1;
          goto LABEL_26;
        case 4:
          v15 = 2;
LABEL_26:
          *((_WORD *)v4 + 1264) = v15;
          goto LABEL_27;
      }
    }
    dev_err(*v4, "%s: Invalid div factor %d, for mic_pair %d\n", "lpass_cdc_tx_macro_update_clk_div_factor", v14, 0);
LABEL_27:
    if ( (v11 & 0xFFFFFFFC) == 4 )
      goto LABEL_84;
    v14 = v13[1];
    if ( v14 > 5 )
    {
      switch ( v14 )
      {
        case 6:
          v18 = 3;
          break;
        case 8:
          v18 = 4;
          break;
        case 16:
          v18 = 5;
          break;
        default:
          goto LABEL_81;
      }
    }
    else
    {
      if ( v14 == 2 )
      {
        *((_WORD *)v4 + 1265) = 0;
        if ( v11 < 8 )
          goto LABEL_84;
        goto LABEL_43;
      }
      if ( v14 != 3 )
      {
        if ( v14 == 4 )
        {
          v18 = 2;
          goto LABEL_42;
        }
LABEL_81:
        dev_err(*v4, "%s: Invalid div factor %d, for mic_pair %d\n", "lpass_cdc_tx_macro_update_clk_div_factor", v14, 1);
        if ( v11 < 8 )
          goto LABEL_84;
        goto LABEL_43;
      }
      v18 = 1;
    }
LABEL_42:
    *((_WORD *)v4 + 1265) = v18;
    if ( v11 < 8 )
      goto LABEL_84;
LABEL_43:
    if ( (v11 & 0xFFFFFFFC) == 8 )
      goto LABEL_84;
    v14 = v13[2];
    if ( v14 > 5 )
    {
      switch ( v14 )
      {
        case 6:
          v19 = 3;
          break;
        case 8:
          v19 = 4;
          break;
        case 16:
          v19 = 5;
          break;
        default:
LABEL_83:
          dev_err(
            *v4,
            "%s: Invalid div factor %d, for mic_pair %d\n",
            "lpass_cdc_tx_macro_update_clk_div_factor",
            v14,
            2);
          if ( v11 < 0xC )
            goto LABEL_84;
          goto LABEL_59;
      }
    }
    else
    {
      if ( v14 == 2 )
      {
        *((_WORD *)v4 + 1266) = 0;
        if ( v11 < 0xC )
          goto LABEL_84;
LABEL_59:
        if ( (v11 & 0xFFFFFFFC) != 0xC )
        {
          v14 = v13[3];
          if ( v14 > 5 )
          {
            switch ( v14 )
            {
              case 6:
                *((_WORD *)v4 + 1267) = 3;
                goto LABEL_74;
              case 8:
                *((_WORD *)v4 + 1267) = 4;
                goto LABEL_74;
              case 16:
                *((_WORD *)v4 + 1267) = 5;
                goto LABEL_74;
            }
          }
          else
          {
            switch ( v14 )
            {
              case 2:
                *((_WORD *)v4 + 1267) = 0;
                goto LABEL_74;
              case 3:
                *((_WORD *)v4 + 1267) = 1;
                goto LABEL_74;
              case 4:
                *((_WORD *)v4 + 1267) = 2;
                goto LABEL_74;
            }
          }
LABEL_85:
          dev_err(
            *v4,
            "%s: Invalid div factor %d, for mic_pair %d\n",
            "lpass_cdc_tx_macro_update_clk_div_factor",
            v14,
            3);
          goto LABEL_74;
        }
LABEL_84:
        __break(1u);
        goto LABEL_85;
      }
      if ( v14 != 3 )
      {
        if ( v14 == 4 )
        {
          v19 = 2;
          goto LABEL_58;
        }
        goto LABEL_83;
      }
      v19 = 1;
    }
LABEL_58:
    *((_WORD *)v4 + 1266) = v19;
    if ( v11 < 0xC )
      goto LABEL_84;
    goto LABEL_59;
  }
LABEL_74:
  v20 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "adapt-tuning-reg-values", (char *)v4 + 2732, 0, 30);
  *((_DWORD *)v4 + 682) = v20;
  if ( v20 < 0 )
  {
    dev_err(v1, "failure in reading tuning registers\n");
    *((_DWORD *)v4 + 682) = 0;
  }
  _mutex_init(v4 + 3, "&tx_priv->mclk_lock", &lpass_cdc_tx_macro_probe___key);
  _mutex_init(v4 + 9, "&tx_priv->wlock", &lpass_cdc_tx_macro_probe___key_11);
  v27 = 0;
  v24 = lpass_cdc_tx_macro_init;
  v25 = lpass_cdc_tx_macro_deinit;
  v28 = &lpass_cdc_tx_macro_dai;
  v29 = 0;
  v26 = 3;
  v30 = lpass_cdc_tx_macro_event_handler;
  v31 = 0;
  v32 = 0;
  v33 = lpass_cdc_tx_macro_clk_div_get;
  v36 = v9;
  v37 = 0;
  v34 = 0;
  v35 = _lpass_cdc_tx_macro_mclk_enable;
  v21 = lpass_cdc_register_macro(v1, 0, &v24);
  if ( v21 )
  {
    v22 = v21;
    dev_err(v1, "%s: register macro failed\n", "lpass_cdc_tx_macro_probe");
    result = v22;
  }
  else
  {
    pm_runtime_set_autosuspend_delay(v1, 50);
    _pm_runtime_use_autosuspend(v1, 1);
    _pm_runtime_set_status(v1, 2);
    *(_WORD *)(a1 + 504) |= 0x100u;
    pm_runtime_enable(v1);
    result = 0;
  }
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return result;
}
