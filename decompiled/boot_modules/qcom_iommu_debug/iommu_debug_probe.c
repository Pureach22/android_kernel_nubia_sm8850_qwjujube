__int64 __fastcall iommu_debug_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 next_child; // x0
  const char **v8; // x22
  int v9; // w24
  __int64 v10; // x0
  unsigned __int64 dir; // x0
  unsigned __int64 v13; // x20

  v1 = a1 + 16;
  v3 = devm_kmalloc(a1 + 16, 152, 3520);
  if ( !v3 )
    return 4294967284LL;
  v4 = v3;
  *(_QWORD *)v3 = v1;
  *(_DWORD *)(v3 + 48) = -1;
  *(_DWORD *)(v3 + 144) = 1;
  _mutex_init(v3 + 56, "&ddev->state_lock", &iommu_debug_probe___key);
  *(_DWORD *)(v4 + 104) = 0;
  _init_swait_queue_head(v4 + 112, "&x->wait", &init_completion___key);
  v5 = devm_kmalloc(v1, 4096, 3520);
  *(_QWORD *)(v4 + 16) = v5;
  if ( !v5 )
    return 4294967284LL;
  v6 = *(_QWORD *)(a1 + 760);
  *(_DWORD *)(v4 + 8) = 0;
  next_child = of_get_next_child(v6, 0);
  if ( next_child )
  {
    v8 = (const char **)next_child;
    v9 = 0;
    while ( 1 )
    {
      v9 += scnprintf(*(_QWORD *)(v4 + 16) + v9, 4096LL - v9, "%d: %s\n", *(_DWORD *)(v4 + 8), *v8);
      if ( v9 == 4095 )
        break;
      v10 = *(_QWORD *)(a1 + 760);
      ++*(_DWORD *)(v4 + 8);
      v8 = (const char **)of_get_next_child(v10, v8);
      if ( !v8 )
        goto LABEL_7;
    }
    dev_err(v1, "Too many testcases?\n");
  }
LABEL_7:
  *(_QWORD *)(a1 + 168) = v4;
  dir = debugfs_create_dir("iommu-test", 0);
  if ( dir > 0xFFFFFFFFFFFFF000LL )
    return 4294967274LL;
  v13 = dir;
  *(_QWORD *)(v4 + 24) = dir;
  debugfs_create_file("usecase", 384, dir, v4, &iommu_debug_usecase_fops);
  debugfs_create_file("functional_arm_dma_api", 256, v13, v4, &iommu_debug_functional_arm_dma_api_fops);
  debugfs_create_file("functional_fast_dma_api", 256, v13, v4, &iommu_debug_functional_fast_dma_api_fops);
  debugfs_create_file("atos", 384, v13, v4, &iommu_debug_atos_fops);
  debugfs_create_file("map", 128, v13, v4, &iommu_debug_map_fops);
  debugfs_create_file("unmap", 128, v13, v4, &iommu_debug_unmap_fops);
  debugfs_create_file("dma_map", 128, v13, v4, &iommu_debug_dma_map_fops);
  debugfs_create_file("dma_unmap", 128, v13, v4, &iommu_debug_dma_unmap_fops);
  debugfs_create_file("nr_iters", 384, v13, v4, &iommu_debug_nr_iters_fops);
  debugfs_create_file("test_virt_addr", 256, v13, v4, &iommu_debug_test_virt_addr_fops);
  debugfs_create_file("profiling", 256, v13, v4, &iommu_debug_profiling_fops);
  return 0;
}
