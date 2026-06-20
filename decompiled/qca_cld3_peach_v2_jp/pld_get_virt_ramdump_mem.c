__int64 __fastcall pld_get_virt_ramdump_mem(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x3
  int v8; // w8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v11; // x1

  v3 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
    goto LABEL_22;
  }
  v5 = raw_spin_lock_irqsave(pld_ctx + 8);
  v6 = v3 + 16;
  do
  {
    v6 = *(_QWORD *)v6;
    if ( v6 == v3 + 16 )
    {
      raw_spin_unlock_irqrestore(v3 + 8, v5);
      goto LABEL_22;
    }
  }
  while ( *(_QWORD *)(v6 - 16) != a1 );
  raw_spin_unlock_irqrestore(v3 + 8, v5);
  if ( v6 == 16 )
    goto LABEL_22;
  v8 = *(_DWORD *)(v6 + 16);
  result = 0;
  if ( v8 > 3 )
  {
    if ( (unsigned int)(v8 - 4) < 4 )
      return result;
LABEL_22:
    printk(&unk_8EB76B, "pld_get_virt_ramdump_mem", 739, v7);
    return 0;
  }
  if ( !v8 )
    return cnss_get_virt_ramdump_mem(a1, a2);
  if ( v8 == 1 )
    return result;
  if ( v8 != 2 )
    goto LABEL_22;
  if ( !a2 )
    return 0;
  *a2 = 0x200000;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || (_ReadStatusReg(DAIF) & 0x80) != 0
    || *(_DWORD *)(StatusReg + 16) )
  {
    v11 = 2336;
  }
  else
  {
    v11 = 3520;
  }
  return _kmalloc_large_noprof(0x200000, v11);
}
