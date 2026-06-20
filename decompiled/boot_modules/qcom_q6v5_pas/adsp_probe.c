__int64 __fastcall adsp_probe(_QWORD *a1)
{
  _QWORD *v1; // x20
  __int64 match_data; // x0
  unsigned int *v4; // x22
  __int64 v5; // x0
  unsigned int v6; // w0
  unsigned int inited; // w24
  __int64 v8; // x0
  unsigned int v9; // w0
  void *v10; // x2
  __int64 v11; // x0
  __int64 v12; // x23
  _QWORD *v13; // x19
  int v14; // w8
  __int64 v15; // x8
  char v16; // w9
  __int64 v17; // x24
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x2
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  const char *v31; // x1
  __int64 v32; // x0
  const char *v33; // x1
  __int64 v34; // x19
  unsigned __int64 v36; // x0
  unsigned __int64 v37; // x0
  unsigned __int64 v38; // x0
  __int64 ramdump_device; // x0
  unsigned int v40; // w0
  unsigned int v41; // w0
  bool v42; // zf
  const char *v43; // x1
  __int64 v44; // [xsp+8h] [xbp-88h] BYREF
  __int64 v45; // [xsp+10h] [xbp-80h] BYREF
  char s[8]; // [xsp+18h] [xbp-78h] BYREF
  __int64 v47; // [xsp+20h] [xbp-70h]
  __int64 v48; // [xsp+28h] [xbp-68h]
  __int64 v49; // [xsp+30h] [xbp-60h]
  __int64 v50; // [xsp+38h] [xbp-58h] BYREF
  __int64 v51; // [xsp+40h] [xbp-50h]
  __int64 v52; // [xsp+48h] [xbp-48h]
  __int64 v53; // [xsp+50h] [xbp-40h]
  __int64 v54; // [xsp+58h] [xbp-38h]
  __int64 v55; // [xsp+60h] [xbp-30h]
  __int64 v56; // [xsp+68h] [xbp-28h]
  __int64 v57; // [xsp+70h] [xbp-20h]
  __int64 v58; // [xsp+78h] [xbp-18h]
  __int64 v59; // [xsp+80h] [xbp-10h]
  __int64 v60; // [xsp+88h] [xbp-8h]

  v1 = a1 + 2;
  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = 0;
  v48 = 0;
  v49 = 0;
  *(_QWORD *)s = 0;
  v47 = 0;
  match_data = of_device_get_match_data(a1 + 2);
  if ( !match_data )
  {
    inited = -22;
    goto LABEL_44;
  }
  v4 = (unsigned int *)match_data;
  if ( (qcom_scm_is_available() & 1) == 0 )
  {
    inited = -517;
    goto LABEL_44;
  }
  v5 = a1[95];
  v45 = *((_QWORD *)v4 + 1);
  v6 = of_property_read_string(v5, "firmware-name", &v45);
  if ( (v6 & 0x80000000) == 0 || (inited = v6, v6 == -22) )
  {
    if ( !*((_QWORD *)v4 + 2)
      || (v8 = a1[95],
          v44 = *((_QWORD *)v4 + 2),
          v9 = of_property_read_string_helper(v8, "firmware-name", &v44, 1, 1),
          (v9 & 0x80000000) == 0)
      || (inited = v9, v9 == -22) )
    {
      if ( v4[9] )
        v10 = &adsp_minidump_ops;
      else
        v10 = &adsp_ops;
      v11 = devm_rproc_alloc(v1, *a1, v10, v45, 1336);
      if ( !v11 )
      {
        dev_err(v1, "unable to allocate remoteproc\n");
        inited = -12;
        goto LABEL_44;
      }
      v12 = v11;
      *(_BYTE *)(v11 + 1204) = 1;
      *(_BYTE *)(v11 + 1249) = *((_BYTE *)v4 + 42);
      rproc_coredump_set_elf_info();
      v13 = *(_QWORD **)(v12 + 40);
      *v13 = v1;
      v13[2] = v12;
      *((_DWORD *)v13 + 117) = v4[9];
      *((_DWORD *)v13 + 114) = v4[6];
      *((_DWORD *)v13 + 116) = v4[8];
      v13[62] = *((_QWORD *)v4 + 9);
      *((_DWORD *)v13 + 121) = v4[21];
      *((_BYTE *)v13 + 488) = *((_BYTE *)v4 + 43);
      *((_BYTE *)v13 + 472) = *((_BYTE *)v4 + 40);
      *((_DWORD *)v13 + 186) = v4[22];
      v14 = v4[23];
      if ( v14 >= 3 )
        v14 = 3;
      *((_DWORD *)v13 + 187) = v14;
      *((_DWORD *)v13 + 189) = v4[25];
      *((_BYTE *)v13 + 752) = *((_BYTE *)v4 + 96);
      *((_BYTE *)v13 + 784) = *((_BYTE *)v4 + 104);
      v15 = v44;
      v16 = *((_BYTE *)v4 + 105);
      *((_BYTE *)v13 + 785) = 1;
      *((_BYTE *)v13 + 1328) = v16;
      if ( v15 )
      {
        v13[56] = v15;
        *((_DWORD *)v13 + 115) = v4[7];
      }
      a1[21] = v13;
      v17 = *v13;
      device_set_wakeup_capable(*v13, 1);
      inited = device_wakeup_enable(v17);
      if ( inited )
        goto LABEL_43;
      v18 = *(_QWORD *)(*v13 + 744LL);
      v58 = 0;
      v59 = 0;
      v56 = 0;
      v57 = 0;
      v54 = 0;
      v55 = 0;
      v52 = 0;
      v53 = 0;
      v50 = 0;
      v51 = 0;
      if ( (unsigned int)_of_parse_phandle_with_args(v18, "memory-region", 0, 0, 0, &v50) || !v50 )
      {
        v30 = *v13;
        v31 = "no memory-region specified\n";
      }
      else
      {
        v19 = of_reserved_mem_lookup();
        if ( v19 )
        {
          v20 = *(_QWORD *)(v19 + 24);
          v13[81] = v20;
          v13[79] = v20;
          v21 = *(_QWORD *)(v19 + 32);
          v22 = *v13;
          v13[88] = v21;
          v23 = devm_ioremap_wc(v22);
          v13[86] = v23;
          if ( !v23 )
          {
            v32 = *v13;
            v33 = "unable to map memory region: %pa+%zx\n";
            goto LABEL_42;
          }
          if ( !*((_DWORD *)v13 + 115) )
          {
LABEL_26:
            inited = adsp_setup_32b_dma_allocs(v13);
            if ( inited )
              goto LABEL_43;
            inited = adsp_init_clock(v13);
            if ( inited )
              goto LABEL_43;
            inited = adsp_init_regulator(v13);
            if ( inited )
              goto LABEL_43;
            inited = adsp_pds_attach(v1, v13 + 52, *((_QWORD *)v4 + 6));
            if ( (inited & 0x80000000) != 0 )
              goto LABEL_43;
            *((_DWORD *)v13 + 110) = inited;
            inited = qcom_q6v5_init(
                       v13 + 3,
                       a1,
                       v12,
                       *v4,
                       v4[1],
                       v4[21],
                       *((_QWORD *)v4 + 7),
                       *((unsigned __int8 *)v4 + 106),
                       qcom_pas_handover);
            if ( inited )
              goto LABEL_31;
            if ( *((_BYTE *)v13 + 1328) != 1 )
              goto LABEL_51;
            if ( (unsigned int)rproc_find_status_register(v13) )
            {
              inited = 0;
LABEL_31:
              adsp_pds_detach(v13, v13 + 52, *((int *)v13 + 110));
LABEL_43:
              v34 = *v13;
              device_wakeup_disable(v34);
              device_set_wakeup_capable(v34, 0);
              goto LABEL_44;
            }
            v36 = devm_qcom_smem_state_get(v1, "wakeup", v13 + 162);
            v13[151] = v36;
            if ( v36 >= 0xFFFFFFFFFFFFF001LL )
            {
              v43 = "failed to acquire wake state\n";
            }
            else
            {
              v37 = devm_qcom_smem_state_get(v1, "sleep", (char *)v13 + 1300);
              v13[152] = v37;
              if ( v37 < 0xFFFFFFFFFFFFF001LL )
              {
                _mutex_init(v13 + 156, "&adsp->adsp_lock", &adsp_probe___key);
                *((_DWORD *)v13 + 326) = 0;
LABEL_51:
                qcom_q6v5_register_ssr_subdev(v13 + 3, v13 + 131);
                qcom_q6v5_register_glink_subdev(v13 + 3, v13 + 99);
                qcom_add_glink_subdev(v12, v13 + 99, *((_QWORD *)v4 + 8));
                qcom_add_smd_subdev(v12, v13 + 113);
                qcom_add_pdm_subdev(v12, v13 + 122);
                v38 = qcom_add_sysmon_subdev(v12, *((_QWORD *)v4 + 9), v4[20]);
                v13[144] = v38;
                if ( v38 >= 0xFFFFFFFFFFFFF001LL )
                {
                  inited = v38;
                  goto LABEL_31;
                }
                inited = device_create_file(*v13, &dev_attr_txn_id);
                if ( inited )
                {
LABEL_64:
                  qcom_remove_sysmon_subdev(v13[144]);
                  goto LABEL_31;
                }
                snprintf(s, 0x20u, "%s-md", *(const char **)a1[95]);
                ramdump_device = qcom_create_ramdump_device(s, 0);
                v13[1] = ramdump_device;
                if ( !ramdump_device )
                  dev_err(v1, "Unable to create %s minidump device.\n", s);
                qcom_add_ssr_subdev(v12, v13 + 131, *((_QWORD *)v4 + 8));
                if ( *((_BYTE *)v13 + 344) == 1 )
                {
                  *(_DWORD *)(v13[2] + 972LL) = 6;
                  v40 = ping_subsystem_init(v13 + 3, a1);
                  if ( v40 )
                  {
                    inited = v40;
                    dev_err(v1, "Unable to find ping/pong bits\n");
                    qcom_remove_sysmon_subdev(v13[144]);
                    goto LABEL_44;
                  }
                }
                inited = rproc_add(v12);
                if ( inited )
                {
LABEL_61:
                  if ( v13[1] )
                    qcom_destroy_ramdump_device();
                  device_remove_file(*v13, &dev_attr_txn_id);
                  goto LABEL_64;
                }
                v41 = q6v5_debugfs_init(v13 + 3);
                if ( v41 )
                {
                  inited = v41;
                  rproc_del(v12);
                  goto LABEL_61;
                }
                v42 = *((_BYTE *)v13 + 1328) == 1;
                rproc_recovery_set_fn = rproc_recovery_set;
                if ( v42 )
                {
                  *((_DWORD *)v13 + 310) = 2147483645;
                  v13[153] = rproc_panic_handler;
                  atomic_notifier_chain_register(&panic_notifier_list, v13 + 153);
                }
                inited = 0;
                goto LABEL_44;
              }
              v43 = "failed to acquire sleep state\n";
            }
            dev_err(v1, v43);
            inited = 0;
            goto LABEL_31;
          }
          v24 = *(_QWORD *)(*v13 + 744LL);
          v58 = 0;
          v59 = 0;
          v56 = 0;
          v57 = 0;
          v54 = 0;
          v55 = 0;
          v52 = 0;
          v53 = 0;
          v50 = 0;
          v51 = 0;
          if ( (unsigned int)_of_parse_phandle_with_args(v24, "memory-region", 0, 0, 1, &v50) || !v50 )
          {
            v30 = *v13;
            v31 = "no dtb memory-region specified\n";
          }
          else
          {
            v25 = of_reserved_mem_lookup();
            if ( v25 )
            {
              v26 = *(_QWORD *)(v25 + 24);
              v13[82] = v26;
              v13[80] = v26;
              v27 = *(_QWORD *)(v25 + 32);
              v28 = *v13;
              v13[89] = v27;
              v29 = devm_ioremap_wc(v28);
              v13[87] = v29;
              if ( v29 )
                goto LABEL_26;
              v32 = *v13;
              v33 = "unable to map dtb memory region: %pa+%zx\n";
LABEL_42:
              dev_err(v32, v33);
              inited = -16;
              goto LABEL_43;
            }
            v30 = *v13;
            v31 = "unable to resolve dtb memory-region\n";
          }
        }
        else
        {
          v30 = *v13;
          v31 = "unable to resolve memory-region\n";
        }
      }
      dev_err(v30, v31);
      inited = -22;
      goto LABEL_43;
    }
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return inited;
}
