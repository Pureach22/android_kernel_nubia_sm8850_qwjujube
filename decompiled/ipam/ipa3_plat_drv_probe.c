__int64 __fastcall ipa3_plat_drv_probe(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned int v4; // w9
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  int v10; // w12
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  void *v14; // x0
  __int64 result; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  unsigned int ipa_dts_configuration; // w0
  __int64 v35; // x21
  unsigned int v36; // w22
  unsigned int gsi_ver; // w0
  __int64 property; // x21
  __int64 v39; // x0
  unsigned int v40; // w0
  unsigned int v41; // w21
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  unsigned int v51; // w0
  unsigned int v52; // w19
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x8
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x8
  __int64 v69; // x0
  __int64 v70; // x0

  v2 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
    printk(&unk_3C30BD, "ipa3_plat_drv_probe");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11757);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11757);
        return 4294966779LL;
      }
    }
    return 4294966779LL;
  }
  v4 = *(_DWORD *)(ipa3_ctx + 32240);
  if ( !v4 )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,ipa-hw-ver", ipa3_ctx + 32240, 1, 0)
        & 0x80000000) != 0
      || (v2 = ipa3_ctx, (v4 = *(_DWORD *)(ipa3_ctx + 32240)) == 0) )
    {
      v14 = &unk_3B1870;
      goto LABEL_37;
    }
  }
  if ( v4 <= 9 )
  {
    v14 = &unk_3DA966;
LABEL_37:
    printk(v14, a2);
    return 4294967277LL;
  }
  if ( v4 >= 0x1A )
  {
    v14 = &unk_3B748F;
    goto LABEL_37;
  }
  if ( v2 )
  {
    v5 = *(_QWORD *)(v2 + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d IPA driver probing started\n", "ipa3_plat_drv_probe", 11783);
      v2 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v2 + 34160);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d IPA driver probing started\n", "ipa3_plat_drv_probe", 11783);
      v2 = ipa3_ctx;
    }
    if ( v2 )
    {
      v7 = *(_QWORD *)(v2 + 34152);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "ipa %s:%d dev->of_node->name = %s\n",
          "ipa3_plat_drv_probe",
          11784,
          **(const char ***)(a1 + 760));
        v2 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v2 + 34160);
      if ( v8 )
        ipc_log_string(
          v8,
          "ipa %s:%d dev->of_node->name = %s\n",
          "ipa3_plat_drv_probe",
          11784,
          **(const char ***)(a1 + 760));
    }
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,ipa-smmu-ap-cb") )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_DWORD *)(ipa3_ctx + 50136);
      qword_1F7818 = a1 + 16;
      smmu_info = 1;
LABEL_62:
      *(_DWORD *)(v9 + 50136) = v10 + 1;
      return ipa_smmu_update_fw_loader();
    }
    printk(&unk_3C30BD, "ipa3_plat_drv_probe");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11788);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11788);
        return 4294966779LL;
      }
    }
    return 4294966779LL;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,ipa-smmu-wlan-cb") )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      qword_1F7850 = a1 + 16;
      v10 = *(_DWORD *)(ipa3_ctx + 50136);
      byte_1F79A1 = 1;
      goto LABEL_62;
    }
    printk(&unk_3C30BD, "ipa3_plat_drv_probe");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11800);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11800);
        return 4294966779LL;
      }
    }
    return 4294966779LL;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,ipa-smmu-wlan1-cb") )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      qword_1F7888 = a1 + 16;
      v10 = *(_DWORD *)(ipa3_ctx + 50136);
      byte_1F79A2 = 1;
      goto LABEL_62;
    }
    printk(&unk_3C30BD, "ipa3_plat_drv_probe");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11812);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11812);
        return 4294966779LL;
      }
    }
    return 4294966779LL;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,ipa-smmu-eth-cb") )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      qword_1F7930 = a1 + 16;
      v10 = *(_DWORD *)(ipa3_ctx + 50136);
      byte_1F79A5 = 1;
      goto LABEL_62;
    }
    printk(&unk_3C30BD, "ipa3_plat_drv_probe");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11824);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11824);
        return 4294966779LL;
      }
    }
    return 4294966779LL;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,ipa-smmu-eth1-cb") )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      qword_1F7968 = a1 + 16;
      v10 = *(_DWORD *)(ipa3_ctx + 50136);
      byte_1F79A6 = 1;
      goto LABEL_62;
    }
    printk(&unk_3C30BD, "ipa3_plat_drv_probe");
    v28 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v29 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v29 )
      {
        ipc_log_string(v29, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11836);
        v28 = ipa3_ctx;
      }
      v30 = *(_QWORD *)(v28 + 34160);
      if ( v30 )
      {
        ipc_log_string(v30, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11836);
        return 4294966779LL;
      }
    }
    return 4294966779LL;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,ipa-smmu-uc-cb") )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      qword_1F78C0 = a1 + 16;
      v10 = *(_DWORD *)(ipa3_ctx + 50136);
      byte_1F79A3 = 1;
      goto LABEL_62;
    }
    printk(&unk_3C30BD, "ipa3_plat_drv_probe");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(v32, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11848);
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
      {
        ipc_log_string(v33, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11848);
        return 4294966779LL;
      }
    }
    return 4294966779LL;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,ipa-smmu-11ad-cb") )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      qword_1F78F8 = a1 + 16;
      v10 = *(_DWORD *)(ipa3_ctx + 50136);
      byte_1F79A4 = 1;
      goto LABEL_62;
    }
    printk(&unk_3C30BD, "ipa3_plat_drv_probe");
    v45 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v46 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v46 )
      {
        ipc_log_string(v46, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11860);
        v45 = ipa3_ctx;
      }
      v47 = *(_QWORD *)(v45 + 34160);
      if ( v47 )
      {
        ipc_log_string(v47, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_plat_drv_probe", 11860);
        return 4294966779LL;
      }
    }
    return 4294966779LL;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,smp2p-map-ipa-1-out")
    || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), "qcom,smp2p-map-ipa-1-in") )
  {
    return ipa3_smp2p_probe(a1 + 16);
  }
  ipa_dts_configuration = get_ipa_dts_configuration(a1);
  if ( ipa_dts_configuration )
  {
    v41 = ipa_dts_configuration;
    printk(&unk_3AEE75, "ipa3_plat_drv_probe");
    v56 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v57 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v57 )
      {
        ipc_log_string(v57, "ipa %s:%d IPA dts parsing failed\n", "ipa3_plat_drv_probe", 11879);
        v56 = ipa3_ctx;
      }
      v58 = *(_QWORD *)(v56 + 34160);
      if ( v58 )
      {
        ipc_log_string(v58, "ipa %s:%d IPA dts parsing failed\n", "ipa3_plat_drv_probe", 11879);
        return v41;
      }
    }
    return v41;
  }
  v35 = (unsigned int)dword_1F7DB4;
  v36 = dword_1F7DB8;
  gsi_ver = ipa3_get_gsi_ver((unsigned int)qword_1F7DDC);
  if ( !(unsigned int)gsi_map_base(v35, v36, gsi_ver) )
  {
    *(_DWORD *)(ipa3_ctx + 32252) = ipa3_get_gsi_ver((unsigned int)qword_1F7DDC);
    property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,arm-smmu", 0);
    v39 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,use-64-bit-dma-mask", 0);
    if ( property )
    {
      if ( !v39 || (byte_1F79A8 = 1, !(unsigned int)dma_set_mask_and_coherent(a1 + 16, -1)) )
      {
        byte_1F79A7 = 1;
        v40 = ipa3_pre_init(a1);
        if ( v40 )
        {
          v41 = v40;
          printk(&unk_3C30E7, "ipa3_plat_drv_probe");
          v42 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v43 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v43 )
            {
              ipc_log_string(v43, "ipa %s:%d ipa3_init failed\n", "ipa3_plat_drv_probe", 11939);
              v42 = ipa3_ctx;
            }
            v44 = *(_QWORD *)(v42 + 34160);
            if ( v44 )
            {
              ipc_log_string(v44, "ipa %s:%d ipa3_init failed\n", "ipa3_plat_drv_probe", 11939);
              return v41;
            }
          }
          return v41;
        }
        goto LABEL_110;
      }
      printk(&unk_3C0098, "ipa3_plat_drv_probe");
      v62 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v63 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v63 )
        {
          ipc_log_string(v63, "ipa %s:%d DMA set 64bit mask failed\n", "ipa3_plat_drv_probe", 11905);
          v62 = ipa3_ctx;
        }
        v64 = *(_QWORD *)(v62 + 34160);
        if ( v64 )
        {
          ipc_log_string(v64, "ipa %s:%d DMA set 64bit mask failed\n", "ipa3_plat_drv_probe", 11905);
          return 4294967201LL;
        }
      }
      return 4294967201LL;
    }
    if ( v39 )
    {
      if ( (unsigned int)dma_set_mask_and_coherent(a1 + 16, -1) )
      {
        printk(&unk_3C0098, "ipa3_plat_drv_probe");
        v48 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v49 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v49 )
          {
            ipc_log_string(v49, "ipa %s:%d DMA set 64bit mask failed\n", "ipa3_plat_drv_probe", 11914);
            v48 = ipa3_ctx;
          }
          v50 = *(_QWORD *)(v48 + 34160);
          if ( v50 )
          {
            ipc_log_string(v50, "ipa %s:%d DMA set 64bit mask failed\n", "ipa3_plat_drv_probe", 11914);
            return 4294967201LL;
          }
        }
        return 4294967201LL;
      }
    }
    else if ( (unsigned int)dma_set_mask_and_coherent(a1 + 16, 0xFFFFFFFFLL) )
    {
      printk(&unk_3F6FC1, "ipa3_plat_drv_probe");
      v68 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v69 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v69 )
        {
          ipc_log_string(v69, "ipa %s:%d DMA set 32bit mask failed\n", "ipa3_plat_drv_probe", 11919);
          v68 = ipa3_ctx;
        }
        v70 = *(_QWORD *)(v68 + 34160);
        if ( v70 )
        {
          ipc_log_string(v70, "ipa %s:%d DMA set 32bit mask failed\n", "ipa3_plat_drv_probe", 11919);
          return 4294967201LL;
        }
      }
      return 4294967201LL;
    }
    v51 = ipa3_pre_init(a1);
    if ( v51 )
    {
      v41 = v51;
      printk(&unk_3C30E7, "ipa3_plat_drv_probe");
      v65 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v66 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v66 )
        {
          ipc_log_string(v66, "ipa %s:%d ipa3_init failed\n", "ipa3_plat_drv_probe", 11929);
          v65 = ipa3_ctx;
        }
        v67 = *(_QWORD *)(v65 + 34160);
        if ( v67 )
        {
          ipc_log_string(v67, "ipa %s:%d ipa3_init failed\n", "ipa3_plat_drv_probe", 11929);
          return v41;
        }
      }
      return v41;
    }
    ipa_fw_load_sm_handle_event(1);
LABEL_110:
    result = of_platform_populate(*(_QWORD *)(a1 + 760), &ipa_plat_drv_match, 0, a1 + 16);
    if ( (_DWORD)result )
    {
      v52 = result;
      printk(&unk_3F4725, "ipa3_plat_drv_probe");
      v53 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v54 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v54 )
        {
          ipc_log_string(v54, "ipa %s:%d failed to populate platform\n", "ipa3_plat_drv_probe", 11947);
          v53 = ipa3_ctx;
        }
        v55 = *(_QWORD *)(v53 + 34160);
        if ( v55 )
          ipc_log_string(v55, "ipa %s:%d failed to populate platform\n", "ipa3_plat_drv_probe", 11947);
      }
      return v52;
    }
    return result;
  }
  printk(&unk_3C9043, "ipa3_plat_drv_probe");
  v59 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 4294967282LL;
  v60 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v60 )
  {
    ipc_log_string(v60, "ipa %s:%d Allocation of gsi base failed\n", "ipa3_plat_drv_probe", 11893);
    v59 = ipa3_ctx;
  }
  v61 = *(_QWORD *)(v59 + 34160);
  if ( !v61 )
    return 4294967282LL;
  ipc_log_string(v61, "ipa %s:%d Allocation of gsi base failed\n", "ipa3_plat_drv_probe", 11893);
  return 4294967282LL;
}
