__int64 __fastcall lt9611uxc_probe(_QWORD *a1)
{
  __int64 result; // x0
  __int64 (*v2)(void); // x8
  __int64 v3; // x0
  __int64 v4; // x24
  __int64 v5; // x20
  void *v6; // x0
  __int64 remote_port_parent; // x0
  int v8; // w8
  unsigned int v9; // w19
  int named_gpio; // w0
  int v11; // w8
  int v12; // w0
  _QWORD *v13; // x21
  char *child_by_name; // x22
  __int64 next_child; // x0
  int v16; // w28
  __int64 v17; // x23
  int v18; // w27
  __int64 v19; // x0
  __int64 v20; // x20
  __int64 property; // x25
  __int64 v22; // x24
  __int16 v23; // w10
  __int16 v24; // w11
  _QWORD *v25; // x0
  __int16 v26; // w8
  __int16 v27; // w9
  __int16 v28; // w10
  __int16 v29; // w11
  __int16 v30; // w8
  __int16 v31; // w9
  __int16 v32; // w10
  __int16 v33; // w8
  __int16 v34; // w9
  int v35; // w8
  bool v36; // zf
  int v37; // w10
  _QWORD *v38; // x1
  void *v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  _QWORD *v42; // x26
  void *v43; // x0
  __int64 v44; // x20
  __int64 next_available_child; // x0
  __int64 v46; // x1
  unsigned int v47; // w19
  __int64 v48; // x21
  int v49; // w0
  __int64 v50; // x0
  unsigned __int64 *v51; // x19
  __int64 v52; // x20
  __int64 v53; // x0
  __int64 v54; // x0
  unsigned __int64 v55; // x8
  int v56; // w0
  __int64 v57; // x21
  __int64 v58; // x23
  unsigned __int64 *v59; // x22
  int is_enabled; // w0
  int v61; // w8
  int v62; // w20
  int v63; // w0
  int v64; // w8
  int v65; // w20
  unsigned __int64 v66; // t1
  __int64 v67; // x0
  int v68; // w20
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x8
  __int16 v73; // w10
  __int64 v74; // x0
  int group; // w0
  __int64 v76; // x8
  unsigned __int64 *v77; // x19
  __int64 v78; // x21
  bool v79; // cc
  int v80; // w8
  int v81; // w8
  __int64 v82; // x0
  unsigned __int64 *v83; // x19
  int v84; // w24
  unsigned __int64 v85; // x0
  const char *v86; // x22
  const char *v87; // x23
  __int64 v88; // x21
  int variable_u32_array; // w0
  char *v90; // x24
  __int64 v91; // x26
  size_t v92; // x0
  unsigned __int64 v93; // x2
  __int64 v94; // x24
  int v95; // w8
  int v96; // w8
  int v97; // w8
  int v98; // w8
  int v99; // w8
  int v100; // w8
  void *v101; // x8
  unsigned __int64 v102; // x23
  __int64 v103; // x24
  unsigned __int64 v104; // x0
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 v107; // x0
  _QWORD *v108; // [xsp+10h] [xbp-90h]
  int v109; // [xsp+1Ch] [xbp-84h]
  __int64 v110; // [xsp+20h] [xbp-80h]
  __int64 v112; // [xsp+30h] [xbp-70h] BYREF
  __int64 v113; // [xsp+38h] [xbp-68h] BYREF
  __int64 v114; // [xsp+40h] [xbp-60h] BYREF
  char *string; // [xsp+48h] [xbp-58h] BYREF
  __int64 v116; // [xsp+50h] [xbp-50h]
  __int64 v117; // [xsp+58h] [xbp-48h]
  __int64 v118; // [xsp+60h] [xbp-40h]
  __int64 v119; // [xsp+68h] [xbp-38h]
  __int64 v120; // [xsp+70h] [xbp-30h]
  __int64 v121; // [xsp+78h] [xbp-28h]
  __int64 v122; // [xsp+80h] [xbp-20h]
  __int64 v123; // [xsp+88h] [xbp-18h]
  __int64 v124; // [xsp+90h] [xbp-10h]
  __int64 v125; // [xsp+98h] [xbp-8h]

  v125 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a1[97] )
  {
    v2 = *(__int64 (**)(void))(*(_QWORD *)(a1[3] + 16LL) + 32LL);
    if ( *((_DWORD *)v2 - 1) != 2093148950 )
      __break(0x8228u);
    if ( (v2() & 1) == 0 )
    {
      printk(&unk_B380, "lt9611uxc_probe");
      result = 4294967277LL;
      goto LABEL_4;
    }
    printk(&unk_AA71, "lt9611uxc_probe");
    v3 = devm_kmalloc(a1 + 4, 4032, 3520);
    if ( !v3 )
    {
      result = 4294967284LL;
      goto LABEL_4;
    }
    v4 = v3;
    v5 = a1[97];
    if ( !of_graph_get_endpoint_by_regs(v5, 0, 0) )
    {
      v6 = &unk_ABCE;
LABEL_15:
      printk(v6, "lt9611uxc_parse_dt");
      v8 = -19;
LABEL_16:
      v9 = v8;
      printk(&unk_AB63, "lt9611uxc_probe");
      result = v9;
      goto LABEL_4;
    }
    remote_port_parent = of_graph_get_remote_port_parent();
    *(_QWORD *)(v4 + 304) = remote_port_parent;
    if ( !remote_port_parent )
    {
      v6 = &unk_A75A;
      goto LABEL_15;
    }
    named_gpio = of_get_named_gpio(v5, "lt,irq-gpio", 0);
    v11 = 0;
    *(_DWORD *)(v4 + 3124) = named_gpio;
    if ( named_gpio < 0 )
    {
      printk(&unk_B444, "lt9611uxc_parse_dt");
      v11 = -22;
    }
    v109 = v11;
    v12 = of_get_named_gpio(v5, "lt,reset-gpio", 0);
    *(_DWORD *)(v4 + 3128) = v12;
    if ( v12 < 0 )
    {
      printk(&unk_ABEF, "lt9611uxc_parse_dt");
      v109 = -22;
    }
    *(_DWORD *)(v4 + 3132) = of_get_named_gpio(v5, "lt,hdmi-ps-gpio", 0);
    *(_DWORD *)(v4 + 3136) = of_get_named_gpio(v5, "lt,hdmi-en-gpio", 0);
    *(_DWORD *)(v4 + 3140) = of_get_named_gpio(v5, "lt,hdmi-3p3-en", 0);
    *(_DWORD *)(v4 + 3144) = of_get_named_gpio(v5, "lt,hdmi-1p2-en", 0);
    v13 = (_QWORD *)(v4 + 3184);
    *(_BYTE *)(v4 + 3120) = of_find_property(v5, "lt,ac-mode", 0) != 0;
    *(_QWORD *)(v4 + 3184) = v4 + 3184;
    *(_QWORD *)(v4 + 3192) = v4 + 3184;
    v113 = 0;
    v114 = 0;
    v112 = 0;
    child_by_name = (char *)of_get_child_by_name(v5, "lt,customize-modes");
    v110 = v4;
    v108 = a1 + 4;
    if ( !child_by_name )
    {
      v123 = 0;
      v124 = 0;
      v121 = 0;
      v122 = 0;
      v119 = 0;
      v120 = 0;
      v117 = 0;
      v118 = 0;
      string = nullptr;
      v116 = 0;
      if ( (unsigned int)_of_parse_phandle_with_args(v5, "lt,customize-modes", 0, 0, 0, &string)
        || (child_by_name = string) == nullptr )
      {
        printk(&unk_AF75, "lt9611uxc_parse_dt_modes");
        goto LABEL_64;
      }
    }
    next_child = of_get_next_child(child_by_name, 0);
    if ( !next_child )
    {
      v16 = 0;
LABEL_26:
      *(_DWORD *)(v4 + 3176) = v16;
LABEL_64:
      v8 = v109;
      if ( v109 )
        goto LABEL_16;
      HIDWORD(v114) = 0;
      v40 = a1[97];
      *(_DWORD *)(v4 + 3148) = 0;
      v41 = of_get_child_by_name(v40, "lt,supply-entries");
      v42 = a1 + 4;
      if ( !v41 )
      {
        v43 = &unk_A8A2;
LABEL_73:
        printk(v43, "lt9611uxc_get_dt_supply");
        goto LABEL_74;
      }
      v44 = v41;
      next_available_child = of_get_next_available_child(v41, 0);
      if ( !next_available_child )
      {
        *(_DWORD *)(v4 + 3148) = 0;
LABEL_72:
        v43 = &unk_B211;
        goto LABEL_73;
      }
      v46 = next_available_child;
      v47 = 0;
      do
      {
        ++v47;
        v46 = of_get_next_available_child(v44, v46);
      }
      while ( v46 );
      *(_DWORD *)(v4 + 3148) = v47;
      if ( !v47 )
        goto LABEL_72;
      v67 = devm_kmalloc(v108, 72LL * v47, 3520);
      *(_QWORD *)(v4 + 3152) = v67;
      if ( !v67 )
      {
        LODWORD(v44) = -12;
LABEL_191:
        printk(&unk_B4B3, "lt9611uxc_probe");
        goto LABEL_118;
      }
      v82 = of_get_next_available_child(v44, 0);
      if ( v82 )
      {
        v88 = v82;
        v83 = nullptr;
        v86 = "lt,supply-post-on-sleep";
        v87 = "lt,supply-post-off-sleep";
        while ( 1 )
        {
          string = nullptr;
          variable_u32_array = of_property_read_string(v88, "lt,supply-name", &string);
          if ( variable_u32_array )
          {
            v101 = &unk_B072;
            goto LABEL_168;
          }
          v90 = string;
          v91 = *(_QWORD *)(v110 + 3152);
          v92 = strnlen(string, 0x20u);
          if ( v92 == -1 )
          {
            _fortify_panic(2, -1, 0);
LABEL_184:
            _fortify_panic(7, 32, v93);
            goto LABEL_185;
          }
          if ( v92 == 32 )
            v93 = 32;
          else
            v93 = v92 + 1;
          if ( v93 >= 0x21 )
            goto LABEL_184;
          sized_strscpy(v91 + 72LL * (int)v83 + 8, v90);
          variable_u32_array = of_property_read_variable_u32_array(
                                 v88,
                                 "lt,supply-min-voltage",
                                 (char *)&v114 + 4,
                                 1,
                                 0);
          if ( variable_u32_array < 0 )
          {
            v101 = &unk_B3B4;
            goto LABEL_168;
          }
          *(_DWORD *)(*(_QWORD *)(v110 + 3152) + 72LL * (int)v83 + 40) = HIDWORD(v114);
          variable_u32_array = of_property_read_variable_u32_array(
                                 v88,
                                 "lt,supply-max-voltage",
                                 (char *)&v114 + 4,
                                 1,
                                 0);
          if ( variable_u32_array < 0 )
            break;
          v94 = 72LL * (int)v83;
          *(_DWORD *)(*(_QWORD *)(v110 + 3152) + v94 + 44) = HIDWORD(v114);
          if ( (int)of_property_read_variable_u32_array(v88, "lt,supply-enable-load", (char *)&v114 + 4, 1, 0) >= 0 )
            v95 = HIDWORD(v114);
          else
            v95 = 0;
          *(_DWORD *)(*(_QWORD *)(v110 + 3152) + v94 + 48) = v95;
          if ( (int)of_property_read_variable_u32_array(v88, "lt,supply-disable-load", (char *)&v114 + 4, 1, 0) >= 0 )
            v96 = HIDWORD(v114);
          else
            v96 = 0;
          *(_DWORD *)(*(_QWORD *)(v110 + 3152) + v94 + 52) = v96;
          if ( (int)of_property_read_variable_u32_array(v88, "lt,supply-pre-on-sleep", (char *)&v114 + 4, 1, 0) >= 0 )
            v97 = HIDWORD(v114);
          else
            v97 = 0;
          *(_DWORD *)(*(_QWORD *)(v110 + 3152) + v94 + 56) = v97;
          if ( (int)of_property_read_variable_u32_array(v88, "lt,supply-pre-off-sleep", (char *)&v114 + 4, 1, 0) >= 0 )
            v98 = HIDWORD(v114);
          else
            v98 = 0;
          *(_DWORD *)(*(_QWORD *)(v110 + 3152) + v94 + 64) = v98;
          if ( (int)of_property_read_variable_u32_array(v88, "lt,supply-post-on-sleep", (char *)&v114 + 4, 1, 0) >= 0 )
            v99 = HIDWORD(v114);
          else
            v99 = 0;
          *(_DWORD *)(*(_QWORD *)(v110 + 3152) + v94 + 60) = v99;
          v83 = (unsigned __int64 *)(unsigned int)((_DWORD)v83 + 1);
          if ( (int)of_property_read_variable_u32_array(v88, "lt,supply-post-off-sleep", (char *)&v114 + 4, 1, 0) >= 0 )
            v100 = HIDWORD(v114);
          else
            v100 = 0;
          *(_DWORD *)(*(_QWORD *)(v110 + 3152) + v94 + 68) = v100;
          v88 = of_get_next_available_child(v44, v88);
          if ( !v88 )
            goto LABEL_126;
        }
        v101 = &unk_B2E0;
LABEL_168:
        LODWORD(v44) = variable_u32_array;
        printk(v101, "lt9611uxc_get_dt_supply");
        goto LABEL_189;
      }
LABEL_126:
      v42 = a1 + 4;
      v83 = *(unsigned __int64 **)(v110 + 3152);
      if ( v83 )
      {
        v84 = *(_DWORD *)(v110 + 3148);
        if ( v84 >= 1 )
        {
          v85 = regulator_get(v108, v83 + 1);
          LODWORD(v86) = 0;
          *v83 = v85;
          if ( v85 && v85 <= 0xFFFFFFFFFFFFF000LL )
          {
            LODWORD(v44) = regulator_set_voltage();
            if ( (v44 & 0x80000000) != 0 )
            {
              LODWORD(v86) = 0;
              v87 = (const char *)v83;
LABEL_177:
              printk(&unk_AFA4, "lt9611uxc_config_vreg");
              while ( 1 )
              {
                regulator_put(*(_QWORD *)v87);
LABEL_185:
                LODWORD(v86) = (_DWORD)v86 - 1;
                *(_QWORD *)v87 = 0;
                if ( (int)v86 < 0 )
                  break;
                v87 = (const char *)&v83[9 * (unsigned int)v86];
                regulator_set_load(*(_QWORD *)v87, 0);
              }
              v42 = a1 + 4;
              if ( (_DWORD)v44 )
              {
LABEL_189:
                if ( *(_QWORD *)(v110 + 3152) )
                {
                  *(_QWORD *)(v110 + 3152) = 0;
                  *(_DWORD *)(v110 + 3148) = 0;
                }
                goto LABEL_191;
              }
              goto LABEL_74;
            }
            v42 = a1 + 4;
            v102 = 0;
            LODWORD(v86) = 0;
            v103 = 72LL * (unsigned int)v84 - 72;
            while ( 1 )
            {
              if ( v103 == v102 )
                goto LABEL_74;
              v104 = regulator_get(v108, &v83[v102 / 8 + 10]);
              v83[v102 / 8 + 9] = v104;
              if ( !v104 || v104 >= 0xFFFFFFFFFFFFF001LL )
                break;
              LODWORD(v44) = regulator_set_voltage();
              v102 += 72LL;
              LODWORD(v86) = (_DWORD)v86 + 1;
              if ( (v44 & 0x80000000) != 0 )
              {
                v87 = (const char *)&v83[v102 / 8];
                goto LABEL_177;
              }
            }
            LODWORD(v86) = (_DWORD)v86 + 1;
            v87 = (const char *)&v83[v102 / 8 + 9];
          }
          else
          {
            LODWORD(v44) = 0;
            v87 = (const char *)v83;
          }
          printk(&unk_AA9C, "lt9611uxc_config_vreg");
          goto LABEL_185;
        }
      }
LABEL_74:
      v48 = v110;
      *(_QWORD *)v110 = v42;
      *(_QWORD *)(v110 + 3160) = a1;
      v49 = lt9611uxc_gpio_configure(v110, 1);
      if ( v49 )
      {
        LODWORD(v44) = v49;
        printk(&unk_B12E, "lt9611uxc_probe");
LABEL_117:
        lt9611uxc_put_dt_supply(v42, v48);
LABEL_118:
        result = (unsigned int)v44;
        goto LABEL_4;
      }
      if ( (*(_DWORD *)(v110 + 3136) & 0x80000000) == 0 )
      {
        v50 = ((__int64 (*)(void))gpio_to_desc)();
        gpiod_set_raw_value(v50, 1);
        msleep(20);
      }
      v51 = *(unsigned __int64 **)(v110 + 3152);
      v52 = *(unsigned int *)(v110 + 3148);
      if ( (*(_DWORD *)(v110 + 3140) & 0x80000000) != 0 )
      {
        if ( (*(_DWORD *)(v110 + 3144) & 0x80000000) != 0 )
        {
LABEL_79:
          if ( (int)v52 < 1 )
            goto LABEL_105;
          goto LABEL_84;
        }
      }
      else
      {
        v53 = ((__int64 (*)(void))gpio_to_desc)();
        gpiod_set_raw_value(v53, 1);
        if ( (*(_DWORD *)(v110 + 3144) & 0x80000000) != 0 )
          goto LABEL_79;
      }
      v54 = ((__int64 (*)(void))gpio_to_desc)();
      gpiod_set_raw_value(v54, 1);
      if ( (int)v52 < 1 )
        goto LABEL_105;
LABEL_84:
      v55 = *v51;
      v56 = 0;
      LODWORD(v57) = 0;
      if ( *v51 && v55 <= 0xFFFFFFFFFFFFF000LL )
      {
        v57 = 0;
        v58 = v52 - 1;
        v59 = v51;
        while ( 1 )
        {
          is_enabled = regulator_is_enabled(v55);
          v61 = *((_DWORD *)v59 + 14);
          v62 = is_enabled;
          if ( v61 && !is_enabled )
            usleep_range_state(1000 * v61, 1000 * v61, 2);
          v63 = regulator_set_load(*v59, *((unsigned int *)v59 + 12));
          if ( v63 < 0 )
          {
            v68 = v63;
            printk(&unk_AEE4, "lt9611uxc_enable_vreg");
            goto LABEL_102;
          }
          v56 = regulator_enable(*v59);
          v64 = *((_DWORD *)v59 + 15);
          if ( v64 && !v62 )
          {
            v65 = v56;
            usleep_range_state(1000 * v64, 1000 * v64, 2);
            v56 = v65;
          }
          if ( v56 < 0 )
            break;
          if ( v58 == v57 )
            goto LABEL_104;
          v66 = v59[9];
          v59 += 9;
          v55 = v66;
          ++v57;
          if ( !v66 || v55 >= 0xFFFFFFFFFFFFF001LL )
            goto LABEL_101;
        }
        v68 = v56;
        printk(&unk_A777, "lt9611uxc_enable_vreg");
        regulator_set_load(*v59, *((unsigned int *)v59 + 13));
      }
      else
      {
LABEL_101:
        v68 = v56;
        printk(&unk_A5B2, "lt9611uxc_enable_vreg");
      }
LABEL_102:
      if ( (_DWORD)v57 )
      {
        v76 = (unsigned int)(v57 - 1);
        v77 = &v51[9 * (unsigned int)v76];
        v78 = v76 + 1;
        do
        {
          v80 = *((_DWORD *)v77 + 16);
          if ( v80 )
            usleep_range_state(1000 * v80, 1000 * v80, 2);
          regulator_set_load(*v77, *((unsigned int *)v77 + 13));
          regulator_disable(*v77);
          v81 = *((_DWORD *)v77 + 17);
          if ( v81 )
            usleep_range_state(1000 * v81, 1000 * v81, 2);
          v79 = v78-- <= 1;
          v77 -= 9;
        }
        while ( !v79 );
      }
      v56 = v68;
LABEL_104:
      v48 = v110;
      if ( v56 )
      {
        LODWORD(v44) = v56;
        printk(&unk_B4FD, "lt9611uxc_probe");
LABEL_116:
        lt9611uxc_gpio_configure(v48, 0);
        goto LABEL_117;
      }
LABEL_105:
      v69 = gpio_to_desc(*(unsigned int *)(v48 + 3128));
      gpiod_set_raw_value(v69, 1);
      msleep(20);
      v70 = gpio_to_desc(*(unsigned int *)(v48 + 3128));
      gpiod_set_raw_value(v70, 0);
      msleep(20);
      v71 = gpio_to_desc(*(unsigned int *)(v48 + 3128));
      gpiod_set_raw_value(v71, 1);
      msleep(300);
      BYTE4(v114) = 0;
      LOBYTE(v114) = 0;
      lt9611uxc_ctl_en(v48);
      v72 = *(_QWORD *)(v48 + 3160);
      v73 = *(_WORD *)(v72 + 2);
      *(_DWORD *)((char *)&string + 2) = 0x20000;
      *(_QWORD *)(v48 + 3760) = 0;
      *(_QWORD *)(v48 + 3768) = 0;
      *(_QWORD *)(v48 + 3776) = 0;
      *(_QWORD *)(v48 + 3784) = 0;
      *(_QWORD *)(v48 + 3792) = 0;
      *(_QWORD *)(v48 + 3800) = 0;
      *(_QWORD *)(v48 + 3808) = 0;
      *(_QWORD *)(v48 + 3816) = 0;
      *(_QWORD *)(v48 + 3824) = 0;
      *(_QWORD *)(v48 + 3832) = 0;
      *(_QWORD *)(v48 + 3840) = 0;
      *(_QWORD *)(v48 + 3848) = 0;
      *(_QWORD *)(v48 + 3856) = 0;
      *(_QWORD *)(v48 + 3864) = 0;
      *(_QWORD *)(v48 + 3872) = 0;
      *(_QWORD *)(v48 + 3880) = 0;
      *(_WORD *)(v48 + 3760) = -32257;
      v74 = *(_QWORD *)(v72 + 24);
      LOWORD(string) = v73;
      HIWORD(string) = 0;
      v116 = v48 + 3760;
      if ( (int)i2c_transfer(v74, &string, 1) <= 0 )
        printk(&unk_A9C9, "lt9611uxc_write_byte");
      if ( (unsigned int)lt9611uxc_read((_QWORD *)v48, 0, (char *)&v114 + 4, 1u)
        || (unsigned int)lt9611uxc_read((_QWORD *)v48, 1, &v114, 1u) )
      {
        printk(&unk_A961, "lt9611uxc_read_device_id");
        lt9611uxc_ctl_disable(v48);
        msleep(50);
        printk(&unk_B51A, "lt9611uxc_probe");
        LODWORD(v44) = -1;
      }
      else
      {
        printk(&unk_B578, "lt9611uxc_read_device_id");
        lt9611uxc_ctl_disable(v48);
        msleep(50);
        a1[23] = v48;
        group = sysfs_create_group(v42, &lt9611uxc_sysfs_attr_grp);
        if ( group )
        {
          LODWORD(v44) = group;
          printk(&unk_B305, "lt9611uxc_sysfs_init");
          printk(&unk_A741, "lt9611uxc_probe");
        }
        else
        {
          if ( (unsigned __int8)lt9611uxc_get_version((_QWORD *)v48) )
          {
            printk(&unk_B4D2, "lt9611uxc_probe");
            _mutex_init(v48 + 328, "&pdata->lock", &lt9611uxc_probe___key);
            _init_waitqueue_head(v48 + 3480, "&pdata->edid_wq", &lt9611uxc_probe___key_37);
            *(_QWORD *)(v48 + 144) = a1[97];
            *(_QWORD *)(v48 + 176) = &lt9611uxc_bridge_funcs;
            drm_bridge_add(v48 + 8);
            v105 = alloc_workqueue("%s", (const char *)0x6000A);
            *(_QWORD *)(v48 + 3440) = v105;
            if ( v105 )
            {
              *(_QWORD *)(v110 + 3448) = 0xFFFFFFFE00000LL;
              *(_QWORD *)(v110 + 3456) = v110 + 3456;
              *(_QWORD *)(v110 + 3464) = v110 + 3456;
              v106 = *(unsigned int *)(v110 + 3124);
              *(_QWORD *)(v110 + 3472) = lt9611uxc_hpd_work;
              v107 = gpio_to_desc(v106);
              *(_DWORD *)(v110 + 3116) = gpiod_to_irq(v107);
              result = request_threaded_irq();
              if ( !(_DWORD)result )
                goto LABEL_4;
              LODWORD(v44) = result;
              printk(&unk_A8CE, "lt9611uxc_probe");
            }
            else
            {
              printk(&unk_B052, "lt9611uxc_probe");
              LODWORD(v44) = 0;
            }
          }
          else
          {
            result = request_firmware_nowait(
                       &_this_module,
                       1,
                       "lt9611uxc_fw.bin",
                       v108,
                       3264,
                       v48,
                       lt9611uxc_firmware_cb);
            if ( !(_DWORD)result )
              goto LABEL_4;
            LODWORD(v44) = result;
            printk(&unk_A78F, "lt9611uxc_probe");
          }
          v48 = v110;
        }
        v42 = a1 + 4;
      }
      goto LABEL_116;
    }
    v17 = next_child;
    v16 = 0;
    v18 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v19 = _kmalloc_cache_noprof(gpiod_set_raw_value, 3520, 120);
      v20 = v19;
      if ( v19 )
        break;
      printk(&unk_AC0F, "lt9611uxc_parse_dt_modes");
LABEL_29:
      v17 = of_get_next_child(child_by_name, v17);
      if ( !v17 )
        goto LABEL_26;
    }
    if ( (of_property_read_variable_u32_array(v17, "lt,mode-h-active", v19 + 4, 1, 0) & 0x80000000) != 0 )
    {
      v39 = &unk_AD20;
    }
    else if ( (of_property_read_variable_u32_array(v17, "lt,mode-h-front-porch", (char *)&v114 + 4, 1, 0) & 0x80000000) != 0 )
    {
      v39 = &unk_AEB9;
    }
    else if ( (of_property_read_variable_u32_array(v17, "lt,mode-h-pulse-width", &v114, 1, 0) & 0x80000000) != 0 )
    {
      v39 = &unk_A6B6;
    }
    else if ( (of_property_read_variable_u32_array(v17, "lt,mode-h-back-porch", (char *)&v113 + 4, 1, 0) & 0x80000000) != 0 )
    {
      v39 = &unk_AD86;
    }
    else
    {
      property = of_find_property(v17, "lt,mode-h-active-high", 0);
      if ( (of_property_read_variable_u32_array(v17, "lt,mode-v-active", v20 + 14, 1, 0) & 0x80000000) != 0 )
      {
        v39 = &unk_B164;
      }
      else if ( (of_property_read_variable_u32_array(v17, "lt,mode-v-front-porch", &v113, 1, 0) & 0x80000000) != 0 )
      {
        v39 = &unk_A907;
      }
      else if ( (of_property_read_variable_u32_array(v17, "lt,mode-v-pulse-width", (char *)&v112 + 4, 1, 0) & 0x80000000) != 0 )
      {
        v39 = &unk_B1C3;
      }
      else
      {
        if ( (of_property_read_variable_u32_array(v17, "lt,mode-v-back-porch", &v112, 1, 0) & 0x80000000) == 0 )
        {
          v22 = of_find_property(v17, "lt,mode-v-active-high", 0);
          if ( (of_property_read_variable_u32_array(v17, "lt,mode-clock-in-khz", v20, 1, 0) & 0x80000000) == 0 )
          {
            v23 = *(_WORD *)(v20 + 14);
            v24 = v113;
            v25 = (_QWORD *)(v20 + 64);
            v26 = *(_WORD *)(v20 + 4) + WORD2(v114);
            v27 = v114;
            *(_WORD *)(v20 + 6) = v26;
            v28 = v23 + v24;
            v29 = WORD2(v112);
            v30 = v26 + v27;
            v31 = WORD2(v113);
            *(_WORD *)(v20 + 16) = v28;
            *(_WORD *)(v20 + 8) = v30;
            v32 = v28 + v29;
            v33 = v30 + v31;
            v34 = v112;
            *(_WORD *)(v20 + 18) = v32;
            *(_WORD *)(v20 + 10) = v33;
            if ( property )
              v35 = 1;
            else
              v35 = 2;
            v36 = v22 == 0;
            v4 = v110;
            *(_WORD *)(v20 + 20) = v32 + v34;
            if ( v36 )
              v37 = 8;
            else
              v37 = 4;
            v38 = *(_QWORD **)(v110 + 3192);
            v18 |= v35 | v37;
            *(_DWORD *)(v20 + 24) = v18;
            if ( v25 == v13 || v38 == v25 || (_QWORD *)*v38 != v13 )
            {
              _list_add_valid_or_report();
            }
            else
            {
              *(_QWORD *)(v110 + 3192) = v25;
              *(_QWORD *)(v20 + 64) = v13;
              *(_QWORD *)(v20 + 72) = v38;
              *v38 = v25;
            }
            ++v16;
            drm_mode_set_name(v20);
            goto LABEL_29;
          }
          printk(&unk_B1EE, "lt9611uxc_parse_dt_modes");
          v4 = v110;
          goto LABEL_60;
        }
        v39 = &unk_A84E;
      }
    }
    printk(v39, "lt9611uxc_parse_dt_modes");
LABEL_60:
    kfree(v20);
    goto LABEL_29;
  }
  printk(&unk_AB3E, "lt9611uxc_probe");
  result = 4294967274LL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
