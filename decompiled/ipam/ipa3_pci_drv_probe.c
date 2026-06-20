__int64 __fastcall ipa3_pci_drv_probe(_DWORD *a1, __int64 a2)
{
  __int64 v3; // x8
  const void *v4; // x20
  __int64 v5; // x1
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // w4
  int v12; // w26
  int v13; // w28
  int v14; // w27
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w22
  int v18; // w23
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  unsigned int v35; // w22
  __int64 v36; // x23
  unsigned int v37; // w8
  __int64 result; // x0
  unsigned int v39; // w20
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  int v64; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v65; // [xsp+8h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = 0;
  if ( !a1 || !a2 )
  {
    printk(&unk_3E0399, a1);
LABEL_124:
    result = 4294967201LL;
    goto LABEL_125;
  }
  v3 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
    printk(&unk_3C30BD, "ipa3_pci_drv_probe");
    v43 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_126;
    v44 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v44 )
    {
      ipc_log_string(v44, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_pci_drv_probe", 12379);
      v43 = ipa3_ctx;
    }
    v45 = *(_QWORD *)(v43 + 34160);
    if ( v45 )
    {
      ipc_log_string(v45, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_pci_drv_probe", 12379);
      result = 4294966779LL;
    }
    else
    {
LABEL_126:
      result = 4294966779LL;
    }
    goto LABEL_125;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) )
  {
    v4 = a1 + 50;
  }
  else
  {
    if ( (of_property_read_variable_u32_array(0, "qcom,ipa-hw-ver", ipa3_ctx + 32240, 1, 0) & 0x80000000) != 0
      || (v3 = ipa3_ctx, !*(_DWORD *)(ipa3_ctx + 32240)) )
    {
      printk(&unk_3B1870, v5);
      result = 4294967277LL;
      goto LABEL_125;
    }
    v4 = a1 + 50;
    if ( !ipa3_ctx )
      goto LABEL_13;
  }
  v6 = *(_QWORD *)(v3 + 34152);
  if ( v6 )
  {
    ipc_log_string(v6, "ipa %s:%d IPA PCI driver probing started\n", "ipa3_pci_drv_probe", 12396);
    v3 = ipa3_ctx;
  }
  v7 = *(_QWORD *)(v3 + 34160);
  if ( v7 )
    ipc_log_string(v7, "ipa %s:%d IPA PCI driver probing started\n", "ipa3_pci_drv_probe", 12396);
LABEL_13:
  if ( (pci_enable_device(a1) & 0x80000000) != 0 )
  {
    printk(&unk_3CBA2D, "ipa3_pci_drv_probe");
    v46 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v47 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v47 )
      {
        ipc_log_string(v47, "ipa %s:%d pci_enable_device() failed\n", "ipa3_pci_drv_probe", 12405);
        v46 = ipa3_ctx;
      }
      v48 = *(_QWORD *)(v46 + 34160);
      if ( v48 )
        ipc_log_string(v48, "ipa %s:%d pci_enable_device() failed\n", "ipa3_pci_drv_probe", 12405);
    }
    goto LABEL_124;
  }
  if ( (pci_request_region(a1, 0, "IPA Memory") & 0x80000000) != 0 )
  {
    printk(&unk_3E03C4, "ipa3_pci_drv_probe");
    v49 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v50 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v50 )
      {
        ipc_log_string(v50, "ipa %s:%d pci_request_region() failed\n", "ipa3_pci_drv_probe", 12411);
        v49 = ipa3_ctx;
      }
      v51 = *(_QWORD *)(v49 + 34160);
      if ( v51 )
        ipc_log_string(v51, "ipa %s:%d pci_request_region() failed\n", "ipa3_pci_drv_probe", 12411);
    }
    goto LABEL_123;
  }
  if ( (unsigned int)get_ipa_dts_configuration((__int64)&ipa3_pci_drv_probe_platform_dev) )
  {
    printk(&unk_3E8BC2, "ipa3_pci_drv_probe");
    v52 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v53 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v53 )
      {
        ipc_log_string(v53, "ipa %s:%d get_ipa_dts_configuration() failed\n", "ipa3_pci_drv_probe", 12424);
        v52 = ipa3_ctx;
      }
      v54 = *(_QWORD *)(v52 + 34160);
      if ( v54 )
        ipc_log_string(v54, "ipa %s:%d get_ipa_dts_configuration() failed\n", "ipa3_pci_drv_probe", 12424);
    }
LABEL_122:
    pci_release_region(a1, 0);
LABEL_123:
    pci_disable_device(a1);
    goto LABEL_124;
  }
  if ( (of_property_read_variable_u32_array(0, "emulator-bar0-offset", &v64, 1, 0) & 0x80000000) == 0 )
  {
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d :using emulator-bar0-offset 0x%08X\n", "ipa3_pci_drv_probe", 12441, v64);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d :using emulator-bar0-offset 0x%08X\n", "ipa3_pci_drv_probe", 12441, v64);
        v8 = ipa3_ctx;
      }
      v11 = a1[279];
      v12 = dword_1F7DAC;
      v13 = dword_1F7DB4;
      v14 = dword_1F7DC0;
      dword_1F7DC8 = v11;
      if ( v8 )
      {
        v15 = *(_QWORD *)(v8 + 34152);
        if ( v15 )
        {
          ipc_log_string(v15, "ipa %s:%d EMULATION PCI_INTERRUPT_PIN(%u)\n", "ipa3_pci_drv_probe", 12453, v11);
          v8 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v8 + 34160);
        if ( v16 )
        {
          ipc_log_string(v16, "ipa %s:%d EMULATION PCI_INTERRUPT_PIN(%u)\n", "ipa3_pci_drv_probe", 12453, dword_1F7DC8);
          v8 = ipa3_ctx;
        }
        v17 = a1[280];
        if ( v8 )
        {
          v18 = a1[282];
          v19 = *(_QWORD *)(v8 + 34152);
          if ( v19 )
          {
            ipc_log_string(v19, "ipa %s:%d PCI START = 0x%x\n", "ipa3_pci_drv_probe", 12461, v17);
            v8 = ipa3_ctx;
          }
          v20 = *(_QWORD *)(v8 + 34160);
          if ( v20 )
          {
            ipc_log_string(v20, "ipa %s:%d PCI START = 0x%x\n", "ipa3_pci_drv_probe", 12461, v17);
            v8 = ipa3_ctx;
          }
          if ( v8 )
          {
            v21 = *(_QWORD *)(v8 + 34152);
            if ( v21 )
            {
              ipc_log_string(v21, "ipa %s:%d PCI END = 0x%x\n", "ipa3_pci_drv_probe", 12462, v18);
              v8 = ipa3_ctx;
            }
            v22 = *(_QWORD *)(v8 + 34160);
            if ( v22 )
            {
              ipc_log_string(v22, "ipa %s:%d PCI END = 0x%x\n", "ipa3_pci_drv_probe", 12462, v18);
              v8 = ipa3_ctx;
            }
          }
        }
LABEL_39:
        dword_1F7DAC = v64 + v17;
        dword_1F79AC = v64 + v17;
        dword_1F79B0 = dword_1F7DB0;
        dword_1F7DB4 = v13 - v12 + v64 + v17;
        dword_1F7DC0 = v14 - v12 + v64 + v17;
        if ( v8 )
        {
          v23 = *(_QWORD *)(v8 + 34152);
          if ( v23 )
          {
            ipc_log_string(v23, "ipa %s:%d ipa_mem_base = 0x%x\n", "ipa3_pci_drv_probe", 12476, v64 + v17);
            v8 = ipa3_ctx;
          }
          v24 = *(_QWORD *)(v8 + 34160);
          if ( v24 )
          {
            ipc_log_string(v24, "ipa %s:%d ipa_mem_base = 0x%x\n", "ipa3_pci_drv_probe", 12476, dword_1F7DAC);
            v8 = ipa3_ctx;
          }
          if ( v8 )
          {
            v25 = *(_QWORD *)(v8 + 34152);
            if ( v25 )
            {
              ipc_log_string(v25, "ipa %s:%d ipa_mem_size = 0x%x\n", "ipa3_pci_drv_probe", 12478, dword_1F7DB0);
              v8 = ipa3_ctx;
            }
            v26 = *(_QWORD *)(v8 + 34160);
            if ( v26 )
            {
              ipc_log_string(v26, "ipa %s:%d ipa_mem_size = 0x%x\n", "ipa3_pci_drv_probe", 12478, dword_1F7DB0);
              v8 = ipa3_ctx;
            }
            if ( v8 )
            {
              v27 = *(_QWORD *)(v8 + 34152);
              if ( v27 )
              {
                ipc_log_string(v27, "ipa %s:%d transport_mem_base = 0x%x\n", "ipa3_pci_drv_probe", 12481, dword_1F7DB4);
                v8 = ipa3_ctx;
              }
              v28 = *(_QWORD *)(v8 + 34160);
              if ( v28 )
              {
                ipc_log_string(v28, "ipa %s:%d transport_mem_base = 0x%x\n", "ipa3_pci_drv_probe", 12481, dword_1F7DB4);
                v8 = ipa3_ctx;
              }
              if ( v8 )
              {
                v29 = *(_QWORD *)(v8 + 34152);
                if ( v29 )
                {
                  ipc_log_string(
                    v29,
                    "ipa %s:%d transport_mem_size = 0x%x\n",
                    "ipa3_pci_drv_probe",
                    12483,
                    dword_1F7DB8);
                  v8 = ipa3_ctx;
                }
                v30 = *(_QWORD *)(v8 + 34160);
                if ( v30 )
                {
                  ipc_log_string(
                    v30,
                    "ipa %s:%d transport_mem_size = 0x%x\n",
                    "ipa3_pci_drv_probe",
                    12483,
                    dword_1F7DB8);
                  v8 = ipa3_ctx;
                }
                if ( v8 )
                {
                  v31 = *(_QWORD *)(v8 + 34152);
                  if ( v31 )
                  {
                    ipc_log_string(
                      v31,
                      "ipa %s:%d emulator_intcntrlr_mem_base = 0x%x\n",
                      "ipa3_pci_drv_probe",
                      12486,
                      dword_1F7DC0);
                    v8 = ipa3_ctx;
                  }
                  v32 = *(_QWORD *)(v8 + 34160);
                  if ( v32 )
                  {
                    ipc_log_string(
                      v32,
                      "ipa %s:%d emulator_intcntrlr_mem_base = 0x%x\n",
                      "ipa3_pci_drv_probe",
                      12486,
                      dword_1F7DC0);
                    v8 = ipa3_ctx;
                  }
                  if ( v8 )
                  {
                    v33 = *(_QWORD *)(v8 + 34152);
                    if ( v33 )
                    {
                      ipc_log_string(
                        v33,
                        "ipa %s:%d emulator_intcntrlr_mem_size = 0x%x\n",
                        "ipa3_pci_drv_probe",
                        12488,
                        dword_1F7DC4);
                      v8 = ipa3_ctx;
                    }
                    v34 = *(_QWORD *)(v8 + 34160);
                    if ( v34 )
                      ipc_log_string(
                        v34,
                        "ipa %s:%d emulator_intcntrlr_mem_size = 0x%x\n",
                        "ipa3_pci_drv_probe",
                        12488,
                        dword_1F7DC4);
                  }
                }
              }
            }
          }
        }
        if ( (_BYTE)word_1F7DF3 )
          v35 = 64;
        else
          v35 = 32;
        if ( (_BYTE)word_1F7DF3 )
          v36 = -1;
        else
          v36 = ~(-1LL << v35);
        if ( (unsigned int)dma_set_mask(v4, v36) )
        {
          printk(&unk_3DA9BB, "ipa3_pci_drv_probe");
          v58 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v59 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v59 )
            {
              ipc_log_string(v59, "ipa %s:%d dma_set_mask(%pK, %u) failed\n", "ipa3_pci_drv_probe", 12493, v4, v35);
              v58 = ipa3_ctx;
            }
            v60 = *(_QWORD *)(v58 + 34160);
            if ( v60 )
              ipc_log_string(v60, "ipa %s:%d dma_set_mask(%pK, %u) failed\n", "ipa3_pci_drv_probe", 12493, v4, v35);
          }
        }
        else
        {
          if ( !(unsigned int)dma_set_coherent_mask(v4, v36) )
          {
            pci_set_master(a1);
            memset(&ipa3_pci_drv_probe_platform_dev, 0, 0x3F0u);
            memcpy(&unk_1F79C8, v4, 0x390u);
            v37 = ipa3_pre_init((__int64)&ipa3_pci_drv_probe_platform_dev);
            result = 0;
            if ( v37 )
            {
              v39 = v37;
              printk(&unk_3C30E7, "ipa3_pci_drv_probe");
              v40 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v41 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v41 )
                {
                  ipc_log_string(v41, "ipa %s:%d ipa3_init failed\n", "ipa3_pci_drv_probe", 12514);
                  v40 = ipa3_ctx;
                }
                v42 = *(_QWORD *)(v40 + 34160);
                if ( v42 )
                  ipc_log_string(v42, "ipa %s:%d ipa3_init failed\n", "ipa3_pci_drv_probe", 12514);
              }
              pci_clear_master(a1);
              pci_release_region(a1, 0);
              pci_disable_device(a1);
              result = v39;
            }
            goto LABEL_125;
          }
          printk(&unk_3F7043, "ipa3_pci_drv_probe");
          v61 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v62 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v62 )
            {
              ipc_log_string(
                v62,
                "ipa %s:%d dma_set_coherent_mask(%pK, %u) failed\n",
                "ipa3_pci_drv_probe",
                12500,
                v4,
                v35);
              v61 = ipa3_ctx;
            }
            v63 = *(_QWORD *)(v61 + 34160);
            if ( v63 )
              ipc_log_string(
                v63,
                "ipa %s:%d dma_set_coherent_mask(%pK, %u) failed\n",
                "ipa3_pci_drv_probe",
                12500,
                v4,
                v35);
          }
        }
        goto LABEL_122;
      }
    }
    else
    {
      v12 = dword_1F7DAC;
      v13 = dword_1F7DB4;
      v14 = dword_1F7DC0;
      dword_1F7DC8 = a1[279];
    }
    v17 = a1[280];
    v8 = 0;
    goto LABEL_39;
  }
  printk(&unk_3E59AA, "ipa3_pci_drv_probe");
  v55 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v56 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v56 )
    {
      ipc_log_string(v56, "ipa %s:%d :get resource failed for emulator-bar0-offset!\n", "ipa3_pci_drv_probe", 12436);
      v55 = ipa3_ctx;
    }
    v57 = *(_QWORD *)(v55 + 34160);
    if ( v57 )
      ipc_log_string(v57, "ipa %s:%d :get resource failed for emulator-bar0-offset!\n", "ipa3_pci_drv_probe", 12436);
  }
  pci_release_region(a1, 0);
  pci_disable_device(a1);
  result = 4294967277LL;
LABEL_125:
  _ReadStatusReg(SP_EL0);
  return result;
}
