__int64 __fastcall gpio_keys_probe(_QWORD *a1)
{
  unsigned __int64 v1; // x20
  _QWORD *v2; // x26
  _QWORD *v3; // x23
  unsigned __int64 v4; // x24
  unsigned __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x19
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 device; // x0
  __int64 v13; // x21
  __int64 v14; // x8
  int v15; // w21
  __int64 v16; // x1
  __int64 v17; // x19
  __int64 v18; // x25
  __int64 v19; // x10
  const char *v20; // x8
  unsigned __int64 v21; // x21
  __int64 v22; // x1
  __int64 v23; // x2
  int v24; // w0
  unsigned int v25; // w2
  __int64 v26; // x0
  __int64 v27; // x2
  __int64 v28; // x3
  __int64 v29; // x4
  __int64 v30; // x5
  unsigned __int64 index; // x0
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x5
  unsigned __int64 v36; // x8
  __int64 v37; // x19
  __int64 next_child; // x0
  __int64 v39; // x20
  int v40; // w8
  unsigned __int64 v41; // x19
  unsigned int v42; // w0
  unsigned int v43; // w26
  unsigned __int64 v44; // x19
  int v45; // w8
  int v46; // w8
  void *v47; // x8
  __int64 v48; // x19
  unsigned __int64 v49; // x8
  int v50; // w8
  __int64 v51; // x8
  unsigned int v52; // w8
  __int64 v53; // x1
  int v54; // w0
  __int64 v55; // x3
  unsigned int v56; // w0
  __int64 v57; // x0
  __int64 v58; // x19
  bool v59; // cf
  __int64 v60; // x9
  char v62; // w26
  bool v64; // w23
  int named_gpio; // w0
  int v66; // w0
  unsigned __int64 v67; // x19
  __int64 v68; // x0
  __int64 v69; // x0
  int v70; // w0
  __int64 v71; // x4
  __int64 v72; // x5
  __int64 v73; // x1
  __int64 v74; // x2
  __int64 v75; // x3
  __int64 v76; // x4
  __int64 v77; // x5
  int child_node_count; // w0
  int v79; // w19
  __int64 v80; // x22
  unsigned __int64 v81; // x21
  __int64 v82; // x0
  char v83; // w0
  _QWORD *v84; // x25
  __int64 next_child_node; // x0
  unsigned __int64 v86; // x23
  int v87; // w0
  char v88; // w0
  char v89; // w0
  unsigned __int64 v90; // x8
  __int64 v91; // x8
  void (__fastcall *v92)(unsigned __int64, unsigned __int64); // x8
  int v93; // w0
  const char *v94; // x1
  __int64 v95; // x8
  void (__fastcall *v96)(_QWORD); // x8
  __int64 v97; // x8
  void (*v98)(void); // x8
  _QWORD *v100; // [xsp+8h] [xbp-78h]
  unsigned __int64 v101; // [xsp+10h] [xbp-70h]
  __int64 v102; // [xsp+18h] [xbp-68h]
  unsigned __int64 v103; // [xsp+20h] [xbp-60h]
  int v104; // [xsp+2Ch] [xbp-54h]
  unsigned __int64 v105; // [xsp+30h] [xbp-50h]
  unsigned int v106; // [xsp+38h] [xbp-48h]
  void *v107; // [xsp+38h] [xbp-48h]
  _QWORD *v108; // [xsp+40h] [xbp-40h]
  __int64 v109; // [xsp+48h] [xbp-38h]
  const char *v110; // [xsp+50h] [xbp-30h]
  __int64 v111; // [xsp+58h] [xbp-28h]
  unsigned __int64 v112; // [xsp+60h] [xbp-20h]
  __int64 v113; // [xsp+68h] [xbp-18h]
  __int64 v114; // [xsp+68h] [xbp-18h]
  const char *v115[2]; // [xsp+70h] [xbp-10h] BYREF

  v2 = a1;
  v3 = a1 + 2;
  v115[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[20];
  if ( !v4 )
  {
    child_node_count = device_get_child_node_count(a1 + 2);
    if ( !child_node_count )
    {
      LODWORD(v1) = -19;
      goto LABEL_255;
    }
    v79 = child_node_count;
    v80 = 56LL * child_node_count;
    v81 = v80 + 48;
    v82 = devm_kmalloc(v3, v80 + 48, 3520);
    if ( !v82 )
    {
      LODWORD(v1) = -12;
      goto LABEL_255;
    }
    if ( v80 == -48 )
      goto LABEL_256;
    v4 = v82;
    *(_DWORD *)(v82 + 8) = v79;
    *(_QWORD *)v82 = v82 + 48;
    v83 = device_property_present(v3, "autorepeat");
    if ( v81 < 0x10 )
      goto LABEL_256;
    *(_BYTE *)(v4 + 16) = *(_BYTE *)(v4 + 16) & 0xFE | v83 & 1;
    device_property_read_string(v3, "label", v4 + 40);
    v84 = v3;
    next_child_node = device_get_next_child_node(v3, 0);
    if ( next_child_node )
    {
      v1 = next_child_node;
      v86 = 96;
      v114 = 48 - v80;
      while ( 1 )
      {
        if ( v1 <= 0xFFFFFFFFFFFFF000LL && *(_UNKNOWN **)(v1 + 8) == &of_fwnode_ops )
        {
          v87 = irq_of_parse_and_map(v1 - 24, 0);
          if ( (v86 & 0x8000000000000000LL) != 0
            || v114 + v86 == 96
            || v81 < v86
            || (v86 & 0x8000000000000000LL) != 0
            || v81 < v86
            || v114 + v86 == 96 )
          {
            break;
          }
          *(_DWORD *)(v4 + v86) = v87;
        }
        if ( (unsigned int)fwnode_property_read_u32_array(v1, "linux,code", v4 + v86 - 48, 1) )
        {
          dev_err(v84, "Button without keycode\n");
          if ( v1 <= 0xFFFFFFFFFFFFF000LL )
          {
            v95 = *(_QWORD *)(v1 + 8);
            if ( v95 )
            {
              v96 = *(void (__fastcall **)(_QWORD))(v95 + 8);
              if ( v96 )
              {
                if ( *((_DWORD *)v96 - 1) != -643302289 )
                  __break(0x8228u);
                v96(v1);
              }
            }
          }
          LODWORD(v1) = -22;
          goto LABEL_255;
        }
        fwnode_property_read_string(v1, "label", v4 + v86 - 32);
        if ( (unsigned int)fwnode_property_read_u32_array(v1, "linux,input-type", v4 + v86 - 24, 1) )
        {
          if ( (__int64)(v86 - 24) < 0 || v81 <= v86 - 24 || ((v86 - 24) & 0x8000000000000000LL) != 0 || v81 <= v86 - 24 )
            break;
          *(_DWORD *)(v4 + v86 - 24) = 1;
        }
        v88 = (fwnode_property_present(v1, "wakeup-source") & 1) != 0
            ? 1
            : fwnode_property_present(v1, "gpio-key,wakeup");
        if ( (__int64)(v86 - 20) < 0 )
          break;
        if ( v81 < v86 - 20 )
          break;
        *(_DWORD *)(v4 + v86 - 20) = v88 & 1;
        fwnode_property_read_u32_array(v1, "wakeup-event-action", v4 + v86 - 16, 1);
        v89 = fwnode_property_present(v1, "linux,can-disable");
        if ( (__int64)(v86 - 8) < 0 || v81 <= v86 - 8 )
          break;
        *(_BYTE *)(v4 + v86 - 8) = v89 & 1;
        if ( (unsigned int)fwnode_property_read_u32_array(v1, "debounce-interval", v4 + v86 - 12, 1) )
        {
          v90 = v86 - 12;
          if ( v81 < v86 - 12 || (v90 & 0x8000000000000000LL) != 0 || v81 < v90 )
            break;
          *(_DWORD *)(v4 + v86 - 12) = 5;
        }
        v1 = device_get_next_child_node(v84, v1);
        v86 += 56LL;
        if ( !v1 )
          goto LABEL_222;
      }
LABEL_256:
      __break(1u);
      goto LABEL_257;
    }
LABEL_222:
    v3 = v84;
    if ( v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      LODWORD(v1) = v4;
      goto LABEL_255;
    }
  }
  v5 = *(int *)(v4 + 8);
  v6 = (v5 * (unsigned __int128)0x110uLL) >> 64;
  v5 *= 272LL;
  v59 = __CFADD__(v5, 72);
  v7 = v5 + 72;
  if ( v59 )
    v7 = -1;
  if ( v6 )
    v8 = -1;
  else
    v8 = v7;
  v9 = devm_kmalloc(v3, v8, 3520);
  if ( !v9 )
  {
    v94 = "failed to allocate state\n";
LABEL_228:
    dev_err(v3, v94);
    LODWORD(v1) = -12;
    goto LABEL_255;
  }
  v10 = *(unsigned int *)(v4 + 8);
  v1 = v9;
  if ( (v10 & 0x80000000) != 0 )
  {
LABEL_257:
    *(_QWORD *)(v1 + 64) = 0;
    LODWORD(v1) = -12;
    goto LABEL_255;
  }
  v11 = devm_kmalloc(v3, 2 * v10, 3520);
  *(_QWORD *)(v1 + 64) = v11;
  if ( !v11 )
  {
    LODWORD(v1) = -12;
    goto LABEL_255;
  }
  device = devm_input_allocate_device(v3);
  if ( !device )
  {
    v94 = "failed to allocate input device\n";
    goto LABEL_228;
  }
  *(_QWORD *)v1 = v4;
  if ( (v8 & 0xFFFFFFFFFFFFFFF8LL) == 8 )
    goto LABEL_256;
  v13 = device;
  *(_QWORD *)(v1 + 8) = device;
  _mutex_init(v1 + 16, "&ddata->disable_lock", &gpio_keys_probe___key);
  v2[21] = v1;
  *(_QWORD *)(v13 + 712) = v1;
  v14 = *(_QWORD *)(v4 + 40);
  if ( !v14 )
    v14 = *v2;
  *(_QWORD *)(v13 + 656) = v3;
  *(_QWORD *)v13 = v14;
  *(_QWORD *)(v13 + 8) = "gpio-keys_nubia/input0";
  *(_QWORD *)(v13 + 456) = gpio_keys_open;
  *(_QWORD *)(v13 + 464) = gpio_keys_close;
  *(_QWORD *)(v13 + 24) = 0x100000100010019LL;
  *(_QWORD *)(v13 + 224) = *(_QWORD *)(v1 + 64);
  *(_DWORD *)(v13 + 216) = 2;
  *(_DWORD *)(v13 + 212) = *(_DWORD *)(v4 + 8);
  if ( (*(_BYTE *)(v4 + 16) & 1) != 0 )
    *(_QWORD *)(v13 + 40) |= 0x100000uLL;
  if ( *(int *)(v4 + 8) < 1 )
  {
    v93 = input_register_device(v13);
    if ( !v93 )
    {
LABEL_220:
      device_wakeup_disable(v3);
      device_set_wakeup_capable(v3, 0);
LABEL_221:
      LODWORD(v1) = 0;
      goto LABEL_255;
    }
LABEL_229:
    LODWORD(v1) = v93;
    dev_err(v3, "Unable to register input device, error: %d\n", v93);
    goto LABEL_255;
  }
  v109 = v13;
  v15 = 0;
  v16 = 0;
  v111 = 0;
  v112 = v8;
  v100 = v3;
  v101 = v1;
  v103 = v1 + 72;
  v108 = v2;
  while ( 1 )
  {
    v17 = *(_QWORD *)v4;
    if ( v2[20] )
    {
      v1 = v112;
    }
    else
    {
      v1 = v112;
      v16 = device_get_next_child_node(v3, v16);
      if ( !v16 )
      {
        dev_err(v3, "missing child device node for entry %d\n", v111);
        LODWORD(v1) = -22;
        goto LABEL_255;
      }
    }
    v104 = v15;
    v18 = v17 + 56 * v111;
    v19 = 272 * v111;
    v20 = "gpio_keys_nubia";
    v113 = 272 * v111;
    if ( *(_QWORD *)(v18 + 16) )
      v20 = *(const char **)(v18 + 16);
    v110 = v20;
    if ( v19 + 80 < 0 )
      goto LABEL_256;
    if ( v1 < v19 + 80 )
      goto LABEL_256;
    v21 = v103 + v113;
    *(_QWORD *)(v103 + v113 + 8) = v109;
    if ( v113 + 72 < 0 )
      goto LABEL_256;
    if ( v1 < v113 + 72 )
      goto LABEL_256;
    if ( v1 - (v113 + 72) < 8 )
      goto LABEL_256;
    *(_QWORD *)v21 = v18;
    if ( v113 + 332 < 0 || v1 < v113 + 332 || v1 - (v113 + 332) < 4 )
      goto LABEL_256;
    *(_DWORD *)(v21 + 260) = 0;
    v105 = v16;
    if ( !v16 )
      break;
    index = devm_fwnode_gpiod_get_index(v3, v16, 0, 0, 1, v20);
    v36 = v113 + 88;
    if ( v113 + 88 < 0 || v1 < v36 || v1 - (v113 + 88) < 8 )
      goto LABEL_256;
    v1 = index;
    *(_QWORD *)(v21 + 16) = index;
    if ( index < 0xFFFFFFFFFFFFF001LL )
      goto LABEL_56;
    if ( (_DWORD)index == -2 )
    {
      v59 = v112 >= v36;
      v49 = v112 - v36;
      if ( !v59 || v49 < 8 )
        goto LABEL_256;
      *(_QWORD *)(v21 + 16) = 0;
      goto LABEL_111;
    }
    if ( (_DWORD)index == -517 )
      goto LABEL_247;
    dev_err(v3, "failed to get gpio: %d\n", index);
    if ( (_DWORD)v1 )
      goto LABEL_247;
LABEL_168:
    v15 = v104;
    v16 = v105;
    if ( *(_DWORD *)(v18 + 28) )
      v15 = 1;
    if ( ++v111 >= *(int *)(v4 + 8) )
    {
      if ( v105 )
      {
        if ( v105 <= 0xFFFFFFFFFFFFF000LL )
        {
          v91 = *(_QWORD *)(v105 + 8);
          if ( v91 )
          {
            v92 = *(void (__fastcall **)(unsigned __int64, unsigned __int64))(v91 + 8);
            if ( v92 )
            {
              if ( *((_DWORD *)v92 - 1) != -643302289 )
                __break(0x8228u);
              v92(v105, v105);
            }
          }
        }
      }
      v93 = input_register_device(v109);
      if ( !v93 )
      {
        if ( !v15 )
          goto LABEL_220;
        device_set_wakeup_capable(v3, 1);
        device_wakeup_enable(v3);
        goto LABEL_221;
      }
      goto LABEL_229;
    }
  }
  v22 = *(unsigned int *)(v18 + 4);
  if ( (v22 & 0x80000000) == 0 )
  {
    if ( *(_DWORD *)(v18 + 8) )
      v23 = 5;
    else
      v23 = 1;
    v24 = devm_gpio_request_one(v3, v22, v23, v20);
    v25 = *(_DWORD *)(v18 + 4);
    if ( v24 < 0 )
    {
      LODWORD(v1) = v24;
      dev_err(v3, "Failed to request GPIO %d, error %d\n", v25, v24);
      goto LABEL_254;
    }
    v26 = gpio_to_desc(v25);
    if ( v113 + 88 < 0 || v112 < v113 + 88 || v112 - (v113 + 88) < 8 )
      goto LABEL_256;
    *(_QWORD *)(v21 + 16) = v26;
    if ( !v26 )
    {
      LODWORD(v1) = -22;
LABEL_254:
      printk(&unk_8841, "gpio_keys_probe", v27, v28, v29, v30);
      goto LABEL_255;
    }
    goto LABEL_57;
  }
  if ( v113 + 88 < 0 || v1 < v113 + 88 || v1 - (v113 + 88) < 8 )
    goto LABEL_256;
  v1 = *(_QWORD *)(v21 + 16);
LABEL_56:
  if ( v1 )
  {
LABEL_57:
    v37 = v2[95];
    v115[0] = nullptr;
    next_child = of_get_next_child(v37, 0);
    if ( next_child )
    {
      v39 = next_child;
      while ( (of_property_read_string(v39, "label", v115) & 0x80000000) == 0 )
      {
        of_get_named_gpio(v39, "gpios", 0);
        if ( !strcmp(v115[0], *(const char **)(v18 + 16)) )
        {
          v106 = 1;
          goto LABEL_63;
        }
        v39 = of_get_next_child(v37, v39);
        if ( !v39 )
          break;
      }
    }
    v106 = 0;
LABEL_63:
    v1 = v112;
    v40 = *(_DWORD *)(v18 + 36);
    v41 = v113 + 88;
    if ( v40 )
    {
      if ( (v41 & 0x8000000000000000LL) != 0 || v112 < v41 || v112 - v41 < 8 )
        goto LABEL_256;
      if ( (gpiod_set_debounce(*(_QWORD *)(v21 + 16), (unsigned int)(1000 * v40)) & 0x80000000) != 0 )
      {
        if ( v113 + 256 < 0 || v112 < v113 + 256 )
          goto LABEL_256;
        *(_DWORD *)(v21 + 184) = *(_DWORD *)(v18 + 36);
      }
    }
    v1 = *(unsigned int *)(v18 + 48);
    if ( (_DWORD)v1 )
    {
      v43 = -1;
    }
    else
    {
      if ( (v41 & 0x8000000000000000LL) != 0 || v112 < v41 || v112 - v41 < 8 )
        goto LABEL_256;
      v42 = gpiod_to_irq(*(_QWORD *)(v21 + 16));
      v1 = v42;
      if ( (v42 & 0x80000000) != 0 )
      {
        dev_err(v3, "Unable to get irq number for GPIO %d, error %d\n", *(unsigned int *)(v18 + 4), v42);
        goto LABEL_247;
      }
      v43 = v42;
    }
    v44 = v113 + 260;
    if ( v113 + 260 < 0 )
      goto LABEL_256;
    if ( v112 < v113 + 260 )
      goto LABEL_256;
    if ( v112 - (v113 + 260) < 4 )
      goto LABEL_256;
    *(_DWORD *)(v21 + 188) = v1;
    if ( v113 + 152 < 0 )
      goto LABEL_256;
    if ( v112 < v113 + 152 )
      goto LABEL_256;
    if ( v112 - (v113 + 152) < 8 )
      goto LABEL_256;
    *(_QWORD *)(v21 + 80) = 0xFFFFFFFE00000LL;
    v1 = v112;
    *(_QWORD *)(v21 + 88) = v21 + 88;
    *(_QWORD *)(v21 + 96) = v21 + 88;
    if ( v113 + 176 < 0 )
      goto LABEL_256;
    if ( v112 < v113 + 176 )
      goto LABEL_256;
    *(_QWORD *)(v21 + 104) = gpio_keys_gpio_work_func;
    init_timer_key(v21 + 112, &delayed_work_timer_fn, 0x200000, 0, 0);
    if ( v112 < v44 || v112 - v44 < 4 || v113 + 264 < 0 || v112 < v113 + 264 || v112 - (v113 + 264) < 4 )
      goto LABEL_256;
    printk(
      &unk_89B1,
      v43,
      *(unsigned int *)(v21 + 188),
      *(unsigned int *)(v21 + 192),
      *(unsigned int *)(v18 + 48),
      v106);
    v45 = *(_DWORD *)(v18 + 32);
    if ( v45 == 2 )
    {
      v2 = v108;
      if ( v113 + 328 < 0 || v112 < v113 + 328 || v112 - (v113 + 328) < 4 )
        goto LABEL_256;
      if ( v106 )
        v46 = 1;
      else
        v46 = 2;
    }
    else
    {
      v2 = v108;
      if ( v45 != 1 )
      {
LABEL_106:
        v47 = &gpio_keys_gpio_isr;
        v48 = 3;
LABEL_119:
        v107 = v47;
        if ( v113 + 96 < 0 || v1 < v113 + 96 )
          goto LABEL_256;
        v51 = *(_QWORD *)(v101 + 64);
        *(_QWORD *)(v21 + 24) = v51 + 2 * v111;
        *(_WORD *)(v51 + 2 * v111) = *(_DWORD *)v18;
        v52 = *(_DWORD *)(v18 + 24);
        if ( v52 <= 1 )
          v53 = 1;
        else
          v53 = v52;
        input_set_capability(v109, v53, **(unsigned __int16 **)(v21 + 24));
        v54 = _devm_add_action(v3, gpio_keys_quiesce_key, v21, "gpio_keys_quiesce_key");
        if ( v54 )
        {
          LODWORD(v1) = v54;
          dev_err(v3, "failed to register quiesce action, error: %d\n", v54);
          goto LABEL_247;
        }
        if ( *(_BYTE *)(v18 + 40) )
          v55 = v48;
        else
          v55 = v48 | 0x80;
        if ( v113 + 260 < 0 || v112 < v113 + 260 || v112 - (v113 + 260) < 4 )
          goto LABEL_256;
        v102 = v55;
        v56 = devm_request_any_context_irq(v3, *(unsigned int *)(v21 + 188), v107, v55, v110, v21);
        if ( (v56 & 0x80000000) != 0 )
        {
          if ( ((v113 + 260) & 0x8000000000000000LL) == 0 && v112 >= v113 + 260 && v112 - (v113 + 260) >= 4 )
          {
            LODWORD(v1) = v56;
            dev_err(v3, "Unable to claim irq %d; error %d\n", *(unsigned int *)(v21 + 188), v56);
            goto LABEL_247;
          }
          goto LABEL_256;
        }
        v1 = v2[95];
        v57 = of_get_next_child(v1, 0);
        if ( v57 )
        {
          v58 = v57;
          v59 = v112 >= v113 + 268 && v112 - (v113 + 268) >= 4;
          v60 = v113 + 272;
          v62 = !v59 || v113 + 268 < 0;
          v64 = v60 < 0 || v112 < v60;
          do
          {
            named_gpio = of_get_named_gpio(v58, "gpios", 0);
            if ( (v62 & 1) != 0 )
              goto LABEL_256;
            *(_DWORD *)(v21 + 196) = named_gpio;
            v66 = of_get_named_gpio(v58, "gpion", 0);
            if ( v64 )
              goto LABEL_256;
            *(_DWORD *)(v21 + 200) = v66;
            v58 = of_get_next_child(v1, v58);
          }
          while ( v58 );
        }
        v1 = v112;
        v67 = v113 + 272;
        if ( v113 + 272 < 0 || v112 < v67 )
          goto LABEL_256;
        v68 = *(unsigned int *)(v21 + 200);
        if ( (_DWORD)v68 )
        {
          v69 = gpio_to_desc(v68);
          v70 = gpiod_to_irq(v69);
          if ( v113 + 264 < 0 || v112 < v113 + 264 || v112 - (v113 + 264) < 4 )
            goto LABEL_256;
          *(_DWORD *)(v21 + 192) = v70;
        }
        _mutex_init(v21 + 208, "&bdata->report_lock", &nb_setup_secondary___key);
        if ( v113 + 268 < 0 )
          goto LABEL_256;
        if ( v112 < v113 + 268 )
          goto LABEL_256;
        if ( v112 - (v113 + 268) < 4 )
          goto LABEL_256;
        v3 = v100;
        v2 = v108;
        if ( v112 < v67 )
          goto LABEL_256;
        printk(&unk_87F8, "nb_setup_secondary", *(unsigned int *)(v21 + 196), *(unsigned int *)(v21 + 200), v71, v72);
        if ( v113 + 264 < 0 || v112 < v113 + 264 || v112 - (v113 + 264) < 4 )
          goto LABEL_256;
        v73 = *(unsigned int *)(v21 + 192);
        if ( (_DWORD)v73 && (devm_request_any_context_irq(v100, v73, v107, v102, v110, v21) & 0x80000000) != 0 )
          printk(&unk_839A, "gpio_keys_setup_key", v74, v75, v76, v77);
        goto LABEL_168;
      }
      if ( v113 + 328 < 0 || v112 < v113 + 328 || v112 - (v113 + 328) < 4 )
        goto LABEL_256;
      if ( v106 )
        v46 = 2;
      else
        v46 = 1;
    }
    *(_DWORD *)(v21 + 256) = v46;
    goto LABEL_106;
  }
LABEL_111:
  v50 = *(_DWORD *)(v18 + 48);
  if ( !v50 )
  {
    dev_err(v3, "Found button without gpio or irq\n");
    goto LABEL_237;
  }
  v1 = v112;
  if ( v113 + 260 < 0 || v112 < v113 + 260 || v112 - (v113 + 260) < 4 )
    goto LABEL_256;
  *(_DWORD *)(v21 + 188) = v50;
  if ( *(_DWORD *)(v18 + 24) < 2u )
  {
    if ( v113 + 144 < 0 || v112 < v113 + 144 )
      goto LABEL_256;
    *(_DWORD *)(v21 + 72) = *(_DWORD *)(v18 + 36);
    init_timer_key(v21 + 32, gpio_keys_irq_timer, 0, 0, 0);
    v48 = 0;
    v47 = &gpio_keys_irq_isr;
    goto LABEL_119;
  }
  dev_err(v3, "Only EV_KEY allowed for IRQ buttons.\n");
LABEL_237:
  LODWORD(v1) = -22;
LABEL_247:
  printk(&unk_8841, "gpio_keys_probe", v32, v33, v34, v35);
  if ( v105 )
  {
    if ( v105 <= 0xFFFFFFFFFFFFF000LL )
    {
      v97 = *(_QWORD *)(v105 + 8);
      if ( v97 )
      {
        v98 = *(void (**)(void))(v97 + 8);
        if ( v98 )
        {
          if ( *((_DWORD *)v98 - 1) != -643302289 )
            __break(0x8228u);
          v98();
        }
      }
    }
  }
LABEL_255:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v1;
}
