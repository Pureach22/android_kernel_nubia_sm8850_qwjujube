__int64 __fastcall cnss_pci_init_smmu(__int64 a1)
{
  _QWORD *v2; // x24
  __int64 v3; // x25
  __int64 v4; // x6
  __int64 v5; // x7
  unsigned int v6; // w21
  __int64 v7; // x20
  unsigned __int64 StatusReg; // x22
  const char *v9; // x1
  __int64 v10; // x6
  __int64 v11; // x7
  const char *v12; // x1
  __int64 v13; // x0
  unsigned int iommu_addr; // w0
  __int64 v15; // x7
  int v16; // w9
  const char *v17; // x1
  const char *v18; // x1
  __int64 *resource_byname; // x0
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x0
  __int64 v24; // x7
  const char *v25; // x1
  __int64 property; // x0
  __int64 v27; // x7
  bool v28; // zf
  __int64 v29; // x8
  __int64 v30; // x0
  char v31; // w9
  const char *v32; // x1
  char *s2; // [xsp+0h] [xbp-60h] BYREF
  _QWORD v35[11]; // [xsp+8h] [xbp-58h] BYREF

  v35[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)a1;
  v2 = *(_QWORD **)(a1 + 8);
  s2 = nullptr;
  memset(v35, 0, 80);
  v6 = 0;
  if ( !(unsigned int)_of_parse_phandle_with_args(*(_QWORD *)(v3 + 944), "qcom,iommu-group", 0, 0, 0, v35) )
  {
    v7 = v35[0];
    if ( v35[0] )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v9 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v9 = "soft_irq";
      }
      else
      {
        v9 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v9,
        "cnss_pci_init_smmu",
        7u,
        7u,
        "Initializing SMMU\n",
        v4,
        v5,
        (char)s2);
      *(_QWORD *)(a1 + 264) = iommu_get_domain_for_dev(v3 + 200);
      if ( !(unsigned int)of_property_read_string(v7, "qcom,iommu-dma", &s2) && !strcmp("fastmap", s2) )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v12 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v12 = "soft_irq";
        }
        else
        {
          v12 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v12,
          "cnss_pci_init_smmu",
          7u,
          7u,
          "Enabling SMMU S1 stage\n",
          v10,
          v11,
          (char)s2);
        v13 = *(_QWORD *)(a1 + 264);
        *(_BYTE *)(a1 + 272) = 1;
        iommu_set_fault_handler(v13, cnss_pci_smmu_fault_handler, a1);
        cnss_register_iommu_fault_handler_irq();
      }
      iommu_addr = cnss_pci_get_iommu_addr((__int64 *)a1);
      v16 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
      if ( iommu_addr )
      {
        v6 = iommu_addr;
        if ( v16 )
        {
          v17 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v17 = "soft_irq";
        }
        else
        {
          v17 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v17,
          "cnss_pci_init_smmu",
          3u,
          3u,
          "Invalid SMMU size window, err = %d\n",
          iommu_addr,
          v15,
          (char)s2);
      }
      else
      {
        if ( v16 )
        {
          v18 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v18 = "soft_irq";
        }
        else
        {
          v18 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v18,
          "cnss_pci_init_smmu",
          7u,
          7u,
          "smmu_iova_start: %pa, smmu_iova_len: 0x%zx\n",
          a1 + 280,
          *(_QWORD *)(a1 + 288),
          (char)s2);
        resource_byname = (__int64 *)platform_get_resource_byname(*v2, 512, "smmu_iova_ipa");
        if ( resource_byname )
        {
          v20 = *resource_byname;
          *(_QWORD *)(a1 + 296) = *resource_byname;
          *(_QWORD *)(a1 + 304) = v20;
          v22 = *resource_byname;
          v21 = resource_byname[1];
          v23 = cnss_ipc_log_context;
          v24 = v21 - v22 + 1;
          *(_QWORD *)(a1 + 312) = v24;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v25 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v25 = "soft_irq";
          }
          else
          {
            v25 = (const char *)(StatusReg + 2320);
          }
          cnss_debug_ipc_log_print(
            v23,
            v25,
            "cnss_pci_init_smmu",
            7u,
            7u,
            "smmu_iova_ipa_start: %pa, smmu_iova_ipa_len: 0x%zx\n",
            a1 + 296,
            v24,
            (char)s2);
        }
        property = of_find_property(v7, "qcom,iommu-geometry", 0);
        v28 = property == 0;
        v29 = property;
        v30 = cnss_ipc_log_context;
        v31 = !v28;
        *(_BYTE *)(a1 + 696) = v31;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v32 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v32 = "soft_irq";
        }
        else
        {
          v32 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          v30,
          v32,
          "cnss_pci_init_smmu",
          7u,
          7u,
          "iommu_geometry: %d\n",
          v29 != 0,
          v27,
          (char)s2);
        v6 = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
