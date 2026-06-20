__int64 __fastcall qmp_sdca_dmic_probe(unsigned __int64 a1)
{
  unsigned __int64 inited; // x0
  unsigned __int64 v3; // x21
  unsigned int v4; // w19
  unsigned __int64 v5; // x20
  unsigned __int64 *v6; // x0
  unsigned __int64 *v7; // x19
  unsigned __int64 v8; // x0
  unsigned int v9; // w0
  __int64 v10; // x0
  __int64 v11; // x24
  unsigned __int64 v12; // x22
  _DWORD *v13; // x21
  unsigned int variable_u32_array; // w0
  __int64 v15; // x8
  int v16; // w10
  int v17; // w10
  int v18; // w10
  int v19; // w8
  const char **v20; // x0
  const char **v21; // x21
  const char *v22; // x0
  int v23; // w23
  __int64 *v24; // x0
  __int64 *v25; // x22
  __int64 v26; // x25
  __int64 v27; // x24
  __int64 v28; // x0
  __int64 v29; // x25
  __int64 v30; // x24
  __int64 v31; // x0
  unsigned __int64 v32; // x1
  unsigned int v33; // w22
  const char *v34; // x20
  unsigned int v35; // w0
  __int64 v36; // x3
  const char *v38; // x1
  const char *v39; // x2
  int v40; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v41; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v42; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)(a1 + 993) = 1;
  inited = _devm_regmap_init_swr();
  v3 = inited;
  if ( inited >= 0xFFFFFFFFFFFFF001LL )
  {
    v4 = inited;
    goto LABEL_72;
  }
  v5 = a1 + 72;
  v41 = 0;
  v40 = -1;
  v6 = (unsigned __int64 *)devm_kmalloc(a1 + 72, 312, 3520);
  if ( !v6 )
    goto LABEL_71;
  v7 = v6;
  *(_QWORD *)(a1 + 224) = v6;
  v6[1] = v5;
  v6[2] = a1;
  *v6 = v3;
  v6[24] = 9600000;
  v6[38] = 0;
  v8 = devm_regulator_get(a1 + 72, "qmp-vdd");
  v7[6] = v8;
  if ( v8 < 0xFFFFFFFFFFFFF001LL )
  {
    v9 = of_property_read_string(*(_QWORD *)(a1 + 816), "qcom,codec-name", &v41);
    if ( v9 )
    {
      v4 = v9;
      dev_err(
        a1 + 72,
        "Looking up %s property in node %s failed\n",
        "qcom,codec-name",
        *(_QWORD *)(*(_QWORD *)(a1 + 816) + 16LL));
      goto LABEL_72;
    }
    v10 = *(_QWORD *)(a1 + 816);
    v11 = *(_QWORD *)(a1 + 224);
    v42 = 0;
    if ( of_find_property(v10, "qcom,swr-tx-port-params", &v42) )
    {
      if ( (v42 & 0xFFFFFFF0) == 0x40 )
      {
        v12 = v42;
        v13 = (_DWORD *)_kmalloc_noprof(v42, 3520);
        if ( v13 )
        {
          variable_u32_array = of_property_read_variable_u32_array(
                                 *(_QWORD *)(a1 + 816),
                                 "qcom,swr-tx-port-params",
                                 v13,
                                 16,
                                 0);
          if ( (variable_u32_array & 0x80000000) == 0 )
          {
            if ( v12 < 4 )
              goto LABEL_84;
            v15 = (unsigned int)v12 & 0xFFFFFFFC;
            *(_DWORD *)(v11 + 60) = *v13;
            if ( v15 == 4 )
              goto LABEL_84;
            *(_DWORD *)(v11 + 64) = v13[1];
            if ( v12 < 8 )
              goto LABEL_84;
            if ( v15 == 8 )
              goto LABEL_84;
            if ( (v12 & 0xFFFFFFFC) == 8 )
              goto LABEL_84;
            *(_DWORD *)(v11 + 68) = v13[2];
            if ( v12 < 0xC )
              goto LABEL_84;
            if ( v15 == 12 )
              goto LABEL_84;
            if ( (v12 & 0xFFFFFFFC) == 0xC )
              goto LABEL_84;
            v16 = v13[3];
            *(_QWORD *)(v11 + 128) = v11 + 60;
            *(_DWORD *)(v11 + 72) = v16;
            if ( v12 < 0x10 )
              goto LABEL_84;
            if ( v15 == 16 )
              goto LABEL_84;
            if ( (v12 & 0xFFFFFFFC) == 0x10 )
              goto LABEL_84;
            *(_DWORD *)(v11 + 76) = v13[4];
            if ( v12 < 0x14 )
              goto LABEL_84;
            if ( v15 == 20 )
              goto LABEL_84;
            if ( (v12 & 0xFFFFFFFC) == 0x14 )
              goto LABEL_84;
            *(_DWORD *)(v11 + 80) = v13[5];
            if ( v12 < 0x18 )
              goto LABEL_84;
            if ( v15 == 24 )
              goto LABEL_84;
            if ( (v12 & 0xFFFFFFFC) == 0x18 )
              goto LABEL_84;
            *(_DWORD *)(v11 + 84) = v13[6];
            if ( v12 < 0x1C )
              goto LABEL_84;
            if ( v15 == 28 )
              goto LABEL_84;
            if ( (v12 & 0xFFFFFFFC) == 0x1C )
              goto LABEL_84;
            v17 = v13[7];
            *(_QWORD *)(v11 + 136) = v11 + 76;
            *(_DWORD *)(v11 + 88) = v17;
            if ( v12 < 0x20 )
              goto LABEL_84;
            if ( v15 == 32 )
              goto LABEL_84;
            if ( (v12 & 0xFFFFFFFC) == 0x20 )
              goto LABEL_84;
            *(_DWORD *)(v11 + 92) = v13[8];
            if ( v12 < 0x24 )
              goto LABEL_84;
            if ( v15 == 36 )
              goto LABEL_84;
            if ( (v12 & 0xFFFFFFFC) == 0x24 )
              goto LABEL_84;
            *(_DWORD *)(v11 + 96) = v13[9];
            if ( v12 < 0x28
              || v15 == 40
              || (v12 & 0xFFFFFFFC) == 0x28
              || (*(_DWORD *)(v11 + 100) = v13[10], v12 < 0x2C)
              || v15 == 44
              || (v12 & 0xFFFFFFFC) == 0x2C
              || (v18 = v13[11], *(_QWORD *)(v11 + 144) = v11 + 92, *(_DWORD *)(v11 + 104) = v18, v12 < 0x30)
              || v15 == 48
              || (v12 & 0xFFFFFFFC) == 0x30
              || (*(_DWORD *)(v11 + 108) = v13[12], v12 < 0x34)
              || v15 == 52
              || (v12 & 0xFFFFFFFC) == 0x34
              || (*(_DWORD *)(v11 + 112) = v13[13], v12 < 0x38)
              || v15 == 56
              || (v12 & 0xFFFFFFFC) == 0x38
              || (*(_DWORD *)(v11 + 116) = v13[14], v12 < 0x3C)
              || v15 == 60
              || (v12 & 0xFFFFFFFC) == 0x3C )
            {
LABEL_84:
              __break(1u);
            }
            v19 = v13[15];
            *(_QWORD *)(v11 + 152) = v11 + 108;
            *(_DWORD *)(v11 + 120) = v19;
            kfree(v13);
            v20 = (const char **)devm_kmalloc(a1 + 72, 384, 3520);
            if ( v20 )
            {
              v21 = v20;
              memcpy(v20, &soc_codec_dev_qmp_dmic, 0x180u);
              v22 = (const char *)devm_kstrdup(a1 + 72, v41, 3264);
              *v21 = v22;
              if ( v22 )
              {
                v7[4] = (unsigned __int64)v21;
                if ( sscanf(v22, "qmp-dmic.%02d", &v40) != 1 )
                {
                  dev_err(a1 + 72, "name parsing for dev_index failed:%s\n", *(const char **)v7[4]);
                  v4 = -22;
                  goto LABEL_72;
                }
                v23 = v40;
                v24 = (__int64 *)devm_kmalloc(v5, 624, 3520);
                if ( !v24 )
                  goto LABEL_73;
                v25 = v24;
                memcpy(v24, &qmp_dmic_dai, 0x270u);
                v26 = devm_kasprintf(v5, 3264, "qmp_dmic_normal_tx%d", v23);
                *v25 = v26;
                v27 = devm_kasprintf(v5, 3264, "qmp_dmic_lp_tx%d", v23);
                v25[26] = v27;
                v28 = devm_kasprintf(v5, 3264, "qmp_dmic_va_normal_tx%d", v23);
                v25[52] = v28;
                if ( !v26
                  || !v27
                  || !v28
                  || (v29 = devm_kasprintf(v5, 3264, "QMP_DMIC AIF%d Normal Capture", v23),
                      v25[13] = v29,
                      v30 = devm_kasprintf(v5, 3264, "QMP_DMIC AIF%d LP Capture", v23),
                      v25[39] = v30,
                      v31 = devm_kasprintf(v5, 3264, "QMP_DMIC AIF%d VA Normal Capture", v23),
                      v25[65] = v31,
                      !v29)
                  || !v30
                  || !v31 )
                {
LABEL_73:
                  v7[5] = 0;
                  v4 = -22;
                  goto LABEL_72;
                }
                v32 = v7[4];
                v7[5] = (unsigned __int64)v25;
                v33 = devm_snd_soc_register_component(v5, v32, v25, 3);
                if ( v33 )
                  dev_err(v5, "Codec component %s registration failed\n", *(const char **)v7[4]);
                v34 = *v21;
                v35 = kobject_init_and_add(v7 + 26, &qmp_ktype, kernel_kobj, *v21);
                if ( (v35 & 0x80000000) != 0 )
                {
                  printk(&unk_A718, "qmp_sysfs_init", v34, v35);
                }
                else
                {
                  if ( (sysfs_create_file_ns(v7 + 26, &device_state_attr, 0) & 0x80000000) == 0 )
                  {
LABEL_70:
                    v4 = v33;
                    goto LABEL_72;
                  }
                  printk(&unk_ADD9, "qmp_sysfs_init", v34, v36);
                }
                kobject_put(v7 + 26);
                goto LABEL_70;
              }
            }
LABEL_71:
            v4 = -12;
            goto LABEL_72;
          }
          v4 = variable_u32_array;
          dev_err(a1 + 72, "Failed to read port mapping from prop %s\n", "qcom,swr-tx-port-params");
          kfree(v13);
        }
        else
        {
          v4 = -12;
        }
LABEL_86:
        dev_err(
          a1 + 72,
          "Parsing %s failed in node %s\n",
          "qcom,swr-tx-port-params",
          *(_QWORD *)(*(_QWORD *)(a1 + 816) + 16LL));
        goto LABEL_72;
      }
      v38 = "%s:port params not provided for all usecases\n";
      v39 = "qmp_sdca_dmic_parse_port_params";
    }
    else
    {
      v38 = "missing port mapping property %s\n";
      v39 = "qcom,swr-tx-port-params";
    }
    dev_err(a1 + 72, v38, v39);
    v4 = -22;
    goto LABEL_86;
  }
  if ( (_DWORD)v8 == -517 )
  {
    v4 = -517;
  }
  else
  {
    v4 = v8;
    dev_err(a1 + 72, "%s: get qmp-vdd-supply failed, ret=%d\n", "qmp_sdca_dmic_init", v8);
  }
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return v4;
}
