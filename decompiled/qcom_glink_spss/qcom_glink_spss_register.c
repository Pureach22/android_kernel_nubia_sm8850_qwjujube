__int64 __fastcall qcom_glink_spss_register(__int64 a1, const void *a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x19
  const char **v6; // x8
  const char *v7; // x2
  int v8; // w0
  int v9; // w0
  _QWORD *v10; // x20
  __int64 v11; // x0
  unsigned __int64 v12; // x22
  _QWORD *v13; // x21
  int v14; // w0
  _DWORD *v15; // x23
  unsigned int v16; // w0
  int v17; // w0
  unsigned __int64 v18; // x0
  unsigned int v19; // w22
  __int64 v20; // x0
  __int64 v21; // x24
  __int64 v22; // x23
  unsigned int matched; // w25
  unsigned int v24; // w0
  unsigned int v25; // w26
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x25
  const char *v28; // x1
  unsigned __int64 v29; // x0
  unsigned __int64 v30; // x24
  __int64 v31; // x0
  const char *v32; // x1
  __int64 v34; // [xsp+0h] [xbp-E0h] BYREF
  unsigned int v35; // [xsp+Ch] [xbp-D4h] BYREF
  _QWORD v36[12]; // [xsp+10h] [xbp-D0h] BYREF
  _QWORD v37[14]; // [xsp+70h] [xbp-70h] BYREF

  v37[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v34 = 0;
  v4 = (_QWORD *)_kmalloc_cache_noprof(mbox_request_channel, 3520, 1048);
  v5 = (__int64)v4;
  if ( !v4 )
  {
    v5 = -12;
    goto LABEL_42;
  }
  v6 = *(const char ***)(a1 + 96);
  v4[12] = a1;
  v4[93] = a2;
  v4[101] = qcom_glink_spss_release;
  v7 = v6[14];
  if ( !v7 )
    v7 = *v6;
  dev_set_name(v4, "%s:%pOFn", v7, a2);
  v8 = device_register(v5);
  if ( v8 )
  {
    LODWORD(v12) = v8;
    printk(&unk_6BE9);
    goto LABEL_37;
  }
  v9 = of_property_read_variable_u32_array(*(_QWORD *)(v5 + 744), "qcom,remote-pid", &v35, 1, 0);
  if ( v9 < 0 )
  {
    LODWORD(v12) = v9;
    v28 = "failed to parse qcom,remote-pid\n";
LABEL_33:
    dev_err(v5, v28);
    goto LABEL_37;
  }
  *(_DWORD *)(v5 + 1040) = v35;
  v10 = (_QWORD *)devm_kmalloc(v5, 80, 3520);
  v11 = devm_kmalloc(v5, 80, 3520);
  LODWORD(v12) = -12;
  if ( !v10 )
    goto LABEL_37;
  v13 = (_QWORD *)v11;
  if ( !v11 )
    goto LABEL_37;
  v34 = 4120;
  v14 = qcom_smem_alloc(v35, 478, 4120);
  if ( v14 != -17 )
  {
    LODWORD(v12) = v14;
    if ( v14 )
    {
      v28 = "failed to allocate glink descriptors\n";
      goto LABEL_33;
    }
  }
  v15 = (_DWORD *)qcom_smem_get(v35, 478, &v34);
  if ( (unsigned __int64)v15 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v5, "failed to acquire xprt descriptor\n");
    LODWORD(v12) = (_DWORD)v15;
    goto LABEL_37;
  }
  if ( v34 != 4120 )
  {
    dev_err(v5, "glink descriptor of invalid size\n");
    LODWORD(v12) = -22;
    goto LABEL_37;
  }
  scnprintf(v5 + 916, 32, "glink-native-%u", v35);
  v16 = of_irq_get(*(_QWORD *)(v5 + 744), 0);
  *(_DWORD *)(v5 + 912) = v16;
  v17 = devm_request_threaded_irq(v5, v16, qcom_glink_spss_intr, 0, 540672, v5 + 916, v5);
  if ( v17 )
  {
    LODWORD(v12) = v17;
    v28 = "failed to request IRQ\n";
    goto LABEL_33;
  }
  *(_QWORD *)(v5 + 960) = v5;
  *(_BYTE *)(v5 + 984) = 1;
  v18 = mbox_request_channel(v5 + 960, 0);
  *(_QWORD *)(v5 + 1016) = v18;
  if ( v18 >= 0xFFFFFFFFFFFFF001LL )
  {
    LODWORD(v12) = dev_err_probe(v5, v18, "failed to acquire IPC channel\n");
LABEL_37:
    put_device(v5);
    v5 = (int)v12;
    goto LABEL_42;
  }
  v15[2] = 2048;
  v19 = v34;
  v15[5] = 2048;
  v13[6] = v15;
  v13[7] = v15 + 1;
  v13[8] = v15 + 6;
  v13[9] = v5;
  v10[6] = v15 + 3;
  v10[7] = v15 + 4;
  v10[8] = v15 + 518;
  v10[9] = v5;
  *(_QWORD *)(v5 + 1024) = v13;
  *v10 = 2048;
  v10[1] = glink_spss_rx_avail;
  v10[2] = glink_spss_rx_peek;
  v10[3] = glink_spss_rx_advance;
  *v13 = 2048;
  v13[1] = glink_spss_tx_avail;
  *(_QWORD *)(v5 + 1032) = v10;
  v13[4] = glink_spss_tx_write;
  v13[5] = glink_spss_tx_kick;
  v15[3] = 0;
  v15[1] = 0;
  v20 = qcom_smem_virt_to_phys(v15);
  v21 = *(_QWORD *)(v5 + 744);
  v22 = v20;
  memset(v37, 0, 96);
  memset(v36, 0, sizeof(v36));
  matched = of_property_match_string(v21, "reg-names", "qcom,spss-addr");
  v24 = of_property_match_string(v21, "reg-names", "qcom,spss-size");
  if ( (matched & 0x80000000) != 0 || (v25 = v24, (v24 & 0x80000000) != 0) )
  {
    dev_err(v5, "failed to find location registers\n");
    LODWORD(v12) = -22;
    goto LABEL_36;
  }
  if ( (unsigned int)of_address_to_resource(v21, matched, v37) )
    goto LABEL_18;
  v26 = ioremap_prot();
  if ( !v26 || (v27 = v26, v26 >= 0xFFFFFFFFFFFFF001LL) )
  {
    v32 = "failed to map spss addr resource\n";
LABEL_40:
    dev_err(v5, v32);
LABEL_18:
    LODWORD(v12) = -12;
LABEL_36:
    mbox_free_channel(*(_QWORD *)(v5 + 1016));
    goto LABEL_37;
  }
  if ( (unsigned int)of_address_to_resource(v21, v25, v36) )
  {
    iounmap(v27);
    LODWORD(v12) = -12;
    goto LABEL_36;
  }
  v29 = ioremap_prot();
  if ( !v29 || (v30 = v29, v29 >= 0xFFFFFFFFFFFFF001LL) )
  {
    iounmap(v27);
    v32 = "failed to map spss size resource\n";
    goto LABEL_40;
  }
  writeq_relaxed(v22, v27);
  writel_relaxed(v19, v30);
  iounmap(v27);
  iounmap(v30);
  v12 = qcom_glink_native_probe(v5, 1, v10, v13, 0);
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_36;
  v31 = *(unsigned int *)(v5 + 912);
  *(_QWORD *)(v5 + 952) = v12;
  enable_irq(v31);
  LODWORD(v12) = qcom_glink_native_start(v12);
  if ( (_DWORD)v12 )
    goto LABEL_36;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v5;
}
