__int64 __fastcall cnss_register_ramdump(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x6
  bool v10; // zf
  __int64 *v11; // x8
  __int64 v12; // x0
  __int64 v13; // x7
  unsigned __int64 StatusReg; // x21
  const char *v15; // x1
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x10
  unsigned __int64 v19; // x12
  __int64 v20; // x11
  __int64 v21; // x13
  __int64 v22; // x14
  __int64 v23; // x8
  __int64 v24; // x8
  unsigned int v25; // w0
  __int64 v26; // x6
  __int64 v27; // x7
  unsigned int v28; // w20
  const char *v29; // x1
  __int64 v30; // x21
  __int64 *v31; // x8
  __int64 v32; // x0
  int v33; // w20
  __int64 v34; // x0
  unsigned __int64 v35; // x22
  const char *v36; // x1
  unsigned __int64 v37; // x8
  const char *v38; // x1
  const char *v39; // x1
  __int64 v40; // x6
  __int64 v41; // x7
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 v44; // x9
  unsigned __int64 v45; // x12
  __int64 v46; // x8
  __int64 v47; // x9
  unsigned int v48; // w0
  __int64 v49; // x6
  __int64 v50; // x7
  const char *v51; // x1
  __int16 v52; // w9
  const char *v53; // x8
  const char *v54; // x1
  const char *v55; // x1
  char v57; // [xsp+0h] [xbp-40h]
  char v58; // [xsp+0h] [xbp-40h]
  char v59; // [xsp+0h] [xbp-40h]
  unsigned int v60; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v61; // [xsp+8h] [xbp-38h] BYREF
  __int64 v62; // [xsp+10h] [xbp-30h]
  __int64 v63; // [xsp+18h] [xbp-28h]
  __int64 v64; // [xsp+20h] [xbp-20h]
  __int64 v65; // [xsp+28h] [xbp-18h]
  __int64 v66; // [xsp+30h] [xbp-10h]
  __int64 v67; // [xsp+38h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[66];
  v10 = (unsigned __int64)(v9 - 4352) > 0x12 || ((1LL << v9) & 0x6448F) == 0;
  if ( !v10 )
  {
    v11 = (__int64 *)(*a1 + 760);
    if ( *((_DWORD *)a1 + 1934) == 2 )
      v11 = a1 + 972;
    v12 = *v11;
    v65 = 0;
    v66 = 0;
    v63 = 0;
    v64 = 0;
    v61 = 0;
    v62 = 0;
    v60 = 0;
    if ( (of_property_read_variable_u32_array(v12, "qcom,wlan-ramdump-dynamic", &v60, 1, 0) & 0x80000000) == 0 )
      a1[33] = v60;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v15 = "soft_irq";
    }
    else
    {
      v15 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_register_ramdump_v2",
      7u,
      7u,
      "Ramdump size 0x%lx\n",
      a1[33],
      v13,
      v57);
    v16 = _kmalloc_cache_noprof(iommu_get_domain_for_dev, 3520, 4096);
    a1[34] = v16;
    if ( !v16 )
    {
      v28 = -12;
      goto LABEL_80;
    }
    v17 = v16 << 8 >> 8;
    *((_DWORD *)a1 + 85) = 1;
    v18 = memstart_addr;
    v19 = (unsigned __int64)(v17 + 0x8000000000LL) >> 38;
    v20 = kimage_voffset;
    *((_WORD *)a1 + 152) = 78;
    v21 = v18 + v17 + 0x8000000000LL;
    v22 = (__int64)((_QWORD)(a1 + 36) << 8) >> 8;
    v23 = v17 - v20;
    if ( !v19 )
      v23 = v21;
    a1[41] = v23;
    a1[36] = 0x4244595300000022LL;
    a1[37] = *(_QWORD *)"CNSS_WLAN";
    if ( (unsigned __int64)(v22 + 0x8000000000LL) >> 38 )
      v24 = v22 - v20;
    else
      v24 = v18 + v22 + 0x8000000000LL;
    LODWORD(v61) = 225;
    v66 = v24;
    v25 = msm_dump_data_register_nominidump(0, &v61);
    if ( v25 )
    {
      v28 = v25;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v29 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v29 = "soft_irq";
      }
      else
      {
        v29 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v29,
        "cnss_register_ramdump_v2",
        3u,
        3u,
        "Failed to setup dump table, %s (%d)\n",
        (__int64)"Error",
        v25,
        v58);
LABEL_38:
      kfree(a1[34]);
      a1[34] = 0;
      goto LABEL_80;
    }
    v10 = *a1 == -16;
    a1[32] = *a1 + 16;
    if ( v10 )
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v39 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v39 = "soft_irq";
      }
      else
      {
        v39 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v39,
        "cnss_register_ramdump_v2",
        3u,
        3u,
        "Failed to create ramdump device!\n",
        v26,
        v27,
        v58);
      v28 = -12;
      goto LABEL_38;
    }
    goto LABEL_24;
  }
  if ( v9 == 62 )
  {
    v30 = *a1;
    if ( *((_DWORD *)a1 + 1934) == 2 )
      v31 = a1 + 972;
    else
      v31 = (__int64 *)(*a1 + 760);
    v32 = *v31;
    v60 = 0;
    v33 = of_property_read_variable_u32_array(v32, "qcom,wlan-ramdump-dynamic", &v60, 1, 0);
    if ( (v33 & 0x80000000) == 0 )
    {
      v34 = dma_alloc_attrs(v30 + 16, v60, a1 + 23, 3264, 0);
      a1[22] = v34;
      if ( v34 )
        a1[21] = v60;
    }
    v35 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v35 + 16) & 0xF0000) != 0 )
    {
      v36 = "irq";
    }
    else if ( (*(_DWORD *)(v35 + 16) & 0xFF00) != 0 )
    {
      v36 = "soft_irq";
    }
    else
    {
      v36 = (const char *)(v35 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v36,
      "cnss_register_ramdump_v1",
      7u,
      7u,
      "ramdump va: %pK, pa: %pa\n",
      a1[22],
      (__int64)(a1 + 23),
      v57);
    v42 = a1[21];
    if ( v42 )
    {
      v61 = 0;
      a1[24] = 0x4244595300000011LL;
      v43 = a1[23];
      strcpy((char *)a1 + 200, "CNSS_WLAN");
      a1[29] = v43;
      a1[30] = v42;
      v44 = (__int64)((_QWORD)(a1 + 24) << 8) >> 8;
      LODWORD(v61) = 225;
      v63 = 0;
      v64 = 0;
      v45 = (unsigned __int64)(v44 + 0x8000000000LL) >> 38;
      v46 = memstart_addr + v44 + 0x8000000000LL;
      v62 = 0;
      v47 = v44 - kimage_voffset;
      if ( v45 )
        v46 = v47;
      v65 = 0;
      v66 = v46;
      v48 = msm_dump_data_register_nominidump(0, &v61);
      if ( v48 )
      {
        v28 = v48;
        if ( (*(_DWORD *)(v35 + 16) & 0xF0000) != 0 )
        {
          v51 = "irq";
        }
        else if ( (*(_DWORD *)(v35 + 16) & 0xFF00) != 0 )
        {
          v51 = "soft_irq";
        }
        else
        {
          v51 = (const char *)(v35 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v51,
          "cnss_register_ramdump_v1",
          3u,
          3u,
          "Failed to setup dump table, err = %d\n",
          v48,
          v50,
          v59);
      }
      else
      {
        v10 = *a1 == -16;
        a1[20] = *a1 + 16;
        if ( !v10 )
        {
LABEL_24:
          v28 = 0;
          goto LABEL_80;
        }
        if ( (*(_DWORD *)(v35 + 16) & 0xF0000) != 0 )
        {
          v55 = "irq";
        }
        else if ( (*(_DWORD *)(v35 + 16) & 0xFF00) != 0 )
        {
          v55 = "soft_irq";
        }
        else
        {
          v55 = (const char *)(v35 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v55,
          "cnss_register_ramdump_v1",
          3u,
          3u,
          "Failed to create ramdump device!",
          v49,
          v50,
          v59);
        v28 = -12;
      }
      dma_free_attrs(v30 + 16, a1[21], a1[22], a1[23], 0);
      goto LABEL_80;
    }
    v28 = v33 & (v33 >> 31);
    if ( (*(_DWORD *)(v35 + 16) & 0xF0000) != 0 )
    {
      v54 = "irq";
    }
    else if ( (*(_DWORD *)(v35 + 16) & 0xFF00) != 0 )
    {
      v54 = "soft_irq";
    }
    else
    {
      v54 = (const char *)(v35 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v54,
      "cnss_register_ramdump_v1",
      6u,
      6u,
      "Ramdump will not be collected",
      v40,
      v41,
      v59);
  }
  else
  {
    v37 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v37 + 16) & 0xF0000) != 0 )
    {
      v38 = "irq";
    }
    else
    {
      v52 = *(_DWORD *)(v37 + 16);
      v53 = (const char *)(v37 + 2320);
      if ( (v52 & 0xFF00) != 0 )
        v38 = "soft_irq";
      else
        v38 = v53;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v38,
      "cnss_register_ramdump",
      3u,
      3u,
      "Unknown device ID: 0x%lx\n",
      v9,
      a8,
      v57);
    v28 = -19;
  }
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return v28;
}
