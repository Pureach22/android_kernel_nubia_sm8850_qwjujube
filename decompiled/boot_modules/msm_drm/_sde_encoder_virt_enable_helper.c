__int64 __fastcall sde_encoder_virt_enable_helper(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x9
  int v8; // w8
  __int64 v9; // x1
  __int64 v10; // x8
  void (__fastcall *v11)(__int64, __int64); // x10
  int v12; // w21
  __int64 v13; // x0
  __int64 v14; // x8
  void (__fastcall *v15)(_QWORD); // x9
  int v16; // w20
  __int64 v17; // x9
  int v18; // w8
  __int64 v19; // x8
  void (__fastcall *v20)(__int64, __int64); // x10
  int v21; // w20
  __int64 v22; // x0
  __int64 v23; // x1
  void (__fastcall *v24)(__int64, __int64); // x10
  int v25; // w20
  __int64 v26; // x1
  __int64 v27; // x8
  void (__fastcall *v28)(__int64, __int64, __int64); // x9
  int v29; // w20
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x8
  __int64 v33; // x9
  __int64 v34; // x8
  void (__fastcall *v35)(__int64, __int64); // x10
  __int64 v36; // x0
  unsigned int v37; // w8
  __int64 v38; // x0
  void (*v39)(void); // x9
  __int64 v40; // x0
  void (*v41)(void); // x9
  __int64 v42; // x0
  void (*v43)(void); // x9
  __int64 v44; // x0
  void (*v45)(void); // x8
  __int64 v46; // x8
  __int64 v47; // x8
  unsigned int disp_op; // w20
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 v51; // x24
  __int64 v52; // x21
  __int64 v53; // x22
  __int64 v54; // x23
  __int64 v55; // x25
  __int64 v56; // x26
  __int64 v57; // x27
  _DWORD *v58; // x8
  __int64 v59; // x0
  unsigned int v60; // w28
  _DWORD *v61; // x8
  __int64 v62; // x26
  __int64 v63; // x25
  unsigned int v64; // w23
  __int64 v65; // x20
  unsigned int v66; // w9
  __int64 v67; // x1
  void *v68; // x0
  void *v69; // x0
  void *v70; // x0
  __int64 v71; // [xsp+20h] [xbp-20h]
  __int64 v72; // [xsp+28h] [xbp-18h]
  int v73; // [xsp+3Ch] [xbp-4h]

  if ( !*(_QWORD *)a1 )
    return printk(&unk_27D28A, "_sde_encoder_virt_enable_helper");
  v1 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v1 )
    return printk(&unk_27D28A, "_sde_encoder_virt_enable_helper");
  if ( !a1 )
    return printk(&unk_26FCAB, "sde_encoder_get_kms");
  if ( !*(_QWORD *)(v1 + 8) )
  {
    printk(&unk_234896, "sde_encoder_get_kms");
    result = 0;
    v4 = *(_QWORD *)a1;
    if ( *(_QWORD *)a1 )
      goto LABEL_6;
    return printk(&unk_26FCAB, "sde_encoder_get_kms");
  }
  result = sde_kms_get_disp_op();
  v4 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
    return printk(&unk_26FCAB, "sde_encoder_get_kms");
LABEL_6:
  v5 = *(_QWORD *)(v4 + 56);
  if ( !v5 )
    return printk(&unk_234896, "sde_encoder_get_kms");
  v6 = *(_QWORD *)(v5 + 8);
  if ( !v6 )
    return printk(&unk_234896, "sde_encoder_get_kms");
  v7 = *(_QWORD *)(a1 + 328);
  if ( v7 )
  {
    if ( (*(_BYTE *)(a1 + 644) & 0x80) != 0 )
      goto LABEL_89;
    v8 = *(_DWORD *)(a1 + 640);
    v9 = v8 == 10;
    if ( (v8 & 0xFFFFFFFE) == 0xA )
    {
      v10 = *(_QWORD *)(v7 + 408);
      if ( v10 )
      {
        if ( (unsigned int)result >= 3 )
          goto LABEL_140;
        v11 = *(void (__fastcall **)(__int64, __int64))(v10 + 8LL * (unsigned int)result + 248);
        if ( v11 )
        {
          v12 = result;
          v13 = *(_QWORD *)(v7 + 408);
          if ( *((_DWORD *)v11 - 1) != 872184471 )
            __break(0x822Au);
          v11(v13, v9);
          v7 = *(_QWORD *)(a1 + 328);
          LODWORD(result) = v12;
        }
      }
    }
    v14 = *(_QWORD *)(v7 + 408);
    if ( v14 )
    {
      if ( (unsigned int)result > 2 )
        goto LABEL_140;
      v15 = *(void (__fastcall **)(_QWORD))(v14 + 8LL * (unsigned int)result + 224);
      if ( v15 )
      {
        v9 = *(_QWORD *)(v6 + 152);
        if ( !v9 || (*(_BYTE *)(v9 + 20120) & 1) == 0 )
        {
          v16 = result;
          if ( *((_DWORD *)v15 - 1) != 422924813 )
            __break(0x8229u);
          v15(v14);
          LODWORD(result) = v16;
        }
      }
    }
    if ( *(_BYTE *)(a1 + 4936) == 1 )
    {
      v17 = *(_QWORD *)(a1 + 328);
      if ( v17 )
      {
        v18 = *(_DWORD *)(v17 + 664);
        if ( v18 == 2 )
        {
          v32 = *(_QWORD *)(v17 + 416);
          if ( !v32 )
            goto LABEL_56;
          if ( (unsigned int)result > 2 )
            goto LABEL_140;
          v28 = *(void (__fastcall **)(__int64, __int64, __int64))(v32 + 8LL * (unsigned int)result + 1664);
          if ( !v28 )
            goto LABEL_56;
          v29 = result;
          v30 = v32;
          v31 = 0;
        }
        else
        {
          if ( v18 != 1 )
            goto LABEL_56;
          v19 = *(_QWORD *)(v17 + 408);
          if ( v19 )
          {
            if ( (unsigned int)result > 2 )
              goto LABEL_140;
            v20 = *(void (__fastcall **)(__int64, __int64))(v19 + 8LL * (unsigned int)result + 464);
            if ( !v20 )
              goto LABEL_35;
            v21 = result;
            v22 = *(_QWORD *)(v17 + 408);
            v23 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v17 + 424) + 32LL) - 1);
            if ( *((_DWORD *)v20 - 1) != 872184471 )
              __break(0x822Au);
            v20(v22, v23);
            v17 = *(_QWORD *)(a1 + 328);
            LODWORD(result) = v21;
            v19 = *(_QWORD *)(v17 + 408);
            if ( v19 )
            {
LABEL_35:
              v24 = *(void (__fastcall **)(__int64, __int64))(v19 + 8LL * (unsigned int)result + 488);
              if ( v24 )
              {
                v25 = result;
                v26 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v17 + 424) + 32LL) - 1);
                if ( *((_DWORD *)v24 - 1) != 872184471 )
                  __break(0x822Au);
                v24(v19, v26);
                v17 = *(_QWORD *)(a1 + 328);
                LODWORD(result) = v25;
              }
            }
          }
          v27 = *(_QWORD *)(v17 + 416);
          if ( !v27 )
            goto LABEL_56;
          if ( (unsigned int)result > 2 )
            goto LABEL_140;
          v28 = *(void (__fastcall **)(__int64, __int64, __int64))(v27 + 8LL * (unsigned int)result + 1664);
          if ( !v28 )
            goto LABEL_56;
          v29 = result;
          v30 = v27;
          v31 = 1;
        }
        if ( *((_DWORD *)v28 - 1) != 128872864 )
          __break(0x8229u);
        v28(v30, v31, 1);
        LODWORD(result) = v29;
      }
    }
LABEL_56:
    v33 = *(_QWORD *)(a1 + 328);
    v34 = *(_QWORD *)(v33 + 416);
    if ( !v34 )
    {
LABEL_64:
      sde_encoder_update_vsync_source(a1, (unsigned __int8 *)(a1 + 640));
      if ( *(_BYTE *)(a1 + 751) == 1 )
      {
        v37 = *(_DWORD *)(a1 + 196);
        if ( v37 )
        {
          v38 = *(_QWORD *)(a1 + 200);
          if ( v38 )
          {
            v39 = *(void (**)(void))(v38 + 248);
            if ( v39 )
            {
              if ( *((_DWORD *)v39 - 1) != 1595431362 )
                __break(0x8229u);
              v39();
              v37 = *(_DWORD *)(a1 + 196);
            }
          }
          if ( v37 >= 2 )
          {
            v40 = *(_QWORD *)(a1 + 208);
            if ( v40 )
            {
              v41 = *(void (**)(void))(v40 + 248);
              if ( v41 )
              {
                if ( *((_DWORD *)v41 - 1) != 1595431362 )
                  __break(0x8229u);
                v41();
                v37 = *(_DWORD *)(a1 + 196);
              }
            }
            if ( v37 >= 3 )
            {
              v42 = *(_QWORD *)(a1 + 216);
              if ( v42 )
              {
                v43 = *(void (**)(void))(v42 + 248);
                if ( v43 )
                {
                  if ( *((_DWORD *)v43 - 1) != 1595431362 )
                    __break(0x8229u);
                  v43();
                  v37 = *(_DWORD *)(a1 + 196);
                }
              }
              if ( v37 >= 4 )
              {
                v44 = *(_QWORD *)(a1 + 224);
                if ( v44 )
                {
                  v45 = *(void (**)(void))(v44 + 248);
                  if ( v45 )
                  {
                    if ( *((_DWORD *)v45 - 1) != 1595431362 )
                      __break(0x8228u);
                    v45();
                  }
                }
              }
            }
          }
        }
      }
LABEL_89:
      v46 = *(_QWORD *)(a1 + 328);
      if ( v46 && (*(_BYTE *)(v46 + 2289) & 1) != 0 )
        goto LABEL_133;
      if ( *(_QWORD *)a1 )
      {
        v47 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
        if ( v47 && *(_QWORD *)(v47 + 8) )
        {
          disp_op = sde_kms_get_disp_op();
          v49 = *(_QWORD *)(a1 + 328);
          if ( !v49 )
            goto LABEL_129;
          goto LABEL_95;
        }
        v68 = &unk_234896;
      }
      else
      {
        v68 = &unk_26FCAB;
      }
      printk(v68, "sde_encoder_get_kms");
      disp_op = 0;
      v49 = *(_QWORD *)(a1 + 328);
      if ( !v49 )
        goto LABEL_129;
LABEL_95:
      if ( *(_QWORD *)(v49 + 8) )
      {
        if ( *(_DWORD *)(a1 + 640) == 15 && (*(_BYTE *)(a1 + 644) & 0x80) == 0 )
          goto LABEL_133;
        if ( *(_QWORD *)a1 )
        {
          v50 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
          if ( v50 )
          {
            v51 = *(_QWORD *)(v50 + 8);
            if ( v51 )
            {
              if ( !*(_DWORD *)(*(_QWORD *)(v51 + 152) + 22144LL) )
                goto LABEL_133;
              v72 = *(_QWORD *)(v51 + 3528);
              if ( v72 )
              {
                v52 = *(unsigned int *)(a1 + 496);
                if ( (_DWORD)v52 )
                {
                  v53 = 0;
                  v54 = a1 + 336;
                  v55 = disp_op;
                  v73 = *(_DWORD *)(*(_QWORD *)(v51 + 152) + 22148LL);
                  v56 = *(_QWORD *)(*(_QWORD *)(a1 + 80) + 2008LL);
                  v71 = v56;
                  while ( 1 )
                  {
                    if ( v53 == 4 )
                      goto LABEL_140;
                    v57 = *(_QWORD *)(v54 + 8 * v53);
                    if ( !v57 )
                    {
                      printk(&unk_253772, "_sde_encoder_update_ppb_size");
                      goto LABEL_133;
                    }
                    if ( disp_op > 2 )
                      goto LABEL_140;
                    v58 = *(_DWORD **)(v57 + 8 * v55 + 448);
                    if ( v58 )
                      break;
                    v61 = *(_DWORD **)(v72 + 440 + 8 * v55);
                    if ( !v61 )
                    {
                      if ( !disp_op )
                        printk(&unk_2738AD, "_sde_encoder_update_ppb_size");
                      goto LABEL_107;
                    }
                    v62 = v55;
                    v63 = v54;
                    v64 = disp_op;
                    v65 = *(_QWORD *)(*(_QWORD *)(a1 + 328) + 8LL);
                    if ( !v65 || (v66 = *(_DWORD *)(v65 + 5124)) == 0 )
                    {
                      if ( (_drm_debug & 4) != 0 )
                        _drm_dev_dbg(0, 0, 0, "enc%d failed to get max horizantal resolution\n", *(_DWORD *)(a1 + 24));
                      goto LABEL_133;
                    }
                    v67 = *(unsigned int *)(v57 + 32);
                    v60 = v66 % (unsigned int)v52 * v73 / (unsigned int)v52 + v66 / (unsigned int)v52 * v73;
                    if ( *(v61 - 1) != -1231383397 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64, __int64, _QWORD))v61)(v72, v67, v60);
                    sde_evtlog_log(
                      sde_dbg_base_evtlog,
                      "_sde_encoder_update_ppb_size",
                      1602,
                      -1,
                      *(_DWORD *)(a1 + 24),
                      v53,
                      *(_DWORD *)(v57 + 32),
                      *(_DWORD *)(v65 + 5124),
                      v60);
                    disp_op = v64;
                    v54 = v63;
                    v55 = v62;
                    v56 = v71;
                    if ( (_drm_debug & 4) != 0 )
                      goto LABEL_122;
LABEL_107:
                    if ( v52 == ++v53 )
                      goto LABEL_133;
                  }
                  v59 = *(_QWORD *)(v54 + 8 * v53);
                  v60 = *(unsigned __int16 *)(v56 + 28) % (unsigned int)v52 * v73 / (unsigned int)v52
                      + *(unsigned __int16 *)(v56 + 28) / (unsigned int)v52 * v73;
                  if ( *(v58 - 1) != -873099604 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64, _QWORD))v58)(v59, v60);
                  sde_evtlog_log(
                    sde_dbg_base_evtlog,
                    "_sde_encoder_update_ppb_size",
                    1584,
                    -1,
                    *(_DWORD *)(a1 + 24),
                    v53,
                    *(_DWORD *)(v57 + 32),
                    *(unsigned __int16 *)(v56 + 28),
                    v60);
                  if ( (_drm_debug & 4) == 0 )
                    goto LABEL_107;
LABEL_122:
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "enc%d hw-pp i:%d pp_cnt:%d pixels_per_pp:%d\n",
                    *(_DWORD *)(a1 + 24),
                    v53,
                    v52,
                    v60);
                  goto LABEL_107;
                }
                goto LABEL_133;
              }
              v70 = &unk_234ED4;
LABEL_132:
              printk(v70, "_sde_encoder_update_ppb_size");
LABEL_133:
              *(_QWORD *)(a1 + 1352) = 0;
              *(_QWORD *)(a1 + 1344) = 0;
              result = ((__int64 (__fastcall *)(__int64, __int64))sde_encoder_control_fal10_veto)(a1, 1);
              *(_DWORD *)(a1 + 592) = 0;
              if ( !*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 328) + 8LL) + 2512LL) )
                return printk(&unk_215D04, "_sde_encoder_virt_enable_helper");
              if ( *(_DWORD *)(a1 + 800) )
                *(_BYTE *)(a1 + 808) = 1;
              return result;
            }
          }
          v69 = &unk_234896;
        }
        else
        {
          v69 = &unk_26FCAB;
        }
        printk(v69, "sde_encoder_get_kms");
        v70 = &unk_234EA4;
        goto LABEL_132;
      }
LABEL_129:
      v70 = &unk_2383FF;
      goto LABEL_132;
    }
    if ( (unsigned int)result <= 2 )
    {
      v35 = *(void (__fastcall **)(__int64, __int64))(v34 + 8LL * (unsigned int)result + 880);
      if ( !v35 || (*(_BYTE *)(v33 + 2289) & 1) != 0 )
        goto LABEL_63;
      v36 = *(_QWORD *)(v33 + 416);
      if ( *((_DWORD *)v35 - 1) != 836498625 )
        __break(0x822Au);
      v35(v36, v33 + 696);
      v34 = *(_QWORD *)(*(_QWORD *)(a1 + 328) + 416LL);
      if ( v34 )
LABEL_63:
        ((void (__fastcall *)(__int64, __int64))sde_fence_output_hw_fence_dir_write_init)(v34, v9);
      goto LABEL_64;
    }
LABEL_140:
    __break(0x5512u);
    return sde_encoder_virt_reset();
  }
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "invalid sde encoder/master\n");
  return result;
}
