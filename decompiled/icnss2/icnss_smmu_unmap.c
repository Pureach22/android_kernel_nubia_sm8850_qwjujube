__int64 __fastcall icnss_smmu_unmap(_QWORD *a1, unsigned int a2, __int64 a3)
{
  _QWORD *v3; // x21
  __int64 v4; // x4
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x20
  __int64 v7; // x0
  __int64 result; // x0
  const char *v10; // x19
  __int64 v11; // x20
  __int64 v12; // x0

  v3 = (_QWORD *)a1[19];
  if ( !v3 )
  {
    printk("%sicnss2: Invalid drvdata: dev %pK, data %pK\n", byte_130B32, a1, nullptr);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Invalid drvdata: dev %pK, data %pK\n",
      (const char *)&unk_12DBF3,
      a1,
      nullptr);
    return 4294967274LL;
  }
  if ( !a2 )
  {
    v10 = "%sicnss2: iova_addr is NULL, size %zu\n";
    v11 = a3;
    printk("%sicnss2: iova_addr is NULL, size %zu\n", byte_130B32, a3);
    v12 = icnss_ipc_log_context;
LABEL_11:
    ipc_log_string(v12, v10, &unk_12DBF3, v11);
    return 4294967274LL;
  }
  v4 = v3[77];
  v5 = a2 & 0xFFFFF000;
  if ( v5 >= v4 + v3[75] )
  {
    printk(
      "%sicnss2: Out of IOVA space during unmap, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n",
      byte_130B32,
      v5,
      v3 + 75,
      v4);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Out of IOVA space during unmap, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n",
      (const char *)&unk_12DBF3,
      v5,
      v3 + 75,
      v3[77]);
    return 4294967284LL;
  }
  v6 = (a3 + a2 - v5 + 4095) & 0xFFFFFFFFFFFFF000LL;
  ipc_log_string(icnss_ipc_log_context, "icnss2: IOMMU Unmap: iova %lx, len %zu\n", v5, v6);
  v7 = iommu_unmap(v3[72], v5, v6);
  if ( v7 != v6 )
  {
    v10 = "%sicnss2: Failed to unmap, %zu\n";
    v11 = v7;
    printk("%sicnss2: Failed to unmap, %zu\n", byte_130B32, v7);
    v12 = icnss_ipc_log_context;
    goto LABEL_11;
  }
  result = 0;
  v3[76] = v5;
  return result;
}
