__int64 __fastcall qcom_glink_smem_register(__int64 a1, const void *a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x19
  const char **v6; // x8
  const char *v7; // x2
  int v8; // w0
  int v9; // w0
  _QWORD *v10; // x21
  __int64 v11; // x0
  unsigned __int64 v12; // x22
  _QWORD *v13; // x20
  int v14; // w0
  __int64 v15; // x0
  int v16; // w0
  unsigned __int64 v17; // x0
  unsigned int v18; // w0
  int v19; // w0
  unsigned __int64 v20; // x0
  __int64 v21; // x0
  int v22; // w20
  const char *v23; // x1
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v26; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v25 = 0;
  v4 = (_QWORD *)_kmalloc_cache_noprof(mbox_request_channel, 3520, 1032);
  v5 = (__int64)v4;
  if ( !v4 )
  {
    v5 = -12;
    goto LABEL_34;
  }
  v6 = *(const char ***)(a1 + 96);
  v4[12] = a1;
  v4[93] = a2;
  v4[101] = qcom_glink_smem_release;
  v7 = v6[14];
  if ( !v7 )
    v7 = *v6;
  dev_set_name(v4, "%s:%pOFn", v7, a2);
  v8 = device_register(v5);
  if ( v8 )
  {
    v22 = v8;
    printk(&unk_6CAE);
    put_device(v5);
    v5 = v22;
    goto LABEL_34;
  }
  v9 = of_property_read_variable_u32_array(*(_QWORD *)(v5 + 744), "qcom,remote-pid", &v26, 1, 0);
  if ( v9 < 0 )
  {
    LODWORD(v12) = v9;
    v23 = "failed to parse qcom,remote-pid\n";
LABEL_31:
    dev_err(v5, v23);
    goto LABEL_32;
  }
  *(_DWORD *)(v5 + 1024) = v26;
  v10 = (_QWORD *)devm_kmalloc(v5, 80, 3520);
  v11 = devm_kmalloc(v5, 80, 3520);
  LODWORD(v12) = -12;
  if ( !v10 )
    goto LABEL_32;
  v13 = (_QWORD *)v11;
  if ( !v11 )
    goto LABEL_32;
  v14 = qcom_smem_alloc(v26, 478, 32);
  if ( v14 != -17 )
  {
    LODWORD(v12) = v14;
    if ( v14 )
    {
      v23 = "failed to allocate glink descriptors\n";
      goto LABEL_31;
    }
  }
  v12 = qcom_smem_get(v26, 478, &v25);
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v5, "failed to acquire xprt descriptor\n");
    goto LABEL_32;
  }
  if ( v25 != 32 )
  {
    dev_err(v5, "glink descriptor of invalid size\n");
    LODWORD(v12) = -22;
    goto LABEL_32;
  }
  v15 = v26;
  v13[6] = v12;
  v13[7] = v12 + 4;
  v10[6] = v12 + 8;
  v10[7] = v12 + 12;
  v16 = qcom_smem_alloc(v15, 479, 0x4000);
  if ( v16 != -17 )
  {
    LODWORD(v12) = v16;
    if ( v16 )
    {
      v23 = "failed to allocate TX fifo\n";
      goto LABEL_31;
    }
  }
  v17 = qcom_smem_get(v26, 479, v13);
  v13[8] = v17;
  if ( v17 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v5, "failed to acquire TX fifo\n");
    LODWORD(v12) = *((_DWORD *)v13 + 16);
    goto LABEL_32;
  }
  scnprintf(v5 + 916, 32, "glink-native-%u", v26);
  v18 = of_irq_get(*(_QWORD *)(v5 + 744), 0);
  *(_DWORD *)(v5 + 912) = v18;
  v19 = devm_request_threaded_irq(v5, v18, qcom_glink_smem_intr, 0, 540672, v5 + 916, v5);
  if ( v19 )
  {
    LODWORD(v12) = v19;
    v23 = "failed to request IRQ\n";
    goto LABEL_31;
  }
  *(_QWORD *)(v5 + 960) = v5;
  *(_BYTE *)(v5 + 984) = 1;
  v20 = mbox_request_channel(v5 + 960, 0);
  *(_QWORD *)(v5 + 1016) = v20;
  if ( v20 >= 0xFFFFFFFFFFFFF001LL )
  {
    LODWORD(v12) = dev_err_probe(v5, v20, "failed to acquire IPC channel\n");
LABEL_32:
    device_unregister(v5);
    v5 = (int)v12;
    goto LABEL_34;
  }
  v10[9] = v5;
  v10[1] = glink_smem_rx_avail;
  v10[2] = glink_smem_rx_peek;
  v10[3] = glink_smem_rx_advance;
  v13[1] = glink_smem_tx_avail;
  v13[9] = v5;
  v13[4] = glink_smem_tx_write;
  v13[5] = glink_smem_tx_kick;
  *(_DWORD *)v10[6] = 0;
  *(_DWORD *)v13[7] = 0;
  v12 = qcom_glink_native_probe(v5, 9, v10, v13, 0);
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    mbox_free_channel(*(_QWORD *)(v5 + 1016));
    goto LABEL_32;
  }
  if ( !glink_ilctxt )
    glink_ilctxt = ipc_log_context_create(32, "glink_smem", 0);
  v21 = *(unsigned int *)(v5 + 912);
  *(_QWORD *)(v5 + 952) = v12;
  enable_irq(v21);
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v5;
}
