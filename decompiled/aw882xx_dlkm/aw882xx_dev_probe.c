__int64 __fastcall aw882xx_dev_probe(__int64 a1)
{
  _UNKNOWN **v1; // x20
  __int64 v3; // x8
  __int64 *v4; // x8
  __int64 v5; // x1
  __int64 *v6; // x8
  __int64 v7; // x1
  __int64 v8; // x0
  int (__fastcall *v9)(_QWORD); // x8
  _UNKNOWN **v10; // x8
  __int64 *v11; // x8
  __int64 v12; // x1
  unsigned int v13; // w3
  __int64 v14; // x0
  __int64 *v15; // x8
  __int64 v16; // x1
  __int64 *v17; // x8
  __int64 v18; // x1
  __int64 result; // x0
  void *v20; // x2
  __int64 *v21; // x8
  __int64 v22; // x1
  __int64 *v23; // x8
  __int64 v24; // x1
  __int64 *v25; // x8
  __int64 v26; // x1
  unsigned int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v1 = (_UNKNOWN **)(a1 + 1224);
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 1224) = a1 + 1224;
  *(_QWORD *)(a1 + 1232) = a1 + 1224;
  v3 = *(_QWORD *)(a1 + 112);
  v27 = 0;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v3 + 744), "sound-channel", &v27, 1, 0) & 0x80000000) != 0 )
  {
    v4 = *(__int64 **)(a1 + 112);
    v27 = 0;
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    printk(&unk_270E0, v5, "aw_dev_parse_sound_channel_dt");
  }
  v6 = *(__int64 **)(a1 + 112);
  v7 = v6[14];
  if ( !v7 )
    v7 = *v6;
  v8 = printk(&unk_257FA, v7, "aw_dev_parse_sound_channel_dt");
  if ( v27 >= 8 )
    v27 = 0;
  v9 = *(int (__fastcall **)(_QWORD))(a1 + 1144);
  if ( *((_DWORD *)v9 - 1) != 1874538549 )
    __break(0x8228u);
  if ( v9(v8) <= 0 )
  {
    v13 = v27;
LABEL_17:
    *(_DWORD *)(a1 + 52) = v13;
    aw882xx_dsp_parse_topo_id_dt(a1);
    aw882xx_dsp_parse_port_id_dt(a1);
    v14 = *(_QWORD *)(*(_QWORD *)(a1 + 112) + 744LL);
    v27 = 0;
    if ( (of_property_read_variable_u32_array(v14, "fade-flag", &v27, 1, 0) & 0x80000000) != 0 )
    {
      v15 = *(__int64 **)(a1 + 112);
      v16 = v15[14];
      if ( !v16 )
        v16 = *v15;
      printk(&unk_24BFF, v16, "aw_dev_parse_fade_flag_dt");
    }
    v17 = *(__int64 **)(a1 + 112);
    *(_DWORD *)(a1 + 24) = v27;
    v18 = v17[14];
    if ( !v18 )
      v18 = *v17;
    printk(&unk_2294B, v18, "aw_dev_parse_fade_flag_dt");
    if ( !*(_DWORD *)(a1 + 52) && (unsigned int)misc_register(&misc_algo_auth) )
    {
      v25 = *(__int64 **)(a1 + 112);
      v26 = v25[14];
      if ( !v26 )
        v26 = *v25;
      printk(&unk_285D0, v26, "aw_algo_auth_misc_init");
    }
    result = aw882xx_cali_init(a1 + 648);
    if ( !(_DWORD)result )
    {
      aw882xx_monitor_init(a1 + 672);
      result = aw882xx_spin_init(a1 + 936);
      if ( !(_DWORD)result )
      {
        mutex_lock(&g_dev_lock);
        v20 = g_dev_list;
        if ( g_dev_list == (_UNKNOWN *)v1
          || v1 == &g_dev_list
          || *(_UNKNOWN ***)((char *)&qword_8 + (_QWORD)g_dev_list) != &g_dev_list )
        {
          _list_add_valid_or_report(v1, &g_dev_list);
        }
        else
        {
          *(__int64 *)((char *)&qword_8 + (_QWORD)g_dev_list) = (__int64)v1;
          *(_QWORD *)(a1 + 1224) = v20;
          *(_QWORD *)(a1 + 1232) = &g_dev_list;
          g_dev_list = v1;
        }
        mutex_unlock(&g_dev_lock);
        result = 0;
      }
    }
  }
  else
  {
    v10 = (_UNKNOWN **)g_dev_list;
    if ( g_dev_list == (_UNKNOWN *)&g_dev_list )
    {
      v11 = *(__int64 **)(a1 + 112);
      v12 = v11[14];
      if ( !v12 )
        v12 = *v11;
      printk(&unk_26C84, v12, "aw_dev_parse_sound_channel_dt");
    }
    else
    {
      v13 = v27;
      while ( *((_DWORD *)v10 - 293) != v27 )
      {
        v10 = (_UNKNOWN **)*v10;
        if ( v10 == &g_dev_list )
          goto LABEL_17;
      }
      v21 = (__int64 *)*(v10 - 139);
      v22 = v21[14];
      if ( !v22 )
        v22 = *v21;
      printk(&unk_229C2, v22, "aw_dev_parse_sound_channel_dt");
    }
    v23 = *(__int64 **)(a1 + 112);
    v24 = v23[14];
    if ( !v24 )
      v24 = *v23;
    printk(&unk_28298, v24, "aw_dev_parse_dt");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
