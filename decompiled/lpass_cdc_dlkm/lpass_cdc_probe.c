__int64 __fastcall lpass_cdc_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned int v5; // w0
  unsigned int v6; // w3
  unsigned __int64 v7; // x0
  __int64 v8; // x0
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x0
  __int64 v12; // x1
  unsigned __int64 v13; // x9
  __int64 result; // x0
  unsigned int v15; // w20
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v1 = a1 + 16;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v3 = devm_kmalloc(a1 + 16, 1144, 3520);
  if ( v3 )
  {
    v4 = v3;
    v5 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,num-macros", &v16, 1, 0);
    if ( (v5 & 0x80000000) != 0 )
    {
      v15 = v5;
      dev_err(v1, "%s:num-macros property not found\n", "lpass_cdc_probe");
      result = v15;
    }
    else
    {
      v6 = (unsigned __int16)v16;
      *(_WORD *)(v4 + 804) = v16;
      if ( v6 >= 6 )
      {
        dev_err(v1, "%s:num_macros(%d) > MAX_MACRO(%d) than supported\n", "lpass_cdc_probe", v6, 5);
        result = 4294967274LL;
      }
      else
      {
        of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,lpass-cdc-version", v4 + 848, 1, 0);
        _init_rwsem(v4 + 1008, "&(&priv->notifier)->rwsem", &lpass_cdc_probe___key);
        *(_QWORD *)(v4 + 1072) = 0;
        *(_QWORD *)v4 = v1;
        *(_WORD *)(v4 + 222) = 257;
        *(_BYTE *)(v4 + 224) = 1;
        v7 = lpass_cdc_regmap_init(v1, &lpass_cdc_regmap_config);
        *(_QWORD *)(v4 + 16) = v7;
        if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
        {
          devm_regmap_qti_debugfs_register(*(_QWORD *)v4, v7);
          v8 = proc_mkdir("lpass_cdc_reginfo", 0);
          *(_QWORD *)(v4 + 1136) = v8;
          if ( v8 )
          {
            if ( !proc_create_data("lpass_cdc_regdump", 292, v8, &lpass_cdc_proc_ops, v4) )
            {
              dev_err(v1, "%s: error creating proc read file interface\n", "lpass_cdc_probe");
              proc_remove(*(_QWORD *)(v4 + 1136));
              *(_QWORD *)(v4 + 1136) = 0;
            }
          }
          else
          {
            dev_err(v1, "%s: error creating proc dir interface\n", "lpass_cdc_probe");
          }
          *(_QWORD *)(v4 + 904) = &_lpass_cdc_reg_read;
          *(_QWORD *)(v4 + 912) = &_lpass_cdc_reg_write;
          *(_QWORD *)(v4 + 984) = lpass_cdc_update_wcd_event;
          *(_QWORD *)(v4 + 976) = v4;
          *(_QWORD *)(v4 + 992) = lpass_cdc_register_notifier;
          *(_QWORD *)(v4 + 872) = 0;
          *(_QWORD *)(a1 + 168) = v4;
          _mutex_init(v4 + 24, "&priv->macro_lock", &lpass_cdc_probe___key_69);
          _mutex_init(v4 + 72, "&priv->io_lock", &lpass_cdc_probe___key_71);
          _mutex_init(v4 + 120, "&priv->clk_lock", &lpass_cdc_probe___key_73);
          _mutex_init(v4 + 168, "&priv->vote_lock", &lpass_cdc_probe___key_75);
          *(_QWORD *)(v4 + 816) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v4 + 824) = v4 + 824;
          *(_QWORD *)(v4 + 832) = v4 + 824;
          *(_QWORD *)(v4 + 840) = lpass_cdc_add_child_devices;
          v9 = devm_clk_get(v1, "lpass_core_hw_vote");
          if ( v9 <= 0xFFFFFFFFFFFFF000LL )
            v10 = v9;
          else
            v10 = 0;
          *(_QWORD *)(v4 + 856) = v10;
          v11 = devm_clk_get(v1, "lpass_audio_hw_vote");
          v12 = system_wq;
          if ( v11 <= 0xFFFFFFFFFFFFF000LL )
            v13 = v11;
          else
            v13 = 0;
          *(_QWORD *)(v4 + 864) = v13;
          queue_work_on(32, v12, v4 + 816);
          result = 0;
        }
        else
        {
          dev_err(v1, "%s:regmap init failed\n", "lpass_cdc_probe");
          result = 4294967274LL;
        }
      }
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
