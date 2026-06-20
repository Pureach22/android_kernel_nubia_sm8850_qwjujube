__int64 __fastcall lpg_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x26
  __int64 v3; // x0
  _QWORD *v4; // x19
  __int64 match_data; // x0
  __int64 regmap; // x0
  __int64 v7; // x20
  unsigned __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x23
  __int64 v13; // x8
  int v14; // w9
  __int64 v15; // x21
  unsigned int v16; // w0
  __int64 v17; // x1
  int v18; // w8
  unsigned int v19; // w22
  __int64 v20; // x20
  __int64 v21; // x25
  __int64 v22; // x24
  unsigned int u32_index; // w0
  unsigned int v24; // w24
  unsigned int v25; // w0
  __int64 v26; // x9
  int v27; // w8
  __int64 v28; // x0
  int v29; // w10
  int v30; // w9
  unsigned int v31; // w8
  unsigned int v32; // w0
  __int64 v33; // x0
  int string_helper; // w0
  int v35; // w20
  unsigned __int64 v36; // x0
  unsigned int v37; // w0
  __int64 v38; // x0
  int *v39; // x8
  int v40; // w1
  int v41; // w8
  __int64 v42; // x0
  __int64 next_available_child; // x0
  char *v44; // x21
  unsigned int v45; // w0
  __int64 v46; // x0
  __int64 v47; // x1
  int v48; // w22
  unsigned __int64 v49; // x26
  __int64 v50; // x0
  int v51; // w8
  unsigned __int64 v52; // x25
  __int64 v53; // x0
  __int64 v54; // x23
  int v55; // w28
  __int64 v56; // x20
  __int64 v57; // x27
  unsigned __int64 v58; // x9
  unsigned __int64 v59; // x9
  bool v60; // cf
  _DWORD *v61; // x9
  unsigned __int64 v62; // x8
  __int64 v63; // x11
  int v64; // w9
  __int64 v65; // x28
  __int64 v66; // x20
  __int64 v67; // x8
  __int64 (__fastcall *v68)(); // x9
  __int64 v69; // x22
  unsigned __int64 v70; // x8
  int v71; // w9
  __int64 property; // x0
  unsigned __int64 v73; // x20
  int v74; // w8
  __int64 v75; // x1
  void (__fastcall *v76)(__int64, __int64); // x8
  __int64 v77; // x0
  unsigned int v78; // w0
  unsigned int v79; // w8
  unsigned int j; // w20
  _DWORD *v81; // x22
  __int64 v82; // x23
  unsigned __int64 v83; // x0
  unsigned int v84; // w8
  unsigned int i; // w20
  _DWORD *v86; // x23
  int v87; // w9
  __int64 v88; // x0
  _QWORD *v89; // x25
  int v90; // w8
  __int64 v91; // x0
  __int64 v92; // x8
  __int64 v93; // x0
  __int64 v95; // [xsp+10h] [xbp-50h]
  __int64 v96; // [xsp+18h] [xbp-48h]
  __int64 v97; // [xsp+20h] [xbp-40h]
  int v98; // [xsp+2Ch] [xbp-34h] BYREF
  _BYTE *v99; // [xsp+30h] [xbp-30h] BYREF
  _QWORD v100[5]; // [xsp+38h] [xbp-28h] BYREF

  v1 = a1 + 16;
  v2 = a1;
  v100[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = devm_kmalloc(a1 + 16, 160, 3520);
  if ( !v3 )
    goto LABEL_165;
  v4 = (_QWORD *)v3;
  match_data = of_device_get_match_data(v1);
  v4[9] = match_data;
  if ( !match_data )
  {
LABEL_38:
    v24 = -22;
    goto LABEL_166;
  }
  *v4 = v1;
  _mutex_init(v4 + 2, "&lpg->lock", &lpg_probe___key);
  regmap = dev_get_regmap(*(_QWORD *)(v2 + 112), 0);
  v4[1] = regmap;
  if ( !regmap )
  {
    v24 = dev_err_probe(v1, 4294967290LL, "parent regmap unavailable\n");
    goto LABEL_166;
  }
  v7 = v4[9];
  v8 = *(int *)(v7 + 16);
  *((_DWORD *)v4 + 38) = v8;
  if ( !is_mul_ok(v8, 0x68u) )
  {
    v4[18] = 0;
    goto LABEL_165;
  }
  v9 = devm_kmalloc(*v4, 104LL * (int)v8, 3520);
  v4[18] = v9;
  if ( !v9 )
  {
LABEL_165:
    v24 = -12;
    goto LABEL_166;
  }
  if ( *(int *)(v7 + 16) >= 1 )
  {
    v10 = 0;
    v11 = 0;
    v12 = 0;
    do
    {
      v13 = v4[18] + v10;
      *(_QWORD *)v13 = v4;
      v14 = *(_DWORD *)(*(_QWORD *)(v7 + 24) + v11 + 4);
      *(_DWORD *)(v13 + 8) = v14;
      *(_DWORD *)(v13 + 12) = *(unsigned __int8 *)(*(_QWORD *)(v7 + 24) + v11 + 8);
      *(_DWORD *)(v13 + 16) = 1LL << v12;
      *(_DWORD *)(v13 + 24) = *(_DWORD *)(*(_QWORD *)(v7 + 24) + v11);
      regmap_read(v4[1], (unsigned int)(v14 + 5), v13 + 20);
      ++v12;
      v11 += 12;
      v10 += 104;
    }
    while ( v12 < *(int *)(v7 + 16) );
  }
  v15 = *(_QWORD *)(*v4 + 744LL);
  v16 = of_property_count_elems_of_size(v15, "qcom,dtest", 4);
  if ( v16 == -22 )
    goto LABEL_23;
  v17 = v16;
  if ( (v16 & 0x80000000) == 0 )
  {
    v18 = *(_DWORD *)(v4[9] + 16LL);
    if ( v16 != 2 * v18 )
    {
      v25 = dev_err_probe(*v4, 4294967274LL, "qcom,dtest needs to be %d items\n", 2 * v18);
      goto LABEL_22;
    }
    if ( v18 < 1 )
      goto LABEL_23;
    v19 = 0;
    v20 = 0;
    v21 = 40;
    while ( 1 )
    {
      v22 = v4[18] + v21;
      u32_index = of_property_read_u32_index(v15, "qcom,dtest", v19, v22 - 4);
      if ( u32_index )
        break;
      u32_index = of_property_read_u32_index(v15, "qcom,dtest", v19 + 1, v22);
      if ( u32_index )
        break;
      ++v20;
      v19 += 2;
      v21 += 104;
      if ( v20 >= *(int *)(v4[9] + 16LL) )
        goto LABEL_23;
    }
    v17 = u32_index;
  }
  v25 = dev_err_probe(*v4, v17, "malformed qcom,dtest\n");
LABEL_22:
  v24 = v25;
  if ( (v25 & 0x80000000) != 0 )
    goto LABEL_166;
LABEL_23:
  v26 = v4[9];
  v27 = *(_DWORD *)(v26 + 8);
  if ( !v27 )
    goto LABEL_36;
  v28 = *(_QWORD *)(*v4 + 744LL);
  *((_DWORD *)v4 + 32) = v27;
  v29 = *(unsigned __int8 *)(v26 + 12);
  *((_BYTE *)v4 + 136) = v29;
  v30 = *(unsigned __int8 *)(v26 + 13);
  *((_BYTE *)v4 + 137) = v30;
  if ( v30 != 1 )
  {
    if ( !v29 )
    {
LABEL_32:
      if ( *((_BYTE *)v4 + 137) == 1 )
      {
        regmap_write(v4[1], (unsigned int)(v27 + 69), *((unsigned int *)v4 + 33));
        v27 = *((_DWORD *)v4 + 32);
      }
      regmap_write(v4[1], (unsigned int)(v27 + 70), 0);
      goto LABEL_36;
    }
LABEL_31:
    regmap_write(v4[1], (unsigned int)(v27 + 71), 0);
    v27 = *((_DWORD *)v4 + 32);
    goto LABEL_32;
  }
  if ( (of_property_read_variable_u32_array(v28, "qcom,power-source", (char *)v4 + 132, 1, 0) & 0x80000000) == 0 )
  {
    v31 = *((_DWORD *)v4 + 33);
    if ( v31 != 2 && v31 <= 3 )
    {
      v27 = *((_DWORD *)v4 + 32);
      if ( (v4[17] & 1) == 0 )
        goto LABEL_32;
      goto LABEL_31;
    }
  }
  v32 = dev_err_probe(*v4, 4294967274LL, "invalid power source\n");
  if ( (v32 & 0x80000000) != 0 )
  {
LABEL_145:
    v24 = v32;
    goto LABEL_166;
  }
LABEL_36:
  v33 = *(_QWORD *)(*v4 + 744LL);
  LOBYTE(v99) = 0;
  string_helper = of_property_read_string_helper(v33, "nvmem-names", 0, 0, 0);
  if ( string_helper < 1 )
    goto LABEL_44;
  if ( (unsigned int)string_helper > 2 )
    goto LABEL_38;
  v35 = string_helper;
  v36 = devm_nvmem_device_get(*v4, "lpg_chan_sdam");
  v4[13] = v36;
  if ( v36 >= 0xFFFFFFFFFFFFF001LL )
  {
    v37 = dev_err_probe(*v4, v36, "Failed to get LPG chan SDAM device\n");
    goto LABEL_43;
  }
  if ( v35 == 1 )
  {
    v38 = *v4;
    v4[12] = -19;
    v37 = dev_err_probe(v38, 4294967277LL, "Failed to get PBS client device\n");
    goto LABEL_43;
  }
  v83 = devm_nvmem_device_get(*v4, "lut_sdam");
  v4[14] = v83;
  if ( v83 > 0xFFFFFFFFFFFFF000LL )
  {
    v37 = dev_err_probe(*v4, v83, "Failed to get LPG LUT SDAM device\n");
LABEL_43:
    v24 = v37;
    if ( (v37 & 0x80000000) != 0 )
      goto LABEL_166;
    goto LABEL_44;
  }
  v84 = *((_DWORD *)v4 + 38);
  if ( v84 )
  {
    for ( i = 0; i < v84; ++i )
    {
      v86 = (_DWORD *)(v4[18] + 104LL * (int)i);
      v87 = v86[6];
      if ( v87 )
      {
        v32 = nvmem_device_write(v4[13], (unsigned int)(v87 + 6), 1, &v99);
        if ( (v32 & 0x80000000) != 0 )
          goto LABEL_145;
        LOBYTE(v100[0]) = 0;
        v88 = *(_QWORD *)(*(_QWORD *)v86 + 104LL);
        if ( v88 )
        {
          v32 = nvmem_device_write(v88, (unsigned int)v86[6], 1, v100);
          if ( (v32 & 0x80000000) != 0 )
            goto LABEL_145;
          v89 = *(_QWORD **)v86;
          v90 = v86[4];
          LOBYTE(v100[0]) = 0;
          v91 = v89[13];
          if ( v91 )
          {
            v92 = v89[15] & (unsigned int)~v90;
            v89[15] = v92;
            if ( !v92 )
            {
              v32 = nvmem_device_write(v91, 66, 1, v100);
              if ( (v32 & 0x80000000) != 0 )
                goto LABEL_145;
              if ( v89[14] )
              {
                v93 = v89[13];
                LOBYTE(v100[0]) = 1;
                v32 = nvmem_device_write(v93, 230, 1, v100);
                if ( (v32 & 0x80000000) != 0 )
                  goto LABEL_145;
              }
            }
          }
        }
        v84 = *((_DWORD *)v4 + 38);
      }
    }
  }
LABEL_44:
  v39 = (int *)v4[9];
  v40 = v39[1];
  if ( v40 )
  {
    *((_DWORD *)v4 + 21) = v40;
    v41 = *v39;
    if ( v41 )
      *((_DWORD *)v4 + 20) = v41;
    v42 = devm_bitmap_zalloc(*v4);
    v4[11] = v42;
    if ( !v42 )
      goto LABEL_165;
  }
  next_available_child = of_get_next_available_child(*(_QWORD *)(v2 + 760), 0);
  if ( !next_available_child )
  {
LABEL_139:
    v79 = *((_DWORD *)v4 + 38);
    if ( v79 )
    {
      for ( j = 0; j < v79; ++j )
      {
        v81 = (_DWORD *)(v4[18] + 104LL * (int)j);
        if ( v81[9] )
        {
          v82 = *(_QWORD *)v81;
          regmap_write(*(_QWORD *)(*(_QWORD *)v81 + 8LL), (unsigned int)(v81[2] + 208), 165);
          regmap_write(*(_QWORD *)(v82 + 8), (unsigned int)(v81[2] + v81[9] + 225), (unsigned int)v81[10]);
          v79 = *((_DWORD *)v4 + 38);
        }
      }
    }
    v32 = lpg_add_pwm(v4);
    goto LABEL_145;
  }
  v44 = (char *)next_available_child;
  v95 = v2;
  while ( 1 )
  {
    memset(v100, 0, 32);
    v99 = nullptr;
    v98 = 0;
    v45 = of_property_read_variable_u32_array(v44, "color", &v98, 1, 0);
    if ( (v45 & 0x80000000) != 0 && v45 != -22 )
    {
      v32 = dev_err_probe(*v4, v45, "failed to parse \"color\" of %pOF\n", v44);
      if ( v32 )
        goto LABEL_145;
      goto LABEL_51;
    }
    if ( v98 == 9 )
    {
      v46 = of_get_next_available_child(v44, 0);
      if ( v46 )
      {
        v47 = v46;
        v48 = 0;
        do
        {
          ++v48;
          v47 = of_get_next_available_child(v44, v47);
        }
        while ( v47 );
      }
      else
      {
        v48 = 0;
      }
    }
    else
    {
      v48 = 1;
    }
    if ( v48 < 0 )
      v49 = -1;
    else
      v49 = 8LL * v48 + 928;
    v50 = devm_kmalloc(*v4, v49, 3520);
    if ( !v50 )
      goto LABEL_165;
    *(_QWORD *)v50 = v4;
    if ( (v49 & 0xFFFFFFFFFFFFFFFCLL) == 0x398 )
      goto LABEL_167;
    v51 = v98;
    *(_DWORD *)(v50 + 920) = v48;
    v96 = v50;
    if ( v51 == 9 )
    {
      if ( v48 < 0 )
        goto LABEL_165;
      v52 = 16LL * v48;
      v97 = devm_kmalloc(*v4, v52, 3520);
      if ( !v97 )
        goto LABEL_165;
      v53 = of_get_next_available_child(v44, 0);
      if ( v53 )
      {
        v54 = v53;
        v55 = 0;
        v56 = v96 + 928;
        do
        {
          v57 = 8LL * v55;
          v32 = lpg_parse_channel(v4, v54, v56 + v57);
          if ( (v32 & 0x80000000) != 0 )
            goto LABEL_145;
          if ( v55 < -116 )
            goto LABEL_167;
          v58 = 8LL * v55 + 928;
          if ( v49 < v58 )
            goto LABEL_167;
          if ( v49 - v58 < 8 )
            goto LABEL_167;
          v59 = 16LL * v55;
          if ( v52 <= v59 )
            goto LABEL_167;
          if ( v49 < v57 + 928 )
            goto LABEL_167;
          if ( v49 - (v57 + 928) < 8 )
            goto LABEL_167;
          if ( v55 < 0 )
            goto LABEL_167;
          if ( v52 <= v59 )
            goto LABEL_167;
          v60 = v52 >= (v59 | 8);
          v61 = (_DWORD *)(v97 + v59);
          *v61 = *(_DWORD *)(*(_QWORD *)(v56 + 8LL * v55) + 32LL);
          if ( !v60 )
            goto LABEL_167;
          v61[2] = 0;
          ++v55;
          v54 = of_get_next_available_child(v44, v54);
        }
        while ( v54 );
      }
      v62 = v49 & 0xFFFFFFFFFFFFFFF8LL;
      if ( (v49 & 0xFFFFFFFFFFFFFFF8LL) == 0x390 )
        goto LABEL_167;
      v63 = v96;
      *(_QWORD *)(v96 + 912) = v97;
      if ( (v49 & 0xFFFFFFFFFFFFFFFCLL) == 0x388 )
        goto LABEL_167;
      *(_DWORD *)(v96 + 904) = v48;
      if ( v62 == 496 )
        goto LABEL_167;
      if ( (v49 & 0xFFFFFFFFFFFFFFF8LL) == 0x1F0 )
        goto LABEL_167;
      *(_QWORD *)(v96 + 496) = lpg_brightness_mc_set;
      if ( v62 == 512 || (v49 & 0xFFFFFFFFFFFFFFF8LL) == 0x200 )
        goto LABEL_167;
      v64 = *((_DWORD *)v4 + 20);
      v65 = v96 + 456;
      *(_QWORD *)(v96 + 512) = lpg_blink_mc_set;
      if ( !v64 && !v4[13] )
      {
        v66 = -568;
        v69 = 456;
        goto LABEL_108;
      }
      if ( v62 == 520 )
        goto LABEL_167;
      if ( (v49 & 0xFFFFFFFFFFFFFFF8LL) == 0x208 )
        goto LABEL_167;
      *(_QWORD *)(v96 + 520) = lpg_pattern_mc_set;
      if ( v62 == 528 || (v49 & 0xFFFFFFFFFFFFFFF8LL) == 0x210 )
        goto LABEL_167;
      v66 = -568;
      v67 = 528;
      v68 = lpg_pattern_mc_clear;
      v69 = 456;
    }
    else
    {
      v32 = lpg_parse_channel(v4, v44, v50 + 928);
      if ( (v32 & 0x80000000) != 0 )
        goto LABEL_145;
      v70 = v49 & 0xFFFFFFFFFFFFFFF8LL;
      if ( (v49 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
        goto LABEL_167;
      v63 = v96;
      *(_QWORD *)(v96 + 48) = lpg_brightness_single_set;
      if ( v70 == 64 || (v49 & 0xFFFFFFFFFFFFFFF8LL) == 0x40 )
        goto LABEL_167;
      v71 = *((_DWORD *)v4 + 20);
      v65 = v96 + 8;
      *(_QWORD *)(v96 + 64) = lpg_blink_single_set;
      if ( !v71 && !v4[13] )
      {
        v66 = -120;
        v69 = 8;
        goto LABEL_108;
      }
      if ( v70 == 72 )
        goto LABEL_167;
      if ( (v49 & 0xFFFFFFFFFFFFFFF8LL) == 0x48 )
        goto LABEL_167;
      *(_QWORD *)(v96 + 72) = lpg_pattern_single_set;
      if ( v70 == 80 || (v49 & 0xFFFFFFFFFFFFFFF8LL) == 0x50 )
        goto LABEL_167;
      v66 = -120;
      v67 = 80;
      v68 = lpg_pattern_single_clear;
      v69 = 8;
    }
    *(_QWORD *)(v63 + v67) = v68;
LABEL_108:
    property = of_get_property(v44, "linux,default-trigger", 0);
    if ( v66 + v49 < 8 )
      goto LABEL_167;
    if ( v49 < v69 + 112 )
      goto LABEL_167;
    if ( v49 - (v69 + 112) < 8 )
      goto LABEL_167;
    v73 = v69 + 12;
    *(_QWORD *)(v65 + 112) = property;
    if ( v49 < v69 + 12 || v49 - (v69 + 12) < 4 )
      goto LABEL_167;
    v74 = v4[13] ? 255 : 511;
    *(_DWORD *)(v65 + 12) = v74;
    if ( !(unsigned int)of_property_read_string(v44, "default-state", &v99) && *v99 == 111 && v99[1] == 110 && !v99[2] )
    {
      if ( v49 < v73 || v49 - v73 < 4 || v49 < v69 + 8 || v49 - (v69 + 8) < 4 )
        goto LABEL_167;
      v75 = *(unsigned int *)(v65 + 12);
      *(_DWORD *)(v65 + 8) = v75;
    }
    else
    {
      if ( v49 < v69 + 8 || v49 - (v69 + 8) < 4 )
        goto LABEL_167;
      v75 = 0;
      *(_DWORD *)(v65 + 8) = 0;
    }
    if ( v49 < v69 + 40 || v49 - (v69 + 40) < 8 )
      goto LABEL_167;
    v76 = *(void (__fastcall **)(__int64, __int64))(v65 + 40);
    if ( *((_DWORD *)v76 - 1) != 2007718315 )
      __break(0x8228u);
    v76(v65, v75);
    v77 = *v4;
    v100[0] = v44 + 24;
    v78 = v98 == 9
        ? devm_led_classdev_multicolor_register_ext(v77, v96 + 456, v100)
        : devm_led_classdev_register_ext(v77, v96 + 8, v100);
    v24 = v78;
    if ( v78 )
      break;
    v2 = v95;
LABEL_51:
    v44 = (char *)of_get_next_available_child(*(_QWORD *)(v2 + 760), v44);
    if ( !v44 )
      goto LABEL_139;
  }
  if ( v49 - v69 < 8 )
LABEL_167:
    __break(1u);
  dev_err_probe(*v4, v78, "unable to register %s\n", *(const char **)v65);
LABEL_166:
  _ReadStatusReg(SP_EL0);
  return v24;
}
