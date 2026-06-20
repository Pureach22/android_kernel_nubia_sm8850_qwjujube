__int64 __fastcall cnss_pci_remove(__int64 a1, __int64 a2)
{
  __int64 v3; // x23
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  __int64 v11; // x19
  _QWORD *v12; // x20
  __int64 v13; // x6
  __int64 *v14; // x19
  __int64 v15; // x8
  unsigned __int64 StatusReg; // x9
  const char *v17; // x1
  __int16 v18; // w10
  const char *v19; // x9
  _QWORD *v20; // x20
  __int64 v21; // x6
  __int64 *v22; // x19
  __int64 v23; // x8
  unsigned __int64 v24; // x9
  const char *v25; // x1
  __int16 v26; // w10
  const char *v27; // x9
  __int64 *v28; // x22
  __int64 v29; // x6
  __int64 *v30; // x21
  __int64 v31; // x8
  unsigned __int64 v32; // x9
  const char *v33; // x1
  __int16 v34; // w10
  const char *v35; // x9
  __int64 v36; // x6
  __int64 *v37; // x19
  __int64 v38; // x8
  unsigned __int64 v39; // x9
  const char *v40; // x1
  __int16 v41; // w10
  const char *v42; // x9
  __int64 v43; // x6
  __int64 *v44; // x21
  __int64 v45; // x8
  unsigned __int64 v46; // x9
  const char *v47; // x1
  __int16 v48; // w10
  const char *v49; // x9
  _QWORD *v50; // x20
  __int64 v51; // x6
  __int64 *v52; // x19
  __int64 v53; // x8
  unsigned __int64 v54; // x9
  const char *v55; // x1
  __int16 v56; // w10
  const char *v57; // x9
  __int64 v58; // x25
  unsigned int v59; // w8
  unsigned int v60; // w26
  __int64 v61; // x21
  unsigned __int64 v62; // x19
  __int64 v63; // x20
  __int64 v64; // x6
  const char *v65; // x1
  char v66; // w0
  unsigned __int64 v67; // x10
  const char *v68; // x1
  __int16 v69; // w11
  const char *v70; // x10
  __int64 v71; // x21
  int v72; // w8
  __int64 v73; // x1
  __int64 v74; // x2
  __int64 v75; // x3
  __int64 v76; // x4
  __int64 v77; // x5
  __int64 v78; // x6
  __int64 v79; // x7
  __int64 result; // x0
  unsigned __int64 v81; // x8
  const char *v82; // x1
  __int16 v83; // w9
  const char *v84; // x8
  unsigned __int64 v91; // x10
  unsigned __int64 v94; // x9
  unsigned __int64 v97; // x10
  char v98; // [xsp+0h] [xbp-30h]
  __int64 v99; // [xsp+18h] [xbp-18h]
  _QWORD *v100; // [xsp+20h] [xbp-10h]

  v3 = *(_QWORD *)(a1 + 352);
  v100 = (_QWORD *)cnss_bus_dev_to_plat_priv(a1 + 200, a2);
  v99 = a1;
  _X8 = v100 + 69;
  __asm { PRFM            #0x11, [X8] }
  do
    v91 = __ldxr(_X8);
  while ( __stxr(v91 & 0xFFFFFFFFFFBFFFFFLL, _X8) );
  if ( v3 )
  {
    v11 = *(_QWORD *)(v3 + 8);
    _X8 = (unsigned __int64 *)(v11 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v94 = __ldxr(_X8);
    while ( __stxr(v94 | 0x20, _X8) );
    cnss_pci_dev_shutdown(v3, v4, v5, v6, v7, v8, v9, v10);
    *(_QWORD *)(v3 + 40) = 0;
    _X8 = (unsigned __int64 *)(v11 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v97 = __ldxr(_X8);
    while ( __stxr(v97 & 0xFFFFFFFFFBFFFFFFLL, _X8) );
  }
  v12 = *(_QWORD **)(v3 + 8);
  v13 = v12[508];
  v14 = v12 + 507;
  if ( v13 )
  {
    v15 = *v14;
    if ( *v14 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v17 = "irq";
      }
      else
      {
        v18 = *(_DWORD *)(StatusReg + 16);
        v19 = (const char *)(StatusReg + 2320);
        if ( (v18 & 0xFF00) != 0 )
          v17 = "soft_irq";
        else
          v17 = v19;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v17,
        "cnss_pci_free_aux_mem",
        7u,
        7u,
        "Freeing memory for AUX, va: 0x%pK, pa: %pa, size: 0x%zx\n",
        v13,
        (__int64)(v12 + 509),
        v15);
      dma_free_attrs(*(_QWORD *)v3 + 200LL, v12[507], v12[508], v12[509], 0);
    }
  }
  v12[508] = 0;
  v12[509] = 0;
  *v14 = 0;
  v20 = *(_QWORD **)(v3 + 8);
  v21 = v20[487];
  v22 = v20 + 486;
  if ( v21 )
  {
    v23 = *v22;
    if ( *v22 )
    {
      v24 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
      {
        v25 = "irq";
      }
      else
      {
        v26 = *(_DWORD *)(v24 + 16);
        v27 = (const char *)(v24 + 2320);
        if ( (v26 & 0xFF00) != 0 )
          v25 = "soft_irq";
        else
          v25 = v27;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v25,
        "cnss_pci_free_tme_lite_mem",
        7u,
        7u,
        "Freeing memory for TME patch, va: 0x%pK, pa: %pa, size: 0x%zx\n",
        v21,
        (__int64)(v20 + 488),
        v23);
      dma_free_attrs(*(_QWORD *)v3 + 200LL, v20[486], v20[487], v20[488], 0);
    }
  }
  v20[487] = 0;
  v20[488] = 0;
  *v22 = 0;
  v28 = *(__int64 **)(v3 + 8);
  v29 = v28[492];
  v30 = v28 + 491;
  if ( v29 )
  {
    v31 = *v30;
    if ( *v30 )
    {
      v32 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v32 + 16) & 0xF0000) != 0 )
      {
        v33 = "irq";
      }
      else
      {
        v34 = *(_DWORD *)(v32 + 16);
        v35 = (const char *)(v32 + 2320);
        if ( (v34 & 0xFF00) != 0 )
          v33 = "soft_irq";
        else
          v33 = v35;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v33,
        "cnss_pci_free_tme_opt_file_mem",
        7u,
        7u,
        "Free memory for TME opt file,va:0x%pK, pa:%pa, size:0x%zx\n",
        v29,
        (__int64)(v28 + 493),
        v31);
      dma_free_attrs(*(_QWORD *)v3 + 200LL, v28[491], v28[492], v28[493], 0);
    }
  }
  v36 = v28[497];
  v37 = v28 + 496;
  v28[492] = 0;
  v28[493] = 0;
  *v30 = 0;
  if ( v36 )
  {
    v38 = *v37;
    if ( *v37 )
    {
      v39 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v39 + 16) & 0xF0000) != 0 )
      {
        v40 = "irq";
      }
      else
      {
        v41 = *(_DWORD *)(v39 + 16);
        v42 = (const char *)(v39 + 2320);
        if ( (v41 & 0xFF00) != 0 )
          v40 = "soft_irq";
        else
          v40 = v42;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v40,
        "cnss_pci_free_tme_opt_file_mem",
        7u,
        7u,
        "Free memory for TME opt file,va:0x%pK, pa:%pa, size:0x%zx\n",
        v36,
        (__int64)(v28 + 498),
        v38);
      dma_free_attrs(*(_QWORD *)v3 + 200LL, v28[496], v28[497], v28[498], 0);
    }
  }
  v43 = v28[502];
  v44 = v28 + 501;
  v28[497] = 0;
  v28[498] = 0;
  *v37 = 0;
  if ( v43 )
  {
    v45 = *v44;
    if ( *v44 )
    {
      v46 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v46 + 16) & 0xF0000) != 0 )
      {
        v47 = "irq";
      }
      else
      {
        v48 = *(_DWORD *)(v46 + 16);
        v49 = (const char *)(v46 + 2320);
        if ( (v48 & 0xFF00) != 0 )
          v47 = "soft_irq";
        else
          v47 = v49;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v47,
        "cnss_pci_free_tme_opt_file_mem",
        7u,
        7u,
        "Free memory for TME opt file,va:0x%pK, pa:%pa, size:0x%zx\n",
        v43,
        (__int64)(v28 + 503),
        v45);
      dma_free_attrs(*(_QWORD *)v3 + 200LL, v28[501], v28[502], v28[503], 0);
    }
  }
  v28[502] = 0;
  v28[503] = 0;
  *v44 = 0;
  v50 = *(_QWORD **)(v3 + 8);
  v51 = v50[477];
  v52 = v50 + 476;
  if ( v51 )
  {
    v53 = *v52;
    if ( *v52 )
    {
      v54 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v54 + 16) & 0xF0000) != 0 )
      {
        v55 = "irq";
      }
      else
      {
        v56 = *(_DWORD *)(v54 + 16);
        v57 = (const char *)(v54 + 2320);
        if ( (v56 & 0xFF00) != 0 )
          v55 = "soft_irq";
        else
          v55 = v57;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v55,
        "cnss_pci_free_m3_mem",
        7u,
        7u,
        "Freeing memory for M3, va: 0x%pK, pa: %pa, size: 0x%zx\n",
        v51,
        (__int64)(v50 + 478),
        v53);
      dma_free_attrs(*(_QWORD *)v3 + 200LL, v50[476], v50[477], v50[478], 0);
    }
  }
  v50[477] = 0;
  v50[478] = 0;
  *v52 = 0;
  v58 = *(_QWORD *)(v3 + 8);
  v59 = *(_DWORD *)(v58 + 1720);
  if ( v59 )
  {
    v60 = 0;
    v61 = *(_QWORD *)v3;
    v62 = _ReadStatusReg(SP_EL0);
    do
    {
      v63 = v58 + 1728 + 40LL * (int)v60;
      v64 = *(_QWORD *)(v63 + 8);
      if ( v64 && *(_QWORD *)v63 )
      {
        v65 = "irq";
        if ( (*(_DWORD *)(v62 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v62 + 16) & 0xFF00) != 0 )
            v65 = "soft_irq";
          else
            v65 = (const char *)(v62 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v65,
          "cnss_pci_free_fw_mem",
          7u,
          7u,
          "Freeing memory for FW, va: 0x%pK, pa: %pa, size: 0x%zx, type: %u\n",
          v64,
          v63 + 16,
          *(_QWORD *)v63);
        dma_free_attrs(v61 + 200, *(_QWORD *)v63, *(_QWORD *)(v63 + 8), *(_QWORD *)(v63 + 16), *(_QWORD *)(v63 + 32));
        *(_QWORD *)v63 = 0;
        *(_QWORD *)(v63 + 8) = 0;
        *(_QWORD *)(v63 + 16) = 0;
        v59 = *(_DWORD *)(v58 + 1720);
        *(_DWORD *)(v63 + 28) = 0;
      }
      ++v60;
    }
    while ( v60 < v59 );
  }
  *(_DWORD *)(v58 + 1720) = 0;
  cnss_pci_free_qdss_mem(v3);
  if ( (unsigned int)*(unsigned __int16 *)(v99 + 62) - 4352 <= 0x12 && ((1 << *(_WORD *)(v99 + 62)) & 0x6448F) != 0 )
  {
    timer_delete((timer_t)(v3 + 448));
    v66 = timer_delete((timer_t)(v3 + 400));
    v67 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v67 + 16) & 0xF0000) != 0 )
    {
      v68 = "irq";
    }
    else
    {
      v69 = *(_DWORD *)(v67 + 16);
      v70 = (const char *)(v67 + 2320);
      if ( (v69 & 0xFF00) != 0 )
        v68 = "soft_irq";
      else
        v68 = v70;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v68,
      "__cnss_del_rddm_timer",
      7u,
      7u,
      "Delete RDDM timer @%s(%d), ret %d\n",
      (__int64)"cnss_pci_remove",
      8863,
      v66);
  }
  if ( *(_DWORD *)(v3 + 24) != 62 )
  {
    v71 = *(_QWORD *)(v3 + 344);
    mhi_unregister_controller(v71);
    kfree(*(_QWORD *)(v71 + 200));
    *(_QWORD *)(v71 + 200) = 0;
    mhi_free_controller(v71);
    v72 = *(_DWORD *)(v3 + 24);
    *(_QWORD *)(v3 + 344) = 0;
    if ( v72 != 62 )
      pci_free_irq_vectors(*(_QWORD *)v3);
  }
  cnss_pci_disable_bus(v3);
  cnss_dereg_pci_event(v3);
  *(_QWORD *)(v3 + 264) = 0;
  if ( v100 )
  {
    cnss_unregister_ramdump(v100, v73, v74, v75, v76, v77, v78, v79);
    result = cnss_unregister_subsys((__int64)v100);
    v100[1] = 0;
  }
  else
  {
    v81 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v81 + 16) & 0xF0000) != 0 )
    {
      v82 = "irq";
    }
    else
    {
      v83 = *(_DWORD *)(v81 + 16);
      v84 = (const char *)(v81 + 2320);
      if ( (v83 & 0xFF00) != 0 )
        v82 = "soft_irq";
      else
        v82 = v84;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v82,
             "cnss_pci_remove",
             3u,
             3u,
             "Plat_priv is null, Unable to unregister ramdump,subsys\n",
             v78,
             v79,
             v98);
  }
  return result;
}
