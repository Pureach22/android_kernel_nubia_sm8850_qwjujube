__int64 __fastcall kgsl_iommu_bind(__int64 a1, __int64 a2)
{
  const void *v4; // x21
  _QWORD *resource; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 i; // x23
  char *v10; // x22
  unsigned __int64 v11; // x0
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned __int64 v14; // x0
  __int64 node_by_name; // x0
  __int64 v16; // x22
  unsigned int v17; // w24
  unsigned int v18; // w0
  _QWORD *v19; // x23
  __int64 v20; // x8
  __int64 v21; // x12
  __int64 v22; // x13
  __int64 v23; // x10
  __int64 v24; // x9
  __int64 v25; // x11
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 *v29; // x27
  __int64 v30; // x24
  __int64 (__fastcall *v31)(_QWORD); // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 *v34; // x25
  __int64 v35; // x9
  __int64 v36; // x10
  __int64 v37; // x11
  __int64 v38; // x8
  __int64 v39; // x12
  __int64 v40; // x8
  __int64 v41; // x10
  __int64 v42; // x11
  __int64 v43; // x8
  __int64 v44; // x10
  __int64 v45; // x11
  __int64 v46; // x0
  __int64 v47; // x24
  __int64 *v48; // x24
  _DWORD *v49; // x8
  __int64 v50; // x0
  __int64 *v51; // x22
  _DWORD *v52; // x8
  __int64 v53; // x0
  unsigned __int64 v60; // x9
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x22
  __int64 device_by_node; // x21
  __int64 v68; // x0
  int v69; // w0
  __int64 v70; // x0
  __int64 v71; // x1
  int v72; // w8
  __int64 v73; // x0
  _QWORD *v74; // x20
  _QWORD *v75; // x21
  unsigned __int64 v76; // x8
  __int64 global_fixed; // x0
  int v78; // w8
  int context_bank_nr; // w0
  unsigned __int64 v80; // x0
  unsigned __int64 v83; // x9
  unsigned __int64 v86; // x10
  _QWORD v87[4]; // [xsp+8h] [xbp-78h] BYREF
  _QWORD v88[11]; // [xsp+28h] [xbp-58h] BYREF

  v88[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(const void **)(a2 + 760);
  if ( !addr_entry_cache )
  {
    memset(&v87[1], 0, 24);
    v87[0] = 8;
    addr_entry_cache = _kmem_cache_create_args("kgsl_iommu_addr_entry", 40, v87, 0);
    if ( !addr_entry_cache )
      goto LABEL_34;
  }
  resource = (_QWORD *)platform_get_resource(a2, 512, 0);
  v6 = *(_QWORD *)(a1 + 11168);
  if ( !resource )
  {
    dev_err(v6 + 16, "%pOF: Unable to read KGSL IOMMU register range\n", v4);
    v17 = -19;
    goto LABEL_35;
  }
  v7 = devm_ioremap(v6 + 16, *resource, resource[1] - *resource + 1LL);
  *(_QWORD *)(a1 + 960) = v7;
  if ( !v7 )
  {
    dev_err(*(_QWORD *)(a1 + 11168) + 16LL, "Couldn't map IOMMU registers\n");
    goto LABEL_34;
  }
  *(_QWORD *)(a1 + 1008) = a2;
  *(_DWORD *)(a1 + 992) = 0;
  v8 = devm_kmalloc(a2 + 16, 192, 3520);
  *(_QWORD *)(a1 + 984) = v8;
  if ( !v8 )
  {
LABEL_34:
    v17 = -12;
    goto LABEL_35;
  }
  for ( i = 0; i != 12; ++i )
  {
    v10 = kgsl_iommu_clocks[i];
    v11 = devm_clk_get(*(_QWORD *)(a1 + 11168) + 16LL, v10);
    if ( v11 <= 0xFFFFFFFFFFFFF000LL )
    {
      *(_QWORD *)(*(_QWORD *)(a1 + 984) + 16LL * *(int *)(a1 + 992)) = v10;
      v12 = *(int *)(a1 + 992);
      v13 = *(_QWORD *)(a1 + 984) + 16 * v12;
      *(_DWORD *)(a1 + 992) = v12 + 1;
      *(_QWORD *)(v13 + 8) = v11;
    }
  }
  if ( of_find_property(*(_QWORD *)(a2 + 760), "power-domains", 0) )
  {
    pm_runtime_enable(a2 + 16);
  }
  else
  {
    v14 = devm_regulator_get(a2 + 16, "vddcx");
    if ( v14 <= 0xFFFFFFFFFFFFF000LL )
      *(_QWORD *)(a1 + 1032) = v14;
  }
  _X8 = (unsigned __int64 *)(a1 + 104);
  __asm { PRFM            #0x11, [X8] }
  do
    v60 = __ldxr(_X8);
  while ( __stxr(v60 | 2, _X8) );
  *(_DWORD *)(a1 + 64) = 0;
  *(_QWORD *)(a1 + 88) = kgsl_iommu_ops;
  node_by_name = of_find_node_by_name(v4, "gfx3d_user");
  if ( node_by_name )
  {
    memset(v88, 0, 80);
    if ( !(unsigned int)_of_parse_phandle_with_args(node_by_name, "iommus", 0, 0, 0, v88) )
    {
      v16 = v88[0];
      if ( v88[0] )
      {
        if ( (unsigned int)of_device_is_compatible(v88[0]) )
          *(_DWORD *)(a1 + 68) = 1;
        if ( (unsigned int)of_device_is_compatible(v16) )
        {
          _X8 = (unsigned __int64 *)(a1 + 104);
          __asm { PRFM            #0x11, [X8] }
          do
            v83 = __ldxr(_X8);
          while ( __stxr(v83 | 0x40, _X8) );
        }
      }
    }
  }
  v17 = kgsl_iommu_setup_context(a1 + 56, v4, a1 + 120, "gfx3d_user", kgsl_iommu_default_fault_handler);
  if ( v17 )
    goto LABEL_35;
  if ( !device_link_add(*(_QWORD *)(a1 + 11168) + 16LL, *(_QWORD *)(a1 + 120) + 16LL, 2) )
    dev_err(*(_QWORD *)(a1 + 120) + 16LL, "Unable to create device link to gpu device\n");
  v18 = kgsl_iommu_setup_context(a1 + 56, v4, a1 + 680, "gfx3d_lpac", kgsl_iommu_lpac_fault_handler);
  if ( (v18 & 0x80000000) != 0 )
  {
    v17 = v18;
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x40) != 0 )
      goto LABEL_86;
  }
  v19 = (_QWORD *)_kmalloc_cache_noprof(clk_set_rate, 3520, 360);
  if ( !v19 )
  {
    LODWORD(v19) = -12;
    *(_QWORD *)(a1 + 72) = -12;
    goto LABEL_85;
  }
  kgsl_mmu_pagetable_init(a1 + 56, (__int64)v19, 0);
  v19[15] = 0;
  v19[12] = &default_pt_ops;
  v19[13] = -1;
  v20 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 64LL) + *(_QWORD *)(a1 + 14256);
  if ( (*(_QWORD *)(a1 + 104) & 1) != 0 )
  {
    v19[20] = v20;
    if ( (*(_QWORD *)(a1 + 104) & 1) != 0 )
    {
      v25 = 0x8000000000LL;
      v21 = 16;
      v22 = 21;
      v20 = 0x4000000000LL;
      if ( (*(_QWORD *)(a1 + 104) & 0x40LL) != 0 )
        v23 = 4026527744LL;
      else
        v23 = 3932155904LL;
      v24 = 17;
    }
    else
    {
      v25 = 0x8000000000LL;
      v20 = 0x4000000000LL;
      v24 = 17;
      v21 = 16;
      v23 = 3204448256LL;
      v22 = 21;
    }
  }
  else
  {
    v19[16] = v20;
    v21 = 20;
    v22 = 17;
    if ( (*(_QWORD *)(a1 + 104) & 1LL) != 0 )
      v23 = 3932155904LL;
    else
      v23 = 4160749568LL;
    v24 = 21;
    v25 = v23;
  }
  v19[v22] = v23;
  v19[v21] = v20;
  v19[v24] = v25;
  if ( (*(_QWORD *)(a1 + 104) & 0x40) == 0 )
  {
    v27 = 4160749568LL;
    if ( (*(_QWORD *)(a1 + 104) & 1LL) != 0 )
      v27 = 3932155904LL;
    v19[23] = v27;
    goto LABEL_49;
  }
  v28 = *(_QWORD *)(a1 + 120);
  v19[23] = 0x1FF8000000000LL;
  v29 = *(__int64 **)(v28 + 168);
  v30 = *v29;
  if ( !*v29 )
    goto LABEL_56;
  v31 = (__int64 (__fastcall *)(_QWORD))v29[1];
  v32 = *v29;
  if ( *((_DWORD *)v31 - 1) != -249716041 )
    __break(0x8228u);
  v33 = v31(v32);
  if ( v33 )
  {
    v34 = (__int64 *)v33;
    memcpy(v19 + 26, v29 + 6, 0x98u);
    v35 = v34[4];
    v37 = v34[2];
    v36 = v34[3];
    v19[31] = v34[5];
    v38 = *v34;
    v39 = v34[1];
    v19[29] = v36;
    v19[30] = v35;
    v19[27] = v39;
    v19[28] = v37;
    v19[26] = v38;
    v40 = v34[9];
    v41 = v34[6];
    v42 = v34[7];
    v19[34] = v34[8];
    v19[35] = v40;
    v19[32] = v41;
    v19[33] = v42;
    v43 = v34[13];
    v44 = v34[10];
    v45 = v34[11];
    v19[38] = v34[12];
    v19[39] = v43;
    v19[36] = v44;
    v19[37] = v45;
    v19[27] = v39 & 0xFFFFFFFFFFFFFFDFLL;
    v19[31] = kgsl_iopgtbl_tlb_ops;
    v46 = qcom_alloc_io_pgtable_ops(4294967294LL, v19 + 26, v30);
    v19[25] = v46;
    if ( v46 )
    {
      v19[24] = v19[35];
LABEL_49:
      kgsl_mmu_pagetable_add(a1 + 56, (__int64)v19);
      goto LABEL_58;
    }
    v47 = -12;
  }
  else
  {
LABEL_56:
    v47 = -19;
  }
  kfree(v19);
  v19 = (_QWORD *)v47;
LABEL_58:
  *(_QWORD *)(a1 + 72) = v19;
  if ( (unsigned __int64)v19 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (*(_QWORD *)(a1 + 104) & 0x40) == 0 )
      goto LABEL_91;
    if ( *(_QWORD *)(a1 + 192) )
    {
      v48 = *(__int64 **)(*(_QWORD *)(a1 + 120) + 168LL);
      kgsl_iommu_enable_clk(a1 + 56);
      v49 = (_DWORD *)v48[2];
      v50 = *v48;
      if ( *(v49 - 1) != 985432076 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v49)(v50, v19 + 26);
      kgsl_iommu_disable_clk(a1 + 56);
    }
    if ( (*(_QWORD *)(a1 + 104) & 0x20) == 0 )
      goto LABEL_131;
    v17 = qcom_scm_kgsl_set_smmu_aperture(*(unsigned int *)(a1 + 136));
    if ( v17 == -16 )
      v17 = qcom_scm_kgsl_set_smmu_aperture(*(unsigned int *)(a1 + 136));
    if ( v17 )
    {
      dev_err(
        *(_QWORD *)(a1 + 11168) + 16LL,
        "Unable to set the SMMU aperture: %d. The aperture needs to be set to use per-process pagetables\n",
        v17);
    }
    else
    {
LABEL_131:
      if ( *(_QWORD *)(a1 + 752) )
      {
        v51 = *(__int64 **)(*(_QWORD *)(a1 + 680) + 168LL);
        kgsl_iommu_enable_clk(a1 + 56);
        v52 = (_DWORD *)v51[2];
        v53 = *v51;
        if ( *(v52 - 1) != 985432076 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD *))v52)(v53, v19 + 26);
        kgsl_iommu_disable_clk(a1 + 56);
      }
      if ( (*(_QWORD *)(a1 + 104) & 0x20) == 0 || (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x40) == 0 )
        goto LABEL_91;
      v17 = qcom_scm_kgsl_set_smmu_lpac_aperture(*(unsigned int *)(a1 + 696));
      if ( v17 == -16 )
        v17 = qcom_scm_kgsl_set_smmu_lpac_aperture(*(unsigned int *)(a1 + 696));
      if ( !v17
        || (dev_err(
              *(_QWORD *)(a1 + 11168) + 16LL,
              "Unable to set the LPAC SMMU aperture: %d. The aperture needs to be set to use per-process pagetables\n",
              v17),
            (v17 & 0x80000000) == 0) )
      {
LABEL_91:
        if ( *(_BYTE *)(a1 + 96) != 1 )
          goto LABEL_104;
        v65 = of_find_node_by_name(v4, "gfx3d_secure");
        if ( !v65 )
          goto LABEL_104;
        v66 = v65;
        device_by_node = of_find_device_by_node();
        if ( (unsigned int)of_dma_configure_id(device_by_node + 16, v66, 1, 0) )
          goto LABEL_104;
        *(_QWORD *)(a1 + 440) = 0;
        *(_QWORD *)(a1 + 448) = 0;
        *(_DWORD *)(a1 + 416) = -1;
        *(_DWORD *)(a1 + 444) = 1250;
        *(_QWORD *)(a1 + 424) = a1;
        *(_QWORD *)(a1 + 400) = device_by_node;
        *(_QWORD *)(a1 + 408) = "gfx3d_secure";
        *(_QWORD *)(a1 + 456) = 0;
        *(_QWORD *)(a1 + 464) = 0;
        *(_DWORD *)(a1 + 448) = 10;
        v68 = iommu_domain_alloc(&platform_bus_type);
        *(_QWORD *)(a1 + 472) = v68;
        if ( !v68 )
          goto LABEL_104;
        v69 = qcom_iommu_set_secure_vmid(v68, 10);
        if ( v69 )
        {
          dev_err(*(_QWORD *)(a1 + 11168) + 16LL, "Unable to set the secure VMID: %d\n", v69);
          v73 = *(_QWORD *)(a1 + 472);
          goto LABEL_103;
        }
        v70 = *(_QWORD *)(a1 + 472);
        if ( (*(_QWORD *)(a1 + 104) & 0x10) != 0 )
        {
          if ( *(_DWORD *)(a1 + 68) != 1 )
          {
            v71 = 64;
            goto LABEL_101;
          }
          if ( (*(_QWORD *)(a1 + 104) & 8) == 0 )
          {
            v71 = 0x80000000LL;
LABEL_101:
            iommu_set_pgtable_quirks(v70, v71);
            v70 = *(_QWORD *)(a1 + 472);
          }
        }
        v72 = iommu_attach_device(v70, *(_QWORD *)(a1 + 400) + 16LL);
        v73 = *(_QWORD *)(a1 + 472);
        if ( v72 )
        {
LABEL_103:
          iommu_domain_free(v73);
          *(_QWORD *)(a1 + 472) = 0;
          goto LABEL_104;
        }
        iommu_set_fault_handler(v73, kgsl_iommu_secure_fault_handler, a1 + 56);
        context_bank_nr = qcom_iommu_get_context_bank_nr(*(_QWORD *)(a1 + 472));
        *(_DWORD *)(a1 + 416) = context_bank_nr;
        if ( context_bank_nr < 0 )
        {
          iommu_detach_device(*(_QWORD *)(a1 + 472), *(_QWORD *)(a1 + 400) + 16LL);
          v73 = *(_QWORD *)(a1 + 472);
          goto LABEL_103;
        }
        v80 = kgsl_iommu_secure_pagetable(a1 + 56);
        *(_QWORD *)(a1 + 80) = v80;
        if ( v80 >= 0xFFFFFFFFFFFFF001LL )
          *(_BYTE *)(a1 + 96) = 0;
LABEL_104:
        v74 = *(_QWORD **)(a1 + 13112);
        v75 = (_QWORD *)(a1 + 13112);
        if ( v74 == (_QWORD *)(a1 + 13112) )
        {
LABEL_112:
          global_fixed = kgsl_allocate_global_fixed((_QWORD *)a1, "qcom,gpu-timer", (__int64)"gpu-qtimer");
          v78 = *(_DWORD *)(a1 + 68);
          *(_QWORD *)(a1 + 13144) = global_fixed;
          if ( v78 == 1 && (*(_QWORD *)(a1 + 104) & 0x80) != 0 )
          {
            kgsl_vbo_zero_page = _alloc_pages_noprof(69058, 0, 0, 0);
            if ( !kgsl_vbo_zero_page )
              goto LABEL_126;
          }
          else if ( !kgsl_vbo_zero_page )
          {
LABEL_126:
            _X8 = (unsigned __int64 *)(a1 + 104);
            __asm { PRFM            #0x11, [X8] }
            do
              v86 = __ldxr(_X8);
            while ( __stxr(v86 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
          }
          v17 = 0;
          *(_QWORD *)(a1 + 1504) = 0;
          goto LABEL_38;
        }
        while ( 1 )
        {
          while ( (*(_BYTE *)(v74 - 18) & 8) == 0 )
          {
            kgsl_iommu_default_map(*(_QWORD *)(a1 + 72), v74 - 27);
LABEL_107:
            v74 = (_QWORD *)*v74;
            if ( v74 == v75 )
              goto LABEL_112;
          }
          v76 = *(_QWORD *)(a1 + 80);
          if ( !v76 || v76 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_107;
          kgsl_iommu_map(*(_QWORD *)(v76 + 112), *(_QWORD *)(*(_QWORD *)(v76 + 112) + 416LL), v74 - 27);
          v74 = (_QWORD *)*v74;
          if ( v74 == v75 )
            goto LABEL_112;
        }
      }
    }
    goto LABEL_86;
  }
LABEL_85:
  v17 = (unsigned int)v19;
LABEL_86:
  kgsl_mmu_putpagetable(*(_QWORD **)(a1 + 72));
  v61 = *(_QWORD *)(a1 + 752);
  *(_QWORD *)(a1 + 72) = 0;
  if ( v61 )
  {
    iommu_detach_device(v61, *(_QWORD *)(a1 + 680) + 16LL);
    iommu_domain_free(*(_QWORD *)(a1 + 752));
    v62 = *(_QWORD *)(a1 + 680);
    *(_QWORD *)(a1 + 752) = 0;
    platform_device_put(v62);
    *(_QWORD *)(a1 + 680) = 0;
  }
  v63 = *(_QWORD *)(a1 + 192);
  if ( v63 )
  {
    iommu_detach_device(v63, *(_QWORD *)(a1 + 120) + 16LL);
    iommu_domain_free(*(_QWORD *)(a1 + 192));
    v64 = *(_QWORD *)(a1 + 120);
    *(_QWORD *)(a1 + 192) = 0;
    platform_device_put(v64);
    *(_QWORD *)(a1 + 120) = 0;
  }
  if ( !v17 )
    goto LABEL_91;
LABEL_35:
  if ( (*(_WORD *)(a2 + 504) & 7) == 0 )
    _pm_runtime_disable(a2 + 16, 1);
  kmem_cache_destroy(addr_entry_cache);
  addr_entry_cache = 0;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v17;
}
