__int64 __fastcall sps_mem_init(__int64 a1, unsigned int a2)
{
  __int64 v2; // x2
  __int64 result; // x0

  if ( (d_type & 0xFFFFFFFD) != 0 && imem != 1 )
    goto LABEL_12;
  iomem_phys = a1;
  iomem_size = a2;
  if ( a1 )
  {
    if ( arm64_use_ng_mappings )
      v2 = 0x68000000000F13LL;
    else
      v2 = 0x68000000000713LL;
    iomem_virt = ioremap_prot(a1, a2, v2);
    if ( !iomem_virt )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_mem_init__rs_9, "sps_mem_init")) )
      {
        printk(&unk_2A87A, "sps_mem_init", "sps_mem_init");
      }
      if ( sps )
        ipc_log_string(
          *(_QWORD *)(sps + 272),
          "%s: sps:%s:Failed to IO map pipe memory\n",
          "sps_mem_init",
          "sps_mem_init");
      return 4294967284LL;
    }
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 4u
      && (!print_limit_option || (unsigned int)__ratelimit(&sps_mem_init__rs_12, "sps_mem_init")) )
    {
      printk(&unk_29BE5, "sps_mem_init", "sps_mem_init");
    }
    if ( sps && !*(_DWORD *)(sps + 288) )
      ipc_log_string(
        *(_QWORD *)(sps + 248),
        "%s: sps:%s.iomem_phys=%pa,iomem_virt=0x%pK\n",
        "sps_mem_init",
        "sps_mem_init",
        &iomem_phys,
        (const void *)iomem_virt);
LABEL_12:
    pool = gen_pool_create(8, 0xFFFFFFFFLL);
    if ( pool )
    {
      if ( (d_type & 0xFFFFFFFD) != 0 && imem != 1 )
        return 0;
      result = gen_pool_add_owner();
      if ( !(_DWORD)result )
        return 0;
      return result;
    }
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_mem_init__rs_15, "sps_mem_init")) )
    {
      printk(&unk_28404, "sps_mem_init", "sps_mem_init");
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:%s:Failed to create a new memory pool\n",
        "sps_mem_init",
        "sps_mem_init");
    return 4294967284LL;
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_mem_init__rs, "sps_mem_init")) )
  {
    printk(&unk_283DD, "sps_mem_init", "sps_mem_init");
  }
  if ( sps )
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:%s:Invalid Pipe-Mem address\n", "sps_mem_init", "sps_mem_init");
  return 0xFFFFFFFFLL;
}
