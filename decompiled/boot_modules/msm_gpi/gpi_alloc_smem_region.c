__int64 __fastcall gpi_alloc_smem_region(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x8
  unsigned __int64 v8; // x0
  __int64 v9; // x0
  unsigned __int64 v10; // x21
  __int64 v11; // x8
  const char **v12; // x20
  unsigned __int64 v13; // x21
  char v14; // w0
  __int64 v15; // x4
  __int64 v16; // x8
  unsigned int v17; // w19
  unsigned int v18; // w20
  char v19; // w22
  const char *v20; // x0
  const char *v21; // x2
  __int64 v22; // x0
  __int64 v23; // x0

  result = qcom_smem_alloc(0xFFFFFFFFLL, 673, 59392);
  if ( (result & 0x80000000) == 0 || (_DWORD)result == -17 )
  {
    v5 = qcom_smem_get(0xFFFFFFFFLL, 673, 0);
    v6 = *(_QWORD *)(a1 + 472);
    v7 = v5 + 25600;
    v8 = (v5 & 0xFFFFFFFFFFFFFC00LL) + 1024;
    *(_QWORD *)(a1 + 504) = v8;
    *(_QWORD *)(a1 + 512) = v7;
    if ( v6 && *(_DWORD *)(a1 + 480) )
    {
      v9 = qcom_smem_virt_to_phys();
      ipc_log_string(
        v6,
        "%s: %s:smem phy_addr 0x%llx virt_addr:%p\n",
        "gpi_alloc_smem_region",
        "gpi_alloc_smem_region",
        v9,
        *(const void **)(a1 + 504));
      v8 = *(_QWORD *)(a1 + 504);
    }
    v10 = v8 & 0xFFF;
    v11 = (vmalloc_to_page() << 6) + 0xFFFFD000000000LL;
    v12 = *(const char ***)(a1 + 392);
    v13 = (v11 & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + v10;
    v14 = is_vmalloc_addr(v13);
    if ( (v14 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v19 = v14;
      dma_map_single_attrs___already_done = 1;
      v20 = (const char *)dev_driver_string(v12);
      v21 = v12[14];
      if ( !v21 )
        v21 = *v12;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v20, v21);
      __break(0x800u);
      if ( (v19 & 1) != 0 )
        goto LABEL_14;
    }
    else if ( (v14 & 1) != 0 )
    {
LABEL_14:
      v15 = -1;
LABEL_27:
      v22 = *(_QWORD *)(a1 + 472);
      *(_QWORD *)(a1 + 520) = v15;
      if ( v22 && *(_DWORD *)(a1 + 480) )
      {
        ipc_log_string(v22, "%s: %s: smem_dma_iova:0x%llx\n", "gpi_alloc_smem_region", "gpi_alloc_smem_region", v15);
        v15 = *(_QWORD *)(a1 + 520);
      }
      if ( v15 != -1 )
        return 0;
      if ( *(_DWORD *)(a1 + 484) >= 2u )
      {
        dev_err(
          *(_QWORD *)(a1 + 392),
          "%s: %s: dma mapping failed smem_dma_iova:0x%llx ret:%d\n",
          "gpi_alloc_smem_region",
          "gpi_alloc_smem_region",
          -1,
          -12);
        v23 = *(_QWORD *)(a1 + 472);
        if ( v23 )
        {
LABEL_34:
          if ( *(_DWORD *)(a1 + 480) >= 2u )
            ipc_log_string(
              v23,
              "%s: %s: dma mapping failed smem_dma_iova:0x%llx ret:%d\n",
              "gpi_alloc_smem_region",
              "gpi_alloc_smem_region",
              *(_QWORD *)(a1 + 520),
              -12);
        }
      }
      else
      {
        v23 = *(_QWORD *)(a1 + 472);
        if ( v23 )
          goto LABEL_34;
      }
      return 4294967291LL;
    }
    v15 = dma_map_page_attrs(
            v12,
            ((unsigned __int64)(((__int64)(v13 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            v13 & 0xFFF,
            25600,
            0,
            0);
    goto LABEL_27;
  }
  v3 = *(_DWORD *)(a1 + 484);
  if ( (_DWORD)result == -517 )
  {
    if ( v3 >= 2 )
    {
      dev_err(*(_QWORD *)(a1 + 392), "%s: probe defer issue observed with smem ret:%d\n", "gpi_alloc_smem_region", -517);
      v4 = *(_QWORD *)(a1 + 472);
      if ( v4 )
      {
LABEL_6:
        if ( *(_DWORD *)(a1 + 480) >= 2u )
        {
          ipc_log_string(v4, "%s: probe defer issue observed with smem ret:%d\n", "gpi_alloc_smem_region", -517);
          return 4294966779LL;
        }
      }
    }
    else
    {
      v4 = *(_QWORD *)(a1 + 472);
      if ( v4 )
        goto LABEL_6;
    }
    return 4294966779LL;
  }
  if ( v3 >= 2 )
  {
    v18 = result;
    dev_err(
      *(_QWORD *)(a1 + 392),
      "%s: unable to allocate local smem for qup ret:%d\n",
      "gpi_alloc_smem_region",
      result);
    result = v18;
    v16 = *(_QWORD *)(a1 + 472);
    if ( !v16 )
      return result;
  }
  else
  {
    v16 = *(_QWORD *)(a1 + 472);
    if ( !v16 )
      return result;
  }
  if ( *(_DWORD *)(a1 + 480) >= 2u )
  {
    v17 = result;
    ipc_log_string(v16, "%s: unable to allocate local smem for qup ret:%d\n", "gpi_alloc_smem_region", result);
    return v17;
  }
  return result;
}
