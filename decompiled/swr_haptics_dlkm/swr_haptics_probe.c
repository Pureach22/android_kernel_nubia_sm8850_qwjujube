__int64 __fastcall swr_haptics_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x23
  __int64 v4; // x0
  _QWORD *v5; // x20
  int match_data; // w0
  char v7; // w8
  unsigned int v8; // w22
  _QWORD *v9; // x22
  unsigned int v10; // w0
  char v11; // w9
  char v12; // w8
  int v13; // w10
  char v14; // w8
  unsigned int v15; // w0
  char v16; // w9
  char v17; // w8
  int v18; // w10
  char v19; // w8
  unsigned __int64 v20; // x0
  __int64 v21; // x0
  const char *v22; // x1
  unsigned __int64 v23; // x0
  unsigned int variable_u32_array; // w0
  unsigned int v25; // w0
  __int64 v26; // x22
  int v27; // w8
  int v28; // w24
  int logical_dev_num; // w23
  unsigned __int64 inited; // x0
  unsigned int v31; // w0
  char v32; // w8
  unsigned __int64 v33; // x0
  unsigned int v34; // w0
  __int64 v35; // x3
  int v37; // w0
  int v38; // w21
  __int64 v39; // [xsp+0h] [xbp-20h] BYREF
  __int64 v40; // [xsp+8h] [xbp-18h]
  int v41; // [xsp+10h] [xbp-10h]
  __int64 v42; // [xsp+18h] [xbp-8h]

  v1 = a1 + 72;
  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 816);
  v4 = devm_kmalloc(a1 + 72, 192, 3520);
  if ( !v4 )
  {
    v8 = -12;
    goto LABEL_48;
  }
  v5 = (_QWORD *)v4;
  *(_QWORD *)v4 = v1;
  *(_QWORD *)(v4 + 8) = a1;
  *(_BYTE *)(v4 + 184) = 100;
  match_data = of_device_get_match_data(v1);
  if ( match_data == 1 )
  {
    v7 = 1;
    goto LABEL_7;
  }
  if ( match_data == 3 )
  {
    v7 = 6;
LABEL_7:
    *((_BYTE *)v5 + 186) |= v7;
  }
  *(_QWORD *)(a1 + 224) = v5;
  _mutex_init(v5 + 15, "&swr_hap->play_lock", &swr_haptics_probe___key);
  if ( !a1 || (v9 = *(_QWORD **)(a1 + 224), v41 = 0, v39 = 0, v40 = 0, !v9) )
  {
    dev_err(v1, "%s: get swr_haptics_dev failed\n", "swr_haptics_parse_port_mapping");
    goto LABEL_45;
  }
  v10 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 816), "qcom,rx_swr_ch_map", &v39, 5, 0);
  if ( (v10 & 0x80000000) != 0 )
  {
    dev_err(*v9, "%s: Get qcom,rx_swr_ch_map failed, rc=%d\n", "swr_haptics_parse_port_mapping", v10);
    goto LABEL_45;
  }
  v11 = BYTE4(v39);
  *((_BYTE *)v9 + 32) = v39;
  v12 = v40;
  v13 = HIDWORD(v40);
  *((_BYTE *)v9 + 40) = v11;
  *((_BYTE *)v9 + 33) = v12;
  v14 = v41;
  *((_DWORD *)v9 + 9) = v13;
  *((_BYTE *)v9 + 41) = v14;
  if ( of_find_property(*(_QWORD *)(a1 + 816), "qcom,rx_swr_vi_ch_map", 0) )
  {
    v15 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 816), "qcom,rx_swr_vi_ch_map", &v39, 5, 0);
    if ( (v15 & 0x80000000) == 0 )
    {
      v16 = BYTE4(v39);
      *((_BYTE *)v9 + 44) = v39;
      v17 = v40;
      v18 = HIDWORD(v40);
      *((_BYTE *)v9 + 52) = v16;
      *((_BYTE *)v9 + 45) = v17;
      v19 = v41;
      *((_DWORD *)v9 + 12) = v18;
      *((_BYTE *)v9 + 53) = v19;
      goto LABEL_14;
    }
    dev_err(*v9, "%s: Get qcom,rx_swr_vi_ch_map failed, rc=%d\n", "swr_haptics_parse_port_mapping", v15);
LABEL_45:
    v21 = *v5;
    v22 = "%s: failed to parse swr port mapping, rc=%d\n";
    v35 = 4294967274LL;
    v8 = -22;
LABEL_46:
    dev_err(v21, v22, "swr_haptics_probe", v35);
    goto LABEL_47;
  }
  dev_err(*v9, "%s: qcom,rx_swr_vi_ch_map not supported\n", "swr_haptics_parse_port_mapping");
LABEL_14:
  v20 = devm_regulator_get(*v5, "swr-slave");
  v5[7] = v20;
  if ( v20 >= 0xFFFFFFFFFFFFF001LL )
  {
    v8 = v20;
    if ( (_DWORD)v20 != -517 )
    {
      v21 = *v5;
      v22 = "%s: get swr-slave-supply failed, rc=%d\n";
LABEL_59:
      v35 = v8;
      goto LABEL_46;
    }
    goto LABEL_20;
  }
  if ( of_find_property(v3, "qcom,hpwr-supply", 0) )
  {
    v23 = devm_regulator_get(*v5, "qcom,hpwr");
    v5[8] = v23;
    if ( v23 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (_DWORD)v23 != -517 )
      {
        v8 = v23;
        v21 = *v5;
        v22 = "%s: Get qcom,hpwr-supply failed, rc=%d\n";
        goto LABEL_59;
      }
LABEL_20:
      v8 = -517;
LABEL_47:
      *(_QWORD *)(a1 + 224) = 0;
      goto LABEL_48;
    }
    variable_u32_array = of_property_read_variable_u32_array(v3, "qcom,hpwr-voltage-mv", v5 + 22, 1, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v8 = variable_u32_array;
      v21 = *v5;
      v22 = "%s: Failed to read qcom,hpwr-voltage-mv, rc=%d\n";
      goto LABEL_59;
    }
  }
  if ( (*((_BYTE *)v5 + 180) & 1) == 0 )
  {
    v25 = regulator_enable(v5[7]);
    if ( (v25 & 0x80000000) != 0 )
    {
      v8 = v25;
      if ( (unsigned int)__ratelimit(&swr_haptics_slave_enable__rs, "swr_haptics_slave_enable") )
        dev_err(*v5, "%s: enable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_enable", v8);
      v21 = *v5;
      v22 = "%s: enable swr-slave-vdd failed, rc=%d\n";
      goto LABEL_59;
    }
    *((_BYTE *)v5 + 180) = 1;
  }
  v26 = v5[1];
  LOBYTE(v39) = 0;
  usleep_range_state(500, 510, 2);
  v27 = -29;
  do
  {
    v28 = v27;
    logical_dev_num = swr_get_logical_dev_num(v26, *(_QWORD *)(v26 + 984), &v39);
    if ( logical_dev_num < 0 )
      msleep(20);
    if ( !logical_dev_num )
      break;
    v27 = v28 + 1;
  }
  while ( v28 );
  if ( logical_dev_num )
  {
    dev_err(*v5, "%s: failed to get devnum for swr-haptics, rc=%d\n", "swr_haptics_slave_enumeration", logical_dev_num);
    v8 = -517;
    goto LABEL_61;
  }
  *(_BYTE *)(v26 + 64) = v39;
  inited = _devm_regmap_init_swr(a1, &swr_hap_regmap_config, 0, 0);
  v5[3] = inited;
  if ( inited >= 0xFFFFFFFFFFFFF001LL )
  {
    v8 = inited;
    dev_err(*v5, "%s: init regmap failed, rc=%d\n", "swr_haptics_probe", (unsigned int)inited);
    goto LABEL_61;
  }
  v31 = snd_soc_register_component(v1, &swr_haptics_component, &haptics_dai, 2);
  if ( v31 )
  {
    v8 = v31;
    dev_err(*v5, "%s: register swr_haptics component failed, rc=%d\n", "swr_haptics_probe", v31);
    goto LABEL_61;
  }
  v5[9] = hboost_notifier;
  register_hboost_event_notifier(v5 + 9);
  v32 = *((_BYTE *)v5 + 186);
  if ( (v32 & 4) != 0 )
  {
    v5[12] = lpass_ssr_notifier;
    v33 = qcom_register_ssr_notifier("lpass", v5 + 12);
    v5[21] = v33;
    if ( v33 <= 0xFFFFFFFFFFFFF000LL )
    {
      v32 = *((_BYTE *)v5 + 186);
      goto LABEL_36;
    }
    v8 = v33;
    dev_err(*v5, "%s: register SSR notifier failed, rc:%d\n", "swr_haptics_probe", (unsigned int)v33);
LABEL_61:
    if ( *((_BYTE *)v5 + 180) == 1 )
    {
      v37 = regulator_disable(v5[7]);
      if ( v37 < 0 )
      {
        v38 = v37;
        if ( (unsigned int)__ratelimit(&swr_haptics_slave_disable__rs, "swr_haptics_slave_disable") )
          dev_err(*v5, "%s: disable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_disable", v38);
      }
      else
      {
        *((_BYTE *)v5 + 180) = 0;
      }
    }
    swr_remove_device(a1);
    goto LABEL_47;
  }
LABEL_36:
  if ( (v32 & 2) != 0 && *((_BYTE *)v5 + 180) == 1 )
  {
    v34 = regulator_disable(v5[7]);
    if ( (v34 & 0x80000000) != 0 )
    {
      v8 = v34;
      if ( (unsigned int)__ratelimit(&swr_haptics_slave_disable__rs, "swr_haptics_slave_disable") )
        dev_err(*v5, "%s: disable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_disable", v8);
    }
    else
    {
      v8 = 0;
      *((_BYTE *)v5 + 180) = 0;
    }
  }
  else
  {
    v8 = 0;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return v8;
}
