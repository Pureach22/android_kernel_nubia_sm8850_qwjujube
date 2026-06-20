__int64 __fastcall pld_wlan_enable(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  __int64 v8; // x24
  int v9; // w8
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x0
  _QWORD *v13; // x9

  v4 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
    return 4294967274LL;
  }
  v7 = raw_spin_lock_irqsave(pld_ctx + 8);
  v8 = v4 + 16;
  do
  {
    v8 = *(_QWORD *)v8;
    if ( v8 == v4 + 16 )
    {
      raw_spin_unlock_irqrestore(v4 + 8, v7);
      return 4294967274LL;
    }
  }
  while ( *(_QWORD *)(v8 - 16) != a1 );
  raw_spin_unlock_irqrestore(v4 + 8, v7);
  if ( v8 == 16 )
    return 4294967274LL;
  v9 = *(_DWORD *)(v8 + 16);
  result = 4294967274LL;
  if ( v9 > 3 )
  {
    if ( v9 <= 6 || v9 == 7 )
      return 0;
  }
  else
  {
    if ( v9 > 1 )
    {
      if ( v9 != 2 )
      {
        v11 = pld_ctx;
        if ( pld_ctx )
        {
          v12 = raw_spin_lock_irqsave(pld_ctx + 8);
          v13 = (_QWORD *)(v11 + 16);
          do
            v13 = (_QWORD *)*v13;
          while ( v13 != (_QWORD *)(v11 + 16) && *(v13 - 2) != a1 );
          raw_spin_unlock_irqrestore(v11 + 8, v12);
        }
        else
        {
          printk(&unk_99F123, "pld_get_dev_node", 198, a1);
        }
      }
      return 0;
    }
    if ( v9 )
    {
      if ( v9 != 1 )
        return result;
      return 0;
    }
    else
    {
      return pld_pcie_wlan_enable(a1, a2, a3, "5.2.1.137C");
    }
  }
  return result;
}
