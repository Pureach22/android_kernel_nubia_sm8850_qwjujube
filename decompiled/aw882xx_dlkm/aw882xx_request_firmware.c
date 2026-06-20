__int64 __fastcall aw882xx_request_firmware(__int64 a1)
{
  __int64 **v1; // x23
  _BYTE *v3; // x22
  __int64 v4; // x2
  int v5; // w0
  __int64 *v6; // x8
  __int64 v7; // x1
  _DWORD *v8; // x20
  unsigned __int64 v9; // x21
  size_t *v10; // x0
  __int64 v11; // x21
  __int64 v12; // x24
  __int64 *v13; // x23
  __int64 v14; // x0
  __int64 v15; // x20
  char *v16; // x0
  char *v17; // x21
  __int64 v18; // x8
  char *v19; // x0
  char *v20; // x21
  __int64 v21; // x8
  char *v22; // x0
  char *v23; // x21
  __int64 v24; // x8
  char *v25; // x0
  char *v26; // x21
  __int64 v27; // x8
  char *v28; // x0
  char *v29; // x21
  __int64 v30; // x10
  char *v31; // x0
  char *v32; // x21
  __int64 v33; // x10
  char *v34; // x0
  char *v35; // x21
  __int64 v36; // x9
  char *v37; // x0
  char *v38; // x21
  __int64 v39; // x9
  char *v40; // x0
  char *v41; // x21
  __int64 v42; // x9
  char *v43; // x0
  char *v44; // x21
  void (__fastcall *v45)(__int64, __int64, __int64); // x8
  __int64 v46; // x0
  void *v47; // x0
  __int64 result; // x0
  _BYTE *v49; // x20
  int v50; // w8
  __int64 v51; // x1
  __int64 v52; // x1
  __int64 v53; // x1
  __int64 v54; // x1
  _QWORD *v55; // x8
  unsigned __int64 StatusReg; // x25
  __int64 v57; // x26
  __int64 v58; // x1
  _QWORD v59[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = (__int64 **)(a1 - 360);
  v3 = (_BYTE *)(a1 - 388);
  v59[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 360);
  v59[0] = 0;
  *(_BYTE *)(a1 - 388) = 0;
  v5 = request_firmware(v59, "aw882xx_acf.bin", v4);
  v6 = *v1;
  v7 = (*v1)[14];
  if ( v5 || !v59[0] )
  {
    if ( !v7 )
      v7 = *v6;
    result = printk(&unk_28477, v7, "aw882xx_request_firmware");
    v49 = (_BYTE *)(a1 - 387);
    v50 = *(unsigned __int8 *)(a1 - 387);
    if ( v50 == 5 )
    {
      *v49 = 0;
    }
    else
    {
      *v49 = v50 + 1;
      msleep(1000);
      v51 = (*v1)[14];
      if ( !v51 )
        v51 = **v1;
      printk(&unk_27AAB, v51, "aw882xx_request_firmware");
      result = aw882xx_request_firmware(a1);
    }
    goto LABEL_33;
  }
  if ( !v7 )
    v7 = *v6;
  printk(&unk_27AD2, v7, "aw882xx_request_firmware");
  mutex_lock(&g_aw882xx_lock);
  v8 = (_DWORD *)g_awinic_cfg;
  if ( g_awinic_cfg )
  {
    release_firmware(v59[0]);
    v52 = (*v1)[14];
    if ( !v52 )
      v52 = **v1;
    printk(&unk_23E68, v52, "aw882xx_request_firmware");
LABEL_11:
    mutex_unlock(&g_aw882xx_lock);
    mutex_lock(a1 + 104);
    v12 = a1 - 328;
    if ( (aw882xx_dev_init(*(_QWORD *)(a1 - 328), v8) & 0x80000000) != 0 )
    {
      v53 = (*v1)[14];
      if ( !v53 )
        v53 = **v1;
      printk(&unk_27B02, v53, "aw882xx_request_firmware");
    }
    else
    {
      v13 = (__int64 *)(a1 - 384);
      v14 = devm_kmalloc(*(_QWORD *)(*(_QWORD *)(a1 - 384) + 24LL), 800, 3520);
      if ( v14 )
      {
        v15 = v14;
        v16 = (char *)devm_kmalloc(*(_QWORD *)(*v13 + 24), 50, 3520);
        if ( v16 )
        {
          v17 = v16;
          snprintf(v16, 0x32u, "aw_dev_%d_prof", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
          *(_QWORD *)(v15 + 16) = v17;
          *(_QWORD *)(v15 + 40) = aw882xx_profile_info;
          *(_QWORD *)(v15 + 48) = aw882xx_profile_get;
          v18 = *v13;
          *(_DWORD *)v15 = 2;
          *(_QWORD *)(v15 + 56) = aw882xx_profile_set;
          v19 = (char *)devm_kmalloc(*(_QWORD *)(v18 + 24), 50, 3520);
          if ( v19 )
          {
            v20 = v19;
            snprintf(v19, 0x32u, "aw_dev_%d_switch", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
            *(_QWORD *)(v15 + 96) = v20;
            *(_QWORD *)(v15 + 120) = aw882xx_switch_info;
            *(_QWORD *)(v15 + 128) = aw882xx_switch_get;
            v21 = *v13;
            *(_DWORD *)(v15 + 80) = 2;
            *(_QWORD *)(v15 + 136) = aw882xx_switch_set;
            v22 = (char *)devm_kmalloc(*(_QWORD *)(v21 + 24), 50, 3520);
            if ( v22 )
            {
              v23 = v22;
              snprintf(v22, 0x32u, "aw_dev_%d_monitor", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
              *(_QWORD *)(v15 + 176) = v23;
              *(_QWORD *)(v15 + 200) = aw882xx_monitor_info;
              *(_QWORD *)(v15 + 208) = aw882xx_monitor_get;
              v24 = *v13;
              *(_DWORD *)(v15 + 160) = 2;
              *(_QWORD *)(v15 + 216) = aw882xx_monitor_set;
              v25 = (char *)devm_kmalloc(*(_QWORD *)(v24 + 24), 50, 3520);
              if ( v25 )
              {
                v26 = v25;
                snprintf(v25, 0x32u, "aw_dev_%d_volume", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
                *(_QWORD *)(v15 + 256) = v26;
                *(_QWORD *)(v15 + 280) = aw882xx_volume_info;
                *(_QWORD *)(v15 + 288) = aw882xx_volume_get;
                v27 = *v13;
                *(_DWORD *)(v15 + 240) = 2;
                *(_QWORD *)(v15 + 296) = aw882xx_volume_put;
                v28 = (char *)devm_kmalloc(*(_QWORD *)(v27 + 24), 50, 3520);
                if ( v28 )
                {
                  v29 = v28;
                  snprintf(v28, 0x32u, "aw_dev_%d_hal_mon_work", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
                  *(_DWORD *)(v15 + 348) = 1;
                  v30 = *v13;
                  *(_QWORD *)(v15 + 336) = v29;
                  *(_DWORD *)(v15 + 320) = 2;
                  *(_QWORD *)(v15 + 360) = aw882xx_hal_monitor_work_info;
                  *(_QWORD *)(v15 + 368) = aw882xx_hal_monitor_work_get;
                  v31 = (char *)devm_kmalloc(*(_QWORD *)(v30 + 24), 50, 3520);
                  if ( v31 )
                  {
                    v32 = v31;
                    snprintf(v31, 0x32u, "aw_dev_%d_offset", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
                    v33 = *v13;
                    *(_QWORD *)(v15 + 416) = v32;
                    *(_DWORD *)(v15 + 400) = 2;
                    *(_QWORD *)(v15 + 440) = aw882xx_voltage_offset_info;
                    *(_QWORD *)(v15 + 448) = aw882xx_voltage_offset_get;
                    v34 = (char *)devm_kmalloc(*(_QWORD *)(v33 + 24), 50, 3520);
                    if ( v34 )
                    {
                      v35 = v34;
                      snprintf(v34, 0x32u, "aw_dev_%d_iv_output", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
                      v36 = *v13;
                      *(_QWORD *)(v15 + 520) = aw882xx_iv_output_info;
                      *(_QWORD *)(v15 + 536) = aw882xx_iv_output_set;
                      *(_QWORD *)(v15 + 496) = v35;
                      *(_DWORD *)(v15 + 480) = 2;
                      *(_QWORD *)(v15 + 528) = aw882xx_iv_output_get;
                      v37 = (char *)devm_kmalloc(*(_QWORD *)(v36 + 24), 50, 3520);
                      if ( v37 )
                      {
                        v38 = v37;
                        snprintf(v37, 0x32u, "aw_dev_%d_algo_volume", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
                        v39 = *v13;
                        *(_QWORD *)(v15 + 600) = aw882xx_algo_volume_info;
                        *(_QWORD *)(v15 + 616) = aw882xx_algo_volume_put;
                        *(_QWORD *)(v15 + 576) = v38;
                        *(_DWORD *)(v15 + 560) = 2;
                        *(_QWORD *)(v15 + 608) = aw882xx_algo_volume_get;
                        v40 = (char *)devm_kmalloc(*(_QWORD *)(v39 + 24), 50, 3520);
                        if ( v40 )
                        {
                          v41 = v40;
                          snprintf(v40, 0x32u, "aw_dev_%d_ramp_switch", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
                          v42 = *v13;
                          *(_QWORD *)(v15 + 680) = aw882xx_ramp_switch_info;
                          *(_QWORD *)(v15 + 688) = aw882xx_ramp_switch_get;
                          *(_QWORD *)(v15 + 656) = v41;
                          *(_DWORD *)(v15 + 640) = 2;
                          *(_QWORD *)(v15 + 696) = aw882xx_ramp_switch_set;
                          v43 = (char *)devm_kmalloc(*(_QWORD *)(v42 + 24), 50, 3520);
                          if ( v43 )
                          {
                            v44 = v43;
                            snprintf(v43, 0x32u, "aw_dev_%d_ramp_params", *(_DWORD *)(*(_QWORD *)v12 + 52LL));
                            *(_QWORD *)(v15 + 760) = aw882xx_ramp_params_info;
                            v45 = (void (__fastcall *)(__int64, __int64, __int64))off_358;
                            v46 = *v13;
                            *(_QWORD *)(v15 + 776) = aw882xx_ramp_params_put;
                            *(_QWORD *)(v15 + 736) = v44;
                            *(_DWORD *)(v15 + 720) = 2;
                            *(_QWORD *)(v15 + 768) = aw882xx_ramp_params_get;
                            if ( *((_DWORD *)v45 - 1) != -467765670 )
                              __break(0x8228u);
                            v45(v46, v15, 10);
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
      *v3 = 1;
      *(_BYTE *)(a1 - 387) = 0;
    }
    v47 = (void *)(a1 + 104);
    goto LABEL_28;
  }
  v9 = *(_QWORD *)v59[0] + 4LL;
  v8 = (_DWORD *)vzalloc_noprof(v9);
  v10 = (size_t *)v59[0];
  if ( !v8 )
  {
LABEL_48:
    release_firmware(v10);
    v58 = (*v1)[14];
    if ( !v58 )
      v58 = **v1;
    printk(&unk_2365A, v58, "aw882xx_request_firmware");
    goto LABEL_51;
  }
  while ( 1 )
  {
    if ( v9 < 4 )
    {
      __break(1u);
      goto LABEL_47;
    }
    *v8 = *v10;
    if ( v9 - 4 >= *v10 )
      break;
LABEL_47:
    _fortify_panic(17);
    v55 = (_QWORD *)v59[0];
    StatusReg = _ReadStatusReg(SP_EL0);
    v57 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &aw882xx_request_firmware__alloc_tag;
    v9 = *v55 + 4LL;
    v8 = (_DWORD *)vzalloc_noprof(v9);
    *(_QWORD *)(StatusReg + 80) = v57;
    v10 = (size_t *)v59[0];
    if ( !v8 )
      goto LABEL_48;
  }
  v11 = v59[0];
  memcpy(v8 + 1, *(const void **)((char *)&qword_8 + v59[0]), *v10);
  release_firmware(v11);
  if ( !(unsigned int)aw882xx_dev_parse_check_acf(v8) )
  {
    g_awinic_cfg = (__int64)v8;
    goto LABEL_11;
  }
  v54 = (*v1)[14];
  if ( !v54 )
    v54 = **v1;
  printk(&unk_25C89, v54, "aw882xx_request_firmware");
  vfree(v8);
LABEL_51:
  v47 = &g_aw882xx_lock;
LABEL_28:
  result = mutex_unlock(v47);
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
