__int64 __fastcall pld_release_virt_ramdump_mem(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x3
  unsigned int v9; // w8

  v3 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v5 = raw_spin_lock_irqsave(pld_ctx + 8);
    v6 = v3 + 16;
    do
    {
      v6 = *(_QWORD *)v6;
      if ( v6 == v3 + 16 )
      {
        raw_spin_unlock_irqrestore(v3 + 8, v5);
        return printk(&unk_9C3340, "pld_release_virt_ramdump_mem", 762, v8);
      }
    }
    while ( *(_QWORD *)(v6 - 16) != a1 );
    result = raw_spin_unlock_irqrestore(v3 + 8, v5);
    if ( v6 != 16 )
    {
      v9 = *(_DWORD *)(v6 + 16);
      if ( v9 <= 7 )
      {
        if ( ((1 << v9) & 0xF3) != 0 )
          return result;
        if ( v9 == 2 )
          return kfree(a2);
      }
    }
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
  }
  return printk(&unk_9C3340, "pld_release_virt_ramdump_mem", 762, v8);
}
