__int64 __fastcall wcd9378_probe(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 *v3; // x0
  __int64 *v4; // x20
  __int64 v5; // x0
  __int64 v6; // x22
  unsigned int inited; // w0
  __int64 *v8; // x8
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x8
  int v12; // w22
  unsigned int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x24
  unsigned __int64 v16; // x23
  _DWORD *v17; // x22
  unsigned int variable_u32_array; // w0
  __int64 v19; // x8
  int v20; // w10
  int v21; // w9
  int v22; // w9
  int v23; // w8
  __int64 v24; // x21
  __int64 v25; // x2
  __int64 result; // x0
  const char *v27; // x1
  unsigned int v28; // w20
  unsigned __int64 StatusReg; // x25
  __int64 v30; // x26
  __int64 v31; // [xsp+0h] [xbp-60h] BYREF
  __int64 v32; // [xsp+8h] [xbp-58h] BYREF
  __int64 v33; // [xsp+10h] [xbp-50h]
  __int64 v34; // [xsp+18h] [xbp-48h]
  __int64 v35; // [xsp+20h] [xbp-40h]
  __int64 v36; // [xsp+28h] [xbp-38h]
  __int64 v37; // [xsp+30h] [xbp-30h]
  __int64 v38; // [xsp+38h] [xbp-28h]
  __int64 v39; // [xsp+40h] [xbp-20h]
  __int64 v40; // [xsp+48h] [xbp-18h]
  __int64 v41; // [xsp+50h] [xbp-10h]
  __int64 v42; // [xsp+58h] [xbp-8h]

  v1 = (__int64)(a1 + 2);
  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v3 = (__int64 *)devm_kmalloc(a1 + 2, 3384, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_137;
  }
  v4 = v3;
  a1[21] = v3;
  *v3 = v1;
  v5 = wcd9378_populate_dt_data(v1);
  if ( !v5 )
  {
    dev_err(v1, "%s: Fail to obtain platform data\n", "wcd9378_probe");
LABEL_121:
    result = 4294967274LL;
    goto LABEL_137;
  }
  a1[20] = v5;
  v6 = v5;
  v4[5] = *(_QWORD *)v5;
  inited = msm_cdc_init_supplies(v1, v4 + 399, *(_QWORD *)(v5 + 64), *(unsigned int *)(v5 + 72));
  if ( !v4[399] )
  {
    v27 = "%s: Cannot init wcd supplies\n";
LABEL_123:
    v28 = inited;
    dev_err(v1, v27, "wcd9378_probe");
LABEL_136:
    result = v28;
    goto LABEL_137;
  }
  v8 = *(__int64 **)(a1[14] + 144LL);
  if ( !v8 )
  {
    dev_err(v1, "%s: platform data from parent is NULL\n", "wcd9378_probe");
    goto LABEL_121;
  }
  v9 = *v8;
  v4[403] = *v8;
  if ( !v9 )
  {
    dev_err(v1, "%s: handle is NULL\n", "wcd9378_probe");
    goto LABEL_121;
  }
  v10 = v8[1];
  v4[404] = v10;
  if ( !v10 )
  {
    dev_err(v1, "%s: update_wcd_event api is null!\n", "wcd9378_probe");
    goto LABEL_121;
  }
  v11 = v8[2];
  v4[405] = v11;
  if ( !v11 )
  {
    dev_err(v1, "%s: register_notifier api is null!\n", "wcd9378_probe");
    goto LABEL_121;
  }
  if ( (of_property_read_variable_u32_array(a1[95], "qcom,wcd-mode", v4 + 3, 1, 0) & 0x80000000) != 0 )
    *((_DWORD *)v4 + 6) = 1;
  inited = msm_cdc_enable_static_supplies(v1, v4[399], *(_QWORD *)(v6 + 64), *(unsigned int *)(v6 + 72));
  if ( inited )
  {
    v27 = "%s: wcd static supply enable failed!\n";
    goto LABEL_123;
  }
  v12 = wcd9378_parse_port_mapping(v1, "qcom,rx_swr_ch_map", 1);
  v13 = wcd9378_parse_port_mapping(v1, "qcom,tx_swr_ch_map", 0) | v12;
  if ( v13 )
  {
    v28 = v13;
    dev_err(v1, "Failed to read port mapping\n");
    goto LABEL_136;
  }
  v14 = a1[95];
  v15 = a1[21];
  LODWORD(v32) = 0;
  if ( !of_find_property(v14, "qcom,swr-tx-port-params", &v32) )
  {
    dev_err(v1, "missing port mapping prop %s\n", "qcom,swr-tx-port-params");
LABEL_127:
    v28 = -22;
LABEL_135:
    dev_err(v1, "Failed to read port params\n");
    goto LABEL_136;
  }
  if ( (v32 & 0xFFFFFFE0) != 0x80 )
  {
    dev_err(v1, "%s: port params not provided for all usecases\n", "wcd9378_parse_port_params");
    goto LABEL_127;
  }
  v16 = (unsigned int)v32;
  v17 = (_DWORD *)_kmalloc_noprof((unsigned int)v32, 3520);
  if ( !v17 )
  {
LABEL_134:
    v28 = -12;
    goto LABEL_135;
  }
  while ( 1 )
  {
    variable_u32_array = of_property_read_variable_u32_array(a1[95], "qcom,swr-tx-port-params", v17, 32, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v28 = variable_u32_array;
      dev_err(
        v1,
        "%s: Failed to read  port mapping from prop %s\n",
        "wcd9378_parse_port_params",
        "qcom,swr-tx-port-params");
      kfree(v17);
      goto LABEL_135;
    }
    if ( v16 >= 4 )
    {
      v19 = (unsigned int)v16 & 0xFFFFFFFC;
      *(_DWORD *)(v15 + 3028) = *v17;
      if ( v19 != 4 )
      {
        *(_DWORD *)(v15 + 3032) = v17[1];
        if ( v16 >= 8 && v19 != 8 && (v16 & 0xFFFFFFFC) != 8 )
        {
          *(_DWORD *)(v15 + 3036) = v17[2];
          if ( v16 >= 0xC && v19 != 12 && (v16 & 0xFFFFFFFC) != 0xC )
          {
            *(_DWORD *)(v15 + 3040) = v17[3];
            if ( v16 >= 0x10 && v19 != 16 && (v16 & 0xFFFFFFFC) != 0x10 )
            {
              *(_DWORD *)(v15 + 3044) = v17[4];
              if ( v16 >= 0x14 && v19 != 20 && (v16 & 0xFFFFFFFC) != 0x14 )
              {
                *(_DWORD *)(v15 + 3048) = v17[5];
                if ( v16 >= 0x18 && v19 != 24 && (v16 & 0xFFFFFFFC) != 0x18 )
                {
                  *(_DWORD *)(v15 + 3052) = v17[6];
                  if ( v16 >= 0x1C && v19 != 28 && (v16 & 0xFFFFFFFC) != 0x1C )
                  {
                    v20 = v17[7];
                    *(_QWORD *)(v15 + 3160) = v15 + 3028;
                    *(_DWORD *)(v15 + 3056) = v20;
                    if ( v16 >= 0x20 && v19 != 32 && (v16 & 0xFFFFFFFC) != 0x20 )
                    {
                      *(_DWORD *)(v15 + 3060) = v17[8];
                      if ( v16 >= 0x24 && v19 != 36 && (v16 & 0xFFFFFFFC) != 0x24 )
                      {
                        *(_DWORD *)(v15 + 3064) = v17[9];
                        if ( v16 >= 0x28 && v19 != 40 && (v16 & 0xFFFFFFFC) != 0x28 )
                        {
                          *(_DWORD *)(v15 + 3068) = v17[10];
                          if ( v16 >= 0x2C && v19 != 44 && (v16 & 0xFFFFFFFC) != 0x2C )
                          {
                            *(_DWORD *)(v15 + 3072) = v17[11];
                            if ( v16 >= 0x30 && v19 != 48 && (v16 & 0xFFFFFFFC) != 0x30 )
                            {
                              *(_DWORD *)(v15 + 3076) = v17[12];
                              if ( v16 >= 0x34 && v19 != 52 && (v16 & 0xFFFFFFFC) != 0x34 )
                              {
                                *(_DWORD *)(v15 + 3080) = v17[13];
                                if ( v16 >= 0x38 && v19 != 56 && (v16 & 0xFFFFFFFC) != 0x38 )
                                {
                                  *(_DWORD *)(v15 + 3084) = v17[14];
                                  if ( v16 >= 0x3C && v19 != 60 && (v16 & 0xFFFFFFFC) != 0x3C )
                                  {
                                    v21 = v17[15];
                                    *(_QWORD *)(v15 + 3168) = v15 + 3060;
                                    *(_DWORD *)(v15 + 3088) = v21;
                                    if ( v16 >= 0x40 && v19 != 64 && (v16 & 0xFFFFFFFC) != 0x40 )
                                    {
                                      *(_DWORD *)(v15 + 3092) = v17[16];
                                      if ( v16 >= 0x44 && v19 != 68 && (v16 & 0xFFFFFFFC) != 0x44 )
                                      {
                                        *(_DWORD *)(v15 + 3096) = v17[17];
                                        if ( v16 >= 0x48 && v19 != 72 && (v16 & 0xFFFFFFFC) != 0x48 )
                                        {
                                          *(_DWORD *)(v15 + 3100) = v17[18];
                                          if ( v16 >= 0x4C && v19 != 76 && (v16 & 0xFFFFFFFC) != 0x4C )
                                          {
                                            *(_DWORD *)(v15 + 3104) = v17[19];
                                            if ( v16 >= 0x50 && v19 != 80 && (v16 & 0xFFFFFFFC) != 0x50 )
                                            {
                                              *(_DWORD *)(v15 + 3108) = v17[20];
                                              if ( v16 >= 0x54 && v19 != 84 && (v16 & 0xFFFFFFFC) != 0x54 )
                                              {
                                                *(_DWORD *)(v15 + 3112) = v17[21];
                                                if ( v16 >= 0x58 && v19 != 88 && (v16 & 0xFFFFFFFC) != 0x58 )
                                                {
                                                  *(_DWORD *)(v15 + 3116) = v17[22];
                                                  if ( v16 >= 0x5C && v19 != 92 && (v16 & 0xFFFFFFFC) != 0x5C )
                                                  {
                                                    v22 = v17[23];
                                                    *(_QWORD *)(v15 + 3176) = v15 + 3092;
                                                    *(_DWORD *)(v15 + 3120) = v22;
                                                    if ( v16 >= 0x60 && v19 != 96 && (v16 & 0xFFFFFFFC) != 0x60 )
                                                    {
                                                      *(_DWORD *)(v15 + 3124) = v17[24];
                                                      if ( v16 >= 0x64 && v19 != 100 && (v16 & 0xFFFFFFFC) != 0x64 )
                                                      {
                                                        *(_DWORD *)(v15 + 3128) = v17[25];
                                                        if ( v16 >= 0x68 && v19 != 104 && (v16 & 0xFFFFFFFC) != 0x68 )
                                                        {
                                                          *(_DWORD *)(v15 + 3132) = v17[26];
                                                          if ( v16 >= 0x6C && v19 != 108 && (v16 & 0xFFFFFFFC) != 0x6C )
                                                          {
                                                            *(_DWORD *)(v15 + 3136) = v17[27];
                                                            if ( v16 >= 0x70 && v19 != 112 && (v16 & 0xFFFFFFFC) != 0x70 )
                                                            {
                                                              *(_DWORD *)(v15 + 3140) = v17[28];
                                                              if ( v16 >= 0x74
                                                                && v19 != 116
                                                                && (v16 & 0xFFFFFFFC) != 0x74 )
                                                              {
                                                                *(_DWORD *)(v15 + 3144) = v17[29];
                                                                if ( v16 >= 0x78
                                                                  && v19 != 120
                                                                  && (v16 & 0xFFFFFFFC) != 0x78 )
                                                                {
                                                                  *(_DWORD *)(v15 + 3148) = v17[30];
                                                                  if ( v16 >= 0x7C
                                                                    && v19 != 124
                                                                    && (v16 & 0xFFFFFFFC) != 0x7C )
                                                                  {
                                                                    break;
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    __break(1u);
    v16 = (unsigned int)v32;
    StatusReg = _ReadStatusReg(SP_EL0);
    v30 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &wcd9378_parse_port_params__alloc_tag;
    v17 = (_DWORD *)_kmalloc_noprof(v16, 3520);
    *(_QWORD *)(StatusReg + 80) = v30;
    if ( !v17 )
      goto LABEL_134;
  }
  v23 = v17[31];
  *(_QWORD *)(v15 + 3184) = v15 + 3124;
  *(_DWORD *)(v15 + 3152) = v23;
  kfree(v17);
  _mutex_init(v4 + 23, "&wcd9378->wakeup_lock", &wcd9378_probe___key);
  _mutex_init(v4 + 17, "&wcd9378->micb_lock", &wcd9378_probe___key_55);
  _mutex_init(v4 + 29, "&wcd9378->sys_usage_lock", &wcd9378_probe___key_57);
  v24 = a1[95];
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v24, "qcom,rx-slave", 0, 0, 0, &v32) || !v32 )
  {
    dev_err(v1, "%s: Rx-slave node not defined\n", "wcd9378_add_slave_components");
LABEL_131:
    result = 4294967277LL;
    goto LABEL_137;
  }
  component_match_add_release(v1, &v31, wcd9378_release_of, wcd9378_compare_of);
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v24, "qcom,tx-slave", 0, 0, 0, &v32) || !v32 )
  {
    dev_err(v1, "%s: Tx-slave node not defined\n", "wcd9378_add_slave_components");
    goto LABEL_131;
  }
  component_match_add_release(v1, &v31, wcd9378_release_of, wcd9378_compare_of);
  if ( (unsigned int)wcd9378_reset(v1) == -517 )
  {
    dev_err(v1, "%s: wcd reset failed!\n", "wcd9378_probe");
    result = 4294966779LL;
  }
  else
  {
    v25 = v31;
    v4[406] = (__int64)wcd9378_wakeup;
    result = component_master_add_with_match(v1, wcd9378_comp_ops, v25);
  }
LABEL_137:
  _ReadStatusReg(SP_EL0);
  return result;
}
