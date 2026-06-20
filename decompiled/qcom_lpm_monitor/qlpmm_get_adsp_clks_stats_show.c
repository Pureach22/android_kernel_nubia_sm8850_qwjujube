__int64 __fastcall qlpmm_get_adsp_clks_stats_show(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x22
  unsigned __int64 v4; // x23
  unsigned int v5; // w19
  unsigned __int64 StatusReg; // x21
  __int64 v7; // x22

  v2 = _kmalloc_cache_noprof(MEMORY[0x8288], 3520, 2936);
  if ( v2 )
  {
    while ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, __int64))qlpmm_get_subsystem_lpm_data)(0, v2) )
    {
      seq_printf(a1, "subsystem id:%u\nresource name:%s\n\n", 0, (const char *)(v2 + 8));
      seq_printf(a1, "%-40s%-10s%-20s%-20s\n", "clock name", "count", "last on timestamp", "last off timestamp");
      if ( !*(_DWORD *)(v2 + 4) )
      {
LABEL_9:
        v5 = 0;
        goto LABEL_10;
      }
      v3 = 0;
      v4 = 0;
      while ( v3 != 2880 )
      {
        if ( (unsigned __int64)(v3 - 2872) < 0xFFFFFFFFFFFFF488LL
          || (unsigned __int64)(v3 - 2864) < 0xFFFFFFFFFFFFF488LL )
        {
          __break(1u);
          break;
        }
        seq_printf(
          a1,
          "%-40s%-10u%-20llu%-20llu\n",
          (const char *)(v2 + v3 + 80),
          *(_DWORD *)(v2 + v3 + 56),
          *(_QWORD *)(v2 + v3 + 64),
          *(_QWORD *)(v2 + v3 + 72));
        ++v4;
        v3 += 72;
        if ( v4 >= *(unsigned int *)(v2 + 4) )
          goto LABEL_9;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v7 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v2 = _kmalloc_cache_noprof(MEMORY[0x8288], 3520, 2936);
      *(_QWORD *)(StatusReg + 80) = v7;
      if ( !v2 )
        return (unsigned int)-12;
    }
    printk(&unk_6A98);
    v5 = -11;
LABEL_10:
    kfree(v2);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v5;
}
