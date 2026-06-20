__int64 sps_mem_de_init()
{
  if ( iomem_virt )
  {
    gen_pool_destroy(pool);
    pool = 0;
    iounmap(iomem_virt);
    iomem_virt = 0;
  }
  if ( total_alloc == total_free )
    return 0;
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_mem_de_init__rs, "sps_mem_de_init")) )
  {
    printk(&unk_26D63, "sps_mem_de_init", "sps_mem_de_init");
  }
  if ( sps )
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:%s:some memory not free\n", "sps_mem_de_init", "sps_mem_de_init");
  return 0xFFFFFFFFLL;
}
