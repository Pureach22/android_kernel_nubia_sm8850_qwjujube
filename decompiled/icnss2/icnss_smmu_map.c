__int64 __fastcall icnss_smmu_map(_QWORD *a1, __int64 a2, int *a3, __int64 a4)
{
  _QWORD *v5; // x24
  __int16 v8; // w23
  unsigned __int64 v9; // x19
  __int64 v10; // x4
  unsigned __int64 v11; // x21
  const char *v12; // x2
  int v13; // w25
  int v14; // w0
  int v15; // w2
  __int64 result; // x0
  unsigned int v17; // w19
  int v18; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = (_QWORD *)a1[19];
  v19[0] = a2;
  v18 = 0;
  if ( !v5 )
  {
    printk("%sicnss2: Invalid drvdata: dev %pK, data %pK\n", byte_130B32, a1, nullptr);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid drvdata: dev %pK, data %pK\n", &unk_12DBF3, a1, 0);
LABEL_13:
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( !a3 )
  {
    printk("%sicnss2: iova_addr is NULL, paddr %pa, size %zu\n", byte_130B32, v19, a4);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: iova_addr is NULL, paddr %pa, size %zu\n", &unk_12DBF3, v19, a4);
    goto LABEL_13;
  }
  v8 = a2;
  v9 = (v5[76] + 4095LL) & 0xFFFFFFFFFFFFF000LL;
  if ( of_get_property(a1[93], "qcom,iommu-geometry", &v18) && (v10 = v5[77], v9 >= v10 + v5[75]) )
  {
    printk(
      "%sicnss2: No IOVA space to map, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n",
      byte_130B32,
      v9,
      v5 + 75,
      v10);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: No IOVA space to map, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n",
      (const char *)&unk_12DBF3,
      v9,
      v5 + 75,
      v5[77]);
    result = 4294967284LL;
  }
  else
  {
    v11 = ((v8 & 0xFFF) + a4 + 4095) & 0xFFFFFFFFFFFFF000LL;
    if ( of_find_property(a1[93], "dma-coherent", 0) )
      v12 = "enabled";
    else
      v12 = "disabled";
    ipc_log_string(icnss_ipc_log_context, "icnss2: dma-coherent is %s\n", v12);
    ipc_log_string(icnss_ipc_log_context, "icnss2: IOMMU Map: iova %lx, len %zu\n", v9, v11);
    v13 = v19[0];
    v14 = iommu_map(v5[72], v9);
    if ( v14 )
    {
      v17 = v14;
      printk("%sicnss2: PA to IOVA mapping failed, ret %d\n", byte_130B32, v14);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: PA to IOVA mapping failed, ret %d\n",
        (const char *)&unk_12DBF3,
        v17);
      result = v17;
    }
    else
    {
      v15 = v13 + v9 - (v13 & 0xFFFFF000);
      v5[76] = v9 + v11;
      *a3 = v15;
      ipc_log_string(icnss_ipc_log_context, "icnss2: IOVA addr mapped to physical addr %x\n", v15);
      result = 0;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
