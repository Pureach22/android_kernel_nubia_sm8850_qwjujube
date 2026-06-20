__int64 __fastcall pmic_glink_rx_work(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x28
  __int64 *v4; // x21
  __int64 *v5; // x24
  unsigned int *v6; // x28
  __int64 v7; // x27
  int v8; // w8
  __int64 v9; // x2
  __int64 v10; // x0
  void (__fastcall *v11)(__int64, __int64 *, __int64); // x8
  __int64 v12; // x2
  __int64 v13; // x0
  __int64 **v14; // x8
  __int64 *v15; // x9

  v1 = a1 - 8;
  v3 = raw_spin_lock_irqsave(a1 - 8);
  v4 = *(__int64 **)(a1 + 72);
  if ( v4 != (__int64 *)(a1 + 72) )
  {
    do
    {
      v5 = (__int64 *)*v4;
      raw_spin_unlock_irqrestore(v1, v3);
      mutex_lock(a1 - 120);
      v6 = (unsigned int *)(v4 + 3);
      v7 = idr_find(a1 - 144, *((unsigned int *)v4 + 6));
      mutex_unlock(a1 - 120);
      if ( v7 && *(_QWORD *)(v7 + 80) )
      {
        if ( *(_BYTE *)(a1 + 120) == 1 )
        {
          v8 = *(_DWORD *)(a1 + 116);
          v9 = *v6;
          if ( v8 == (_DWORD)v9 )
          {
            printk(&unk_77CE, "pmic_glink_rx_callback", *((unsigned int *)v4 + 4));
          }
          else if ( v8 == 0xFFFF )
          {
            printk(&unk_77EF, "pmic_glink_rx_callback", v9);
          }
        }
        v10 = *(_QWORD *)(v7 + 72);
        v11 = *(void (__fastcall **)(__int64, __int64 *, __int64))(v7 + 80);
        v12 = v4[2];
        if ( *((_DWORD *)v11 - 1) != -469557113 )
          __break(0x8228u);
        v11(v10, v4 + 3, v12);
      }
      else
      {
        printk(&unk_7C0E, "pmic_glink_rx_callback", *v6);
      }
      v13 = raw_spin_lock_irqsave(v1);
      v14 = (__int64 **)v4[1];
      v3 = v13;
      if ( *v14 == v4 && (v15 = (__int64 *)*v4, *(__int64 **)(*v4 + 8) == v4) )
      {
        v15[1] = (__int64)v14;
        *v14 = v15;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      kfree(v4);
      v4 = v5;
    }
    while ( v5 != (__int64 *)(a1 + 72) );
  }
  return raw_spin_unlock_irqrestore(v1, v3);
}
