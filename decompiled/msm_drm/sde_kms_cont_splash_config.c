__int64 __fastcall sde_kms_cont_splash_config(__int64 a1, __int64 a2)
{
  void *v2; // x0
  unsigned int v4; // w25
  __int64 v6; // x8
  __int64 v7; // x28
  __int64 v8; // x22
  __int64 v9; // x9
  char v10; // w10
  __int64 v11; // x21
  __int64 v12; // x23
  __int64 v13; // x22
  __int64 v14; // x23
  __int64 v15; // x20
  unsigned int v16; // w0
  const char *v17; // x4
  __int64 v18; // x27
  __int64 v19; // x0
  __int64 v20; // x24
  __int64 v21; // x8
  __int64 v22; // x8
  unsigned __int64 v23; // x20
  const char *v24; // x23
  _QWORD *v25; // x9
  __int64 v26; // x22
  _QWORD *v27; // x26
  _QWORD *v28; // x9
  unsigned int v29; // w0
  void (__fastcall *v30)(_QWORD); // x8
  __int64 v31; // x0
  __int64 v32; // x28
  unsigned __int64 v33; // x21
  unsigned int *v34; // x22
  int v35; // w5
  __int64 v36; // x24
  unsigned int v37; // w25
  char v38; // w23
  __int64 v39; // x10
  char v40; // w9
  void *v41; // x0
  void *v42; // x0
  __int64 v43; // [xsp+18h] [xbp-F8h]
  __int64 v44; // [xsp+20h] [xbp-F0h]
  __int64 v45; // [xsp+28h] [xbp-E8h]
  __int64 v46; // [xsp+30h] [xbp-E0h]
  unsigned int *v47; // [xsp+38h] [xbp-D8h]
  __int64 v48; // [xsp+40h] [xbp-D0h]
  __int64 v49; // [xsp+40h] [xbp-D0h]
  __int64 v50; // [xsp+48h] [xbp-C8h]
  _QWORD v51[2]; // [xsp+50h] [xbp-C0h] BYREF
  __int64 v52; // [xsp+60h] [xbp-B0h] BYREF
  __int64 v53; // [xsp+68h] [xbp-A8h]
  __int64 v54; // [xsp+70h] [xbp-A0h]
  __int64 v55; // [xsp+78h] [xbp-98h]
  __int64 v56; // [xsp+80h] [xbp-90h]
  __int64 v57; // [xsp+88h] [xbp-88h]
  __int64 v58; // [xsp+90h] [xbp-80h]
  __int64 v59; // [xsp+98h] [xbp-78h]
  __int64 v60; // [xsp+A0h] [xbp-70h]
  __int64 v61; // [xsp+A8h] [xbp-68h]
  __int64 v62; // [xsp+B0h] [xbp-60h]
  __int64 v63; // [xsp+B8h] [xbp-58h]
  __int64 v64; // [xsp+C0h] [xbp-50h]
  __int64 v65; // [xsp+C8h] [xbp-48h]
  __int64 v66; // [xsp+D0h] [xbp-40h]
  __int64 v67; // [xsp+D8h] [xbp-38h]
  __int64 v68; // [xsp+E0h] [xbp-30h]
  __int64 v69; // [xsp+E8h] [xbp-28h]
  __int64 v70; // [xsp+F0h] [xbp-20h]
  __int64 v71; // [xsp+F8h] [xbp-18h]
  __int64 v72; // [xsp+100h] [xbp-10h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v51[0] = 0;
  v51[1] = 0;
  if ( !a1 )
  {
    v2 = &unk_234896;
    goto LABEL_5;
  }
  if ( !*(_QWORD *)(a1 + 136) )
  {
    v2 = &unk_231B33;
LABEL_5:
    printk(v2, "sde_kms_cont_splash_config");
LABEL_6:
    v4 = -22;
    goto LABEL_7;
  }
  v45 = *(_QWORD *)(a1 + 136);
  v6 = *(_QWORD *)(a1 + 152);
  v7 = a2;
  if ( v6 && *(_BYTE *)(v6 + 20120) == 1 && *(int *)(a1 + 3568) >= 1 )
  {
    v8 = 0;
    while ( 1 )
    {
      v9 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3576) + 8 * v8) + 1296LL) + 112LL);
      if ( !v9 )
        break;
      v10 = _drm_debug;
      *(_DWORD *)(v9 + 72) = 1 << v8;
      if ( (v10 & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "dsi-display:%d encoder id[%d]=%d name=%s crtcs=%x\n",
          v8,
          *(_DWORD *)(v9 + 68),
          *(_DWORD *)(v9 + 24),
          *(const char **)(v9 + 56),
          1 << v8);
      if ( ++v8 >= *(int *)(a1 + 3568) )
        goto LABEL_16;
    }
    printk(&unk_249913, "sde_kms_vm_trusted_cont_splash_res_init");
    v41 = &unk_224636;
LABEL_100:
    v4 = -22;
LABEL_101:
    printk(v41, "sde_kms_cont_splash_config");
  }
  else
  {
LABEL_16:
    if ( (*(_DWORD *)(a1 + 2536) || *(_DWORD *)(a1 + 2540)) && (a2 = *(unsigned int *)(a1 + 2544), (_DWORD)a2) )
    {
      printk(&unk_22B18A, a2);
      if ( *(int *)(a1 + 3568) >= 1 )
      {
        v11 = 0;
        v12 = 0;
        v4 = 0;
        v13 = a1 + 2712;
        v43 = v7;
        while ( 1 )
        {
          v46 = v12;
          if ( v11 == 3 )
LABEL_110:
            __break(0x5512u);
          v14 = *(_QWORD *)(*(_QWORD *)(a1 + 3576) + 8 * v11);
          v48 = v13 + 80 * v11;
          if ( (*(_BYTE *)v48 & 1) != 0 )
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "display->name = %s\n", *(const char **)(v14 + 32));
            v15 = *(_QWORD *)(*(_QWORD *)(v14 + 1296) + 112LL);
            if ( v15 )
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "encoder name = %s\n", *(const char **)(v15 + 56));
              v46 = v15;
            }
            v70 = 0;
            v71 = 0;
            v68 = 0;
            v69 = 0;
            v66 = 0;
            v67 = 0;
            v64 = 0;
            v65 = 0;
            v62 = 0;
            v63 = 0;
            v60 = 0;
            v61 = 0;
            v58 = 0;
            v59 = 0;
            v56 = 0;
            v57 = 0;
            v54 = 0;
            v55 = 0;
            v52 = 0;
            v53 = 0;
            v16 = ((__int64 (__fastcall *)(_QWORD, __int64 *, __int64))dsi_display_get_info)(0, &v52, v14);
            if ( v16 )
            {
              v4 = v16;
              printk(&unk_243028, "sde_kms_cont_splash_config");
              v12 = 0;
            }
            else
            {
              if ( (_drm_debug & 4) != 0 )
              {
                if ( (_BYTE)v55 )
                  v17 = "true";
                else
                  v17 = "false";
                _drm_dev_dbg(0, 0, 0, "info.is_connected = %s, info.display_type = %d\n", v17, v59);
              }
              if ( !v46 )
              {
                v2 = &unk_24319E;
                goto LABEL_5;
              }
              v18 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL) + 8 * v11 + 1000);
              *(_QWORD *)(v46 + 80) = v18;
              *(_QWORD *)(v48 + 8) = v46;
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "for dsi-display:%d crtc id[%d]:%d enc id[%d]:%d\n",
                  v11,
                  *(_DWORD *)(v18 + 160),
                  *(_DWORD *)(v18 + 112),
                  *(_DWORD *)(v46 + 68),
                  *(_DWORD *)(v46 + 24));
              v44 = v11;
              mutex_lock(v45 + 432);
              drm_connector_list_iter_begin(v45, v51);
              do
              {
                v19 = drm_connector_list_iter_next(v51);
                if ( !v19 )
                {
                  drm_connector_list_iter_end(v51);
                  v42 = &unk_246572;
LABEL_104:
                  printk(v42, "sde_kms_cont_splash_config");
                  mutex_unlock(v45 + 432);
                  goto LABEL_6;
                }
                v20 = v19;
                v21 = *(_QWORD *)v19 + 816LL;
                do
                  v21 = *(_QWORD *)v21;
                while ( v21 != *(_QWORD *)v19 + 816LL && ((*(_DWORD *)(v19 + 2264) >> *(_DWORD *)(v21 + 60)) & 1) == 0 );
                if ( v21 == 8 )
                {
                  v42 = &unk_24CD2C;
                  goto LABEL_104;
                }
              }
              while ( *(_DWORD *)(v21 + 16) != *(_DWORD *)(v46 + 24) );
              drm_connector_list_iter_end(v51);
              mutex_unlock(v45 + 432);
              *(_DWORD *)(*(_QWORD *)(v18 + 2008) + 20LL) = 1 << *(_DWORD *)(v46 + 68);
              *(_DWORD *)(*(_QWORD *)(v18 + 2008) + 16LL) = 1 << *(_DWORD *)(v20 + 152);
              *(_QWORD *)(*(_QWORD *)(v20 + 2512) + 8LL) = v18;
              if ( !*(_DWORD *)(a1 + 2536) )
              {
                v28 = (_QWORD *)(v20 + 176);
                while ( 1 )
                {
                  v28 = (_QWORD *)*v28;
                  if ( v28 == (_QWORD *)(v20 + 176) )
                    break;
                  if ( (*((_BYTE *)v28 - 2) & 8) != 0 )
                  {
                    v24 = (const char *)(v28 - 8);
                    goto LABEL_67;
                  }
                }
LABEL_105:
                printk(&unk_235504, "sde_kms_cont_splash_config");
                goto LABEL_6;
              }
              if ( !v7 )
                goto LABEL_105;
              v22 = *(_QWORD *)(v7 + 8);
              if ( !*(_DWORD *)(v22 + 860) )
                goto LABEL_105;
              v23 = 0;
              v24 = nullptr;
              do
              {
                v25 = (_QWORD *)(*(_QWORD *)(v7 + 32) + 56 * v23);
                if ( *v25 )
                {
                  v26 = v25[3];
                  if ( (*(_BYTE *)(v26 + 9) & 1) != 0 || *(_BYTE *)(v25[2] + 9LL) == 1 )
                  {
                    v27 = (_QWORD *)(v20 + 176);
                    while ( 1 )
                    {
                      v27 = (_QWORD *)*v27;
                      if ( v27 == (_QWORD *)(v20 + 176) )
                        break;
                      if ( (drm_mode_equal(v26 + 144, v27 - 8) & 1) != 0 )
                      {
                        v24 = (const char *)(v27 - 8);
                        break;
                      }
                    }
                    v22 = *(_QWORD *)(v7 + 8);
                  }
                }
                ++v23;
              }
              while ( v23 < *(unsigned int *)(v22 + 860) );
LABEL_67:
              if ( !v24 )
                goto LABEL_105;
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "drm_mode->name:%s, type:0x%x, flags:0x%x, handoff_type:%d\n",
                  v24 + 80,
                  *((unsigned __int8 *)v24 + 62),
                  *((_DWORD *)v24 + 6),
                  *(_DWORD *)(a1 + 2536));
              *(_BYTE *)(*(_QWORD *)(v18 + 2008) + 9LL) = 1;
              v29 = drm_atomic_set_mode_for_crtc(*(_QWORD *)(v18 + 2008), v24);
              if ( v29 )
              {
                v4 = v29;
                v41 = &unk_2163B9;
                goto LABEL_101;
              }
              drm_mode_copy(*(_QWORD *)(v18 + 2008) + 24LL, v24);
              drm_mode_copy(v18 + 176, v24);
              v12 = v46;
              *(_BYTE *)(*(_QWORD *)(v18 + 2008) + 6904LL) = 1;
              sde_encoder_update_caps_for_cont_splash(v46, v48, 1u);
              sde_crtc_update_cont_splash_settings(v18);
              v30 = *(void (__fastcall **)(_QWORD))(v20 + 3120);
              if ( v30 )
              {
                v31 = *(_QWORD *)(v20 + 2760);
                if ( *((_DWORD *)v30 - 1) != -1066802076 )
                  __break(0x8228u);
                v30(v31);
              }
              *(_BYTE *)(*(_QWORD *)(v20 + 2512) + 3260LL) = 1;
              if ( !v48 || !v18 )
              {
                printk(&unk_2503C4, "_sde_kms_update_planes_for_cont_splash");
                v41 = &unk_23F84C;
                goto LABEL_100;
              }
              v32 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL);
              if ( *(_DWORD *)(v32 + 728) )
              {
                v33 = 0;
                v34 = *(unsigned int **)(v48 + 16);
                v50 = v48 + 48;
                v47 = *(unsigned int **)(v48 + 24);
                v49 = v48 + 56;
                do
                {
                  if ( v33 == 32 )
                    goto LABEL_110;
                  v36 = *(_QWORD *)(v32 + 736 + 8 * v33);
                  v37 = sde_plane_pipe(v36);
                  v38 = is_sde_plane_virtual(v36);
                  if ( (v38 & 1) != 0 )
                    v39 = v49;
                  else
                    v39 = v50;
                  if ( (*(_QWORD *)(v39 + 8 * ((unsigned __int64)v37 >> 6)) & (1LL << v37)) != 0 )
                  {
                    if ( v34
                      && (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))sde_plane_validate_src_addr)(
                                         v36,
                                         *((_QWORD *)v34 + 1),
                                         *v34)
                      && (!v47
                       || (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))sde_plane_validate_src_addr)(
                                          v36,
                                          *((_QWORD *)v47 + 1),
                                          *v47)) )
                    {
                      printk(&unk_253E4C, "_sde_kms_update_planes_for_cont_splash");
                    }
                    else
                    {
                      *(_QWORD *)(*(_QWORD *)(v36 + 1768) + 8LL) = v18;
                      *(_DWORD *)(*(_QWORD *)(v18 + 2008) + 12LL) |= 1 << *(_DWORD *)(v36 + 1756);
                      v40 = _drm_debug;
                      *(_BYTE *)(*(_QWORD *)(v36 + 1768) + 2760LL) = 1;
                      if ( (v40 & 4) != 0 )
                      {
                        if ( v36 )
                          v35 = *(_DWORD *)(v36 + 104);
                        else
                          v35 = -1;
                        _drm_dev_dbg(
                          0,
                          0,
                          0,
                          "set crtc:%d for plane:%d rect:%d\n",
                          *(_DWORD *)(v18 + 112),
                          v35,
                          v38 & 1);
                      }
                    }
                  }
                  ++v33;
                }
                while ( v33 < *(unsigned int *)(v32 + 728) );
                v7 = v43;
                v11 = v44;
                v4 = 0;
                v13 = a1 + 2712;
                v12 = v46;
              }
              else
              {
                v7 = v43;
                v4 = 0;
                v13 = a1 + 2712;
              }
            }
          }
          else
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "display->name = %s splash not enabled\n", *(const char **)(v14 + 32));
            sde_kms_inform_cont_splash_res_disable(a1, v14);
            v12 = v46;
          }
          if ( ++v11 >= *(int *)(a1 + 3568) )
            goto LABEL_7;
        }
      }
      v4 = 0;
    }
    else
    {
      printk(&unk_2693AC, a2);
      sde_kms_inform_cont_splash_res_disable(a1, 0);
      v4 = 0;
    }
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v4;
}
