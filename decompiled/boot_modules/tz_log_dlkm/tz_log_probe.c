__int64 __fastcall tz_log_probe(__int64 a1)
{
  unsigned int tz_log_feat_id; // w0
  unsigned int tz_feat_id_version; // w0
  bool v4; // cf
  char v5; // w8
  _QWORD *resource; // x0
  unsigned int v7; // w20
  const void *v8; // x20
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 property; // x0
  __int64 v12; // x0
  __int64 v13; // x3
  __int64 v14; // x20
  unsigned int v15; // w0
  int v16; // w8
  unsigned int v17; // w21
  unsigned int v18; // w0
  const char *v19; // x1
  unsigned int v20; // w21
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x2
  __int64 v24; // x1
  __int64 v25; // x0
  __int64 v26; // x2
  _QWORD *v27; // x20
  __int64 v28; // x2
  __int64 v29; // x1
  unsigned int v30; // w0
  __int64 v31; // x2
  unsigned int v32; // w0
  unsigned int v33; // w0
  __int64 v35; // x2
  unsigned __int64 v36; // x20
  __int64 v37; // x0
  __int64 v38; // x2
  __int64 v39; // x0
  const char *v40; // x1
  __int64 v41; // x3
  __int64 v42; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v44; // x24
  __int64 v45; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v46; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v47; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v48; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+28h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  byte_188 = 1;
  byte_1B0 = 1;
  byte_1D8 = 1;
  byte_200 = 1;
  byte_228 = 1;
  byte_250 = 1;
  byte_278 = 1;
  byte_2A0 = 1;
  byte_2C8 = 1;
  byte_2F0 = 1;
  byte_318 = 1;
  v47 = 0;
  tz_log_feat_id = qcom_scm_get_tz_log_feat_id(&v47);
  if ( tz_log_feat_id )
  {
    v7 = tz_log_feat_id;
    printk(&unk_9E40, "tzdbg_get_tz_version", "tzdbg_get_tz_version");
  }
  else
  {
    dword_32C = v47;
    tz_feat_id_version = qcom_scm_get_tz_feat_id_version(6, &v47);
    if ( !tz_feat_id_version )
    {
      printk(&unk_A71D, "tzdbg_get_tz_version", v47);
      dword_338 = ((unsigned int)v47 >> 12) & 0x3FF;
      v4 = (unsigned int)v47 >> 22 != 9 || (((unsigned int)v47 >> 12) & 0x3FF) - 2 >= 3;
      dword_33C = (unsigned int)v47 >> 22;
      v5 = !v4;
      byte_332 = v5;
      resource = (_QWORD *)platform_get_resource(a1, 512, 0);
      if ( !resource )
      {
        dev_err(a1 + 16, "%s: ERROR Missing MEM resource\n", "tz_log_probe");
LABEL_66:
        v7 = -6;
        goto LABEL_67;
      }
      v8 = resource;
      debug_rw_buf_size = resource[1] - *resource + 1;
      v9 = devm_ioremap(a1 + 16);
      if ( !v9 )
      {
        dev_err(a1 + 16, "%s: ERROR could not ioremap: start=%pr, len=%u\n", "tz_log_probe", v8, debug_rw_buf_size);
        goto LABEL_66;
      }
      if ( !*(_QWORD *)(a1 + 760) )
      {
LABEL_23:
        v14 = (unsigned int)readl_relaxed(v9);
        v47 = 0;
        v45 = v14;
        v15 = qcom_scm_query_log_status(&v47);
        if ( !v15 )
        {
          v16 = ((unsigned __int8)v47 >> 1) & 1;
          byte_330 = v47 & 1;
LABEL_25:
          byte_331 = v16;
          goto LABEL_32;
        }
        v17 = v15;
        printk(&unk_A3A9, "tzdbg_query_log_status", v15);
        if ( v17 == -5 )
        {
          v18 = qcom_scm_query_encrypted_log_feature(&v47);
          if ( v18 )
          {
            v20 = v18;
            printk(&unk_996E, "tzdbg_query_log_status", v18);
            if ( v20 == -5 )
              goto LABEL_29;
          }
          else
          {
            byte_330 = v47 != 0;
            if ( !v47 )
            {
LABEL_29:
              LOBYTE(v16) = 1;
              goto LABEL_25;
            }
          }
        }
LABEL_32:
        printk(&unk_A46C, "tzdbg_query_log_status", (unsigned __int8)byte_330);
        if ( byte_331 == 1 )
        {
          tzdbg[0] = devm_ioremap(a1 + 16);
          if ( !tzdbg[0] )
          {
            dev_err(a1 + 16, "%s: could not ioremap: start=%pr, len=%u\n", "tz_log_probe", &v45, debug_rw_buf_size);
            goto LABEL_66;
          }
          v21 = _kmalloc_noprof((unsigned int)debug_rw_buf_size, 3520);
          if ( !v21 )
          {
            v7 = -12;
            goto LABEL_67;
          }
          qword_110 = v21;
        }
        if ( byte_330 == 1 )
        {
          if ( dword_33C == 9 && dword_338 >= 4 )
            byte_333 = 1;
          v22 = *(_QWORD *)(a1 + 760);
          if ( v22 )
            byte_334 = of_find_property(v22, "qcom,full-encrypted-tz-logs-enabled", 0) != 0;
        }
        if ( (of_property_read_variable_u32_array(
                *(_QWORD *)(a1 + 760),
                "tmecrashdump-address-offset",
                &tmecrashdump_address_offset,
                1,
                0)
            & 0x80000000) != 0 )
        {
          printk(&unk_A28D, "tzdbg_init_tme_log", v23);
        }
        else
        {
          qword_108 = devm_ioremap(a1 + 16);
          if ( qword_108 )
            goto LABEL_44;
          printk(&unk_9A21, "tzdbg_init_tme_log", (unsigned int)tmecrashdump_address_offset);
        }
        byte_318 = 0;
        printk(&unk_A7FE, "tz_log_probe", v35);
LABEL_44:
        LODWORD(v47) = 3;
        v48 = 6;
        if ( byte_332 == 1 )
        {
          if ( (of_property_read_variable_u32_array(
                  *(_QWORD *)(a1 + 760),
                  "qseelog-buf-size-v2",
                  &qseelog_buf_size,
                  1,
                  0)
              & 0x80000000) == 0 )
          {
            v24 = (unsigned int)qseelog_buf_size;
            goto LABEL_50;
          }
          v24 = 0x20000;
        }
        else
        {
          v24 = 0x8000;
        }
        qseelog_buf_size = v24;
LABEL_50:
        v25 = dma_alloc_attrs(a1 + 16, v24, &coh_pmem, 3264, 0);
        if ( v25 )
        {
          v27 = (_QWORD *)v25;
          if ( (byte_330 & 1) == 0
            && (unsigned int)qtee_shmbridge_register(
                               coh_pmem,
                               (unsigned int)qseelog_buf_size,
                               &v47,
                               &v48,
                               1,
                               6,
                               &qseelog_shmbridge_handle) )
          {
            printk(&unk_9E96, "tzdbg_register_qsee_log_buf", v28);
          }
          else
          {
            g_qsee_log = (__int64)v27;
            v29 = (unsigned int)qseelog_buf_size;
            g_qsee_log_v2 = (__int64)v27;
            *v27 = 0;
            v30 = qcom_scm_register_qsee_log_buf(coh_pmem, v29);
            if ( !v30 )
              goto LABEL_54;
            printk(&unk_A899, "tzdbg_register_qsee_log_buf", v30);
            if ( (byte_330 & 1) == 0 )
              qtee_shmbridge_deregister(qseelog_shmbridge_handle);
          }
          dma_free_attrs(a1 + 16, (unsigned int)qseelog_buf_size, g_qsee_log, coh_pmem, 0);
        }
        printk(&unk_A6AA, "tz_log_probe", v26);
        byte_278 = 0;
LABEL_54:
        LODWORD(v47) = 3;
        v48 = 6;
        if ( byte_330 != 1 )
          goto LABEL_59;
        qword_ABC8 = (unsigned int)qseelog_buf_size + 4096LL;
        qword_ABC0 = dma_alloc_attrs(a1 + 16, (unsigned int)qseelog_buf_size + 4096LL, &enc_qseelog_info, 3264, 0);
        if ( qword_ABC0 )
        {
          v32 = qtee_shmbridge_register(enc_qseelog_info, qword_ABC8, &v47, &v48, 1, 6, &qword_ABD0);
          if ( v32 )
          {
            printk(&unk_A8DF, "tzdbg_allocate_encrypted_log_buf", v32);
          }
          else
          {
            qword_ABE8 = (unsigned int)debug_rw_buf_size;
            qword_ABE0 = dma_alloc_attrs(a1 + 16, (unsigned int)debug_rw_buf_size, &enc_tzlog_info, 3264, 0);
            if ( qword_ABE0 )
            {
              v33 = qtee_shmbridge_register(enc_tzlog_info, qword_ABE8, &v47, &v48, 1, 6, &qword_ABF0);
              if ( !v33 )
              {
LABEL_59:
                if ( (unsigned int)qseelog_buf_size >> 30 )
                {
                  printk(&unk_9D2A, "tz_log_probe", v31);
                }
                else
                {
                  display_buf_size = 4 * qseelog_buf_size;
                  qword_130 = dma_alloc_attrs(a1 + 16, 4LL * (unsigned int)qseelog_buf_size, &disp_buf_paddr, 3264, 0);
                  if ( qword_130 )
                  {
                    g_realtime_consolidation_enable = tzdbg_query_tz_time() & 1;
                    if ( g_realtime_consolidation_enable )
                      printk(&unk_A9A4, "tz_log_probe", g_tz_ticks_baseline);
                    else
                      printk(&unk_A82E, "tz_log_probe", v38);
                    if ( !(unsigned int)tzdbg_fs_init(a1) )
                    {
                      v7 = 0;
                      goto LABEL_67;
                    }
                    dma_free_attrs(a1 + 16, (unsigned int)display_buf_size, qword_130, disp_buf_paddr, 0);
                  }
                  qtee_shmbridge_deregister(qword_ABF0);
                  dma_free_attrs(a1 + 16, qword_ABE8, qword_ABE0, enc_tzlog_info, 0);
                  qtee_shmbridge_deregister(qword_ABD0);
                  dma_free_attrs(a1 + 16, qword_ABC8, qword_ABC0, enc_qseelog_info, 0);
                }
                goto LABEL_62;
              }
              printk(&unk_AA6D, "tzdbg_allocate_encrypted_log_buf", v33);
              dma_free_attrs(a1 + 16, qword_ABE8, qword_ABE0, enc_tzlog_info, 0);
            }
            qtee_shmbridge_deregister(qword_ABD0);
          }
          dma_free_attrs(a1 + 16, qword_ABC8, qword_ABC0, enc_qseelog_info, 0);
        }
        dev_err(a1 + 16, " %s: Failed to allocate encrypted log buffer\n", "tz_log_probe");
LABEL_62:
        if ( (byte_330 & 1) == 0 )
          qtee_shmbridge_deregister(qseelog_shmbridge_handle);
        dma_free_attrs(a1 + 16, (unsigned int)qseelog_buf_size, g_qsee_log, coh_pmem, 0);
        if ( byte_331 == 1 )
          kfree(qword_110);
        goto LABEL_66;
      }
      v10 = v9;
      property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,hyplog-enabled", 0);
      byte_328 = property != 0;
      if ( !property )
      {
        byte_2C8 = 0;
        byte_2A0 = 0;
        byte_2F0 = 0;
        dev_info(a1 + 16, "Hyp log service not support\n");
LABEL_22:
        v9 = v10;
        goto LABEL_23;
      }
      v12 = *(_QWORD *)(a1 + 760);
      v48 = 0;
      v46 = 0;
      if ( (of_property_read_variable_u32_array(v12, "hyplog-address-offset", &v48, 1, 0) & 0x80000000) != 0 )
      {
        v19 = "hyplog address offset is not defined\n";
      }
      else
      {
        if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "hyplog-size-offset", &v46, 1, 0) & 0x80000000) == 0 )
        {
          v47 = (unsigned int)readl_relaxed(v10 + v48);
          dword_320 = readl_relaxed(v10 + v46);
          qword_F8 = devm_ioremap(a1 + 16);
          if ( !qword_F8 )
          {
            dev_err(a1 + 16, "ERROR could not ioremap: start=%pr, len=%u\n", &v47, dword_320);
            v13 = 4294967290LL;
LABEL_70:
            dev_err(a1 + 16, "%s: fail to get hypdbg_base ret %d\n", "tz_log_probe", v13);
LABEL_71:
            v7 = -22;
            goto LABEL_67;
          }
          v36 = (unsigned int)dword_320;
          v37 = _kmalloc_noprof((unsigned int)dword_320, 3520);
          if ( !v37 )
          {
            v13 = 4294967284LL;
            goto LABEL_70;
          }
          qword_118 = v37;
          if ( v36 >= 0xE && (v36 & 0xFFFFFFFE) != 0xE )
          {
            *(_WORD *)(v37 + 14) = 0;
            if ( (v36 & 0xFFFFFFFE) != 0xC )
            {
              *(_WORD *)(v37 + 12) = 0;
              v39 = *(_QWORD *)(a1 + 760);
              LODWORD(v47) = 0;
              v48 = 0;
              if ( (of_property_read_variable_u32_array(v39, "rmlog-address", &v47, 1, 0) & 0x80000000) != 0 )
              {
                v40 = "RM log address is not defined\n";
              }
              else
              {
                if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "rmlog-size", &v48, 1, 0) & 0x80000000) == 0 )
                {
                  dword_324 = v48;
                  if ( !v48 )
                  {
                    qword_100 = 0;
                    qword_120 = 0;
                    dev_err(a1 + 16, "RM log size is %d\n", 0);
                    goto LABEL_22;
                  }
                  qword_100 = devm_ioremap(a1 + 16);
                  if ( !qword_100 )
                  {
                    dev_err(a1 + 16, "ERROR could not ioremap: start=%u, len=%u\n", v47, dword_324);
                    v41 = 4294967290LL;
LABEL_110:
                    dev_err(a1 + 16, "%s: fail to get rmlog_base ret %d\n", "tz_log_probe", v41);
                    goto LABEL_71;
                  }
                  v42 = _kmalloc_noprof((unsigned int)dword_324, 3520);
                  if ( !v42 )
                  {
LABEL_109:
                    v41 = 4294967284LL;
                    goto LABEL_110;
                  }
LABEL_112:
                  qword_120 = v42;
                  goto LABEL_22;
                }
                v40 = "RM log size is not defined\n";
              }
              dev_err(a1 + 16, v40);
              dword_324 = 0;
              goto LABEL_22;
            }
          }
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v44 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &_update_rmlog_base__alloc_tag;
          v42 = _kmalloc_noprof(*(unsigned int *)(v36 + 804), 3520);
          *(_QWORD *)(StatusReg + 80) = v44;
          if ( !v42 )
            goto LABEL_109;
          goto LABEL_112;
        }
        v19 = "hyplog size offset is not defined\n";
      }
      dev_err(a1 + 16, v19);
      v13 = 4294967274LL;
      goto LABEL_70;
    }
    v7 = tz_feat_id_version;
    printk(&unk_A14F, "tzdbg_get_tz_version", "tzdbg_get_tz_version");
  }
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return v7;
}
