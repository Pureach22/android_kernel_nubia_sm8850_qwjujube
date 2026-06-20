__int64 md_minidump_memory_init()
{
  int v0; // w19
  __int64 dir; // x19
  __int64 v3; // x8
  unsigned __int64 v10; // x13

  md_debug_totalcma_pages = debug_symbol_lookup_name("totalcma_pages");
  if ( md_debug_totalcma_pages )
  {
    v0 = 0;
  }
  else
  {
    printk(&unk_113D5C, "totalcma_pages");
    v0 = 1;
  }
  md_debug_slab_caches = debug_symbol_lookup_name("slab_caches");
  if ( !md_debug_slab_caches )
  {
    printk(&unk_113D5C, "slab_caches");
    v0 = 1;
  }
  md_debug_slab_mutex = debug_symbol_lookup_name("slab_mutex");
  if ( !md_debug_slab_mutex )
  {
    printk(&unk_113D5C, "slab_mutex");
    v0 = 1;
  }
  md_debug_page_owner_inited = debug_symbol_lookup_name("page_owner_inited");
  if ( !md_debug_page_owner_inited )
  {
    printk(&unk_113D5C, "page_owner_inited");
    v0 = 1;
  }
  md_debug_slub_debug_enabled = debug_symbol_lookup_name("slub_debug_enabled");
  if ( !md_debug_slub_debug_enabled )
  {
    printk(&unk_113D5C, "slub_debug_enabled");
    v0 = 1;
  }
  md_debug_min_low_pfn = debug_symbol_lookup_name("min_low_pfn");
  if ( !md_debug_min_low_pfn )
  {
    printk(&unk_113D5C, "min_low_pfn");
    v0 = 1;
  }
  md_debug_max_pfn = debug_symbol_lookup_name("max_pfn");
  if ( md_debug_max_pfn )
  {
    if ( v0 )
    {
      return 1;
    }
    else
    {
      dir = debugfs_create_dir("minidump", 0);
      md_register_panic_entries(1, (__int64)"MEMINFO", (__int64 **)&md_meminfo_seq_buf);
      md_register_panic_entries(8, (__int64)"SLABINFO", (__int64 **)&md_slabinfo_seq_buf);
      if ( md_debug_page_owner_inited && *(_DWORD *)md_debug_page_owner_inited )
      {
        ((void (__fastcall *)(_QWORD, const char *))md_register_memory_dump)(
          (unsigned int)md_pageowner_dump_size,
          "PAGEOWNER");
        debugfs_create_file("page_owner_dump_size_mb", 256, dir, 0, &proc_page_owner_dump_size_ops);
        debugfs_create_file("page_owner_filter", 256, dir, 0, &proc_page_owner_filter_ops);
        debugfs_create_file("page_owner_handles_size_kb", 256, dir, 0, &proc_page_owner_handle_ops);
        debugfs_create_file("page_owner_call_sites", 256, dir, 0, &proc_page_owner_call_site_ops);
      }
      if ( md_debug_slub_debug_enabled && *(_DWORD *)md_debug_slub_debug_enabled )
      {
        ((void (__fastcall *)(_QWORD, const char *))md_register_memory_dump)(
          (unsigned int)md_slabowner_dump_size,
          "SLABOWNER");
        debugfs_create_file("slab_owner_dump_size_mb", 256, dir, 0, &proc_slab_owner_dump_size_ops);
        debugfs_create_file("slab_owner_filter", 256, dir, 0, &proc_slab_owner_filter_ops);
        debugfs_create_file("slab_owner_handles_size_kb", 256, dir, 0, &proc_slab_owner_handle_ops);
        v3 = 0;
        _X11 = &slab_owner_filter;
        do
        {
          if ( kmalloc_caches[v3] )
          {
            __asm { PRFM            #0x11, [X11] }
            do
              v10 = __ldxr((unsigned __int64 *)&slab_owner_filter);
            while ( __stxr(v10 | (1LL << v3), (unsigned __int64 *)&slab_owner_filter) );
          }
          ++v3;
        }
        while ( v3 != 14 );
      }
      ((void (__fastcall *)(_QWORD, const char *))md_register_memory_dump)(
        (unsigned int)md_dma_buf_info_size,
        "DMA_INFO");
      debugfs_create_file("dma_buf_info_size_mb", 256, dir, 0, &proc_dma_buf_info_size_ops);
      ((void (__fastcall *)(_QWORD, const char *))md_register_memory_dump)(
        (unsigned int)md_dma_buf_procs_size,
        "DMA_PROC");
      debugfs_create_file("dma_buf_procs_size_mb", 256, dir, 0, &proc_dma_buf_procs_size_ops);
      ((void (__fastcall *)(_QWORD, const char *))md_register_memory_dump)(
        (unsigned int)md_task_memstat_size,
        "TASK_MEMSTAT");
      debugfs_create_file("task_memstat_size_mb", 256, dir, 0, &proc_task_memstat_size_ops);
      return 0;
    }
  }
  else
  {
    printk(&unk_113D5C, "max_pfn");
    return 1;
  }
}
