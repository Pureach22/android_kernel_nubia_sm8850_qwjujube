__int64 __fastcall sde_encoder_virt_atomic_check(__int64 a1, __int64 a2, __int64 **a3)
{
  __int64 v6; // x8
  __int64 v7; // x25
  __int64 *v8; // x22
  __int64 result; // x0
  __int64 v10; // x0
  __int64 (*v11)(void); // x8
  unsigned int v12; // w0
  unsigned int v13; // w20
  void *v14; // x0
  __int64 (*v15)(void); // x8
  __int64 v16; // x0
  __int64 (*v17)(void); // x8
  unsigned int v18; // w0
  __int64 (*v19)(void); // x8
  __int64 v20; // x0
  __int64 (*v21)(void); // x8
  unsigned int v22; // w0
  __int64 (*v23)(void); // x8
  __int64 v24; // x0
  __int64 (*v25)(void); // x8
  __int64 (*v26)(void); // x8
  __int64 v27; // x0
  int v28; // w26
  int v29; // w23
  int v30; // w28
  unsigned int v31; // w27
  int v32; // w23
  __int64 *v33; // x9
  unsigned int mode_info; // w0
  unsigned int updated; // w0
  unsigned int v36; // w0
  const char *v37; // x1
  unsigned int v38; // w19
  void *v39; // x0
  __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 (__fastcall *v43)(_QWORD); // x8
  __int64 v44; // x0
  int v45; // w4
  unsigned int v46; // w0
  unsigned int v47; // w0
  int v48; // w22
  int v49; // w24
  unsigned int v50; // w26
  int v51; // w25
  int v52; // w21
  char v53; // w0
  void *v54; // x0
  const char *v55; // x1
  __int64 v56; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v57[2]; // [xsp+50h] [xbp-10h] BYREF

  v57[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || !a3 )
  {
    printk(&unk_25ACD8, "sde_encoder_virt_atomic_check");
    result = 4294967274LL;
    goto LABEL_95;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(a1 + 24));
  if ( !*(_QWORD *)a1 )
  {
    v14 = &unk_26FCAB;
    goto LABEL_20;
  }
  v6 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v6 || (v7 = *(_QWORD *)(v6 + 8)) == 0 )
  {
    v14 = &unk_234896;
LABEL_20:
    printk(v14, "sde_encoder_get_kms");
    result = 4294967274LL;
    goto LABEL_95;
  }
  v8 = *a3;
  result = sde_connector_set_msm_mode(a3, a2 + 24);
  if ( (_DWORD)result )
    goto LABEL_95;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_virt_atomic_check",
    1409,
    -1,
    *(_DWORD *)(a1 + 24),
    (*(unsigned __int8 *)(a2 + 10) >> 1) & 1,
    (*(unsigned __int8 *)(a2 + 10) >> 2) & 1,
    (*(unsigned __int8 *)(a2 + 10) >> 3) & 1,
    239);
  if ( !*(_DWORD *)(a1 + 196) )
    goto LABEL_59;
  v10 = *(_QWORD *)(a1 + 200);
  if ( v10 )
  {
    v11 = *(__int64 (**)(void))(v10 + 80);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != 378617142 )
        __break(0x8228u);
      v12 = v11();
      if ( v12 )
      {
        v13 = v12;
LABEL_111:
        printk(&unk_21D768, "_sde_encoder_atomic_check_phys_enc");
        result = v13;
        goto LABEL_95;
      }
    }
    else
    {
      v15 = *(__int64 (**)(void))(v10 + 40);
      if ( v15 )
      {
        if ( *((_DWORD *)v15 - 1) != -127045866 )
          __break(0x8228u);
        if ( (v15() & 1) == 0 )
        {
          v13 = -22;
          goto LABEL_111;
        }
      }
    }
  }
  if ( *(_DWORD *)(a1 + 196) < 2u )
    goto LABEL_59;
  v16 = *(_QWORD *)(a1 + 208);
  if ( v16 )
  {
    v17 = *(__int64 (**)(void))(v16 + 80);
    if ( v17 )
    {
      if ( *((_DWORD *)v17 - 1) != 378617142 )
        __break(0x8228u);
      v18 = v17();
      if ( v18 )
      {
        v13 = v18;
        goto LABEL_111;
      }
    }
    else
    {
      v19 = *(__int64 (**)(void))(v16 + 40);
      if ( v19 )
      {
        if ( *((_DWORD *)v19 - 1) != -127045866 )
          __break(0x8228u);
        if ( (v19() & 1) == 0 )
        {
          v13 = -22;
          goto LABEL_111;
        }
      }
    }
  }
  if ( *(_DWORD *)(a1 + 196) < 3u )
    goto LABEL_59;
  v20 = *(_QWORD *)(a1 + 216);
  if ( v20 )
  {
    v21 = *(__int64 (**)(void))(v20 + 80);
    if ( v21 )
    {
      if ( *((_DWORD *)v21 - 1) != 378617142 )
        __break(0x8228u);
      v22 = v21();
      if ( v22 )
      {
        v13 = v22;
        goto LABEL_111;
      }
    }
    else
    {
      v23 = *(__int64 (**)(void))(v20 + 40);
      if ( v23 )
      {
        if ( *((_DWORD *)v23 - 1) != -127045866 )
          __break(0x8228u);
        if ( (v23() & 1) == 0 )
        {
          v13 = -22;
          goto LABEL_111;
        }
      }
    }
  }
  if ( *(_DWORD *)(a1 + 196) < 4u )
    goto LABEL_59;
  v24 = *(_QWORD *)(a1 + 224);
  if ( v24 )
  {
    v25 = *(__int64 (**)(void))(v24 + 80);
    if ( v25 )
    {
      if ( *((_DWORD *)v25 - 1) != 378617142 )
        __break(0x8228u);
      LODWORD(v24) = v25();
      if ( (_DWORD)v24 )
      {
        v13 = v24;
        goto LABEL_111;
      }
    }
    else
    {
      v26 = *(__int64 (**)(void))(v24 + 40);
      if ( v26 )
      {
        if ( *((_DWORD *)v26 - 1) != -127045866 )
          __break(0x8228u);
        LODWORD(v24) = v26();
        if ( (v24 & 1) == 0 )
        {
          v13 = -22;
          goto LABEL_111;
        }
      }
    }
  }
  if ( *(_DWORD *)(a1 + 196) <= 4u )
  {
LABEL_59:
    if ( (*(_BYTE *)(a2 + 10) & 6) == 0 )
    {
LABEL_69:
      v32 = *((_DWORD *)a3 + 344);
      *((_DWORD *)a3 + 814) = v32;
      if ( !v8 )
        goto LABEL_89;
      if ( (*(_BYTE *)(a2 + 10) & 0xE) == 0 )
      {
        if ( !*a3 )
          goto LABEL_89;
        v40 = **a3;
        if ( !v40 )
          goto LABEL_89;
        v41 = *(_QWORD *)(v40 + 56);
        if ( !v41 )
          goto LABEL_89;
        v42 = *(_QWORD *)(v41 + 8);
        if ( !v42 )
          goto LABEL_89;
        v43 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v42 + 80LL);
        if ( !v43 )
          goto LABEL_89;
        if ( *((_DWORD *)v43 - 1) != -1440990782 )
          __break(0x8228u);
        v44 = v43(a3);
        if ( !v44 || (*(_WORD *)(v44 + 8) & 0x1D4) == 0 )
        {
LABEL_89:
          if ( (*(_BYTE *)(a1 + 644) & 0x40) == 0
            || *(_BYTE *)(a2 + 9) != 1
            || (v45 = *((_DWORD *)a3 + 344), v45 == 6)
            || v45 == 9 )
          {
            v46 = sde_connector_roi_v1_check_roi(a3);
            if ( !v46 )
            {
              drm_mode_set_crtcinfo(a2 + 24, 0);
              v47 = sde_encoder_atomic_check_qsync(v8, a3);
              v48 = sde_dbg_base_evtlog;
              v49 = *(_DWORD *)(a1 + 24);
              v50 = v47;
              v51 = *(_DWORD *)(a2 + 48);
              v52 = *((_DWORD *)a3 + 810);
              v53 = drm_mode_vrefresh(a2 + 24);
              sde_evtlog_log(v48, "sde_encoder_virt_atomic_check", 1462, -1, v49, v51, v52, v32, v53);
              result = v50;
              goto LABEL_95;
            }
            v37 = "sde_encoder_virt_atomic_check";
            v38 = v46;
            v39 = &unk_24932E;
LABEL_107:
            printk(v39, v37);
            result = v38;
            goto LABEL_95;
          }
          v54 = &unk_220C40;
          v55 = "sde_encoder_virt_atomic_check";
LABEL_105:
          printk(v54, v55);
          result = 4294967274LL;
          goto LABEL_95;
        }
      }
      v33 = a3[244];
      LODWORD(v57[0]) = (unsigned int)a3[228];
      HIDWORD(v57[0]) = (_DWORD)v33;
      mode_info = sde_connector_get_mode_info(v8, a2 + 24, v57, a3 + 276);
      if ( mode_info )
      {
        v37 = "_sde_encoder_atomic_check_reserve";
        v38 = mode_info;
        v39 = &unk_231A21;
        goto LABEL_107;
      }
      if ( *((_DWORD *)a3 + 567) && *((_DWORD *)a3 + 568) >= 0x1F4u )
      {
        v54 = &unk_219923;
        v55 = "_sde_encoder_atomic_check_reserve";
        goto LABEL_105;
      }
      result = sde_rm_reserve(v7 + 2144, a1, a2, a3, 1);
      if ( (_DWORD)result != -11 )
      {
        if ( (_DWORD)result )
        {
          v37 = "_sde_encoder_atomic_check_reserve";
          v38 = result;
          v39 = &unk_24FE9E;
          goto LABEL_107;
        }
        if ( *(_BYTE *)(a2 + 9) == 1 )
        {
          updated = sde_rm_update_topology(v7 + 2144, a3, (char *)a3 + 2244);
          if ( updated )
          {
            v37 = "_sde_encoder_atomic_check_reserve";
            v38 = updated;
            v39 = &unk_234FBF;
            goto LABEL_107;
          }
        }
        v36 = sde_connector_set_blob_data(*a3, a3, 0);
        if ( v36 )
        {
          v37 = "_sde_encoder_atomic_check_reserve";
          v38 = v36;
          v39 = &unk_24FEE6;
          goto LABEL_107;
        }
        goto LABEL_89;
      }
LABEL_95:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v27 = *(_QWORD *)a2;
    v56 = 0;
    v57[0] = 0;
    sde_crtc_get_resolution(v27, a2, a2 + 24, (_DWORD *)&v56 + 1, &v56);
    v28 = WORD2(v56);
    v29 = (unsigned __int16)v56;
    if ( *((_DWORD *)a3 + 512)
      && ((sde_kms_rect_merge_rectangles(a3 + 256, v57), LODWORD(v57[0]))
       || WORD2(v57[0]) != v28
       || HIWORD(v57[0]) != v29) )
    {
      printk(&unk_2241EB, "_sde_encoder_atomic_check_pu_roi");
      v30 = 0;
      result = 4294967274LL;
      if ( !*(_DWORD *)(a2 + 620) )
        goto LABEL_68;
    }
    else
    {
      result = 0;
      v30 = 1;
      if ( !*(_DWORD *)(a2 + 620) )
        goto LABEL_68;
    }
    v31 = result;
    sde_kms_rect_merge_rectangles(a2 + 620, v57);
    if ( LODWORD(v57[0]) || WORD2(v57[0]) != v28 || (result = v31, HIWORD(v57[0]) != v29) )
    {
      printk(&unk_25AD24, "_sde_encoder_atomic_check_pu_roi");
      result = 4294967274LL;
      goto LABEL_95;
    }
LABEL_68:
    if ( !v30 )
      goto LABEL_95;
    goto LABEL_69;
  }
  __break(0x5512u);
  return sde_encoder_virt_modeset_rc(v24);
}
