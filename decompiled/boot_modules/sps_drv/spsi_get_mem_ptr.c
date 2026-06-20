unsigned __int64 __fastcall spsi_get_mem_ptr(unsigned __int64 a1)
{
  unsigned __int64 v1; // x19
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = a1;
  if ( a1 < iomem_phys || iomem_phys + (unsigned __int64)(unsigned int)iomem_size <= a1 )
  {
    v1 = (a1 - memstart_addr) | 0xFFFFFF8000000000LL;
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&spsi_get_mem_ptr__rs, "spsi_get_mem_ptr")) )
    {
      printk(&unk_290AC, "spsi_get_mem_ptr", "spsi_get_mem_ptr");
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps:%s.invalid phys addr=0x%pa\n",
        "spsi_get_mem_ptr",
        "spsi_get_mem_ptr",
        v3);
  }
  else
  {
    v1 = iomem_virt + a1 - iomem_phys;
  }
  _ReadStatusReg(SP_EL0);
  return v1;
}
