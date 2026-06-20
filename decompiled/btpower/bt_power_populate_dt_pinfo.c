__int64 __fastcall bt_power_populate_dt_pinfo(__int64 a1)
{
  __int64 next_available_child; // x0
  const char **v3; // x20
  __int64 result; // x0
  __int64 v5; // x8
  const char *v6; // x25
  __int64 match_data; // x0
  __int64 v8; // x8
  __int64 v9; // x23
  __int64 v10; // x10
  __int64 v11; // x11
  int v12; // w3
  __int64 v13; // x27
  __int64 v14; // x20
  __int64 v15; // x21
  __int64 v16; // x24
  __int64 v17; // x25
  _DWORD *v18; // x28
  __int64 v19; // x21
  __int64 v20; // x20
  __int64 v21; // x21
  __int64 v22; // x20
  __int64 v23; // x21
  int named_gpio; // w0
  __int64 v25; // x1
  int v26; // w0
  int v27; // w0
  int v28; // w0
  __int64 v29; // x1
  int v30; // w0
  __int64 v31; // x1
  __int64 v32; // x8
  __int64 v33; // x1
  unsigned __int64 v34; // x0
  unsigned __int64 v35; // x1
  unsigned int v36; // w0
  unsigned __int64 v37; // x0
  unsigned __int64 v38; // x22
  unsigned int v39; // w0
  int v40; // w0
  __int64 v41; // x1
  int v42; // w0
  __int64 v43; // x1
  __int64 v44; // x22
  __int64 v45; // x20
  __int64 v46; // x0
  _QWORD *v47; // x21
  unsigned __int64 v48; // x0
  void *v49; // x0
  void *v50; // x0
  _QWORD v51[11]; // [xsp+8h] [xbp-58h] BYREF

  v51[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !pwr_data )
  {
    result = 4294967284LL;
    goto LABEL_68;
  }
  if ( *(_BYTE *)(pwr_data + 176) == 1 )
  {
    next_available_child = of_get_next_available_child(*(_QWORD *)(a1 + 760), 0);
    if ( next_available_child )
    {
      v3 = (const char **)next_available_child;
      do
      {
        v6 = *v3;
        if ( !strcmp(*v3, "bt_ganges") )
        {
          v5 = 304;
        }
        else
        {
          if ( strcmp(v6, "uwb_ganges") )
            goto LABEL_8;
          v5 = 312;
        }
        *(_QWORD *)(pwr_data + v5) = v3;
        printk(&unk_12796, "bt_power_populate_dt_pinfo");
LABEL_8:
        v3 = (const char **)of_get_next_available_child(*(_QWORD *)(a1 + 760), v3);
      }
      while ( v3 );
    }
  }
  match_data = of_device_get_match_data(a1 + 16);
  if ( !match_data )
  {
    printk(&unk_13931, "get_power_dt_pinfo");
    result = 4294967274LL;
    goto LABEL_68;
  }
  v8 = *(_QWORD *)(match_data + 24);
  v9 = pwr_data;
  v11 = *(_QWORD *)match_data;
  v10 = *(_QWORD *)(match_data + 8);
  *(_QWORD *)(pwr_data + 120) = *(_QWORD *)(match_data + 16);
  *(_QWORD *)(v9 + 128) = v8;
  *(_QWORD *)(v9 + 104) = v11;
  *(_QWORD *)(v9 + 112) = v10;
  *(_QWORD *)(v9 + 56) = *(_QWORD *)(match_data + 32);
  LODWORD(v8) = *(unsigned __int8 *)(v9 + 176);
  v12 = *(_DWORD *)(match_data + 40);
  *(_DWORD *)(v9 + 136) = v12;
  if ( (_DWORD)v8 != 1 )
  {
    if ( v12 < 1 )
    {
LABEL_70:
      printk(&unk_131A2, "get_power_dt_pinfo");
LABEL_34:
      v22 = *(_QWORD *)(a1 + 760);
      v23 = devm_pinctrl_get(a1 + 16);
      named_gpio = of_get_named_gpio(v22, "qcom,bt-reset-gpio", 0);
      *(_DWORD *)(pwr_data + 8) = named_gpio;
      if ( named_gpio < 0 )
        printk(&unk_134D9, v25);
      v26 = of_get_named_gpio(v22, "qcom,wl-reset-gpio", 0);
      *(_DWORD *)(pwr_data + 12) = v26;
      if ( v26 < 0 )
        printk(&unk_12E1E, "get_gpio_dt_pinfo");
      v27 = of_get_named_gpio(v22, "qcom,wl-resetb-gpio", 0);
      *(_DWORD *)(pwr_data + 32) = v27;
      if ( v27 < 0 )
        printk(&unk_131CE, "get_gpio_dt_pinfo");
      v28 = of_get_named_gpio(v22, "qcom,bt-sw-ctrl-gpio", 0);
      *(_DWORD *)(pwr_data + 16) = v28;
      if ( v28 < 0 )
        printk(&unk_12585, v29);
      v30 = of_get_named_gpio(v22, "qcom,bt-fmd-clk-gpio", 0);
      v32 = pwr_data;
      *(_DWORD *)(pwr_data + 20) = v30;
      if ( v30 < 0 )
      {
        printk(&unk_118AD, v31);
        v32 = pwr_data;
      }
      if ( (of_property_read_variable_u32_array(v22, "mpm_wake_set_gpios", v32 + 36, 1, 0) & 0x80000000) != 0 )
      {
        printk(&unk_12880, v33);
        if ( v23 )
          goto LABEL_46;
      }
      else if ( v23 )
      {
LABEL_46:
        v34 = pinctrl_lookup_state(v23, "sw_ctrl");
        v35 = v34;
        if ( v34 && v34 < 0xFFFFFFFFFFFFF001LL )
        {
          v36 = pinctrl_select_state(v23, v34);
          if ( !v36 )
          {
LABEL_49:
            v37 = pinctrl_lookup_state(v23, "bt_en");
            v38 = v37;
            if ( !v37 || v37 >= 0xFFFFFFFFFFFFF001LL )
            {
              if ( *(_BYTE *)(pwr_data + 176) != 1 )
              {
                printk(&unk_12987, (unsigned int)v37);
                if ( !v38 )
                  goto LABEL_57;
                goto LABEL_54;
              }
              v38 = pinctrl_lookup_state(v23, "bt_uwb_en");
            }
            if ( !v38 )
              goto LABEL_57;
LABEL_54:
            if ( v38 <= 0xFFFFFFFFFFFFF000LL )
            {
              v39 = pinctrl_select_state(v23, v38);
              if ( v39 )
                printk(&unk_1169A, v39);
            }
LABEL_57:
            v40 = of_get_named_gpio(v22, "qcom,bt-debug-gpio", 0);
            *(_DWORD *)(pwr_data + 24) = v40;
            if ( v40 < 0 )
              printk(&unk_121DC, v41);
            v42 = of_get_named_gpio(v22, "qcom,xo-clk-gpio", 0);
            v44 = pwr_data;
            *(_DWORD *)(pwr_data + 40) = v42;
            if ( v42 < 0 )
            {
              printk(&unk_12B61, v43);
              v44 = pwr_data;
            }
            v45 = *(_QWORD *)(a1 + 760);
            *(_QWORD *)(v44 + 88) = 0;
            memset(v51, 0, 80);
            if ( (unsigned int)_of_parse_phandle_with_args(v45, "clocks", 0, 0, 0, v51) || !v51[0] )
            {
              v49 = &unk_12CB6;
            }
            else
            {
              v46 = devm_kmalloc(a1 + 16, 24, 3520);
              if ( !v46 )
              {
LABEL_67:
                result = 0;
                *(_QWORD *)(pwr_data + 96) = &power_regulators;
                goto LABEL_68;
              }
              v47 = (_QWORD *)v46;
              *(_QWORD *)(v46 + 8) = devm_kmalloc(a1 + 16, 20, 3520);
              if ( (of_property_read_string_helper(v45, "clock-names", v47 + 1, 1, 0) & 0x80000000) == 0 )
              {
                v48 = devm_clk_get(a1 + 16, v47[1]);
                *v47 = v48;
                if ( v48 >= 0xFFFFFFFFFFFFF001LL )
                {
                  printk(&unk_116C4, "bt_dt_parse_clk_info");
                  *v47 = 0;
                }
                else
                {
                  *(_QWORD *)(v44 + 88) = v47;
                }
                goto LABEL_67;
              }
              v49 = &unk_1335A;
            }
            printk(v49, "bt_dt_parse_clk_info");
            goto LABEL_67;
          }
          v35 = v36;
          v50 = &unk_12E4F;
        }
        else
        {
          v50 = &unk_13331;
        }
        printk(v50, v35);
        goto LABEL_49;
      }
      printk(&unk_11C78, "get_gpio_dt_pinfo");
      goto LABEL_57;
    }
    goto LABEL_18;
  }
  *(_QWORD *)(v9 + 64) = *(_QWORD *)(match_data + 48);
  *(_QWORD *)(v9 + 80) = *(_QWORD *)(match_data + 64);
  *(_DWORD *)(v9 + 140) = *(_DWORD *)(match_data + 56);
  LODWORD(v13) = *(_DWORD *)(match_data + 72);
  *(_DWORD *)(v9 + 144) = v13;
  if ( v12 > 0 )
  {
LABEL_18:
    v14 = 0;
    v15 = 0;
    while ( 1 )
    {
      result = dt_parse_vreg_info(a1 + 16, *(_QWORD *)(v9 + 304), *(_QWORD *)(v9 + 56) + v14);
      if ( (_DWORD)result )
        goto LABEL_33;
      v9 = pwr_data;
      ++v15;
      v14 += 48;
      if ( v15 >= *(int *)(pwr_data + 136) )
      {
        if ( (*(_BYTE *)(pwr_data + 176) & 1) == 0 )
          goto LABEL_70;
        LODWORD(v13) = *(_DWORD *)(pwr_data + 144);
        if ( (int)v13 < 1 )
          goto LABEL_28;
        goto LABEL_23;
      }
    }
  }
  if ( (int)v13 >= 1 )
  {
LABEL_23:
    v16 = 0;
    v17 = 0;
    v18 = (_DWORD *)(v9 + 144);
    while ( 1 )
    {
      v19 = *(_QWORD *)(v9 + 80);
      if ( !strcmp(*(const char **)(v19 + v16 + 8), "qcom,bt-vdd-wlan-aon") )
      {
        *(_QWORD *)(v9 + 72) = v19 + v16;
        *v18 = v13 - 1;
        printk(&unk_12047, "get_power_dt_pinfo");
        v19 = *(_QWORD *)(pwr_data + 80);
      }
      result = dt_parse_vreg_info(a1 + 16, 0, v19 + v16);
      if ( (_DWORD)result )
        break;
      v9 = pwr_data;
      ++v17;
      v16 += 48;
      v18 = (_DWORD *)(pwr_data + 144);
      v13 = *(int *)(pwr_data + 144);
      if ( v17 >= v13 )
        goto LABEL_28;
    }
  }
  else
  {
LABEL_28:
    if ( *(int *)(v9 + 140) < 1 )
    {
LABEL_32:
      printk(&unk_13703, "get_power_dt_pinfo");
      goto LABEL_34;
    }
    v20 = 0;
    v21 = 0;
    while ( 1 )
    {
      result = dt_parse_vreg_info(a1 + 16, *(_QWORD *)(v9 + 312), *(_QWORD *)(v9 + 64) + v20);
      if ( (_DWORD)result )
        break;
      v9 = pwr_data;
      ++v21;
      v20 += 48;
      if ( v21 >= *(int *)(pwr_data + 140) )
        goto LABEL_32;
    }
  }
LABEL_33:
  if ( (result & 0x80000000) == 0 )
    goto LABEL_34;
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return result;
}
