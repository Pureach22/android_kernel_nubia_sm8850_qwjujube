__int64 __fastcall msm_msi_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 result; // x0
  const char *v6; // x1
  __int64 v7; // x0
  const char *v8; // x1
  __int64 v9; // x0
  __int64 v10; // x22
  __int64 v11; // x9
  __int64 v12; // x0
  int v13; // w8
  __int64 property; // x0
  __int64 v15; // x8
  const char *v16; // x2
  __int64 v17; // x0
  __int64 i; // x1
  int v19; // w8
  __int64 v20; // x0
  _QWORD *resource_byname; // x0
  __int64 v22; // x2
  __int64 v23; // x8
  int v24; // w9
  __int64 (__fastcall *v25)(); // x20
  __int64 (__fastcall *v26)(); // x10
  __int64 (__fastcall *v27)(); // x11
  unsigned __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x8
  unsigned int v33; // w0
  unsigned int v34; // w8
  __int64 v35; // x0
  unsigned int v36; // w19
  unsigned int v37; // [xsp+4h] [xbp-10Ch] BYREF
  _QWORD v38[12]; // [xsp+8h] [xbp-108h] BYREF
  _QWORD v39[10]; // [xsp+68h] [xbp-A8h] BYREF
  _QWORD v40[11]; // [xsp+B8h] [xbp-58h] BYREF

  v40[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 744);
  memset(v38, 0, sizeof(v38));
  memset(v39, 0, sizeof(v39));
  v37 = 0;
  if ( !v2 )
  {
    v6 = "MSI: missing DT node\n";
    v7 = a1;
LABEL_18:
    dev_err(v7, v6);
    result = 4294967274LL;
    goto LABEL_19;
  }
  memset(v40, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v2, "msi-parent", 0, 0, 0, v40) || (v3 = v40[0]) == 0 )
  {
    v8 = "MSI: no phandle for MSI found\n";
LABEL_12:
    v9 = a1;
    goto LABEL_13;
  }
  if ( !(unsigned int)of_device_is_compatible(v40[0], "qcom,pci-msi") )
  {
    v8 = "MSI: no compatible qcom,pci-msi found\n";
    goto LABEL_12;
  }
  if ( !of_find_property(v3, "msi-controller", 0) )
  {
    result = 4294967277LL;
    goto LABEL_19;
  }
  v4 = _kmalloc_cache_noprof(dev_err, 3520, 176);
  if ( v4 )
  {
    *(_QWORD *)(v4 + 16) = a1;
    *(_QWORD *)(v4 + 24) = v3;
    v10 = v4;
    _mutex_init(v4 + 64, "&msi->mutex", &msm_msi_init___key);
    *(_DWORD *)(v10 + 144) = 0;
    *(_QWORD *)v10 = v10;
    *(_QWORD *)(v10 + 8) = v10;
    if ( (unsigned int)of_address_to_resource(*(_QWORD *)(v10 + 24), 0, v38) )
    {
      v7 = *(_QWORD *)(v10 + 16);
      v6 = "MSI: missing 'reg' devicetree\n";
      goto LABEL_18;
    }
    v11 = v38[0];
    *(_QWORD *)(v10 + 128) = v38[0];
    if ( !v11 )
    {
      v7 = *(_QWORD *)(v10 + 16);
      v6 = "MSI: failed to get MSI address\n";
      goto LABEL_18;
    }
    of_property_read_variable_u32_array(v3, "qcom,msi-addr-size-exp", &v37, 1, 0);
    v12 = *(_QWORD *)(v10 + 24);
    if ( v37 <= 0xC )
      v13 = 12;
    else
      v13 = v37;
    v37 = v13;
    *(_DWORD *)(v10 + 136) = 1 << v13;
    property = of_find_property(v12, "qcom,snps", 0);
    v15 = *(_QWORD *)(v10 + 16);
    *(_DWORD *)(v10 + 140) = property != 0;
    if ( property )
      v16 = "synopsys";
    else
      v16 = "qgic";
    dev_info(v15, "MSI: %s controller is present\n", v16);
    v17 = *(_QWORD *)(v10 + 24);
    for ( i = *(unsigned int *)(v10 + 32); !(unsigned int)of_irq_parse_one(v17, i, v39); *(_DWORD *)(v10 + 32) = i )
    {
      v17 = *(_QWORD *)(v10 + 24);
      i = (unsigned int)(*(_DWORD *)(v10 + 32) + 1);
    }
    v19 = *(_DWORD *)(v10 + 32);
    v20 = v10;
    if ( v19 )
    {
      if ( *(_DWORD *)(v10 + 140) != 1 )
      {
        v25 = msm_msi_qgic_irq_setup;
        v26 = msm_msi_qgic_unmask_irq;
        v27 = msm_msi_qgic_mask_irq;
        v24 = 1;
        goto LABEL_38;
      }
      resource_byname = (_QWORD *)platform_get_resource_byname(a1 - 16, 512, "dm_core");
      if ( resource_byname )
      {
        if ( arm64_use_ng_mappings )
          v22 = 0x68000000000F13LL;
        else
          v22 = 0x68000000000713LL;
        v23 = ioremap_prot(*resource_byname, resource_byname[1] - *resource_byname + 1LL, v22);
        v20 = v10;
        *(_QWORD *)(v10 + 152) = v23;
        if ( !v23 )
        {
          v36 = -12;
LABEL_52:
          kfree(v20);
          result = v36;
          goto LABEL_19;
        }
        v24 = *(_DWORD *)(v10 + 32);
        v25 = (__int64 (__fastcall *)())msm_msi_snps_irq_setup;
        v26 = msm_msi_snps_unmask_irq;
        v27 = msm_msi_snps_mask_irq;
        v19 = 32 * v24;
LABEL_38:
        *(_DWORD *)(v20 + 36) = v19;
        *(_DWORD *)(v20 + 40) = v24;
        *(_QWORD *)(v20 + 160) = v27;
        *(_QWORD *)(v20 + 168) = v26;
        v28 = *(int *)(v20 + 40);
        if ( is_mul_ok(v28, 0x420u) )
        {
          v29 = _kmalloc_noprof(1056 * v28, 3520);
          v30 = v10;
          *(_QWORD *)(v10 + 48) = v29;
          if ( v29 )
          {
            v31 = _kmalloc_noprof(((unsigned __int64)(*(int *)(v10 + 36) + 63LL) >> 3) & 0x1FFFFFFFFFFFFFF8LL, 3520);
            v32 = v10;
            *(_QWORD *)(v10 + 56) = v31;
            if ( v31 )
            {
              v33 = msm_msi_alloc_domains(v10);
              if ( v33 )
              {
                v36 = v33;
                dev_err(*(_QWORD *)(v10 + 16), "MSI: failed to allocate MSI domains\n");
              }
              else
              {
                if ( *((_DWORD *)v25 - 1) != -141017268 )
                  __break(0x8234u);
                v34 = ((__int64 (__fastcall *)(__int64))v25)(v10);
                v35 = *(_QWORD *)(v10 + 120);
                if ( !v34 )
                {
                  msm_msi_config(v35);
                  result = 0;
                  goto LABEL_19;
                }
                v36 = v34;
                irq_domain_remove(v35);
                irq_domain_remove(*(_QWORD *)(v10 + 112));
              }
              kfree(*(_QWORD *)(v10 + 56));
              v32 = v10;
            }
            else
            {
              v36 = -12;
            }
            kfree(*(_QWORD *)(v32 + 48));
            v30 = v10;
          }
          else
          {
            v36 = -12;
          }
        }
        else
        {
          v30 = v10;
          *(_QWORD *)(v10 + 48) = 0;
          v36 = -12;
        }
        iounmap(*(_QWORD *)(v30 + 152));
        v20 = v10;
        goto LABEL_52;
      }
      v9 = *(_QWORD *)(v10 + 16);
      v8 = "MSI: failed to get PCIe register base\n";
    }
    else
    {
      v9 = *(_QWORD *)(v10 + 16);
      v8 = "MSI: found no MSI interrupts\n";
    }
LABEL_13:
    dev_err(v9, v8);
    result = 4294967277LL;
    goto LABEL_19;
  }
  result = 4294967284LL;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
