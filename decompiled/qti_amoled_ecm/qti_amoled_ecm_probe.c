__int64 __fastcall qti_amoled_ecm_probe(__int64 a1)
{
  __int64 v1; // x25
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 regmap; // x0
  __int64 v7; // x22
  __int64 v8; // x0
  unsigned int v9; // w0
  unsigned int string_helper; // w21
  __int64 v11; // x23
  unsigned __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x24
  int v15; // w25
  int byname; // w28
  __int64 v17; // x0
  unsigned __int64 v18; // x20
  unsigned __int64 v19; // x26
  unsigned __int64 v20; // x0
  __int64 v21; // x21
  int v22; // w20
  __int64 v23; // x0
  int v24; // w9
  unsigned int v25; // w22
  unsigned __int8 v26; // w8
  __int64 v27; // x0
  int v28; // w8
  __int64 v29; // x22
  __int64 v30; // x8
  __int64 v31; // x0
  unsigned __int64 v32; // x0
  __int64 v33; // x20
  int v34; // w0
  int v35; // w21
  unsigned int v36; // w22
  int v37; // w8
  __int64 result; // x0
  unsigned __int64 panel; // x0
  unsigned __int64 v40; // x2
  unsigned __int64 v41; // x20
  const char *v42; // x1
  __int64 v43; // x19
  __int64 v44; // x8
  unsigned int v45; // w19
  __int64 v46; // x8
  __int64 v47; // x9
  __int64 v48; // x19
  __int64 v49; // x8
  __int64 v50; // [xsp+8h] [xbp-68h]
  int v51; // [xsp+10h] [xbp-60h] BYREF
  int v52; // [xsp+14h] [xbp-5Ch] BYREF
  __int64 v53; // [xsp+18h] [xbp-58h] BYREF
  __int64 v54; // [xsp+20h] [xbp-50h]
  __int64 v55; // [xsp+28h] [xbp-48h]
  __int64 v56; // [xsp+30h] [xbp-40h]
  __int64 v57; // [xsp+38h] [xbp-38h]
  __int64 v58; // [xsp+40h] [xbp-30h]
  __int64 v59; // [xsp+48h] [xbp-28h]
  __int64 v60; // [xsp+50h] [xbp-20h]
  __int64 v61; // [xsp+58h] [xbp-18h]
  __int64 v62; // [xsp+60h] [xbp-10h]
  __int64 v63; // [xsp+68h] [xbp-8h]

  v1 = a1 + 16;
  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v3 = devm_kmalloc(a1 + 16, 232, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_58;
  }
  v4 = v3;
  v5 = *(_QWORD *)(a1 + 112);
  *(_QWORD *)(v4 + 8) = v1;
  regmap = dev_get_regmap(v5, 0);
  *(_QWORD *)v4 = regmap;
  if ( !regmap )
  {
    dev_err(v1, "Failed to get regmap\n");
    result = 4294967274LL;
    goto LABEL_58;
  }
  v7 = *(_QWORD *)(v4 + 8);
  v8 = *(_QWORD *)(v7 + 744);
  v52 = 0;
  LODWORD(v55) = 0;
  v53 = 0;
  v54 = 0;
  v9 = of_property_read_variable_u32_array(v8, "reg", &v52, 1, 0);
  if ( (v9 & 0x80000000) != 0 )
  {
    string_helper = v9;
    dev_err(v7, "Failed to get reg, rc = %d\n", v9);
    goto LABEL_56;
  }
  *(_DWORD *)(v4 + 220) = v52;
  string_helper = of_property_read_string_helper(*(_QWORD *)(v7 + 744), "nvmem-names", 0, 0, 0);
  if ( (string_helper & 0x80000000) != 0 )
  {
    dev_err(*(_QWORD *)(v4 + 8), "Could not find nvmem device\n");
    goto LABEL_56;
  }
  v11 = *(_QWORD *)(v4 + 8);
  v12 = 32LL * string_helper;
  *(_DWORD *)(v4 + 216) = string_helper;
  v13 = devm_kmalloc(v11, v12, 3520);
  *(_QWORD *)(v4 + 40) = v13;
  if ( !v13 )
  {
    string_helper = -12;
    goto LABEL_56;
  }
  v50 = v1;
  if ( !string_helper )
  {
LABEL_15:
    v1 = v50;
    goto LABEL_16;
  }
  v14 = v13;
  v15 = 0;
  while ( 1 )
  {
    scnprintf(&v53, 20, "ecm-sdam%d", v15);
    byname = of_irq_get_byname(*(_QWORD *)(v11 + 744), &v53);
    if ( byname < 0 )
    {
      dev_err(v11, "Failed to get irq for ecm sdam, err=%d\n", byname);
      string_helper = -22;
LABEL_55:
      v1 = v50;
      goto LABEL_56;
    }
    v17 = devm_kstrdup(v11, &v53, 3264);
    if ( v12 < ((32LL * v15) | 0x10uLL) )
      goto LABEL_72;
    v18 = 32LL * v15;
    v19 = v14 + v18;
    *(_QWORD *)(v14 + v18 + 16) = v17;
    if ( !v17 )
    {
      string_helper = -12;
      goto LABEL_55;
    }
    if ( v12 < (v18 | 0x18) )
      goto LABEL_72;
    *(_DWORD *)(v19 + 24) = byname;
    scnprintf(&v53, 20, "amoled-ecm-sdam%d", v15);
    v20 = devm_nvmem_device_get(v11, &v53);
    if ( v12 <= v18 )
      goto LABEL_72;
    *(_QWORD *)v19 = v20;
    if ( v20 >= 0xFFFFFFFFFFFFF001LL )
      break;
    if ( ++v15 >= string_helper )
      goto LABEL_15;
  }
  if ( (_DWORD)v20 == -517 )
  {
    v1 = v50;
    if ( v12 > v18 )
    {
      *(_QWORD *)v19 = 0;
      string_helper = -517;
      goto LABEL_56;
    }
LABEL_72:
    __break(1u);
  }
  string_helper = v20;
  dev_err(v11, "Failed to get nvmem device, rc=%d\n", v20);
  v1 = v50;
  if ( v12 <= v18 )
    goto LABEL_72;
  *(_QWORD *)v19 = 0;
  if ( (string_helper & 0x80000000) == 0 )
  {
LABEL_16:
    v21 = *(_QWORD *)v4;
    v22 = *(_DWORD *)(v4 + 220);
    v23 = regmap_read(*(_QWORD *)v4, (unsigned int)(v22 + 5), &v51);
    if ( (v23 & 0x80000000) != 0 )
    {
      v42 = "Failed to read AB subtype, rc=%d\n";
    }
    else
    {
      v24 = v51 & 0xFE;
      v25 = (unsigned __int8)v51;
      *(_BYTE *)(v4 + 225) = v51;
      if ( v24 != 6 )
      {
        dev_err(v1, "ECM not supported for unknown subtype %u\n", v25);
        goto LABEL_64;
      }
      v23 = regmap_read(v21, (unsigned int)(v22 + 1), &v51);
      if ( (v23 & 0x80000000) == 0 )
      {
        v26 = v51;
        *(_BYTE *)(v4 + 224) = v51;
        if ( v25 != 6 || v26 < 2u )
        {
          *(_WORD *)(v4 + 226) = 0;
          *(_QWORD *)(v4 + 32) = 0x200000000LL;
          *(_QWORD *)(v4 + 96) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v4 + 16) = 0;
          *(_QWORD *)(v4 + 24) = 0;
          *(_QWORD *)(v4 + 104) = v4 + 104;
          *(_QWORD *)(v4 + 112) = v4 + 104;
          *(_QWORD *)(v4 + 120) = ecm_average_work;
          init_timer_key(v4 + 128, &delayed_work_timer_fn, 0x200000, 0, 0);
          _mutex_init(v4 + 48, "&ecm->sdam_lock", &qti_amoled_ecm_probe___key_8);
          *(_QWORD *)(*(_QWORD *)(v4 + 8) + 152LL) = v4;
          if ( *(_DWORD *)(v4 + 216) )
          {
            v27 = devm_request_threaded_irq(
                    *(_QWORD *)(v4 + 8),
                    *(unsigned int *)(*(_QWORD *)(v4 + 40) + 24LL),
                    0,
                    sdam_full_irq_handler,
                    0x2000,
                    *(_QWORD *)(*(_QWORD *)(v4 + 40) + 16LL),
                    v4);
            if ( (v27 & 0x80000000) != 0 )
            {
              v46 = v27;
              v29 = 0;
LABEL_69:
              v47 = *(_QWORD *)(v4 + 40);
              v48 = v46;
              dev_err(v1, "Failed to request IRQ(%s), rc=%d\n", *(const char **)(v47 + 32 * v29 + 16), v46);
              result = v48;
              goto LABEL_58;
            }
            *(_DWORD *)(*(_QWORD *)(v4 + 40) + 8LL) = 108;
            if ( *(_DWORD *)(v4 + 216) >= 2u )
            {
              v28 = 1;
              while ( 1 )
              {
                v29 = v28;
                v30 = *(_QWORD *)(v4 + 40) + 32LL * v28;
                v31 = devm_request_threaded_irq(
                        *(_QWORD *)(v4 + 8),
                        *(unsigned int *)(v30 + 24),
                        0,
                        sdam_full_irq_handler,
                        0x2000,
                        *(_QWORD *)(v30 + 16),
                        v4);
                if ( (v31 & 0x80000000) != 0 )
                  break;
                *(_DWORD *)(*(_QWORD *)(v4 + 40) + 32 * v29 + 8) = 70;
                v28 = v29 + 1;
                if ( (unsigned int)(v29 + 1) >= *(_DWORD *)(v4 + 216) )
                  goto LABEL_27;
              }
              v46 = v31;
              goto LABEL_69;
            }
          }
LABEL_27:
          v32 = devm_hwmon_device_register_with_groups(v1, "amoled_ecm", v4, &amoled_ecm_groups);
          if ( !v32 || v32 >= 0xFFFFFFFFFFFFF001LL )
          {
            v44 = *(_QWORD *)(v4 + 8);
            v45 = v32;
            dev_err(v44, "failed to register hwmon device for amoled-ecm, rc=%d\n", (unsigned int)v32);
            goto LABEL_57;
          }
          v33 = *(_QWORD *)(*(_QWORD *)(v4 + 8) + 744LL);
          v34 = of_count_phandle_with_args(v33, "display-panels", 0);
          if ( v34 < 1 )
          {
            result = 0;
            goto LABEL_58;
          }
          v35 = v34;
          v36 = 0;
          while ( 1 )
          {
            v61 = 0;
            v62 = 0;
            v59 = 0;
            v60 = 0;
            v57 = 0;
            v58 = 0;
            v55 = 0;
            v56 = 0;
            v53 = 0;
            v54 = 0;
            v37 = _of_parse_phandle_with_args(v33, "display-panels", 0, 0, v36, &v53);
            result = 4294967277LL;
            if ( v37 || !v53 )
              goto LABEL_58;
            panel = of_drm_find_panel(v53);
            if ( panel <= 0xFFFFFFFFFFFFF000LL )
              break;
            if ( v35 == ++v36 )
            {
              v40 = *(_QWORD *)(v4 + 200);
              if ( !v40 )
                goto LABEL_36;
LABEL_41:
              v41 = panel_event_notifier_register(1, 2, v40, panel_event_notifier_callback, v4);
              if ( v41 >= 0xFFFFFFFFFFFFF001LL )
              {
                dev_err(*(_QWORD *)(v4 + 8), "failed to register panel event notifier, rc=%d\n", v41);
                result = (unsigned int)v41;
              }
              else
              {
                result = 0;
                *(_QWORD *)(v4 + 208) = v41;
              }
              goto LABEL_58;
            }
          }
          *(_QWORD *)(v4 + 200) = panel;
          v40 = panel;
          if ( panel )
            goto LABEL_41;
LABEL_36:
          if ( (_DWORD)panel == -517 )
          {
            result = 4294966779LL;
            goto LABEL_58;
          }
          v49 = *(_QWORD *)(v4 + 8);
          v43 = panel;
          dev_err(v49, "failed to find active panel, rc=%d\n", (unsigned int)panel);
LABEL_51:
          result = v43;
          goto LABEL_58;
        }
        dev_err(v1, "ECM is not supported for AB version %u\n", v26);
LABEL_64:
        result = 4294967277LL;
        goto LABEL_58;
      }
      v42 = "Failed to read AB revision, rc=%d\n";
    }
    v43 = v23;
    dev_err(v1, v42, (unsigned int)v23);
    goto LABEL_51;
  }
LABEL_56:
  v45 = string_helper;
  dev_err(v1, "Failed to parse AMOLED ECM rc=%d\n", string_helper);
LABEL_57:
  result = v45;
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
