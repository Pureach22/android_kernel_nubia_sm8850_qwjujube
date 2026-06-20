__int64 __fastcall sps_mem_free_io(__int64 a1, unsigned int a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = iomem_virt;
  v6[0] = a1;
  v4 = (unsigned int)(a1 - iomem_phys);
  if ( (unsigned __int8)logging_option >= 2u
    && debug_level_option
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_mem_free_io__rs, "sps_mem_free_io")) )
  {
    printk(&unk_23F1F, "sps_mem_free_io", "sps_mem_free_io");
  }
  if ( sps && *(_DWORD *)(sps + 288) <= 3u )
    ipc_log_string(
      *(_QWORD *)(sps + 272),
      "%s: sps:%s.phys=%pa.virt=0x%pK.size=0x%x\n",
      "sps_mem_free_io",
      "sps_mem_free_io",
      v6,
      (const void *)(v4 + v3),
      a2);
  result = gen_pool_free_owner(pool, v4 + v3, a2, 0);
  total_free += a2;
  _ReadStatusReg(SP_EL0);
  return result;
}
