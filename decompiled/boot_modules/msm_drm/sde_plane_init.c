__int64 __fastcall sde_plane_init(__int64 a1, unsigned int a2, char a3, __int64 a4, unsigned int a5)
{
  __int64 v6; // x26
  const char *v7; // x23
  __int64 v8; // x22
  unsigned int v10; // w24
  __int64 v11; // x19
  int v12; // w0
  int v13; // w25
  __int64 v14; // x8
  void (__fastcall *v15)(_QWORD); // x8
  _QWORD *v16; // x25
  __int64 v17; // x0
  __int64 v18; // x2
  _QWORD *v19; // x1
  unsigned int *v20; // x8
  unsigned __int64 v21; // x0
  __int64 v22; // x8
  int v23; // w0
  __int64 v24; // x8
  __int64 v25; // x9
  unsigned int v26; // w0
  __int64 v27; // x8
  void *v28; // x0
  __int64 v30; // x25
  int v31; // w8
  int v32; // w8
  __int64 v33; // x5
  __int64 v34; // x4
  void *v35; // x0
  __int64 v36; // x0
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x8
  __int64 v40; // x4
  __int64 v41; // x4
  __int64 v42; // x8
  __int64 v43; // x8
  __int64 v44; // x2
  int rotation_property; // w0
  __int64 v46; // x8
  unsigned int *v47; // x23
  unsigned int v48; // w8
  unsigned int v49; // w1
  _DWORD *v50; // x23
  unsigned int v51; // t1
  __int64 v52; // x2
  unsigned int *v53; // x8
  unsigned int *v54; // x23
  unsigned int v55; // w8
  unsigned int v56; // w1
  _DWORD *v57; // x23
  unsigned int v58; // t1
  int v59; // w8
  unsigned int v60; // w9
  unsigned int v61; // w8
  __int64 v62; // x8
  __int64 v63; // x2
  __int64 v64; // x8
  __int64 v65; // x2
  unsigned int *v66; // x23
  unsigned int v67; // w8
  unsigned int v68; // w1
  _DWORD *v69; // x23
  unsigned int v70; // t1
  __int64 v71; // x8
  char v72; // w9
  unsigned __int64 StatusReg; // x25
  __int64 v74; // x27
  __int64 v75; // [xsp+0h] [xbp-130h]
  int v76[2]; // [xsp+8h] [xbp-128h] BYREF
  __int64 v77; // [xsp+10h] [xbp-120h]
  int v78[2]; // [xsp+18h] [xbp-118h]
  __int64 v79; // [xsp+20h] [xbp-110h]
  char s[8]; // [xsp+28h] [xbp-108h] BYREF
  __int64 v81; // [xsp+30h] [xbp-100h]
  __int64 v82; // [xsp+38h] [xbp-F8h]
  __int64 v83; // [xsp+40h] [xbp-F0h]
  __int64 v84; // [xsp+48h] [xbp-E8h]
  __int64 v85; // [xsp+50h] [xbp-E0h]
  __int64 v86; // [xsp+58h] [xbp-D8h]
  __int64 v87; // [xsp+60h] [xbp-D0h]
  __int64 v88; // [xsp+68h] [xbp-C8h]
  __int64 v89; // [xsp+70h] [xbp-C0h]
  __int64 v90; // [xsp+78h] [xbp-B8h]
  __int64 v91; // [xsp+80h] [xbp-B0h]
  __int64 v92; // [xsp+88h] [xbp-A8h]
  __int64 v93; // [xsp+90h] [xbp-A0h]
  __int64 v94; // [xsp+98h] [xbp-98h]
  __int64 v95; // [xsp+A0h] [xbp-90h]
  __int64 v96; // [xsp+A8h] [xbp-88h]
  __int64 v97; // [xsp+B0h] [xbp-80h]
  __int64 v98; // [xsp+B8h] [xbp-78h]
  __int64 v99; // [xsp+C0h] [xbp-70h]
  __int64 v100; // [xsp+C8h] [xbp-68h]
  __int64 v101; // [xsp+D0h] [xbp-60h]
  __int64 v102; // [xsp+D8h] [xbp-58h]
  __int64 v103; // [xsp+E0h] [xbp-50h]
  __int64 v104; // [xsp+E8h] [xbp-48h]
  __int64 v105; // [xsp+F0h] [xbp-40h]
  __int64 v106; // [xsp+F8h] [xbp-38h]
  __int64 v107; // [xsp+100h] [xbp-30h]
  __int64 v108; // [xsp+108h] [xbp-28h]
  __int64 v109; // [xsp+110h] [xbp-20h]
  __int64 v110; // [xsp+118h] [xbp-18h]
  __int64 v111; // [xsp+120h] [xbp-10h]
  __int64 v112; // [xsp+128h] [xbp-8h]

  v112 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)v78 = 0;
  v79 = 0;
  *(_QWORD *)v76 = 0;
  v77 = 0;
  if ( !a1 )
  {
    v28 = &unk_21DD42;
LABEL_41:
    printk(v28, "sde_plane_init");
    v11 = 0;
    goto LABEL_42;
  }
  v6 = *(_QWORD *)(a1 + 56);
  v7 = (const char *)a1;
  if ( !v6 )
  {
    v28 = &unk_227A5A;
    goto LABEL_41;
  }
  v8 = *(_QWORD *)(v6 + 8);
  if ( !v8 )
  {
    v28 = &unk_219DE8;
    goto LABEL_41;
  }
  if ( !*(_QWORD *)(v8 + 152) )
  {
    v28 = &unk_2499B8;
    goto LABEL_41;
  }
  LOBYTE(v10) = a3;
  v11 = _kmalloc_cache_noprof(kthread_unpark, 3520, 4504);
  if ( !v11 )
  {
LABEL_188:
    printk(&unk_2575BE, "sde_plane_init");
    v11 = -12;
    goto LABEL_42;
  }
  while ( 1 )
  {
    v12 = hfi_plane_init(a2, (_QWORD *)v11);
    if ( v12 )
    {
      v13 = v12;
      LODWORD(v14) = 0;
LABEL_8:
      v15 = *(void (__fastcall **)(_QWORD))(v11 + 8LL * (unsigned int)v14 + 4304);
      if ( v15 )
      {
        if ( *((_DWORD *)v15 - 1) != -2119401948 )
          __break(0x8228u);
        v15(v11);
      }
      kfree(v11);
      v11 = v13;
      goto LABEL_42;
    }
    v16 = (_QWORD *)(v11 + 2392);
    *(_DWORD *)(v11 + 1928) = a2;
    *(_BYTE *)(v11 + 2388) = a5 != 0;
    *(_QWORD *)(v11 + 2392) = v11 + 2392;
    *(_QWORD *)(v11 + 2400) = v11 + 2392;
    v17 = drm_mode_object_find(v7, 0, a5, 4008636142LL);
    if ( v17 && v17 != 104 )
    {
      v18 = v17 + 2288;
      v19 = *(_QWORD **)(v17 + 2296);
      if ( v16 == (_QWORD *)(v17 + 2288) || v19 == v16 || *v19 != v18 )
      {
        _list_add_valid_or_report(v11 + 2392, v19);
      }
      else
      {
        *(_QWORD *)(v17 + 2296) = v16;
        *(_QWORD *)(v11 + 2392) = v18;
        *(_QWORD *)(v11 + 2400) = v19;
        *v19 = v16;
      }
    }
    v20 = *(unsigned int **)(*(_QWORD *)(v8 + 136) + 64LL);
    if ( v20 )
    {
      v21 = sde_hw_sspp_init(
              a2,
              *(_QWORD *)(v8 + 1752),
              *(_QWORD *)(v8 + 152),
              *(unsigned __int8 *)(v11 + 2388),
              v76,
              *v20);
      *(_QWORD *)(v11 + 2208) = v21;
      if ( !v21 )
        goto LABEL_57;
    }
    else
    {
      v21 = *(_QWORD *)(v11 + 2208);
      if ( !v21 )
        goto LABEL_57;
    }
    if ( v21 >= 0xFFFFFFFFFFFFF001LL )
    {
LABEL_57:
      printk(&unk_257602, "sde_plane_init");
      v13 = *(_DWORD *)(v11 + 2208);
      goto LABEL_79;
    }
    v22 = *(_QWORD *)(v21 + 56);
    if ( !v22 || !*(_QWORD *)(v22 + 48) )
    {
      v35 = &unk_25ED89;
      goto LABEL_76;
    }
    if ( (*(_QWORD *)(*(_QWORD *)(v8 + 152) + 22008LL) & 0x8000000000LL) != 0 )
    {
      v23 = sde_vbif_clk_register(v8, v76);
      if ( v23 )
      {
        v13 = v23;
        printk(&unk_26CAE5, "sde_plane_init");
        if ( !*(_QWORD *)(v11 + 2208) )
          goto LABEL_79;
        goto LABEL_78;
      }
      v21 = *(_QWORD *)(v11 + 2208);
      v22 = *(_QWORD *)(v21 + 56);
    }
    *(_QWORD *)(v11 + 1936) = *(_QWORD *)(v22 + 32);
    *(_DWORD *)(v11 + 1944) = *(_QWORD *)(*(_QWORD *)(v21 + 56) + 40LL);
    v24 = *(_QWORD *)(*(_QWORD *)(v21 + 56) + 48LL);
    *(_QWORD *)(v11 + 3320) = v24;
    if ( !v24 )
    {
      v35 = &unk_265D20;
      goto LABEL_76;
    }
    v25 = 1224;
    if ( *(_BYTE *)(v11 + 2388) )
      v25 = 1232;
    v26 = sde_populate_formats(*(_QWORD *)(v24 + v25), v11 + 1952, 0, 64);
    *(_DWORD *)(v11 + 1948) = v26;
    if ( !v26 )
    {
      v35 = &unk_22E7C6;
LABEL_76:
      printk(v35, "sde_plane_init");
      v13 = 0;
LABEL_77:
      if ( *(_QWORD *)(v11 + 2208) )
LABEL_78:
        sde_hw_sspp_destroy();
LABEL_79:
      v14 = *(_QWORD *)v11;
      if ( !*(_QWORD *)v11 )
        goto LABEL_8;
      v14 = *(_QWORD *)(v14 + 56);
      if ( !v14 )
        goto LABEL_8;
      LODWORD(v14) = *(_DWORD *)(v14 + 5912);
      if ( (unsigned int)v14 < 3 )
        goto LABEL_8;
      goto LABEL_187;
    }
    v75 = 0;
    v13 = drm_universal_plane_init(v7, v11, 255, &sde_plane_funcs, v11 + 1952, v26, 0, v10 & 1);
    if ( v13 )
      goto LABEL_77;
    qword_887C = 0x100000001LL;
    qword_87D4 = 0x100000001LL;
    qword_8840 = 0x100000001LL;
    plane_prop_array = 0x200000002LL;
    dword_87E8 = -523745;
    qword_8814 = 0x1FFF8021FLL;
    qword_885C = 0x100000000LL;
    qword_8864 = 0x100000000LL;
    dword_8884 = 1;
    qword_880C = 1;
    qword_886C = 0xFFF8021F00000010LL;
    dword_8838 = 8;
    dword_883C = 8;
    qword_881C = 1;
    qword_87EC = 0x4000000020LL;
    dword_87DC = 1;
    qword_87F4 = 0x10000000080LL;
    dword_8834 = 1;
    qword_882C = 0xFFF8021FFFF8021FLL;
    qword_8824 = 0xFFF8021FFFF8021FLL;
    qword_87E0 = 0xFFF8021FFFF8021FLL;
    dword_8848 = 2;
    dword_884C = 1024;
    dword_87D0 = 0;
    qword_87FC = 0x100000000800LL;
    qword_8850 = 0x2000000002000LL;
    qword_8874 = 0x800000004000LL;
    dword_8804 = 1;
    dword_8808 = 0x10000;
    dword_8858 = 0x40000;
    *(_QWORD *)(v11 + 1760) = sde_plane_helper_funcs;
    msm_property_init(v11 + 3344, v11 + 104, v7, v6 + 4200, v11 + 3472, 48, 17, 2952);
    if ( *(_QWORD *)v11 && (v27 = *(_QWORD *)(*(_QWORD *)v11 + 56LL)) != 0 )
      v10 = *(_DWORD *)(v27 + 5912);
    else
      v10 = 0;
    if ( !*(_QWORD *)(v11 + 2208) || !*(_QWORD *)(v11 + 3320) )
    {
      printk(&unk_24CE23, "_sde_plane_install_properties");
      goto LABEL_162;
    }
    v30 = *(_QWORD *)(v8 + 152);
    if ( !v30 )
    {
      printk(&unk_265E45, "_sde_plane_install_properties");
      goto LABEL_162;
    }
    v7 = (const char *)*(unsigned __int8 *)(v11 + 2388);
    *(_QWORD *)(v11 + 2408) = v30;
    v8 = vzalloc_noprof(16396);
    if ( !v8 )
    {
      printk(&unk_2657A2, "_sde_plane_install_properties");
      goto LABEL_162;
    }
    if ( (sde_is_custom_client() & 1) == 0 )
    {
      if ( *(_DWORD *)(v11 + 1752) == 1 )
LABEL_56:
        v33 = 0;
      else
        v33 = *(_DWORD *)(v11 + 1756) + 1;
      v34 = 255;
      goto LABEL_60;
    }
    if ( !*(_DWORD *)(v30 + 6952) )
      goto LABEL_56;
    v31 = *(_DWORD *)(*(_QWORD *)(v30 + 7008) + 4LL);
    if ( !v31 )
      goto LABEL_56;
    v32 = v31 - 1;
    if ( v32 >= 12 && (*(_QWORD *)(v30 + 22008) & 0x2000) != 0 )
    {
      v33 = 0;
      v34 = 11;
    }
    else
    {
      v33 = 0;
      if ( v32 >= 10 )
        v32 = 10;
      v34 = v32;
    }
LABEL_60:
    msm_property_install_range(v11 + 3344, "zpos", 0, 0, v34, v33, 17);
    if ( (*(_QWORD *)(v30 + 22008) & 0x400000000000LL) != 0 )
    {
      msm_property_install_range(v11 + 3344, "alpha", 0, 0, 0xFFFF, 0xFFFF, 18);
      v36 = v11 + 3344;
      v37 = 0xFFFF;
      v38 = 0xFFFF;
    }
    else
    {
      msm_property_install_range(v11 + 3344, "alpha", 0, 0, 255, 255, 18);
      v36 = v11 + 3344;
      v37 = 255;
      v38 = 255;
    }
    msm_property_install_volatile_range(v36, "bg_alpha", 0, 0, v37, v38, 37);
    msm_property_install_range(v11 + 3344, "input_fence", 0, 0, 4096, 0, 22);
    if ( ((unsigned __int8)v7 & 1) == 0 )
    {
      v39 = *(_QWORD *)(v11 + 3320);
      v110 = 0;
      v111 = 0;
      v108 = 0;
      v109 = 0;
      v106 = 0;
      v107 = 0;
      v104 = 0;
      v105 = 0;
      v102 = 0;
      v103 = 0;
      v100 = 0;
      v101 = 0;
      v98 = 0;
      v99 = 0;
      v96 = 0;
      v97 = 0;
      v94 = 0;
      v95 = 0;
      v92 = 0;
      v93 = 0;
      v90 = 0;
      v91 = 0;
      v88 = 0;
      v89 = 0;
      v86 = 0;
      v87 = 0;
      v84 = 0;
      v85 = 0;
      v82 = 0;
      v83 = 0;
      v40 = *(unsigned int *)(v39 + 28);
      *(_QWORD *)s = 0;
      v81 = 0;
      if ( (_DWORD)v40 )
      {
        msm_property_install_range(v11 + 3344, "h_decimate", 0, 0, v40, 0, 20);
        v39 = *(_QWORD *)(v11 + 3320);
      }
      v41 = *(unsigned int *)(v39 + 32);
      if ( (_DWORD)v41 )
        msm_property_install_range(v11 + 3344, "v_decimate", 0, 0, v41, 0, 21);
      v42 = *(_QWORD *)(v11 + 1936);
      if ( (v42 & 8) != 0 )
      {
        msm_property_install_range(v11 + 3344, "scaler_v2", 0, 0, -1, 0, 31);
        msm_property_install_blob(v11 + 3344, "lut_ed", 0, 3);
        msm_property_install_blob(v11 + 3344, "lut_cir", 0, 4);
      }
      else
      {
        if ( (v42 & 0x400000) == 0 )
        {
          if ( (v42 & 4) != 0 )
            msm_property_install_range(v11 + 3344, "scaler_v1", 0, 0, -1, 0, 30);
          goto LABEL_85;
        }
        msm_property_install_range(v11 + 3344, "scaler_v2", 0, 0, -1, 0, 31);
      }
      msm_property_install_blob(v11 + 3344, "lut_sep", 0, 5);
LABEL_85:
      v43 = *(_QWORD *)(v11 + 1936);
      if ( (v43 & 0x30) != 0 )
      {
        msm_property_install_volatile_range(v11 + 3344, "csc_v1", 0, 0, -1, 0, 0);
        v43 = *(_QWORD *)(v11 + 1936);
      }
      if ( (v43 & 0x40) != 0 )
      {
        v7 = "%s%d";
        snprintf(s, 0x100u, "%s%d", "SDE_SSPP_HUE_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 194LL));
        msm_property_install_range(v11 + 3344, s, 0, 0, 0xFFFFFFFFLL, 0, 23);
        snprintf(s, 0x100u, "%s%d", "SDE_SSPP_SATURATION_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 194LL));
        msm_property_install_range(v11 + 3344, s, 0, 0, 0xFFFFFFFFLL, 0, 24);
        snprintf(s, 0x100u, "%s%d", "SDE_SSPP_VALUE_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 194LL));
        msm_property_install_range(v11 + 3344, s, 0, 0, 0xFFFFFFFFLL, 0, 25);
        snprintf(s, 0x100u, "%s%d", "SDE_SSPP_CONTRAST_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 194LL));
        msm_property_install_range(v11 + 3344, s, 0, 0, 0xFFFFFFFFLL, 0, 26);
      }
      goto LABEL_89;
    }
    msm_property_install_enum(
      v11 + 3344,
      "multirect_mode",
      0,
      0,
      &sde_plane_install_properties_e_multirect_mode,
      3,
      0,
      42);
LABEL_89:
    if ( (*(_BYTE *)(v11 + 1937) & 2) != 0 )
      msm_property_install_volatile_range(v11 + 3344, "excl_rect_v1", 0, 0, -1, 0, 27);
    v44 = 53;
    if ( (*(_BYTE *)(v11 + 2388) & 1) == 0 )
    {
      if ( (*(_BYTE *)(v11 + 1938) & 0x80) != 0 )
        v44 = 63;
      else
        v44 = 53;
    }
    rotation_property = drm_plane_create_rotation_property(v11, 1, v44);
    if ( rotation_property )
      _drm_err("create rotation property failed: %d\n", rotation_property);
    msm_property_install_enum(v11 + 3344, "blend_op", 0, 0, &sde_plane_install_properties_e_blend_op, 5, 0, 39);
    msm_property_install_enum(v11 + 3344, "src_config", 0, 1, &sde_plane_install_properties_e_src_config, 1, 0, 40);
    if ( (*(_BYTE *)(v11 + 1941) & 3) != 0 )
    {
      msm_property_install_enum(v11 + 3344, "cac_type", 0, 0, &sde_plane_install_properties_e_cac_type, 5, 0, 45);
      msm_property_install_volatile_range(v11 + 3344, "src_img_size", 0, 0, -1, 0, 38);
      msm_property_install_volatile_range(v11 + 3344, "src_rect_extn", 0, 0, -1, 0, 46);
      msm_property_install_volatile_range(v11 + 3344, "dst_rect_extn", 0, 0, -1, 0, 47);
    }
    if ( v10 <= 2 )
    {
      if ( *(_QWORD *)(*(_QWORD *)(v11 + 2208) + 8LL * v10 + 256) )
        msm_property_install_range(v11 + 3344, "color_fill", 0, 0, 0xFFFFFFFFLL, 0, 19);
      msm_property_install_range(v11 + 3344, "prefill_size", 0, 0, -1, 0, 28);
      msm_property_install_range(v11 + 3344, "prefill_time", 0, 0, -1, 0, 29);
      msm_property_install_blob(v11 + 3344, "capabilities", 4, 2);
      sde_kms_info_reset(v8);
      v46 = *(_QWORD *)(v11 + 3320);
      if ( (*(_BYTE *)(v11 + 2388) & 1) != 0 )
      {
        v47 = *(unsigned int **)(v46 + 1232);
        sde_kms_info_add_keyint(v8, (__int64)"primary_smart_plane_id", a5);
      }
      else
      {
        v47 = *(unsigned int **)(v46 + 1224);
      }
      if ( v47 )
      {
        ((void (__fastcall *)(__int64, const char *))sde_kms_info_start)(v8, "pixel_formats");
        v49 = *v47;
        if ( *v47 )
        {
          v50 = v47 + 4;
          do
          {
            sde_kms_info_append_format(v8, v49, *((_QWORD *)v50 - 1), v48, v75, v76[0], v77, v78[0], v79);
            v51 = *v50;
            v50 += 4;
            v49 = v51;
          }
          while ( v51 );
        }
        ((void (__fastcall *)(__int64))sde_kms_info_stop)(v8);
      }
      if ( *(_QWORD *)(v11 + 2208) )
      {
        v52 = *(unsigned int *)(v30 + 20);
        if ( (_DWORD)v52 )
          sde_kms_info_add_keyint(v8, (__int64)"scaler_step_ver", v52);
      }
      v53 = *(unsigned int **)(v11 + 3320);
      if ( (v53[324] & 1) != 0 )
      {
        v54 = *((unsigned int **)v53 + 156);
        if ( v54 )
        {
          ((void (__fastcall *)(__int64, const char *))sde_kms_info_start)(v8, "cac_supported_formats");
          v56 = *v54;
          if ( *v54 )
          {
            v57 = v54 + 4;
            do
            {
              sde_kms_info_append_format(v8, v56, *((_QWORD *)v57 - 1), v55, v75, v76[0], v77, v78[0], v79);
              v58 = *v57;
              v57 += 4;
              v56 = v58;
            }
            while ( v58 );
          }
          ((void (__fastcall *)(__int64))sde_kms_info_stop)(v8);
          v53 = *(unsigned int **)(v11 + 3320);
        }
      }
      sde_kms_info_add_keyint(v8, (__int64)"max_linewidth", *v53);
      sde_kms_info_add_keyint(v8, (__int64)"max_upscale", *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 24LL));
      sde_kms_info_add_keyint(v8, (__int64)"max_downscale", *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 20LL));
      sde_kms_info_add_keyint(v8, (__int64)"max_horizontal_deci", *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 28LL));
      sde_kms_info_add_keyint(v8, (__int64)"max_vertical_deci", *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 32LL));
      v7 = (_BYTE *)&unk_3E8;
      sde_kms_info_add_keyint(
        v8,
        (__int64)"max_per_pipe_bw",
        1000LL * *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 40LL));
      sde_kms_info_add_keyint(
        v8,
        (__int64)"max_per_pipe_bw_high",
        1000LL * *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 44LL));
      v59 = *(_DWORD *)(v11 + 1928);
      v60 = v59 - 9;
      v61 = v59 - 1;
      if ( v60 >= 6 )
        v60 = -1;
      if ( v61 >= 8 )
        v61 = v60;
      sde_kms_info_add_keyint(v8, (__int64)"pipe_idx", (int)v61);
      if ( (*(_QWORD *)(v30 + 22008) & 0x800000) == 0 )
        goto LABEL_127;
      v62 = *(unsigned int *)(v11 + 1928);
      if ( (unsigned int)v62 < 0xF )
        break;
    }
LABEL_187:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v74 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sde_plane_init__alloc_tag;
    v11 = _kmalloc_cache_noprof(kthread_unpark, 3520, 4504);
    *(_QWORD *)(StatusReg + 80) = v74;
    if ( !v11 )
      goto LABEL_188;
  }
  v63 = *(unsigned int *)(v30 + 8 * v62 + 4LL * (a5 != 0) + 19984);
  if ( (_DWORD)v63 != -1 )
    sde_kms_info_add_keyint(v8, (__int64)"demura_block", v63);
LABEL_127:
  v64 = *(_QWORD *)(v11 + 1936);
  if ( (v64 & 0x100000) != 0 )
  {
    sde_kms_info_add_keyint(v8, (__int64)"sec_ui_allowed", 1);
    v64 = *(_QWORD *)(v11 + 1936);
    if ( (v64 & 0x200000) != 0 )
      goto LABEL_132;
LABEL_129:
    if ( (v64 & 0x30000000000LL) != 0 )
    {
LABEL_133:
      sde_kms_info_add_keyint(v8, (__int64)"cac_mode", *(int *)(*(_QWORD *)(v11 + 3320) + 1296LL));
      v65 = *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 4LL * (a5 != 0) + 1300);
      if ( (_DWORD)v65 != 255 )
        sde_kms_info_add_keyint(v8, (__int64)"cac_parent_rec", v65);
    }
  }
  else
  {
    if ( (v64 & 0x200000) == 0 )
      goto LABEL_129;
LABEL_132:
    sde_kms_info_add_keyint(v8, (__int64)"block_sec_ui", 1);
    if ( (*(_QWORD *)(v11 + 1936) & 0x30000000000LL) != 0 )
      goto LABEL_133;
  }
  if ( (*(_BYTE *)(v11 + 1938) & 0x80) != 0 )
  {
    sde_kms_info_add_keyint(v8, (__int64)"true_inline_rot_rev", *(unsigned int *)(v30 + 44));
    sde_kms_info_add_keyint(
      v8,
      (__int64)"true_inline_dwnscale_rt",
      *(_DWORD *)(*(_QWORD *)(v11 + 3320) + 1256LL) / *(_DWORD *)(*(_QWORD *)(v11 + 3320) + 1260LL));
    sde_kms_info_add_keyint(
      v8,
      (__int64)"true_inline_dwnscale_rt_numerator",
      *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 1256LL));
    sde_kms_info_add_keyint(
      v8,
      (__int64)"true_inline_dwnscale_rt_denominator",
      *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 1260LL));
    sde_kms_info_add_keyint(
      v8,
      (__int64)"true_inline_dwnscale_nrt",
      *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 1264LL));
    sde_kms_info_add_keyint(v8, (__int64)"true_inline_max_height", *(unsigned int *)(*(_QWORD *)(v11 + 3320) + 1276LL));
    v66 = *(unsigned int **)(*(_QWORD *)(v11 + 3320) + 1240LL);
    if ( v66 )
    {
      ((void (__fastcall *)(__int64, const char *))sde_kms_info_start)(v8, "inline_rot_pixel_formats");
      v68 = *v66;
      if ( *v66 )
      {
        v69 = v66 + 4;
        do
        {
          sde_kms_info_append_format(v8, v68, *((_QWORD *)v69 - 1), v67, v75, v76[0], v77, v78[0], v79);
          v70 = *v69;
          v69 += 4;
          v68 = v70;
        }
        while ( v70 );
      }
      ((void (__fastcall *)(__int64))sde_kms_info_stop)(v8);
    }
  }
  v71 = *(_QWORD *)(v11 + 1936);
  v72 = *(_BYTE *)(v11 + 2388);
  v110 = 0;
  v111 = 0;
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  *(_QWORD *)s = 0;
  v81 = 0;
  if ( !(v72 & 1 | ((v71 & 0x20000) == 0)) || (v71 & 0x40000) != 0 )
  {
    msm_property_install_range(v11 + 3344, "inverse_pma", 0, 0, 1, 0, 32);
    sde_kms_info_add_keyint(v8, (__int64)"inverse_pma", 1);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x80000) != 0 )
      goto LABEL_165;
LABEL_144:
    if ( (v71 & 0x80) == 0 )
      goto LABEL_145;
LABEL_166:
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_SKIN_COLOR_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 230LL));
    msm_property_install_blob(v11 + 3344, s, 0, 6);
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_SKY_COLOR_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 230LL));
    msm_property_install_blob(v11 + 3344, s, 0, 7);
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_FOLIAGE_COLOR_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 230LL));
    msm_property_install_blob(v11 + 3344, s, 0, 8);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x4000) != 0 )
      goto LABEL_167;
LABEL_146:
    if ( (v71 & 0x2000) == 0 )
      goto LABEL_147;
LABEL_168:
    snprintf(s, 0x100u, "%s%d", "SDE_VIG_1D_LUT_IGC_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 342LL));
    msm_property_install_blob(v11 + 3344, s, 0, 10);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x8000) != 0 )
      goto LABEL_169;
LABEL_148:
    if ( (v71 & 0x10000) == 0 )
      goto LABEL_149;
LABEL_170:
    snprintf(s, 0x100u, "%s%d", "SDE_DGM_1D_LUT_GC_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 418LL));
    msm_property_install_blob(v11 + 3344, s, 0, 12);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x10000000) != 0 )
      goto LABEL_171;
LABEL_150:
    if ( (v71 & 0x20000000) == 0 )
      goto LABEL_151;
LABEL_172:
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_FP16_GC_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 646LL));
    msm_property_install_blob(v11 + 3344, s, 0, 13);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x40000000) != 0 )
      goto LABEL_173;
LABEL_152:
    if ( (v71 & 0x80000000) == 0 )
      goto LABEL_153;
LABEL_174:
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_FP16_UNMULT_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 798LL));
    msm_property_install_range(v11 + 3344, s, 0, 0, 1, 0, 34);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x800000000LL) != 0 )
      goto LABEL_175;
LABEL_154:
    if ( (v71 & 0x1000000000LL) == 0 )
      goto LABEL_155;
LABEL_176:
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_UCSC_GC_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 950LL));
    msm_property_install_volatile_enum(v11 + 3344, s, 0, 0, &sde_plane_install_colorproc_properties_ucsc_gc, 5, 0, 44);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x2000000000LL) != 0 )
      goto LABEL_177;
LABEL_156:
    if ( (v71 & 0x4000000000LL) == 0 )
      goto LABEL_157;
LABEL_178:
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_UCSC_UNMULT_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 1102LL));
    msm_property_install_volatile_range(v11 + 3344, s, 0, 0, 1, 0, 35);
    if ( (*(_QWORD *)(v11 + 1936) & 0x8000000000LL) != 0 )
    {
LABEL_158:
      snprintf(
        s,
        0x100u,
        "%s%d",
        "SDE_SSPP_UCSC_ALPHA_DITHER_V",
        *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 1178LL));
      msm_property_install_volatile_range(v11 + 3344, s, 0, 0, 1, 0, 36);
    }
  }
  else
  {
    if ( (v71 & 0x80000) == 0 )
      goto LABEL_144;
LABEL_165:
    msm_property_install_volatile_range(v11 + 3344, "csc_dma_v1", 0, 0, -1, 0, 1);
    sde_kms_info_add_keyint(v8, (__int64)"csc_dma_v1", 1);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x80) != 0 )
      goto LABEL_166;
LABEL_145:
    if ( (v71 & 0x4000) == 0 )
      goto LABEL_146;
LABEL_167:
    snprintf(s, 0x100u, "%s%d", "SDE_VIG_3D_LUT_GAMUT_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 302LL));
    msm_property_install_blob(v11 + 3344, s, 0, 9);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x2000) != 0 )
      goto LABEL_168;
LABEL_147:
    if ( (v71 & 0x8000) == 0 )
      goto LABEL_148;
LABEL_169:
    snprintf(s, 0x100u, "%s%d", "SDE_DGM_1D_LUT_IGC_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 342LL));
    msm_property_install_blob(v11 + 3344, s, 0, 11);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x10000) != 0 )
      goto LABEL_170;
LABEL_149:
    if ( (v71 & 0x10000000) == 0 )
      goto LABEL_150;
LABEL_171:
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_FP16_IGC_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 570LL));
    msm_property_install_range(v11 + 3344, s, 0, 0, 1, 0, 33);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x20000000) != 0 )
      goto LABEL_172;
LABEL_151:
    if ( (v71 & 0x40000000) == 0 )
      goto LABEL_152;
LABEL_173:
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_FP16_CSC_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 722LL));
    msm_property_install_blob(v11 + 3344, s, 0, 14);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x80000000) != 0 )
      goto LABEL_174;
LABEL_153:
    if ( (v71 & 0x800000000LL) == 0 )
      goto LABEL_154;
LABEL_175:
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_UCSC_IGC_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 874LL));
    msm_property_install_volatile_enum(v11 + 3344, s, 0, 0, &sde_plane_install_colorproc_properties_ucsc_igc, 6, 0, 43);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x1000000000LL) != 0 )
      goto LABEL_176;
LABEL_155:
    if ( (v71 & 0x2000000000LL) == 0 )
      goto LABEL_156;
LABEL_177:
    snprintf(s, 0x100u, "%s%d", "SDE_SSPP_UCSC_CSC_V", *(unsigned __int16 *)(*(_QWORD *)(v11 + 3320) + 1026LL));
    msm_property_install_blob(v11 + 3344, s, 0, 16);
    v71 = *(_QWORD *)(v11 + 1936);
    if ( (v71 & 0x4000000000LL) != 0 )
      goto LABEL_178;
LABEL_157:
    if ( (v71 & 0x8000000000LL) != 0 )
      goto LABEL_158;
  }
  msm_property_set_blob(v11 + 3344, v11 + 4240, v8, (unsigned int)(*(_DWORD *)(v8 + 0x4000) + 1), 2);
  msm_property_install_enum(
    v11 + 3344,
    "fb_translation_mode",
    0,
    0,
    &sde_plane_install_properties_e_fb_translation_mode,
    4,
    0,
    41);
  if ( *(_QWORD *)(*(_QWORD *)(v11 + 2208) + 8LL * v10 + 1048) )
    msm_property_install_volatile_range(v11 + 3344, "ubwc_stats_roi", 0, 0, -1, 0, 15);
  vfree(v8);
LABEL_162:
  snprintf((char *)(v11 + 3328), 0xCu, "plane%u", *(_DWORD *)(v11 + 104));
  _mutex_init(v11 + 1880, "&psde->lock", &sde_plane_init___key);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "%s created for pipe:%u id:%u master:%u\n",
      (const char *)(v11 + 3328),
      a2,
      *(_DWORD *)(v11 + 104),
      a5);
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v11;
}
