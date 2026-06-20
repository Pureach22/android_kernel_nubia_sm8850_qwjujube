__int64 __fastcall wcd938x_probe(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 *v3; // x0
  __int64 *v4; // x20
  __int64 v5; // x0
  __int64 v6; // x22
  unsigned int inited; // w0
  __int64 v8; // x1
  __int64 *v9; // x8
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x8
  int v13; // w22
  unsigned int v14; // w8
  __int64 v15; // x0
  __int64 v16; // x24
  unsigned __int64 v17; // x23
  _DWORD *v18; // x22
  unsigned int variable_u32_array; // w0
  __int64 v20; // x8
  int v21; // w10
  int v22; // w9
  int v23; // w9
  int v24; // w8
  __int64 v25; // x21
  __int64 v26; // x2
  __int64 result; // x0
  const char *v28; // x1
  unsigned int v29; // w20
  unsigned __int64 StatusReg; // x25
  __int64 v31; // x26
  __int64 v32; // [xsp+0h] [xbp-60h] BYREF
  __int64 v33; // [xsp+8h] [xbp-58h] BYREF
  __int64 v34; // [xsp+10h] [xbp-50h]
  __int64 v35; // [xsp+18h] [xbp-48h]
  __int64 v36; // [xsp+20h] [xbp-40h]
  __int64 v37; // [xsp+28h] [xbp-38h]
  __int64 v38; // [xsp+30h] [xbp-30h]
  __int64 v39; // [xsp+38h] [xbp-28h]
  __int64 v40; // [xsp+40h] [xbp-20h]
  __int64 v41; // [xsp+48h] [xbp-18h]
  __int64 v42; // [xsp+50h] [xbp-10h]
  __int64 v43; // [xsp+58h] [xbp-8h]

  v1 = (__int64)(a1 + 2);
  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v3 = (__int64 *)devm_kmalloc(a1 + 2, 3280, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_138;
  }
  v4 = v3;
  a1[21] = v3;
  *v3 = v1;
  v5 = wcd938x_populate_dt_data(v1);
  if ( !v5 )
  {
    dev_err(v1, "%s: Fail to obtain platform data\n", "wcd938x_probe");
LABEL_123:
    result = 4294967274LL;
    goto LABEL_138;
  }
  a1[20] = v5;
  v6 = v5;
  v4[3] = *(_QWORD *)v5;
  inited = msm_cdc_init_supplies(v1, v4 + 386, *(_QWORD *)(v5 + 56), *(unsigned int *)(v5 + 64));
  v8 = v4[386];
  if ( !v8 )
  {
    v28 = "%s: Cannot init wcd supplies\n";
LABEL_125:
    v29 = inited;
    dev_err(v1, v28, "wcd938x_probe");
LABEL_137:
    result = v29;
    goto LABEL_138;
  }
  v9 = *(__int64 **)(a1[14] + 144LL);
  if ( !v9 )
  {
    dev_err(v1, "%s: platform data from parent is NULL\n", "wcd938x_probe");
    goto LABEL_123;
  }
  v10 = *v9;
  v4[390] = *v9;
  if ( !v10 )
  {
    dev_err(v1, "%s: handle is NULL\n", "wcd938x_probe");
    goto LABEL_123;
  }
  v11 = v9[1];
  v4[391] = v11;
  if ( !v11 )
  {
    dev_err(v1, "%s: update_wcd_event api is null!\n", "wcd938x_probe");
    goto LABEL_123;
  }
  v12 = v9[2];
  v4[392] = v12;
  if ( !v12 )
  {
    dev_err(v1, "%s: register_notifier api is null!\n", "wcd938x_probe");
    goto LABEL_123;
  }
  inited = msm_cdc_enable_static_supplies(v1, v8, *(_QWORD *)(v6 + 56), *(unsigned int *)(v6 + 64));
  if ( inited )
  {
    v28 = "%s: wcd static supply enable failed!\n";
    goto LABEL_125;
  }
  v13 = wcd938x_parse_port_mapping(v1, "qcom,rx_swr_ch_map", 1);
  v14 = wcd938x_parse_port_mapping(v1, "qcom,tx_swr_ch_map", 0) | v13;
  if ( v14 )
  {
    v29 = v14;
    dev_err(v1, "Failed to read port mapping\n");
    goto LABEL_137;
  }
  v15 = a1[95];
  v16 = a1[21];
  LODWORD(v33) = 0;
  if ( !of_find_property(v15, "qcom,swr-tx-port-params", &v33) )
  {
    dev_err(v1, "missing port mapping prop %s\n", "qcom,swr-tx-port-params");
LABEL_129:
    v29 = -22;
LABEL_136:
    dev_err(v1, "Failed to read port params\n");
    goto LABEL_137;
  }
  if ( (v33 & 0xFFFFFFE0) != 0x80 )
  {
    dev_err(v1, "%s: port params not provided for all usecases\n", "wcd938x_parse_port_params");
    goto LABEL_129;
  }
  v17 = (unsigned int)v33;
  v18 = (_DWORD *)_kmalloc_noprof((unsigned int)v33, 3520);
  if ( !v18 )
  {
LABEL_135:
    v29 = -12;
    goto LABEL_136;
  }
  while ( 1 )
  {
    variable_u32_array = of_property_read_variable_u32_array(a1[95], "qcom,swr-tx-port-params", v18, 32, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v29 = variable_u32_array;
      dev_err(
        v1,
        "%s: Failed to read  port mapping from prop %s\n",
        "wcd938x_parse_port_params",
        "qcom,swr-tx-port-params");
      kfree(v18);
      goto LABEL_136;
    }
    if ( v17 >= 4 )
    {
      v20 = (unsigned int)v17 & 0xFFFFFFFC;
      *(_DWORD *)(v16 + 2924) = *v18;
      if ( v20 != 4 )
      {
        *(_DWORD *)(v16 + 2928) = v18[1];
        if ( v17 >= 8 && v20 != 8 && (v17 & 0xFFFFFFFC) != 8 )
        {
          *(_DWORD *)(v16 + 2932) = v18[2];
          if ( v17 >= 0xC && v20 != 12 && (v17 & 0xFFFFFFFC) != 0xC )
          {
            *(_DWORD *)(v16 + 2936) = v18[3];
            if ( v17 >= 0x10 && v20 != 16 && (v17 & 0xFFFFFFFC) != 0x10 )
            {
              *(_DWORD *)(v16 + 2940) = v18[4];
              if ( v17 >= 0x14 && v20 != 20 && (v17 & 0xFFFFFFFC) != 0x14 )
              {
                *(_DWORD *)(v16 + 2944) = v18[5];
                if ( v17 >= 0x18 && v20 != 24 && (v17 & 0xFFFFFFFC) != 0x18 )
                {
                  *(_DWORD *)(v16 + 2948) = v18[6];
                  if ( v17 >= 0x1C && v20 != 28 && (v17 & 0xFFFFFFFC) != 0x1C )
                  {
                    v21 = v18[7];
                    *(_QWORD *)(v16 + 3056) = v16 + 2924;
                    *(_DWORD *)(v16 + 2952) = v21;
                    if ( v17 >= 0x20 && v20 != 32 && (v17 & 0xFFFFFFFC) != 0x20 )
                    {
                      *(_DWORD *)(v16 + 2956) = v18[8];
                      if ( v17 >= 0x24 && v20 != 36 && (v17 & 0xFFFFFFFC) != 0x24 )
                      {
                        *(_DWORD *)(v16 + 2960) = v18[9];
                        if ( v17 >= 0x28 && v20 != 40 && (v17 & 0xFFFFFFFC) != 0x28 )
                        {
                          *(_DWORD *)(v16 + 2964) = v18[10];
                          if ( v17 >= 0x2C && v20 != 44 && (v17 & 0xFFFFFFFC) != 0x2C )
                          {
                            *(_DWORD *)(v16 + 2968) = v18[11];
                            if ( v17 >= 0x30 && v20 != 48 && (v17 & 0xFFFFFFFC) != 0x30 )
                            {
                              *(_DWORD *)(v16 + 2972) = v18[12];
                              if ( v17 >= 0x34 && v20 != 52 && (v17 & 0xFFFFFFFC) != 0x34 )
                              {
                                *(_DWORD *)(v16 + 2976) = v18[13];
                                if ( v17 >= 0x38 && v20 != 56 && (v17 & 0xFFFFFFFC) != 0x38 )
                                {
                                  *(_DWORD *)(v16 + 2980) = v18[14];
                                  if ( v17 >= 0x3C && v20 != 60 && (v17 & 0xFFFFFFFC) != 0x3C )
                                  {
                                    v22 = v18[15];
                                    *(_QWORD *)(v16 + 3064) = v16 + 2956;
                                    *(_DWORD *)(v16 + 2984) = v22;
                                    if ( v17 >= 0x40 && v20 != 64 && (v17 & 0xFFFFFFFC) != 0x40 )
                                    {
                                      *(_DWORD *)(v16 + 2988) = v18[16];
                                      if ( v17 >= 0x44 && v20 != 68 && (v17 & 0xFFFFFFFC) != 0x44 )
                                      {
                                        *(_DWORD *)(v16 + 2992) = v18[17];
                                        if ( v17 >= 0x48 && v20 != 72 && (v17 & 0xFFFFFFFC) != 0x48 )
                                        {
                                          *(_DWORD *)(v16 + 2996) = v18[18];
                                          if ( v17 >= 0x4C && v20 != 76 && (v17 & 0xFFFFFFFC) != 0x4C )
                                          {
                                            *(_DWORD *)(v16 + 3000) = v18[19];
                                            if ( v17 >= 0x50 && v20 != 80 && (v17 & 0xFFFFFFFC) != 0x50 )
                                            {
                                              *(_DWORD *)(v16 + 3004) = v18[20];
                                              if ( v17 >= 0x54 && v20 != 84 && (v17 & 0xFFFFFFFC) != 0x54 )
                                              {
                                                *(_DWORD *)(v16 + 3008) = v18[21];
                                                if ( v17 >= 0x58 && v20 != 88 && (v17 & 0xFFFFFFFC) != 0x58 )
                                                {
                                                  *(_DWORD *)(v16 + 3012) = v18[22];
                                                  if ( v17 >= 0x5C && v20 != 92 && (v17 & 0xFFFFFFFC) != 0x5C )
                                                  {
                                                    v23 = v18[23];
                                                    *(_QWORD *)(v16 + 3072) = v16 + 2988;
                                                    *(_DWORD *)(v16 + 3016) = v23;
                                                    if ( v17 >= 0x60 && v20 != 96 && (v17 & 0xFFFFFFFC) != 0x60 )
                                                    {
                                                      *(_DWORD *)(v16 + 3020) = v18[24];
                                                      if ( v17 >= 0x64 && v20 != 100 && (v17 & 0xFFFFFFFC) != 0x64 )
                                                      {
                                                        *(_DWORD *)(v16 + 3024) = v18[25];
                                                        if ( v17 >= 0x68 && v20 != 104 && (v17 & 0xFFFFFFFC) != 0x68 )
                                                        {
                                                          *(_DWORD *)(v16 + 3028) = v18[26];
                                                          if ( v17 >= 0x6C && v20 != 108 && (v17 & 0xFFFFFFFC) != 0x6C )
                                                          {
                                                            *(_DWORD *)(v16 + 3032) = v18[27];
                                                            if ( v17 >= 0x70 && v20 != 112 && (v17 & 0xFFFFFFFC) != 0x70 )
                                                            {
                                                              *(_DWORD *)(v16 + 3036) = v18[28];
                                                              if ( v17 >= 0x74
                                                                && v20 != 116
                                                                && (v17 & 0xFFFFFFFC) != 0x74 )
                                                              {
                                                                *(_DWORD *)(v16 + 3040) = v18[29];
                                                                if ( v17 >= 0x78
                                                                  && v20 != 120
                                                                  && (v17 & 0xFFFFFFFC) != 0x78 )
                                                                {
                                                                  *(_DWORD *)(v16 + 3044) = v18[30];
                                                                  if ( v17 >= 0x7C
                                                                    && v20 != 124
                                                                    && (v17 & 0xFFFFFFFC) != 0x7C )
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
    v17 = (unsigned int)v33;
    StatusReg = _ReadStatusReg(SP_EL0);
    v31 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &wcd938x_parse_port_params__alloc_tag;
    v18 = (_DWORD *)_kmalloc_noprof(v17, 3520);
    *(_QWORD *)(StatusReg + 80) = v31;
    if ( !v18 )
      goto LABEL_135;
  }
  v24 = v18[31];
  *(_QWORD *)(v16 + 3080) = v16 + 3020;
  *(_DWORD *)(v16 + 3048) = v24;
  kfree(v18);
  _mutex_init(v4 + 19, "&wcd938x->wakeup_lock", &wcd938x_probe___key);
  _mutex_init(v4 + 13, "&wcd938x->micb_lock", &wcd938x_probe___key_74);
  v25 = a1[95];
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v25, "qcom,rx-slave", 0, 0, 0, &v33) || !v33 )
  {
    if ( !(unsigned int)__ratelimit(&wcd938x_add_slave_components__rs, "wcd938x_add_slave_components") )
    {
LABEL_116:
      result = 4294967277LL;
      goto LABEL_138;
    }
    dev_err(v1, "%s: Rx-slave node not defined\n", "wcd938x_add_slave_components");
LABEL_132:
    result = 4294967277LL;
    goto LABEL_138;
  }
  component_match_add_release(v1, &v32, wcd938x_release_of, wcd938x_compare_of);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v25, "qcom,tx-slave", 0, 0, 0, &v33) || !v33 )
  {
    if ( !(unsigned int)__ratelimit(&wcd938x_add_slave_components__rs_86, "wcd938x_add_slave_components") )
      goto LABEL_116;
    dev_err(v1, "%s: Tx-slave node not defined\n", "wcd938x_add_slave_components");
    goto LABEL_132;
  }
  component_match_add_release(v1, &v32, wcd938x_release_of, wcd938x_compare_of);
  if ( (unsigned int)wcd938x_reset(v1) == -517 )
  {
    dev_err(v1, "%s: wcd reset failed!\n", "wcd938x_probe");
    result = 4294966779LL;
  }
  else
  {
    v26 = v32;
    v4[393] = (__int64)wcd938x_wakeup;
    result = component_master_add_with_match(v1, wcd938x_comp_ops, v26);
  }
LABEL_138:
  _ReadStatusReg(SP_EL0);
  return result;
}
