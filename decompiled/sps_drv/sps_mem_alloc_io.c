__int64 __fastcall sps_mem_alloc_io(unsigned int a1)
{
  __int64 v2; // x20
  const void *v3; // x0
  const void *v5; // x20
  const void *v6; // x20
  int v7; // w8
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = 3735928559LL;
  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 3735928559LL;
  v3 = (const void *)gen_pool_alloc_algo_owner(pool, a1, *(_QWORD *)(pool + 32), *(_QWORD *)(pool + 40), 0);
  if ( v3 )
  {
    v8[0] = (unsigned int)((_DWORD)v3 - iomem_virt) + iomem_phys;
    total_alloc += a1;
    if ( (unsigned __int8)logging_option > 1u )
    {
      if ( debug_level_option )
      {
        if ( !print_limit_option
          || (v6 = v3, v7 = __ratelimit(&sps_mem_alloc_io__rs_4, "sps_mem_alloc_io"), v3 = v6, v7) )
        {
          v5 = v3;
          printk(&unk_23F1F, "sps_mem_alloc_io", "sps_mem_alloc_io");
          v3 = v5;
        }
      }
    }
    if ( sps && *(_DWORD *)(sps + 288) <= 3u )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:%s.phys=%pa.virt=0x%pK.size=0x%x\n",
        "sps_mem_alloc_io",
        "sps_mem_alloc_io",
        v8,
        v3,
        a1);
    v2 = v8[0];
  }
  else
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_mem_alloc_io__rs, "sps_mem_alloc_io")) )
    {
      printk(&unk_2A852, "sps_mem_alloc_io", a1);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:gen_pool_alloc %d bytes fail\n", "sps_mem_alloc_io", a1);
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
