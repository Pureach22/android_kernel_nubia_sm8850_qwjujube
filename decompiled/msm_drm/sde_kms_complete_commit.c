__int64 __fastcall sde_kms_complete_commit(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x8
  __int64 v12; // x19
  __int64 v13; // x23
  __int64 v14; // x8
  __int64 *v15; // x22
  __int64 v16; // x19
  __int64 i; // x25
  __int64 v18; // x24
  unsigned int (__fastcall *v19)(__int64, __int64 *); // x8
  __int64 v20; // x0
  __int64 v21; // x8
  unsigned int (__fastcall *v22)(__int64, __int64); // x8
  int v23; // w6
  int v24; // w7
  __int64 v25; // x25
  __int64 v26; // x26
  __int64 v27; // x22
  __int64 v28; // x19
  __int64 v29; // x0
  _QWORD *v30; // x23
  __int64 v31; // x3
  __int64 v32; // x3
  __int64 v33; // x3
  __int64 v34; // x3
  char v35; // [xsp+0h] [xbp-40h]
  __int64 v36; // [xsp+10h] [xbp-30h] BYREF
  __int64 v37; // [xsp+18h] [xbp-28h]
  __int64 v38; // [xsp+20h] [xbp-20h]
  __int64 v39; // [xsp+28h] [xbp-18h]
  __int64 v40; // [xsp+30h] [xbp-10h]
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    if ( a2 )
    {
      v9 = *(_QWORD *)(result + 136);
      v10 = result;
      if ( v9 )
      {
        if ( *(_QWORD *)(v9 + 56) )
        {
          v39 = 0;
          v40 = 0;
          v37 = 0;
          v38 = 0;
          v11 = *(_QWORD *)(v9 + 8);
          v36 = 0;
          if ( (*(_WORD *)(v11 + 488) & 7) != 0 )
          {
            result = printk(&unk_24FBDF, "sde_kms_complete_commit");
          }
          else
          {
            _ReadStatusReg(SP_EL0);
            if ( *(int *)(*(_QWORD *)(a2 + 8) + 860LL) >= 1 )
            {
              v12 = 0;
              v13 = 0;
              do
              {
                v14 = *(_QWORD *)(a2 + 32);
                v15 = *(__int64 **)(v14 + v12);
                if ( v15 )
                {
                  sde_crtc_complete_commit(v15, *(_QWORD *)(v14 + v12 + 16), a3, a4, a5, a6, a7, a8);
                  if ( *(_DWORD *)(v10 + 3672) == 2 )
                    sde_kms_secure_ctrl(v10, v15, 1);
                }
                ++v13;
                v12 += 56;
              }
              while ( v13 < *(int *)(*(_QWORD *)(a2 + 8) + 860LL) );
            }
            if ( *(int *)(a2 + 40) >= 1 )
            {
              v16 = 0;
              for ( i = 0; i < *(int *)(a2 + 40); ++i )
              {
                v18 = *(_QWORD *)(*(_QWORD *)(a2 + 48) + v16);
                if ( v18 && *(_QWORD *)(v18 + 3048) )
                {
                  v39 = 0;
                  v40 = 0;
                  v37 = 0;
                  v38 = 0;
                  v36 = 0;
                  sde_connector_complete_qsync_commit(v18, &v36);
                  v19 = *(unsigned int (__fastcall **)(__int64, __int64 *))(v18 + 3048);
                  if ( *((_DWORD *)v19 - 1) != -1353054398 )
                    __break(0x8228u);
                  if ( v19(v18, &v36) )
                  {
                    printk(&unk_250318, "sde_kms_complete_commit");
                    v20 = *(_QWORD *)(v18 + 2272);
                    if ( v20 )
                    {
LABEL_21:
                      if ( *(_BYTE *)(v20 + 749) == 1 )
                        sde_encoder_post_commit_bl_sr_work(v20);
                    }
                  }
                  else
                  {
                    v20 = *(_QWORD *)(v18 + 2272);
                    if ( v20 )
                      goto LABEL_21;
                  }
                }
                v16 += 40;
              }
            }
            v21 = *(_QWORD *)(v10 + 6384);
            if ( v21 )
            {
              v22 = *(unsigned int (__fastcall **)(__int64, __int64))(v21 + 104);
              if ( v22 )
              {
                if ( *((_DWORD *)v22 - 1) != -307910306 )
                  __break(0x8228u);
                if ( v22(v10, a2) )
                  printk(&unk_2498AE, "sde_kms_complete_commit");
              }
            }
            sde_kms_drm_check_dpms(a2, 0);
            _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(v10 + 136) + 8LL), 4);
            if ( *(int *)(*(_QWORD *)(a2 + 8) + 860LL) >= 1 )
            {
              v25 = 0;
              v26 = 0;
              do
              {
                v27 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + v25);
                if ( v27 )
                {
                  if ( *(_BYTE *)(*(_QWORD *)(v27 + 2008) + 9LL) == 1 )
                  {
                    v23 = *(_DWORD *)(v10 + 2544);
                    if ( v23 )
                    {
                      if ( (v28 = *(_QWORD *)(*(_QWORD *)(v10 + 136) + 56LL),
                            sde_evtlog_log(
                              sde_dbg_base_evtlog,
                              "_sde_kms_release_splash_resource",
                              1503,
                              -1,
                              *(_DWORD *)(v27 + 112),
                              1,
                              v23,
                              -1059143953,
                              v35),
                            (v29 = *(_QWORD *)(v10 + 2720)) != 0)
                        && (v30 = (_QWORD *)(v10 + 2712), *(_QWORD *)(v29 + 80) == v27)
                        || (v29 = *(_QWORD *)(v10 + 2800)) != 0
                        && (v30 = (_QWORD *)(v10 + 2792), *(_QWORD *)(v29 + 80) == v27) )
                      {
                        if ( *(_BYTE *)v30 == 1 )
                        {
                          sde_encoder_update_caps_for_cont_splash(v29, (__int64)v30, 0);
                          sde_kms_free_splash_display_data(v10, v30);
                        }
                        if ( !*(_DWORD *)(v10 + 2544) )
                        {
                          if ( !*(_DWORD *)(v28 + 5912) )
                          {
                            v31 = *(_QWORD *)(v28 + 400) ? *(_QWORD *)(v28 + 400) : 400000000LL;
                            sde_power_data_bus_set_quota(v28 + 16, 0, 0, v31);
                            if ( !*(_DWORD *)(v28 + 5912) )
                            {
                              v32 = *(_QWORD *)(v28 + 408) ? *(_QWORD *)(v28 + 408) : 400000000LL;
                              sde_power_data_bus_set_quota(v28 + 16, 1, 0, v32);
                              if ( !*(_DWORD *)(v28 + 5912) )
                              {
                                v33 = *(_QWORD *)(v28 + 416) ? *(_QWORD *)(v28 + 416) : 400000000LL;
                                sde_power_data_bus_set_quota(v28 + 16, 2, 0, v33);
                                if ( !*(_DWORD *)(v28 + 5912) )
                                {
                                  if ( *(_QWORD *)(v28 + 424) )
                                    v34 = *(_QWORD *)(v28 + 424);
                                  else
                                    v34 = 400000000;
                                  sde_power_data_bus_set_quota(v28 + 16, 3, 0, v34);
                                }
                              }
                            }
                          }
                          sde_cesta_splash_release(**(unsigned int **)(*(_QWORD *)(v10 + 136) + 64LL));
                          _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(v10 + 136) + 8LL), 4);
                        }
                      }
                    }
                  }
                }
                ++v26;
                v25 += 56;
              }
              while ( v26 < *(int *)(*(_QWORD *)(a2 + 8) + 860LL) );
            }
            result = sde_evtlog_log(
                       sde_dbg_base_evtlog,
                       "sde_kms_complete_commit",
                       1806,
                       4,
                       8738,
                       -1059143953,
                       v23,
                       v24,
                       v35);
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
