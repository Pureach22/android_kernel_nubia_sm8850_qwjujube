__int64 __fastcall zte_disp_common_func(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x9
  const char *v7; // x21
  int v8; // w0
  const char *v9; // x21
  int v10; // w0
  __int64 (__fastcall *v11)(__int64, const char *); // x8
  __int64 v12; // x0
  const char *v13; // x20
  int v14; // w0
  __int64 (__fastcall *v15)(__int64, const char *); // x8
  __int64 v16; // x0
  const char *v17; // x20
  int v18; // w0
  __int64 (__fastcall *v19)(__int64, const char *); // x8
  __int64 v20; // x0
  const char *v21; // x20
  int v22; // w0
  __int64 (__fastcall *v23)(__int64, const char *); // x8
  __int64 v24; // x0
  const char *v25; // x20
  int v26; // w0
  __int64 (__fastcall *v27)(__int64, const char *); // x8
  __int64 v28; // x0
  const char *v29; // x20
  int v30; // w0
  __int64 (__fastcall *v31)(__int64, const char *); // x8
  __int64 v32; // x0
  const char *v33; // x20
  int v34; // w0
  __int64 (__fastcall *v35)(__int64, const char *); // x8
  __int64 v36; // x0
  const char *v37; // x20
  int v38; // w0
  unsigned int (__fastcall *v39)(__int64, const char *, __int64); // x8
  __int64 v40; // x0
  unsigned int (__fastcall *v41)(__int64, const char *, __int64); // x8
  __int64 v42; // x0
  unsigned int (__fastcall *v43)(__int64, const char *, __int64); // x8
  __int64 v44; // x0
  const char *v45; // x20
  int v46; // w0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0

  if ( !a1 )
    return printk(&unk_23DCE0, a2);
  v4 = _kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 240);
  *(_QWORD *)(a1 + 2312) = v4;
  if ( !v4 )
    return printk(&unk_2304AA, "zte_disp_common_func");
  v5 = 0;
  v6 = 0;
  do
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 2312) + v5) = feature_name[v6];
    *(_DWORD *)(*(_QWORD *)(a1 + 2312) + v5 + 8) = 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 2312) + v5 + 13) = 1;
    *(_BYTE *)(*(_QWORD *)(a1 + 2312) + v5 + 12) = 1;
    *(_BYTE *)(*(_QWORD *)(a1 + 2312) + v5 + 14) = 1;
    if ( (int)v6 <= 4 )
    {
      if ( (int)v6 > 2 )
      {
        if ( (_DWORD)v6 != 3 )
          *(_DWORD *)(*(_QWORD *)(a1 + 2312) + v5 + 8) = 1;
LABEL_9:
        *(_BYTE *)(*(_QWORD *)(a1 + 2312) + v5 + 13) = 0;
        goto LABEL_10;
      }
      if ( (_DWORD)v6 == 1 )
        goto LABEL_9;
      if ( (_DWORD)v6 == 2 )
      {
        *(_DWORD *)(*(_QWORD *)(a1 + 2312) + v5 + 8) = 60;
LABEL_21:
        *(_BYTE *)(*(_QWORD *)(a1 + 2312) + v5 + 12) = 0;
      }
    }
    else
    {
      if ( (int)v6 <= 8 )
      {
        if ( (_DWORD)v6 != 5 )
        {
          if ( (_DWORD)v6 != 6 )
            goto LABEL_10;
          *(_DWORD *)(*(_QWORD *)(a1 + 2312) + v5 + 8) = *(_DWORD *)(a1 + 1488);
          goto LABEL_9;
        }
        goto LABEL_21;
      }
      if ( (_DWORD)v6 == 9 )
      {
        *(_BYTE *)(*(_QWORD *)(a1 + 2312) + v5 + 14) = 0;
      }
      else if ( (_DWORD)v6 == 10 || (_DWORD)v6 == 14 )
      {
        goto LABEL_9;
      }
    }
LABEL_10:
    v5 += 16;
    ++v6;
  }
  while ( v5 != 240 );
  load_panel_info(a1);
  v7 = *(const char **)(a1 + 8);
  strcmp(v7, "primary");
  printk(&unk_21F63F, v7);
  v8 = strcmp(*(const char **)(a1 + 8), "primary");
  proc_create_data(node_name[15 * (v8 != 0) + 5], 436, 0, &zte_panel_state_proc_fops, a1);
  v9 = *(const char **)(a1 + 8);
  strcmp(v9, "primary");
  printk(&unk_21F63F, v9);
  v10 = strcmp(*(const char **)(a1 + 8), "primary");
  proc_create_data(node_name[15 * (v10 != 0) + 14], 436, 0, &zte_lcd_temp_debug_proc_fops, a1);
  v11 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v12 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v11 - 1) != -834495637 )
    __break(0x8228u);
  if ( (v11(v12, "zte,hbm_enabled") & 1) != 0 )
  {
    v13 = *(const char **)(a1 + 8);
    strcmp(v13, "primary");
    printk(&unk_21F63F, v13);
    v14 = strcmp(*(const char **)(a1 + 8), "primary");
    proc_create_data(node_name[15 * (v14 != 0)], 436, 0, &zte_lcd_hbm_proc_fops, a1);
  }
  v15 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v16 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v15 - 1) != -834495637 )
    __break(0x8228u);
  if ( (v15(v16, "zte,aod_enabled") & 1) != 0 )
  {
    v17 = *(const char **)(a1 + 8);
    strcmp(v17, "primary");
    printk(&unk_21F63F, v17);
    v18 = strcmp(*(const char **)(a1 + 8), "primary");
    proc_create_data(node_name[15 * (v18 != 0) + 4], 436, 0, &zte_lcd_aod_bl_proc_fops, a1);
  }
  v19 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v20 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v19 - 1) != -834495637 )
    __break(0x8228u);
  if ( (v19(v20, "zte,fps_enabled") & 1) != 0 )
  {
    v21 = *(const char **)(a1 + 8);
    strcmp(v21, "primary");
    printk(&unk_21F63F, v21);
    v22 = strcmp(*(const char **)(a1 + 8), "primary");
    proc_create_data(node_name[15 * (v22 != 0) + 2], 436, 0, &zte_lcd_cur_fps_proc_fops, a1);
  }
  v23 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v24 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v23 - 1) != -834495637 )
    __break(0x8228u);
  if ( (v23(v24, "zte,color_space_enabled") & 1) != 0 )
  {
    v25 = *(const char **)(a1 + 8);
    strcmp(v25, "primary");
    printk(&unk_21F63F, v25);
    v26 = strcmp(*(const char **)(a1 + 8), "primary");
    proc_create_data(node_name[15 * (v26 != 0) + 1], 436, 0, &zte_lcd_color_gamut_proc_fops, a1);
  }
  v27 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v28 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v27 - 1) != -834495637 )
    __break(0x8228u);
  if ( (v27(v28, "zte,acl_enabled") & 1) != 0 )
  {
    v29 = *(const char **)(a1 + 8);
    strcmp(v29, "primary");
    printk(&unk_21F63F, v29);
    v30 = strcmp(*(const char **)(a1 + 8), "primary");
    proc_create_data(node_name[15 * (v30 != 0) + 3], 436, 0, &zte_lcd_acl_proc_fops, a1);
  }
  v31 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v32 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v31 - 1) != -834495637 )
    __break(0x8228u);
  if ( (v31(v32, "zte,bl_limit_enabled") & 1) != 0 )
  {
    v33 = *(const char **)(a1 + 8);
    strcmp(v33, "primary");
    printk(&unk_21F63F, v33);
    v34 = strcmp(*(const char **)(a1 + 8), "primary");
    proc_create_data(node_name[15 * (v34 != 0) + 6], 436, 0, &zte_lcd_bl_limit_proc_fops, a1);
  }
  v35 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v36 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v35 - 1) != -834495637 )
    __break(0x8228u);
  if ( (v35(v36, "zte,local_hbm_enabled") & 1) != 0 )
  {
    v37 = *(const char **)(a1 + 8);
    strcmp(v37, "primary");
    printk(&unk_21F63F, v37);
    v38 = strcmp(*(const char **)(a1 + 8), "primary");
    proc_create_data(node_name[15 * (v38 != 0) + 13], 436, 0, &zte_lcd_local_hbm_proc_fops, a1);
  }
  v39 = *(unsigned int (__fastcall **)(__int64, const char *, __int64))(a1 + 1848);
  v40 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v39 - 1) != 309187163 )
    __break(0x8228u);
  if ( v39(v40, "zte,te-high-width", a1 + 2544) )
    *(_DWORD *)(a1 + 2544) = 0;
  v41 = *(unsigned int (__fastcall **)(__int64, const char *, __int64))(a1 + 1848);
  v42 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v41 - 1) != 309187163 )
    __break(0x8228u);
  if ( v41(v42, "zte,dim-delay", a1 + 2444) )
    *(_DWORD *)(a1 + 2444) = 20;
  v43 = *(unsigned int (__fastcall **)(__int64, const char *, __int64))(a1 + 1848);
  v44 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v43 - 1) != 309187163 )
    __break(0x8228u);
  if ( v43(v44, "zte,bl-normalmax-level", a1 + 2548) )
    *(_DWORD *)(a1 + 2548) = 0;
  zte_lcd_reg_debug_func(a1);
  v45 = *(const char **)(a1 + 8);
  strcmp(v45, "primary");
  printk(&unk_21F63F, v45);
  v46 = strcmp(*(const char **)(a1 + 8), "primary");
  proc_create_data(node_name[15 * (v46 != 0) + 10], 436, 0, &zte_lcd_ltm_sensor_bl_proc_fops, a1);
  *(_QWORD *)(a1 + 2328) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 2336) = a1 + 2336;
  *(_QWORD *)(a1 + 2344) = a1 + 2336;
  *(_QWORD *)(a1 + 2352) = dimming_work_handler;
  init_timer_key(a1 + 2360, &delayed_work_timer_fn, 0x200000, 0, 0);
  v47 = alloc_workqueue("%s", (_BYTE *)&loc_60008 + 2);
  *(_QWORD *)(a1 + 2456) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 2432) = v47;
  *(_QWORD *)(a1 + 2464) = a1 + 2464;
  *(_QWORD *)(a1 + 2472) = a1 + 2464;
  *(_QWORD *)(a1 + 2480) = setting_bl_work_handler;
  v48 = alloc_workqueue("%s", (_BYTE *)&loc_60008 + 2);
  *(_QWORD *)(a1 + 2504) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 2488) = v48;
  *(_QWORD *)(a1 + 2512) = a1 + 2512;
  *(_QWORD *)(a1 + 2520) = a1 + 2512;
  *(_QWORD *)(a1 + 2528) = setting_aodbl_work_handler;
  v49 = alloc_workqueue("%s", (_BYTE *)&loc_60008 + 2);
  *(_QWORD *)(a1 + 2560) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 2536) = v49;
  *(_QWORD *)(a1 + 2568) = a1 + 2568;
  *(_QWORD *)(a1 + 2576) = a1 + 2568;
  *(_QWORD *)(a1 + 2584) = setting_nolp_work_handler;
  result = alloc_workqueue("%s", (_BYTE *)&loc_60008 + 2);
  *(_QWORD *)(a1 + 2592) = result;
  return result;
}
