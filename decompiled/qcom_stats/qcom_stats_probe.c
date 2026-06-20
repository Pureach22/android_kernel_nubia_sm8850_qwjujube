__int64 __fastcall qcom_stats_probe(__int64 a1)
{
  __int64 match_data; // x0
  __int64 v3; // x22
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x8
  _QWORD *v6; // x23
  __int64 v7; // x0
  __int64 v8; // x19
  unsigned __int64 v9; // x8
  char v10; // w9
  unsigned __int64 v11; // x11
  int v12; // w10
  __int64 v13; // x12
  __int64 v14; // x0
  int v15; // w0
  unsigned __int64 v16; // x26
  char **v17; // x27
  char *v18; // x12
  char **v19; // x8
  char **v20; // x10
  unsigned __int64 v21; // x25
  const char **v22; // x20
  char *v23; // x19
  const char **v24; // x21
  const char *v25; // x28
  char *v26; // x24
  int v27; // w0
  char *v28; // x10
  char *v29; // x9
  char *v30; // x11
  int v31; // w8
  __int64 v32; // x10
  unsigned int v33; // w21
  unsigned int v34; // w9
  int v35; // w21
  __int64 v36; // x19
  unsigned __int64 v37; // x25
  unsigned __int64 v38; // x22
  unsigned int v39; // w20
  __int64 v40; // x0
  unsigned __int64 v41; // x26
  int v42; // w9
  __int64 v43; // x19
  _QWORD *v44; // x8
  __int64 v45; // x0
  __int64 v46; // x19
  unsigned int *v47; // x22
  unsigned int v48; // w0
  unsigned __int64 v49; // x0
  _QWORD *v50; // x20
  unsigned __int64 v51; // x0
  unsigned __int64 v52; // x0
  __int64 v53; // x0
  unsigned __int64 v54; // x9
  __int64 v55; // x0
  unsigned __int64 v56; // x9
  __int64 v57; // x0
  __int64 v59; // [xsp+0h] [xbp-40h]
  unsigned __int64 v60; // [xsp+8h] [xbp-38h]
  __int64 v61; // [xsp+10h] [xbp-30h]
  __int64 v62; // [xsp+18h] [xbp-28h]
  __int64 v63; // [xsp+18h] [xbp-28h]
  __int64 v64; // [xsp+20h] [xbp-20h]
  __int64 dir; // [xsp+28h] [xbp-18h]
  const char *v66[2]; // [xsp+30h] [xbp-10h] BYREF

  v66[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  match_data = device_get_match_data(a1 + 16);
  if ( match_data )
  {
    v3 = match_data;
    v4 = devm_platform_get_and_ioremap_resource(a1, 0, 0);
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = *(_QWORD *)(v3 + 24);
      if ( !(v5 >> 60) )
      {
        v6 = (_QWORD *)(16 * v5);
        v60 = v4;
        v7 = devm_kmalloc(a1 + 16, 16 * v5, 3520);
        if ( v7 )
        {
          v8 = v7;
          drv = devm_kmalloc(a1 + 16, 256, 3520);
          if ( drv )
          {
            v9 = *(_QWORD *)(v3 + 24);
            if ( v9 )
            {
              v10 = *(_BYTE *)(v3 + 32);
              v11 = 0;
              v12 = 1;
              while ( (v11 & 0x8000000000000000LL) == 0 )
              {
                v13 = 16 * v11;
                if ( (unsigned __int64)v6 <= 16 * v11 )
                  break;
                v11 = v12++;
                *(_BYTE *)(v8 + v13) = v10;
                if ( v9 <= v11 )
                  goto LABEL_11;
              }
              goto LABEL_85;
            }
LABEL_11:
            v59 = a1;
            v64 = v8;
            dir = debugfs_create_dir("qcom_stats", 0);
            if ( *(_BYTE *)(v3 + 34) == 1 )
            {
              v14 = *(_QWORD *)(a1 + 760);
              v66[0] = nullptr;
              v62 = v14;
              v15 = ((__int64 (*)(void))of_property_read_string_helper)();
              if ( v15 >= 1 )
              {
                v16 = 0;
                v17 = &subsystems;
                v18 = (char *)&subsystems_zte;
                v19 = &off_248;
                v20 = &off_260;
                v21 = 24;
                v61 = (unsigned int)v15;
                do
                {
                  v22 = (const char **)v20;
                  v23 = v18;
                  v24 = (const char **)v19;
                  of_property_read_string_helper(v62, "ss-name", v66, 1, (unsigned int)v16);
                  v25 = v66[0];
                  v26 = subsystems;
                  if ( strcmp(subsystems, v66[0]) )
                  {
                    v17 = &off_170;
                    v26 = off_170;
                    if ( strcmp(off_170, v25) )
                    {
                      v17 = &off_188;
                      v26 = off_188;
                      if ( strcmp(off_188, v25) )
                      {
                        v17 = &off_1A0;
                        v26 = off_1A0;
                        if ( strcmp(off_1A0, v25) )
                        {
                          v17 = &off_1B8;
                          v26 = off_1B8;
                          if ( strcmp(off_1B8, v25) )
                          {
                            v17 = &off_1D0;
                            v26 = off_1D0;
                            if ( strcmp(off_1D0, v25) )
                            {
                              v17 = &off_1E8;
                              v26 = off_1E8;
                              if ( strcmp(off_1E8, v25) )
                              {
                                v17 = &off_200;
                                v26 = off_200;
                                if ( strcmp(off_200, v25) )
                                {
                                  v17 = &off_218;
                                  v26 = off_218;
                                  if ( strcmp(off_218, v25) )
                                  {
                                    v17 = &off_230;
                                    v26 = off_230;
                                    if ( strcmp(off_230, v25) )
                                    {
                                      v26 = (char *)*v24;
                                      v17 = (char **)v24;
                                      if ( strcmp(*v24, v25) )
                                      {
                                        v26 = (char *)*v22;
                                        v17 = (char **)v22;
                                        if ( strcmp(*v22, v25) )
                                        {
                                          v17 = &off_278;
                                          v26 = off_278;
                                          if ( strcmp(off_278, v25) )
                                          {
                                            v17 = &off_290;
                                            v26 = off_290;
                                            if ( strcmp(off_290, v25) )
                                            {
                                              v26 = off_2A8;
                                              v27 = strcmp(off_2A8, v25);
                                              v19 = (char **)v24;
                                              v18 = v23;
                                              v20 = (char **)v22;
                                              if ( v27 )
                                                goto LABEL_33;
                                              v17 = &off_2A8;
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
                  debugfs_create_file(v26, 256, dir, v17, &qcom_subsystem_sleep_stats_fops);
                  if ( v16 > 0x13 )
                    __break(0x5512u);
                  v9 = (unsigned __int64)*v17;
                  v28 = v17[1];
                  v29 = &v23[v21];
                  v30 = v17[2];
                  *((_QWORD *)v29 - 3) = *v17;
                  *((_QWORD *)v29 - 2) = v28;
                  *((_QWORD *)v29 - 1) = v30;
                  if ( v21 > 0x280 )
                    goto LABEL_85;
                  v18 = v23;
                  *(_DWORD *)&v23[v21] = 1;
                  v19 = (char **)v24;
                  v20 = (char **)v22;
LABEL_33:
                  ++v16;
                  v21 += 32LL;
                  v17 = &subsystems;
                }
                while ( v61 != v16 );
              }
            }
            v31 = *(unsigned __int8 *)(v3 + 33);
            BYTE4(v66[0]) = 0;
            LODWORD(v66[0]) = 0;
            if ( v31 == 1 )
              v32 = (unsigned __int16)readl(v60 + 20);
            else
              v32 = *(_QWORD *)v3;
            v63 = v3;
            if ( *(_QWORD *)(v3 + 24) )
            {
              v9 = 0;
              v34 = 0;
              v35 = 1;
              v36 = v60 + v32;
              while ( (v9 & 0x8000000000000000LL) == 0 )
              {
                v37 = (16 * v9) | 8;
                if ( (unsigned __int64)v6 < v37 )
                  break;
                v38 = 16 * v9;
                v39 = v34;
                v40 = v36 + v34;
                v41 = v64 + v38;
                *(_QWORD *)(v64 + v38 + 8) = v40;
                LODWORD(v66[0]) = readl(v40);
                strim(v66);
                debugfs_create_file(v66, 256, dir, v64 + v38, &qcom_soc_sleep_stats_fops);
                v9 = LODWORD(v66[0]) ^ 0x64736F61 | (unsigned int)BYTE4(v66[0]);
                if ( !(_DWORD)v9 )
                {
                  if ( (unsigned __int64)v6 < v37 )
                    break;
                  soc_aosd_0 = *(_QWORD *)(v41 + 8);
                }
                v9 = LODWORD(v66[0]) ^ 0x64737863 | (unsigned int)BYTE4(v66[0]);
                if ( !(_DWORD)v9 )
                {
                  if ( (unsigned __int64)v6 < v37 )
                    break;
                  v9 = *(_QWORD *)(v41 + 8);
                  qword_3B8 = v9;
                }
                if ( (unsigned __int64)v6 <= v38 )
                  break;
                v3 = v63;
                v9 = v35++;
                if ( *(_BYTE *)v41 )
                  v42 = 48;
                else
                  v42 = 32;
                v34 = v42 + v39;
                if ( *(_QWORD *)(v63 + 24) <= v9 )
                  goto LABEL_54;
              }
LABEL_85:
              __break(1u);
              goto LABEL_86;
            }
LABEL_54:
            v43 = *(_QWORD *)(v3 + 8);
            if ( v43 && (unsigned int)readl_relaxed((unsigned int *)(v60 + v43)) == -1592427915 )
              debugfs_create_file("ddr_stats", 256, dir, v60 + v43, &ddr_stats_fops);
            v6 = &unk_9000;
            if ( *(_BYTE *)(v3 + 39) == 1 )
              debugfs_create_file("island_stats", 256, dir, 0, &island_stats_fops);
            v44 = (_QWORD *)drv;
            v45 = drv + 192;
            *(_QWORD *)drv = v60;
            v44[1] = v3;
            v44[2] = v64;
            v44[3] = dir;
            v44[31] = 0;
            _mutex_init(v45, "&drv->lock", &qcom_stats_probe___key);
            v46 = drv;
            v47 = (unsigned int *)(drv + 32);
            v33 = alloc_chrdev_region(drv + 32, 0, 1, "stats");
            if ( v33 )
              goto LABEL_83;
            cdev_init(v46 + 56, &qcom_stats_device_fops);
            v48 = cdev_add(v46 + 56, *(unsigned int *)(v46 + 32), 1);
            if ( v48 )
            {
              v33 = v48;
LABEL_82:
              unregister_chrdev_region(*v47, 1);
              goto LABEL_83;
            }
            v49 = class_create("stats");
            *(_QWORD *)(v46 + 40) = v49;
            v50 = (_QWORD *)(v46 + 40);
            if ( v49 && v49 <= 0xFFFFFFFFFFFFF000LL )
            {
              v51 = device_create();
              *(_QWORD *)(v46 + 48) = v51;
              if ( v51 && v51 < 0xFFFFFFFFFFFFF001LL )
                goto LABEL_68;
              class_destroy(*v50);
              v50 = (_QWORD *)(v46 + 48);
            }
            cdev_del(v46 + 56);
            unregister_chrdev_region(*v47, 1);
            v33 = *(_DWORD *)v50;
            if ( *(_DWORD *)v50 )
            {
LABEL_83:
              debugfs_remove(*(_QWORD *)(v6[470] + 24LL));
              goto LABEL_84;
            }
LABEL_68:
            if ( *(_BYTE *)(v63 + 35) == 1 )
            {
              if ( *(_QWORD *)(v63 + 8) )
              {
                v52 = qmp_get(v59 + 16);
                v9 = drv;
                *(_QWORD *)(drv + 240) = v52;
                if ( v52 >= 0xFFFFFFFFFFFFF001LL )
                {
                  v33 = v52;
LABEL_81:
                  device_destroy(*(_QWORD *)(v9 + 40), *(unsigned int *)(v9 + 32));
                  class_destroy(*(_QWORD *)(v6[470] + 40LL));
                  cdev_del(v6[470] + 56LL);
                  v47 = (unsigned int *)(v6[470] + 32LL);
                  goto LABEL_82;
                }
              }
            }
            subsystem_stats_debug_on = 0;
            b_subsystem_stats = devm_kmalloc(v59 + 16, 480, 3520);
            if ( b_subsystem_stats )
            {
              v53 = devm_kmalloc(v59 + 16, 480, 3520);
              v9 = drv;
              a_subsystem_stats = v53;
              if ( v53 )
              {
                v54 = *(_QWORD *)(*(_QWORD *)(drv + 8) + 24LL);
                if ( v54 >> 59 )
                {
LABEL_86:
                  b_system_stats = 0;
                  goto LABEL_80;
                }
                v55 = devm_kmalloc(v59 + 16, 32 * v54, 3520);
                v9 = drv;
                b_system_stats = v55;
                if ( v55 )
                {
                  v56 = *(_QWORD *)(*(_QWORD *)(drv + 8) + 24LL);
                  if ( v56 >> 59 )
                  {
                    a_system_stats = 0;
                    goto LABEL_80;
                  }
                  v57 = devm_kmalloc(v59 + 16, 32 * v56, 3520);
                  v9 = drv;
                  a_system_stats = v57;
                  if ( v57 )
                  {
                    *(_QWORD *)(v59 + 168) = drv;
                    tracepoint_probe_register(&_tracepoint_suspend_resume, debug_suspend_trace_probe, 0);
                    v33 = 0;
                    goto LABEL_84;
                  }
                }
              }
            }
            else
            {
              v9 = drv;
            }
LABEL_80:
            v33 = -12;
            goto LABEL_81;
          }
        }
      }
    }
    v33 = -12;
  }
  else
  {
    v33 = -19;
  }
LABEL_84:
  _ReadStatusReg(SP_EL0);
  return v33;
}
