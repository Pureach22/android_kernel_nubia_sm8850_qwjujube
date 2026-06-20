__int64 __fastcall sde_encoder_virt_mode_set(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  __int64 v6; // x0
  int v7; // w6
  int v8; // w7
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x26
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  int v18; // w7
  __int64 v19; // x21
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x23
  __int64 v23; // x25
  __int64 result; // x0
  __int64 v25; // x8
  unsigned int v26; // w6
  __int64 v27; // x1
  __int64 v28; // x8
  __int64 v29; // x28
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x0
  unsigned int v33; // w24
  int v34; // w8
  int v35; // w8
  int v36; // w8
  int v37; // w9
  __int64 v38; // x20
  __int64 v39; // x20
  __int64 v40; // x20
  __int64 v41; // x20
  __int64 v42; // x8
  int v43; // w8
  __int64 v44; // x27
  __int64 (__fastcall *v45)(_QWORD); // x8
  __int64 v46; // x0
  __int64 v47; // x8
  int v48; // w8
  __int64 v49; // x27
  __int64 (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x0
  __int64 v52; // x8
  int v53; // w8
  __int64 v54; // x27
  __int64 (__fastcall *v55)(_QWORD); // x8
  __int64 v56; // x0
  __int64 v57; // x8
  int v58; // w8
  __int64 v59; // x27
  __int64 (__fastcall *v60)(_QWORD); // x8
  __int64 v61; // x0
  __int64 v62; // x8
  int v63; // w26
  unsigned int v64; // w20
  unsigned __int64 i; // x27
  _QWORD *v66; // x28
  __int64 v67; // x9
  _DWORD *v68; // x9
  __int64 v69; // x0
  void (*v70)(void); // x8
  __int64 v71; // x2
  __int64 v72; // x0
  __int64 (__fastcall *v73)(__int64, __int64, __int64, __int64); // x9
  __int64 (*v74)(void); // x10
  int v75; // w8
  void *v76; // x0
  void *v77; // x0
  void *v78; // x0
  char v79; // [xsp+0h] [xbp-430h]
  char v80; // [xsp+0h] [xbp-430h]
  unsigned int disp_op; // [xsp+14h] [xbp-41Ch]
  __int64 v82; // [xsp+18h] [xbp-418h]
  _BOOL4 v84; // [xsp+2Ch] [xbp-404h]
  __int64 v85; // [xsp+30h] [xbp-400h]
  __int64 v86; // [xsp+38h] [xbp-3F8h]
  __int64 v87; // [xsp+38h] [xbp-3F8h]
  __int64 v88; // [xsp+38h] [xbp-3F8h]
  __int64 v89; // [xsp+38h] [xbp-3F8h]
  __int64 v90; // [xsp+40h] [xbp-3F0h] BYREF
  __int64 v91; // [xsp+48h] [xbp-3E8h]
  _QWORD v92[3]; // [xsp+50h] [xbp-3E0h] BYREF
  _QWORD v93[3]; // [xsp+68h] [xbp-3C8h] BYREF
  _QWORD v94[3]; // [xsp+80h] [xbp-3B0h] BYREF
  _QWORD dest[115]; // [xsp+98h] [xbp-398h] BYREF

  dest[113] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = printk(&unk_26FCAB, "sde_encoder_virt_mode_set");
    goto LABEL_161;
  }
  if ( !*(_QWORD *)a1 )
  {
    v76 = &unk_26FCAB;
LABEL_150:
    printk(v76, "sde_encoder_get_kms");
    disp_op = 0;
    v9 = *(_QWORD *)a1;
    if ( !*(_QWORD *)a1 )
      goto LABEL_151;
    goto LABEL_6;
  }
  v5 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v5 || (v6 = *(_QWORD *)(v5 + 8)) == 0 )
  {
    v76 = &unk_234896;
    goto LABEL_150;
  }
  disp_op = sde_kms_get_disp_op(v6, a2);
  v9 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
  {
LABEL_151:
    result = printk(&unk_24FBDF, "sde_encoder_virt_mode_set");
    goto LABEL_161;
  }
LABEL_6:
  if ( (*(_WORD *)(*(_QWORD *)(v9 + 8) + 488LL) & 7) != 0 )
    goto LABEL_151;
  v10 = *(_QWORD *)(v9 + 56);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 8)) == 0 )
  {
    result = printk(&unk_234896, "sde_encoder_get_kms");
    goto LABEL_161;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(a1 + 24));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_virt_mode_set",
    3606,
    -1,
    *(_DWORD *)(a1 + 24),
    -1059143953,
    v7,
    v8,
    v79);
  v19 = *(_QWORD *)(a1 + 80);
  if ( !v19 )
  {
    result = printk(&unk_25E167, "sde_encoder_virt_mode_set");
    goto LABEL_161;
  }
  *(_QWORD *)(a1 + 1360) = v19;
  v82 = *(_QWORD *)(v19 + 2008);
  v84 = *(_BYTE *)(v82 + 6922) == 1 && (*(_BYTE *)(a1 + 644) & 0x80) == 0;
  if ( *(_DWORD *)(a1 + 640) != 15 || ((*(_DWORD *)(v82 + 1816) >> *(_DWORD *)(a1 + 68)) & 1) == 0 )
    sde_crtc_set_qos_dirty((int *)v19, v12, v13, v14, v15, v16, v17, v18);
  v20 = *(_QWORD *)(v11 + 136);
  dest[0] = 0;
  dest[1] = 0;
  drm_connector_list_iter_begin(v20, dest);
  do
  {
    v21 = drm_connector_list_iter_next(dest);
    if ( !v21 )
    {
      drm_connector_list_iter_end(dest);
      result = printk(&unk_256FE3, "sde_encoder_virt_mode_set");
      goto LABEL_161;
    }
  }
  while ( *(_QWORD *)(v21 + 2272) != a1 );
  v85 = v21;
  drm_connector_list_iter_end(dest);
  v22 = *(_QWORD *)(v85 + 2512);
  if ( !v22 )
  {
    result = printk(&unk_2538C5, "sde_encoder_virt_mode_set");
    goto LABEL_161;
  }
  if ( (*(_BYTE *)(a1 + 644) & 0x80) == 0 )
  {
    sde_connector_state_get_mode_info(*(_QWORD *)(v85 + 2512), (void *)(a1 + 3944));
    v23 = *(_QWORD *)(a1 + 1360);
    memcpy(dest, (const void *)(a1 + 3944), 0x388u);
    sde_encoder_dce_set_bpp(dest, v23);
    v22 = *(_QWORD *)(v85 + 2512);
    if ( !v22 )
    {
      result = printk(&unk_2319B1, "sde_encoder_virt_mode_set");
      goto LABEL_161;
    }
  }
  kthread_cancel_delayed_work_sync(a1 + 944);
  result = sde_encoder_virt_modeset_rc(a1);
  if ( !(_DWORD)result )
  {
    if ( *(_BYTE *)(a1 + 749) == 1 )
    {
      v25 = *(_QWORD *)(a1 + 328);
      if ( v25 )
      {
        if ( *(_BYTE *)(v25 + 2289) )
          sde_connector_set_vrr_params(*(_QWORD *)(v25 + 8));
      }
    }
    if ( *(_DWORD *)(a1 + 640) == 15 )
    {
      v26 = *(_DWORD *)(v82 + 1816);
      if ( ((v26 >> *(_DWORD *)(a1 + 68)) & 1) != 0 )
      {
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_virt_mode_set",
          3666,
          -1,
          *(_DWORD *)(a1 + 24),
          *(_DWORD *)(v82 + 1812),
          v26,
          -1059143953,
          v80);
        *(_DWORD *)(v82 + 1812) = *(_DWORD *)(v82 + 1816);
        ((void (__fastcall *)(__int64, __int64))sde_encoder_set_clone_mode)(a1, v82);
        *(_DWORD *)(v19 + 7872) |= 1 << *(_DWORD *)(a1 + 68);
      }
    }
    if ( (unsigned int)sde_rm_reserve(
                         v11 + 2144,
                         a1,
                         *(_QWORD *)(*(_QWORD *)(a1 + 80) + 2008LL),
                         *(_QWORD *)(v85 + 2512),
                         0) )
    {
      result = printk(&unk_256EF0, "sde_encoder_virt_mode_set");
      goto LABEL_161;
    }
    if ( *(_QWORD *)a1 )
    {
      v28 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
      if ( v28 )
      {
        v29 = *(_QWORD *)(v28 + 8);
        if ( v29 )
        {
LABEL_36:
          v30 = *(_QWORD *)a1;
          memset(dest, 0, 24);
          memset(v94, 0, sizeof(v94));
          memset(v93, 0, sizeof(v93));
          memset(v92, 0, sizeof(v92));
          v90 = 0;
          v91 = 0;
          *(_DWORD *)(a1 + 496) = 0;
          if ( v30 )
          {
            v31 = *(_QWORD *)(v30 + 56);
            if ( v31 )
            {
              v32 = *(_QWORD *)(v31 + 8);
              if ( v32 )
              {
                v33 = sde_kms_get_disp_op(v32, v27);
LABEL_40:
                sde_rm_init_hw_iter(dest, *(unsigned int *)(a1 + 24), 7);
                *(_QWORD *)(a1 + 336) = 0;
                if ( (sde_rm_get_hw(v29 + 2144, dest) & 1) != 0 )
                {
                  v34 = *(_DWORD *)(a1 + 496) + 1;
                  *(_QWORD *)(a1 + 336) = dest[0];
                  *(_QWORD *)(a1 + 344) = 0;
                  *(_DWORD *)(a1 + 496) = v34;
                  if ( (sde_rm_get_hw(v29 + 2144, dest) & 1) != 0 )
                  {
                    v35 = *(_DWORD *)(a1 + 496) + 1;
                    *(_QWORD *)(a1 + 344) = dest[0];
                    *(_QWORD *)(a1 + 352) = 0;
                    *(_DWORD *)(a1 + 496) = v35;
                    if ( (sde_rm_get_hw(v29 + 2144, dest) & 1) != 0 )
                    {
                      v36 = *(_DWORD *)(a1 + 496) + 1;
                      *(_QWORD *)(a1 + 352) = dest[0];
                      *(_QWORD *)(a1 + 360) = 0;
                      *(_DWORD *)(a1 + 496) = v36;
                      if ( (sde_rm_get_hw(v29 + 2144, dest) & 1) != 0 )
                      {
                        v37 = *(_DWORD *)(a1 + 496);
                        *(_QWORD *)(a1 + 360) = dest[0];
                        *(_DWORD *)(a1 + 496) = v37 + 1;
                      }
                    }
                  }
                }
                if ( *(_DWORD *)(a1 + 196) )
                {
                  v38 = *(_QWORD *)(a1 + 200);
                  if ( v38 )
                  {
                    sde_rm_init_hw_iter(v94, *(unsigned int *)(a1 + 24), 13);
                    if ( (sde_rm_get_hw(v29 + 2144, v94) & 1) != 0 )
                      *(_QWORD *)(v38 + 440) = v94[0];
                  }
                  if ( *(_DWORD *)(a1 + 196) >= 2u )
                  {
                    v39 = *(_QWORD *)(a1 + 208);
                    if ( v39 )
                    {
                      sde_rm_init_hw_iter(v94, *(unsigned int *)(a1 + 24), 13);
                      if ( (sde_rm_get_hw(v29 + 2144, v94) & 1) != 0 )
                        *(_QWORD *)(v39 + 440) = v94[0];
                    }
                    if ( *(_DWORD *)(a1 + 196) >= 3u )
                    {
                      v40 = *(_QWORD *)(a1 + 216);
                      if ( v40 )
                      {
                        sde_rm_init_hw_iter(v94, *(unsigned int *)(a1 + 24), 13);
                        if ( (sde_rm_get_hw(v29 + 2144, v94) & 1) != 0 )
                          *(_QWORD *)(v40 + 440) = v94[0];
                      }
                      if ( *(_DWORD *)(a1 + 196) >= 4u )
                      {
                        v41 = *(_QWORD *)(a1 + 224);
                        if ( v41 )
                        {
                          sde_rm_init_hw_iter(v94, *(unsigned int *)(a1 + 24), 13);
                          if ( (sde_rm_get_hw(v29 + 2144, v94) & 1) != 0 )
                            *(_QWORD *)(v41 + 440) = v94[0];
                        }
                        if ( *(_DWORD *)(a1 + 196) > 4u )
                          goto LABEL_168;
                      }
                    }
                  }
                }
                sde_rm_init_hw_iter(v93, *(unsigned int *)(a1 + 24), 10);
                *(_QWORD *)(a1 + 368) = 0;
                if ( (sde_rm_get_hw(v29 + 2144, v93) & 1) != 0 )
                  *(_QWORD *)(a1 + 368) = v93[0];
                *(_QWORD *)(a1 + 376) = 0;
                if ( (sde_rm_get_hw(v29 + 2144, v93) & 1) != 0 )
                  *(_QWORD *)(a1 + 376) = v93[0];
                *(_QWORD *)(a1 + 384) = 0;
                if ( (sde_rm_get_hw(v29 + 2144, v93) & 1) != 0 )
                  *(_QWORD *)(a1 + 384) = v93[0];
                *(_QWORD *)(a1 + 392) = 0;
                if ( (sde_rm_get_hw(v29 + 2144, v93) & 1) != 0 )
                  *(_QWORD *)(a1 + 392) = v93[0];
                sde_rm_init_hw_iter(v92, *(unsigned int *)(a1 + 24), 11);
                *(_QWORD *)(a1 + 400) = 0;
                if ( (sde_rm_get_hw(v29 + 2144, v92) & 1) != 0 )
                  *(_QWORD *)(a1 + 400) = v92[0];
                *(_QWORD *)(a1 + 408) = 0;
                if ( (sde_rm_get_hw(v29 + 2144, v92) & 1) != 0 )
                  *(_QWORD *)(a1 + 408) = v92[0];
                *(_QWORD *)(a1 + 416) = 0;
                if ( (sde_rm_get_hw(v29 + 2144, v92) & 1) != 0 )
                  *(_QWORD *)(a1 + 416) = v92[0];
                *(_QWORD *)(a1 + 424) = 0;
                result = sde_rm_get_hw(v29 + 2144, v92);
                if ( (result & 1) != 0 )
                  *(_QWORD *)(a1 + 424) = v92[0];
                v42 = *(_QWORD *)(a1 + 368);
                v86 = 0;
                if ( v42 )
                {
                  v43 = *(_DWORD *)(v42 + 32);
                  LODWORD(v91) = 7;
                  HIDWORD(v91) = v43;
                  result = sde_rm_request_hw_blk(v29 + 2144, &v90);
                  if ( (result & 1) != 0 )
                  {
                    if ( v33 <= 2 )
                    {
                      v44 = v90;
                      v45 = *(__int64 (__fastcall **)(_QWORD))(v90 + 8LL * v33 + 424);
                      if ( v45 )
                      {
                        v46 = v90;
                        if ( *((_DWORD *)v45 - 1) != 401501016 )
                          __break(0x8228u);
                        result = v45(v46);
                        v86 = result;
                      }
                      *(_QWORD *)(a1 + 432) = v44 & (v86 << 58 >> 63);
                      goto LABEL_86;
                    }
LABEL_168:
                    __break(0x5512u);
                  }
                }
                else
                {
LABEL_86:
                  v47 = *(_QWORD *)(a1 + 376);
                  v87 = 0;
                  if ( v47 )
                  {
                    v48 = *(_DWORD *)(v47 + 32);
                    LODWORD(v91) = 7;
                    HIDWORD(v91) = v48;
                    result = sde_rm_request_hw_blk(v29 + 2144, &v90);
                    if ( (result & 1) == 0 )
                      goto LABEL_110;
                    if ( v33 > 2 )
                      goto LABEL_168;
                    v49 = v90;
                    v50 = *(__int64 (__fastcall **)(_QWORD))(v90 + 8LL * v33 + 424);
                    if ( v50 )
                    {
                      v51 = v90;
                      if ( *((_DWORD *)v50 - 1) != 401501016 )
                        __break(0x8228u);
                      result = v50(v51);
                      v87 = result;
                    }
                    *(_QWORD *)(a1 + 440) = v49 & (v87 << 58 >> 63);
                  }
                  v52 = *(_QWORD *)(a1 + 384);
                  v88 = 0;
                  if ( v52 )
                  {
                    v53 = *(_DWORD *)(v52 + 32);
                    LODWORD(v91) = 7;
                    HIDWORD(v91) = v53;
                    result = sde_rm_request_hw_blk(v29 + 2144, &v90);
                    if ( (result & 1) == 0 )
                      goto LABEL_110;
                    if ( v33 > 2 )
                      goto LABEL_168;
                    v54 = v90;
                    v55 = *(__int64 (__fastcall **)(_QWORD))(v90 + 8LL * v33 + 424);
                    if ( v55 )
                    {
                      v56 = v90;
                      if ( *((_DWORD *)v55 - 1) != 401501016 )
                        __break(0x8228u);
                      result = v55(v56);
                      v88 = result;
                    }
                    *(_QWORD *)(a1 + 448) = v54 & (v88 << 58 >> 63);
                  }
                  v57 = *(_QWORD *)(a1 + 392);
                  v89 = 0;
                  if ( v57 )
                  {
                    v58 = *(_DWORD *)(v57 + 32);
                    LODWORD(v91) = 7;
                    HIDWORD(v91) = v58;
                    result = sde_rm_request_hw_blk(v29 + 2144, &v90);
                    if ( (result & 1) != 0 )
                    {
                      if ( v33 > 2 )
                        goto LABEL_168;
                      v59 = v90;
                      v60 = *(__int64 (__fastcall **)(_QWORD))(v90 + 8LL * v33 + 424);
                      if ( v60 )
                      {
                        v61 = v90;
                        if ( *((_DWORD *)v60 - 1) != 401501016 )
                          __break(0x8228u);
                        result = v60(v61);
                        v89 = result;
                      }
                      *(_QWORD *)(a1 + 456) = v59 & (v89 << 58 >> 63);
                    }
                  }
                }
LABEL_110:
                v62 = v85;
                if ( (unsigned int)(*(_DWORD *)(a1 + 3980) / *(_DWORD *)(a1 + 3988)) <= 1 )
                  v63 = 1;
                else
                  v63 = *(_DWORD *)(a1 + 3980) / *(_DWORD *)(a1 + 3988);
                if ( *(_DWORD *)(a1 + 196) )
                {
                  v64 = 0;
                  for ( i = 0; i < *(unsigned int *)(a1 + 196); ++i )
                  {
                    if ( i == 4 )
                      goto LABEL_168;
                    v66 = *(_QWORD **)(a1 + 200 + 8 * i);
                    if ( v66 )
                    {
                      if ( (*(_BYTE *)(**(_QWORD **)(v62 + 2512) + 5128LL) & 1) == 0 )
                      {
                        if ( v64 > 3 )
                          goto LABEL_168;
                        v67 = *(_QWORD *)(a1 + 336 + 8LL * v64);
                        if ( !v67 )
                        {
                          result = printk(&unk_270128, "sde_encoder_virt_mode_set");
                          goto LABEL_161;
                        }
                        v66[62] = v67;
                      }
                      v68 = (_DWORD *)v66[6];
                      v66[1] = v62;
                      if ( v68 )
                      {
                        if ( *(v68 - 1) != 1448630571 )
                          __break(0x8229u);
                        result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))v68)(
                                   v66,
                                   a2,
                                   a3,
                                   v19 + 7757);
                        v62 = v85;
                      }
                      if ( (*(_BYTE *)(a1 + 644) & 0x80) != 0 )
                      {
                        result = sde_get_primary_ctl_in_lb((__int64 **)v82);
                        v62 = v85;
                        v66[52] = result;
                        if ( !result )
                        {
                          result = printk(&unk_270166, "sde_encoder_virt_mode_set");
                          goto LABEL_161;
                        }
                      }
                      if ( v84 )
                      {
                        if ( disp_op > 2 )
                          goto LABEL_168;
                        v69 = v66[53];
                        v70 = *(void (**)(void))(v69 + 8LL * disp_op + 416);
                        if ( v70 && *(_QWORD *)(v66[52] + 8LL * disp_op + 1192) )
                        {
                          if ( *((_DWORD *)v70 - 1) != 530145669 )
                            __break(0x8228u);
                          v70();
                          v69 = v66[53];
                        }
                        v71 = *(unsigned int *)(v69 + 32);
                        v72 = v66[52];
                        v73 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v72 + 8LL * disp_op + 1192);
                        if ( *((_DWORD *)v73 - 1) != 949740941 )
                          __break(0x8229u);
                        result = v73(v72, 7, v71, 1);
                        v62 = v85;
                        if ( *(_QWORD *)(v66[62] + 56LL) )
                        {
                          result = v66[52];
                          v74 = *(__int64 (**)(void))(result + 8LL * disp_op + 1192);
                          if ( v74 )
                          {
                            if ( *((_DWORD *)v74 - 1) != 949740941 )
                              __break(0x822Au);
                            result = v74();
                            v62 = v85;
                          }
                        }
                      }
                    }
                    v64 += v63;
                  }
                }
                v75 = *(_DWORD *)(v22 + 3240);
                if ( (v75 & 4) != 0 || (v75 & 0x10) != 0 && *(_DWORD *)(a1 + 648) == 2 )
                {
                  result = sde_encoder_resource_control(a1, 5);
                }
                else if ( (v75 & 0xC0) != 0 )
                {
                  result = sde_encoder_modeset_helper_locked(a1, 5);
                }
                goto LABEL_161;
              }
            }
            v78 = &unk_234896;
          }
          else
          {
            v78 = &unk_26FCAB;
          }
          printk(v78, "sde_encoder_get_kms");
          v33 = 0;
          goto LABEL_40;
        }
      }
      v77 = &unk_234896;
    }
    else
    {
      v77 = &unk_26FCAB;
    }
    printk(v77, "sde_encoder_get_kms");
    v29 = 0;
    goto LABEL_36;
  }
LABEL_161:
  _ReadStatusReg(SP_EL0);
  return result;
}
