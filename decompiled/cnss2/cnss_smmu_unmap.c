__int64 __fastcall cnss_smmu_unmap(__int64 a1, unsigned int a2, __int64 a3)
{
  _QWORD *v3; // x21
  __int64 v4; // x10
  __int64 v5; // x8
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v7; // x19
  bool v8; // cf
  int v9; // w10
  unsigned __int64 v10; // x20
  const char *v11; // x1
  const char *v13; // x1
  __int64 v14; // x0
  const char *v15; // x1
  char v16; // [xsp+0h] [xbp-10h]
  char v17; // [xsp+0h] [xbp-10h]

  v3 = *(_QWORD **)(a1 + 152);
  if ( !v3 )
    return 4294967277LL;
  v4 = v3[37];
  v5 = v3[39];
  StatusReg = _ReadStatusReg(SP_EL0);
  v7 = a2 & 0xFFFFF000;
  v8 = v7 >= v5 + v4;
  v9 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( v8 )
  {
    if ( v9 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_smmu_unmap",
      3u,
      3u,
      "Out of IOVA space to unmap, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n",
      v7,
      (__int64)(v3 + 37),
      v5);
    return 4294967284LL;
  }
  else
  {
    v10 = (a3 + a2 - v7 + 4095) & 0xFFFFFFFFFFFFF000LL;
    if ( v9 )
    {
      v11 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v11 = "soft_irq";
    }
    else
    {
      v11 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_smmu_unmap",
      7u,
      7u,
      "IOMMU unmap: iova %lx, len %zu\n",
      v7,
      v10,
      v16);
    v14 = iommu_unmap(v3[33], v7, v10);
    if ( v14 == v10 )
    {
      v3[38] = v7;
      return 0;
    }
    else
    {
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
        "cnss_smmu_unmap",
        3u,
        3u,
        "IOMMU unmap failed, unmapped = %zu, requested = %zu\n",
        v14,
        v10,
        v17);
      return 4294967274LL;
    }
  }
}
