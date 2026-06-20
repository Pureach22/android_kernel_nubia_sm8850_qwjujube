__int64 __fastcall cam_smmu_iommu_fault_handler(const void *a1, const void *a2, __int64 a3, int a4, char *s2)
{
  int v9; // w24
  __int64 v10; // x25
  int v11; // w19
  __int64 v12; // x28
  int v13; // w9
  __int64 v14; // x0
  __int64 v16; // x0
  __int64 v17; // x24
  __int64 *v18; // x1
  __int64 v19; // x0

  if ( !s2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_iommu_fault_handler",
      1015,
      "token is NULL, domain = %pK, device = %pK,iova = 0x%lx, flags = 0x%x",
      a1,
      a2,
      a3,
      a4);
    return 0;
  }
  v9 = dword_394060;
  if ( !dword_394060 )
  {
    v11 = 0;
LABEL_15:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_iommu_fault_handler",
      1029,
      "index is invalid, index = %d, token = %s, cb_num = %s",
      v11,
      s2,
      v9);
    return 0;
  }
  v10 = 0;
  v11 = 0;
  v12 = iommu_cb_set;
  while ( strcmp(*(const char **)(v12 + 14280LL * v11 + 32), s2) )
  {
    ++v11;
    v10 += 14280;
    if ( v9 == v11 )
    {
      v11 = v9;
      goto LABEL_15;
    }
  }
  if ( v11 < 0 )
    goto LABEL_15;
  v13 = *(_DWORD *)(v12 + v10 + 8592) + 1;
  *(_DWORD *)(v12 + v10 + 8592) = v13;
  if ( v13 > g_num_pf_handled )
  {
    if ( (unsigned int)__ratelimit(&cam_smmu_iommu_fault_handler__rs, "cam_smmu_iommu_fault_handler") )
      v14 = 3;
    else
      v14 = 2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v14,
      64,
      3,
      "cam_smmu_iommu_fault_handler",
      1036,
      "PF already handled %d %d %d",
      g_num_pf_handled,
      v11,
      *(_DWORD *)(iommu_cb_set + v10 + 8592));
    return 0;
  }
  if ( mem_trace_en == 1 )
    v16 = cam_mem_trace_alloc(64, 0x820u, 0, "cam_smmu_iommu_fault_handler", 0x410u);
  else
    v16 = _kvmalloc_node_noprof(64, 0, 2336, 0xFFFFFFFFLL);
  v17 = v16;
  if ( !v16 )
    return 0;
  *(_QWORD *)(v16 + 40) = s2;
  *(_QWORD *)(v16 + 8) = a1;
  *(_QWORD *)(v16 + 16) = a2;
  *(_QWORD *)(v16 + 24) = a3;
  *(_DWORD *)(v16 + 32) = a4;
  *(_DWORD *)v16 = v11;
  mutex_lock(&unk_394088);
  v18 = (__int64 *)qword_3940C0;
  v19 = v17 + 48;
  if ( (_UNKNOWN *)v17 == &unk_394088 || qword_3940C0 == v19 || *(__int64 **)qword_3940C0 != &qword_3940B8 )
  {
    _list_add_valid_or_report(v19);
  }
  else
  {
    qword_3940C0 = v17 + 48;
    *(_QWORD *)(v17 + 48) = &qword_3940B8;
    *(_QWORD *)(v17 + 56) = v18;
    *v18 = v19;
  }
  mutex_unlock(&unk_394088);
  cam_smmu_page_fault_work();
  if ( *(_BYTE *)(iommu_cb_set + v10 + 106) == 1 && (((unsigned __int64)(unsigned int)dword_3940D0 >> v11) & 1) != 0 )
    panic("CAMERA - SMMU context fault from soc: %s[cb_idx: %u]\n", *(const char **)(iommu_cb_set + v10 + 32), v11);
  return 4294967258LL;
}
