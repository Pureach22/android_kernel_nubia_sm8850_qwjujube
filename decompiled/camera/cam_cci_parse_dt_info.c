__int64 __fastcall cam_cci_parse_dt_info(__int64 a1, __int64 a2)
{
  unsigned int dt_properties; // w0
  int v5; // w21
  unsigned int v6; // w0
  unsigned int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x26
  __int64 v10; // x27
  __int64 v11; // x22
  __int64 v12; // x23
  __int64 v13; // x20
  __int64 v14; // x28
  const char *v15; // x1
  __int64 node_by_name; // x21
  int v17; // w0
  int v18; // w24
  int v19; // w0
  int v20; // w0
  int v21; // w0
  int v22; // w0
  int v23; // w0
  int v24; // w0
  int v25; // w0
  int v26; // w0
  int v27; // w0
  char v28; // w8
  int v29; // w0
  int v30; // w8
  int v31; // w24
  int v32; // w24
  int v33; // w24
  int v34; // w24
  int v35; // w24
  int v36; // w24
  int v37; // w24
  int v38; // w24
  int v39; // w24
  __int64 v40; // x8
  __int64 v41; // x9
  __int64 v42; // x6
  const char *v43; // x5
  __int64 v44; // x4
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 result; // x0
  int v48; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v49; // [xsp+8h] [xbp-18h] BYREF
  __int64 v50; // [xsp+10h] [xbp-10h]
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  v50 = 0;
  dt_properties = cam_soc_util_get_dt_properties(a2 + 384);
  if ( (dt_properties & 0x80000000) != 0 )
  {
    v42 = dt_properties;
    v43 = "Parsing DT data failed:%d";
    v44 = 414;
LABEL_80:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_parse_dt_info",
      v44,
      v43,
      v42);
    result = 4294967274LL;
    goto LABEL_81;
  }
  v5 = *(_DWORD *)(a2 + 488);
  *(_BYTE *)(a2 + 3964) = 0;
  if ( v5 )
  {
    v49 = a2;
    if ( v5 != 1 )
    {
      v50 = a2;
      if ( v5 != 2 )
        goto LABEL_82;
    }
  }
  *(_DWORD *)(a2 + 488) = 0;
  v6 = cam_soc_util_request_platform_resource(a2 + 384, (__int64)cam_cci_irq, &v49);
  if ( (v6 & 0x80000000) != 0 )
  {
    v42 = v6;
    v43 = "requesting platform resources failed:%d";
    v44 = 431;
    goto LABEL_80;
  }
  *(_DWORD *)(a2 + 488) = v5;
  if ( v5 )
  {
    v7 = devm_request_threaded_irq(
           a1 + 16,
           *(unsigned int *)(a2 + 464),
           cam_cci_irq,
           &cam_cci_threaded_irq,
           1,
           *(_QWORD *)(a2 + 424),
           v49);
    if ( (v7 & 0x80000000) != 0 )
    {
LABEL_79:
      v42 = v7;
      v43 = "Failed to reserve IRQ: %d";
      v44 = 444;
      goto LABEL_80;
    }
    disable_irq(*(unsigned int *)(a2 + 464));
    if ( *(_DWORD *)(a2 + 488) >= 2u )
    {
      v7 = devm_request_threaded_irq(
             a1 + 16,
             *(unsigned int *)(a2 + 468),
             cam_cci_irq,
             &cam_cci_threaded_irq,
             1,
             *(_QWORD *)(a2 + 432),
             v50);
      if ( (v7 & 0x80000000) == 0 )
      {
        disable_irq(*(unsigned int *)(a2 + 468));
        if ( *(_DWORD *)(a2 + 488) <= 2u )
          goto LABEL_11;
LABEL_82:
        __break(0x5512u);
        JUMPOUT(0x26A664);
      }
      goto LABEL_79;
    }
  }
LABEL_11:
  *(_QWORD *)(a2 + 5312) = a1;
  *(_DWORD *)(a2 + 4040) = 0;
  *(_WORD *)(a2 + 4448) = 0;
  *(_BYTE *)(a2 + 4450) = 0;
  _mutex_init(a2 + 4056, "&new_cci_dev->cci_master_info[i].mutex", &cam_cci_init_cci_params___key);
  *(_QWORD *)(a2 + 4384) = a2 + 4384;
  *(_QWORD *)(a2 + 4392) = a2 + 4384;
  *(_QWORD *)(a2 + 4376) = 0x100000000LL;
  _mutex_init(a2 + 4400, "&new_cci_dev->cci_master_info[i].freq_cnt_lock", &cam_cci_init_cci_params___key_28);
  *(_DWORD *)(a2 + 4104) = 0;
  _init_swait_queue_head(a2 + 4112, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 4168) = 0;
  _init_swait_queue_head(a2 + 4176, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 4136) = 0;
  _init_swait_queue_head(a2 + 4144, "&x->wait", &init_completion___key_18);
  _mutex_init(a2 + 4200, "&new_cci_dev->cci_master_info[i].mutex_q[j]", &cam_cci_init_cci_params___key_30);
  *(_DWORD *)(a2 + 4296) = 0;
  _init_swait_queue_head(a2 + 4304, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 4456) = 0;
  _init_swait_queue_head(a2 + 4464, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 4368) = 0;
  _mutex_init(a2 + 4248, "&new_cci_dev->cci_master_info[i].mutex_q[j]", &cam_cci_init_cci_params___key_30);
  *(_DWORD *)(a2 + 4328) = 0;
  _init_swait_queue_head(a2 + 4336, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 4488) = 0;
  _init_swait_queue_head(a2 + 4496, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 4372) = 0;
  *(_DWORD *)(a2 + 4584) = 0;
  *(_WORD *)(a2 + 4992) = 0;
  *(_BYTE *)(a2 + 4994) = 0;
  _mutex_init(a2 + 4600, "&new_cci_dev->cci_master_info[i].mutex", &cam_cci_init_cci_params___key);
  *(_QWORD *)(a2 + 4920) = 0x100000000LL;
  *(_QWORD *)(a2 + 4928) = a2 + 4928;
  *(_QWORD *)(a2 + 4936) = a2 + 4928;
  _mutex_init(a2 + 4944, "&new_cci_dev->cci_master_info[i].freq_cnt_lock", &cam_cci_init_cci_params___key_28);
  *(_DWORD *)(a2 + 4648) = 0;
  _init_swait_queue_head(a2 + 4656, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 4712) = 0;
  _init_swait_queue_head(a2 + 4720, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 4680) = 0;
  _init_swait_queue_head(a2 + 4688, "&x->wait", &init_completion___key_18);
  _mutex_init(a2 + 4744, "&new_cci_dev->cci_master_info[i].mutex_q[j]", &cam_cci_init_cci_params___key_30);
  *(_DWORD *)(a2 + 4840) = 0;
  _init_swait_queue_head(a2 + 4848, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 5000) = 0;
  _init_swait_queue_head(a2 + 5008, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 4912) = 0;
  _mutex_init(a2 + 4792, "&new_cci_dev->cci_master_info[i].mutex_q[j]", &cam_cci_init_cci_params___key_30);
  *(_DWORD *)(a2 + 4872) = 0;
  _init_swait_queue_head(a2 + 4880, "&x->wait", &init_completion___key_18);
  *(_DWORD *)(a2 + 5032) = 0;
  _init_swait_queue_head(a2 + 5040, "&x->wait", &init_completion___key_18);
  v8 = *(_QWORD *)(a2 + 5312);
  *(_DWORD *)(a2 + 4916) = 0;
  v9 = 0;
  *(_DWORD *)(a2 + 5824) = 0;
  v10 = 0;
  v11 = *(_QWORD *)(v8 + 760);
  v48 = 0;
  v12 = a2 + 5155;
  v13 = a2 + 5154;
  v14 = a2 + 5156;
  do
  {
    v15 = "qcom,i2c_custom_mode";
    if ( (v10 & 0xFC) == 0 )
      v15 = off_454518[v10];
    node_by_name = of_find_node_by_name(v11, v15);
    v17 = of_property_read_variable_u32_array(node_by_name, "hw-thigh", &v48, 1, 0);
    v18 = v17;
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        326,
        "hw-thigh %d, rc %d",
        v48,
        v17 & (v17 >> 31));
      if ( v18 < 0 )
        goto LABEL_67;
    }
    else if ( v17 < 0 )
    {
      goto LABEL_67;
    }
    *(_WORD *)(a2 + v9 + 5140) = v48;
    v19 = of_property_read_variable_u32_array(node_by_name, "hw-tlow", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v31 = v19;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        332,
        "hw-tlow %d, rc %d",
        v48,
        v19 & (v19 >> 31));
      if ( v31 < 0 )
        goto LABEL_67;
    }
    else if ( v19 < 0 )
    {
      goto LABEL_67;
    }
    *(_WORD *)(a2 + v9 + 5142) = v48;
    v20 = of_property_read_variable_u32_array(node_by_name, "hw-tsu-sto", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v32 = v20;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        339,
        "hw-tsu-sto %d, rc %d",
        v48,
        v20 & (v20 >> 31));
      if ( v32 < 0 )
        goto LABEL_67;
    }
    else if ( v20 < 0 )
    {
      goto LABEL_67;
    }
    *(_WORD *)(a2 + v9 + 5144) = v48;
    v21 = of_property_read_variable_u32_array(node_by_name, "hw-tsu-sta", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v33 = v21;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        346,
        "hw-tsu-sta %d, rc %d",
        v48,
        v21 & (v21 >> 31));
      if ( v33 < 0 )
        goto LABEL_67;
    }
    else if ( v21 < 0 )
    {
      goto LABEL_67;
    }
    *(_WORD *)(a2 + v9 + 5146) = v48;
    v22 = of_property_read_variable_u32_array(node_by_name, "hw-thd-dat", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v34 = v22;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        353,
        "hw-thd-dat %d, rc %d",
        v48,
        v22 & (v22 >> 31));
      if ( v34 < 0 )
        goto LABEL_67;
    }
    else if ( v22 < 0 )
    {
      goto LABEL_67;
    }
    *(_WORD *)(a2 + v9 + 5148) = v48;
    v23 = of_property_read_variable_u32_array(node_by_name, "hw-thd-sta", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v35 = v23;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        360,
        "hw-thd-sta %d, rc %d",
        v48,
        v23 & (v23 >> 31));
      if ( v35 < 0 )
        goto LABEL_67;
    }
    else if ( v23 < 0 )
    {
      goto LABEL_67;
    }
    *(_WORD *)(a2 + v9 + 5150) = v48;
    v24 = of_property_read_variable_u32_array(node_by_name, "hw-tbuf", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v36 = v24;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        367,
        "hw-tbuf %d, rc %d",
        v48,
        v24 & (v24 >> 31));
      if ( v36 < 0 )
        goto LABEL_67;
    }
    else if ( v24 < 0 )
    {
      goto LABEL_67;
    }
    *(_WORD *)(a2 + v9 + 5152) = v48;
    v25 = of_property_read_variable_u32_array(node_by_name, "hw-scl-stretch-en", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v37 = v25;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        374,
        "hw-scl-stretch-en %d, rc %d",
        v48,
        v25 & (v25 >> 31));
      if ( v37 < 0 )
        goto LABEL_67;
    }
    else if ( v25 < 0 )
    {
      goto LABEL_67;
    }
    *(_BYTE *)(v13 + v9) = v48;
    v26 = of_property_read_variable_u32_array(node_by_name, "hw-trdhld", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v38 = v26;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        381,
        "hw-trdhld %d, rc %d",
        v48,
        v26 & (v26 >> 31));
      if ( v38 < 0 )
        goto LABEL_67;
    }
    else if ( v26 < 0 )
    {
      goto LABEL_67;
    }
    *(_BYTE *)(v12 + v9) = v48;
    v27 = of_property_read_variable_u32_array(node_by_name, "hw-tsp", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v39 = v27;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        387,
        "hw-tsp %d, rc %d",
        v48,
        v27 & (v27 >> 31));
      if ( v39 < 0 )
      {
LABEL_67:
        v40 = a2 + v9;
        *(_BYTE *)(v13 + v9) = 0;
        *(_QWORD *)(v40 + 5140) = 0xE700CC00AE00C9LL;
        *(_DWORD *)(v40 + 5148) = 10616854;
        *(_WORD *)(v40 + 5152) = 227;
        *(_BYTE *)(v12 + v9) = 6;
        v30 = 37500000;
        *(_BYTE *)(v14 + v9) = 3;
        goto LABEL_68;
      }
    }
    else if ( v27 < 0 )
    {
      goto LABEL_67;
    }
    v28 = v48;
    v48 = 0;
    *(_BYTE *)(v14 + v9) = v28;
    v29 = of_property_read_variable_u32_array(node_by_name, "cci-clk-src", &v48, 1, 0);
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init_clk_params",
        394,
        "cci-clk-src %d, rc %d",
        v48,
        v29 & (v29 >> 31));
    v30 = v48;
LABEL_68:
    v41 = a2 + v9;
    v9 += 24;
    ++v10;
    *(_DWORD *)(v41 + 5160) = v30;
  }
  while ( v9 != 96 );
  v45 = alloc_workqueue("%s", byte_6000A);
  *(_QWORD *)(a2 + 5280) = v45;
  if ( !v45 )
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_parse_dt_info",
      458);
  v46 = alloc_workqueue("%s", byte_6000A);
  *(_QWORD *)(a2 + 5288) = v46;
  if ( !v46 )
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_parse_dt_info",
      458);
  result = 0;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_parse_dt_info",
      460,
      "Exit");
    result = 0;
  }
LABEL_81:
  _ReadStatusReg(SP_EL0);
  return result;
}
