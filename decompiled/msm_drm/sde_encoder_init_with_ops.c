__int64 __fastcall sde_encoder_init_with_ops(__int64 a1, int *a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x25
  __int64 v8; // x23
  __int64 v9; // x19
  int v10; // w0
  int v11; // w8
  int v12; // w8
  int v13; // w4
  int v14; // w8
  char v15; // w9
  __int64 v16; // x8
  unsigned __int64 v17; // x8
  __int64 v18; // x28
  _DWORD *v19; // x8
  unsigned __int64 v20; // x0
  __int64 v21; // x8
  int v22; // w6
  __int64 v23; // x8
  unsigned int v24; // w9
  _DWORD *v25; // x8
  int v26; // w9
  __int64 v27; // x9
  void *v28; // x0
  const char *v29; // x1
  unsigned int v30; // w4
  unsigned __int64 v31; // x0
  unsigned __int64 v32; // x0
  unsigned __int64 v33; // x0
  int v34; // w8
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 v37; // x9
  __int64 v38; // x8
  __int64 v39; // x9
  __int64 v40; // x8
  __int64 v41; // x9
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 v44; // x8
  int v45; // w8
  __int64 v46; // x0
  void (*v47)(void); // x8
  __int64 v48; // x0
  void (*v49)(void); // x8
  __int64 v50; // x0
  void (*v51)(void); // x8
  __int64 v52; // x0
  void (*v53)(void); // x8
  int v54; // w8
  char v55; // w8
  _QWORD *v56; // x0
  char v57; // w8
  char v58; // w9
  const char *v59; // x1
  unsigned __int64 StatusReg; // x22
  __int64 v61; // x24
  unsigned int v63; // [xsp+4h] [xbp-ACh]
  __int64 v64; // [xsp+10h] [xbp-A0h]
  __int64 v65; // [xsp+18h] [xbp-98h]
  __int64 v66; // [xsp+38h] [xbp-78h] BYREF
  __int64 v67; // [xsp+40h] [xbp-70h]
  __int64 (__fastcall *v68)(); // [xsp+48h] [xbp-68h]
  __int64 (__fastcall *v69)(); // [xsp+50h] [xbp-60h]
  __int64 (__fastcall *v70)(); // [xsp+58h] [xbp-58h]
  __int64 (__fastcall *v71)(); // [xsp+60h] [xbp-50h]
  __int64 (__fastcall *v72)(__int64, _DWORD *, __int64, __int64); // [xsp+68h] [xbp-48h]
  __int128 v73; // [xsp+70h] [xbp-40h]
  __int64 v74; // [xsp+80h] [xbp-30h]
  __int64 v75; // [xsp+88h] [xbp-28h]
  char s[8]; // [xsp+90h] [xbp-20h] BYREF
  int v77; // [xsp+98h] [xbp-18h]
  __int64 v78; // [xsp+A0h] [xbp-10h]

  v6 = a1;
  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 56) + 8LL);
  v9 = _kmalloc_cache_noprof(kthread_unpark, 3520, 5416);
  if ( !v9 )
  {
LABEL_237:
    v10 = -12;
    goto LABEL_238;
  }
  while ( 1 )
  {
    v10 = hfi_encoder_init(v6, (_QWORD *)v9);
    if ( v10 )
      goto LABEL_238;
    if ( a3 )
      *(_QWORD *)(v9 + 4944) = *(_QWORD *)a3;
    v77 = 0;
    *(_QWORD *)s = 0;
    _mutex_init(v9 + 528, "&sde_enc->enc_lock", &sde_encoder_init_with_ops___key);
    v74 = 0;
    v75 = 0;
    v73 = 0u;
    v71 = nullptr;
    v72 = nullptr;
    v69 = nullptr;
    v70 = nullptr;
    v67 = 0;
    v68 = nullptr;
    v66 = 0;
    if ( !v8 )
    {
      printk(&unk_25E7C8, "sde_encoder_setup_display");
      goto LABEL_223;
    }
    a3 = (unsigned int)a2[1];
    v68 = nullptr;
    v69 = nullptr;
    v70 = nullptr;
    v71 = nullptr;
    v72 = nullptr;
    v73 = 0u;
    v66 = v8;
    v67 = v9;
    if ( (a3 & 0x80) == 0 )
    {
      v72 = sde_encoder_get_qsync_fps_callback;
      v70 = sde_encoder_underrun_callback;
      v71 = sde_encoder_frame_done_callback;
      v68 = sde_encoder_vblank_callback;
      v69 = sde_encoder_empulse_callback;
    }
    v74 = v9 + 128;
    v75 = v9 + 136;
    *(_DWORD *)(v9 + 804) = 0;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "\n");
    v11 = *a2;
    v65 = v6;
    if ( *a2 <= 13 )
    {
      if ( v11 == 10 )
      {
        v6 = 10;
        if ( (a2[1] & 0x20) != 0 )
          v12 = 7;
        else
          v12 = 2;
        goto LABEL_27;
      }
      if ( v11 != 11 )
      {
LABEL_225:
        printk(&unk_231936, "sde_encoder_setup_display");
LABEL_223:
        v10 = -22;
LABEL_238:
        LODWORD(v9) = v10;
        printk(&unk_25ABD7, "sde_encoder_init_with_ops");
        v9 = (int)v9;
        goto LABEL_239;
      }
      v6 = 3;
    }
    else
    {
      if ( v11 == 16 )
      {
        v12 = 6;
        v6 = 1;
        goto LABEL_27;
      }
      if ( v11 == 15 )
      {
        if ( (a3 & 0x80) != 0 )
          v6 = 257;
        else
          v6 = 256;
        v12 = 5;
        goto LABEL_27;
      }
      if ( v11 != 14 )
        goto LABEL_225;
      v6 = 10;
    }
    v12 = 2;
LABEL_27:
    v63 = v12;
    v13 = a2[3];
    if ( !v13 )
    {
      __break(0x800u);
      v13 = a2[3];
    }
    v14 = a2[34];
    v15 = _drm_debug;
    v64 = a4;
    *(_DWORD *)(v9 + 188) = v13;
    *(_DWORD *)(v9 + 192) = v14;
    if ( (v15 & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "dsi_info->num_of_h_tiles %d\n", v13);
    if ( (a3 & 0x80) == 0 )
    {
      *(_BYTE *)(v9 + 836) = (*(_QWORD *)(*(_QWORD *)(v8 + 152) + 22008LL) & 0x200) != 0;
      v16 = *(_QWORD *)(v8 + 152);
      if ( (*(_QWORD *)(v16 + 680) & 0x4000) != 0 )
      {
        *(_BYTE *)(v9 + 4936) = *((_BYTE *)a2 + 156);
        v16 = *(_QWORD *)(v8 + 152);
      }
      *(_BYTE *)(v9 + 837) = (*(_QWORD *)(v16 + 22008) & 0x4000) != 0;
    }
    *(_BYTE *)(v9 + 4922) = ((unsigned __int16)WORD2(*(_QWORD *)(*(_QWORD *)(v8 + 152) + 22008LL)) >> 8) & 1;
    mutex_lock(v9 + 528);
    LODWORD(v17) = a2[3];
    if ( !(_DWORD)v17 )
    {
LABEL_157:
      a3 = 0;
      goto LABEL_158;
    }
    a4 = 0;
    v18 = v9 + 200;
    while ( 1 )
    {
      if ( a4 == 2 )
        goto LABEL_235;
      if ( (unsigned int)v17 < 2 )
      {
        if ( *(_BYTE *)(v9 + 4936) == 1 )
        {
          if ( *((_BYTE *)a2 + 157) )
            v22 = 1;
          else
            v22 = 2;
        }
        else
        {
          v22 = 0;
        }
      }
      else if ( a4 )
      {
        v22 = 3;
      }
      else if ( *(_BYTE *)(v9 + 4936) == 1 && *((_BYTE *)a2 + 157) != 1 )
      {
        v22 = 2;
      }
      else
      {
        v22 = 1;
      }
      a3 = (unsigned int)a2[a4 + 4];
      LODWORD(v73) = v22;
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "h_tile_instance %d = %d, split_role %d\n", a4, a3, v22);
      v19 = *(_DWORD **)(v9 + 4944);
      if ( v19 )
      {
        if ( *(v19 - 1) != -1670429996 )
          __break(0x8228u);
        v20 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64 *))v19)((unsigned int)v6, (unsigned int)a3, &v66);
        if ( !v20 )
        {
          printk(&unk_25AC80, "sde_encoder_setup_display");
          goto LABEL_43;
        }
        v21 = *(unsigned int *)(v9 + 196);
        if ( (unsigned int)v21 > 3 )
          goto LABEL_235;
        goto LABEL_42;
      }
      if ( (_DWORD)v6 == 256 )
      {
        v23 = *(_QWORD *)(v8 + 152);
        v24 = *(_DWORD *)(v23 + 14272);
        DWORD1(v73) = 10;
        if ( v24 <= (unsigned int)a3 )
        {
          DWORD2(v73) = 5;
          goto LABEL_234;
        }
        if ( (unsigned int)a3 >= 0xC )
          goto LABEL_235;
        DWORD2(v73) = *(_DWORD *)(v23 + 88LL * (unsigned int)a3 + 14296);
        if ( DWORD2(v73) == 5 )
          goto LABEL_234;
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(v9 + 24));
        if ( (unsigned int)(*(_DWORD *)(v9 + 196) - 3) <= 0xFFFFFFFB )
        {
          v59 = "sde_encoder_virt_add_phys_enc_wb";
LABEL_229:
          printk(&unk_220BC5, v59);
LABEL_230:
          a3 = 4294967274LL;
LABEL_231:
          printk(&unk_25AC80, "sde_encoder_setup_display");
          goto LABEL_158;
        }
        v20 = sde_encoder_phys_wb_init(&v66);
        if ( !v20 || v20 >= 0xFFFFFFFFFFFFF001LL )
        {
          a3 = v20;
          v28 = &unk_265936;
          v29 = "sde_encoder_virt_add_phys_enc_wb";
          goto LABEL_155;
        }
        v21 = *(unsigned int *)(v9 + 196);
        if ( (unsigned int)v21 >= 4 )
          goto LABEL_235;
LABEL_42:
        *(_QWORD *)(v18 + 8 * v21) = v20;
        *(_DWORD *)(v9 + 196) = v21 + 1;
        goto LABEL_43;
      }
      if ( (_DWORD)v6 == 257 )
      {
        *(_QWORD *)((char *)&v73 + 4) = 0x50000000ALL;
        goto LABEL_124;
      }
      v25 = *(_DWORD **)(v8 + 152);
      DWORD2(v73) = 5;
      v26 = v25[3350];
      if ( !v26 )
        goto LABEL_233;
      if ( v25[3364] == (_DWORD)v6 && v25[3365] == (_DWORD)a3 )
      {
        v27 = 3352;
        goto LABEL_123;
      }
      if ( v26 == 1 )
        goto LABEL_233;
      if ( v25[3382] == (_DWORD)v6 && v25[3383] == (_DWORD)a3 )
      {
        v27 = 3370;
        goto LABEL_123;
      }
      if ( v26 == 2 )
        goto LABEL_233;
      if ( v25[3400] == (_DWORD)v6 && v25[3401] == (_DWORD)a3 )
      {
        v27 = 3388;
        goto LABEL_123;
      }
      if ( v26 == 3 )
        goto LABEL_233;
      if ( v25[3418] == (_DWORD)v6 && v25[3419] == (_DWORD)a3 )
      {
        v27 = 3406;
        goto LABEL_123;
      }
      if ( v26 == 4 )
        goto LABEL_233;
      if ( v25[3436] == (_DWORD)v6 && v25[3437] == (_DWORD)a3 )
      {
        v27 = 3424;
        goto LABEL_123;
      }
      if ( v26 == 5 )
        goto LABEL_233;
      if ( v25[3454] == (_DWORD)v6 && v25[3455] == (_DWORD)a3 )
      {
        v27 = 3442;
        goto LABEL_123;
      }
      if ( v26 == 6 )
        goto LABEL_233;
      if ( v25[3472] == (_DWORD)v6 && v25[3473] == (_DWORD)a3 )
      {
        v27 = 3460;
        goto LABEL_123;
      }
      if ( v26 == 7 )
        goto LABEL_233;
      if ( v25[3490] == (_DWORD)v6 && v25[3491] == (_DWORD)a3 )
      {
        v27 = 3478;
        goto LABEL_123;
      }
      if ( v26 == 8 )
        goto LABEL_233;
      if ( v25[3508] == (_DWORD)v6 && v25[3509] == (_DWORD)a3 )
      {
        v27 = 3496;
        goto LABEL_123;
      }
      if ( v26 == 9 )
        goto LABEL_233;
      if ( v25[3526] == (_DWORD)v6 && v25[3527] == (_DWORD)a3 )
      {
        v27 = 3514;
        goto LABEL_123;
      }
      if ( v26 == 10 )
        goto LABEL_233;
      if ( v25[3544] == (_DWORD)v6 && v25[3545] == (_DWORD)a3 )
      {
        v27 = 3532;
        goto LABEL_123;
      }
      if ( v26 == 11 )
        goto LABEL_233;
      if ( v25[3562] != (_DWORD)v6 || v25[3563] != (_DWORD)a3 )
        break;
      v27 = 3550;
LABEL_123:
      DWORD1(v73) = v25[v27 + 4];
      if ( DWORD1(v73) == 10 )
        goto LABEL_234;
LABEL_124:
      a3 = (unsigned int)a2[1];
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(v9 + 24));
      v30 = *(_DWORD *)(v9 + 196);
      if ( v30 - 2 <= 0xFFFFFFFB )
      {
        v59 = "sde_encoder_virt_add_phys_encs";
        goto LABEL_229;
      }
      if ( (a3 & 0x80) != 0 )
      {
        v31 = sde_encoder_phys_vid_init(&v66, 1);
        if ( !v31 || v31 >= 0xFFFFFFFFFFFFF001LL )
        {
          a3 = v31;
          v28 = &unk_268EC0;
          v29 = "sde_encoder_virt_add_phys_encs";
          goto LABEL_155;
        }
        v30 = *(_DWORD *)(v9 + 196);
        if ( v30 >= 4 )
          goto LABEL_235;
        *(_QWORD *)(v9 + 296 + 8LL * v30) = v31;
      }
      if ( (a3 & 1) != 0 )
      {
        v32 = sde_encoder_phys_vid_init(&v66, 0);
        if ( !v32 || v32 >= 0xFFFFFFFFFFFFF001LL )
        {
          a3 = v32;
          v28 = &unk_256FA7;
          v29 = "sde_encoder_virt_add_phys_encs";
          goto LABEL_155;
        }
        v30 = *(_DWORD *)(v9 + 196);
        if ( v30 > 3 )
          goto LABEL_235;
        *(_QWORD *)(v9 + 232 + 8LL * v30) = v32;
      }
      if ( (a3 & 2) != 0 )
      {
        v33 = sde_encoder_phys_cmd_init(&v66);
        if ( v33 && v33 < 0xFFFFFFFFFFFFF001LL )
        {
          v30 = *(_DWORD *)(v9 + 196);
          if ( v30 > 3 )
            goto LABEL_235;
          *(_QWORD *)(v9 + 264 + 8LL * v30) = v33;
          goto LABEL_142;
        }
        a3 = v33;
        v28 = &unk_242C31;
        v29 = "sde_encoder_virt_add_phys_encs";
LABEL_155:
        printk(v28, v29);
        if ( !a3 )
          goto LABEL_230;
        goto LABEL_231;
      }
LABEL_142:
      v34 = a2[2];
      if ( v34 == 2 )
      {
        if ( v30 >= 4 )
          goto LABEL_235;
        v35 = 264;
      }
      else if ( v34 == 1 )
      {
        if ( v30 >= 4 )
          goto LABEL_235;
        v35 = 232;
      }
      else
      {
        if ( v30 > 3 )
          goto LABEL_235;
        v35 = 296;
      }
      if ( (v35 + 8 * (unsigned __int64)v30) >> 3 > 0x2A4 )
        goto LABEL_236;
      v36 = *(_QWORD *)(v9 + v35 + 8LL * v30);
      *(_DWORD *)(v9 + 196) = v30 + 1;
      *(_QWORD *)(v18 + 8LL * v30) = v36;
LABEL_43:
      v17 = (unsigned int)a2[3];
      if ( ++a4 >= v17 )
        goto LABEL_157;
    }
    if ( v26 == 12 )
      break;
LABEL_235:
    __break(0x5512u);
LABEL_236:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v61 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sde_encoder_init_with_ops__alloc_tag;
    v9 = _kmalloc_cache_noprof(kthread_unpark, 3520, 5416);
    *(_QWORD *)(StatusReg + 80) = v61;
    if ( !v9 )
      goto LABEL_237;
  }
LABEL_233:
  DWORD1(v73) = 10;
LABEL_234:
  printk(&unk_2124BD, "sde_encoder_setup_display");
  a3 = 4294967274LL;
LABEL_158:
  if ( *(_DWORD *)(v9 + 196) )
  {
    v37 = *(_QWORD *)(v9 + 232);
    v38 = *(_QWORD *)(v9 + 264);
    if ( v37 )
    {
      *(_DWORD *)(v37 + 860) = 0;
      *(_DWORD *)(v37 + 872) = 0;
    }
    if ( v38 )
    {
      *(_DWORD *)(v38 + 860) = 0;
      *(_DWORD *)(v38 + 872) = 0;
    }
    if ( *(_DWORD *)(v9 + 196) >= 2u )
    {
      v39 = *(_QWORD *)(v9 + 240);
      v40 = *(_QWORD *)(v9 + 272);
      if ( v39 )
      {
        *(_DWORD *)(v39 + 860) = 0;
        *(_DWORD *)(v39 + 872) = 0;
      }
      if ( v40 )
      {
        *(_DWORD *)(v40 + 860) = 0;
        *(_DWORD *)(v40 + 872) = 0;
      }
      if ( *(_DWORD *)(v9 + 196) >= 3u )
      {
        v41 = *(_QWORD *)(v9 + 248);
        v42 = *(_QWORD *)(v9 + 280);
        if ( v41 )
        {
          *(_DWORD *)(v41 + 860) = 0;
          *(_DWORD *)(v41 + 872) = 0;
        }
        if ( v42 )
        {
          *(_DWORD *)(v42 + 860) = 0;
          *(_DWORD *)(v42 + 872) = 0;
        }
        if ( *(_DWORD *)(v9 + 196) >= 4u )
        {
          v43 = *(_QWORD *)(v9 + 256);
          v44 = *(_QWORD *)(v9 + 288);
          if ( v43 )
          {
            *(_DWORD *)(v43 + 860) = 0;
            *(_DWORD *)(v43 + 872) = 0;
          }
          if ( v44 )
          {
            *(_DWORD *)(v44 + 860) = 0;
            *(_DWORD *)(v44 + 872) = 0;
          }
          if ( *(_DWORD *)(v9 + 196) > 4u )
            goto LABEL_235;
        }
      }
    }
  }
  mutex_unlock(v9 + 528);
  v10 = a3;
  if ( (_DWORD)a3 )
    goto LABEL_238;
  *(_QWORD *)(v9 + 328) = 0;
  *(_DWORD *)(v9 + 128) = 0;
  _mutex_init(v9 + 136, "&sde_enc->vblank_ctl_lock", &sde_encoder_init_with_ops___key_100);
  *(_DWORD *)(v9 + 576) = 0;
  *(_DWORD *)(v9 + 580) = 0;
  *(_DWORD *)(v9 + 584) = 0;
  *(_DWORD *)(v9 + 588) = 0;
  drm_encoder_init(v65, v9, &sde_encoder_funcs, v63, 0);
  v45 = *(_DWORD *)(v9 + 196);
  *(_QWORD *)(v9 + 112) = &sde_encoder_helper_funcs;
  if ( v45 )
  {
    v46 = *(_QWORD *)(v9 + 200);
    if ( v46 )
    {
      v47 = *(void (**)(void))(v46 + 32);
      if ( v47 )
      {
        if ( *((_DWORD *)v47 - 1) != -1375811177 )
          __break(0x8228u);
        v47();
      }
    }
    if ( *(_DWORD *)(v9 + 196) >= 2u )
    {
      v48 = *(_QWORD *)(v9 + 208);
      if ( v48 )
      {
        v49 = *(void (**)(void))(v48 + 32);
        if ( v49 )
        {
          if ( *((_DWORD *)v49 - 1) != -1375811177 )
            __break(0x8228u);
          v49();
        }
      }
      if ( *(_DWORD *)(v9 + 196) >= 3u )
      {
        v50 = *(_QWORD *)(v9 + 216);
        if ( v50 )
        {
          v51 = *(void (**)(void))(v50 + 32);
          if ( v51 )
          {
            if ( *((_DWORD *)v51 - 1) != -1375811177 )
              __break(0x8228u);
            v51();
          }
        }
        if ( *(_DWORD *)(v9 + 196) >= 4u )
        {
          v52 = *(_QWORD *)(v9 + 224);
          if ( v52 )
          {
            v53 = *(void (**)(void))(v52 + 32);
            if ( v53 )
            {
              if ( *((_DWORD *)v53 - 1) != -1375811177 )
                __break(0x8228u);
              v53();
            }
          }
          if ( *(_DWORD *)(v9 + 196) > 4u )
            goto LABEL_235;
        }
      }
    }
  }
  v54 = a2[1];
  if ( !*(_QWORD *)(v9 + 4944) && (v54 & 0x80) == 0 )
  {
    snprintf(s, 0xCu, "rsc_enc%u", *(_DWORD *)(v9 + 24));
    v55 = _drm_debug;
    *(_QWORD *)(v9 + 624) = 0;
    if ( (v55 & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "sde rsc client create failed :%ld\n", 0);
    v54 = a2[1];
    *(_QWORD *)(v9 + 624) = 0;
  }
  if ( ((v54 & 2) != 0 || *((_BYTE *)a2 + 109) == 1) && *(_BYTE *)(v9 + 837) == 1 )
  {
    if ( *(_QWORD *)(v9 + 1304) )
    {
      printk(&unk_227404, "_sde_encoder_input_handler");
    }
    else
    {
      v56 = (_QWORD *)_kmalloc_cache_noprof(_drm_dev_dbg, 3520, 128);
      if ( v56 )
      {
        v56[1] = &sde_encoder_input_event_handler;
        *(_QWORD *)(v9 + 1304) = v56;
        v56[5] = sde_encoder_input_connect;
        v56[6] = sde_encoder_input_disconnect;
        v56[9] = "sde";
        v56[10] = &sde_input_ids;
        goto LABEL_216;
      }
    }
    printk(&unk_26C807, "sde_encoder_init_with_ops");
  }
LABEL_216:
  if ( *(_BYTE *)(*(_QWORD *)(v8 + 152) + 19920LL) == 1 )
    *(_DWORD *)(v9 + 1316) = 2;
  _mutex_init(v9 + 896, "&sde_enc->off_work_lock", &sde_encoder_init_with_ops___key_105);
  _mutex_init(v9 + 840, "&sde_enc->rc_lock", &sde_encoder_init_with_ops___key_107);
  v57 = *((_BYTE *)a2 + 4);
  *(_BYTE *)(v9 + 1312) = 0;
  *(_BYTE *)(v9 + 501) = 0;
  if ( (v57 & 0x80) == 0 )
  {
    *(_QWORD *)(v9 + 976) = 0;
    *(_QWORD *)(v9 + 968) = 0;
    *(_QWORD *)(v9 + 944) = v9 + 944;
    *(_QWORD *)(v9 + 952) = v9 + 944;
    *(_QWORD *)(v9 + 960) = sde_encoder_off_work;
    init_timer_key(v9 + 984, &kthread_delayed_work_timer_fn, 0x200000, 0, 0);
    *(_QWORD *)(v9 + 1096) = 0;
    *(_QWORD *)(v9 + 1088) = 0;
    *(_QWORD *)(v9 + 1064) = v9 + 1064;
    *(_QWORD *)(v9 + 1072) = v9 + 1064;
    *(_QWORD *)(v9 + 1080) = sde_encoder_input_event_work_handler;
    *(_QWORD *)(v9 + 1048) = 0;
    *(_QWORD *)(v9 + 1056) = 0;
    *(_QWORD *)(v9 + 1024) = v9 + 1024;
    *(_QWORD *)(v9 + 1032) = v9 + 1024;
    *(_QWORD *)(v9 + 1040) = sde_encoder_early_wakeup_work_handler;
    *(_QWORD *)(v9 + 1128) = 0;
    *(_QWORD *)(v9 + 1136) = 0;
    *(_QWORD *)(v9 + 1104) = v9 + 1104;
    *(_QWORD *)(v9 + 1112) = v9 + 1104;
    *(_QWORD *)(v9 + 1120) = sde_encoder_esd_trigger_work_handler;
  }
  *(_QWORD *)(v9 + 1176) = 0;
  *(_QWORD *)(v9 + 1168) = 0;
  *(_QWORD *)(v9 + 1144) = v9 + 1144;
  *(_QWORD *)(v9 + 1152) = v9 + 1144;
  *(_QWORD *)(v9 + 1160) = sde_encoder_handle_self_refresh;
  *(_QWORD *)(v9 + 1208) = 0;
  *(_QWORD *)(v9 + 1216) = 0;
  *(_QWORD *)(v9 + 1184) = v9 + 1184;
  *(_QWORD *)(v9 + 1192) = v9 + 1184;
  *(_QWORD *)(v9 + 1200) = sde_encoder_cmd_backlight_update;
  *(_QWORD *)(v9 + 1248) = 0;
  *(_QWORD *)(v9 + 1256) = 0;
  *(_QWORD *)(v9 + 1224) = v9 + 1224;
  *(_QWORD *)(v9 + 1232) = v9 + 1224;
  *(_QWORD *)(v9 + 1240) = sde_encoder_cmd_backlight_sr_work_handler;
  init_timer_key(v9 + 1264, &kthread_delayed_work_timer_fn, 0x200000, 0, 0);
  memcpy((void *)(v9 + 640), a2, 0xA0u);
  v58 = _drm_debug;
  *(_DWORD *)(v9 + 4952) = 0;
  *(_QWORD *)(v9 + 4960) = v64;
  *(_BYTE *)(v9 + 4968) = 1;
  if ( (v58 & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d created\n", *(_DWORD *)(v9 + 24));
LABEL_239:
  _ReadStatusReg(SP_EL0);
  return v9;
}
